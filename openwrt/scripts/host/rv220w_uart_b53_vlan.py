#!/usr/bin/env python3
"""Read or change the RV220W BCM53115 VLAN/PVID diagnostic state over UART.

The uploaded target helper is RAM-only.  Writes are limited to port-0/5
PVID registers and VLAN-table entries 0/1, with automatic original-state
capture and restoration support.
"""
from __future__ import annotations

import argparse
import datetime as dt
import hashlib
import pathlib
import re
import sys

from rv220w_uart_collect_b53 import UartError, UartShell, octal_escape, shell_quote

REMOTE_INSTALLED = "/usr/sbin/rv220w-b53-vlan-state"
REMOTE_TEMP = "/tmp/rv220w-b53-vlan-state"
SAFE_BUS = re.compile(r"^[A-Za-z0-9._:-]+$")
ACTIONS = (
    "show",
    "set-p5-pvid0",
    "set-domain-vlan0",
    "set-domain-vlan1",
    "restore",
)
UPLOAD_CHUNK_BYTES = 24


def utc_stamp() -> str:
    return dt.datetime.now(dt.timezone.utc).strftime("%Y%m%dT%H%M%SZ")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("serial_port")
    parser.add_argument("helper_script", type=pathlib.Path)
    parser.add_argument("action", choices=ACTIONS)
    parser.add_argument("bus", nargs="?", default="8001180000001800")
    parser.add_argument("--baud", type=int, default=115200)
    parser.add_argument("--timeout", type=float, default=120.0)
    parser.add_argument("--transcript", type=pathlib.Path)
    parser.add_argument("--force-upload", action="store_true")
    return parser.parse_args()


def upload_helper(shell: UartShell, helper: pathlib.Path) -> str:
    blob = helper.read_bytes()
    digest = hashlib.sha256(blob).hexdigest()
    result = shell.run(f"rm -f {REMOTE_TEMP}")
    if result.status != 0:
        raise UartError("could not clear temporary VLAN helper")
    for offset in range(0, len(blob), UPLOAD_CHUNK_BYTES):
        chunk = octal_escape(blob[offset : offset + UPLOAD_CHUNK_BYTES])
        result = shell.run_upload_append(chunk, REMOTE_TEMP, timeout=15.0)
        if result.status != 0:
            raise UartError(f"UART upload failed at byte offset {offset}")
    result = shell.run(
        f"chmod 0755 {REMOTE_TEMP} && "
        f"rv_size=$(wc -c < {REMOTE_TEMP}) && printf 'size=%s\\n' \"$rv_size\" && "
        f"sha256sum {REMOTE_TEMP} 2>/dev/null || true && /bin/sh -n {REMOTE_TEMP}",
        timeout=30.0,
    )
    if result.status != 0:
        raise UartError(f"target rejected VLAN helper:\n{result.output}")
    match = re.search(r"(?:^|\n)size=(\d+)(?:\n|$)", result.output)
    if match is None or int(match.group(1)) != len(blob):
        raise UartError("VLAN helper upload size mismatch")
    digest_match = re.search(r"(?:^|\n)([0-9a-fA-F]{64})\s+", result.output)
    if digest_match and digest_match.group(1).lower() != digest:
        raise UartError("VLAN helper upload checksum mismatch")
    return REMOTE_TEMP


def choose_helper(shell: UartShell, helper: pathlib.Path, force: bool) -> str:
    if force:
        return upload_helper(shell, helper)
    result = shell.run(
        f"if [ -x {REMOTE_INSTALLED} ]; then echo {REMOTE_INSTALLED}; "
        f"elif [ -x {REMOTE_TEMP} ]; then echo {REMOTE_TEMP}; else echo MISSING; fi"
    )
    selected = result.output.strip().splitlines()[-1] if result.output.strip() else ""
    if result.status == 0 and selected in (REMOTE_INSTALLED, REMOTE_TEMP):
        return selected
    return upload_helper(shell, helper)


def main() -> int:
    args = parse_args()
    if not SAFE_BUS.fullmatch(args.bus):
        raise UartError(f"unsafe MDIO bus selector: {args.bus!r}")
    helper = args.helper_script.resolve()
    if not helper.is_file():
        raise UartError(f"packaged VLAN helper not found: {helper}")

    transcript_path = args.transcript
    if transcript_path is None:
        transcript_path = pathlib.Path.cwd() / (
            f"rv220w-b53-vlan-{args.action}-{utc_stamp()}.serial.log"
        )
    transcript_path.parent.mkdir(parents=True, exist_ok=True)

    try:
        import serial  # type: ignore
    except ImportError as exc:
        raise UartError("pyserial is required; install CachyOS package python-pyserial") from exc

    transcript = transcript_path.open("ab")
    serial_handle = None
    shell = None
    try:
        kwargs = dict(
            port=args.serial_port,
            baudrate=args.baud,
            bytesize=8,
            parity="N",
            stopbits=1,
            timeout=0.15,
            write_timeout=10,
        )
        try:
            serial_handle = serial.Serial(exclusive=True, **kwargs)
        except TypeError:
            serial_handle = serial.Serial(**kwargs)
        try:
            serial_handle.dtr = False
            serial_handle.rts = False
        except OSError:
            pass
        shell = UartShell(serial_handle, args.timeout, transcript)
        shell.synchronize()
        remote = choose_helper(shell, helper, args.force_upload)
        confirm = "" if args.action == "show" else " RAM_ONLY_CONFIRM"
        command = (
            f"{shell_quote(remote)} {shell_quote(args.action)} "
            f"{shell_quote(args.bus)}{confirm}"
        )
        result = shell.run(command, timeout=args.timeout)
        if result.status != 0:
            raise UartError(
                f"target VLAN helper failed with status {result.status}:\n{result.output}"
            )
        print(result.output)
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
