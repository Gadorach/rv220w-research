#!/usr/bin/env python3
from __future__ import annotations

import argparse
import pathlib
import re
import shutil
import subprocess

ROOT = pathlib.Path(__file__).resolve().parents[2]
VERSION = (ROOT / "VERSION").read_text().strip()
OPENWRT_REF = "v25.12.5"


RELEASE_VERSION_RE = re.compile(r"^1\.16\.0(?:-rc[0-9]+)?$")
RELEASE_TRACKED_PATHS = {
    "target/linux/octeon/base-files/etc/board.d/01_network",
    "target/linux/octeon/base-files/lib/preinit/01_sysinfo",
    "target/linux/octeon/base-files/lib/upgrade/platform.sh",
    "target/linux/octeon/image/Makefile",
}
RELEASE_OWNED_UNTRACKED = (
    "target/linux/octeon/files/arch/mips/boot/dts/cavium-octeon/cn5010_cisco_rv220w.dts",
)
RELEASE_OWNED_PATCH_GLOBS = (
    "target/linux/generic/hack-6.12/900-rv220w-*.patch",
    "target/linux/octeon/patches-6.12/900-rv220w-*.patch",
    "package/kernel/mac80211/patches/brcm/900-rv220w-*.patch",
)


def git_lines(tree: pathlib.Path, *args: str) -> list[str]:
    out = subprocess.check_output(["git", "-C", str(tree), *args], text=True)
    return [line for line in out.splitlines() if line]


def reset_previous_release_tree(tree: pathlib.Path, marker: pathlib.Path, marker_version: str) -> None:
    """Reset only a source tree explicitly owned by a prior RV220W release.

    Preserve OpenWrt downloads/build caches and feeds.  Refuse to reset when
    tracked user/source modifications exist outside the small release-owned
    integration surface.
    """
    if not RELEASE_VERSION_RE.fullmatch(marker_version):
        raise SystemExit(
            f"refusing to migrate source tree with unknown RV220W owner marker {marker_version!r}"
        )

    changed = set(git_lines(tree, "diff", "--name-only", "HEAD", "--"))
    unexpected = sorted(changed - RELEASE_TRACKED_PATHS)
    if unexpected:
        detail = "\n  ".join(unexpected)
        raise SystemExit(
            "prior RV220W release tree also contains tracked modifications outside the "
            f"release-owned integration surface; refusing automatic reset:\n  {detail}\n"
            "Save/revert those edits or run make distclean for a pristine checkout."
        )

    print(
        f"[rv220w] Migrating cached OpenWrt worktree from RV220W {marker_version} to {VERSION}; "
        "preserving downloads/build caches."
    )
    run(["git", "reset", "--hard", OPENWRT_REF], cwd=tree, quiet=True)

    for rel in RELEASE_OWNED_UNTRACKED:
        (tree / rel).unlink(missing_ok=True)
    for pattern in RELEASE_OWNED_PATCH_GLOBS:
        for path in tree.glob(pattern):
            if path.is_file():
                path.unlink()
    marker.unlink(missing_ok=True)


def run(cmd: list[str], cwd: pathlib.Path | None = None, *, stdin=None, quiet: bool = False) -> None:
    if not quiet:
        print("+", " ".join(map(str, cmd)))
    subprocess.run(list(map(str, cmd)), cwd=cwd, stdin=stdin, check=True,
                   stdout=subprocess.DEVNULL if quiet else None,
                   stderr=subprocess.DEVNULL if quiet else None)


def same(a: pathlib.Path, b: pathlib.Path) -> bool:
    return a.is_file() and b.is_file() and a.read_bytes() == b.read_bytes()


def copy_exact(src: pathlib.Path, dst: pathlib.Path) -> None:
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dst)


