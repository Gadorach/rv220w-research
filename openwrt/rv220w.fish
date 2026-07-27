#!/usr/bin/env fish
set -l root (realpath (dirname (status --current-filename)))
if test (count $argv) -eq 0
    printf '%s\n' \
        'Usage: ./rv220w.fish ACTION [arguments]' \
        '' \
        'Actions:' \
        '  version            Show toolkit, platform-baseline, and discovery versions' \
        '  doctor             Check the CachyOS host and toolkit' \
        '  setup-host         Install minimal CachyOS host dependencies' \
        '  setup-box          Create/validate/provision the Ubuntu Distrobox' \
        '  prepare-sources    Clone/pin repos, install RV220W platform, and install feeds' \
        '  platform           Install or verify the RV220W OpenWrt platform overlay' \
        '  dump               Read the complete NOR through JP1/U-Boot' \
        '  extract            Split and extract a verified 32 MiB dump' \
        '  build              Build OpenWrt initramfs, squashfs or squashfs-live' \
        '  build-linux        Build the standalone Octeon Linux reference tree' \
        '  tftp-boot          Start TFTP and automate U-Boot live boot' \
        '  collect-snapshot   Retrieve a read-only discovery snapshot over SSH' \
        '  collect-mdio       Run/retrieve a read-only MDIO scan over UART (SSH optional)' \
        '  collect-b53        Run/retrieve a passive B53 topology snapshot over UART' \
        '  collect-conduit    Collect paired DSA and raw B53 conduit-state snapshots' \
        '  compare-b53        Compare two B53 snapshots, focused on ports 0/5/8' \
        '  b53-eap            Read/change BCM53115 standalone-port EAP mode over UART' \
        '  b53-vlan           Read/change BCM53115 VLAN/PVID diagnostic state over UART' \
        '  collect-dsa        Retrieve a DSA validation snapshot over UART' \
        '  verify             Verify generated artifacts and manifests'
    exit 2
end
set -l action $argv[1]
set -e argv[1]
switch $action
    case version
        exec "$root/scripts/version.fish" $argv
    case doctor
        exec "$root/scripts/doctor.fish" $argv
    case setup-host
        exec "$root/scripts/setup-host-cachyos.fish" $argv
    case setup-box
        exec "$root/scripts/setup-distrobox.fish" $argv
    case prepare-sources
        exec "$root/scripts/prepare-sources.fish" $argv
    case platform
        exec "$root/scripts/platform.fish" $argv
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
    case collect-snapshot
        exec "$root/scripts/collect-snapshot.fish" $argv
    case collect-mdio
        exec "$root/scripts/collect-mdio.fish" $argv
    case collect-b53
        exec "$root/scripts/collect-b53.fish" $argv
    case collect-conduit
        exec "$root/scripts/collect-conduit.fish" $argv
    case compare-b53
        exec "$root/scripts/compare-b53.fish" $argv
    case b53-eap
        exec "$root/scripts/b53-eap.fish" $argv
    case b53-vlan
        exec "$root/scripts/b53-vlan.fish" $argv
    case collect-dsa
        exec "$root/scripts/collect-dsa.fish" $argv
    case verify
        exec "$root/scripts/verify-artifacts.fish" $argv
    case '*'
        printf 'Unknown action: %s\n' "$action" >&2
        exit 2
end
