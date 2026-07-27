#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse \
    'p/port=' \
    'u/uart-baud=' \
    't/timeout=' \
    'r/router-ip=' \
    'o/output-dir=' \
    'b/bus=' \
    'S/ssh' \
    'f/force-upload' -- $argv; or exit 2

set -l label identity
if test (count $argv) -ge 1
    set label $argv[1]
end
set label (string replace -ra '[^A-Za-z0-9._-]' '_' -- "$label")

set -l bus $RV220W_MDIO_BUS
set -q _flag_bus; and set bus $_flag_bus
set -l output_dir "$RV220W_WORKSPACE/logs/discovery/mdio"
set -q _flag_output_dir; and set output_dir (realpath -m $_flag_output_dir)
set -l fallback "$RV220W_TOOLKIT_ROOT/openwrt/files-discovery/usr/sbin/rv220w-mdio-scan"

string match -qr '^[A-Za-z0-9._:-]+$' -- "$bus"; or rv_die "Unsafe MDIO bus selector: $bus"
test -f "$fallback"; or rv_die "Missing packaged MDIO scan script: $fallback"
mkdir -p "$output_dir"; or rv_die "Could not create output directory: $output_dir"

# UART is the default because NONE and WAN measurements intentionally may not
# provide a routable Ethernet path. SSH remains available only as an explicit
# compatibility transport for already-connected LAN measurements.
if not set -q _flag_ssh
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
    string match -qr '^[0-9]+$' -- "$baud"; or rv_die "Invalid UART baud: $baud"

    set -l timeout 120
    set -q _flag_timeout; and set timeout $_flag_timeout
    string match -qr '^[0-9]+([.][0-9]+)?$' -- "$timeout"; or rv_die "Invalid UART timeout: $timeout"

    set -l command \
        python3 "$RV220W_TOOLKIT_ROOT/scripts/host/rv220w_uart_collect_mdio.py" \
        "$port" "$fallback" "$label" "$bus" \
        --baud "$baud" \
        --timeout "$timeout" \
        --output-dir "$output_dir"
    set -q _flag_force_upload; and set -a command --force-upload

    rv_info "Collecting read-only MDIO report over UART: port=$port baud=$baud label=$label"
    command $command
    or rv_die 'UART MDIO collection failed. Ensure no other process has the serial adapter open and that the OpenWrt shell is active.'
    exit 0
end

# Explicit SSH compatibility mode. This cannot be used for NONE or for any
# physical port that does not route to 192.168.240.2.
set -l router_ip $RV220W_TFTP_DEVICE_IP
set -q _flag_router_ip; and set router_ip $_flag_router_ip
rv_require ssh
set -l ssh_options \
    -o BatchMode=yes \
    -o ConnectTimeout=5 \
    -o StrictHostKeyChecking=no \
    -o UserKnownHostsFile=/dev/null \
    -o LogLevel=ERROR
set -l target "root@$router_ip"
set -l remote_script /usr/sbin/rv220w-mdio-scan

if not ssh $ssh_options "$target" "test -x $remote_script" >/dev/null 2>&1
    rv_warn 'MDIO scan script is not installed on the target; streaming the packaged read-only script to /tmp over SSH.'
    command cat "$fallback" | ssh $ssh_options "$target" \
        'umask 077; cat > /tmp/rv220w-mdio-scan && chmod 0755 /tmp/rv220w-mdio-scan'
    set -l transfer_status $pipestatus
    if test $transfer_status[1] -ne 0 -o $transfer_status[2] -ne 0
        rv_die 'Could not stream MDIO scan script to the target over SSH'
    end
    set remote_script /tmp/rv220w-mdio-scan
end

set -l remote_output (ssh $ssh_options "$target" "$remote_script '$label' '$bus'" | string trim | tail -n 1)
test -n "$remote_output"; or rv_die 'Target did not return an MDIO output path'
string match -qr '^/tmp/rv220w-mdio-[A-Za-z0-9._-]+\.txt$' -- "$remote_output"; or rv_die "Unexpected target output path: $remote_output"

set -l local_output "$output_dir/"(basename "$remote_output")
set -l local_partial "$local_output.partial.$fish_pid"
command rm -f "$local_partial"
ssh $ssh_options "$target" "cat '$remote_output'" > "$local_partial"; or begin
    command rm -f "$local_partial"
    rv_die 'Could not retrieve MDIO scan over SSH'
end
test -s "$local_partial"; or begin
    command rm -f "$local_partial"
    rv_die 'Retrieved MDIO scan was empty'
end
command mv -f "$local_partial" "$local_output"; or begin
    command rm -f "$local_partial"
    rv_die "Could not finalize MDIO scan: $local_output"
end
rv_info "Saved $local_output"
