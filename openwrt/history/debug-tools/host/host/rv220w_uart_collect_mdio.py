#!/usr/bin/env python3
"""Run the RV220W read-only MDIO scanner and retrieve its report over UART.

The transport deliberately does not depend on Ethernet.  It synchronizes with
an already-running OpenWrt ash console, uploads the packaged scanner to /tmp
when necessary, executes it, and captures the generated report between unique
sentinels.  The target-side scanner itself performs direct Clause 22 reads only.
"""

from __future__ import annotations

import argparse
import datetime as dt
import hashlib
import os
import pathlib
import re
import secrets
import sys
import time
from dataclasses import dataclass
from typing import Final


DEFAULT_BAUD: Final[int] = 115200
DEFAULT_BUS: Final[str] = "8001180000001800"
REMOTE_INSTALLED: Final[str] = "/usr/sbin/rv220w-mdio-scan"
REMOTE_TEMP: Final[str] = "/tmp/rv220w-mdio-scan"
SAFE_LABEL = re.compile(r"^[A-Za-z0-9._-]+$")
SAFE_BUS = re.compile(r"^[A-Za-z0-9._:-]+$")
REMOTE_OUTPUT_RE = re.compile(r"/tmp/rv220w-mdio-[A-Za-z0-9._-]+\.txt")

UPLOAD_CHUNK_BYTES: Final[int] = 24
UPLOAD_MAX_COMMAND_BYTES: Final[int] = 240
UPLOAD_WRITE_BURST_BYTES: Final[int] = 32
UPLOAD_WRITE_BURST_DELAY: Final[float] = 0.003


class UartError(RuntimeError):
    """Expected UART collection failure."""


def utc_stamp() -> str:
    return dt.datetime.now(dt.timezone.utc).strftime("%Y%m%dT%H%M%SZ")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("serial_port")
    parser.add_argument("scan_script", type=pathlib.Path)
    parser.add_argument("label")
    parser.add_argument("bus", nargs="?", default=DEFAULT_BUS)
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD)
    parser.add_argument("--timeout", type=float, default=120.0)
    parser.add_argument("--output-dir", type=pathlib.Path, required=True)
    parser.add_argument("--transcript", type=pathlib.Path)
    parser.add_argument("--force-upload", action="store_true")
    return parser.parse_args()


def normalize_label(value: str) -> str:
    label = re.sub(r"[^A-Za-z0-9._-]", "_", value)
    if not label or not SAFE_LABEL.fullmatch(label):
        raise UartError(f"unsafe or empty label: {value!r}")
    return label


def validate_bus(value: str) -> str:
    if not SAFE_BUS.fullmatch(value):
        raise UartError(f"unsafe MDIO bus selector: {value!r}")
    return value


@dataclass
class CommandResult:
    output: str
    status: int


