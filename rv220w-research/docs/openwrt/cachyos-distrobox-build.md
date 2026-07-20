# CachyOS and Distrobox build environment

## Host responsibilities

CachyOS provides:

- fish entry points,
- Git and artifact storage,
- Podman/Distrobox,
- serial and direct-link network devices,
- TFTP runtime tools.

## Container responsibilities

Ubuntu 24.04 Distrobox provides the stable OpenWrt build dependency set, cross-toolchains, kernel headers, SquashFS tools, device-tree compiler, and image utilities.

## Setup

```fish
cd openwrt
cp config/toolkit.env.fish.example config/toolkit.env.fish
./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
```

Default workspace:

```text
~/src/rv220w-openwrt/
  sources/openwrt/
  sources/linux-reference/
  sources/meraki-builder-reference/
  artifacts/
  logs/
  source-lock.json
```

The Meraki builder checkout is a workflow reference, not an RV220W code dependency.

## Build modes

```fish
./rv220w.fish build initramfs
./rv220w.fish build squashfs
./rv220w.fish build squashfs-live
./rv220w.fish build kernel
./rv220w.fish build-linux
```

The generic Octeon build is only a transport/kernel baseline. Do not flash it and do not assume another Octeon device’s DTS matches the RV220W.

## Reproducibility

- Keep source checkouts clean before updating.
- Record exact commits in `source-lock.json`.
- Keep generated configs and build logs with each artifact.
- Rebuild from a clean output directory before promotion to hardware testing.
