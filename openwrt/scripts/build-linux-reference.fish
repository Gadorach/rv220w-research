#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'j/jobs=' 'c/clean' 'm/menuconfig' -- $argv; or exit 2

set -l jobs (nproc)
set -q _flag_jobs; and set jobs $_flag_jobs

rv_require_build_box
rv_box_has_reference_cross; or rv_die 'The optional MIPS64 reference compiler is unavailable. Re-run ./rv220w.fish setup-box after applying v1.0.4; OpenWrt builds do not require this compiler.'
test -d "$RV220W_WORKSPACE/sources/linux-reference/.git"; or rv_die 'Linux source is missing; run prepare-sources'
mkdir -p "$RV220W_WORKSPACE/artifacts/linux-reference" "$RV220W_WORKSPACE/logs"

set -l inner "$RV220W_TOOLKIT_ROOT/scripts/inner/build-linux-reference.sh"
test -x "$inner"; or rv_die "Linux build helper is missing or not executable: $inner"

set -l clean 0
set -q _flag_clean; and set clean 1
set -l menu 0
set -q _flag_menuconfig; and set menu 1

set -l box_command env \
    RV220W_JOBS="$jobs" \
    RV220W_CLEAN="$clean" \
    RV220W_MENUCONFIG="$menu" \
    RV220W_WORKSPACE="$RV220W_WORKSPACE" \
    RV220W_LINUX_CROSS_COMPILE="$RV220W_LINUX_CROSS_COMPILE" \
    bash "$inner"

rv_info "Building the standalone Linux Octeon reference tree in $RV220W_BOX with $jobs job(s)."
if test $menu -eq 1
    rv_box_enter_tty $box_command
    or rv_die 'Linux reference build failed'
else
    rv_box_enter $box_command
    or rv_die 'Linux reference build failed'
end

rv_info "Reference kernel artifacts: $RV220W_WORKSPACE/artifacts/linux-reference"