class UartShell:
    def __init__(self, serial_handle, timeout: float, transcript):
        self.serial = serial_handle
        self.timeout = timeout
        self.transcript = transcript

    def _record(self, data: bytes) -> None:
        if self.transcript is not None and data:
            self.transcript.write(data)
            self.transcript.flush()

    def write(self, data: bytes) -> None:
        self.serial.write(data)
        self.serial.flush()

    def write_paced(
        self,
        data: bytes,
        burst_size: int = UPLOAD_WRITE_BURST_BYTES,
        burst_delay: float = UPLOAD_WRITE_BURST_DELAY,
    ) -> None:
        """Write bounded bursts for consoles with small canonical input buffers."""
        for offset in range(0, len(data), burst_size):
            self.serial.write(data[offset : offset + burst_size])
            self.serial.flush()
            if offset + burst_size < len(data):
                time.sleep(burst_delay)

    def drain(self, duration: float = 0.35) -> bytes:
        deadline = time.monotonic() + duration
        chunks: list[bytes] = []
        while time.monotonic() < deadline:
            data = self.serial.read(self.serial.in_waiting or 1)
            if data:
                chunks.append(data)
                self._record(data)
                deadline = time.monotonic() + duration
            else:
                time.sleep(0.02)
        return b"".join(chunks)

    @staticmethod
    def _normalized_lines(data: bytes) -> list[str]:
        text = data.replace(b"\r\n", b"\n").replace(b"\r", b"\n").decode(
            "utf-8", "replace"
        )
        return text.split("\n")

    def read_until_line(self, marker: str, timeout: float | None = None) -> bytes:
        """Wait for marker as a complete output line, never echoed source text."""
        deadline = time.monotonic() + (self.timeout if timeout is None else timeout)
        data = bytearray()
        while time.monotonic() < deadline:
            chunk = self.serial.read(self.serial.in_waiting or 1)
            if chunk:
                data.extend(chunk)
                self._record(chunk)
                if marker in self._normalized_lines(bytes(data)):
                    return bytes(data)
            else:
                time.sleep(0.02)
        preview = bytes(data[-500:]).decode("utf-8", "replace")
        raise UartError(
            f"timed out waiting for UART marker line {marker!r}; tail follows:\n{preview}"
        )

    def read_until_status_line(
        self, marker_prefix: str, timeout: float | None = None
    ) -> tuple[bytes, int]:
        """Wait for a complete short upload acknowledgement line."""
        deadline = time.monotonic() + (self.timeout if timeout is None else timeout)
        data = bytearray()
        pattern = re.compile(re.escape(marker_prefix) + r"(\d+)")
        while time.monotonic() < deadline:
            chunk = self.serial.read(self.serial.in_waiting or 1)
            if chunk:
                data.extend(chunk)
                self._record(chunk)
                for line in reversed(self._normalized_lines(bytes(data))):
                    match = pattern.fullmatch(line)
                    if match is not None:
                        return bytes(data), int(match.group(1))
            else:
                time.sleep(0.01)
        preview = bytes(data[-500:]).decode("utf-8", "replace")
        continuation = "\nThe target appears to be at ash's continuation prompt." if "\n> " in preview else ""
        raise UartError(
            f"timed out waiting for UART upload acknowledgement {marker_prefix!r}; tail follows:\n{preview}{continuation}"
        )

    def run_upload_append(
        self, escaped_chunk: str, remote_path: str, timeout: float = 15.0
    ) -> CommandResult:
        """Append one short octal chunk without the long general command wrapper."""
        token = secrets.token_hex(4)
        marker_prefix = f"U{token}:"
        command = (
            f"printf '%b' {shell_quote(escaped_chunk)} >> {shell_quote(remote_path)};"
            f"r=$?;printf '\\n{marker_prefix}%s\\n' \"$r\"\r"
        )
        encoded = command.encode("ascii")
        if len(encoded) > UPLOAD_MAX_COMMAND_BYTES:
            raise UartError(
                f"internal UART upload command is too long: {len(encoded)} > {UPLOAD_MAX_COMMAND_BYTES}"
            )
        self.write_paced(encoded)
        _, status = self.read_until_status_line(marker_prefix, timeout=timeout)
        self.drain(0.02)
        return CommandResult(output="", status=status)

    def synchronize(self) -> None:
        # Abort any partially typed command, obtain a fresh ash prompt, then
        # disable local terminal echo so command text cannot be confused with
        # the unique output sentinels used below.
        self.write(b"\x03\r\n")
        self.drain(0.5)
        self.write(b"stty -echo 2>/dev/null\r\n")
        self.drain(0.4)
        token = f"RVUART_READY_{secrets.token_hex(8)}"
        self.write(f"printf '\\n{token}\\n'\r".encode("ascii"))
        self.read_until_line(token, timeout=15.0)
        self.drain(0.15)

    def restore_echo(self) -> None:
        try:
            self.write(b"stty echo 2>/dev/null\r\n")
            self.drain(0.15)
        except Exception:
            pass

    def run(self, command: str, timeout: float | None = None) -> CommandResult:
        token = secrets.token_hex(12)
        begin = f"__RV220W_BEGIN_{token}__"
        rc_prefix = f"__RV220W_RC_{token}__:"
        end = f"__RV220W_END_{token}__"

        # The leading newline puts the real begin marker on its own line even
        # if terminal echo could not be disabled and a prompt is present. The
        # parser accepts markers only as complete lines, so tokens embedded in
        # the echoed command cannot terminate collection.
        wrapped = (
            f"printf '\\n{begin}\\n'; "
            f"{{ {command}; }}; rv_rc=$?; "
            f"printf '\\n{rc_prefix}%s\\n{end}\\n' \"$rv_rc\"\r"
        )
        self.write(wrapped.encode("utf-8"))
        raw = self.read_until_line(end, timeout=timeout)
        lines = self._normalized_lines(raw)

        end_indexes = [index for index, line in enumerate(lines) if line == end]
        if not end_indexes:
            raise UartError("UART sentinel framing failed: no complete end line")
        end_index = end_indexes[-1]

        rc_index = -1
        status = -1
        for index in range(end_index - 1, -1, -1):
            match = re.fullmatch(re.escape(rc_prefix) + r"(\d+)", lines[index])
            if match is not None:
                rc_index = index
                status = int(match.group(1))
                break
        if rc_index < 0:
            tail = "\n".join(lines[max(0, end_index - 20) : end_index])
            raise UartError(f"UART command did not return a complete status line:\n{tail}")

        begin_index = -1
        for index in range(rc_index - 1, -1, -1):
            if lines[index] == begin:
                begin_index = index
                break
        if begin_index < 0:
            raise UartError("UART sentinel framing failed: no complete begin line")

        output = "\n".join(lines[begin_index + 1 : rc_index]).strip("\n")
        self.drain(0.08)
        return CommandResult(output=output, status=status)


