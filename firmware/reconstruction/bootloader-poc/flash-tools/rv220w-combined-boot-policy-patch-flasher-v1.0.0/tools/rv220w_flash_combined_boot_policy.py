#!/usr/bin/env python3
"""Apply both validated RV220W boot-policy patches in one operation.

The combined target:
  * disables the vendor startup hook that forcibly overwrites ``bootcmd``; and
  * bypasses only the invalid-firmware Sercomm HTTP-recovery call.

The active-low physical recovery-button path remains intact. The tool accepts
known stock, bootcmd-only, HTTP-only, or already-combined sector-0 baselines.
It writes only the first 128 KiB NOR erase sector, stages the exact live sector
for immediate rollback, constructs the selected target in a separate RAM
buffer, and uses no Ethernet or TFTP transfer.

No environment variable is saved and no automatic reset is performed.
"""
from __future__ import annotations

import argparse
import hashlib
import os
import re
import select
import sys
import termios
import threading
import time
import zlib
from pathlib import Path
from typing import BinaryIO

VERSION = "1.0.0"
PROMPT = b"rv200w#"
FLASH_BASE = 0xBDC00000
SECTOR_SIZE = 0x20000
HTTP_BRANCH_OFFSET = 0x13138
BOOTCMD_WORD_OFFSET = 0x13168
TARGET_RAM = 0x05500000
ROLLBACK_RAM = 0x05700000
STOCK_BRANCH = bytes.fromhex("04410003")   # bgez v0, 0xffffffffbfc13148
BYPASS_BRANCH = bytes.fromhex("10000003")  # b 0xffffffffbfc13148
STOCK_BOOTCMD_WORD = bytes.fromhex("03200008")
PATCH_BOOTCMD_WORD = bytes.fromhex("03e00008")
CONFIRM_TOKENS = {
    "combined": "RV220W_FLASH_COMBINED_BOOT_POLICY_PATCHES",
    "stock": "RV220W_RESTORE_STOCK_BOOT_SECTOR0",
    "bootcmd-only": "RV220W_RESTORE_BOOTCMD_ONLY_POLICY",
}


EXPECTED = {
    "stock": {
        "filename": "rv220w-boot-sector0-stock.bin",
        "size": SECTOR_SIZE,
        "sha256": "30e4d4a88230d362d1258ccffda8cda9a9c3dc92707e2656a7e98ec30d885748",
        "crc32": 0xCE86D667,
        "branch": STOCK_BRANCH,
        "bootcmd_word": STOCK_BOOTCMD_WORD,
    },
    "bootcmd-only": {
        "filename": "rv220w-boot-sector0-bootcmd-only.bin",
        "size": SECTOR_SIZE,
        "sha256": "3aa9f7c647212d1ae3b60dedef04e1b565cff3dacc6d2c7cb6c1d0bdd49c0611",
        "crc32": 0x36DB247B,
        "branch": STOCK_BRANCH,
        "bootcmd_word": PATCH_BOOTCMD_WORD,
    },
    "http-only": {
        "filename": "rv220w-boot-sector0-http-only.bin",
        "size": SECTOR_SIZE,
        "sha256": "4c6374978824ce0de88c06364a702817836587ddfaf3de3bde9336b147fa4a3c",
        "crc32": 0x4F2766C2,
        "branch": BYPASS_BRANCH,
        "bootcmd_word": STOCK_BOOTCMD_WORD,
    },
    "combined": {
        "filename": "rv220w-boot-sector0-combined.bin",
        "size": SECTOR_SIZE,
        "sha256": "c40913ebacfefaa228bd14de78d53f9aed56ac4a878a4e73f066d7243ac5d7eb",
        "crc32": 0xB77A94DE,
        "branch": BYPASS_BRANCH,
        "bootcmd_word": PATCH_BOOTCMD_WORD,
    },
}



class FlasherError(RuntimeError):
    pass


class Logger:
    def __init__(self, path: Path) -> None:
        path.parent.mkdir(parents=True, exist_ok=True)
        self.path = path
        self.fp: BinaryIO = path.open("ab", buffering=0)
        self.lock = threading.Lock()

    def close(self) -> None:
        self.fp.close()

    def write_bytes(self, data: bytes) -> None:
        with self.lock:
            self.fp.write(data)

    def line(self, text: str) -> None:
        stamp = time.strftime("%Y-%m-%dT%H:%M:%S%z")
        self.write_bytes(f"[{stamp}] {text}\n".encode("utf-8", "replace"))
        print(text, flush=True)


