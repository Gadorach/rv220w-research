# Shared helpers for the public RV220W release Makefile helpers.
set -g RV220W_TOOLKIT_ROOT (realpath (dirname (status --current-filename))/../..)

set -q RV220W_BOX; or set -gx RV220W_BOX rv220w-openwrt-release
set -q RV220W_BOX_IMAGE; or set -gx RV220W_BOX_IMAGE docker.io/library/ubuntu:24.04
set -q RV220W_WORKSPACE; or set -gx RV220W_WORKSPACE "$RV220W_TOOLKIT_ROOT/build"
set -q RV220W_OPENWRT_REF; or set -gx RV220W_OPENWRT_REF v25.12.5
set -q RV220W_OPENWRT_URL; or set -gx RV220W_OPENWRT_URL https://github.com/openwrt/openwrt.git

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

function rv_box_enter
    rv_require distrobox
    distrobox enter --name "$RV220W_BOX" --no-tty -- $argv
end

function rv_box_exists
    command -q podman; or return 1
    podman container exists "$RV220W_BOX" >/dev/null 2>&1
end

function rv_box_runtime_summary
    rv_box_exists; or return 1
    podman inspect --format '{{.Name}}|{{.State.Status}}|{{.ImageName}}' "$RV220W_BOX" 2>/dev/null
end

function rv_remove_box_runtime
    rv_require podman timeout
    rv_box_exists; or return 0
    set -l summary (rv_box_runtime_summary)
    test -n "$summary"; or set summary "$RV220W_BOX"
    rv_info "Removing conflicting container: $summary"
    command timeout --foreground 30s podman rm --force --time 3 --ignore "$RV220W_BOX"
    set -l remove_status $status
    switch $remove_status
        case 0
        case 124 137
            rv_die "Timed out removing $RV220W_BOX. Inspect it with: podman inspect $RV220W_BOX"
        case '*'
            rv_die "Podman failed to remove $RV220W_BOX (exit $remove_status)"
    end
    rv_box_exists; and rv_die "Container $RV220W_BOX still exists after removal"
end

function rv_box_identity
    rv_box_exists; or return 1
    rv_box_enter sh -lc '
        test -r /etc/os-release || { printf "unknown|unknown|missing /etc/os-release\n"; exit 0; }
        . /etc/os-release
        printf "%s|%s|%s\n" "${ID:-unknown}" "${VERSION_ID:-unknown}" "${PRETTY_NAME:-unknown}"
    ' 2>/dev/null
end

function rv_box_is_compatible
    rv_box_exists; or return 1
    rv_box_enter sh -lc '
        test -r /etc/os-release || exit 1
        . /etc/os-release
        test "${ID:-}" = ubuntu || exit 1
        case "${VERSION_ID:-}" in 24.04|24.04.*) ;; *) exit 1 ;; esac
        command -v apt-get >/dev/null 2>&1
    ' >/dev/null 2>&1
end

function rv_box_is_provisioned
    rv_box_is_compatible; or return 1
    rv_box_enter sh -lc '
        for command_name in bash git gcc g++ make perl python3 rsync file setsid patch dtc unsquashfs; do
            command -v "$command_name" >/dev/null 2>&1 || exit 1
        done
    ' >/dev/null 2>&1
end

function rv_require_build_box
    rv_box_exists; or rv_die "Distrobox $RV220W_BOX does not exist; run: make setup"
    if not rv_box_is_compatible
        set -l identity (rv_box_identity)
        test -n "$identity"; or set identity unknown
        rv_die "Distrobox $RV220W_BOX is incompatible ($identity). Run: make recreate-box"
    end
    rv_box_is_provisioned; or rv_die "Distrobox $RV220W_BOX is not provisioned; run: make setup"
end