def shell_quote(value: str) -> str:
    return "'" + value.replace("'", "'\\''") + "'"


def octal_escape(data: bytes) -> str:
    """Encode bytes for BusyBox ash printf %b without target decoders."""
    return "".join(f"\\{byte:03o}" for byte in data)


def upload_script(shell: UartShell, script_path: pathlib.Path) -> str:
    blob = script_path.read_bytes()
    digest = hashlib.sha256(blob).hexdigest()

    result = shell.run(f"rm -f {REMOTE_TEMP}")
    if result.status != 0:
        raise UartError("could not clear the temporary UART upload file")

    # Use only ash's printf %b and octal escapes. Upload commands use a
    # deliberately short acknowledgement wrapper and paced serial bursts. This
    # stays below the observed console line limit and avoids the continuation
    # prompt caused by the v1.6.1 long general-command wrapper.
    for offset in range(0, len(blob), UPLOAD_CHUNK_BYTES):
        chunk = octal_escape(blob[offset : offset + UPLOAD_CHUNK_BYTES])
        result = shell.run_upload_append(chunk, REMOTE_TEMP, timeout=15.0)
        if result.status != 0:
            raise UartError(f"UART octal upload failed at byte offset {offset}")

    finalize = shell.run(
        f"chmod 0755 {REMOTE_TEMP} && "
        f"rv_size=$(wc -c < {REMOTE_TEMP}) && printf 'size=%s\\n' \"$rv_size\" && "
        f"if command -v sha256sum >/dev/null 2>&1; then sha256sum {REMOTE_TEMP}; "
        f"else echo sha256=unavailable; fi && "
        f"/bin/sh -n {REMOTE_TEMP}",
        timeout=30.0,
    )
    if finalize.status != 0:
        raise UartError(f"target failed to finalize the octal UART upload:\n{finalize.output}")

    size_match = re.search(r"(?:^|\n)size=(\d+)(?:\n|$)", finalize.output)
    remote_size = int(size_match.group(1)) if size_match is not None else -1
    if remote_size != len(blob):
        raise UartError(
            f"UART upload size mismatch: host={len(blob)}, target={remote_size if remote_size >= 0 else '<missing>'}"
        )

    digest_match = re.search(r"(?:^|\n)([0-9a-fA-F]{64})\s+", finalize.output)
    if digest_match is not None and digest_match.group(1).lower() != digest:
        raise UartError(
            f"UART upload checksum mismatch: host={digest}, target={digest_match.group(1).lower()}"
        )
    return REMOTE_TEMP

