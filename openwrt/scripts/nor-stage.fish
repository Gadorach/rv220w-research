#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish

argparse \
    'H/host=' \
    'i/image=' \
    'm/manifest=' \
    'b/backup-dir=' \
    'c/confirm=' -- $argv; or exit 2

if test (count $argv) -lt 1
    echo 'Usage: ./rv220w.fish nor-stage ACTION [options]' >&2
    echo 'ACTION: status | backup | write | verify | restore | boot-plan' >&2
    echo 'Options: --host root@192.168.240.2 --image FILE --manifest FILE --backup-dir DIR --confirm TOKEN' >&2
    exit 2
end

rv_require ssh python3 sha256sum
set -l action $argv[1]
set -l host "root@$RV220W_TFTP_DEVICE_IP"
set -q _flag_host; and set host $_flag_host
set -l image "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-rj45-luci-nor-slot.bin"
set -q _flag_image; and set image (realpath -m $_flag_image)
set -l manifest "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-rj45-luci-nor-slot.json"
set -q _flag_manifest; and set manifest (realpath -m $_flag_manifest)
set -l backup_dir "$RV220W_WORKSPACE/backups/nor"
set -q _flag_backup_dir; and set backup_dir (realpath -m $_flag_backup_dir)
set -l confirmation
set -q _flag_confirm; and set confirmation $_flag_confirm
# RAM/initramfs boots generate a fresh Dropbear host key. Keep those expected
# ephemeral keys out of the user's persistent known_hosts file. Disable PTY
# allocation so binary backup and upload streams remain byte-exact.
set -l ssh_options \
    -T \
    -o ConnectTimeout=10 \
    -o ServerAliveInterval=5 \
    -o ServerAliveCountMax=3 \
    -o StrictHostKeyChecking=no \
    -o UserKnownHostsFile=/dev/null \
    -o GlobalKnownHostsFile=/dev/null \
    -o LogLevel=ERROR
set -l remote_image /tmp/rv220w-openwrt-slot.bin
set -l remote_restore /tmp/rv220w-restore-slot.bin
set -l slot_helper "$RV220W_TOOLKIT_ROOT/scripts/host/build_rv220w_nor_slot.py"

function target_status --inherit-variable host --inherit-variable ssh_options
    command ssh $ssh_options "$host" /usr/sbin/rv220w-nor-stage status
end

function upload_blob --argument-names local_path remote_path --inherit-variable host --inherit-variable ssh_options
    test -f "$local_path"; or rv_die "Upload source is missing: $local_path"
    set -l remote_partial "$remote_path.partial.$fish_pid"

    # OpenSSH 9+ scp defaults to SFTP, while the Dropbear maintenance image
    # intentionally has no sftp-server. Stream the exact bytes through SSH
    # into a private temporary file, then atomically rename it into place.
    command cat "$local_path" | command ssh $ssh_options "$host" \
        "umask 077; rm -f '$remote_partial' '$remote_path'; cat > '$remote_partial' && mv '$remote_partial' '$remote_path'"
    set -l transfer_status $pipestatus
    if test (count $transfer_status) -ne 2; or test $transfer_status[1] -ne 0; or test $transfer_status[2] -ne 0
        command ssh $ssh_options "$host" "rm -f '$remote_partial' '$remote_path'" >/dev/null 2>&1; or true
        return 1
    end
end

function backup_slot --inherit-variable host --inherit-variable ssh_options --inherit-variable backup_dir
    target_status; or rv_die 'Target did not pass NOR-writer safety checks; no backup was attempted.'
    mkdir -p "$backup_dir"; or rv_die "Could not create backup directory: $backup_dir"
    set -l stamp (rv_timestamp)
    set -l output "$backup_dir/rv220w-openwrt-slot-backup-$stamp.bin"
    set -l partial "$output.partial.$fish_pid"
    rv_info "Reading the complete 22 MiB openwrt-slot into $output"
    command ssh $ssh_options "$host" /usr/sbin/rv220w-nor-stage backup > "$partial"
    or begin
        rm -f "$partial"
        rv_die 'NOR backup stream failed.'
    end
    set -l size (wc -c < "$partial" | string trim)
    test "$size" = 23068672; or begin
        rm -f "$partial"
        rv_die "NOR backup has the wrong size: $size"
    end
    mv "$partial" "$output"; or rv_die 'Could not finalize NOR backup.'
    command sha256sum "$output" > "$output.sha256"; or rv_die 'Could not hash NOR backup.'
    rv_info "Backup complete: $output"
    echo "$output"
end