class SerialConsole:
    def __init__(self, port: str, baud: int, logger: Logger, live: bool = True) -> None:
        self.port = port
        self.baud = baud
        self.logger = logger
        self.live = live
        self.fd: int | None = None

    def __enter__(self) -> "SerialConsole":
        self.fd = os.open(self.port, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)
        attrs = termios.tcgetattr(self.fd)
        attrs[0] = 0
        attrs[1] = 0
        attrs[2] = termios.CLOCAL | termios.CREAD | termios.CS8
        attrs[3] = 0
        speed = {
            9600: termios.B9600,
            19200: termios.B19200,
            38400: termios.B38400,
            57600: termios.B57600,
            115200: termios.B115200,
            230400: getattr(termios, "B230400", termios.B115200),
            460800: getattr(termios, "B460800", termios.B115200),
            921600: getattr(termios, "B921600", termios.B115200),
        }.get(self.baud)
        if speed is None:
            raise FlasherError(f"unsupported baud rate: {self.baud}")
        attrs[4] = speed
        attrs[5] = speed
        attrs[6][termios.VMIN] = 0
        attrs[6][termios.VTIME] = 0
        termios.tcsetattr(self.fd, termios.TCSANOW, attrs)
        termios.tcflush(self.fd, termios.TCIOFLUSH)
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        if self.fd is not None:
            os.close(self.fd)
            self.fd = None

    def _require_fd(self) -> int:
        if self.fd is None:
            raise FlasherError("serial console is not open")
        return self.fd

    def send(self, data: bytes) -> None:
        fd = self._require_fd()
        view = memoryview(data)
        while view:
            try:
                count = os.write(fd, view)
                view = view[count:]
            except BlockingIOError:
                select.select([], [fd], [], 0.2)
        self.logger.write_bytes(b"\n[TX] " + data.replace(b"\r", b"<CR>") + b"\n")

    def _read_once(self, timeout: float) -> bytes:
        fd = self._require_fd()
        ready, _, _ = select.select([fd], [], [], timeout)
        if not ready:
            return b""
        try:
            data = os.read(fd, 65536)
        except BlockingIOError:
            return b""
        if data:
            self.logger.write_bytes(data)
            if self.live:
                sys.stdout.buffer.write(data)
                sys.stdout.buffer.flush()
        return data

    def drain(self, quiet_for: float = 0.15, max_time: float = 1.0) -> bytes:
        end = time.monotonic() + max_time
        last = time.monotonic()
        output = bytearray()
        while time.monotonic() < end:
            data = self._read_once(0.05)
            if data:
                output.extend(data)
                last = time.monotonic()
            elif time.monotonic() - last >= quiet_for:
                break
        return bytes(output)

    def wait_for_prompt(self, timeout: float) -> bytes:
        deadline = time.monotonic() + timeout
        output = bytearray()
        while time.monotonic() < deadline:
            data = self._read_once(min(0.25, max(0.01, deadline - time.monotonic())))
            if data:
                output.extend(data)
                if PROMPT in output:
                    return bytes(output)
        raise FlasherError(f"timed out waiting for U-Boot prompt after {timeout:.1f}s")

    def interrupt_to_prompt(self, timeout: float = 20.0) -> bytes:
        self.drain()
        deadline = time.monotonic() + timeout
        output = bytearray()
        while time.monotonic() < deadline:
            self.send(b"\x03\r")
            slice_end = min(deadline, time.monotonic() + 0.6)
            while time.monotonic() < slice_end:
                data = self._read_once(0.1)
                if data:
                    output.extend(data)
                    if PROMPT in output:
                        return bytes(output)
        raise FlasherError("unable to interrupt boot and reach rv200w#")

    def command(self, command: str, timeout: float = 10.0) -> str:
        self.drain()
        self.send(command.encode("ascii") + b"\r")
        return self.wait_for_prompt(timeout).decode("latin-1", "replace")


