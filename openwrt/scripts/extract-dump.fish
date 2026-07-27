#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'o/output=' 'u/allow-unknown' 'n/no-jffs2' 'f/force' -- $argv; or exit 2
if test (count $argv) -ne 1
    echo 'Usage: ./rv220w.fish extract [--output DIR] [--allow-unknown] [--no-jffs2] DUMP.bin' >&2
    exit 2
end
set -l flash (realpath $argv[1]); or rv_die 'Dump path is invalid'
test -f "$flash"; or rv_die "Dump not found: $flash"
set -l output
if set -q _flag_output
    set output (realpath -m $_flag_output)
else
    set output (string replace -r '\.bin$' '' "$flash")-extracted
end
set -l extractor "$RV220W_TOOLKIT_ROOT/scripts/host/extract_rv220w_flash.py"
set -l cmd python3 "$extractor" "$flash" "$output"
set -q _flag_allow_unknown; and set -a cmd --allow-unknown-image
set -q _flag_no_jffs2; and set -a cmd --no-jffs2
set -q _flag_force; and set -a cmd --overwrite

if command -q unsquashfs
    rv_info 'Using host unsquashfs.'
    $cmd; or rv_die 'Extraction failed'
else
    rv_require_build_box
    rv_info 'Running extraction in the Ubuntu Distrobox because SquashFS tools are not installed on the host.'
    set -l quoted
    for item in $cmd
        set -a quoted (string escape -- $item)
    end
    rv_box_bash (string join ' ' -- $quoted); or rv_die 'Extraction failed inside Distrobox'
end
rv_info "Extraction complete: $output"
