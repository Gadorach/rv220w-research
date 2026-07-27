#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse \
    'p/port=' \
    'P/profile=' \
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
    set -l requested_image "$argv[1]"
    test -f "$requested_image"; or rv_die "Image file not found: $requested_image"
    set image (realpath "$requested_image")
    if set -q _flag_profile; and test "$_flag_profile" = discovery
        if not string match -q '*discovery-initramfs.elf' -- (basename "$image")
            rv_warn "Discovery profile requested with an explicitly supplied non-discovery image: $image"
        end
    end
else if set -q _flag_profile
    switch $_flag_profile
        case discovery
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-discovery-initramfs.elf"
        case reference rv220w
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-initramfs.elf"
        case squashfs-live
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-squashfs-live.elf"
        case generic
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-generic-initramfs.elf"
        case dsa-lan dsa-lan-rxid
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-dsa-lan-rxid.elf"
        case dsa-lan-txid
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-dsa-lan-txid.elf"
        case dsa-lan-rgmii
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-dsa-lan-rgmii.elf"
        case dsa-dual dsa-dual-rxid
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-dsa-dual-rxid.elf"
        case rj45 rj45-full full-rj45
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-rj45-initramfs.elf"
        case dsa-dual-wan-txid
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-dsa-dual-wan-txid.elf"
        case dsa-dual-wan-rgmii
            set image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-dsa-dual-wan-rgmii.elf"
        case '*'
            rv_die "Unknown TFTP profile: $_flag_profile (expected discovery, reference, dsa-lan, dsa-dual, rj45-full, dsa-dual-wan-txid, dsa-dual-wan-rgmii, squashfs-live, or generic)"
    end
    if not test -f "$image"
        if test "$_flag_profile" = discovery
            rv_die "Built discovery image was not found: $image. Build it with: ./rv220w.fish build discovery"
        end
        rv_die "Built image for profile '$_flag_profile' was not found: $image"
    end
else
    set -l candidates \
        "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-initramfs.elf" \
        "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-rj45-initramfs.elf" \
        "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-dsa-dual-rxid.elf" \
        "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-dsa-lan-rxid.elf" \
        "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-discovery-initramfs.elf" \
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
if set -q _flag_profile
    if string match -q 'dsa-*' -- "$_flag_profile"
        rv_warn 'This RAM-only DSA image lets B53 reset and rewrite volatile switch forwarding/tagging state.'
        if string match -q 'dsa-dual*' -- "$_flag_profile"
            rv_warn 'The dual validation profile exposes WAN at 192.168.241.2 without routing, NAT, DHCP or firewall services.'
        else
            rv_warn 'WAN is intentionally unavailable in the LAN-only baseline profile.'
        end
    else if contains -- "$_flag_profile" rj45 rj45-full full-rj45
        rv_warn 'This RAM-only full-RJ45 candidate enables volatile B53/DSA configuration, LAN DHCP, WAN DHCP/DHCPv6, firewall4 and NAT.'
        rv_warn 'LAN remains 192.168.240.2/24 so the proven TFTP direct-link addressing is retained.'
    end
end
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
set -l interface "$RV220W_TFTP_INTERFACE"
set -q _flag_interface; and set interface $_flag_interface
if test -n "$interface"
    set -a command --interface "$interface"
end
set -l server_ip "$RV220W_TFTP_SERVER_IP"
set -q _flag_server_ip; and set server_ip $_flag_server_ip
if test -n "$server_ip"
    set -a command --server-ip "$server_ip"
end
set -l device_ip "$RV220W_TFTP_DEVICE_IP"
set -q _flag_device_ip; and set device_ip $_flag_device_ip
if test -n "$device_ip"
    set -a command --device-ip "$device_ip"
end
if set -q _flag_configure_interface
    set -a command --configure-interface
else if test "$RV220W_TFTP_CONFIGURE_INTERFACE" = 1
    set -a command --configure-interface
end
set -q _flag_bootargs; and set -a command --bootargs $_flag_bootargs
set -q _flag_serial_baud; and set -a command --serial-baud $_flag_serial_baud
set -l ethacts $RV220W_TFTP_ETHACT
set -q _flag_ethact; and set ethacts $_flag_ethact
for item in $ethacts
    set -a command --ethact $item
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
