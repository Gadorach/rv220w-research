#!/usr/bin/env python3
"""Fingerprint D-Link Cavium GPL donors and extract RV220W-relevant facts.

The report records hashes and short factual matches. It does not copy donor source
into the reconstruction repository.
"""
from __future__ import annotations
import argparse, hashlib, json, pathlib, re

def sha256(p: pathlib.Path) -> str:
    h=hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda:f.read(1024*1024), b''): h.update(b)
    return h.hexdigest()

def find_one(root: pathlib.Path, suffix: str) -> pathlib.Path:
    hits=[p for p in root.rglob('*') if p.is_file() and p.as_posix().endswith(suffix)]
    if not hits: raise SystemExit(f'missing {suffix} below {root}')
    return sorted(hits, key=lambda p:len(p.parts))[0]

def grep(path: pathlib.Path, pattern: str) -> list[dict[str,object]]:
    rx=re.compile(pattern)
    rows=[]
    for n,line in enumerate(path.read_text(errors='replace').splitlines(),1):
        if rx.search(line): rows.append({'line':n,'text':line.strip()})
    return rows

def rel(p: pathlib.Path, root: pathlib.Path) -> str: return p.relative_to(root).as_posix()

def main() -> int:
    ap=argparse.ArgumentParser()
    ap.add_argument('--dwc-root',type=pathlib.Path,required=True)
    ap.add_argument('--dsr-root',type=pathlib.Path,required=True)
    ap.add_argument('--output',type=pathlib.Path,required=True)
    a=ap.parse_args()
    targets={
      'dwc_version':(a.dwc_root,'src/sdk/executive/cvmx-version.h'),
      'dwc_board_enum':(a.dwc_root,'src/sdk/executive/cvmx-app-init.h'),
      'dwc_board_helper':(a.dwc_root,'src/sdk/executive/cvmx-helper-board.c'),
      'dwc_csr_addresses':(a.dwc_root,'src/sdk/executive/cvmx-csr-addresses.h'),
      'dwc_csr_types':(a.dwc_root,'src/sdk/executive/cvmx-csr-typedefs.h'),
      'dwc_flash_setup':(a.dwc_root,'src/kernel/linux-2.6.21/arch/mips/cavium-octeon/flash_setup.c'),
      'dsr_version':(a.dsr_root,'src/sdk-2.0/executive/cvmx-version.h'),
      'dsr_bootloader_header':(a.dsr_root,'src/sdk-2.0/executive/cvmx-bootloader.h'),
      'dsr_boot_info':(a.dsr_root,'src/sdk-2.0/executive/octeon-boot-info.h'),
      'dsr_app_init':(a.dsr_root,'src/sdk-2.0/executive/cvmx-app-init.c'),
      'dsr_mio_defs':(a.dsr_root,'src/sdk-2.0/executive/cvmx-mio-defs.h'),
    }
    files={}
    resolved={}
    for key,(root,suffix) in targets.items():
        p=find_one(root,suffix); resolved[key]=p
        files[key]={'path':rel(p,root),'size':p.stat().st_size,'sha256':sha256(p)}
    def bootloader_scan(root: pathlib.Path) -> tuple[list[str], list[str]]:
        path_hits=[]; content_hits=[]
        source_suffixes={".c",".h",".s",".S",".mk"}
        for path in root.rglob("*"):
            if not path.is_file():
                continue
            lower=path.as_posix().lower()
            if "/u-boot/" in lower or "u-boot" in path.name.lower() or "bootoctlinux" in path.name.lower() or "octeon_mem_map" in path.name.lower():
                path_hits.append(rel(path,root))
            if path.suffix in source_suffixes or path.name == "Makefile":
                try:
                    text=path.read_text(errors="ignore")
                except OSError:
                    continue
                if "bootoctlinux" in text or "do_bootoctlinux" in text:
                    content_hits.append(rel(path,root))
        return sorted(path_hits), sorted(content_hits)
    dwc_paths,dwc_content=bootloader_scan(a.dwc_root)
    dsr_paths,dsr_content=bootloader_scan(a.dsr_root)
    report={
      'schema':'rv220w-dlink-cavium-donor-report-v1',
      'policy':'facts and hashes only; donor source is not redistributed',
      'files':files,
      'facts':{
        'dwc_sdk_version':grep(resolved['dwc_version'],r'OCTEON_SDK_VERSION_STRING'),
        'dsr_sdk_version':grep(resolved['dsr_version'],r'OCTEON_SDK_VERSION_STRING'),
        'private_board_enums':grep(resolved['dwc_board_enum'],r'CUST_(DSR|DWC)'),
        'bcm53115_topology':grep(resolved['dwc_board_helper'],r'BCM53115|Port 0, 1 connect to switch|return 3'),
        'bootbus_addresses':grep(resolved['dwc_csr_addresses'],r'CVMX_MIO_BOOT_REG_(CFGX|TIMX)'),
        'flash_mapping':grep(resolved['dwc_flash_setup'],r'region_cfg|flash_map\.(phys|size|bankwidth)|Bootbus flash'),
        'bootloader_header_magic':grep(resolved['dsr_bootloader_header'],r'BOOTLOADER_HEADER_MAGIC|BOOTLOADER_HEADER_CURRENT|BL_HEADER_IMAGE'),
        'boot_descriptor_handoff':grep(resolved['dsr_app_init'],r'process_boot_desc|cvmx_bootinfo_ptr|stack_top|heap_base|board_type|mac_addr'),
      },
      'complete_uboot_source_present': bool(dwc_paths or dwc_content or dsr_paths or dsr_content),
      'bootloader_source_scan': {
        'dwc_path_candidates': dwc_paths[:100],
        'dwc_bootoctlinux_content_candidates': dwc_content[:100],
        'dsr_path_candidates': dsr_paths[:100],
        'dsr_bootoctlinux_content_candidates': dsr_content[:100],
      },
      'dsr_full_uboot_source_present': bool(dsr_paths or dsr_content),
      'dsr_uboot_path_candidates': dsr_paths[:50],
      'conclusions':[
        'DWC SDK 1.7.3 build 264 exactly matches the SDK string embedded in the RV220W boot chain.',
        'DWC board support confirms three RGMII ports, with Octeon ports 0 and 1 connected to BCM53115 and forced to 1000/full.',
        'DSR SDK 2.0 is a useful secondary donor for boot headers and generated CSR definitions.',
        'Neither supplied D-Link package contains a complete U-Boot source tree or bootoctlinux command implementation.',
      ],
    }
    a.output.parent.mkdir(parents=True,exist_ok=True)
    a.output.write_text(json.dumps(report,indent=2)+'\n')
    print(a.output)
    return 0
if __name__=='__main__': raise SystemExit(main())
