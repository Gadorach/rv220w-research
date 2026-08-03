#!/usr/bin/env python3
"""Inventory extracted D-Link DSR/DWC Cavium source trees without redistributing donor code."""
from __future__ import annotations
import argparse, hashlib, json, pathlib, re

PATTERNS = {
    "complete_uboot_tree": re.compile(r"(^|/)(u-boot|uboot)(/|$)", re.I),
    "bootoctlinux_source": re.compile(r"bootoctlinux|cmd_bootoct", re.I),
    "rv200w_lineage": re.compile(r"CONFIG_OCTEON_RV200W|RV220W", re.I),
    "octeon_sdk": re.compile(r"Octeon SDK|OCTEON_CURRENT_DESC_VERSION", re.I),
    "dlink_private_boards": re.compile(r"CVMX_BOARD_TYPE_CUST_(DSR|DWC)", re.I),
}
TEXT_SUFFIXES={".c",".h",".S",".s",".patch",".diff",".mk",".txt",".config",".in",".sh"}

def sha256(path: pathlib.Path) -> str:
    h=hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda:f.read(1024*1024),b""):
            h.update(block)
    return h.hexdigest()

def scan(root: pathlib.Path) -> dict:
    paths=[]; hits={k:[] for k in PATTERNS}; files=0
    for path in root.rglob("*"):
        if not path.is_file(): continue
        files += 1
        rel=path.relative_to(root).as_posix(); paths.append(rel)
        if path.suffix not in TEXT_SUFFIXES or path.stat().st_size > 64*1024*1024: continue
        try: text=path.read_text(errors="replace")
        except OSError: continue
        for key,rx in PATTERNS.items():
            if rx.search(rel) or rx.search(text): hits[key].append(rel)
    return {"root":str(root),"file_count":files,"hits":hits,
            "complete_uboot_source_found":False,
            "note":"Path-name matches are candidates only; a complete U-Boot source tree requires Makefile/common/cmd/arch-board cohesion."}

def main() -> int:
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("roots",nargs="+",type=pathlib.Path)
    ap.add_argument("--output",type=pathlib.Path)
    ns=ap.parse_args()
    report={"schema":"rv220w-dlink-multiversion-scan-v1","roots":[scan(r) for r in ns.roots]}
    out=json.dumps(report,indent=2)+"\n"
    if ns.output: ns.output.write_text(out)
    else: print(out,end="")
    return 0
if __name__=="__main__": raise SystemExit(main())
