# Shared helpers for the RV220W fish entry points.
set -g RV220W_TOOLKIT_ROOT (realpath (dirname (status --current-filename))/../..)
set -g RV220W_REPO_ROOT (realpath "$RV220W_TOOLKIT_ROOT/..")
set -g RV220W_UART_DUMPER "$RV220W_REPO_ROOT/tools/uart/dump_uboot_flash_uart.py"
set -g RV220W_FLASH_EXTRACTOR "$RV220W_REPO_ROOT/tools/firmware/extract_rv220w_flash.py"

if test -f "$RV220W_TOOLKIT_ROOT/config/toolkit.env.fish"
    source "$RV220W_TOOLKIT_ROOT/config/toolkit.env.fish"
else if test -f "$RV220W_TOOLKIT_ROOT/config/toolkit.env.fish.example"
    source "$RV220W_TOOLKIT_ROOT/config/toolkit.env.fish.example"
end

set -q RV220W_BOX; or set -gx RV220W_BOX rv220w-openwrt
set -q RV220W_BOX_IMAGE; or set -gx RV220W_BOX_IMAGE docker.io/library/ubuntu:24.04
set -q RV220W_WORKSPACE; or set -gx RV220W_WORKSPACE "$HOME/src/rv220w-openwrt"
set -q RV220W_OPENWRT_REF; or set -gx RV220W_OPENWRT_REF v25.12.5
set -q RV220W_OPENWRT_URL; or set -gx RV220W_OPENWRT_URL https://github.com/openwrt/openwrt.git
set -q RV220W_LINUX_REF; or set -gx RV220W_LINUX_REF linux-6.12.y
set -q RV220W_LINUX_URL; or set -gx RV220W_LINUX_URL https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
set -q RV220W_MERAKI_BUILDER_REF; or set -gx RV220W_MERAKI_BUILDER_REF ms42p-dev
set -q RV220W_MERAKI_BUILDER_URL; or set -gx RV220W_MERAKI_BUILDER_URL https://github.com/Gadorach/meraki-builder.git
set -q RV220W_UART_BAUD; or set -gx RV220W_UART_BAUD 460800
set -q RV220W_TFTP_LOADADDR; or set -gx RV220W_TFTP_LOADADDR 0x05500000
set -q RV220W_TFTP_TEST_SUBNET; or set -gx RV220W_TFTP_TEST_SUBNET 192.168.240.0/24

function rv_info
    printf '\e[1;34m[rv220w]\e[0m %s\n' "$argv"
end

function rv_warn
    printf '\e[1;33m[rv220w:warning]\e[0m %s\n' "$argv" >&2
end

function rv_die
    printf '\e[1;31m[rv220w:error]\e[0m %s\n' "$argv" >&2
    exit 1
end

function rv_require
    for cmd in $argv
        command -q $cmd; or rv_die "Required command not found: $cmd"
    end
end

function rv_box_exists
    command -q distrobox; or return 1
    distrobox enter "$RV220W_BOX" -- true >/dev/null 2>&1
end

function rv_box_bash
    rv_require distrobox
    distrobox enter "$RV220W_BOX" -- bash -lc "$argv[1]"
end

function rv_find_serial
    set -l candidates /dev/serial/by-id/*FTDI* /dev/serial/by-id/*UART* /dev/ttyUSB*
    set -l found
    for path in $candidates
        if test -e "$path"
            set -a found "$path"
        end
    end
    set found (printf '%s\n' $found | sort -u)
    if test (count $found) -eq 1
        echo $found[1]
        return 0
    end
    if test (count $found) -eq 0
        return 1
    end
    rv_warn "Multiple serial devices found; pass --port explicitly:"
    printf '  %s\n' $found >&2
    return 2
end

function rv_timestamp
    date -u +%Y%m%dT%H%M%SZ
end
