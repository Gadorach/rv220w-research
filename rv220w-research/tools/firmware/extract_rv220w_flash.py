#!/usr/bin/env python3
"""Verify, split, analyze, and extract a Cisco RV220W 32 MiB NOR image.

This tool is read-only with respect to the source image.  It knows the flash map
confirmed from two independent UART reads and the stock U-Boot/Linux boot logs.
The JFFS2 data partition contains device-specific configuration and obsolete
TLS key material. This archival workspace extracts it without redaction.
"""
from __future__ import annotations

import argparse
import binascii
import csv
import hashlib
import json
import os
import pathlib
import shutil
import stat
import struct
import subprocess
import sys
from dataclasses import asdict, dataclass
from typing import Iterable

FLASH_SIZE = 0x02000000
KNOWN_SHA256 = "03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5"
KNOWN_CRC32 = 0xCE96F3E0


@dataclass(frozen=True)
class Region:
    name: str
    offset: int
    size: int
    description: str
    sensitive: bool = False


REGIONS = [
    Region("00-bootloader-combined.bin", 0x00000000, 0x00080000, "boot stub and U-Boot"),
    Region("00a-boot-stub.bin", 0x00000000, 0x00030000, "pre-U-Boot boot stage"),
    Region("00b-u-boot.bin", 0x00030000, 0x00050000, "U-Boot proper"),
    Region("01-kernel-partition.bin", 0x00080000, 0x00600000, "vendor header, Linux ELF, and padding"),
    Region("01a-firmware-header.bin", 0x00080000, 0x00000200, "Cisco/Sercomm firmware header"),
    Region("01c-kernel-boot-copy.bin", 0x00080000, 0x00580000, "exact stock bootcmd copy range"),
    Region("02-rootfs.squashfs3-be.bin", 0x00680000, 0x01000000, "big-endian SquashFS 3.0 rootfs"),
    Region("03-data.jffs2-be.bin", 0x01680000, 0x00100000, "big-endian JFFS2 data/config", True),
    Region("04-linux-named-bootload-env.bin", 0x01780000, 0x00020000, "Linux-named environment partition"),
    Region("05-unmapped-vendor-tail.bin", 0x017A0000, 0x00840000, "unmapped vendor tail"),
    Region("06-u-boot-env-actual.bin", 0x01FE0000, 0x00020000, "actual final U-Boot environment sector"),
]


def crc32(data: bytes) -> int:
    return binascii.crc32(data) & 0xFFFFFFFF


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("flash", type=pathlib.Path)
    parser.add_argument("output", type=pathlib.Path)
    parser.add_argument("--expected-sha256", default=None)
    parser.add_argument("--allow-unknown-image", action="store_true", help="accept a valid-size image whose hash differs from the preserved baseline")
    parser.add_argument("--no-rootfs", action="store_true", help="split but do not invoke unsquashfs")
    parser.add_argument("--no-jffs2", action="store_true", help="do not extract the JFFS2 data partition")
    parser.add_argument("--overwrite", action="store_true")
    return parser.parse_args()


def run_capture(command: list[str], output: pathlib.Path) -> int:
    try:
        result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, check=False)
    except FileNotFoundError:
        output.write_text(f"command unavailable: {command[0]}\n", encoding="utf-8")
        return 127
    output.write_text(result.stdout, encoding="utf-8", errors="replace")
    return result.returncode


def elf_extent(data: bytes, offset: int) -> int:
    if data[offset : offset + 4] != b"\x7fELF":
        raise ValueError(f"ELF magic absent at flash offset 0x{offset:x}")
    if data[offset + 4] != 2:
        raise ValueError("expected ELF64 kernel")
    endian = ">" if data[offset + 5] == 2 else "<"
    shoff = struct.unpack_from(endian + "Q", data, offset + 0x28)[0]
    shentsize = struct.unpack_from(endian + "H", data, offset + 0x3A)[0]
    shnum = struct.unpack_from(endian + "H", data, offset + 0x3C)[0]
    extent = shoff + shentsize * shnum
    if extent <= 0 or offset + extent > len(data):
        raise ValueError("invalid ELF section-table extent")
    return extent


