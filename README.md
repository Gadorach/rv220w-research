# Cisco RV220W research

Research, preservation, boot-chain analysis, and hardware-qualified modern OpenWrt support for the Cisco RV220W.

## Current status

- OpenWrt `1.16.0-rc7` boots automatically through the patched stock U-Boot chain.
- The persistent SquashFS/JFFS2 installation supports LuCI, configuration-preserving sysupgrade, WAN, all four LAN ports, and BCM4322/b43 Wi-Fi.
- The guarded RAM installer writes rootfs first and kernel last, verifies both by SHA-256 readback, and preserves the boot chain and U-Boot environment.
- Hardware-qualified initramfs and sysupgrade images are retained under [`prebuilt/`](prebuilt/).
- Physical-button Sercomm recovery remains available.

## Start here

- [`STATUS.md`](STATUS.md) - exact qualified behavior and remaining limitations.
- [`docs/README.md`](docs/README.md) - canonical research documentation index.
- [`docs/openwrt/installation.md`](docs/openwrt/installation.md) - safe first-install workflow.
- [`openwrt/README.md`](openwrt/README.md) - build and release-tool reference.
- [`prebuilt/README.md`](prebuilt/README.md) - retained release images and verification.

Preserved vendor firmware and extracted data remain subject to their original terms and are included for research and recovery.
