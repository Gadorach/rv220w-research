#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'n/dry-run' 'y/yes' -- $argv; or exit 2
rv_require pacman sudo
set -l packages fish git python python-pyserial podman distrobox dnsmasq iproute2 jq rsync unzip zip xz zstd gzip coreutils
set -l cmd sudo pacman -S --needed
if set -q _flag_yes
    set -a cmd --noconfirm
end
set -a cmd $packages
rv_info 'Only minimal host packages are installed. OpenWrt build dependencies stay inside Distrobox.'
printf '  %s\n' (string join ' ' $cmd)
if set -q _flag_dry_run
    exit 0
end
$cmd; or rv_die 'pacman failed; resolve the reported package conflict rather than forcing replacement'
rv_info 'Host dependencies installed.'
