#!/usr/bin/env fish
argparse 'o/openwrt=' 't/toolkit=' -- $argv; or exit 2
set -l root (realpath (dirname (status --current-filename))/..)
set -l openwrt ~/src/rv220w-openwrt/sources/openwrt
set -l toolkit ~/src/rv220w-research/rv220w-research/promotion-toolkit
set -q _flag_openwrt; and set openwrt $_flag_openwrt
set -q _flag_toolkit; and set toolkit $_flag_toolkit
set openwrt (realpath "$openwrt")
set toolkit (realpath "$toolkit")
set -l opatch "$root/patches/openwrt-rv220w-platform-v1.1.0.patch"
set -l tpatch "$root/patches/promotion-toolkit-rv220w-v1.1.0.patch"
test -d "$openwrt/target/linux/octeon"; or begin; echo "Invalid OpenWrt tree: $openwrt" >&2; exit 1; end
test -f "$toolkit/rv220w.fish"; or begin; echo "Invalid promotion toolkit: $toolkit" >&2; exit 1; end
git -C "$openwrt" apply --check "$opatch"; or exit 1
git -C "$toolkit" apply --check "$tpatch"; or exit 1
git -C "$openwrt" apply "$opatch"; or exit 1
git -C "$toolkit" apply "$tpatch"; or begin
    echo 'Toolkit patch failed after OpenWrt patch; reverting OpenWrt change.' >&2
    git -C "$openwrt" apply -R "$opatch"
    exit 1
end
echo 'RV220W platform update v1.1.0 applied.'
echo "OpenWrt: $openwrt"
echo "Toolkit: $toolkit"
echo 'Build with: ./rv220w.fish build rv220w-initramfs'
