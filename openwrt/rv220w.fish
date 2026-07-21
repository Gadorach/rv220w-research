#!/usr/bin/env fish
set -l root (realpath (dirname (status --current-filename)))
if test (count $argv) -eq 0
    printf '%s\n' \
        'Usage: ./rv220w.fish ACTION [arguments]' \
        '' \
        'Actions:' \
        '  doctor             Check the CachyOS host and toolkit' \
        '  setup-host         Install minimal CachyOS host dependencies' \
        '  setup-box          Create and provision the Ubuntu Distrobox' \
        '  prepare-sources    Clone/pin OpenWrt, Linux and reference repos' \
        '  dump               Read the complete NOR through JP1/U-Boot' \
        '  extract            Split and extract a verified 32 MiB dump' \
        '  build              Build OpenWrt initramfs, squashfs or squashfs-live' \
        '  build-linux        Build the standalone Octeon Linux reference tree' \
        '  tftp-boot          Start TFTP and automate U-Boot live boot' \
        '  verify             Verify generated artifacts and manifests'
    exit 2
end
set -l action $argv[1]
set -e argv[1]
switch $action
    case doctor
        exec "$root/scripts/doctor.fish" $argv
    case setup-host
        exec "$root/scripts/setup-host-cachyos.fish" $argv
    case setup-box
        exec "$root/scripts/setup-distrobox.fish" $argv
    case prepare-sources
        exec "$root/scripts/prepare-sources.fish" $argv
    case dump
        exec "$root/scripts/dump-firmware.fish" $argv
    case extract
        exec "$root/scripts/extract-dump.fish" $argv
    case build
        exec "$root/scripts/build-openwrt.fish" $argv
    case build-linux
        exec "$root/scripts/build-linux-reference.fish" $argv
    case tftp-boot
        exec "$root/scripts/tftp-boot.fish" $argv
    case verify
        exec "$root/scripts/verify-artifacts.fish" $argv
    case '*'
        printf 'Unknown action: %s\n' "$action" >&2
        exit 2
end
