#!/usr/bin/env fish
source (dirname (status --current-filename))/lib/common.fish
argparse 'n/dry-run' 'y/yes' 'u/sync-upgrade' -- $argv; or exit 2

rv_require pacman

set -l packages \
    fish git python python-pyserial podman distrobox dnsmasq iproute2 jq rsync \
    unzip zip xz zstd gzip coreutils

# Query only for missing packages.  Calling `pacman -S --needed` with the full
# list can still select upgrades for already-installed packages when the local
# sync database is newer than the installed version.  On a rolling distribution
# that can turn a simple dependency check into a stale-mirror 404 or partial-
# upgrade attempt.  `pacman -T` avoids that.
set -l missing (pacman -T $packages 2>/dev/null)

rv_info 'Only minimal host packages are installed. OpenWrt build dependencies stay inside Distrobox.'

if test (count $missing) -eq 0
    rv_info 'All required CachyOS host packages are already installed; nothing to do.'
    exit 0
end

rv_require sudo

set -l cmd sudo pacman
if set -q _flag_sync_upgrade
    set -a cmd -Syu --needed
else
    set -a cmd -S --needed
end
if set -q _flag_yes
    set -a cmd --noconfirm
end
set -a cmd $missing

printf '  Missing packages: %s\n' (string join ', ' -- $missing)
printf '  Command: %s\n' (string join ' ' -- $cmd)

if set -q _flag_dry_run
    exit 0
end

$cmd
or begin
    rv_warn 'The package transaction failed. A run of 404 errors usually means the local sync database and mirrors are out of step.'
    rv_warn 'On CachyOS/Arch, refresh mirrors as appropriate and perform a normal full system upgrade, or rerun setup-host with --sync-upgrade.'
    rv_die 'Host package installation failed; no forced package replacement was attempted'
end

rv_info 'Host dependencies installed.'