def cstring(blob: bytes, offset: int, length: int) -> str:
    return blob[offset : offset + length].split(b"\0", 1)[0].decode("ascii", "replace")


def write_manifest(rows: list[dict[str, object]], reports: pathlib.Path) -> None:
    (reports / "partition-manifest.json").write_text(json.dumps(rows, indent=2) + "\n", encoding="utf-8")
    fields = ["name", "offset", "end", "size", "crc32", "sha256", "ff_percent", "sensitive", "description"]
    with (reports / "partition-manifest.csv").open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)


def inventory_tree(root: pathlib.Path) -> dict[str, object]:
    counts = {"directories": 0, "regular_files": 0, "symlinks": 0, "other": 0, "regular_bytes": 0}
    entries: list[dict[str, object]] = []
    if not root.exists():
        return {"counts": counts, "entries": entries}
    for path in sorted(root.rglob("*")):
        info = path.lstat()
        if stat.S_ISDIR(info.st_mode):
            kind = "directory"
            counts["directories"] += 1
        elif stat.S_ISREG(info.st_mode):
            kind = "file"
            counts["regular_files"] += 1
            counts["regular_bytes"] += info.st_size
        elif stat.S_ISLNK(info.st_mode):
            kind = "symlink"
            counts["symlinks"] += 1
        else:
            kind = "other"
            counts["other"] += 1
        entries.append({"path": str(path.relative_to(root)), "type": kind, "size": info.st_size, "mode": oct(stat.S_IMODE(info.st_mode))})
    return {"counts": counts, "entries": entries}


