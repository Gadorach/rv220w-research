#!/usr/bin/env python3
from __future__ import annotations
import hashlib, json, pathlib, subprocess, tempfile

ROOT=pathlib.Path(__file__).resolve().parents[1]
REPO=ROOT.parent
PATCHER=ROOT/'tools/patch_vendor_bootchain.py'
COMBINED=REPO/'u-boot/originals/rv220w-boot-chain.bin'
UPPER=REPO/'u-boot/originals/rv220w-u-boot.bin'

def diff_offsets(a:bytes,b:bytes): return [i for i,(x,y) in enumerate(zip(a,b)) if x!=y]

def run(*args): subprocess.run(['python3',str(PATCHER),*map(str,args)],check=True,stdout=subprocess.DEVNULL)

def main():
    with tempfile.TemporaryDirectory() as td:
        td=pathlib.Path(td)
        out=td/'upper.bin'; run(UPPER,out,'--redirect','run-openwrt-env')
        old=UPPER.read_bytes(); new=out.read_bytes(); ds=diff_offsets(old,new)
        assert ds and min(ds)>=0x63b0 and max(ds)<0x63b0+154
        assert new[0x63b0:].startswith(b'run openwrt_boot\0')

        out=td/'suppress.bin'; run(COMBINED,out,'--suppress-force','--ack-lower-boot-risk')
        old=COMBINED.read_bytes(); new=out.read_bytes(); assert diff_offsets(old,new)==[0x13169]
        assert new[0x13168:0x1316c]==bytes.fromhex('03e00008')

        out=td/'policy.bin'; run(COMBINED,out,'--redirect','direct-current-openwrt','--bypass-recovery','--ack-lower-boot-risk')
        new=out.read_bytes(); assert new[0x13138:0x1313c]==bytes.fromhex('10000003')
        assert new[0x363b0:].startswith(b'cp.b BDC80000 0x05500000 0x11565d0;')
        doc=json.loads(out.with_suffix('.bin.json').read_text())
        assert doc['hardware_written'] is False and len(doc['patches'])==2

        bad=bytearray(COMBINED.read_bytes()); bad[0]^=1; badp=td/'bad.bin'; badp.write_bytes(bad)
        cp=subprocess.run(['python3',str(PATCHER),str(badp),str(td/'no.bin'),'--suppress-force','--ack-lower-boot-risk'],capture_output=True,text=True)
        assert cp.returncode!=0 and 'not the preserved baseline' in cp.stderr
    print('vendor boot-chain patch regression passed')

if __name__=='__main__': main()
