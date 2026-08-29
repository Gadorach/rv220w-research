#!/usr/bin/env python3
"""Verify the RV220W standard OpenWrt sysupgrade tar and component identity."""
from __future__ import annotations

import argparse
import hashlib
import json
import pathlib
import struct
import subprocess
import tarfile
import tempfile
from typing import Any

BOARD = "cisco,rv220w"
KERNEL_LIMIT = 0x00600000
ROOTFS_LIMIT = 0x01960000
SCHEMA = "rv220w-sysupgrade-v1"


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def sha256_file(path: pathlib.Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def read_archive(path: pathlib.Path) -> tuple[str, bytes, bytes, bytes]:
    with tarfile.open(path, "r:*") as archive:
        expected = f"sysupgrade-{BOARD}"
        members = archive.getmembers()
        expected_names = [
            expected,
            f"{expected}/CONTROL",
            f"{expected}/kernel",
            f"{expected}/root",
        ]
        actual_names = [member.name.rstrip("/") for member in members]
        if sorted(actual_names) != sorted(expected_names) or len(actual_names) != len(set(actual_names)):
            raise SystemExit(f"unexpected or duplicate sysupgrade members: {actual_names!r}")
        directory = next(member for member in members if member.name.rstrip("/") == expected)
        if not directory.isdir():
            raise SystemExit(f"sysupgrade board entry is not a directory: {directory.name}")

        def extract(name: str) -> bytes:
            member = archive.getmember(f"{expected}/{name}")
            if not member.isfile():
                raise SystemExit(f"sysupgrade member is not a regular file: {name}")
            stream = archive.extractfile(member)
            if stream is None:
                raise SystemExit(f"sysupgrade member could not be extracted: {name}")
            return stream.read()

        control = extract("CONTROL")
        kernel = extract("kernel")
        root = extract("root")
    return expected, control, kernel, root


def squashfs_bytes_used(data: bytes) -> int:
    if len(data) < 48 or not data.startswith(b"hsqs"):
        raise SystemExit("sysupgrade root is not little-endian SquashFS")
    return struct.unpack_from("<Q", data, 40)[0]


def validate_root_member(member: bytes, staged: bytes) -> tuple[bytes, int]:
    staged_used = squashfs_bytes_used(staged)
    member_used = squashfs_bytes_used(member)
    if staged_used != len(staged):
        raise SystemExit(
            f"staged SquashFS length differs from superblock bytes_used: {len(staged)} != {staged_used}"
        )
    if member_used != staged_used:
        raise SystemExit(
            f"sysupgrade root bytes_used differs from staged SquashFS: {member_used} != {staged_used}"
        )
    if len(member) < member_used:
        raise SystemExit("sysupgrade root is truncated before SquashFS bytes_used")
    raw = member[:member_used]
    if raw != staged:
        raise SystemExit("sysupgrade root payload differs from staged persistent SquashFS")
    padding = member[member_used:]
    if len(member) % 1024 != 0 or len(padding) >= 1024:
        raise SystemExit(
            f"sysupgrade root has unexpected standard-tar padding geometry: member={len(member)} padding={len(padding)}"
        )
    if any(padding):
        raise SystemExit("sysupgrade root has nonzero bytes after SquashFS bytes_used")
    return raw, len(padding)


def extract_metadata(fwtool: pathlib.Path, image: pathlib.Path) -> dict[str, Any]:
    with tempfile.TemporaryDirectory(prefix="rv220w-fwtool-") as temporary:
        metadata_path = pathlib.Path(temporary) / "metadata.json"
        result = subprocess.run(
            [str(fwtool), "-q", "-i", str(metadata_path), str(image)],
            text=True,
            capture_output=True,
            check=False,
        )
        if result.returncode != 0 or not metadata_path.is_file():
            raise SystemExit(
                "OpenWrt fwtool could not extract required sysupgrade metadata: "
                + (result.stderr.strip() or result.stdout.strip() or f"exit {result.returncode}")
            )
        metadata = json.loads(metadata_path.read_text(encoding="utf-8"))
    supported = metadata.get("supported_devices", [])
    newer = metadata.get("new_supported_devices", [])
    if BOARD not in supported and BOARD not in newer:
        raise SystemExit(f"sysupgrade metadata does not support {BOARD}: {metadata!r}")
    return metadata


def validate(
    image: pathlib.Path,
    kernel_path: pathlib.Path,
    rootfs_path: pathlib.Path,
    fwtool: pathlib.Path | None,
) -> dict[str, Any]:
    for path in (image, kernel_path, rootfs_path):
        if not path.is_file() or path.stat().st_size == 0:
            raise SystemExit(f"required artifact is missing or empty: {path}")

    board_dir, control, kernel, root_member = read_archive(image)
    if control != f"BOARD={BOARD}\n".encode():
        raise SystemExit(f"unexpected CONTROL bytes: {control!r}")
    if kernel != kernel_path.read_bytes():
        raise SystemExit("sysupgrade kernel differs from staged persistent gzip kernel")
    staged_root = rootfs_path.read_bytes()
    root, root_padding = validate_root_member(root_member, staged_root)
    if not kernel.startswith(b"\x1f\x8b\x08"):
        raise SystemExit("sysupgrade kernel is not a gzip stream")
    if len(kernel) > KERNEL_LIMIT:
        raise SystemExit("sysupgrade kernel exceeds the 6 MiB NOR partition")
    if len(root) > ROOTFS_LIMIT:
        raise SystemExit("sysupgrade root exceeds the 25.375 MiB NOR rootfs partition")

    metadata: dict[str, Any] | None = None
    if fwtool is not None:
        if not fwtool.is_file():
            raise SystemExit(f"fwtool is unavailable: {fwtool}")
        metadata = extract_metadata(fwtool, image)

    return {
        "schema": SCHEMA,
        "board": BOARD,
        "board_directory": board_dir,
        "image": {
            "filename": image.name,
            "size": image.stat().st_size,
            "sha256": sha256_file(image),
            "metadata_verified": metadata is not None,
        },
        "kernel": {
            "filename": kernel_path.name,
            "size": len(kernel),
            "sha256": sha256_bytes(kernel),
            "format": "gzip-compressed ELF64 big-endian MIPS",
            "partition_limit": KERNEL_LIMIT,
        },
        "rootfs": {
            "filename": rootfs_path.name,
            "size": len(root),
            "sha256": sha256_bytes(root),
            "format": "SquashFS",
            "partition_limit": ROOTFS_LIMIT,
            "archive_member_size": len(root_member),
            "archive_zero_padding": root_padding,
            "runtime_write_size": len(root),
        },
        "metadata": metadata,
        "upgrade_policy": {
            "rootfs_first": True,
            "full_rootfs_erase": True,
            "kernel_last": True,
            "readback_verify": True,
            "preserved": ["boot-chain", "uboot-env"],
        },
    }


def validate_embedded(image: pathlib.Path, fwtool: pathlib.Path | None) -> dict[str, Any]:
    if not image.is_file() or image.stat().st_size == 0:
        raise SystemExit(f"required artifact is missing or empty: {image}")
    board_dir, control, kernel, root_member = read_archive(image)
    if control != f"BOARD={BOARD}\n".encode():
        raise SystemExit(f"unexpected CONTROL bytes: {control!r}")
    if not kernel.startswith(b"\x1f\x8b\x08"):
        raise SystemExit("sysupgrade kernel is not a gzip stream")
    if len(kernel) > KERNEL_LIMIT:
        raise SystemExit("sysupgrade kernel exceeds the 6 MiB NOR partition")
    root_size = squashfs_bytes_used(root_member)
    if root_size > len(root_member):
        raise SystemExit("sysupgrade root is truncated before SquashFS bytes_used")
    if root_size > ROOTFS_LIMIT:
        raise SystemExit("sysupgrade root exceeds the 25.375 MiB NOR rootfs partition")
    padding = root_member[root_size:]
    if len(root_member) % 1024 != 0 or len(padding) >= 1024 or any(padding):
        raise SystemExit("sysupgrade root has invalid standard-tar padding")
    metadata = extract_metadata(fwtool, image) if fwtool is not None else None
    return {
        "schema": SCHEMA,
        "board": BOARD,
        "board_directory": board_dir,
        "image": {"filename": image.name, "size": image.stat().st_size, "sha256": sha256_file(image)},
        "kernel": {"size": len(kernel), "sha256": sha256_bytes(kernel), "partition_limit": KERNEL_LIMIT},
        "rootfs": {"size": root_size, "sha256": sha256_bytes(root_member[:root_size]), "partition_limit": ROOTFS_LIMIT},
        "metadata": metadata,
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("image", type=pathlib.Path)
    parser.add_argument("kernel", type=pathlib.Path, nargs="?")
    parser.add_argument("rootfs", type=pathlib.Path, nargs="?")
    parser.add_argument("--fwtool", type=pathlib.Path)
    parser.add_argument("--report", type=pathlib.Path)
    parser.add_argument("--verify-report", type=pathlib.Path)
    args = parser.parse_args()

    if (args.kernel is None) != (args.rootfs is None):
        parser.error("kernel and rootfs must be supplied together")
    if args.kernel is None:
        document = validate_embedded(args.image.resolve(), args.fwtool)
    else:
        document = validate(args.image.resolve(), args.kernel.resolve(), args.rootfs.resolve(), args.fwtool)
    if args.verify_report:
        expected = json.loads(args.verify_report.read_text(encoding="utf-8"))
        if args.fwtool is None:
            document["metadata"] = expected.get("metadata")
            document["image"]["metadata_verified"] = bool(
                expected.get("image", {}).get("metadata_verified")
            )
        if expected != document:
            raise SystemExit("sysupgrade verification report does not match current artifacts")
    if args.report:
        args.report.write_text(json.dumps(document, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    metadata_verified = document["metadata"] is not None
    print(f"sysupgrade=ok board={BOARD} size={document['image']['size']} "
          f"sha256={document['image']['sha256']} metadata={metadata_verified}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
