#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse \
    'p/port=' \
    'u/uart-baud=' \
    't/timeout=' \
    'o/output-dir=' -- $argv; or exit 2

set -l label rj45-acceptance
if test (count $argv) -ge 1
    set label $argv[1]
end
set label (string replace -ra '[^A-Za-z0-9._-]' '_' -- "$label")
set -l command "$RV220W_TOOLKIT_ROOT/scripts/collect-dsa.fish" "$label"
set -q _flag_port; and set -a command --port $_flag_port
set -q _flag_uart_baud; and set -a command --uart-baud $_flag_uart_baud
set -q _flag_timeout; and set -a command --timeout $_flag_timeout
set -q _flag_output_dir; and set -a command --output-dir (realpath -m $_flag_output_dir)

rv_info 'Collecting the production-safe RJ45 acceptance snapshot (no raw MDIO dependency).'
command $command
or rv_die 'RJ45 acceptance collection failed.'
rv_info 'RJ45 acceptance collection completed. Raw B53 registers were intentionally not requested.'
