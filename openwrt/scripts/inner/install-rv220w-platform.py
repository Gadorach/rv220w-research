#!/usr/bin/env python3
"""Install or verify the Cisco RV220W OpenWrt platform integration.

The integration targets the pinned OpenWrt v25.12.5 source tree. It adds
independent kernel patches and the board DTS through the target overlay.
"""
from __future__ import annotations

import argparse
import pathlib
import re
import subprocess
import sys
from typing import NoReturn

VERSION = "1.4.0"
EXPECTED_REF = "v25.12.5"
VERSIONS = ("1.2.0", "1.3.0", "1.3.1", "1.3.2", "1.4.0")


def run(cmd: list[str], *, cwd: pathlib.Path | None = None, check: bool = True) -> subprocess.CompletedProcess[str]:
    return subprocess.run(cmd, cwd=cwd, text=True, capture_output=True, check=check)


def die(message: str) -> NoReturn:
    raise SystemExit(f"error: {message}")


def exact_ref(tree: pathlib.Path) -> str:
    result = run(["git", "describe", "--tags", "--exact-match", "HEAD"], cwd=tree, check=False)
    return result.stdout.strip() if result.returncode == 0 else ""


def validate_nested_patch(path: pathlib.Path) -> None:
    """Validate unified-diff hunk counts inside an OpenWrt kernel patch file."""
    hunk_re = re.compile(r"^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@")
    lines = path.read_text(encoding="utf-8").splitlines()
    i = 0
    found = 0
    while i < len(lines):
        match = hunk_re.match(lines[i])
        if not match:
            i += 1
            continue
        found += 1
        old_expected = int(match.group(2) or "1")
        new_expected = int(match.group(4) or "1")
        old_seen = new_seen = 0
        i += 1
        while i < len(lines):
            line = lines[i]
            if line.startswith("@@ ") or line.startswith("--- a/") or line.startswith("--- /dev/null"):
                break
            if line.startswith(" "):
                old_seen += 1
                new_seen += 1
            elif line.startswith("-") and not line.startswith("---"):
                old_seen += 1
            elif line.startswith("+") and not line.startswith("+++"):
                new_seen += 1
            elif line.startswith("\\ No newline"):
                pass
            else:
                break
            i += 1
        if (old_seen, new_seen) != (old_expected, new_expected):
            die(
                f"malformed nested patch {path}: expected old/new "
                f"{old_expected}/{new_expected}, saw {old_seen}/{new_seen}"
            )
    if not found:
        die(f"no unified hunks found in nested patch: {path}")


def verify(tree: pathlib.Path) -> None:
    required = {
        tree / "target/linux/octeon/image/Makefile": "Device/cisco_rv220w",
        tree / "target/linux/octeon/base-files/etc/board.d/01_network": "cisco,rv220w)",
        tree / "target/linux/octeon/base-files/lib/preinit/01_sysinfo": '"cisco,rv220w"*',
        tree / "target/linux/octeon/patches-6.12/405-rv220w-guard-ubnt-pruning.patch": "CVMX_BOARD_TYPE_UBNT_E300",
        tree / "target/linux/octeon/patches-6.12/410-cisco-rv220w-dtb-makefile.patch": "cn5010_cisco_rv220w.dtb",
    }
    for path, token in required.items():
        if not path.is_file():
            die(f"required platform file is missing: {path}")
        if token not in path.read_text(encoding="utf-8"):
            die(f"required platform token {token!r} is missing from {path}")

    dts_path = tree / "target/linux/octeon/files/arch/mips/boot/dts/cavium-octeon/cn5010_cisco_rv220w.dts"
    if not dts_path.is_file():
        die(f"required platform file is missing: {dts_path}")
    dts = dts_path.read_text(encoding="utf-8")
    if not re.search(r'^\s*model\s*=\s*"Cisco RV220W"\s*;', dts, re.MULTILINE):
        die("DTS model is not the canonical Cisco RV220W platform model")
    if not re.search(
        r'compatible\s*=\s*"cisco,rv220w"\s*,\s*"cavium,octeon-3860"\s*;',
        dts,
    ):
        die("DTS compatible list does not identify the Cisco RV220W/CN5010 platform")
    for token in (
        'compatible = "cisco,rv220w", "cavium,octeon-3860";',
        '&usbn',
        'status = "disabled";',
        'switch@1e',
        'reg = <0x1e>;',
        'gpios = <&gpio 1 GPIO_ACTIVE_LOW>;',
        '&bootbus',
        'uart0 = &uart0;',
        'clock-frequency = <400000000>;',
        '/delete-node/ compact-flash@5,0;',
        'nor@0,0 {',
    ):
        if token not in dts:
            die(f"DTS verification token missing: {token}")
    if '&bootbus {\n\tstatus = "okay";' not in dts:
        die("DTS BootBus parent is not enabled")
    if 'nor@0,0 {\n\t\tstatus = "okay";' not in dts:
        die("DTS does not restore the v1.3.0 NOR trigger child")
    if '/delete-node/ nor@0,0;' in dts:
        die("DTS still deletes the NOR trigger child")

    image_makefile = (tree / "target/linux/octeon/image/Makefile").read_text(encoding="utf-8")
    if image_makefile.count("IMAGES :=") < 2:
        die("RV220W profiles unexpectedly declare installable images")
    if "Device/cisco_rv220w_flash_stage" not in image_makefile:
        die("RV220W NOR-writer device profile is missing")
    if "TARGET_DEVICES += cisco_rv220w_flash_stage" not in image_makefile:
        die("RV220W NOR-writer device is not registered")

    lines = image_makefile.splitlines()
    normal_cmdline = next((line for line in lines if line.startswith("RV220W_CMDLINE:=")), "")
    writer_cmdline = next((line for line in lines if line.startswith("RV220W_FLASH_STAGE_CMDLINE:=")), "")
    if not normal_cmdline or normal_cmdline.count(")ro") != 7:
        die("RV220W normal command line does not preserve all seven read-only partitions")
    if "22m(openwrt-slot)" not in writer_cmdline:
        die("RV220W NOR-writer command line lacks the 22 MiB openwrt-slot")
    if writer_cmdline.count("22m(openwrt-slot)") != 1:
        die("RV220W NOR-writer command line has an ambiguous openwrt-slot")
    if writer_cmdline.count(")ro") != 5:
        die("RV220W NOR-writer command line does not keep every non-slot partition read-only")
    for forbidden in ("boot-chain)", "stock-data)", "legacy-env-gap)", "vendor-tail)", "uboot-env)"):
        # These regions must only occur in their explicitly read-only form.
        if forbidden.replace(")", ")ro") not in writer_cmdline:
            die(f"RV220W NOR-writer command line does not protect {forbidden[:-1]}")

    validate_nested_patch(tree / "target/linux/octeon/patches-6.12/405-rv220w-guard-ubnt-pruning.patch")
    validate_nested_patch(tree / "target/linux/octeon/patches-6.12/410-cisco-rv220w-dtb-makefile.patch")

    marker = tree / ".rv220w-platform-version"
    if marker.is_file() and marker.read_text(encoding="utf-8").strip() != VERSION:
        die(f"unexpected platform marker version in {marker}")


