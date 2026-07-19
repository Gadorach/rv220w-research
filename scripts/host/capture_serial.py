#!/usr/bin/env python3
"""Receive-only serial logger for first-contact boot captures.

The script never writes to the serial port. Install pyserial with:
    python -m pip install pyserial
"""
from __future__ import annotations

import argparse
import datetime as dt
import pathlib
import sys


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('port', help='Serial device, e.g. /dev/ttyUSB0')
    p.add_argument('--baud', type=int, default=115200)
    p.add_argument('--output', type=pathlib.Path, default=None)
    p.add_argument('--timeout', type=float, default=0.2)
    return p.parse_args()


def main() -> int:
    args = parse_args()
    try:
        import serial  # type: ignore
    except ImportError:
        print('pyserial is required: python -m pip install pyserial', file=sys.stderr)
        return 2

    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    output = args.output or pathlib.Path(f'{stamp}-rv220w-{args.baud}-8n1.log')

    try:
        ser = serial.Serial(
            port=args.port,
            baudrate=args.baud,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=args.timeout,
            write_timeout=0,
            rtscts=False,
            dsrdtr=False,
            xonxoff=False,
        )
    except Exception as exc:
        print(f'Unable to open {args.port}: {exc}', file=sys.stderr)
        return 1

    print(f'Receive-only capture: {args.port} at {args.baud} 8N1 -> {output}')
    print('Press Ctrl-C to stop. The script does not transmit data.')
    try:
        with output.open('ab', buffering=0) as out:
            while True:
                data = ser.read(4096)
                if data:
                    out.write(data)
                    sys.stdout.buffer.write(data)
                    sys.stdout.buffer.flush()
    except KeyboardInterrupt:
        print('\nCapture stopped.')
    finally:
        ser.close()
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
