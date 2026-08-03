#!/usr/bin/env python3
"""Inventory an extracted D-Link/TeamF1 Cavium GPL bundle for donor material."""
from __future__ import annotations
import argparse, hashlib, json, pathlib

TOKENS = [
    "CUST_DSR500", "CUST_DSR500N", "CN5010", "bootoctlinux", "cvmx_mio_uart",
    "octeon_ddr", "octeon_eth", "CVMX_BOARD_TYPE", "bootloader_flash_update",
]
NAME_HINTS = ["u-boot", "uboot", "octeon", "cvmx", "board", "ddr", "bootloader"]

def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("root", type=pathlib.Path)
    ap.add_argument("--output", type=pathlib.Path, required=True)
    ns = ap.parse_args()
    root = ns.root.resolve()
    if not root.is_dir():
        raise SystemExit("error: donor root is not a directory")
    names = []
    hits = {t: [] for t in TOKENS}
    scanned = 0
    for p in root.rglob("*"):
        if not p.is_file():
            continue
        rel = str(p.relative_to(root))
        low = rel.lower()
        if any(h in low for h in NAME_HINTS):
            names.append(rel)
        if p.stat().st_size > 8 * 1024 * 1024:
            continue
        try:
            raw = p.read_bytes()
        except OSError:
            continue
        scanned += 1
        lower = raw.lower()
        for token in TOKENS:
            if token.lower().encode() in lower:
                hits[token].append(rel)
    report = {
        "schema": "rv220w-dlink-cavium-donor-inventory-v1",
        "root": str(root),
        "files_scanned": scanned,
        "name_candidates": sorted(set(names))[:5000],
        "token_hits": {k: sorted(set(v)) for k, v in hits.items()},
        "priority": [
            "CN5010 cold-start and DDR configuration",
            "MIO UART and timer setup",
            "BootBus/CFI NOR setup",
            "Octeon ELF/Linux handoff",
            "PIP/PKO Ethernet and TFTP",
            "board descriptor and MAC persistence",
        ],
    }
    ns.output.parent.mkdir(parents=True, exist_ok=True)
    ns.output.write_text(json.dumps(report, indent=2) + "\n")
    print(ns.output)
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
