#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'p/port=' 'u/uart-baud=' 't/timeout=' 'o/output-dir=' 'f/force-upload' -- $argv; or exit 2
set -l label snapshot
if test (count $argv) -ge 1
    set label $argv[1]
end
set label (string replace -ra '[^A-Za-z0-9._-]' '_' -- "$label")
set -l output_dir "$RV220W_WORKSPACE/logs/dsa"
set -q _flag_output_dir; and set output_dir (realpath -m $_flag_output_dir)
set -l fallback "$RV220W_TOOLKIT_ROOT/openwrt/files-dsa-dual/usr/sbin/rv220w-dsa-snapshot"
test -f "$fallback"; or rv_die "Missing packaged DSA snapshot script: $fallback"
mkdir -p "$output_dir"; or rv_die "Could not create output directory: $output_dir"
rv_require python3
set -l port
if set -q _flag_port
    set port $_flag_port
else
    set port (rv_find_serial); or rv_die 'Could not choose a serial adapter automatically; close other serial-console programs or use --port'
end
test -e "$port"; or rv_die "Serial port not found: $port"
set -l baud 115200
set -q RV220W_CONSOLE_BAUD; and set baud $RV220W_CONSOLE_BAUD
set -q _flag_uart_baud; and set baud $_flag_uart_baud
set -l timeout 180
set -q _flag_timeout; and set timeout $_flag_timeout
set -l command python3 "$RV220W_TOOLKIT_ROOT/scripts/host/rv220w_uart_collect_dsa.py" "$port" "$fallback" "$label" --baud "$baud" --timeout "$timeout" --output-dir "$output_dir"
set -q _flag_force_upload; and set -a command --force-upload
rv_info "Collecting DSA validation snapshot over UART: port=$port baud=$baud label=$label"
command $command
or rv_die 'UART DSA collection failed. Ensure no other process has the serial adapter open and that the OpenWrt shell is active.'
