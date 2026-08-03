#!/usr/bin/env python3
from __future__ import annotations
import json, pathlib
ROOT=pathlib.Path(__file__).resolve().parents[1]

def main():
    p=ROOT/'donors/dlink-cavium-multiversion-report-v1.4.json'
    d=json.loads(p.read_text())
    assert d['schema']=='rv220w-dlink-cavium-multiversion-v1.4'
    assert len(d['archives'])==11
    assert not d['findings']['complete_uboot_source_found']
    assert not d['findings']['bootoctlinux_source_found']
    assert d['findings']['private_board_ids']=={'DSR1000N':20006,'DSR500N':20013,'DSR500':20015,'DSR1000':20016,'DWC1000':20017}
    assert d['findings']['rv200w_numeric_board_id'].startswith('not found')
    assert d['findings']['toolchain_archive_identical_copies']==7
    assert d['octeon_boot_abi']['descriptor_version']==6
    assert d['octeon_boot_abi']['boot_descriptor_size']==400
    assert d['octeon_boot_abi']['cvmx_bootinfo_v1_2_size']==152
    assert d['unchanged_conclusions']['forced_bootcmd_patch_offset']=='0x00013168'
    print('D-Link multiversion report regression passed')
if __name__=='__main__': main()
