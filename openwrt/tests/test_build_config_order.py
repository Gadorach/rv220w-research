#!/usr/bin/env python3
"""Prevent automated OpenWrt targets from running before defconfig."""
from __future__ import annotations

from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TEXT = (ROOT / "scripts/inner/build-openwrt.sh").read_text(encoding="utf-8")


def function_body(name: str, next_name: str) -> str:
    start = TEXT.index(f"{name}()")
    end = TEXT.index(f"{next_name}()", start)
    return TEXT[start:end]


for name, next_name, seed in (
    ("build_dsa_lan", "build_dsa_dual", "configure openwrt-rv220w-dsa-lan-initramfs.config"),
    ("build_dsa_dual", "ensure_discovery_feed_packages", "configure openwrt-rv220w-dsa-dual-initramfs.config"),
):
    body = function_body(name, next_name)
    config_at = body.index(seed)
    active = body[config_at:]
    clean_at = active.index("run_make_noninteractive target/linux/clean")
    guard_at = active.index("require_expanded_config")
    if guard_at > clean_at:
        raise SystemExit(f"{name}: expanded-config guard follows target/linux/clean")
    prefix = body[:config_at]
    # A cleanup trap may mention target/linux/clean, but it must be conditional
    # on the expanded-config predicate so pre-defconfig failures remain safe.
    if "run_make_noninteractive target/linux/clean" in prefix and "if config_is_expanded; then" not in prefix:
        raise SystemExit(f"{name}: unconditional pre-defconfig target/linux/clean remains")

configure = function_body("configure", "download_sources")
for token in ("run_make_noninteractive defconfig", "require_expanded_config"):
    if token not in configure:
        raise SystemExit(f"configure: missing {token}")
if configure.index("run_make_noninteractive defconfig") > configure.index("require_expanded_config"):
    raise SystemExit("configure: expanded-config verification precedes defconfig")

for name, next_name in (
    ("download_sources", "build_world"),
    ("build_world", "find_initramfs"),
):
    if "require_expanded_config" not in function_body(name, next_name):
        raise SystemExit(f"{name}: missing expanded-config guard")

if 'if [[ ${RV220W_CLEAN:-0} == 1 && "$mode" != clean ]]; then' in TEXT:
    raise SystemExit("global pre-defconfig clean remains")

clean_case = TEXT[TEXT.index("  clean)"):TEXT.index("  *)", TEXT.index("  clean)"))]
if clean_case.index("configure openwrt-initramfs.config") > clean_case.index("run_make_noninteractive clean"):
    raise SystemExit("clean mode runs clean before configuring a seed")

for forbidden in ("menuconfig", "nconfig", "xconfig"):
    if forbidden not in TEXT[TEXT.index("run_make_noninteractive()") : TEXT.index("config_is_expanded()")]:
        raise SystemExit(f"noninteractive target guard does not mention {forbidden}")

print("build configuration ordering regression check passed")