def validate_artifacts(artifact_dir: Path) -> dict[str, Path]:
    paths: dict[str, Path] = {}
    blobs: dict[str, bytes] = {}
    for name, spec in EXPECTED.items():
        path = artifact_dir / str(spec["filename"])
        if not path.is_file():
            raise FlasherError(f"missing artifact: {path}")
        data = path.read_bytes()
        if len(data) != spec["size"]:
            raise FlasherError(f"wrong size for {path.name}: {len(data)}")
        actual_sha = hashlib.sha256(data).hexdigest()
        if actual_sha != spec["sha256"]:
            raise FlasherError(f"SHA-256 mismatch for {path.name}: {actual_sha}")
        actual_crc = zlib.crc32(data) & 0xFFFFFFFF
        if actual_crc != spec["crc32"]:
            raise FlasherError(f"CRC32 mismatch for {path.name}: {actual_crc:08x}")
        if data[HTTP_BRANCH_OFFSET:HTTP_BRANCH_OFFSET + 4] != spec["branch"]:
            raise FlasherError(f"HTTP branch mismatch in {path.name}")
        if data[BOOTCMD_WORD_OFFSET:BOOTCMD_WORD_OFFSET + 4] != spec["bootcmd_word"]:
            raise FlasherError(f"bootcmd suppression word mismatch in {path.name}")
        paths[name] = path
        blobs[name] = data

    stock = blobs["stock"]
    expected_diffs = {
        "bootcmd-only": [BOOTCMD_WORD_OFFSET + 1],
        "http-only": [HTTP_BRANCH_OFFSET, HTTP_BRANCH_OFFSET + 1],
        "combined": [HTTP_BRANCH_OFFSET, HTTP_BRANCH_OFFSET + 1, BOOTCMD_WORD_OFFSET + 1],
    }
    for name, wanted in expected_diffs.items():
        diffs = [i for i, pair in enumerate(zip(stock, blobs[name])) if pair[0] != pair[1]]
        if diffs != wanted:
            raise FlasherError(f"{name} differs from stock at unexpected offsets: {diffs[:20]}")
    return paths


def parse_crc32(output: str) -> int:
    matches = re.findall(r"==>\s*([0-9a-fA-F]{8})", output)
    if not matches:
        raise FlasherError(f"could not parse U-Boot CRC32 output:\n{output}")
    return int(matches[-1], 16)


def parse_md_bytes(output: str, address: int, count: int) -> bytes:
    wanted = f"{address:08x}".lower()
    for line in output.splitlines():
        normalized = line.strip().lower()
        if not normalized.startswith(wanted + ":"):
            continue
        pairs = re.findall(r"\b[0-9a-f]{2}\b", normalized.split(":", 1)[1])
        if len(pairs) >= count:
            return bytes(int(value, 16) for value in pairs[:count])
    raise FlasherError(f"could not parse md.b bytes at 0x{address:08x}")


def ensure_no_command_error(output: str, context: str) -> None:
    patterns = [
        r"(?im)^\s*usage:",
        r"(?im)unknown command",
        r"(?im)^\s*error(?:\s*:|\b)",
        r"(?im)\bfailed\b",
        r"(?im)\bfailure\b",
        r"(?im)\btimed out\b",
        r"(?im)^\s*timeout(?:\s*:|\s*$)",
        r"(?im)\bretry count exceeded\b",
        r"(?im)\bcan't\b",
        r"(?im)\bcannot\b",
        r"(?im)\bbad sector\b",
    ]
    for pattern in patterns:
        if re.search(pattern, output):
            raise FlasherError(f"{context} reported an error matching {pattern!r}:\n{output}")


def validate_flinfo(output: str) -> None:
    ensure_no_command_error(output, "flinfo")
    required = [
        "CFI conformant FLASH",
        "Size: 32 MB in 256 Sectors",
        "BDC00000 (RO)",
        "BDC20000 (RO)",
        "BDC40000 (RO)",
        "BDC60000 (RO)",
        "BFBE0000 (RO)",
    ]
    missing = [item for item in required if item.lower() not in output.lower()]
    if missing:
        raise FlasherError(f"flinfo output is missing expected RV220W geometry: {missing}\n{output}")


def run_crc(console: SerialConsole, address: int, size: int) -> int:
    return parse_crc32(console.command(f"crc32 0x{address:08x} 0x{size:x}", timeout=30.0))


def read_word(console: SerialConsole, address: int) -> bytes:
    output = console.command(f"md.b 0x{address:08x} 4", timeout=10.0)
    return parse_md_bytes(output, address, 4)


