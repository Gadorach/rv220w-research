#!/usr/bin/env python3
"""Create JSON evidence metadata and SHA-256 hashes for files supplied on the command line."""
from __future__ import annotations

import argparse
import datetime as dt
import hashlib
import json
from pathlib import Path


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open('rb') as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('files', type=Path, nargs='+')
    p.add_argument('-o', '--output', type=Path, default=Path('evidence-manifest.json'))
    args = p.parse_args()
    entries = []
    for path in args.files:
        if not path.is_file():
            p.error(f'not a file: {path}')
        st = path.stat()
        entries.append({
            'path': str(path),
            'size_bytes': st.st_size,
            'sha256': sha256(path),
            'mtime_utc': dt.datetime.fromtimestamp(st.st_mtime, dt.timezone.utc).isoformat(),
        })
    out = {
        'created_utc': dt.datetime.now(dt.timezone.utc).isoformat(),
        'entries': entries,
    }
    args.output.write_text(json.dumps(out, indent=2) + '\n', encoding='utf-8')
    print(f'Wrote {args.output}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
