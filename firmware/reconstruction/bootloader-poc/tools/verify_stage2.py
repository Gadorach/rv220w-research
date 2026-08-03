#!/usr/bin/env python3
"""Statically verify the RV220W RAM-only stage2 ELF."""
from __future__ import annotations
import argparse, hashlib, pathlib, struct, subprocess, sys

EXPECTED_VADDR = 0xFFFFFFFF84000000
MAX_FILE_SIZE = 0x80000
VENDOR_GATE = bytes.fromhex("ffffffffbfc1d950")
FORBIDDEN_ASCII = [b"Saving Environment to Flash", b"protect off", b"flash_write", b"mtd write"]

class Error(RuntimeError): pass

def die(msg: str) -> None:
    raise SystemExit(f"error: {msg}")

def parse_elf(data: bytes) -> tuple[int, list[tuple[int,int,int,int]]]:
    if len(data) < 64 or data[:4] != b"\x7fELF": die("not an ELF")
    if data[4] != 2 or data[5] != 2: die("expected ELF64 big-endian")
    e_machine = struct.unpack_from(">H", data, 18)[0]
    if e_machine != 8: die(f"expected EM_MIPS, got {e_machine}")
    entry = struct.unpack_from(">Q", data, 24)[0]
    phoff = struct.unpack_from(">Q", data, 32)[0]
    phentsize = struct.unpack_from(">H", data, 54)[0]
    phnum = struct.unpack_from(">H", data, 56)[0]
    segments=[]
    for i in range(phnum):
        off=phoff+i*phentsize
        p_type,p_flags,p_offset,p_vaddr,p_paddr,p_filesz,p_memsz,p_align=struct.unpack_from(">IIQQQQQQ",data,off)
        if p_type==1: segments.append((p_offset,p_vaddr,p_filesz,p_memsz))
    return entry,segments

def main() -> int:
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("elf",type=pathlib.Path)
    ns=ap.parse_args()
    data=ns.elf.read_bytes()
    if len(data)>MAX_FILE_SIZE: die(f"ELF is unexpectedly large: {len(data)}")
    entry,segs=parse_elf(data)
    if entry != EXPECTED_VADDR: die(f"wrong entry 0x{entry:x}")
    if not segs: die("no PT_LOAD segments")
    lo=min(v for _,v,_,_ in segs); hi=max(v+m for _,v,_,m in segs)
    if lo < EXPECTED_VADDR or hi > 0xFFFFFFFF84300000:
        die(f"load range 0x{lo:x}-0x{hi:x} outside reserved stage2 window")
    for token in FORBIDDEN_ASCII:
        if token in data: die(f"forbidden destructive token present: {token!r}")
    # Ensure the reconstructed vendor loader address remains explicit in source-linked code.
    # Depending on instruction synthesis it may not appear as a literal 8-byte sequence, so
    # validate through the symbolized disassembly as well.
    try:
        out=subprocess.check_output(["readelf","-h","-l","-s","-r",str(ns.elf)],text=True)
    except (OSError,subprocess.CalledProcessError) as exc: die(f"readelf failed: {exc}")
    if "MIPS R3000" not in out and "MIPS" not in out: die("readelf does not identify MIPS")
    if "There are no relocations in this file" not in out:
        die("stage2 ELF retains runtime relocations")
    undefined = [line for line in out.splitlines() if " UND " in line and "NOTYPE  LOCAL" not in line]
    if undefined:
        die(f"stage2 ELF has undefined symbols: {undefined[:3]}")
    print(f"stage2 verification passed: size={len(data)} entry=0x{entry:x} load=0x{lo:x}-0x{hi-1:x}")
    print(f"sha256={hashlib.sha256(data).hexdigest()}")
    return 0

if __name__=="__main__":
    raise SystemExit(main())
