#!/usr/bin/env python3
"""Dump the Cisco RV220W parallel NOR through its U-Boot serial console.

This tool is intentionally read-only with respect to flash. It uses only:

* ``base 0`` to remove any U-Boot memory-display address offset;
* ``md.b`` to display bytes from the memory-mapped NOR window;
* ``crc32`` to validate each chunk and the complete dump; and
* optionally ``setenv baudrate`` to change the *in-memory* console baud.

It never invokes ``saveenv``, ``erase``, ``protect``, ``cp``, ``mw`` or any
firmware-update command.

Confirmed JP1 wiring::

    JP1.1  VCC/VREF     leave NC
    JP1.2  target TX    USB-UART RX
    JP1.3  target RX    USB-UART TX
    JP1.4  GND          USB-UART GND

Pin 1 is the square pad furthest from the ``JP1`` silkscreen. Never connect the
USB-UART adapter VCC output.

The RV220W must already be stopped at the ``rv200w# `` prompt. Close any other
program using the serial device before starting this script.

Typical full-flash dump at the stock baud::

    python scripts/host/dump_uboot_flash_uart.py \\
        /dev/serial/by-id/usb-FTDI_... \\
        --output rv220w-flash-32MiB.bin

Attempt a faster console rate, without saving it to flash::

    python scripts/host/dump_uboot_flash_uart.py \\
        /dev/serial/by-id/usb-FTDI_... \\
        --target-baud 460800 \\
        --output rv220w-flash-32MiB.bin

A power cycle returns the board to its default 115200-baud console because the
script never runs ``saveenv``. The script also tries to restore 115200 baud on
normal exit.
"""
from __future__ import annotations

import argparse
import binascii
import datetime as dt
import gzip
import hashlib
import json
import os
import pathlib
import re
import sys
import time
from dataclasses import asdict, dataclass
from typing import BinaryIO, Iterable

PROMPT_DEFAULT = b"rv200w# "
FLASH_BASE_DEFAULT = 0xBDC00000
FLASH_SIZE_DEFAULT = 0x02000000
CHUNK_DEFAULT = 0x00010000
SCRIPT_VERSION = "0.8.1"

# Restrict spacing to horizontal whitespace.  The previous expression used
# ``\s``; in Python that includes CR/LF, so an md.b row whose ASCII column was
# entirely spaces could consume the following row.  That produced a repeatable
# false "missing md.b line" error even though the UART transcript was complete.
MD_LINE_RE = re.compile(
    rb"^([0-9A-Fa-f]{8,16}):((?:[ \t]+[0-9A-Fa-f]{2}){1,16})(?:[ \t]{2,}.*)?\r?$"
)
CRC_LINE_RE = re.compile(
    rb"(?im)^.*CRC32.*?(?:==>|=)\s*([0-9A-Fa-f]{8})\s*\r?$"
)
BAUD_SWITCH_RE = re.compile(
    rb"Switch baudrate to\s+([0-9]+)\s+bps and press ENTER", re.IGNORECASE
)
BAUD_UNSUPPORTED_RE = re.compile(rb"baudrate.*not supported", re.IGNORECASE)


class DumpError(RuntimeError):
    """A recoverable or validation-related dumping failure."""


@dataclass
class SessionMetadata:
    started_utc: str
    finished_utc: str | None
    port: str
    initial_baud: int
    dump_baud: int
    flash_base: str
    flash_size: str
    chunk_size: str
    output_file: str
    raw_log_file: str | None
    resumed_from: str
    target_crc32_before: str | None
    target_crc32_after: str | None
    host_crc32: str | None
    host_sha256: str | None
    completed: bool
    chunks_completed: int
    chunk_retries: int


