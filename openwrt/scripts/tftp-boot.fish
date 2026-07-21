#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse \
    'p/port=' \
    'i/interface=' \
    's/server-ip=' \
    'd/device-ip=' \
    'a/configure-interface' \
    'l/load-address=' \
    'q/test-subnet=' \
    'e/ethact=+' \
    'g/bootargs=' \
    'b/serial-baud=' \
    'n/no-boot' \
    'r/already-at-prompt' \
    'S/server-only' \
    'k/keep-interface-address' \
    'T/tftp-timeout=' \
    'I/interrupt-timeout=' \
    't/boot-timeout=' \
    'x/dry-run' -- $argv; or exit 2
rv_require python3 ip dnsmasq
set -l image
if test (count $argv) -ge 1
    set image (realpath $argv[1]); or rv_die 'Image path is invalid'
else
    set -l candidates \
        "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-squashfs-live.elf" \
        "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-generic-initramfs.elf"
    for candidate in $candidates
        if test -f "$candidate"
            set image "$candidate"
            break
        end
    end
end
test -n "$image"; and test -f "$image"; or rv_die 'No image supplied and no built live image was found'
set -l port
if set -q _flag_port
    set port $_flag_port
else
    set port (rv_find_serial); or rv_die 'Could not choose a serial adapter automatically; use --port'
end
set -l load_address $RV220W_TFTP_LOADADDR
set -q _flag_load_address; and set load_address $_flag_load_address
set -l test_subnet $RV220W_TFTP_TEST_SUBNET
set -q _flag_test_subnet; and set test_subnet $_flag_test_subnet
set -l command python3 "$RV220W_TOOLKIT_ROOT/scripts/host/rv220w_tftp_boot.py" "$port" "$image" \
    --log-dir "$RV220W_WORKSPACE/logs" \
    --load-address "$load_address" \
    --test-subnet "$test_subnet"
set -q _flag_interface; and set -a command --interface $_flag_interface
set -q _flag_server_ip; and set -a command --server-ip $_flag_server_ip
set -q _flag_device_ip; and set -a command --device-ip $_flag_device_ip
set -q _flag_configure_interface; and set -a command --configure-interface
set -q _flag_bootargs; and set -a command --bootargs $_flag_bootargs
set -q _flag_serial_baud; and set -a command --serial-baud $_flag_serial_baud
if set -q _flag_ethact
    for item in $_flag_ethact
        set -a command --ethact $item
    end
end
set -q _flag_no_boot; and set -a command --no-boot
set -q _flag_already_at_prompt; and set -a command --already-at-prompt
set -q _flag_server_only; and set -a command --server-only
set -q _flag_keep_interface_address; and set -a command --keep-interface-address
set -q _flag_tftp_timeout; and set -a command --tftp-timeout $_flag_tftp_timeout
set -q _flag_interrupt_timeout; and set -a command --interrupt-timeout $_flag_interrupt_timeout
set -q _flag_boot_timeout; and set -a command --boot-timeout $_flag_boot_timeout
set -q _flag_dry_run; and set -a command --dry-run
rv_info 'TFTP boot is RAM-only. The helper does not issue saveenv or any flash-writing command.'
$command