def copy_bytes(console: SerialConsole, source: int, destination: int, size: int, context: str) -> None:
    output = console.command(f"cp.b 0x{source:08x} 0x{destination:08x} 0x{size:x}", timeout=90.0)
    ensure_no_command_error(output, context)


def compare_memory(console: SerialConsole, source: int, destination: int, size: int, context: str) -> None:
    output = console.command(f"cmp.b 0x{source:08x} 0x{destination:08x} 0x{size:x}", timeout=90.0)
    ensure_no_command_error(output, context)
    if "were the same" not in output.lower():
        raise FlasherError(f"{context} did not report equality:\n{output}")


def write_ram_byte(console: SerialConsole, address: int, value: int) -> None:
    output = console.command(f"mw.b 0x{address:08x} 0x{value:02x} 1", timeout=10.0)
    ensure_no_command_error(output, "RAM byte write")


def verify_ram_image(console: SerialConsole, name: str, address: int) -> None:
    spec = EXPECTED[name]
    crc = run_crc(console, address, SECTOR_SIZE)
    if crc != spec["crc32"]:
        raise FlasherError(f"{name} RAM CRC32 {crc:08x}, expected {spec['crc32']:08x}")
    branch = read_word(console, address + HTTP_BRANCH_OFFSET)
    if branch != spec["branch"]:
        raise FlasherError(f"{name} RAM branch {branch.hex()}, expected {spec['branch'].hex()}")
    bootcmd_word = read_word(console, address + BOOTCMD_WORD_OFFSET)
    if bootcmd_word != spec["bootcmd_word"]:
        raise FlasherError(
            f"{name} RAM bootcmd word {bootcmd_word.hex()}, expected {spec['bootcmd_word'].hex()}"
        )


def apply_target_bytes(console: SerialConsole, address: int, target: str) -> None:
    spec = EXPECTED[target]
    branch = bytes(spec["branch"])
    bootcmd = bytes(spec["bootcmd_word"])
    write_ram_byte(console, address + HTTP_BRANCH_OFFSET, branch[0])
    write_ram_byte(console, address + HTTP_BRANCH_OFFSET + 1, branch[1])
    # Only byte 1 differs between the two jr instructions.
    write_ram_byte(console, address + BOOTCMD_WORD_OFFSET + 1, bootcmd[1])


def stage_verified_ram_images(
    console: SerialConsole, logger: Logger, live_name: str, target: str
) -> None:
    """Retain the exact live sector for rollback and construct target in RAM."""
    logger.line(f"Copying exact live {live_name} sector 0 into the rollback RAM buffer")
    copy_bytes(console, FLASH_BASE, ROLLBACK_RAM, SECTOR_SIZE, "NOR-to-RAM copy")
    compare_memory(console, FLASH_BASE, ROLLBACK_RAM, SECTOR_SIZE, "NOR-to-RAM compare")
    verify_ram_image(console, live_name, ROLLBACK_RAM)

    logger.line(f"Constructing and verifying the {target} image in a separate RAM buffer")
    copy_bytes(console, ROLLBACK_RAM, TARGET_RAM, SECTOR_SIZE, "RAM-to-RAM copy")
    apply_target_bytes(console, TARGET_RAM, target)
    verify_ram_image(console, target, TARGET_RAM)

    logger.line("Exact rollback and requested target sectors are verified and resident in RAM")


def protect(console: SerialConsole, enable: bool) -> None:
    action = "on" if enable else "off"
    output = console.command(f"protect {action} 0x{FLASH_BASE:08x} +0x{SECTOR_SIZE:x}", timeout=30.0)
    ensure_no_command_error(output, f"protect {action}")
    expected = "Protected 1 sectors" if enable else "Un-Protected 1 sectors"
    if expected.lower() not in output.lower():
        raise FlasherError(f"unexpected protect output; missing {expected!r}:\n{output}")


def erase_sector(console: SerialConsole) -> None:
    output = console.command(f"erase 0x{FLASH_BASE:08x} +0x{SECTOR_SIZE:x}", timeout=180.0)
    ensure_no_command_error(output, "erase")
    if "erased 1 sectors" not in output.lower():
        raise FlasherError(f"erase did not confirm one sector:\n{output}")


def program_sector(console: SerialConsole, source: int) -> None:
    output = console.command(f"cp.b 0x{source:08x} 0x{FLASH_BASE:08x} 0x{SECTOR_SIZE:x}", timeout=180.0)
    ensure_no_command_error(output, "flash program")
    if "copy to flash" not in output.lower() or "done" not in output.lower():
        raise FlasherError(f"flash copy did not report success:\n{output}")


