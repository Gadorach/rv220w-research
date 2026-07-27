#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse \
    'p/port=' \
    'e/eap-port=' \
    'u/uart-baud=' \
    't/timeout=' \
    'b/bus=' \
    'l/log-dir=' \
    'f/force-upload' -- $argv; or exit 2

set -l action show
if test (count $argv) -ge 1
    set action $argv[1]
end
contains -- "$action" show show-all set-basic set-simplified restore; or \
    rv_die 'Usage: ./rv220w.fish b53-eap {show|show-all|set-basic|set-simplified|restore} [--eap-port 0]'

set -l eap_port 0
set -q _flag_eap_port; and set eap_port $_flag_eap_port
string match -qr '^[0-9]+$' -- "$eap_port"; or rv_die "Invalid EAP port: $eap_port"
test "$eap_port" -ge 0 -a "$eap_port" -le 8; or rv_die 'EAP port must be 0..8'
if contains -- "$action" set-basic set-simplified restore
    test "$eap_port" -le 4; or rv_die 'Write actions are restricted to external user ports 0..4'
end

set -l bus $RV220W_MDIO_BUS
set -q _flag_bus; and set bus $_flag_bus
string match -qr '^[A-Za-z0-9._:-]+$' -- "$bus"; or rv_die "Unsafe MDIO bus selector: $bus"

set -l serial_port
if set -q _flag_port
    set serial_port $_flag_port
else
    set serial_port (rv_find_serial); or rv_die 'Could not choose a serial adapter automatically; close other serial-console programs or use --port.'
end
test -e "$serial_port"; or rv_die "Serial port not found: $serial_port"

set -l baud 115200
set -q RV220W_CONSOLE_BAUD; and set baud $RV220W_CONSOLE_BAUD
set -q _flag_uart_baud; and set baud $_flag_uart_baud
string match -qr '^[0-9]+$' -- "$baud"; or rv_die "Invalid UART baud: $baud"

set -l timeout 120
set -q _flag_timeout; and set timeout $_flag_timeout
string match -qr '^[0-9]+([.][0-9]+)?$' -- "$timeout"; or rv_die "Invalid UART timeout: $timeout"

set -l log_dir "$RV220W_WORKSPACE/logs/discovery/b53"
set -q _flag_log_dir; and set log_dir (realpath -m $_flag_log_dir)
mkdir -p "$log_dir"; or rv_die "Could not create log directory: $log_dir"
set -l stamp (date -u +%Y%m%dT%H%M%SZ)
set -l transcript "$log_dir/rv220w-b53-eap-$action-p$eap_port-$stamp.serial.log"
set -l helper "$RV220W_TOOLKIT_ROOT/openwrt/files-dsa-dual/usr/sbin/rv220w-b53-eap-mode"
test -f "$helper"; or rv_die "Missing packaged EAP helper: $helper"

set -l command \
    python3 "$RV220W_TOOLKIT_ROOT/scripts/host/rv220w_uart_b53_eap.py" \
    "$serial_port" "$helper" "$action" "$eap_port" "$bus" \
    --baud "$baud" --timeout "$timeout" --transcript "$transcript"
set -q _flag_force_upload; and set -a command --force-upload

rv_info "BCM53115 EAP action over UART: action=$action port=$eap_port bus=$bus"
command $command
or rv_die 'UART EAP operation failed. Ensure the OpenWrt shell is active and no other process holds the serial adapter.'