def patch_dry_run(tree: pathlib.Path, patch: pathlib.Path, *, reverse: bool) -> bool:
    cmd = ["patch", "-p1", "--batch", "--dry-run"]
    if reverse:
        cmd.append("-R")
    try:
        with patch.open("rb") as fh:
            subprocess.run(cmd, cwd=tree, stdin=fh, check=True,
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return True
    except subprocess.CalledProcessError:
        return False


def apply_base_patch(tree: pathlib.Path, patch: pathlib.Path, marker: pathlib.Path, verify: bool) -> None:
    marker_version = marker.read_text().strip() if marker.is_file() else None

    if verify:
        if marker_version != VERSION:
            raise SystemExit(
                f"release marker mismatch: {marker_version!r}; expected {VERSION!r}. "
                "Use a fresh source tree or rerun make sources after make distclean."
            )
        if not patch_dry_run(tree, patch, reverse=True):
            raise SystemExit("RV220W base platform patch is not present exactly as released")
        return

    if marker_version is not None:
        if marker_version != VERSION:
            reset_previous_release_tree(tree, marker, marker_version)
            marker_version = None
        else:
            if not patch_dry_run(tree, patch, reverse=True):
                raise SystemExit("marked RV220W source tree no longer matches the released base platform patch")
            return

    # An unmarked tree must be pristine at the release-owned integration points.
    image_mk = tree / "target/linux/octeon/image/Makefile"
    network = tree / "target/linux/octeon/base-files/etc/board.d/01_network"
    if (image_mk.is_file() and "cisco_rv220w" in image_mk.read_text(errors="ignore")) or (
        network.is_file() and "cisco,rv220w" in network.read_text(errors="ignore")
    ):
        raise SystemExit(
            "unmarked OpenWrt tree already contains RV220W integration; refusing to merge with an unknown/old patchset. "
            "Use make distclean for a fresh pinned checkout."
        )
    if not patch_dry_run(tree, patch, reverse=False):
        raise SystemExit("RV220W base platform patch does not apply cleanly to the pinned OpenWrt source")
    with patch.open("rb") as fh:
        print("+ patch -p1 --batch <", patch)
        subprocess.run(["patch", "-p1", "--batch"], cwd=tree, stdin=fh, check=True)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("openwrt", type=pathlib.Path)
    ap.add_argument("--verify", action="store_true")
    ns = ap.parse_args()

    tree = ns.openwrt.resolve()
    root = ROOT
    if not (tree / ".git").is_dir():
        raise SystemExit(f"not an OpenWrt git checkout: {tree}")

    ref = subprocess.check_output(
        ["git", "-C", str(tree), "describe", "--tags", "--exact-match", "HEAD"],
        text=True,
        stderr=subprocess.DEVNULL,
    ).strip()
    if ref != OPENWRT_REF:
        raise SystemExit(f"expected OpenWrt {OPENWRT_REF}, found {ref!r}")

    marker = tree / ".rv220w-release"
    base_patch = root / "patches/openwrt/0001-rv220w-platform.patch"
    apply_base_patch(tree, base_patch, marker, ns.verify)

    mappings: list[tuple[pathlib.Path, pathlib.Path]] = []
    for p in sorted((root / "patches/kernel/generic").glob("*.patch")):
        mappings.append((p, tree / "target/linux/generic/hack-6.12" / p.name))
    for p in sorted((root / "patches/kernel/octeon").glob("*.patch")):
        mappings.append((p, tree / "target/linux/octeon/patches-6.12" / p.name))
    for p in sorted((root / "patches/mac80211/brcm").glob("*.patch")):
        mappings.append((p, tree / "package/kernel/mac80211/patches/brcm" / p.name))

    for src, dst in mappings:
        if ns.verify:
            if not same(src, dst):
                raise SystemExit(f"release patch missing/different: {dst}")
        else:
            copy_exact(src, dst)

    dts_src = root / "platform/cn5010_cisco_rv220w.dts"
    dts_dst = tree / "target/linux/octeon/files/arch/mips/boot/dts/cavium-octeon/cn5010_cisco_rv220w.dts"
    plat_src = root / "platform/platform.sh"
    plat_dst = tree / "target/linux/octeon/base-files/lib/upgrade/platform.sh"

    if ns.verify:
        for src, dst in ((dts_src, dts_dst), (plat_src, plat_dst)):
            if not same(src, dst):
                raise SystemExit(f"release platform file missing/different: {dst}")
    else:
        copy_exact(dts_src, dts_dst)
        copy_exact(plat_src, plat_dst)
        marker.write_text(VERSION + "\n")

    # Required release invariants.
    dts = dts_dst.read_text()
    for tok in (
        'label = "rv220w:green:power";',
        'label = "rv220w:red:diag";',
        'label = "rv220w:green:wlan";',
        'label = "rv220w:green:dmz";',
        'label = "wan";',
        'label = "lan4";',
    ):
        if tok not in dts:
            raise SystemExit(f"missing DTS invariant: {tok}")
    if "phy0tpt" in dts:
        raise SystemExit("release DTS must not encode a b43/mac80211 trigger for the mainboard WLAN LED")

    image_mk = (tree / "target/linux/octeon/image/Makefile").read_text()
    if "loglevel=8" in image_mk or "ignore_loglevel" in image_mk:
        raise SystemExit("release kernel command line still forces debug logging")
    board_d = (tree / "target/linux/octeon/base-files/etc/board.d/01_network").read_text()
    if 'ucidef_set_interfaces_lan_wan "lan1 lan2 lan3 lan4" "wan"' not in board_d:
        raise SystemExit("release board.d does not define standard DSA LAN/WAN interfaces")

    print(f"RV220W release platform {VERSION}: PASS")


if __name__ == "__main__":
    main()
