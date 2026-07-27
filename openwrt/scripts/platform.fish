#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish

set -l mode verify
if test (count $argv) -gt 0
    set mode $argv[1]
end

switch $mode
    case install verify
    case '*'
        echo 'Usage: ./rv220w.fish platform [install|verify]' >&2
        exit 2
end

rv_require_build_box
test -d "$RV220W_WORKSPACE/sources/openwrt/.git"; or rv_die 'OpenWrt source is missing; run prepare-sources'

set -l args "$RV220W_WORKSPACE/sources/openwrt"
if test "$mode" = verify
    set -a args --verify-only
end

rv_box_enter python3 "$RV220W_TOOLKIT_ROOT/scripts/inner/install-rv220w-platform.py" $args
or rv_die "RV220W platform $mode failed"

set -l toolkit_version (string trim < "$RV220W_TOOLKIT_ROOT/VERSION")
rv_info "RV220W OpenWrt platform integration v1.3.2 $mode complete (toolkit/discovery $toolkit_version)"
