#!/usr/bin/env python3
from __future__ import annotations
import pathlib, struct, subprocess, sys, tempfile
ROOT=pathlib.Path(__file__).resolve().parents[1]
TOOL=ROOT/'tools/check_octeon_elf.py'
ELF=ROOT/'artifacts/rv220w-stage2-poc.elf'

def synthetic(note_size: int) -> bytes:
    data=bytearray(0x200)
    data[:16]=b'\x7fELF'+bytes((2,2,1,0))+bytes(8)
    struct.pack_into('>HHIQQQIHHHHHH',data,16,2,8,1,0xffffffff84000000,64,0,0x808b0001,64,56,2,0,0,0)
    struct.pack_into('>IIQQQQQQ',data,64,1,5,0x100,0xffffffff84000000,0x04000000,0x10,0x10,0x1000)
    struct.pack_into('>IIQQQQQQ',data,120,4,4,0x180,0,0,note_size,note_size,4)
    data[0x100:0x110]=bytes(range(16))
    if note_size: data[0x180:0x180+note_size]=b'N'*note_size
    return bytes(data)

def main():
    subprocess.run([sys.executable,str(TOOL),str(ELF)],check=True)
    with tempfile.TemporaryDirectory() as td:
        good=pathlib.Path(td)/'good.elf'; bad=pathlib.Path(td)/'bad.elf'
        good.write_bytes(synthetic(0)); bad.write_bytes(synthetic(16))
        subprocess.run([sys.executable,str(TOOL),str(good)],check=True)
        rc=subprocess.run([sys.executable,str(TOOL),str(bad)],check=False).returncode
        assert rc==1
    print('vendor ELF compatibility regression passed')
if __name__=='__main__': main()