def auto_int(value: str) -> int:
    try:
        return int(value, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {value!r}") from exc


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("port", help="Serial device, such as /dev/ttyUSB0")
    parser.add_argument("--version", action="version", version=f"%(prog)s {SCRIPT_VERSION}")
    parser.add_argument(
        "--output",
        type=pathlib.Path,
        default=pathlib.Path("rv220w-flash-32MiB.bin"),
        help="Output image (default: %(default)s)",
    )
    parser.add_argument("--initial-baud", type=int, default=115200)
    parser.add_argument(
        "--target-baud",
        type=int,
        default=None,
        help="Attempt an in-memory console switch; this RV220W build supports 230400 and 460800",
    )
    parser.add_argument("--base", type=auto_int, default=FLASH_BASE_DEFAULT)
    parser.add_argument("--size", type=auto_int, default=FLASH_SIZE_DEFAULT)
    parser.add_argument("--chunk", type=auto_int, default=CHUNK_DEFAULT)
    parser.add_argument(
        "--prompt",
        default=PROMPT_DEFAULT.decode("ascii"),
        help="U-Boot prompt string (default: %(default)r)",
    )
    parser.add_argument("--retries", type=int, default=3)
    parser.add_argument(
        "--no-chunk-crc",
        action="store_true",
        help="Skip target-side CRC32 verification for each chunk",
    )
    parser.add_argument(
        "--no-full-crc",
        action="store_true",
        help="Skip target-side CRC32 verification of the complete range",
    )
    parser.add_argument(
        "--no-raw-log",
        action="store_true",
        help="Do not retain a gzip-compressed raw U-Boot transcript",
    )
    parser.add_argument(
        "--restart",
        action="store_true",
        help="Overwrite an existing output instead of resuming it",
    )
    parser.add_argument(
        "--keep-baud",
        action="store_true",
        help="Do not try to restore the initial console baud on exit",
    )
    parser.add_argument(
        "--timeout-factor",
        type=float,
        default=3.0,
        help="Multiplier for calculated md.b transfer timeout (default: %(default)s)",
    )
    parser.add_argument(
        "--prompt-timeout",
        type=float,
        default=10.0,
        help="Seconds to wait for ordinary command prompts (default: %(default)s)",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Print the plan without opening the serial port",
    )
    return parser.parse_args()


def utc_now() -> str:
    return dt.datetime.now(dt.timezone.utc).isoformat(timespec="seconds")


def crc32_bytes(data: bytes, seed: int = 0) -> int:
    return binascii.crc32(data, seed) & 0xFFFFFFFF


def hash_existing_prefix(path: pathlib.Path) -> tuple[int, str, int]:
    crc = 0
    sha = hashlib.sha256()
    total = 0
    with path.open("rb") as fh:
        while block := fh.read(1024 * 1024):
            crc = crc32_bytes(block, crc)
            sha.update(block)
            total += len(block)
    return crc, sha.hexdigest(), total


class UBootSerial:
    def __init__(
        self,
        serial_port: object,
        prompt: bytes,
        raw_log: BinaryIO | None,
        prompt_timeout: float,
    ) -> None:
        self.ser = serial_port
        self.prompt = prompt
        self.raw_log = raw_log
        self.prompt_timeout = prompt_timeout

    @property
    def baudrate(self) -> int:
        return int(getattr(self.ser, "baudrate"))

    def _log(self, data: bytes) -> None:
        if self.raw_log is not None and data:
            self.raw_log.write(data)

    def write(self, data: bytes) -> None:
        getattr(self.ser, "write")(data)
        getattr(self.ser, "flush")()

    def read_until_any(self, needles: Iterable[bytes], timeout: float) -> tuple[bytes, bytes | None]:
        targets = tuple(needles)
        deadline = time.monotonic() + timeout
        buf = bytearray()
        while time.monotonic() < deadline:
            waiting = int(getattr(self.ser, "in_waiting", 0))
            data = getattr(self.ser, "read")(max(1, min(65536, waiting or 1)))
            if data:
                buf.extend(data)
                self._log(data)
                for needle in targets:
                    if needle == self.prompt:
                        if bytes(buf).endswith(needle):
                            prefix_index = len(buf) - len(needle) - 1
                            if prefix_index < 0 or buf[prefix_index] in (0x0A, 0x0D):
                                if self.raw_log is not None:
                                    self.raw_log.flush()
                                return bytes(buf), needle
                    elif needle in buf:
                        if self.raw_log is not None:
                            self.raw_log.flush()
                        return bytes(buf), needle
            else:
                time.sleep(0.001)
        return bytes(buf), None

    def sync_prompt(self) -> bytes:
        getattr(self.ser, "reset_input_buffer")()
        self.write(b"\r")
        response, found = self.read_until_any([self.prompt], self.prompt_timeout)
        if found is None:
            # This RV220W build is known to accept Ctrl-C during the firmware
            # check even though bootdelay=0. A second sync attempt is safe and
            # makes the tool usable directly after a power cycle.
            self.write(b"\x03\r")
            response2, found = self.read_until_any([self.prompt], self.prompt_timeout)
            response += response2
        if found is None:
            raise DumpError(
                f"did not receive {self.prompt!r} at {self.baudrate} baud; "
                "confirm JP1 is connected, the board is powered, and no terminal program has the port open"
            )
        return response

    def command(self, command: str, timeout: float | None = None) -> bytes:
        # Hard fail if a future edit accidentally tries to issue a destructive command.
        verb = command.strip().split(maxsplit=1)[0].lower() if command.strip() else ""
        allowed = {"base", "md.b", "crc32", "setenv"}
        if verb not in allowed:
            raise DumpError(f"refusing non-whitelisted U-Boot command: {command!r}")
        getattr(self.ser, "reset_input_buffer")()
        self.write(command.encode("ascii") + b"\r")
        response, found = self.read_until_any(
            [self.prompt], timeout if timeout is not None else self.prompt_timeout
        )
        if found is None:
            raise DumpError(f"timeout waiting for prompt after command: {command}")
        return response

    def switch_baud(self, new_baud: int) -> None:
        if new_baud == self.baudrate:
            return
        old_baud = self.baudrate
        getattr(self.ser, "reset_input_buffer")()
        self.write(f"setenv baudrate {new_baud}\r".encode("ascii"))

        # The switch instruction is printed at the old baud. U-Boot then changes
        # its UART and waits for CR at the new baud.
        response, found = self.read_until_any(
            [b"press ENTER", self.prompt], self.prompt_timeout
        )
        if BAUD_UNSUPPORTED_RE.search(response):
            raise DumpError(f"U-Boot rejected {new_baud} baud as unsupported")
        if found == self.prompt:
            # Either no change was required or this build did not apply it.
            if new_baud != old_baud:
                raise DumpError(
                    f"U-Boot returned to the prompt at {old_baud} baud without switching to {new_baud}"
                )
            return
        match = BAUD_SWITCH_RE.search(response)
        if match is None:
            raise DumpError(
                f"did not observe U-Boot's baud-switch handshake while requesting {new_baud}"
            )
        announced = int(match.group(1))
        if announced != new_baud:
            raise DumpError(f"U-Boot announced unexpected baud {announced}")

        setattr(self.ser, "baudrate", new_baud)
        time.sleep(0.1)
        self.write(b"\r")
        response2, found2 = self.read_until_any([self.prompt], self.prompt_timeout)
        if found2 is None:
            # Leave the port configured at the attempted rate so the caller can
            # decide whether to retry or power-cycle.
            raise DumpError(
                f"no prompt received after switching host UART to {new_baud}; "
                f"power-cycle to recover the default {old_baud}-baud console"
            )

    def interrupt_and_sync(self) -> None:
        self.write(b"\x03")
        _response, found = self.read_until_any([self.prompt], self.prompt_timeout)
        if found is None:
            self.write(b"\r")
            _response, found = self.read_until_any([self.prompt], self.prompt_timeout)
        if found is None:
            raise DumpError("could not recover a U-Boot prompt after Ctrl-C")


def parse_md_response(response: bytes, start: int, length: int) -> bytes:
    lines: dict[int, bytes] = {}
    # Parse one physical line at a time.  Besides making diagnostics clearer,
    # this guarantees no regular-expression construct can bridge a CR/LF and
    # accidentally absorb the next address row.
    for physical_line in response.splitlines():
        match = MD_LINE_RE.match(physical_line)
        if match is None:
            continue
        address = int(match.group(1), 16)
        byte_tokens = match.group(2).split()
        row = bytes(int(token, 16) for token in byte_tokens)
        previous = lines.get(address)
        if previous is not None and previous != row:
            raise DumpError(
                f"conflicting duplicate md.b line at 0x{address:x}"
            )
        lines[address] = row

    expected_end = start + length
    cursor = start
    output = bytearray()
    while cursor < expected_end:
        if cursor not in lines:
            nearby = sorted(addr for addr in lines if start <= addr < expected_end)
            first = f"0x{nearby[0]:x}" if nearby else "none"
            last = f"0x{nearby[-1]:x}" if nearby else "none"
            raise DumpError(
                f"missing md.b line at 0x{cursor:x}; parsed range {first}..{last}"
            )
        row = lines[cursor]
        remaining = expected_end - cursor
        take = min(len(row), remaining)
        output.extend(row[:take])
        cursor += take

    if len(output) != length:
        raise DumpError(f"parsed {len(output)} bytes, expected {length}")
    return bytes(output)


def parse_crc32(response: bytes) -> int:
    match = CRC_LINE_RE.search(response)
    if match:
        return int(match.group(1), 16)

    # Some vendor trees print only a bare result. Prefer the final isolated
    # eight-hex-digit token, while excluding addresses embedded in longer words.
    candidates = re.findall(rb"(?<![0-9A-Fa-f])([0-9A-Fa-f]{8})(?![0-9A-Fa-f])", response)
    if not candidates:
        raise DumpError("could not parse crc32 result from U-Boot response")
    return int(candidates[-1], 16)


def target_crc(console: UBootSerial, address: int, length: int) -> int:
    # A full 32 MiB CRC is normally quick, but older CFI flash and vendor
    # builds vary. Use a deliberately generous timeout.
    timeout = max(20.0, min(180.0, 15.0 + length / 1_000_000))
    response = console.command(f"crc32 {address:x} {length:x}", timeout=timeout)
    return parse_crc32(response)


def calculated_md_timeout(length: int, baudrate: int, factor: float) -> float:
    # md.b emits approximately 80 serial characters for each 16 data bytes.
    # 8N1 means ten wire bits per character.
    estimated_seconds = length * 5.0 * 10.0 / max(baudrate, 1)
    return max(10.0, estimated_seconds * factor + 5.0)


def write_metadata(path: pathlib.Path, metadata: SessionMetadata) -> None:
    tmp = path.with_suffix(path.suffix + ".tmp")
    tmp.write_text(json.dumps(asdict(metadata), indent=2) + "\n", encoding="utf-8")
    tmp.replace(path)


def validate_plan(args: argparse.Namespace) -> None:
    if args.size <= 0:
        raise DumpError("--size must be positive")
    if args.chunk <= 0 or args.chunk > args.size:
        raise DumpError("--chunk must be positive and no larger than --size")
    if args.chunk % 16:
        raise DumpError("--chunk must be divisible by 16 for md.b row validation")
    if args.base < 0 or args.base + args.size > 0x1_0000_0000:
        raise DumpError("requested address range is invalid for this 32-bit U-Boot mapping")
    if args.retries < 1:
        raise DumpError("--retries must be at least 1")
    if args.output.exists() and args.restart:
        args.output.unlink()
    if args.output.exists():
        current = args.output.stat().st_size
        if current and current < args.size and args.no_full_crc:
            raise DumpError("resuming requires full/prefix CRC validation; remove --no-full-crc or use --restart")
        if current > args.size:
            raise DumpError("existing output is larger than requested dump size")
        if current != args.size and current % args.chunk != 0:
            raise DumpError(
                "existing output size is not chunk-aligned; move it aside or use --restart"
            )


def main() -> int:
    args = parse_args()
    prompt = args.prompt.encode("ascii")
    try:
        validate_plan(args)
    except DumpError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2

    existing = args.output.stat().st_size if args.output.exists() else 0
    target_baud = args.target_baud or args.initial_baud
    raw_log_path = None if args.no_raw_log else args.output.with_suffix(args.output.suffix + ".uart.log.gz")
    metadata_path = args.output.with_suffix(args.output.suffix + ".json")

    print(f"RV220W U-Boot UART flash-dump plan (script {SCRIPT_VERSION})")
    print(f"  port:          {args.port}")
    print(f"  console:       {args.initial_baud} -> {target_baud} baud")
    print(f"  flash range:   0x{args.base:08x}..0x{args.base + args.size:08x} (exclusive)")
    print(f"  image size:    0x{args.size:x} ({args.size} bytes)")
    print(f"  chunk size:    0x{args.chunk:x} ({args.chunk} bytes)")
    print(f"  output:        {args.output}")
    print(f"  resume offset: 0x{existing:x}")
    print(f"  raw log:       {raw_log_path or 'disabled'}")
    print("  flash writes:  none")
    if args.dry_run:
        return 0

    try:
        import serial  # type: ignore
    except ImportError:
        print("pyserial is required: python -m pip install pyserial", file=sys.stderr)
        return 2

    args.output.parent.mkdir(parents=True, exist_ok=True)
    raw_log_handle: BinaryIO | None = None
    serial_handle = None
    console: UBootSerial | None = None
    current_baud = args.initial_baud
    metadata = SessionMetadata(
        started_utc=utc_now(),
        finished_utc=None,
        port=args.port,
        initial_baud=args.initial_baud,
        dump_baud=target_baud,
        flash_base=f"0x{args.base:08x}",
        flash_size=f"0x{args.size:x}",
        chunk_size=f"0x{args.chunk:x}",
        output_file=str(args.output),
        raw_log_file=str(raw_log_path) if raw_log_path else None,
        resumed_from=f"0x{existing:x}",
        target_crc32_before=None,
        target_crc32_after=None,
        host_crc32=None,
        host_sha256=None,
        completed=False,
        chunks_completed=0,
        chunk_retries=0,
    )
    write_metadata(metadata_path, metadata)

    try:
        if raw_log_path is not None:
            raw_log_handle = gzip.open(raw_log_path, "ab")
        serial_handle = serial.Serial(
            port=args.port,
            baudrate=args.initial_baud,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=0.05,
            write_timeout=2.0,
            rtscts=False,
            dsrdtr=False,
            xonxoff=False,
        )
        console = UBootSerial(serial_handle, prompt, raw_log_handle, args.prompt_timeout)
        console.sync_prompt()
        console.command("base 0")

        if target_baud != args.initial_baud:
            print(f"Requesting temporary U-Boot console switch to {target_baud} baud...")
            console.switch_baud(target_baud)
            current_baud = target_baud
            print(f"Confirmed prompt at {target_baud} baud.")

        if not args.no_full_crc:
            print("Computing target CRC32 before transfer...")
            before = target_crc(console, args.base, args.size)
            metadata.target_crc32_before = f"{before:08x}"
            print(f"  target CRC32 before: {before:08x}")

        if existing:
            prefix_crc, _prefix_sha, prefix_len = hash_existing_prefix(args.output)
            if prefix_len != existing:
                raise DumpError("output changed while calculating resume checksum")
            if not args.no_full_crc:
                print(f"Validating existing 0x{existing:x}-byte prefix against target...")
                device_prefix_crc = target_crc(console, args.base, existing)
                if device_prefix_crc != prefix_crc:
                    raise DumpError(
                        f"resume prefix CRC mismatch: host {prefix_crc:08x}, target {device_prefix_crc:08x}"
                    )
                print(f"  resume prefix CRC32: {prefix_crc:08x} (matched)")

        mode = "r+b" if args.output.exists() else "w+b"
        with args.output.open(mode) as image:
            image.seek(existing)
            offset = existing
            total_chunks = (args.size + args.chunk - 1) // args.chunk
            completed_chunks = offset // args.chunk
            started_transfer = time.monotonic()

            while offset < args.size:
                chunk_len = min(args.chunk, args.size - offset)
                address = args.base + offset
                chunk_index = offset // args.chunk + 1
                timeout = calculated_md_timeout(chunk_len, current_baud, args.timeout_factor)
                last_error: Exception | None = None

                for attempt in range(1, args.retries + 1):
                    try:
                        response = console.command(
                            f"md.b {address:x} {chunk_len:x}", timeout=timeout
                        )
                        data = parse_md_response(response, address, chunk_len)
                        host_chunk_crc = crc32_bytes(data)
                        if not args.no_chunk_crc:
                            device_chunk_crc = target_crc(console, address, chunk_len)
                            if device_chunk_crc != host_chunk_crc:
                                raise DumpError(
                                    f"chunk CRC mismatch at 0x{address:08x}: "
                                    f"host {host_chunk_crc:08x}, target {device_chunk_crc:08x}"
                                )
                        image.seek(offset)
                        image.write(data)
                        image.flush()
                        os.fsync(image.fileno())
                        last_error = None
                        break
                    except (DumpError, OSError) as exc:
                        last_error = exc
                        metadata.chunk_retries += 1
                        print(
                            f"\nRetry {attempt}/{args.retries} for 0x{address:08x}: {exc}",
                            file=sys.stderr,
                        )
                        try:
                            console.interrupt_and_sync()
                        except DumpError:
                            pass
                        time.sleep(0.25)

                if last_error is not None:
                    raise DumpError(
                        f"failed chunk at 0x{address:08x} after {args.retries} attempts: {last_error}"
                    )

                offset += chunk_len
                completed_chunks += 1
                metadata.chunks_completed = completed_chunks
                write_metadata(metadata_path, metadata)

                elapsed = max(time.monotonic() - started_transfer, 0.001)
                transferred = offset - existing
                rate = transferred / elapsed
                remaining = args.size - offset
                eta = remaining / rate if rate > 0 else 0
                percent = offset * 100.0 / args.size
                print(
                    f"\r[{chunk_index:4d}/{total_chunks}] {percent:6.2f}%  "
                    f"0x{offset:08x}/0x{args.size:08x}  "
                    f"{rate/1024:7.1f} KiB/s  ETA {eta/60:6.1f} min",
                    end="",
                    flush=True,
                )
            print()

        host_crc, host_sha, final_size = hash_existing_prefix(args.output)
        if final_size != args.size:
            raise DumpError(f"final image size {final_size} does not equal expected {args.size}")
        metadata.host_crc32 = f"{host_crc:08x}"
        metadata.host_sha256 = host_sha
        print(f"Host CRC32:  {host_crc:08x}")
        print(f"Host SHA-256: {host_sha}")

        if not args.no_full_crc:
            print("Computing target CRC32 after transfer...")
            after = target_crc(console, args.base, args.size)
            metadata.target_crc32_after = f"{after:08x}"
            print(f"Target CRC32: {after:08x}")
            if metadata.target_crc32_before != metadata.target_crc32_after:
                raise DumpError(
                    "target full-range CRC changed during the read-only session; do not trust the dump"
                )
            if after != host_crc:
                raise DumpError(
                    f"full-image CRC mismatch: host {host_crc:08x}, target {after:08x}"
                )
            print("Full-image target/host CRC32 matched.")

        metadata.completed = True
        return_code = 0

    except KeyboardInterrupt:
        print("\nInterrupted by user; the partial image is resumable.", file=sys.stderr)
        return_code = 130
        if console is not None:
            try:
                console.interrupt_and_sync()
            except Exception:
                pass
    except (DumpError, OSError, ValueError) as exc:
        print(f"\nerror: {exc}", file=sys.stderr)
        print("The partial output remains available for a validated resume.", file=sys.stderr)
        return_code = 1
    finally:
        if console is not None and current_baud != args.initial_baud and not args.keep_baud:
            try:
                print(f"Restoring temporary console baud to {args.initial_baud}...")
                console.switch_baud(args.initial_baud)
                current_baud = args.initial_baud
                print("Console baud restored.")
            except Exception as exc:
                print(
                    f"warning: could not restore console baud: {exc}; "
                    f"power-cycle to return to {args.initial_baud}",
                    file=sys.stderr,
                )
        if serial_handle is not None:
            try:
                serial_handle.close()
            except Exception:
                pass
        if raw_log_handle is not None:
            try:
                raw_log_handle.close()
            except Exception:
                pass
        metadata.finished_utc = utc_now()
        try:
            write_metadata(metadata_path, metadata)
        except Exception:
            pass

    return return_code


if __name__ == "__main__":
    raise SystemExit(main())
