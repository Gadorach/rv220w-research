#!/usr/bin/env python3
"""Write a deterministic SHA-256 manifest for a directory tree."""
from __future__ import annotations

import argparse
import hashlib
from pathlib import Path


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open('rb') as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('root', type=Path, nargs='?', default=Path('.'))
    p.add_argument('--output', type=Path, default=Path('SHA256SUMS'))
    args = p.parse_args()
    root = args.root.resolve()
    out = args.output.resolve()
    lines: list[str] = []
    for path in sorted(root.rglob('*')):
        if not path.is_file() or path.resolve() == out:
            continue
        rel = path.resolve().relative_to(root)
        if '.git' in rel.parts:
            continue
        lines.append(f'{sha256(path)}  {rel.as_posix()}')
    out.write_text('\n'.join(lines) + '\n', encoding='utf-8')
    print(f'Wrote {len(lines)} entries to {out}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
