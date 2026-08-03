#!/usr/bin/env python3
from __future__ import annotations
import json, pathlib, subprocess, tempfile
ROOT=pathlib.Path(__file__).resolve().parents[1]
REPO=ROOT.parent

def main():
    with tempfile.TemporaryDirectory() as td:
        out=pathlib.Path(td)/'proof.json'
        subprocess.run([
            'python3',str(ROOT/'tools/analyze_vendor_bootchain.py'),
            str(REPO/'u-boot/originals/rv220w-boot-chain.bin'),
            '--u-boot',str(REPO/'u-boot/originals/rv220w-u-boot.bin'),
            '--output',str(out)
        ],check=True,stdout=subprocess.DEVNULL)
        doc=json.loads(out.read_text())
        assert doc['late_init']['setenv_wrapper']=='0xffffffffbfc19b60'
        assert doc['late_init']['tail_call']['offset']==0x13168
        assert doc['late_init']['bootcmd_name']['value']=='bootcmd'
        assert doc['late_init']['firmware_check']=='0xffffffffbfc22834'
        assert doc['late_init']['http_recovery']=='0xffffffffbfc22bd4'
        assert doc['firmware_header_check']['trailer_magic']=='FWCHKADDISABABA'
    print('boot-chain byte proof regression passed')
if __name__=='__main__': main()
