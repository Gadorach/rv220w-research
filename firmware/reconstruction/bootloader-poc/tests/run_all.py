#!/usr/bin/env python3
from __future__ import annotations
import pathlib, subprocess, sys
HERE=pathlib.Path(__file__).resolve().parent
for name in ['test_bootchain_analysis.py','test_patch_vendor_bootchain.py','test_stage2_crypto.py','test_stage2_static.py','test_dlink_donor_report.py','test_stage2_inspection.py','test_dlink_multiversion_report.py','test_octeon_boot_abi.py','test_elf_compatibility.py','test_combined_patch_flasher.py']:
    subprocess.run([sys.executable,str(HERE/name)],check=True)
print('all RV220W bootloader PoC tests passed')
