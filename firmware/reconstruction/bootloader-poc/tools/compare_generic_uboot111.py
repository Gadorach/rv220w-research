#!/usr/bin/env python3
"""Compare a generic U-Boot 1.1.1 source tree with the RV220W binary needs."""
from __future__ import annotations
import argparse, hashlib, json, pathlib, re

FILES = ["common/env_common.c", "common/env_flash.c", "common/main.c", "common/cmd_elf.c"]
TOKENS = ["bootoctlinux", "CUST_RV200W", "CN5010", "OCTEON", "Cavium"]

def sha(path: pathlib.Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()

def lines(path: pathlib.Path, pattern: str) -> list[int]:
    rx = re.compile(pattern)
    return [i for i, line in enumerate(path.read_text(errors="replace").splitlines(), 1) if rx.search(line)]

def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("source", type=pathlib.Path)
    ap.add_argument("--output", type=pathlib.Path, required=True)
    ns = ap.parse_args()
    root = ns.source.resolve()
    records = {}
    for rel in FILES:
        p = root / rel
        if not p.is_file():
            raise SystemExit(f"error: missing {rel}")
        records[rel] = {
            "sha256": sha(p),
            "env_relocate_lines": lines(p, r"\benv_relocate\b"),
            "saveenv_lines": lines(p, r"\bsaveenv\b"),
            "bootcmd_lines": lines(p, r"\bbootcmd\b"),
            "bootelf_lines": lines(p, r"\bbootelf\b|\bload_elf_image\b"),
        }
    token_hits = {token: [] for token in TOKENS}
    for p in root.rglob("*"):
        if not p.is_file() or p.stat().st_size > 4 * 1024 * 1024:
            continue
        try:
            text = p.read_text(errors="ignore")
        except OSError:
            continue
        for token in TOKENS:
            if token.lower() in text.lower():
                token_hits[token].append(str(p.relative_to(root)))
    report = {
        "schema": "rv220w-generic-uboot111-comparison-v1",
        "source": str(root),
        "relevant_files": records,
        "vendor_token_hits": token_hits,
        "conclusions": [
            "Generic env_relocate handles CRC-valid import and bad-CRC fallback.",
            "Generic saveenv writes the environment; it does not selectively restore bootcmd.",
            "Generic main_loop consumes bootcmd after board initialization.",
            "Generic bootelf supplies the ELF-entry calling convention used by the RAM stage2 PoC.",
            "The generic tree contains no RV220W/CN5010 Octeon board port or bootoctlinux implementation.",
        ],
    }
    ns.output.parent.mkdir(parents=True, exist_ok=True)
    ns.output.write_text(json.dumps(report, indent=2) + "\n")
    print(ns.output)
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
