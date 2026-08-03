#!/usr/bin/env python3
"""Create reviewable RV220W vendor boot-chain patch candidates.

This tool never accesses hardware. It accepts only the preserved exact baseline,
checks every original byte, writes a new file, and emits a JSON audit manifest.
"""
from __future__ import annotations
import argparse, hashlib, json, pathlib, struct, sys

COMBINED_SIZE=0x80000
COMBINED_SHA="0630714e3e86edfeeed064088266c59524d970e0b74780e903b68b45e8982e7d"
UPPER_SIZE=0x50000
UPPER_SHA="1b68453e055dee56a8724b17a927df36ff201a44c8e450c5d17a3b8e9117000d"
UPPER_BASE=0x30000
STOCK_OFFSET=0x363b0
STOCK_FIELD=154
STOCK=(b"cp.b BDC80000 0x2a00000 580000;bootoctlinux 0x2a00200 "
       b"mtdparts=phys_mapped_flash:512k(bootloader)ro,6M(kernel),16M(rootfs),"
       b"1024k(data),128k(bootload-env)")
PATCHES={
 "suppress-force": (0x13168, bytes.fromhex("03200008"), bytes.fromhex("03e00008")),
 "bypass-recovery": (0x13138, bytes.fromhex("04410003"), bytes.fromhex("10000003")),
}
REDIRECTS={
 "run-openwrt-env": b"run openwrt_boot",
 "direct-current-openwrt": b"cp.b BDC80000 0x05500000 0x11565d0;bootoctlinux 0x05500000 console=ttyS0,115200",
}

def sha(data:bytes)->str: return hashlib.sha256(data).hexdigest()
def fail(msg:str)->None: raise SystemExit(f"error: {msg}")

def replace_checked(buf:bytearray,offset:int,old:bytes,new:bytes,records:list[dict],name:str)->None:
    actual=bytes(buf[offset:offset+len(old)])
    if actual!=old: fail(f"{name}: original bytes mismatch at 0x{offset:x}: {actual.hex()} != {old.hex()}")
    if len(new)!=len(old): fail(f"{name}: patch length mismatch")
    buf[offset:offset+len(new)]=new
    records.append({"name":name,"offset":offset,"old_hex":old.hex(),"new_hex":new.hex()})

def main()->int:
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("input",type=pathlib.Path)
    ap.add_argument("output",type=pathlib.Path)
    ap.add_argument("--redirect",choices=sorted(REDIRECTS))
    ap.add_argument("--suppress-force",action="store_true")
    ap.add_argument("--bypass-recovery",action="store_true")
    ap.add_argument("--ack-lower-boot-risk",action="store_true",
                    help="required for any code patch below flash offset 0x30000")
    ns=ap.parse_args()
    raw=ns.input.read_bytes(); digest=sha(raw)
    if len(raw)==COMBINED_SIZE and digest==COMBINED_SHA:
        kind="combined"; base=0
    elif len(raw)==UPPER_SIZE and digest==UPPER_SHA:
        kind="upper"; base=UPPER_BASE
    else:
        fail(f"input is not the preserved baseline: size={len(raw)} sha256={digest}")
    if not (ns.redirect or ns.suppress_force or ns.bypass_recovery): fail("select at least one patch")
    if (ns.suppress_force or ns.bypass_recovery) and kind!="combined":
        fail("lower code patches require the complete 512 KiB boot-chain image")
    if (ns.suppress_force or ns.bypass_recovery) and not ns.ack_lower_boot_risk:
        fail("lower code patch requested without --ack-lower-boot-risk")
    buf=bytearray(raw); records=[]
    if ns.redirect:
        off=STOCK_OFFSET-base
        if off<0: fail("stock command field is outside input")
        old=STOCK+b"\0"
        if bytes(buf[off:off+len(old)])!=old: fail("stock bootcmd field mismatch")
        value=REDIRECTS[ns.redirect]
        if len(value)+1>STOCK_FIELD: fail("replacement does not fit field")
        replacement=value+b"\0"+b"\0"*(STOCK_FIELD-len(value)-1)
        previous=bytes(buf[off:off+STOCK_FIELD])
        buf[off:off+STOCK_FIELD]=replacement
        records.append({"name":f"redirect:{ns.redirect}","offset":off,"flash_offset":off+base,
                        "old_sha256":sha(previous),"new_ascii":value.decode(),"field_size":STOCK_FIELD})
    if ns.suppress_force:
        off,old,new=PATCHES["suppress-force"]
        replace_checked(buf,off,old,new,records,"suppress-force")
    if ns.bypass_recovery:
        off,old,new=PATCHES["bypass-recovery"]
        replace_checked(buf,off,old,new,records,"bypass-recovery")
    out=bytes(buf); ns.output.parent.mkdir(parents=True,exist_ok=True); ns.output.write_bytes(out)
    manifest={"schema":"rv220w-vendor-bootchain-patch-result-v1","input":str(ns.input),
              "input_kind":kind,"input_size":len(raw),"input_sha256":digest,
              "output":str(ns.output),"output_size":len(out),"output_sha256":sha(out),
              "patches":records,"hardware_written":False,
              "warning":"Experimental boot-critical output. External TSOP56 recovery is required before flashing lower-region patches."}
    mp=ns.output.with_suffix(ns.output.suffix+".json")
    mp.write_text(json.dumps(manifest,indent=2)+"\n")
    print(ns.output); print(mp); print(f"sha256={manifest['output_sha256']}")
    return 0

if __name__=="__main__": raise SystemExit(main())
