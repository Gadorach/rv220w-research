#!/usr/bin/env python3
from __future__ import annotations
import json, pathlib
ROOT=pathlib.Path(__file__).resolve().parents[1]
d=json.loads((ROOT/'donors/dlink-cavium-source-report.json').read_text())
assert d['schema']=='rv220w-dlink-cavium-donor-report-v1'
assert any('1.7.3, build 264' in r['text'] for r in d['facts']['dwc_sdk_version'])
assert any('2.0.0, build 366' in r['text'] for r in d['facts']['dsr_sdk_version'])
assert any('BCM53115' in r['text'] for r in d['facts']['bcm53115_topology'])
assert d['dsr_full_uboot_source_present'] is False
assert d['source_archives']['D-Link_DWC-1000_GPL-SRC_v4.1.0.2_10204.tar.bz2']['sha256']=='d42760e4004f33d6767feb766afdf83ebf31f55bd4d7ec4f926d75e3efe9d262'
assert d['source_archives']['D-Link_DSR_500_500N_1000_1000N_GPL-SRC_v1.08B51.7z.001']['sha256']=='729eec4a058fa490b343384588b53d7d2ffe5c3b5031d1c9bdbcafd925150b67'
print('D-Link Cavium donor report regression passed')
