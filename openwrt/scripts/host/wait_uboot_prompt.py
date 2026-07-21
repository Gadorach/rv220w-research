#!/usr/bin/env python3
"""Interrupt RV220W U-Boot automatically after a user-initiated power cycle.

The helper only sends carriage return and Ctrl-C at 115200 8N1. It does not
issue any U-Boot command. It exits after observing the ``rv200w# `` prompt, so
the validated flash dumper can reopen the same serial device.
"""
from __future__ import annotations

import argparse
import pathlib
import sys
import time

PROMPT = b"rv200w# "


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("port")
    p.add_argument("--baud", type=int, default=115200)
    p.add_argument("--timeout", type=float, default=120.0)
    p.add_argument("--log", type=pathlib.Path)
    return p.parse_args()


def main() -> int:
    args = parse_args()
    try:
        import serial  # type: ignore
    except ImportError:
        print("pyserial is required: python -m pip install pyserial", file=sys.stderr)
        return 2

    log = args.log.open("ab") if args.log else None
    try:
        with serial.Serial(
            args.port,
            args.baud,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=0.05,
            write_timeout=2.0,
            rtscts=False,
            dsrdtr=False,
            xonxoff=False,
        ) as ser:
            ser.reset_input_buffer()
            ser.write(b"\r")
            ser.flush()
            deadline = time.monotonic() + args.timeout
            last_interrupt = 0.0
            buffer = bytearray()
            announced = False
            while time.monotonic() < deadline:
                waiting = ser.in_waiting
                data = ser.read(max(1, min(waiting or 1, 65536)))
                if data:
                    buffer.extend(data)
                    if len(buffer) > 16384:
                        del buffer[:-8192]
                    if log:
                        log.write(data)
                        log.flush()
                    sys.stdout.buffer.write(data)
                    sys.stdout.buffer.flush()
                    if bytes(buffer).endswith(PROMPT):
                        print("\n[rv220w] U-Boot prompt captured.", file=sys.stderr)
                        return 0
                if not announced and time.monotonic() + 1.0 < deadline:
                    print("\n[rv220w] Power-cycle the router now; Ctrl-C is being sent automatically.", file=sys.stderr)
                    announced = True
                now = time.monotonic()
                tail = bytes(buffer[-4096:])
                interval = 0.08 if (b"U-Boot" in tail or b"checking fw magic" in tail or b"Image name" in tail) else 0.5
                if now - last_interrupt >= interval:
                    ser.write(b"\x03")
                    ser.flush()
                    last_interrupt = now
                time.sleep(0.002)
    except OSError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    finally:
        if log:
            log.close()
    print(f"error: did not observe {PROMPT!r} within {args.timeout:g} seconds", file=sys.stderr)
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
