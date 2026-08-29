#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'r/recreate' 'R/remove-only' 'n/dry-run' -- $argv; or exit 2

rv_require distrobox podman timeout

set -l create_needed 0
set -l recreate_requested 0
set -q _flag_recreate; and set recreate_requested 1
set -q _flag_remove_only; and set recreate_requested 1

if test $recreate_requested -eq 1
    rv_warn "Recreating Distrobox $RV220W_BOX"
    if set -q _flag_dry_run
        echo "timeout --foreground 30s podman rm --force --time 3 --ignore $RV220W_BOX"
    else
        rv_remove_box_runtime
    end
    if set -q _flag_remove_only
        rv_info 'Removal-only request complete.'
        exit 0
    end
    set create_needed 1
else if not rv_box_exists
    set create_needed 1
else if not rv_box_is_compatible
    set -l identity (rv_box_identity)
    test -n "$identity"; or set identity unknown
    rv_warn "Existing container $RV220W_BOX is incompatible: $identity"
    set -l runtime (rv_box_runtime_summary)
    test -n "$runtime"; and rv_warn "Runtime object: $runtime"
    rv_die "This toolkit requires Ubuntu 24.04 with apt-get. Run: make recreate-box"
end

if test $create_needed -eq 1
    rv_info "Creating $RV220W_BOX from $RV220W_BOX_IMAGE"
    rv_info 'The image pull may take several minutes on first use; Distrobox/Podman progress will remain visible.'
    if set -q _flag_dry_run
        echo "distrobox create --yes --name $RV220W_BOX --image $RV220W_BOX_IMAGE"
    else
        distrobox create --yes --name "$RV220W_BOX" --image "$RV220W_BOX_IMAGE"
        or rv_die 'Distrobox creation failed'
    end
end

if not set -q _flag_dry_run
    rv_box_is_compatible
    or begin
        set -l identity (rv_box_identity)
        test -n "$identity"; or set identity unknown
        rv_die "Created/reused box has an unexpected base system ($identity). Check RV220W_BOX_IMAGE and run make recreate-box"
    end
end

set -l provision "$RV220W_TOOLKIT_ROOT/scripts/inner/provision-openwrt-box.sh"
test -x "$provision"; or rv_die "Provisioning helper is missing or not executable: $provision"

rv_info 'Provisioning OpenWrt build dependencies in the shared-home Ubuntu container.'
if set -q _flag_dry_run
    echo "distrobox enter --name $RV220W_BOX --no-tty -- bash $provision"
    exit 0
end

mkdir -p "$RV220W_WORKSPACE/logs"
set -l provision_log "$RV220W_WORKSPACE/logs/distrobox-provision.log"
rv_info "Provision log: $provision_log"
rv_box_enter bash "$provision" 2>&1 | tee "$provision_log"
set -l provision_pipeline $pipestatus
set -l provision_status $provision_pipeline[1]
if test "$provision_status" -ne 0
    rv_warn "Distrobox provisioning command exited with status $provision_status"
    rv_die "Distrobox provisioning failed; inspect: $provision_log"
end

rv_box_is_provisioned
or rv_die "Provisioning command completed, but required build commands are still missing. Inspect: $provision_log"

set -l identity (rv_box_identity)
rv_info "Distrobox is ready: $identity"