def choose_remote_script(shell: UartShell, fallback: pathlib.Path, force_upload: bool) -> str:
    if force_upload:
        return upload_script(shell, fallback)
    result = shell.run(
        f"if [ -x {REMOTE_INSTALLED} ]; then echo {REMOTE_INSTALLED}; "
        f"elif [ -x {REMOTE_TEMP} ]; then echo {REMOTE_TEMP}; "
        "else echo MISSING; fi"
    )
    if result.status != 0:
        raise UartError(f"could not inspect target MDIO scanner path:\n{result.output}")
    selected = result.output.strip().splitlines()[-1] if result.output.strip() else ""
    if selected in (REMOTE_INSTALLED, REMOTE_TEMP):
        return selected
    return upload_script(shell, fallback)


def collect(shell: UartShell, remote_script: str, label: str, bus: str) -> tuple[str, str]:
    run = shell.run(
        f"{remote_script} {shell_quote(label)} {shell_quote(bus)}",
        timeout=180.0,
    )
    if run.status != 0:
        raise UartError(f"target MDIO scanner failed with status {run.status}:\n{run.output}")
    matches = REMOTE_OUTPUT_RE.findall(run.output)
    if not matches:
        raise UartError(f"target did not return an MDIO output path:\n{run.output}")
    remote_output = matches[-1]

    report = shell.run(f"cat {shell_quote(remote_output)}", timeout=60.0)
    if report.status != 0:
        raise UartError(f"could not retrieve target MDIO report over UART:\n{report.output}")
    if not report.output.startswith("RV220W MDIO identity/status scan"):
        raise UartError("UART report framing succeeded, but the payload header is invalid")
    return remote_output, report.output.rstrip("\n") + "\n"


def main() -> int:
    args = parse_args()
    label = normalize_label(args.label)
    bus = validate_bus(args.bus)
    scan_script = args.scan_script.resolve()
    if not scan_script.is_file():
        raise UartError(f"packaged MDIO scanner not found: {scan_script}")
    args.output_dir.mkdir(parents=True, exist_ok=True)

    transcript_path = args.transcript
    if transcript_path is None:
        transcript_path = args.output_dir / f"rv220w-mdio-uart-{label}-{utc_stamp()}.serial.log"
    transcript_path.parent.mkdir(parents=True, exist_ok=True)

    try:
        import serial  # type: ignore
    except ImportError as exc:
        raise UartError("pyserial is required; install CachyOS package python-pyserial") from exc

    transcript = transcript_path.open("ab")
    serial_handle = None
    shell = None
    try:
        try:
            serial_handle = serial.Serial(
                args.serial_port,
                baudrate=args.baud,
                bytesize=8,
                parity="N",
                stopbits=1,
                timeout=0.15,
                write_timeout=10,
                exclusive=True,
            )
        except TypeError:
            # Older pyserial builds do not expose exclusive= on every platform.
            serial_handle = serial.Serial(
                args.serial_port,
                baudrate=args.baud,
                bytesize=8,
                parity="N",
                stopbits=1,
                timeout=0.15,
                write_timeout=10,
            )
        try:
            serial_handle.dtr = False
            serial_handle.rts = False
        except OSError:
            pass

        shell = UartShell(serial_handle, args.timeout, transcript)
        shell.synchronize()
        remote_script = choose_remote_script(shell, scan_script, args.force_upload)
        remote_output, report = collect(shell, remote_script, label, bus)

        local_output = args.output_dir / pathlib.Path(remote_output).name
        partial = local_output.with_name(local_output.name + f".partial.{os.getpid()}")
        partial.write_text(report, encoding="utf-8")
        if partial.stat().st_size == 0:
            raise UartError("retrieved UART report is empty")
        partial.replace(local_output)
        print(local_output)
        print(f"serial transcript: {transcript_path}", file=sys.stderr)
        return 0
    finally:
        if shell is not None:
            shell.restore_echo()
        if serial_handle is not None:
            serial_handle.close()
        transcript.close()


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except UartError as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        raise SystemExit(1)
