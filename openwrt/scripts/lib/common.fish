# Shared helpers for the RV220W fish entry points.
set -g RV220W_TOOLKIT_ROOT (realpath (dirname (status --current-filename))/../..)

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
set -q RV220W_LINUX_CROSS_COMPILE; or set -gx RV220W_LINUX_CROSS_COMPILE mips64-linux-gnuabi64-
set -q RV220W_MERAKI_BUILDER_REF; or set -gx RV220W_MERAKI_BUILDER_REF ms42p-dev
set -q RV220W_MERAKI_BUILDER_URL; or set -gx RV220W_MERAKI_BUILDER_URL https://github.com/Gadorach/meraki-builder.git
set -q RV220W_UART_BAUD; or set -gx RV220W_UART_BAUD 460800
set -q RV220W_CONSOLE_BAUD; or set -gx RV220W_CONSOLE_BAUD 115200
set -q RV220W_TFTP_LOADADDR; or set -gx RV220W_TFTP_LOADADDR 0x05500000
set -q RV220W_TFTP_TEST_SUBNET; or set -gx RV220W_TFTP_TEST_SUBNET 192.168.240.0/24
set -q RV220W_TFTP_INTERFACE; or set -gx RV220W_TFTP_INTERFACE enp0s31f6
set -q RV220W_TFTP_SERVER_IP; or set -gx RV220W_TFTP_SERVER_IP 192.168.240.1
set -q RV220W_TFTP_DEVICE_IP; or set -gx RV220W_TFTP_DEVICE_IP 192.168.240.2
set -q RV220W_TFTP_ETHACT; or set -gx RV220W_TFTP_ETHACT octeth0
set -q RV220W_MDIO_BUS; or set -gx RV220W_MDIO_BUS 8001180000001800
set -q RV220W_TFTP_CONFIGURE_INTERFACE; or set -gx RV220W_TFTP_CONFIGURE_INTERFACE 1

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

# Always use the explicit Distrobox --name form in scripts.  The positional
# form is convenient interactively, but explicit options make command parsing
# and diagnostics deterministic across Distrobox releases.
function rv_box_enter
    rv_require distrobox
    distrobox enter --name "$RV220W_BOX" --no-tty -- $argv
end

function rv_box_enter_tty
    rv_require distrobox
    distrobox enter --name "$RV220W_BOX" -- $argv
end

# Test the underlying Podman object directly.  Using `distrobox enter` as an
# existence probe starts the container and can blur a Distrobox/Toolbx name
# collision.  The toolkit is configured for rootless Podman on CachyOS.
function rv_box_exists
    command -q podman; or return 1
    podman container exists "$RV220W_BOX" >/dev/null 2>&1
end

function rv_box_runtime_summary
    rv_box_exists; or return 1
    podman inspect --format '{{.Name}}|{{.State.Status}}|{{.ImageName}}' "$RV220W_BOX" 2>/dev/null
end

# Remove a conflicting runtime container without an interactive prompt.  The
# v1.0.2 path called `distrobox stop` without `--yes` and then hid its prompt,
# which looked like a rebuild hang.  Podman's force removal has an explicit
# stop grace period, and GNU timeout bounds the entire operation.
function rv_remove_box_runtime
    rv_require podman timeout
    if not rv_box_exists
        return 0
    end

    set -l summary (rv_box_runtime_summary)
    test -n "$summary"; or set summary "$RV220W_BOX"
    rv_info "Removing conflicting container: $summary"
    rv_info 'Removal is bounded to 30 seconds (3-second container stop grace period).'

    command timeout --foreground 30s podman rm --force --time 3 --ignore "$RV220W_BOX"
    set -l remove_status $status
    switch $remove_status
        case 0
            # Continue below and verify disappearance.
        case 124 137
            rv_die "Timed out removing $RV220W_BOX. Inspect it with: podman inspect $RV220W_BOX"
        case '*'
            rv_die "Podman failed to remove $RV220W_BOX (exit $remove_status)"
    end

    if rv_box_exists
        rv_die "Container $RV220W_BOX still exists after Podman reported successful removal"
    end
    rv_info "Removed container $RV220W_BOX"
end

function rv_box_identity
    rv_box_exists; or return 1
    rv_box_enter sh -lc '
        if test -r /etc/os-release; then
            . /etc/os-release
            printf "%s|%s|%s\n" "${ID:-unknown}" "${VERSION_ID:-unknown}" "${PRETTY_NAME:-unknown}"
        else
            printf "unknown|unknown|missing /etc/os-release\n"
        fi
    ' 2>/dev/null
end

function rv_box_is_compatible
    rv_box_exists; or return 1
    rv_box_enter sh -lc '
        test -r /etc/os-release || exit 1
        . /etc/os-release
        test "${ID:-}" = ubuntu || exit 1
        case "${VERSION_ID:-}" in
            24.04|24.04.*) ;;
            *) exit 1 ;;
        esac
        command -v apt-get >/dev/null 2>&1
    ' >/dev/null 2>&1
end

function rv_box_is_provisioned
    rv_box_is_compatible; or return 1
    rv_box_enter sh -lc '
        for command_name in bash git gcc g++ make perl python3 rsync file setsid flock; do
            command -v "$command_name" >/dev/null 2>&1 || exit 1
        done
        perl -MFindBin -e 1 >/dev/null 2>&1 || exit 1
    ' >/dev/null 2>&1
end

# The external MIPS64 compiler is only required by the standalone upstream
# Linux reference workflow. OpenWrt creates and uses its own target toolchain,
# so absence of this optional compiler must not mark the main build box broken.
function rv_box_has_reference_cross
    rv_box_is_compatible; or return 1
    rv_box_enter sh -lc 'command -v mips64-linux-gnuabi64-gcc >/dev/null 2>&1' >/dev/null 2>&1
end

function rv_require_build_box
    rv_box_exists; or rv_die "Distrobox $RV220W_BOX does not exist; run ./rv220w.fish setup-box"
    if not rv_box_is_compatible
        set -l identity (rv_box_identity)
        test -n "$identity"; or set identity unknown
        rv_die "Distrobox $RV220W_BOX is not Ubuntu 24.04 with apt-get ($identity). Run ./rv220w.fish setup-box --recreate"
    end
    rv_box_is_provisioned; or rv_die "Distrobox $RV220W_BOX is not provisioned; run ./rv220w.fish setup-box"
end

function rv_box_bash
    rv_box_enter bash -lc "$argv[1]"
end

function rv_box_bash_tty
    rv_box_enter_tty bash -lc "$argv[1]"
end

function rv_find_serial
    set -l candidates /dev/serial/by-id/*FTDI* /dev/serial/by-id/*UART* /dev/ttyUSB*
    set -l found
    set -l resolved_seen
    for path in $candidates
        if not test -e "$path"
            continue
        end
        set -l resolved (realpath "$path" 2>/dev/null)
        test -n "$resolved"; or set resolved "$path"
        if contains -- "$resolved" $resolved_seen
            continue
        end
        set -a resolved_seen "$resolved"
        set -a found "$path"
    end
    if test (count $found) -eq 1
        echo $found[1]
        return 0
    end
    if test (count $found) -eq 0
        return 1
    end
    rv_warn "Multiple physical serial adapters found; pass --port explicitly:"
    printf '  %s\n' $found >&2
    return 2
end

function rv_timestamp
    date -u +%Y%m%dT%H%M%SZ
end
