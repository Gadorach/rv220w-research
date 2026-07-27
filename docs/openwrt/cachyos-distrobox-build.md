# CachyOS and Distrobox build environment

The supported workflow uses fish on CachyOS for orchestration and an Ubuntu 24.04 Distrobox for OpenWrt compilation.

## Setup

```fish
cd openwrt
cp config/toolkit.env.fish.example config/toolkit.env.fish
./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
./rv220w.fish platform verify
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

## Current hardware-proven build

```fish
./rv220w.fish build rj45-full
```

Expected artifact:

```text
$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-rj45-initramfs.elf
```

The older `initramfs`, `discovery`, `dsa-lan`, and `dsa-dual` profiles remain useful for regression and diagnostics. The `rj45-full` profile is the current complete wired RAM-boot image.

## Reproducibility

- Preserve `source-lock.json`, expanded configs, build logs, and artifact hashes.
- Run the toolkit tests before packaging changes.
- Do not change the OpenWrt ref while comparing hardware behavior.
- Do not confuse the standalone Linux reference build with the OpenWrt-managed kernel used by the live image.
