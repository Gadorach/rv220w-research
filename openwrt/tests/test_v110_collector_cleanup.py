#!/usr/bin/env python3
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

conduit = (ROOT / "scripts/collect-conduit.fish").read_text()
for token in (
    "r/require-b53",
    "case 3",
    "b53_collection=skipped",
    "production image excludes mdio diagnostics",
):
    if token not in conduit:
        raise SystemExit(f"collect-conduit lacks: {token}")

wrapper = (ROOT / "scripts/collect-b53.fish").read_text()
if "case 3" not in wrapper or "detailed target-side report" not in wrapper:
    raise SystemExit("collect-b53 does not preserve unavailable status or useful diagnostics")

collector = (ROOT / "scripts/host/rv220w_uart_collect_b53.py").read_text()
for token in (
    "class B53Unavailable",
    "def preflight_mdio",
    "mdio=missing",
    "raise SystemExit(3)",
    "def retrieve_failed_report",
    "--- target report ---",
):
    if token not in collector:
        raise SystemExit(f"UART B53 collector lacks: {token}")
preflight_pos = collector.index("preflight_mdio(shell)")
upload_pos = collector.index("remote_script = choose_remote_script")
if preflight_pos > upload_pos:
    raise SystemExit("B53 availability is checked only after the slow UART upload")

production = (ROOT / "scripts/collect-rj45.fish").read_text()
if "collect-dsa.fish" not in production or "no raw MDIO dependency" not in production:
    raise SystemExit("production-safe RJ45 collector is missing")

dsa = (ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-dsa-snapshot").read_text()
for token in (
    "=== PRODUCTION_ACCEPTANCE ===",
    "kernel_tainted=",
    "raw_fdt=available magic=",
    "firewall=loaded",
    "counter_note=DSA wan",
):
    if token not in dsa:
        raise SystemExit(f"DSA acceptance snapshot lacks: {token}")

print("v1.10.0 collector and stale-log cleanup checks passed")
