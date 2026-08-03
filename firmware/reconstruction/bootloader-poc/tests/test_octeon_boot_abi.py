#!/usr/bin/env python3
from __future__ import annotations
import pathlib, subprocess, tempfile
ROOT=pathlib.Path(__file__).resolve().parents[1]

def main():
    header=ROOT/'reconstruction/octeon_boot_abi_v6.h'
    text=header.read_text()
    assert 'RV220W_OCTEON_DESC_VERSION 6u' in text
    with tempfile.TemporaryDirectory() as td:
        src=pathlib.Path(td)/'check.c'; out=pathlib.Path(td)/'check'
        src.write_text('#include "octeon_boot_abi_v6.h"\nint main(void){return 0;}\n')
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-I',str(header.parent),str(src),'-o',str(out)],check=True)
        subprocess.run([str(out)],check=True)
    print('Octeon boot ABI layout assertions passed')
if __name__=='__main__': main()
