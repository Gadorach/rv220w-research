# CachyOS and Distrobox build design

## Why the build stays in Distrobox

CachyOS is a rolling Arch-derived distribution.  OpenWrt master and stable release branches expect a conventional, internally consistent build host.  The toolkit therefore keeps only device access and orchestration on the host while running the complete OpenWrt dependency/toolchain/kernel/image pipeline in one Ubuntu 24.04 Distrobox.

The approach follows the useful pattern in the Gadorach `meraki-builder` fork: automated source preparation, a containerized build environment, staged artifacts, and build logs rather than relying on whatever compilers happen to be installed on the rolling host.

Distrobox shares the real home directory, so:

```text
host:      ~/src/rv220w-openwrt/
container: ~/src/rv220w-openwrt/
```

refer to the same files.

## Host responsibilities

- fish entry points,
- Git and checksums,
- serial access through `/dev/serial/by-id`,
- `dnsmasq` TFTP service,
- network-interface configuration,
- Podman/Distrobox.

The host does not compile OpenWrt.

## Container responsibilities

- feeds,
- OpenWrt host tools,
- cross toolchain,
- Linux kernel,
- packages,
- SquashFS creation,
- image assembly,
- `readelf`/DTB checks.

## Pinned defaults

```text
OpenWrt:      v25.12.5
Distrobox:    Ubuntu 24.04
Linux ref:    linux-6.12.y
Meraki ref:   Gadorach/meraki-builder ms42p-dev
```

The separate Linux checkout is for reference, diffing, and upstream work.  OpenWrt's managed kernel source remains authoritative for actual OpenWrt builds.

## Workspace

```text
~/src/rv220w-openwrt/
├── sources/
│   ├── openwrt/
│   ├── linux-reference/
│   └── meraki-builder-reference/
├── artifacts/
├── logs/
└── source-lock.json
```


## Host-package setup behavior

`setup-host` queries pacman with `pacman -T` and installs only packages that are
actually absent. It does not use the full package list as an upgrade request.

```fish
./rv220w.fish setup-host
```

When all dependencies are already present, the command exits successfully
without invoking sudo or pacman installation.

If missing packages cannot be downloaded because the local sync database points
to package versions no longer present on the mirrors, update the normal
CachyOS/Arch system state first. The toolkit can request that explicitly:

```fish
./rv220w.fish setup-host --sync-upgrade
```

That option performs a normal `pacman -Syu` transaction plus the missing
packages. It is intentionally not the default because a build-tool setup helper
should not silently initiate a full rolling-distribution upgrade.

## Shell separation

The public orchestration entry points are Fish scripts. Container-side build and
provisioning programs are static Bash files under:

```text
scripts/inner/
```

Fish does not support Bash `<<EOF` heredocs. Keeping the languages in separate
files also allows `doctor` to run `fish -n` and `bash -n` before provisioning.

## Recovery from a failed build

Do not delete the source checkout first.  Preserve:

```text
.config
artifacts/*.expanded.config
logs/
source-lock.json
```

Then try:

```fish
./rv220w.fish build clean
./rv220w.fish build initramfs --jobs 1
```

The build helper automatically repeats a failed parallel build with `-j1 V=s` and saves the diagnostic log.

## Updating sources deliberately

```fish
./rv220w.fish prepare-sources --update
```

Changing `RV220W_OPENWRT_REF` creates a new promotion baseline.  Do not silently move the stable tag while comparing hardware results.


## Standalone Linux reference build

The OpenWrt tree remains authoritative for live OpenWrt images. A separate upstream stable tree is prepared so that Octeon platform changes, device-tree work, and driver behavior can be compared without modifying OpenWrt's managed kernel source.

```fish
./rv220w.fish build-linux
```

The helper starts from `cavium_octeon_defconfig`, uses Ubuntu’s optional `mips64-linux-gnuabi64-` system cross compiler, enables conservative serial/PCI/MTD/OF options, builds `vmlinux` and DTBs in an out-of-tree directory, and marks the results `NOT-FOR-BOOT-YET`. This external compiler is not required for OpenWrt, which builds its own toolchain. If Ubuntu cannot provide the optional package, `doctor` reports that only `build-linux` is unavailable. The result becomes a boot candidate only after an RV220W-specific DTS and U-Boot boot contract are proven.

Interactive reference-kernel configuration remains inside Distrobox:

```fish
./rv220w.fish build-linux --menuconfig
```

## Build-container identity validation

Toolkit v1.0.2 does not treat mere Distrobox reachability as proof that the
container is suitable. The named box must report Ubuntu 24.04 from
`/etc/os-release`, provide `apt-get`, and contain the provisioned build tools.
`doctor` displays the actual container identity.

If the configured name already belongs to a different distribution, verify that
`config/toolkit.env.fish` still selects:

```fish
set -gx RV220W_BOX_IMAGE docker.io/library/ubuntu:24.04
```

Then recreate only that container:

```fish
./rv220w.fish setup-box --recreate
```

The workspace remains under the host home directory and is not removed with the
container.

## Source-clone size

New source checkouts are shallow and restricted to the configured branch or tag.
This is especially important for the Linux stable tree, whose complete history
can consume several gigabytes when a server ignores partial-clone filters.

An earlier full-history checkout remains valid. To stage a shallow replacement:

```fish
./rv220w.fish prepare-sources --reclone-linux
```

The old directory is moved to a timestamped backup. Delete that backup manually
only after the new checkout and `source-lock.json` have been verified.
