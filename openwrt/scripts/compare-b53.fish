#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'o/output=' -- $argv; or exit 2
if test (count $argv) -ne 2
    printf '%s\n' 'Usage: ./rv220w.fish compare-b53 SNAPSHOT_A SNAPSHOT_B [--output FILE]' >&2
    exit 2
end
set -l a (realpath -m $argv[1])
set -l b (realpath -m $argv[2])
test -f "$a"; or rv_die "Snapshot not found: $a"
test -f "$b"; or rv_die "Snapshot not found: $b"
set -l cmd python3 "$RV220W_TOOLKIT_ROOT/scripts/host/compare_rv220w_b53_snapshots.py" "$a" "$b"
if set -q _flag_output
    set -a cmd --output (realpath -m $_flag_output)
end
command $cmd
or rv_die 'B53 snapshot comparison failed.'
