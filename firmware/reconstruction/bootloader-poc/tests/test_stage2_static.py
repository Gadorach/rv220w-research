#!/usr/bin/env python3
from __future__ import annotations
import hashlib, pathlib, re, subprocess
ROOT=pathlib.Path(__file__).resolve().parents[1]
STAGE=ROOT/'stage2'; ELF=ROOT/'artifacts/rv220w-stage2-poc.elf'

def main():
    subprocess.run(['python3',str(ROOT/'tools/verify_stage2.py'),str(ELF)],check=True)
    source='\n'.join(p.read_text(errors='replace') for p in STAGE.rglob('*') if p.is_file() and p.suffix in {'.c','.S','.h','.ld'})
    assert 'RV220W_VENDOR_BOOTOCTLINUX' in source
    assert '0xffffffffbfc1d950' in source
    assert 'CVMX_MIO_UART0_BASE' in source
    assert 'CVMX_MIO_BOOT_REG_CFGX' in source
    assert 'command_bootcmd_audit' in source
    assert 'command_elfcheck' in source and 'command_bootabi' in source
    assert 'non-empty PT_NOTE' in source
    assert 'flash_write' not in source and 'protect off' not in source
    assert not re.search(r'\b(do_erase|do_saveenv|saveenv\s*\()',source)
    out=subprocess.check_output(['readelf','-h','-l',str(ELF)],text=True)
    dis=(ROOT/'artifacts/rv220w-stage2-poc.disassembly.txt').read_text()
    assert 'dsll32' in dis and 'dsra32' in dis
    assert '2\'s complement, big endian' in out and 'mips64r2' in out
    print('stage2 static policy regression passed')
if __name__=='__main__': main()