def compare_sector(console: SerialConsole, source: int) -> None:
    output = console.command(f"cmp.b 0x{source:08x} 0x{FLASH_BASE:08x} 0x{SECTOR_SIZE:x}", timeout=90.0)
    ensure_no_command_error(output, "flash compare")
    if "were the same" not in output.lower():
        raise FlasherError(f"flash compare did not report equality:\n{output}")


def verify_flash(console: SerialConsole, target: str) -> None:
    spec = EXPECTED[target]
    crc = run_crc(console, FLASH_BASE, SECTOR_SIZE)
    if crc != spec["crc32"]:
        raise FlasherError(f"flash CRC32 {crc:08x}, expected {spec['crc32']:08x} for {target}")
    branch = read_word(console, FLASH_BASE + HTTP_BRANCH_OFFSET)
    if branch != spec["branch"]:
        raise FlasherError(f"flash branch {branch.hex()}, expected {spec['branch'].hex()}")
    bootcmd_word = read_word(console, FLASH_BASE + BOOTCMD_WORD_OFFSET)
    if bootcmd_word != spec["bootcmd_word"]:
        raise FlasherError(
            f"flash bootcmd word {bootcmd_word.hex()}, expected {spec['bootcmd_word'].hex()}"
        )


def write_target(console: SerialConsole, target: str, logger: Logger) -> None:
    source = TARGET_RAM
    logger.line(f"Writing only NOR sector 0: 0x{FLASH_BASE:08x}-0x{FLASH_BASE + SECTOR_SIZE - 1:08x}")
    protect(console, enable=False)
    try:
        erase_sector(console)
        program_sector(console, source)
        compare_sector(console, source)
        verify_flash(console, target)
    finally:
        try:
            protect(console, enable=True)
        except Exception as exc:
            logger.line(f"WARNING: could not re-protect sector after operation: {exc}")


def attempt_rollback(console: SerialConsole, logger: Logger, live_name: str) -> bool:
    logger.line(f"Attempting immediate rollback to exact verified pre-write state: {live_name}")
    try:
        logger.line(f"Writing rollback sector from RAM at 0x{ROLLBACK_RAM:08x}")
        protect(console, enable=False)
        try:
            erase_sector(console)
            program_sector(console, ROLLBACK_RAM)
            compare_sector(console, ROLLBACK_RAM)
            verify_flash(console, live_name)
        finally:
            protect(console, enable=True)
        logger.line(f"Rollback verified: flash restored to {live_name}")
        return True
    except Exception as exc:
        logger.line(f"ROLLBACK FAILED: {exc}")
        return False


def parse_args(argv: list[str]) -> argparse.Namespace:
    package_root = Path(__file__).resolve().parent.parent
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--version", action="version", version=f"%(prog)s {VERSION}")
    parser.add_argument("--execute", action="store_true", help="perform the destructive flash operation")
    parser.add_argument("--stage-only", action="store_true", help="verify both RAM images without unlocking, erasing, or programming NOR")
    parser.add_argument(
        "--target",
        choices=("combined", "stock", "bootcmd-only"),
        default="combined",
        help="combined applies both validated patches; stock restores sector 0; bootcmd-only retains only bootcmd suppression",
    )
    parser.add_argument("--confirm", default="", help="exact destructive-operation token")
    parser.add_argument("--external-recovery-ready", action="store_true", help="acknowledge external TSOP56 recovery is physically ready")
    parser.add_argument("--artifact-dir", type=Path, default=package_root / "artifacts")
    parser.add_argument("--serial", default="/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_A50285BI-if00-port0")
    parser.add_argument("--baud", type=int, default=115200)
    parser.add_argument("--log-dir", type=Path, default=package_root / "logs")
    parser.add_argument("--quiet-serial", action="store_true")
    return parser.parse_args(argv)


