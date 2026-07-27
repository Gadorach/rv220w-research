#!/usr/bin/env python3
from __future__ import annotations

import importlib.util
import pathlib
import re
import subprocess
import sys
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[1]


class FakeUploadSerial:
    """A console that rejects input lines longer than the observed safe limit."""

    def __init__(self, max_line: int = 240):
        self.max_line = max_line
        self.pending = bytearray()
        self.buffer = bytearray()
        self.max_seen = 0

    @property
    def in_waiting(self) -> int:
        return len(self.buffer)

    def flush(self) -> None:
        return None

    def write(self, data: bytes) -> int:
        self.pending.extend(data)
        while b"\r" in self.pending:
            raw, _, rest = self.pending.partition(b"\r")
            self.pending[:] = rest
            self.max_seen = max(self.max_seen, len(raw) + 1)
            # Simulate a console that enters continuation rather than executing
            # an oversized/truncated command.
            if len(raw) + 1 > self.max_line:
                self.buffer.extend(b"> ")
                continue
            command = raw.decode("ascii")
            completed = subprocess.run(
                ["/bin/sh", "-c", command],
                text=True,
                capture_output=True,
                check=False,
            )
            # Echo the complete input command before target output. The parser
            # must not mistake the marker embedded in source text for output.
            self.buffer.extend(b"root@rv220w:~# " + raw + b"\r\n")
            self.buffer.extend(completed.stdout.encode())
            self.buffer.extend(completed.stderr.encode())
        return len(data)

    def read(self, size: int) -> bytes:
        if not self.buffer:
            return b""
        size = min(size, len(self.buffer))
        data = bytes(self.buffer[:size])
        del self.buffer[:size]
        return data


for filename in ("rv220w_uart_collect_mdio.py", "rv220w_uart_collect_b53.py"):
    path = ROOT / "scripts/host" / filename
    spec = importlib.util.spec_from_file_location(filename.replace(".py", ""), path)
    assert spec and spec.loader
    mod = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = mod
    spec.loader.exec_module(mod)

    serial = FakeUploadSerial(max_line=mod.UPLOAD_MAX_COMMAND_BYTES)
    uart = mod.UartShell(serial, 2.0, None)
    # Eliminate deliberate wall-clock pacing in the test while exercising the
    # real command builder, length guard, acknowledgement parser, and target sh.
    uart.write_paced = serial.write
    uart.drain = lambda duration=0.0: b""

    class LocalShell:
        def run(self, command: str, timeout=None):
            completed = subprocess.run(
                ["/bin/sh", "-c", command],
                text=True,
                capture_output=True,
                timeout=timeout,
                check=False,
            )
            return mod.CommandResult(
                completed.stdout + completed.stderr, completed.returncode
            )

        def run_upload_append(self, escaped_chunk: str, remote_path: str, timeout=15.0):
            return uart.run_upload_append(escaped_chunk, remote_path, timeout)

    payload = (
        b"#!/bin/sh\n"
        b"# quote:' slash:\\\n"
        b"printf '%s\\n' 'short-command octal transport ok'\n"
    ) * 8
    with tempfile.NamedTemporaryFile(delete=False) as source:
        source.write(payload)
        source_path = pathlib.Path(source.name)
    remote = pathlib.Path(mod.REMOTE_TEMP)
    try:
        remote.unlink(missing_ok=True)
        returned = mod.upload_script(LocalShell(), source_path)
        if returned != mod.REMOTE_TEMP:
            raise SystemExit(f"{filename}: unexpected remote path {returned}")
        if remote.read_bytes() != payload:
            raise SystemExit(f"{filename}: reconstructed bytes differ")
        subprocess.run(["/bin/sh", "-n", str(remote)], check=True)
        if serial.max_seen > mod.UPLOAD_MAX_COMMAND_BYTES:
            raise SystemExit(
                f"{filename}: command length {serial.max_seen} exceeded "
                f"{mod.UPLOAD_MAX_COMMAND_BYTES}"
            )
    finally:
        source_path.unlink(missing_ok=True)
        remote.unlink(missing_ok=True)

print("bounded UART octal upload regression checks passed")
