#!/usr/bin/env fish
source (dirname (status --current-filename))/../lib/common.fish
rv_require_build_box
mkdir -p "$RV220W_WORKSPACE"
set -lx RV220W_RELEASE_ROOT "$RV220W_TOOLKIT_ROOT"
rv_box_enter env RV220W_RELEASE_ROOT="$RV220W_TOOLKIT_ROOT" RV220W_WORKSPACE="$RV220W_WORKSPACE" RV220W_OPENWRT_URL="$RV220W_OPENWRT_URL" RV220W_OPENWRT_REF="$RV220W_OPENWRT_REF" bash "$RV220W_TOOLKIT_ROOT/scripts/release/prepare-sources.sh"
or rv_die 'Release source preparation failed'
