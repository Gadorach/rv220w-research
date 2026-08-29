#!/usr/bin/env fish
source (dirname (status --current-filename))/../lib/common.fish
set mode all
if test (count $argv) -ge 1
    set mode $argv[1]
end
rv_require_build_box
set -lx RV220W_RELEASE_ROOT "$RV220W_TOOLKIT_ROOT"
rv_box_enter env RV220W_RELEASE_ROOT="$RV220W_TOOLKIT_ROOT" RV220W_WORKSPACE="$RV220W_WORKSPACE" RV220W_JOBS="" bash "$RV220W_TOOLKIT_ROOT/scripts/release/build.sh" "$mode"
or rv_die "Release build failed: $mode"
