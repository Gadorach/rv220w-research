#!/usr/bin/env fish
argparse 'o/openwrt=' 't/toolkit=' -- $argv; or exit 2
set -l root (realpath (dirname (status --current-filename))/..)
set -l openwrt ~/src/rv220w-openwrt/sources/openwrt
set -l toolkit ~/src/rv220w-research/rv220w-research/promotion-toolkit
set -q _flag_openwrt; and set openwrt $_flag_openwrt
set -q _flag_toolkit; and set toolkit $_flag_toolkit
set openwrt (realpath "$openwrt")
set toolkit (realpath "$toolkit")
git -C "$toolkit" apply --check -R "$root/patches/promotion-toolkit-rv220w-v1.1.0.patch"; or exit 1
git -C "$openwrt" apply --check -R "$root/patches/openwrt-rv220w-platform-v1.1.0.patch"; or exit 1
git -C "$toolkit" apply -R "$root/patches/promotion-toolkit-rv220w-v1.1.0.patch"; or exit 1
git -C "$openwrt" apply -R "$root/patches/openwrt-rv220w-platform-v1.1.0.patch"; or exit 1
echo 'RV220W platform update v1.1.0 reverted.'
