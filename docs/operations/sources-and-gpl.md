# Sources and GPL material

The canonical URL list is `sources/urls.csv`. `sources/fetch-public-docs.sh` downloads selected public references without redistributing third-party PDFs in this package.

The active OpenWrt release is GPL-3.0 licensed under `openwrt/LICENSE`. `openwrt/source-lock.json` records the qualified OpenWrt and feed commits; ordinary source preparation replays rather than silently advances that lock.

The retained prebuilt images contain OpenWrt packages, Linux-derived code, and Broadcom b43 firmware subject to their respective licenses. They are distributed as corresponding release artifacts, not under the repository-level MIT license.

Cisco’s RV220W open-source notice identifies Linux 2.6.21, BusyBox, GCC/binutils/glibc, and related components. The prepared corresponding-source request is in `sources/gpl-source-request.txt`.

High-value requested material includes:

- exact kernel source and configuration,
- Cavium board patches and SDK integration,
- U-Boot source and board files,
- BootBus timing and partition definitions,
- GPIO/LED/reset support,
- switch-management code covered by applicable licenses,
- build scripts and toolchain configuration.
