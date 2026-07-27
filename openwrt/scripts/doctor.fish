#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish

set -l failures 0

rv_info "Toolkit root: $RV220W_TOOLKIT_ROOT"
rv_info "Workspace:    $RV220W_WORKSPACE"
rv_info "Distrobox:    $RV220W_BOX ($RV220W_BOX_IMAGE)"

for cmd in fish git python3 sha256sum cmp gzip ip jq rsync timeout
    if command -q $cmd
        printf '  [OK]   %-16s %s\n' $cmd (command -s $cmd)
    else
        printf '  [MISS] %-16s\n' $cmd
        set failures (math $failures + 1)
    end
end

for cmd in podman distrobox dnsmasq
    if command -q $cmd
        printf '  [OK]   %-16s %s\n' $cmd (command -s $cmd)
    else
        printf '  [WARN] %-16s optional until its workflow is used\n' $cmd
    end
end

# Parse every shipped fish entry point. This catches accidental Bash heredocs
# and other shell-language mixups before a workflow is started.
if command -q fish
    set -l fish_scripts \
        "$RV220W_TOOLKIT_ROOT/rv220w.fish" \
        "$RV220W_TOOLKIT_ROOT"/scripts/*.fish \
        "$RV220W_TOOLKIT_ROOT"/scripts/lib/*.fish
    for script in $fish_scripts
        if test -f "$script"
            fish -n "$script"
            or begin
                printf '  [FAIL] fish syntax: %s\n' "$script"
                set failures (math $failures + 1)
            end
        end
    end
    printf '  [OK]   fish syntax      checked toolkit entry points\n'
end

if command -q bash
    for script in "$RV220W_TOOLKIT_ROOT"/scripts/inner/*.sh
        if test -f "$script"
            bash -n "$script"
            or begin
                printf '  [FAIL] bash syntax: %s\n' "$script"
                set failures (math $failures + 1)
            end
        end
    end
    printf '  [OK]   bash syntax      checked container helpers\n'
end

if test -d /dev/serial/by-id
    set -l serials /dev/serial/by-id/*
    if test (count $serials) -gt 0; and test -e "$serials[1]"
        printf '  [INFO] serial devices:\n'
        printf '         %s\n' $serials
    else
        printf '  [INFO] no serial adapter currently visible\n'
    end
else
    printf '  [INFO] /dev/serial/by-id is absent\n'
end

if rv_box_exists
    set -l runtime (rv_box_runtime_summary)
    test -n "$runtime"; or set runtime unknown
    printf '  [INFO] Container object: %s\n' "$runtime"
    set -l identity (rv_box_identity)
    test -n "$identity"; or set identity unknown
    printf '  [INFO] Distrobox OS: %s\n' "$identity"
    if rv_box_is_compatible
        printf '  [OK]   Distrobox base   Ubuntu 24.04 with apt-get\n'
        if rv_box_is_provisioned
            printf '  [OK]   Distrobox tools  OpenWrt build dependencies available\n'
        else
            printf '  [WARN] Distrobox tools  incomplete; run setup-box\n'
        end
    else
        printf '  [WARN] Distrobox base   incompatible; run setup-box --recreate\n'
    end
else
    printf '  [WARN] Distrobox %s is not ready; run setup-box\n' "$RV220W_BOX"
end

if test $failures -gt 0
    rv_die "$failures required check(s) failed"
end

rv_info 'Host and toolkit checks passed.'
