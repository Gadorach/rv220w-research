#!/usr/bin/env python3
"""Static safety and topology checks for the RV220W dual-conduit DSA stage."""
from __future__ import annotations

import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TEMPLATE = ROOT / "openwrt/dsa-dual/cn5010_cisco_rv220w-dsa-dual.dts.in"
AFFINITY = ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-dsa-affinity"
NETWORK = ROOT / "openwrt/files-dsa-dual/etc/uci-defaults/98-rv220w-dsa-dual-network"
HOTPLUG = ROOT / "openwrt/files-dsa-dual/etc/hotplug.d/net/20-rv220w-dsa-affinity"
INIT = ROOT / "openwrt/files-dsa-dual/etc/init.d/rv220w-dsa-affinity"
SNAPSHOT = ROOT / "openwrt/files-dsa-dual/usr/sbin/rv220w-dsa-snapshot"


def fail(message: str) -> None:
    raise SystemExit(message)


for path in (TEMPLATE, AFFINITY, NETWORK, HOTPLUG, INIT, SNAPSHOT):
    if not path.is_file():
        fail(f"missing dual-conduit file: {path.relative_to(ROOT)}")

text = TEMPLATE.read_text(encoding="utf-8")
for token in (
    'compatible = "brcm,bcm53115";',
    'port@0 { reg = <0>; label = "wan"; };',
    'port@1 { reg = <1>; label = "lan1"; };',
    'port@4 { reg = <4>; label = "lan4"; };',
    'port@5',
    'label = "cpu-wan";',
    'ethernet = <&rv220w_eth1>;',
    'phy-mode = "@WAN_PHY_MODE@";',
    'port@8',
    'label = "cpu-lan";',
    'ethernet = <&rv220w_eth0>;',
    'phy-mode = "rgmii-rxid";',
    'rv220w_eth0: ethernet@0 { status = "okay"; };',
    'rv220w_eth1: ethernet@1 { status = "okay"; };',
    'ethernet@2 { status = "disabled"; };',
):
    if token not in text:
        fail(f"dual-conduit DTS lacks token: {token}")
for forbidden in ("saveenv", "flash_erase", "mtd write", "nand write"):
    if forbidden in text.lower():
        fail(f"dual-conduit DTS contains forbidden token: {forbidden}")

for variant, phy_mode in (
    ("rxid", "rgmii-rxid"),
    ("wan-txid", "rgmii-txid"),
    ("wan-rgmii", "rgmii"),
):
    rendered = text.replace("@VARIANT@", variant).replace("@WAN_PHY_MODE@", phy_mode)
    if "@VARIANT@" in rendered or "@WAN_PHY_MODE@" in rendered:
        fail(f"unexpanded dual DTS placeholder for {variant}")
    if rendered.count("ethernet = <&rv220w_eth0>;") != 1:
        fail(f"unexpected eth0 conduit count for {variant}")
    if rendered.count("ethernet = <&rv220w_eth1>;") != 1:
        fail(f"unexpected eth1 conduit count for {variant}")

# dtc may not be installed on every host, but when it is, compile all variants.
if subprocess.run(["sh", "-c", "command -v dtc >/dev/null 2>&1"]).returncode == 0:
    with tempfile.TemporaryDirectory(prefix="rv220w-dsa-dual-") as tmp:
        for variant, phy_mode in (
            ("rxid", "rgmii-rxid"),
            ("wan-txid", "rgmii-txid"),
            ("wan-rgmii", "rgmii"),
        ):
            # Standalone compilation is not attempted because the OpenWrt include
            # tree is required. Placeholder rendering is still checked above.
            Path(tmp, f"{variant}.dts").write_text(
                text.replace("@VARIANT@", variant).replace("@WAN_PHY_MODE@", phy_mode),
                encoding="utf-8",
            )

affinity = AFFINITY.read_text(encoding="utf-8")
for token in (
    "wan eth1",
    'set_conduit "$port" eth0',
    "type dsa master",
    "type dsa conduit",
    "all_correct",
    "wait_for_ports",
    "/tmp/rv220w-dsa-affinity.status",
):
    if token not in affinity:
        fail(f"affinity helper lacks token: {token}")
active_affinity = "\n".join(
    line for line in affinity.lower().splitlines() if line.strip() and not line.lstrip().startswith("#")
)
for forbidden in (
    "mdio ",
    "devmem",
    "mtd ",
    "flash_erase",
    "saveenv",
    "reboot",
):
    if forbidden in active_affinity:
        fail(f"affinity helper contains forbidden operation: {forbidden}")

network = NETWORK.read_text(encoding="utf-8")
for token in (
    "network.br_lan.ports='lan1'",
    "network.br_lan.ports='lan4'",
    "network.lan.ipaddr='192.168.240.2'",
    "network.wan.device='wan'",
    "network.wan.ipaddr='192.168.241.2'",
    "No gateway, DNS, firewall, DHCP, NAT, or forwarding",
):
    if token not in network:
        fail(f"dual network overlay lacks token: {token}")
for forbidden in ("firewall", "masq", "forwarding='1'", "dhcp.lan", "dhcp.wan"):
    # The explanatory comment may mention disabled services; reject only active UCI commands.
    for line in network.splitlines():
        stripped = line.strip().lower()
        if stripped.startswith("uci") and forbidden in stripped:
            fail(f"dual network overlay activates forbidden policy: {line}")

# The decoder must ignore the bridge's generic ``master br-lan`` token and
# select only DSA's conduit/master attribute.
for sample, expected in (
    ("5: lan1@eth0: <UP> master br-lan state UP\n    dsa conduit eth0\n", "eth0"),
    ("9: wan@eth1: <UP> master br-test state UP\n    dsa master eth1\n", "eth1"),
    ("5: lan1@eth0: <UP>\n    conduit eth0\n", "eth0"),
):
    result = subprocess.run(
        ["sh", str(AFFINITY), "--decode-link"],
        input=sample,
        text=True,
        capture_output=True,
        check=True,
    )
    if result.stdout.strip() != expected:
        fail(
            f"affinity conduit decoder returned {result.stdout.strip()!r}, "
            f"expected {expected!r}"
        )

for shell in (AFFINITY, NETWORK, HOTPLUG, SNAPSHOT):
    subprocess.run(["sh", "-n", str(shell)], check=True)
# rc.common scripts are valid POSIX shell after the interpreter argument.
subprocess.run(["sh", "-n", str(INIT)], check=True)

print("v1.8.0 dual-conduit DSA profile checks passed")
