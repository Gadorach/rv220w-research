#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'u/update' 'n/dry-run' 'R/reclone-linux' -- $argv; or exit 2

rv_require_build_box
mkdir -p "$RV220W_WORKSPACE"

set -l inner "$RV220W_TOOLKIT_ROOT/scripts/inner/prepare-sources.sh"
test -x "$inner"; or rv_die "Source-preparation helper is missing or not executable: $inner"

set -lx RV220W_UPDATE 0
set -q _flag_update; and set -lx RV220W_UPDATE 1
set -lx RV220W_RECLONE_LINUX 0
set -q _flag_reclone_linux; and set -lx RV220W_RECLONE_LINUX 1

rv_info "Preparing sources under $RV220W_WORKSPACE"
if set -q _flag_reclone_linux
    rv_warn 'The existing linux-reference checkout will be replaced with a shallow single-branch clone.'
end
if set -q _flag_dry_run
    echo "distrobox enter --name $RV220W_BOX --no-tty -- env RV220W_WORKSPACE=... bash $inner"
    exit 0
end

rv_box_enter env \
    RV220W_WORKSPACE="$RV220W_WORKSPACE" \
    RV220W_UPDATE="$RV220W_UPDATE" \
    RV220W_RECLONE_LINUX="$RV220W_RECLONE_LINUX" \
    RV220W_OPENWRT_URL="$RV220W_OPENWRT_URL" \
    RV220W_OPENWRT_REF="$RV220W_OPENWRT_REF" \
    RV220W_LINUX_URL="$RV220W_LINUX_URL" \
    RV220W_LINUX_REF="$RV220W_LINUX_REF" \
    RV220W_MERAKI_BUILDER_URL="$RV220W_MERAKI_BUILDER_URL" \
    RV220W_MERAKI_BUILDER_REF="$RV220W_MERAKI_BUILDER_REF" \
    bash "$inner"
or rv_die 'Source preparation failed'

rv_info 'Sources and feeds are ready.'
