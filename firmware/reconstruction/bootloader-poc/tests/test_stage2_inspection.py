#!/usr/bin/env python3
from __future__ import annotations
import pathlib, re
ROOT=pathlib.Path(__file__).resolve().parents[1]
ST=ROOT/'stage2'
source='\n'.join(p.read_text(errors='replace') for p in ST.rglob('*') if p.is_file() and p.suffix in {'.c','.S','.h','.ld'})
for token in ['command_bootbus','command_env','command_fwcheck','command_mac','command_bootcmd_audit','CVMX_MIO_BOOT_REG_CFGX','RV220W_ENV_OFFSET','RV220W_BASE_MAC_OFFSET']:
    assert token in source, token
for prohibited in ['flash_write','flash_erase','do_saveenv','protect off','mdio_write','gpio_write']:
    assert prohibited not in source, prohibited
assert '0x00013168ULL' in source
assert 'vendor-force-enabled (jr t9)' in source
assert 'force-suppressed (jr ra)' in source
assert re.search(r'argc != 2.*csr accepts', source, re.S)
print('stage2 donor-derived inspection policy regression passed')
