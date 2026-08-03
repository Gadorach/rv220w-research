#!/usr/bin/env python3
from __future__ import annotations

import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]


def fail(message: str) -> None:
    raise SystemExit(message)


if (ROOT / "VERSION").read_text().strip() != "1.10.3":
    fail("toolkit version is not 1.10.3")

build = (ROOT / "scripts/inner/build-openwrt.sh").read_text()
body = build.split("verify_nor_writer_config() {", 1)[1].split("\n}", 1)[0]
if "verify_rj45_full_config" not in body:
    fail("writer guard does not use the RJ45 base verifier")
if "\n    verify_luci_config\n" in body:
    fail("writer guard still calls the LuCI verifier")

config_path = ROOT / "evidence/run13-v110-luci-and-writer-guard/openwrt-rv220w-nor-writer-initramfs.expanded.config"
config = set(config_path.read_text().splitlines())
required = {
    "CONFIG_PACKAGE_ip-full=y",
    "CONFIG_PACKAGE_ip-bridge=y",
    "CONFIG_PACKAGE_ethtool-full=y",
    "CONFIG_PACKAGE_kmod-dsa-b53=y",
    "CONFIG_PACKAGE_kmod-dsa-b53-mdio=y",
    "CONFIG_PACKAGE_firewall4=y",
    "CONFIG_PACKAGE_dnsmasq=y",
    "CONFIG_PACKAGE_odhcp6c=y",
    "CONFIG_PACKAGE_odhcpd-ipv6only=y",
    "CONFIG_PACKAGE_ppp=y",
    "CONFIG_PACKAGE_ppp-mod-pppoe=y",
    "CONFIG_PACKAGE_mtd=y",
    "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w_flash_stage=y",
}
missing = sorted(required - config)
if missing:
    fail(f"actual v1.10.0 writer defconfig lacks expected options: {missing}")

forbidden = {
    "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w=y",
    "CONFIG_PACKAGE_kmod-mdio-netlink=y",
    "CONFIG_PACKAGE_mdio-tools=y",
    "CONFIG_PACKAGE_luci-light=y",
    "CONFIG_PACKAGE_luci-base=y",
    "CONFIG_PACKAGE_luci-mod-admin-full=y",
    "CONFIG_PACKAGE_luci-app-firewall=y",
    "CONFIG_PACKAGE_uhttpd=y",
    "CONFIG_PACKAGE_uhttpd-mod-ubus=y",
}
retained = sorted(forbidden & config)
if retained:
    fail(f"actual v1.10.0 writer defconfig retained forbidden options: {retained}")

if "CONFIG_PACKAGE_luci-light=y" in config:
    fail("fixture unexpectedly satisfies the old broken LuCI check")

banner = (ROOT / "openwrt/files-nor-writer/etc/banner").read_text()
if "+ LuCI" in banner:
    fail("writer banner still incorrectly advertises LuCI")

print("v1.10.3 NOR-writer post-defconfig guard regression passed")
