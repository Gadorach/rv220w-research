#!/usr/bin/env python3
from __future__ import annotations

import json
import pathlib
import struct
import subprocess
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[1]


def fail(message: str) -> None:
    raise SystemExit(message)


if (ROOT / "VERSION").read_text().strip() != "1.10.3":
    fail("toolkit version is not 1.10.3")

luci_seed = (ROOT / "config/openwrt-rv220w-rj45-luci-initramfs.config").read_text()
writer_seed = (ROOT / "config/openwrt-rv220w-nor-writer-initramfs.config").read_text()
for token in (
    "CONFIG_PACKAGE_luci-light=y",
    "CONFIG_PACKAGE_luci-base=y",
    "CONFIG_PACKAGE_luci-mod-admin-full=y",
    "CONFIG_PACKAGE_luci-app-firewall=y",
    "CONFIG_PACKAGE_uhttpd=y",
    "CONFIG_PACKAGE_uhttpd-mod-ubus=y",
):
    if token not in luci_seed:
        fail(f"LuCI config token missing: {token}")
    if token in writer_seed:
        fail(f"dedicated NOR writer unexpectedly includes LuCI token: {token}")
if "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w=y" not in luci_seed:
    fail("LuCI profile does not use the all-read-only RV220W target")
if "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w_flash_stage=y" not in writer_seed:
    fail("NOR-writer profile does not select the flash-stage target")
if "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w=y" in writer_seed:
    fail("NOR-writer seed also selects the normal target")

uhttpd = (ROOT / "openwrt/files-rj45-luci/etc/uci-defaults/97-rv220w-luci-lan-only").read_text()
for token in ("192.168.240.2:80", "delete uhttpd.main.listen_https", "redirect_https='0'"):
    if token not in uhttpd:
        fail(f"LAN-only LuCI policy lacks: {token}")
if "0.0.0.0:80" in uhttpd or "[::]:80" in uhttpd:
    fail("LuCI overlay binds a wildcard address")

writer = ROOT / "openwrt/files-nor-writer/usr/sbin/rv220w-nor-stage"
subprocess.run(["sh", "-n", str(writer)], check=True)
writer_text = writer.read_text()
for token in (
    "EXPECTED_SIZE=23068672",
    "EXPECTED_ERASE=131072",
    "RV220W_WRITE_OPENWRT_SLOT",
    "RV220W_RESTORE_OPENWRT_SLOT",
    "openwrt-slot-only",
    "mtd write \"$image\" \"$SLOT_NAME\"",
    "restore FILE EXPECTED_SHA256 RV220W_RESTORE_OPENWRT_SLOT",
    "copy the ELF from NOR to RAM, then run bootoctlinux",
    "automatic_reboot=no",
    "automatic_saveenv=no",
):
    if token not in writer_text:
        fail(f"NOR writer lacks safety token: {token}")
for forbidden in ("saveenv", "fw_setenv", "mtd write $image boot-chain", "reboot -f"):
    if forbidden in writer_text and forbidden != "saveenv":
        fail(f"NOR writer contains forbidden operation: {forbidden}")
# saveenv is permitted only in a statement explicitly saying it is not done.
if writer_text.count("saveenv") != 1 or "automatic_saveenv=no" not in writer_text:
    fail("NOR writer has an unexpected saveenv reference")

platform = (ROOT / "openwrt/platform/openwrt-rv220w-platform-v1.4.0.patch").read_text()
delta = ROOT / "openwrt/platform/openwrt-rv220w-platform-v1.3.2-to-v1.4.0.patch"
for token in (
    "RV220W_FLASH_STAGE_CMDLINE:=",
    "22m(openwrt-slot)",
    "Device/cisco_rv220w_flash_stage",
    "TARGET_DEVICES += cisco_rv220w_flash_stage",
):
    if token not in platform or token not in delta.read_text():
        fail(f"platform v1.4.0 lacks: {token}")
normal_line = next(line for line in platform.splitlines() if line.startswith("+RV220W_CMDLINE:="))
writer_line = next(line for line in platform.splitlines() if line.startswith("+RV220W_FLASH_STAGE_CMDLINE:="))
if normal_line.count(")ro") != 7:
    fail("normal platform target no longer has seven read-only partitions")
if writer_line.count(")ro") != 5 or writer_line.count("22m(openwrt-slot)") != 1:
    fail("writer platform target does not have exactly one writable 22 MiB slot")

