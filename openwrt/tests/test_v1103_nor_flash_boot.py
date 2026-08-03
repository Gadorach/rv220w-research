#!/usr/bin/env python3
from __future__ import annotations

import json
import pathlib
import struct
import subprocess
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[1]
HISTORY_DOCS = ROOT.parent / "docs" / "history" / "openwrt" / "toolkit-v1.10.3"


def fail(message: str) -> None:
    raise SystemExit(message)


if (ROOT / "VERSION").read_text().strip() != "1.10.3":
    fail("toolkit version is not 1.10.3")

builder = ROOT / "scripts/host/build_rv220w_nor_slot.py"
host_stage = (ROOT / "scripts/nor-stage.fish").read_text()
target_stage = (ROOT / "openwrt/files-nor-writer/usr/sbin/rv220w-nor-stage").read_text()

for token in (
    "RAM_LOAD_ADDRESS = 0x05500000",
    'sub.add_parser("boot-plan")',
    'print(f"cp.b 0x{BOOT_ADDRESS:08x} 0x{RAM_LOAD_ADDRESS:08x} 0x{source_size:x}")',
    'print(f"bootoctlinux 0x{RAM_LOAD_ADDRESS:08x} {BOOTARGS}")',
    '"direct_flash_bootoct_supported": False',
):
    if token not in builder.read_text():
        fail(f"NOR boot-plan builder lacks token: {token}")

for token in (
    "case boot-plan",
    "Direct bootoct execution from memory-mapped NOR is not supported",
    'command python3 "$slot_helper" boot-plan "$manifest"',
    "copy the ELF to RAM and then use bootoctlinux",
):
    if token not in host_stage:
        fail(f"host NOR stage lacks corrected boot-plan token: {token}")

if "bootoct 0xbdc80000 forceboot" in host_stage:
    fail("host NOR stage still recommends direct bootoct")
if "bootoct 0xbdc80000 forceboot" in target_stage:
    fail("target NOR writer still recommends direct bootoct")
if "copy the ELF from NOR to RAM, then run bootoctlinux" not in target_stage:
    fail("target NOR writer does not describe the corrected loader sequence")

with tempfile.TemporaryDirectory() as tmp_name:
    tmp = pathlib.Path(tmp_name)
    source = tmp / "test.elf"
    size = 0x11565D0
    data = bytearray(size)
    data[:4] = b"\x7fELF"
    data[4] = 2
    data[5] = 2
    data[6] = 1
    struct.pack_into(">HHI", data, 16, 2, 8, 1)
    struct.pack_into(">Q", data, 24, 0xFFFFFFFF819C5270)
    source.write_bytes(data)
    output = tmp / "slot.bin"
    manifest = tmp / "slot.json"
    subprocess.run(
        ["python3", str(builder), "build", str(source), str(output), "--manifest", str(manifest)],
        check=True,
        stdout=subprocess.DEVNULL,
    )
    plan = subprocess.check_output(
        ["python3", str(builder), "boot-plan", str(manifest)],
        text=True,
    ).splitlines()
    expected = [
        "cp.b 0xbdc80000 0x05500000 0x11565d0",
        "bootoctlinux 0x05500000 console=ttyS0,115200",
    ]
    if plan != expected:
        fail(f"unexpected U-Boot plan: {plan!r}")

    document = json.loads(manifest.read_text())
    if document["manual_uboot_commands"] != expected:
        fail("generated manifest does not preserve the two-command boot plan")
    if document["manual_uboot_command"] != "; ".join(expected):
        fail("generated manifest combined command differs from the two-command plan")

    # Compatibility: v1.10.0 manifests already contain source_size and the
    # correct NOR address, even though their advisory command was wrong.
    old_document = dict(document)
    old_document.pop("ram_load_address", None)
    old_document.pop("source_copy_size", None)
    old_document.pop("source_copy_size_hex", None)
    old_document.pop("boot_method", None)
    old_document.pop("direct_flash_bootoct_supported", None)
    old_document.pop("manual_uboot_commands", None)
    old_document["manual_uboot_command"] = "bootoct 0xbdc80000 forceboot"
    old_manifest = tmp / "old-slot.json"
    old_manifest.write_text(json.dumps(old_document))
    old_plan = subprocess.check_output(
        ["python3", str(builder), "boot-plan", str(old_manifest)],
        text=True,
    ).splitlines()
    if old_plan != expected:
        fail("boot-plan is not compatible with an existing v1.10.0 manifest")

for path in (
    ROOT / "README.md",
    HISTORY_DOCS / "FLASH_WORKFLOW.md",
    HISTORY_DOCS / "PROMOTION_PLAN.md",
    HISTORY_DOCS / "RV220W-V1.10.3-NOR-FLASH-BOOT-CORRECTION.md",
):
    if "bootoct 0xbdc80000 forceboot" in path.read_text() and path.name != "RV220W-V1.10.3-NOR-FLASH-BOOT-CORRECTION.md":
        fail(f"active documentation still recommends direct bootoct: {path}")

print("v1.10.3 NOR-to-RAM bootoctlinux boot-plan checks passed")
