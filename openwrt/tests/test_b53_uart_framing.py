#!/usr/bin/env python3
"""Regression test for passive B53 UART sentinels and payload validation."""
from __future__ import annotations

import importlib.util
import io
import re
import sys
from pathlib import Path

HELPER = Path(__file__).resolve().parents[1] / "scripts/host/rv220w_uart_collect_b53.py"
spec = importlib.util.spec_from_file_location("rv220w_uart_collect_b53", HELPER)
if spec is None or spec.loader is None:
    raise SystemExit("could not load B53 UART helper")
module = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = module
spec.loader.exec_module(module)


class FakeSerial:
    def __init__(self, echo: bool):
        self.echo = echo
        self.buffer = bytearray()

    @property
    def in_waiting(self) -> int:
        return len(self.buffer)

    def flush(self) -> None:
        return None

    def write(self, data: bytes) -> int:
        text = data.decode("utf-8", "replace")
        begin = re.search(r"(__RV220W_BEGIN_[0-9a-f]+__)", text)
        rc = re.search(r"(__RV220W_RC_[0-9a-f]+__:)", text)
        end = re.search(r"(__RV220W_END_[0-9a-f]+__)", text)
        if begin and rc and end:
            if self.echo:
                self.buffer.extend(b"root@rv220w:~# " + data + b"\r\n")
            else:
                self.buffer.extend(b"root@rv220w:~# ")
            response = (
                "\r\n"
                + begin.group(1)
                + "\r\nRV220W passive B53 topology snapshot\r\n"
                + "label=run3-NONE\r\n"
                + rc.group(1)
                + "0\r\n"
                + end.group(1)
                + "\r\nroot@rv220w:~# "
            )
            self.buffer.extend(response.encode("utf-8"))
        return len(data)

    def read(self, size: int) -> bytes:
        if not self.buffer:
            return b""
        size = min(size, len(self.buffer))
        data = bytes(self.buffer[:size])
        del self.buffer[:size]
        return data


for echo_enabled in (True, False):
    serial = FakeSerial(echo_enabled)
    shell = module.UartShell(serial, 2.0, io.BytesIO())
    result = shell.run(
        "/tmp/rv220w-b53-snapshot run3-NONE 8001180000001800", timeout=2.0
    )
    assert result.status == 0
    assert result.output.startswith("RV220W passive B53 topology snapshot")
    assert "label=run3-NONE" in result.output
    assert "__RV220W_END_" not in result.output

print("B53 UART echo/framing regression checks passed")
