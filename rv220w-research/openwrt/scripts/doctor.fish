#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
set -l failures 0
rv_info "Toolkit root: $RV220W_TOOLKIT_ROOT"
rv_info "Workspace:    $RV220W_WORKSPACE"
rv_info "Distrobox:    $RV220W_BOX ($RV220W_BOX_IMAGE)"

for cmd in fish git python3 sha256sum cmp gzip ip jq rsync
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
    printf '  [OK]   Distrobox %s is reachable\n' "$RV220W_BOX"
else
    printf '  [WARN] Distrobox %s is not ready; run setup-box\n' "$RV220W_BOX"
end

if test $failures -gt 0
    rv_die "$failures required host command(s) are missing"
end
rv_info 'Host checks passed.'
