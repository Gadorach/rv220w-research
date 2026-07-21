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

The helper starts from `cavium_octeon_defconfig`, enables conservative serial/PCI/MTD/OF options, builds `vmlinux` and DTBs in an out-of-tree directory, and marks the results `NOT-FOR-BOOT-YET`. It becomes a boot candidate only after an RV220W-specific DTS and U-Boot boot contract are proven.

Interactive reference-kernel configuration remains inside Distrobox:

```fish
./rv220w.fish build-linux --menuconfig
```
