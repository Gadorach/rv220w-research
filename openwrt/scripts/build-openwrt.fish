#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'j/jobs=' 'c/clean' 'v/verbose' -- $argv; or exit 2

if test (count $argv) -lt 1
    echo 'Usage: ./rv220w.fish build MODE [--jobs N] [--clean]' >&2
    echo 'MODE: initramfs | rv220w-initramfs | discovery | dsa-lan | dsa-dual | rj45-full | rj45-luci | nor-writer | rv220w-rj45-initramfs | rv220w-dsa-dual-rxid | rv220w-dsa-dual-wan-txid | rv220w-dsa-dual-wan-rgmii | squashfs | squashfs-live | menuconfig | kernel | clean' >&2
    exit 2
end

set -l mode $argv[1]
if test "$mode" = discovery
    set mode rv220w-discovery-initramfs
else if test "$mode" = dsa-lan
    set mode rv220w-dsa-lan-rxid
else if test "$mode" = dsa-dual
    set mode rv220w-dsa-dual-rxid
else if test "$mode" = rj45-full; or test "$mode" = rj45
    set mode rv220w-rj45-initramfs
else if test "$mode" = rj45-luci; or test "$mode" = luci
    set mode rv220w-rj45-luci-initramfs
else if test "$mode" = nor-writer
    set mode rv220w-nor-writer-initramfs
end
set -l jobs (nproc)
set -q _flag_jobs; and set jobs $_flag_jobs

rv_require_build_box
test -d "$RV220W_WORKSPACE/sources/openwrt/.git"; or rv_die 'OpenWrt source is missing; run prepare-sources'
mkdir -p "$RV220W_WORKSPACE/artifacts" "$RV220W_WORKSPACE/logs"

set -l inner "$RV220W_TOOLKIT_ROOT/scripts/inner/build-openwrt.sh"
test -x "$inner"; or rv_die "OpenWrt build helper is missing or not executable: $inner"

set -l clean 0
set -q _flag_clean; and set clean 1
set -l verbose 0
set -q _flag_verbose; and set verbose 1

set -l allow_menuconfig 0
if test "$mode" = menuconfig
    set allow_menuconfig 1
end

set -l box_command env \
    RV220W_BUILD_MODE="$mode" \
    RV220W_ALLOW_MENUCONFIG="$allow_menuconfig" \
    RV220W_JOBS="$jobs" \
    RV220W_CLEAN="$clean" \
    RV220W_VERBOSE="$verbose" \
    RV220W_TOOLKIT_ROOT="$RV220W_TOOLKIT_ROOT" \
    RV220W_WORKSPACE="$RV220W_WORKSPACE" \
    bash "$inner"

rv_info "Building OpenWrt mode '$mode' in $RV220W_BOX with $jobs job(s)."
if test "$mode" = menuconfig
    rv_box_enter_tty $box_command
    or rv_die "OpenWrt build mode '$mode' failed"
else
    rv_info 'Noninteractive guard: detached session, closed stdin, and no controlling TTY for make.'
    rv_box_enter $box_command
    or rv_die "OpenWrt build mode '$mode' failed"
end

rv_info "Build complete. Artifacts: $RV220W_WORKSPACE/artifacts"