def main() -> int:
    args = parse_args()
    if not args.flash.is_file():
        print(f"error: dump not found: {args.flash}", file=sys.stderr)
        return 2
    data = args.flash.read_bytes()
    if len(data) != FLASH_SIZE:
        print(f"error: expected 0x{FLASH_SIZE:x} bytes, received 0x{len(data):x}", file=sys.stderr)
        return 2

    full_sha = sha256(data)
    full_crc = crc32(data)
    expected = args.expected_sha256 or KNOWN_SHA256
    if full_sha.lower() != expected.lower() and not args.allow_unknown_image:
        print(f"error: SHA-256 mismatch: {full_sha}; expected {expected}", file=sys.stderr)
        print("Use --allow-unknown-image only for a deliberate analysis of another device/revision.", file=sys.stderr)
        return 2

    if args.output.exists() and any(args.output.iterdir()) and not args.overwrite:
        print(f"error: output directory is not empty: {args.output}; use --overwrite", file=sys.stderr)
        return 2
    args.output.mkdir(parents=True, exist_ok=True)
    parts = args.output / "partitions"
    reports = args.output / "reports"
    extracted = args.output / "extracted"
    for directory in (parts, reports, extracted):
        directory.mkdir(parents=True, exist_ok=True)

    metadata_path = args.flash.with_suffix(args.flash.suffix + ".json")
    metadata_check: dict[str, object] = {"metadata_file": None, "matched": None}
    if metadata_path.exists():
        metadata = json.loads(metadata_path.read_text(encoding="utf-8"))
        metadata_check = {
            "metadata_file": str(metadata_path),
            "completed": metadata.get("completed"),
            "target_crc32_before": metadata.get("target_crc32_before"),
            "target_crc32_after": metadata.get("target_crc32_after"),
            "host_crc32": metadata.get("host_crc32"),
            "host_sha256": metadata.get("host_sha256"),
            "matched": metadata.get("host_sha256") == full_sha and metadata.get("host_crc32", "").lower() == f"{full_crc:08x}",
        }

    rows: list[dict[str, object]] = []
    for region in REGIONS:
        blob = data[region.offset : region.offset + region.size]
        target = parts / region.name
        target.write_bytes(blob)
        rows.append(
            {
                "name": region.name,
                "offset": f"0x{region.offset:08x}",
                "end": f"0x{region.offset + region.size:08x}",
                "size": f"0x{region.size:x}",
                "crc32": f"{crc32(blob):08x}",
                "sha256": sha256(blob),
                "ff_percent": round(blob.count(0xFF) * 100.0 / len(blob), 6),
                "sensitive": region.sensitive,
                "description": region.description,
            }
        )

    kernel_offset = 0x00080200
    kernel_size = elf_extent(data, kernel_offset)
    kernel = data[kernel_offset : kernel_offset + kernel_size]
    (parts / "01b-linux-kernel.elf").write_bytes(kernel)
    rows.append(
        {
            "name": "01b-linux-kernel.elf",
            "offset": f"0x{kernel_offset:08x}",
            "end": f"0x{kernel_offset + kernel_size:08x}",
            "size": f"0x{kernel_size:x}",
            "crc32": f"{crc32(kernel):08x}",
            "sha256": sha256(kernel),
            "ff_percent": round(kernel.count(0xFF) * 100.0 / len(kernel), 6),
            "sensitive": False,
            "description": "complete stock ELF64 big-endian Octeon Linux kernel",
        }
    )

    header = data[0x80000:0x80200]
    image_size = struct.unpack_from(">I", header, 0x10)[0]
    vendor_image = data[0x80000 : 0x80000 + image_size]
    vendor_path = parts / "07-RV220W-Firmware-recovered.img"
    vendor_path.write_bytes(vendor_image)
    checksum_copy = bytearray(vendor_image)
    checksum_copy[0x14:0x18] = b"\0\0\0\0"
    stored_checksum = struct.unpack_from(">I", header, 0x14)[0]
    header_report = {
        "field_0x04": f"0x{struct.unpack_from('>I', header, 0x04)[0]:08x}",
        "field_0x08": f"0x{struct.unpack_from('>I', header, 0x08)[0]:08x}",
        "used_length_0x0c": struct.unpack_from(">I", header, 0x0C)[0],
        "image_size_0x10": image_size,
        "additive_checksum_0x14": f"0x{stored_checksum:08x}",
        "additive_checksum_recomputed": f"0x{sum(checksum_copy) & 0xFFFFFFFF:08x}",
        "additive_checksum_matches": (sum(checksum_copy) & 0xFFFFFFFF) == stored_checksum,
        "firmware_version": cstring(header, 0x1C, 12),
        "hardware_version": cstring(header, 0x28, 12),
        "image_family": cstring(header, 0x34, 32),
        "build_time": cstring(header, 0x54, 32),
        "image_name": cstring(header, 0x74, 64),
        "trailer_magic_present": b"FWCHKADDISABABA" in vendor_image[-0x100:],
        "sha256": sha256(vendor_image),
    }
    (reports / "vendor-firmware-header.json").write_text(json.dumps(header_report, indent=2) + "\n", encoding="utf-8")

    write_manifest(rows, reports)
    full_report = {
        "source": str(args.flash.resolve()),
        "size": len(data),
        "crc32": f"{full_crc:08x}",
        "sha256": full_sha,
        "known_baseline_sha256": KNOWN_SHA256,
        "known_baseline_match": full_sha == KNOWN_SHA256,
        "known_baseline_crc32_match": full_crc == KNOWN_CRC32,
        "uart_metadata": metadata_check,
    }
    (reports / "full-image-validation.json").write_text(json.dumps(full_report, indent=2) + "\n", encoding="utf-8")

    run_capture(["file", str(args.flash), *[str(parts / region.name) for region in REGIONS], str(parts / "01b-linux-kernel.elf")], reports / "file-identification.txt")
    run_capture(["readelf", "-a", str(parts / "01b-linux-kernel.elf")], reports / "kernel-readelf.txt")
    run_capture(["strings", "-a", "-t", "x", str(parts / "00-bootloader-combined.bin")], reports / "bootloader-strings.txt")
    run_capture(["strings", "-a", str(parts / "01b-linux-kernel.elf")], reports / "kernel-strings.txt")

    extraction_status: dict[str, object] = {}
    rootfs_output = extracted / "rootfs"
    if not args.no_rootfs:
        unsquashfs = shutil.which("unsquashfs")
        if unsquashfs is None:
            extraction_status["rootfs"] = "unsquashfs unavailable"
        else:
            if rootfs_output.exists() and args.overwrite:
                shutil.rmtree(rootfs_output)
            command = [unsquashfs, "-no-progress", "-d", str(rootfs_output), str(parts / "02-rootfs.squashfs3-be.bin")]
            result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, check=False)
            (reports / "unsquashfs.log").write_text(result.stdout, encoding="utf-8", errors="replace")
            extraction_status["rootfs"] = {"returncode": result.returncode, "path": str(rootfs_output)}
            if result.returncode != 0:
                print("warning: unsquashfs failed; inspect reports/unsquashfs.log", file=sys.stderr)
    else:
        extraction_status["rootfs"] = "skipped"

    data_output = extracted / "data-jffs2"
    if not args.no_jffs2:
        helper = pathlib.Path(__file__).with_name("extract_jffs2_be.py")
        if data_output.exists() and args.overwrite:
            shutil.rmtree(data_output)
        command = [sys.executable, str(helper), str(parts / "03-data.jffs2-be.bin"), str(data_output), "--report", str(reports / "data-jffs2-report.json")]
        result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, check=False)
        (reports / "jffs2-extraction.log").write_text(result.stdout, encoding="utf-8", errors="replace")
        extraction_status["jffs2"] = {"returncode": result.returncode, "path": str(data_output), "contains_device_data": True}
        if result.returncode != 0:
            print("warning: JFFS2 extraction failed; inspect reports/jffs2-extraction.log", file=sys.stderr)
    else:
        extraction_status["jffs2"] = "skipped"

    (reports / "rootfs-inventory.json").write_text(json.dumps(inventory_tree(rootfs_output), indent=2) + "\n", encoding="utf-8")
    if data_output.exists():
        data_inventory = inventory_tree(data_output)
        # Do not print file contents while generating the inventory.
        (reports / "data-jffs2-inventory-SENSITIVE.json").write_text(json.dumps(data_inventory, indent=2) + "\n", encoding="utf-8")
    (reports / "extraction-status.json").write_text(json.dumps(extraction_status, indent=2) + "\n", encoding="utf-8")

    readme = f"""# RV220W dump extraction\n\nSource: `{args.flash}`\n\n- Size: `0x{len(data):x}`\n- CRC32: `{full_crc:08x}`\n- SHA-256: `{full_sha}`\n- Preserved baseline match: `{full_sha == KNOWN_SHA256}`\n\nThe physical partitions are in `partitions/`.  The SquashFS tree is in\n`extracted/rootfs/` when `unsquashfs` succeeded.\n\n**Sensitive:** `partitions/03-data.jffs2-be.bin` and\n`extracted/data-jffs2/` can contain a private TLS key, logs, and\ndevice-specific configuration.  Do not publish them.\n\nThe Linux partition named `bootload-env` at offset `0x01780000` is not the\nactual U-Boot environment.  The environment address reported by U-Boot maps to\nthe final sector at offset `0x01fe0000`.\n"""
    (args.output / "README.md").write_text(readme, encoding="utf-8")

    print(f"Verified image: CRC32 {full_crc:08x}; SHA-256 {full_sha}")
    print(f"Output: {args.output}")
    if not args.no_jffs2:
        print("JFFS2 extraction includes the factory-reset configuration and obsolete TLS key.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