with tempfile.TemporaryDirectory() as tmp_name:
    tmp = pathlib.Path(tmp_name)
    target = tmp / "target/linux/octeon/image"
    target.mkdir(parents=True)
    image_makefile = target / "Makefile"
    image_makefile.write_text(
        "define Device/generic\n  DEVICE_VENDOR := Generic\nendef\nTARGET_DEVICES += generic\n\n"
        "RV220W_CMDLINE:=-mtdparts=phys_mapped_flash:512k(boot-chain)ro,6m(stock-kernel)ro,16m(stock-rootfs)ro,1m(stock-data)ro,128k(legacy-env-gap)ro,8448k(vendor-tail)ro,128k(uboot-env)ro console=ttyS0,115200 loglevel=8 ignore_loglevel usbcore.nousb\n"
        "define Device/cisco_rv220w\n  DEVICE_VENDOR := Cisco\n  DEVICE_MODEL := RV220W\n  BOARD_NAME := cisco,rv220w\n  DEVICE_DTS := cn5010_cisco_rv220w\n  DEVICE_PACKAGES += -kmod-usb-dwc3-octeon\n  KERNEL := kernel-bin | strip-kernel | patch-cmdline | append-dtb-to-elf\n  KERNEL_DEPENDS := $$(wildcard $(DTS_DIR)/$(DEVICE_DTS).dts)\n  CMDLINE := $(RV220W_CMDLINE)\n  SUPPORTED_DEVICES += cisco,rv220w\n  IMAGES :=\nendef\nTARGET_DEVICES += cisco_rv220w\n\n"
        "ITUSROUTER_CMDLINE:=console=ttyS0,115200 root=/dev/mmcblk1p2 rootfstype=squashfs,ext4,f2fs rootwait\n"
        "define Device/itus_shield-router\nendef\n"
    )
    subprocess.run(["git", "init", "-q"], cwd=tmp, check=True)
    subprocess.run(["git", "add", "."], cwd=tmp, check=True)
    subprocess.run(["git", "-c", "user.name=test", "-c", "user.email=test@example.invalid", "commit", "-qm", "base"], cwd=tmp, check=True)
    subprocess.run(["git", "apply", "--check", str(delta)], cwd=tmp, check=True)
    subprocess.run(["git", "apply", str(delta)], cwd=tmp, check=True)
    applied = image_makefile.read_text()
    if applied.count("Device/cisco_rv220w_flash_stage") != 1:
        fail("v1.3.2-to-v1.4.0 delta did not add exactly one writer target")

builder = ROOT / "scripts/host/build_rv220w_nor_slot.py"
with tempfile.TemporaryDirectory() as tmp_name:
    tmp = pathlib.Path(tmp_name)
    source = tmp / "test.elf"
    data = bytearray(4096)
    data[:4] = b"\x7fELF"
    data[4] = 2
    data[5] = 2
    data[6] = 1
    struct.pack_into(">HHI", data, 16, 2, 8, 1)
    struct.pack_into(">Q", data, 24, 0xFFFFFFFF819C5270)
    source.write_bytes(data)
    output = tmp / "slot.bin"
    manifest = tmp / "slot.json"
    subprocess.run(["python3", str(builder), "build", str(source), str(output), "--manifest", str(manifest)], check=True, stdout=subprocess.DEVNULL)
    if output.stat().st_size != 22 * 1024 * 1024:
        fail("NOR slot builder did not pad to exactly 22 MiB")
    if output.read_bytes()[:4] != b"\x7fELF" or output.read_bytes()[-16:] != b"\xff" * 16:
        fail("NOR slot builder did not preserve ELF magic and 0xff padding")
    document = json.loads(manifest.read_text())
    if document["boot_address"] != "0xbdc80000" or document["slot_name"] != "openwrt-slot":
        fail("NOR slot manifest has the wrong boot address or slot name")
    if document["ram_load_address"] != "0x05500000":
        fail("NOR slot manifest has the wrong RAM staging address")
    if document["source_copy_size"] != 4096 or document["source_copy_size_hex"] != "0x1000":
        fail("NOR slot manifest has the wrong ELF copy length")
    if document["direct_flash_bootoct_supported"] is not False:
        fail("NOR slot manifest incorrectly permits direct bootoct")
    subprocess.run(["python3", str(builder), "verify", str(output), str(manifest)], check=True, stdout=subprocess.DEVNULL)

build = (ROOT / "scripts/inner/build-openwrt.sh").read_text()
writer_guard = build.split("verify_nor_writer_config() {", 1)[1].split("\n}", 1)[0]
if "verify_rj45_full_config" not in writer_guard:
    fail("NOR-writer guard does not validate the RJ45 production base")
if "\n    verify_luci_config\n" in writer_guard:
    fail("NOR-writer guard still incorrectly requires LuCI")
for token in (
    "CONFIG_PACKAGE_mtd=y",
    "CONFIG_TARGET_octeon_generic_DEVICE_cisco_rv220w_flash_stage=y",
    "CONFIG_PACKAGE_luci-light=y",
    "CONFIG_PACKAGE_uhttpd=y",
):
    if token not in writer_guard:
        fail(f"NOR-writer guard lacks corrected required/forbidden token: {token}")

writer_banner = (ROOT / "openwrt/files-nor-writer/etc/banner").read_text()
if "+ LuCI" in writer_banner:
    fail("NOR-writer banner still claims to contain LuCI")

for token in (
    "rv220w-rj45-luci-initramfs)",
    "rv220w-nor-writer-initramfs)",
    "build_rv220w_nor_slot.py",
    "rm -f \"$serial_log\"",
    "cisco_rv220w_flash_stage",
):
    if token not in build:
        fail(f"build integration lacks: {token}")

print("v1.10.3 LuCI and guarded NOR-stage checks passed")
