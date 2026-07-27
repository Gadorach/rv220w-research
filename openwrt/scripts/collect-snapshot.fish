#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'r/router-ip=' 'o/output-dir=' -- $argv; or exit 2

set -l label snapshot
if test (count $argv) -ge 1
    set label $argv[1]
end
set label (string replace -ra '[^A-Za-z0-9._-]' '_' -- "$label")

set -l router_ip $RV220W_TFTP_DEVICE_IP
set -q _flag_router_ip; and set router_ip $_flag_router_ip
set -l output_dir "$RV220W_WORKSPACE/logs/discovery"
set -q _flag_output_dir; and set output_dir (realpath -m $_flag_output_dir)

rv_require ssh
mkdir -p "$output_dir"; or rv_die "Could not create output directory: $output_dir"

# RAM-initramfs boots generate a fresh Dropbear host key. Keep those expected
# ephemeral keys out of the user's persistent known_hosts file.
set -l ssh_options \
    -o BatchMode=yes \
    -o ConnectTimeout=5 \
    -o StrictHostKeyChecking=no \
    -o UserKnownHostsFile=/dev/null \
    -o LogLevel=ERROR
set -l target "root@$router_ip"

set -l remote_script /usr/sbin/rv220w-discovery-snapshot
set -l fallback "$RV220W_TOOLKIT_ROOT/openwrt/files-discovery/usr/sbin/rv220w-discovery-snapshot"

if not ssh $ssh_options "$target" "test -x $remote_script" >/dev/null 2>&1
    rv_warn 'Discovery script is not installed on the target; streaming the packaged read-only script to /tmp over SSH.'
    test -f "$fallback"; or rv_die "Missing packaged discovery script: $fallback"
    command cat "$fallback" | ssh $ssh_options "$target" \
        'umask 077; cat > /tmp/rv220w-discovery-snapshot && chmod 0755 /tmp/rv220w-discovery-snapshot'
    set -l transfer_status $pipestatus
    if test $transfer_status[1] -ne 0 -o $transfer_status[2] -ne 0
        rv_die 'Could not stream discovery script to the target over SSH'
    end
    set remote_script /tmp/rv220w-discovery-snapshot
end

set -l remote_output (ssh $ssh_options "$target" "$remote_script '$label'" | string trim | tail -n 1)
test -n "$remote_output"; or rv_die 'Target did not return a discovery output path'
string match -qr '^/tmp/rv220w-discovery-[A-Za-z0-9._-]+\.txt$' -- "$remote_output"; or rv_die "Unexpected target output path: $remote_output"

set -l local_output "$output_dir/"(basename "$remote_output")
set -l local_partial "$local_output.partial.$fish_pid"
command rm -f "$local_partial"
ssh $ssh_options "$target" "cat '$remote_output'" > "$local_partial"; or begin
    command rm -f "$local_partial"
    rv_die 'Could not retrieve discovery snapshot over SSH'
end
test -s "$local_partial"; or begin
    command rm -f "$local_partial"
    rv_die 'Retrieved discovery snapshot was empty'
end
command mv -f "$local_partial" "$local_output"; or begin
    command rm -f "$local_partial"
    rv_die "Could not finalize discovery snapshot: $local_output"
end
rv_info "Saved $local_output"
