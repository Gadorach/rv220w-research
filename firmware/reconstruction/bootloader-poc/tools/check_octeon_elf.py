#!/usr/bin/env python3
"""Check an ELF for the constraints of the RV220W vendor bootoctlinux path."""
from __future__ import annotations
import argparse, json, pathlib, struct, sys

PT_LOAD = 1
PT_NOTE = 4
EM_MIPS = 8
ET_EXEC = 2

class CheckError(RuntimeError):
    pass

def parse(path: pathlib.Path) -> dict:
    data = path.read_bytes()
    if len(data) < 64 or data[:4] != b"\x7fELF":
        raise CheckError("ELF magic/header absent")
    if data[4:7] != bytes((2, 2, 1)):
        raise CheckError("requires ELF64 big-endian current-version encoding")
    etype, machine = struct.unpack_from(">HH", data, 16)
    if etype != ET_EXEC or machine != EM_MIPS:
        raise CheckError(f"requires ET_EXEC/EM_MIPS, found type={etype} machine={machine}")
    entry, phoff = struct.unpack_from(">QQ", data, 24)
    ehsize, phentsize, phnum = struct.unpack_from(">HHH", data, 52)
    if ehsize != 64 or phentsize != 56 or not 0 < phnum <= 128:
        raise CheckError("invalid ELF/program-header geometry")
    if phoff + phentsize * phnum > len(data):
        raise CheckError("program-header table exceeds file")
    segments=[]
    nonempty_notes=[]
    invalid_load=[]
    for i in range(phnum):
        off=phoff+i*phentsize
        p_type,p_flags,p_offset,p_vaddr,p_paddr,p_filesz,p_memsz,p_align=struct.unpack_from(">IIQQQQQQ",data,off)
        row={"index":i,"type":p_type,"flags":p_flags,"offset":p_offset,"vaddr":p_vaddr,"paddr":p_paddr,"filesz":p_filesz,"memsz":p_memsz,"align":p_align}
        segments.append(row)
        if p_type == PT_NOTE and p_filesz:
            nonempty_notes.append(i)
        if p_type == PT_LOAD and (p_filesz > p_memsz or p_offset + p_filesz > len(data)):
            invalid_load.append(i)
    loads=[x for x in segments if x["type"] == PT_LOAD]
    compatible=bool(loads) and not nonempty_notes and not invalid_load
    return {
        "path":str(path), "size":len(data), "entry":f"0x{entry:016x}",
        "phnum":phnum, "pt_load_count":len(loads),
        "pt_note_count":sum(x["type"] == PT_NOTE for x in segments),
        "nonempty_pt_note_indices":nonempty_notes,
        "invalid_pt_load_indices":invalid_load,
        "vendor_bootoctlinux_compatible":compatible,
        "reason":"compatible" if compatible else "non-empty PT_NOTE, invalid PT_LOAD, or no PT_LOAD",
        "segments":segments,
    }

def main() -> int:
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("elf",type=pathlib.Path)
    ap.add_argument("--json",action="store_true")
    ns=ap.parse_args()
    try:
        report=parse(ns.elf)
    except CheckError as exc:
        print(f"error: {exc}",file=sys.stderr)
        return 2
    if ns.json:
        print(json.dumps(report,indent=2))
    else:
        print(f"path={report['path']}")
        print(f"size={report['size']}")
        print(f"entry={report['entry']}")
        print(f"pt_load={report['pt_load_count']}")
        print(f"pt_note={report['pt_note_count']}")
        print(f"pt_note_nonempty={len(report['nonempty_pt_note_indices'])}")
        print("vendor_bootoctlinux_compatible=" + ("yes" if report["vendor_bootoctlinux_compatible"] else "no"))
    return 0 if report["vendor_bootoctlinux_compatible"] else 1
if __name__ == "__main__":
    raise SystemExit(main())
