#!/usr/bin/env python3
"""Validate the first complete RV220W wired-router profile."""
from __future__ import annotations

import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
HISTORY_DOCS = ROOT.parent / "docs" / "history" / "openwrt" / "toolkit-v1.10.3"
SEED = ROOT / "config/openwrt-rv220w-rj45-initramfs.config"
NETWORK = ROOT / "openwrt/files-rj45-full/etc/uci-defaults/98-rv220w-rj45-network"
SERVICES = ROOT / "openwrt/files-rj45-full/etc/uci-defaults/99-rv220w-rj45-services"
STATUS = ROOT / "openwrt/files-rj45-full/usr/sbin/rv220w-rj45-status"
BUILD = ROOT / "scripts/inner/build-openwrt.sh"
OUTER = ROOT / "scripts/build-openwrt.fish"
TFTP = ROOT / "scripts/tftp-boot.fish"
DOC = HISTORY_DOCS / "RV220W-V1.9.3-FDT-VERIFY-API-HOTFIX.md"


def fail(message: str) -> None:
    raise SystemExit(message)


for path in (SEED, NETWORK, SERVICES, STATUS, BUILD, OUTER, TFTP, DOC):
    if not path.is_file():
        fail(f"missing full-RJ45 file: {path.relative_to(ROOT)}")

seed = SEED.read_text(encoding="utf-8")
for token in (
    "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w=y",
    "CONFIG_TARGET_ROOTFS_INITRAMFS=y",
    "CONFIG_PACKAGE_kmod-dsa-b53=y",
    "CONFIG_PACKAGE_kmod-dsa-b53-mdio=y",
    "CONFIG_PACKAGE_firewall4=y",
    "CONFIG_PACKAGE_dnsmasq=y",
    "CONFIG_PACKAGE_odhcp6c=y",
    "CONFIG_PACKAGE_odhcpd-ipv6only=y",
    "CONFIG_PACKAGE_ppp=y",
    "CONFIG_PACKAGE_ppp-mod-pppoe=y",
    '# CONFIG_PACKAGE_luci is not set',
):
    if token not in seed:
        fail(f"full-RJ45 seed lacks token: {token}")

network = NETWORK.read_text(encoding="utf-8")
for token in (
    "uci add_list network.br_lan.ports='lan1'",
    "uci add_list network.br_lan.ports='lan4'",
    "uci -q set system.@system[0].hostname='rv220w-rj45'",
    "uci set network.lan.ipaddr='192.168.240.2'",
    "uci set network.wan.device='wan'",
    "uci set network.wan.proto='dhcp'",
    "uci set network.wan6.device='wan'",
    "uci set network.wan6.proto='dhcpv6'",
):
    if token not in network:
        fail(f"full-RJ45 network overlay lacks token: {token}")
for line in network.splitlines():
    stripped = line.strip()
    if stripped.startswith("uci add_list network.br_lan.ports=") and "wan" in stripped:
        fail("WAN was added to br-lan")

services = SERVICES.read_text(encoding="utf-8")
for token in (
    "dhcp.lan.interface='lan'",
    "dhcp.wan.ignore='1'",
    '"$lan_zone.input=ACCEPT"',
    '"$wan_zone.input=REJECT"',
    '"$wan_zone.forward=REJECT"',
    '"$wan_zone.masq=1"',
    '"$forwarding.src=lan"',
    '"$forwarding.dest=wan"',
):
    if token not in services:
        fail(f"full-RJ45 service policy lacks token: {token}")

# Reject policy that directly bridges WAN or globally enables layer-2 forwarding.
active = "\n".join(
    line for line in (network + "\n" + services).splitlines()
    if line.strip() and not line.lstrip().startswith("#")
).lower()
for forbidden in (
    "br_lan.ports='wan'",
    "br-lan.ports='wan'",
    "network.lan.device='wan'",
    "network.wan.device='br-lan'",
    "wan_zone.forward=accept",
    "forwarding.src=wan",
):
    if forbidden in active:
        fail(f"full-RJ45 policy contains unsafe token: {forbidden}")

build = BUILD.read_text(encoding="utf-8")
for token in (
    "sync_rj45_full_files()",
    "files/etc/uci-defaults/99-rv220w-validation",
    "verify_rj45_full_config()",
    "998-b53-enable-dt-cpu-ports.patch",
    "999-octeon-production-dt-flash-cleanups.patch",
    "cn5010_cisco_rv220w-production.dts.in",
    "openwrt-rv220w-rj45-initramfs.config",
    'build_dsa_dual rxid rgmii-rxid full-rj45',
    'stage_initramfs "rv220w-openwrt-rv220w-rj45-initramfs"',
):
    if token not in build:
        fail(f"full-RJ45 build path lacks token: {token}")

outer = OUTER.read_text(encoding="utf-8")
for token in ("rj45-full", "rv220w-rj45-initramfs"):
    if token not in outer:
        fail(f"outer build wrapper lacks token: {token}")

tftp = TFTP.read_text(encoding="utf-8")
for token in (
    "case rj45 rj45-full full-rj45",
    "rv220w-openwrt-rv220w-rj45-initramfs.elf",
    "LAN DHCP, WAN DHCP/DHCPv6, strict firewall4 isolation and NAT",
):
    if token not in tftp:
        fail(f"TFTP full-RJ45 support lacks token: {token}")

for shell in (NETWORK, SERVICES, STATUS):
    subprocess.run(["sh", "-n", str(shell)], check=True)
subprocess.run(["bash", "-n", str(BUILD)], check=True)

# Ensure the build mode has only one dispatch arm and the artifact name is stable.
if len(re.findall(r"^  rv220w-rj45-initramfs\)$", build, flags=re.M)) != 1:
    fail("full-RJ45 build mode dispatch is missing or duplicated")

print("v1.9.3 full-RJ45 profile checks passed")
