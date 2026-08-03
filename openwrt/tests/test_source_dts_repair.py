#!/usr/bin/env python3
"""Regression checks for safe stale RV220W source-DTS recovery."""
from __future__ import annotations

import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
HELPER = ROOT / "scripts/inner/repair-rv220w-source-dts.py"
CANONICAL = ROOT / "openwrt/reference/cn5010_cisco_rv220w.dts"
LAN_TEMPLATE = ROOT / "openwrt/dsa-lan/cn5010_cisco_rv220w-dsa-lan.dts.in"
DUAL_TEMPLATE = ROOT / "openwrt/dsa-dual/cn5010_cisco_rv220w-dsa-dual.dts.in"
PRODUCTION_TEMPLATE = ROOT / "openwrt/production/cn5010_cisco_rv220w-production.dts.in"


def run(target: Path, *, ok: bool = True) -> subprocess.CompletedProcess[str]:
    result = subprocess.run(
        [
            sys.executable,
            str(HELPER),
            str(target),
            str(CANONICAL),
            str(LAN_TEMPLATE),
            str(DUAL_TEMPLATE),
            str(PRODUCTION_TEMPLATE),
        ],
        text=True,
        capture_output=True,
    )
    if ok and result.returncode != 0:
        raise SystemExit(result.stdout + result.stderr)
    if not ok and result.returncode == 0:
        raise SystemExit("unknown DTS was unexpectedly accepted")
    return result


with tempfile.TemporaryDirectory(prefix="rv220w-dts-repair-") as tmp:
    root = Path(tmp)
    lan_template = LAN_TEMPLATE.read_text(encoding="utf-8")
    dual_template = DUAL_TEMPLATE.read_text(encoding="utf-8")
    production_template = PRODUCTION_TEMPLATE.read_text(encoding="utf-8")
    canonical = CANONICAL.read_bytes()

    stale_lan = root / "stale-lan.dts"
    stale_lan.write_text(
        lan_template.replace("@VARIANT@", "rxid").replace("@PHY_MODE@", "rgmii-rxid"),
        encoding="utf-8",
    )
    run(stale_lan)
    if stale_lan.read_bytes() != canonical:
        raise SystemExit("exact stale LAN DSA candidate was not restored")

    stale_dual = root / "stale-dual.dts"
    stale_dual.write_text(
        dual_template.replace("@VARIANT@", "wan-txid").replace("@WAN_PHY_MODE@", "rgmii-txid"),
        encoding="utf-8",
    )
    run(stale_dual)
    if stale_dual.read_bytes() != canonical:
        raise SystemExit("exact stale dual-conduit DSA candidate was not restored")


    stale_production = root / "stale-production.dts"
    stale_production.write_text(
        production_template.replace("@VARIANT@", "rxid").replace("@WAN_PHY_MODE@", "rgmii-rxid"),
        encoding="utf-8",
    )
    run(stale_production)
    if stale_production.read_bytes() != canonical:
        raise SystemExit("exact stale production DTS candidate was not restored")

    structural_dual = root / "structural-dual.dts"
    structural_dual.write_text(
        dual_template.replace("@VARIANT@", "local-test").replace("@WAN_PHY_MODE@", "rgmii-rxid").replace(
            'label = "cpu-wan";', 'label   =   "cpu-wan" ;'
        ),
        encoding="utf-8",
    )
    run(structural_dual)
    if structural_dual.read_bytes() != canonical:
        raise SystemExit("structurally recognized stale dual DSA candidate was not restored")

    run(stale_dual)
    if stale_dual.read_bytes() != canonical:
        raise SystemExit("canonical rerun changed the DTS")

    formatted = root / "formatted.dts"
    formatted.write_text(
        CANONICAL.read_text(encoding="utf-8").replace(
            'model = "Cisco RV220W";', 'model   =   "Cisco RV220W" ;'
        ),
        encoding="utf-8",
    )
    before = formatted.read_bytes()
    run(formatted)
    if formatted.read_bytes() != before:
        raise SystemExit("platform-compatible formatting was overwritten")

    unknown = root / "unknown.dts"
    unknown.write_text('/dts-v1/;\n/ { model = "Local experimental board"; };\n', encoding="utf-8")
    before = unknown.read_bytes()
    run(unknown, ok=False)
    if unknown.read_bytes() != before:
        raise SystemExit("unrecognized DTS was modified")

print("v1.9.1 safe LAN/dual/production source-DTS recovery checks passed")
