#!/usr/bin/env python3
"""Conservatively repair stale RV220W build-time DTS substitutions.

The DSA builders temporarily substitute a LAN-only, dual-conduit validation,
or full-RJ45 production DTS into OpenWrt's Octeon target overlay.  A killed
build may leave one of those known generated trees behind.  This helper
restores the canonical hardware-proven v1.3.2 DTS only when the current file
is an exact/structural match for a toolkit-generated tree.  Unknown
local edits are never overwritten.
"""
from __future__ import annotations

import argparse
import hashlib
import os
import pathlib
import re
import tempfile
from typing import NoReturn

LAN_VARIANTS = (
    ("rxid", "rgmii-rxid"),
    ("txid", "rgmii-txid"),
    ("rgmii", "rgmii"),
)

DUAL_VARIANTS = (
    ("rxid", "rgmii-rxid"),
    ("wan-txid", "rgmii-txid"),
    ("wan-rgmii", "rgmii"),
)


def die(message: str) -> NoReturn:
    raise SystemExit(f"error: {message}")


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def render_candidates(template_path: pathlib.Path) -> set[bytes]:
    template = template_path.read_text(encoding="utf-8")
    candidates: set[bytes] = set()
    if "@PHY_MODE@" in template:
        for variant, phy_mode in LAN_VARIANTS:
            rendered = template.replace("@VARIANT@", variant).replace("@PHY_MODE@", phy_mode)
            candidates.add(rendered.encode("utf-8"))
    elif "@WAN_PHY_MODE@" in template:
        for variant, phy_mode in DUAL_VARIANTS:
            rendered = template.replace("@VARIANT@", variant).replace("@WAN_PHY_MODE@", phy_mode)
            candidates.add(rendered.encode("utf-8"))
    else:
        die(f"unrecognized DSA DTS template placeholders: {template_path}")
    return candidates


def atomic_write(path: pathlib.Path, data: bytes) -> None:
    mode = path.stat().st_mode & 0o777
    fd, temporary = tempfile.mkstemp(prefix=f".{path.name}.", dir=path.parent)
    tmp = pathlib.Path(temporary)
    try:
        with os.fdopen(fd, "wb") as handle:
            handle.write(data)
            handle.flush()
            os.fsync(handle.fileno())
        os.chmod(tmp, mode)
        os.replace(tmp, path)
    finally:
        tmp.unlink(missing_ok=True)


def has_common_platform_shape(text: str) -> bool:
    checks = (
        re.search(r'compatible\s*=\s*"cisco,rv220w"\s*,\s*"cavium,octeon-3860"\s*;', text),
        "switch@1e" in text,
        "&bootbus" in text,
        "nor@0,0" in text,
        "clock-frequency = <400000000>;" in text,
    )
    return all(checks)


def is_platform_compatible(text: str) -> bool:
    return bool(
        re.search(r'^\s*model\s*=\s*"Cisco RV220W"\s*;', text, re.MULTILINE)
        and has_common_platform_shape(text)
    )


def is_generated_lan_candidate(text: str) -> bool:
    checks = (
        re.search(
            r'^\s*model\s*=\s*"Cisco RV220W LAN-only DSA validation \([^"\n]+\)"\s*;',
            text,
            re.MULTILINE,
        ),
        has_common_platform_shape(text),
        "port@1" in text,
        "port@4" in text,
        "port@8" in text,
        "port@0" not in text,
        "port@5" not in text,
        "ethernet = <&rv220w_eth0>;" in text,
        re.search(r'label\s*=\s*"lan1"\s*;', text),
        re.search(r'label\s*=\s*"lan4"\s*;', text),
        re.search(r'ethernet@1\s*\{\s*status\s*=\s*"disabled"\s*;\s*\}', text),
    )
    return all(checks)


def is_generated_dual_candidate(text: str) -> bool:
    checks = (
        re.search(
            r'^\s*model\s*=\s*"Cisco RV220W dual-conduit DSA validation \([^"\n]+\)"\s*;',
            text,
            re.MULTILINE,
        ),
        has_common_platform_shape(text),
        "port@0" in text,
        "port@1" in text,
        "port@4" in text,
        "port@5" in text,
        "port@8" in text,
        "ethernet = <&rv220w_eth0>;" in text,
        "ethernet = <&rv220w_eth1>;" in text,
        re.search(r'label\s*=\s*"wan"\s*;', text),
        re.search(r'label\s*=\s*"cpu-wan"\s*;', text),
        re.search(r'label\s*=\s*"cpu-lan"\s*;', text),
        re.search(r'ethernet@2\s*\{\s*status\s*=\s*"disabled"\s*;\s*\}', text),
    )
    return all(checks)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("target")
    parser.add_argument("canonical")
    parser.add_argument("templates", nargs="+")
    args = parser.parse_args()

    target = pathlib.Path(args.target).resolve()
    canonical = pathlib.Path(args.canonical).resolve()
    templates = [pathlib.Path(item).resolve() for item in args.templates]
    for path in (target, canonical, *templates):
        if not path.is_file():
            die(f"required DTS file is missing: {path}")

    current = target.read_bytes()
    expected = canonical.read_bytes()

    if current == expected:
        print(f"RV220W source DTS is already canonical: {target}")
        return 0

    exact_candidates: set[bytes] = set()
    for template in templates:
        exact_candidates.update(render_candidates(template))

    try:
        current_text = current.decode("utf-8", errors="strict")
    except UnicodeDecodeError as exc:
        die(f"RV220W source DTS is not valid UTF-8: {target}: {exc}")

    if (
        current in exact_candidates
        or is_generated_lan_candidate(current_text)
        or is_generated_dual_candidate(current_text)
    ):
        old_hash = sha256(current)
        atomic_write(target, expected)
        if target.read_bytes() != expected:
            die(f"canonical DTS verification failed after repair: {target}")
        print(f"repaired stale RV220W DSA source DTS: {target}")
        print(f"replaced_sha256={old_hash}")
        print(f"canonical_sha256={sha256(expected)}")
        return 0

    if is_platform_compatible(current_text):
        print(f"RV220W source DTS contains platform-compatible local formatting/edits; left unchanged: {target}")
        return 0

    die(
        "refusing to overwrite an unrecognized RV220W source DTS; "
        f"target={target} sha256={sha256(current)}"
    )


if __name__ == "__main__":
    raise SystemExit(main())
