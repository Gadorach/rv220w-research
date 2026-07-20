# Documentation index

The files below are canonical. Historical incident reports are kept under `history/`; older numbered documents from the imported package were merged and are mapped in `history/legacy-document-map.md`.

## Platform and hardware

- [`platform-overview.md`](platform-overview.md) — scope, confirmed platform, status, and evidence rules.
- [`hardware/board-and-components.md`](hardware/board-and-components.md) — board identity, component inventory, layout, power, clocks, and reset.
- [`hardware/debug-interfaces.md`](hardware/debug-interfaces.md) — JP1, JP2, J2, SW2, and safe probing.
- [`hardware/photos-and-board-maps.md`](hardware/photos-and-board-maps.md) — direct-stitch policy and photographic evidence.
- [`hardware/ethernet-switch.md`](hardware/ethernet-switch.md) — Octeon Ethernet and BCM53115 promotion.
- [`hardware/wireless.md`](hardware/wireless.md) — BCM4322 module and RF observations.

## Firmware

- [`firmware/acquisition-and-validation.md`](firmware/acquisition-and-validation.md) — UART dumping, validation, and recovery policy.
- [`firmware/flash-layout-and-extraction.md`](firmware/flash-layout-and-extraction.md) — complete NOR map and canonical artifacts.
- [`firmware/bootloader-and-ramboot.md`](firmware/bootloader-and-ramboot.md) — U-Boot environment, commands, and RAM-boot contract.
- [`firmware/stock-software-architecture.md`](firmware/stock-software-architecture.md) — kernel, rootfs, switch, WLAN, buttons, and LEDs.

## OpenWrt

- [`openwrt/promotion-plan.md`](openwrt/promotion-plan.md) — stage-gated port plan.
- [`openwrt/cachyos-distrobox-build.md`](openwrt/cachyos-distrobox-build.md) — source preparation and build environment.
- [`openwrt/tftp-live-boot.md`](openwrt/tftp-live-boot.md) — automated serial/TFTP boot workflow.
- [`openwrt/squashfs-live-design.md`](openwrt/squashfs-live-design.md) — RAM-only SquashFS validation image.

## Operations and references

- [`operations/risk-and-recovery.md`](operations/risk-and-recovery.md)
- [`operations/known-unknowns.md`](operations/known-unknowns.md)
- [`operations/test-session-template.md`](operations/test-session-template.md)
- [`operations/sources-and-gpl.md`](operations/sources-and-gpl.md)
