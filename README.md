# Cisco RV220W research

Research, preservation, boot-chain analysis, and experimental modern OpenWrt support for the Cisco RV220W.

## Current status

- Modern OpenWrt boots automatically from the onboard NOR through the patched stock U-Boot chain.
- The persistent image includes LuCI and operates WAN plus all four LAN ports.
- The required combined boot-policy patch is hardware validated and preserves physical-button Sercomm recovery.
- NOR slot writing, complete backup, and full read-back verification are hardware validated.
- Wi-Fi and a persistent writable OpenWrt root/overlay remain unfinished.

## Start here

- [`STATUS.md`](STATUS.md) — exact current behavior, requirements, and remaining work.
- [`docs/README.md`](docs/README.md) — canonical documentation index.
- [`docs/openwrt/installation.md`](docs/openwrt/installation.md) — required patch-first installation order.
- [`openwrt/README.md`](openwrt/README.md) — build, RAM-boot, and guarded NOR tooling.
- [`firmware/reconstruction/README.md`](firmware/reconstruction/README.md) — boot-chain reconstruction and hardware evidence.

Preserved vendor firmware and extracted data remain subject to their original terms and are included for research and recovery.
