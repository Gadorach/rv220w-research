#!/usr/bin/env python3
"""Build or verify the RV220W 22 MiB parallel-NOR OpenWrt slot image."""
from __future__ import annotations

import argparse
import hashlib
import json
import pathlib
import struct
import sys
import tempfile

SLOT_SIZE = 22 * 1024 * 1024
ERASE_SIZE = 128 * 1024
FLASH_BASE = 0xBDC00000
SLOT_OFFSET = 0x00080000
BOOT_ADDRESS = FLASH_BASE + SLOT_OFFSET
RAM_LOAD_ADDRESS = 0x05500000
RAM_COPY_LIMIT = 0x07C00000
BOOTARGS = "console=ttyS0,115200"
FILL = 0xFF


class SlotError(RuntimeError):
    pass


def sha256_path(path: pathlib.Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def parse_elf(path: pathlib.Path) -> dict[str, int | str]:
    data = path.read_bytes()[:64]
    if len(data) < 64 or data[:4] != b"\x7fELF":
        raise SlotError("source does not begin with a complete ELF64 header")
    if data[4] != 2:
        raise SlotError("source is not ELF64")
    if data[5] != 2:
        raise SlotError("source is not big-endian")
    e_type, e_machine = struct.unpack_from(">HH", data, 16)
    if e_type != 2:
        raise SlotError(f"source is not an executable ELF (e_type={e_type})")
    if e_machine != 8:
        raise SlotError(f"source is not MIPS (e_machine={e_machine})")
    entry = struct.unpack_from(">Q", data, 24)[0]
    return {
        "elf_class": "ELF64",
        "elf_data": "big-endian",
        "elf_machine": "MIPS",
        "elf_entry": entry,
    }


def build(source: pathlib.Path, output: pathlib.Path, manifest: pathlib.Path) -> None:
    source = source.resolve()
    if not source.is_file():
        raise SlotError(f"source image not found: {source}")
    metadata = parse_elf(source)
    source_size = source.stat().st_size
    if source_size > SLOT_SIZE:
        raise SlotError(
            f"ELF is {source_size} bytes and exceeds the {SLOT_SIZE}-byte NOR slot"
        )

    output.parent.mkdir(parents=True, exist_ok=True)
    manifest.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(dir=output.parent, delete=False) as tmp:
        temp_path = pathlib.Path(tmp.name)
        with source.open("rb") as src:
            for chunk in iter(lambda: src.read(1024 * 1024), b""):
                tmp.write(chunk)
        remaining = SLOT_SIZE - source_size
        fill_chunk = bytes([FILL]) * min(1024 * 1024, remaining or 1)
        while remaining:
            size = min(len(fill_chunk), remaining)
            tmp.write(fill_chunk[:size])
            remaining -= size
        tmp.flush()
    temp_path.replace(output)

    if output.stat().st_size != SLOT_SIZE:
        raise SlotError("internal error: padded image has the wrong size")

    document = {
        "schema": "rv220w-openwrt-nor-slot-v1",
        "board": "Cisco RV220W",
        "storage": "32 MiB parallel NOR",
        "slot_name": "openwrt-slot",
        "slot_offset": SLOT_OFFSET,
        "slot_size": SLOT_SIZE,
        "erase_size": ERASE_SIZE,
        "fill_byte": FILL,
        "flash_base_kseg1": f"0x{FLASH_BASE:08x}",
        "boot_address": f"0x{BOOT_ADDRESS:08x}",
        "ram_load_address": f"0x{RAM_LOAD_ADDRESS:08x}",
        "source_copy_size": source_size,
        "source_copy_size_hex": f"0x{source_size:x}",
        "boot_method": "copy ELF from memory-mapped NOR to RAM, then run bootoctlinux",
        "direct_flash_bootoct_supported": False,
        "manual_uboot_commands": [
            f"cp.b 0x{BOOT_ADDRESS:08x} 0x{RAM_LOAD_ADDRESS:08x} 0x{source_size:x}",
            f"bootoctlinux 0x{RAM_LOAD_ADDRESS:08x} {BOOTARGS}",
        ],
        "manual_uboot_command": (
            f"cp.b 0x{BOOT_ADDRESS:08x} 0x{RAM_LOAD_ADDRESS:08x} 0x{source_size:x}; "
            f"bootoctlinux 0x{RAM_LOAD_ADDRESS:08x} {BOOTARGS}"
        ),
        "source_name": source.name,
        "source_size": source_size,
        "source_sha256": sha256_path(source),
        "slot_image_name": output.name,
        "slot_image_sha256": sha256_path(output),
        "configuration_persistence": "none; initramfs runtime is recreated on every boot",
        "automatic_boot_environment_change": False,
        "automatic_reboot": False,
        **metadata,
    }
    manifest.write_text(json.dumps(document, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    output.with_suffix(output.suffix + ".sha256").write_text(
        f"{document['slot_image_sha256']}  {output.name}\n", encoding="utf-8"
    )
    print(output)
    print(manifest)



def load_manifest(manifest: pathlib.Path) -> dict[str, object]:
    if not manifest.is_file():
        raise SlotError(f"manifest is missing: {manifest}")
    document = json.loads(manifest.read_text(encoding="utf-8"))
    if document.get("schema") != "rv220w-openwrt-nor-slot-v1":
        raise SlotError("unexpected slot manifest schema")
    return document


def validated_source_size(document: dict[str, object]) -> int:
    source_size = document.get("source_size")
    if not isinstance(source_size, int):
        raise SlotError("manifest source_size is missing or invalid")
    if source_size < 64 or source_size > SLOT_SIZE:
        raise SlotError(f"manifest source_size is outside the NOR slot: {source_size}")
    if RAM_LOAD_ADDRESS + source_size > RAM_COPY_LIMIT:
        raise SlotError(
            "ELF copy would exceed the validated U-Boot RAM staging window: "
            f"end=0x{RAM_LOAD_ADDRESS + source_size:08x}"
        )
    return source_size


def boot_plan(manifest: pathlib.Path) -> None:
    document = load_manifest(manifest)
    if document.get("boot_address") != f"0x{BOOT_ADDRESS:08x}":
        raise SlotError("manifest boot address is incorrect")
    source_size = validated_source_size(document)
    print(f"cp.b 0x{BOOT_ADDRESS:08x} 0x{RAM_LOAD_ADDRESS:08x} 0x{source_size:x}")
    print(f"bootoctlinux 0x{RAM_LOAD_ADDRESS:08x} {BOOTARGS}")


def verify(image: pathlib.Path, manifest: pathlib.Path) -> None:
    if not image.is_file() or not manifest.is_file():
        raise SlotError("image or manifest is missing")
    document = load_manifest(manifest)
    if document.get("slot_name") != "openwrt-slot":
        raise SlotError("manifest targets an unexpected MTD partition")
    if document.get("slot_size") != SLOT_SIZE or image.stat().st_size != SLOT_SIZE:
        raise SlotError("slot image or manifest size is not exactly 22 MiB")
    if image.read_bytes()[:4] != b"\x7fELF":
        raise SlotError("slot image does not begin with ELF magic")
    actual = sha256_path(image)
    if document.get("slot_image_sha256") != actual:
        raise SlotError(
            f"slot SHA-256 mismatch: manifest={document.get('slot_image_sha256')} actual={actual}"
        )
    if document.get("boot_address") != f"0x{BOOT_ADDRESS:08x}":
        raise SlotError("manifest boot address is incorrect")
    source_size = validated_source_size(document)
    if image.read_bytes()[source_size:source_size + 4] not in (b"", b"\xff" * 4):
        raise SlotError("slot padding does not begin with 0xff after source_size")
    print(actual)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    build_parser = sub.add_parser("build")
    build_parser.add_argument("source", type=pathlib.Path)
    build_parser.add_argument("output", type=pathlib.Path)
    build_parser.add_argument("--manifest", type=pathlib.Path)
    verify_parser = sub.add_parser("verify")
    verify_parser.add_argument("image", type=pathlib.Path)
    verify_parser.add_argument("manifest", type=pathlib.Path)
    boot_parser = sub.add_parser("boot-plan")
    boot_parser.add_argument("manifest", type=pathlib.Path)
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if args.command == "build":
        manifest = args.manifest or args.output.with_suffix(args.output.suffix + ".json")
        build(args.source, args.output, manifest)
    elif args.command == "verify":
        verify(args.image, args.manifest)
    else:
        boot_plan(args.manifest)
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (SlotError, OSError, ValueError, json.JSONDecodeError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        raise SystemExit(1)