def print_plan(args: argparse.Namespace, paths: dict[str, Path]) -> None:
    token = CONFIRM_TOKENS[args.target]
    print(f"RV220W combined boot-policy patch flasher v{VERSION}")
    print("Offline artifact verification: PASS")
    print(f"Target: {args.target}")
    print(f"Source identity: {paths[args.target]}")
    print(f"Flash write range: 0x{FLASH_BASE:08x}-0x{FLASH_BASE + SECTOR_SIZE - 1:08x}")
    print(f"Erase/program size: 0x{SECTOR_SIZE:x} ({SECTOR_SIZE} bytes)")
    print("Combined target changes:")
    print("  0x13138: 04 41 00 03 -> 10 00 00 03 (skip invalid-magic HTTP recovery)")
    print("  0x13168: 03 20 00 08 -> 03 e0 00 08 (do not overwrite bootcmd)")
    print("Physical active-low recovery-button download path is not modified.")
    print("No environment save and no automatic reset will occur.")
    if not args.execute and not args.stage_only:
        print("\nDry run only. Hardware was not contacted.")
        print("To test the complete non-destructive staging path, use:")
        print("  --stage-only")
        print("To execute the flash operation, use:")
        print(f"  --execute --external-recovery-ready --confirm {token}")
    elif args.stage_only:
        print("Stage-only mode: NOR will remain protected and unchanged.")


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    paths = validate_artifacts(args.artifact_dir.resolve())
    print_plan(args, paths)
    if not args.execute and not args.stage_only:
        return 0
    if args.execute and args.stage_only:
        raise FlasherError("--execute and --stage-only are mutually exclusive")

    expected_token = CONFIRM_TOKENS[args.target]
    if args.execute:
        if args.confirm != expected_token:
            raise FlasherError(f"confirmation token must be exactly: {expected_token}")
        if not args.external_recovery_ready:
            raise FlasherError("--external-recovery-ready is required")
    if not Path(args.serial).exists():
        raise FlasherError(f"serial device does not exist: {args.serial}")

    args.log_dir.mkdir(parents=True, exist_ok=True)
    timestamp = time.strftime("%Y%m%dT%H%M%S")
    log_path = args.log_dir / f"rv220w-combined-boot-policy-{args.target}-{timestamp}.log"
    logger = Logger(log_path)
    destructive_started = False
    try:
        logger.line(f"RV220W combined boot-policy patch flasher v{VERSION}; target={args.target}")
        logger.line(f"Serial log: {log_path}")
        with SerialConsole(args.serial, args.baud, logger, live=not args.quiet_serial) as console:
            logger.line("Interrupting boot and waiting for rv200w#")
            console.interrupt_to_prompt()
            console.command("base 0")
            validate_flinfo(console.command("flinfo", timeout=20.0))

            live_crc = run_crc(console, FLASH_BASE, SECTOR_SIZE)
            live_branch = read_word(console, FLASH_BASE + HTTP_BRANCH_OFFSET)
            live_bootcmd = read_word(console, FLASH_BASE + BOOTCMD_WORD_OFFSET)
            logger.line(f"Live sector CRC32={live_crc:08x}; branch={live_branch.hex()}; bootcmd={live_bootcmd.hex()}")

            known = None
            for name, spec in EXPECTED.items():
                if (
                    live_crc == spec["crc32"]
                    and live_branch == spec["branch"]
                    and live_bootcmd == spec["bootcmd_word"]
                ):
                    known = name
                    break
            if known is None:
                raise FlasherError(
                    "live sector is not one of the four hash-gated known baselines: "
                    "stock, bootcmd-only, http-only, or combined"
                )
            logger.line(f"Recognized live sector identity: {known}")
            if known == args.target:
                logger.line(f"Flash already matches target {args.target}; no write performed")
                return 0

            stage_verified_ram_images(console, logger, known, args.target)
            if args.stage_only:
                logger.line("STAGE-ONLY PASS: both RAM images verified; NOR remained protected and unchanged")
                return 0

            destructive_started = True
            try:
                write_target(console, args.target, logger)
            except BaseException:
                attempt_rollback(console, logger, known)
                raise

            logger.line(f"SUCCESS: flash sector 0 now matches {args.target}")
            logger.line("The router was not reset and no environment variable was saved")
            logger.line("Review the complete log before manually issuing reset")
        return 0
    finally:
        logger.line(f"Operation complete; destructive_started={destructive_started}")
        logger.close()


if __name__ == "__main__":
    try:
        raise SystemExit(main(sys.argv[1:]))
    except KeyboardInterrupt:
        print("\nInterrupted by user", file=sys.stderr)
        raise SystemExit(130)
    except FlasherError as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        raise SystemExit(1)