def apply_patch(tree: pathlib.Path, patch: pathlib.Path, description: str) -> None:
    check = run(["git", "apply", "--check", "--whitespace=nowarn", str(patch)], cwd=tree, check=False)
    if check.returncode != 0:
        sys.stderr.write(check.stdout)
        sys.stderr.write(check.stderr)
        die(f"{description} does not apply cleanly")
    run(["git", "apply", "--whitespace=nowarn", str(patch)], cwd=tree)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("tree", help="OpenWrt source tree")
    parser.add_argument("--verify-only", action="store_true")
    parser.add_argument("--allow-ref-mismatch", action="store_true")
    args = parser.parse_args()

    tree = pathlib.Path(args.tree).expanduser().resolve()
    if not (tree / ".git").is_dir() or not (tree / "target/linux/octeon").is_dir():
        die(f"not an OpenWrt Octeon source tree: {tree}")

    toolkit = pathlib.Path(__file__).resolve().parents[2]
    full_patches = {version: toolkit / f"openwrt/platform/openwrt-rv220w-platform-v{version}.patch" for version in VERSIONS}
    upgrades = {
        ("1.2.0", "1.3.0"): toolkit / "openwrt/platform/openwrt-rv220w-platform-v1.2.0-to-v1.3.0.patch",
        ("1.3.0", "1.3.1"): toolkit / "openwrt/platform/openwrt-rv220w-platform-v1.3.0-to-v1.3.1.patch",
        ("1.3.1", "1.3.2"): toolkit / "openwrt/platform/openwrt-rv220w-platform-v1.3.1-to-v1.3.2.patch",
        ("1.3.2", "1.4.0"): toolkit / "openwrt/platform/openwrt-rv220w-platform-v1.3.2-to-v1.4.0.patch",
    }
    for required_patch in (*full_patches.values(), *upgrades.values()):
        if not required_patch.is_file():
            die(f"platform patch is missing: {required_patch}")

    ref = exact_ref(tree)
    if ref != EXPECTED_REF and not args.allow_ref_mismatch:
        die(f"expected OpenWrt {EXPECTED_REF}, found exact ref {ref or '<none>'}")

    marker = tree / ".rv220w-platform-version"
    marker_version = marker.read_text(encoding="utf-8").strip() if marker.is_file() else ""
    if marker_version == VERSION:
        verify(tree)
        print(f"RV220W platform v{VERSION} already installed and verified")
        return 0

    current = marker_version if marker_version in VERSIONS else ""
    if not current:
        for candidate in reversed(VERSIONS):
            reverse = run(
                ["git", "apply", "--reverse", "--check", "--whitespace=nowarn", str(full_patches[candidate])],
                cwd=tree,
                check=False,
            )
            if reverse.returncode == 0:
                current = candidate
                break

    if current == VERSION:
        verify(tree)
        marker.write_text(VERSION + "\n", encoding="utf-8")
        print(f"RV220W platform v{VERSION} already installed and verified")
        return 0

    if current:
        if args.verify_only:
            die(f"RV220W platform v{current} is installed; run platform install to upgrade to v{VERSION}")
        start = VERSIONS.index(current)
        for old, new in zip(VERSIONS[start:-1], VERSIONS[start + 1:]):
            apply_patch(tree, upgrades[(old, new)], f"RV220W v{old}-to-v{new} upgrade patch")
        marker.write_text(VERSION + "\n", encoding="utf-8")
        verify(tree)
        print(f"upgraded and verified RV220W platform v{current} -> v{VERSION} in {tree}")
        return 0

    if args.verify_only:
        die("RV220W platform is not fully installed")

    tracked_dirty = run(["git", "status", "--porcelain", "--untracked-files=no"], cwd=tree).stdout.strip()
    if tracked_dirty:
        die("OpenWrt tree has tracked modifications; use a clean v25.12.5 checkout")

    apply_patch(tree, full_patches[VERSION], "RV220W platform patch")
    marker.write_text(VERSION + "\n", encoding="utf-8")
    verify(tree)
    print(f"installed and verified RV220W platform v{VERSION} in {tree}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
