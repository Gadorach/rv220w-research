#!/usr/bin/env python3
"""Create a conservative signature and hash inventory for a firmware image."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
from typing import Iterable

SIGNATURES: dict[str, bytes] = {
    'ELF': b'\x7fELF',
    'uImage': b'\x27\x05\x19\x56',
    'SquashFS little-endian': b'hsqs',
    'SquashFS big-endian': b'sqsh',
    'CramFS little-endian': b'\x45\x3d\xcd\x28',
    'CramFS big-endian': b'\x28\xcd\x3d\x45',
    'JFFS2 little-endian': b'\x85\x19',
    'JFFS2 big-endian': b'\x19\x85',
    'gzip': b'\x1f\x8b\x08',
    'xz': b'\xfd7zXZ\x00',
    'bzip2': b'BZh',
    'LZMA-alone common': b'\x5d\x00\x00',
    'Flattened device tree': b'\xd0\x0d\xfe\xed',
}


def digest(path: Path, algorithm: str) -> str:
    h = hashlib.new(algorithm)
    with path.open('rb') as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def find_all(data: bytes, needle: bytes) -> Iterable[int]:
    start = 0
    while True:
        pos = data.find(needle, start)
        if pos < 0:
            return
        yield pos
        start = pos + 1


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('image', type=Path)
    p.add_argument('--json', type=Path, dest='json_path')
    p.add_argument('--max-hits', type=int, default=100)
    args = p.parse_args()

    if not args.image.is_file():
        p.error(f'not a file: {args.image}')

    data = args.image.read_bytes()
    hits: dict[str, list[str]] = {}
    for name, sig in SIGNATURES.items():
        offsets = list(find_all(data, sig))[: args.max_hits]
        if offsets:
            hits[name] = [f'0x{x:x}' for x in offsets]

    report = {
        'path': str(args.image),
        'size_bytes': len(data),
        'size_hex': f'0x{len(data):x}',
        'sha256': digest(args.image, 'sha256'),
        'sha1': digest(args.image, 'sha1'),
        'md5': digest(args.image, 'md5'),
        'signatures': hits,
    }
    rendered = json.dumps(report, indent=2)
    print(rendered)
    if args.json_path:
        args.json_path.write_text(rendered + '\n', encoding='utf-8')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