switch "$action"
    case status
        target_status; or rv_die 'NOR-writer status check failed. Confirm the RAM writer is running and reachable over SSH.'

    case backup
        backup_slot

    case verify
        test -f "$image"; or rv_die "Slot image not found: $image"
        test -f "$manifest"; or rv_die "Slot manifest not found: $manifest"
        set -l expected_sha (command python3 "$slot_helper" verify "$image" "$manifest")
        or rv_die 'Local NOR-slot image verification failed.'
        target_status; or rv_die 'Target did not pass NOR-writer safety checks.'
        command ssh $ssh_options "$host" /usr/sbin/rv220w-nor-stage verify "$expected_sha"
        or rv_die 'NOR read-back verification failed.'

    case boot-plan
        test -f "$manifest"; or rv_die "Slot manifest not found: $manifest"
        rv_info 'Direct bootoct execution from memory-mapped NOR is not supported for this Linux ELF.'
        rv_info 'Copy the exact ELF bytes into the proven RAM staging address, then use bootoctlinux:'
        command python3 "$slot_helper" boot-plan "$manifest"
        or rv_die 'Could not derive the U-Boot NOR-to-RAM boot plan from the manifest.'

    case restore
        test "$confirmation" = RV220W_RESTORE_OPENWRT_SLOT; or rv_die 'Refusing restore: pass --confirm RV220W_RESTORE_OPENWRT_SLOT exactly.'
        test -f "$image"; or rv_die "Backup image not found: $image"
        set -l restore_size (wc -c < "$image" | string trim)
        test "$restore_size" = 23068672; or rv_die "Backup image has the wrong size: $restore_size"
        set -l expected_sha (command sha256sum "$image" | awk '{print $1}')
        # Preserve the currently staged slot before restoring an older backup.
        backup_slot

        rv_info "Streaming the verified 22 MiB restore image to $host:$remote_restore"
        upload_blob "$image" "$remote_restore"
        or rv_die 'Restore-image SSH stream failed; NOR was not written.'

        command ssh $ssh_options "$host" /usr/sbin/rv220w-nor-stage restore \
            "$remote_restore" "$expected_sha" RV220W_RESTORE_OPENWRT_SLOT
        or begin
            command ssh $ssh_options "$host" rm -f "$remote_restore" >/dev/null 2>&1; or true
            rv_die 'NOR restore or read-back verification failed. Use TFTP recovery and retain all backups.'
        end

        command ssh $ssh_options "$host" rm -f "$remote_restore" >/dev/null 2>&1; or true
        rv_info 'Restore and read-back verification completed. The router was not rebooted and U-Boot environment was not changed.'

    case write
        test "$confirmation" = RV220W_WRITE_OPENWRT_SLOT; or rv_die 'Refusing write: pass --confirm RV220W_WRITE_OPENWRT_SLOT exactly.'
        test -f "$image"; or rv_die "Slot image not found: $image"
        test -f "$manifest"; or rv_die "Slot manifest not found: $manifest"
        set -l expected_sha (command python3 "$slot_helper" verify "$image" "$manifest")
        or rv_die 'Local NOR-slot image verification failed.'
        # Every first-stage write creates a complete stock-kernel/rootfs-region
        # backup before transferring or erasing anything.
        backup_slot

        rv_info "Streaming the verified 22 MiB slot image to $host:$remote_image"
        upload_blob "$image" "$remote_image"
        or rv_die 'Slot-image SSH stream failed; NOR was not written.'

        rv_info 'Invoking the target-side openwrt-slot-only writer and full read-back verification.'
        command ssh $ssh_options "$host" /usr/sbin/rv220w-nor-stage write \
            "$remote_image" "$expected_sha" RV220W_WRITE_OPENWRT_SLOT
        or begin
            command ssh $ssh_options "$host" rm -f "$remote_image" >/dev/null 2>&1; or true
            rv_die 'NOR write or read-back verification failed. Do not alter U-Boot environment; use TFTP recovery and inspect the backup.'
        end

        command ssh $ssh_options "$host" rm -f "$remote_image" >/dev/null 2>&1; or true
        rv_info 'Write and read-back verification completed. The router was not rebooted and U-Boot environment was not changed.'
        rv_info 'Direct bootoct execution from flash is not valid for this Linux ELF.'
        rv_info 'At the serial U-Boot prompt, copy the ELF to RAM and then use bootoctlinux:'
        command python3 "$slot_helper" boot-plan "$manifest"
        or rv_die 'NOR write succeeded, but the local U-Boot boot plan could not be generated from the manifest.'

    case '*'
        rv_die "Unknown NOR stage action: $action"
end
