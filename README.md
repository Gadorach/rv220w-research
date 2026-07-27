# Cisco RV220W research

Research, preservation, and experimental modern OpenWrt support for the Cisco RV220W.

## Current status

- **Proven:** OpenWrt boots completely from RAM through U-Boot/TFTP.
- **Proven:** the live image initializes and operates all five RJ45 ports: LAN1–LAN4 and WAN.
- **Not included:** LuCI and Wi-Fi support.
- **Not attempted:** persistent installation or writes to the onboard NOR flash.
- **Safety model:** development remains RAM-only; reboot returns to the untouched stock firmware.

## Project map

- [`STATUS.md`](STATUS.md) — detailed current status and remaining work.
- [`docs/README.md`](docs/README.md) — research and hardware documentation.
- [`openwrt/README.md`](openwrt/README.md) — current OpenWrt build, validation, and TFTP RAM-boot toolkit.
- `firmware/` — verified stock images, partitions, filesystems, and analysis.
- `hardware/` and `evidence/` — board records, measurements, photographs, and captured proof.
- `tools/` — preservation and analysis utilities outside the OpenWrt toolkit.

The repository contains preserved vendor firmware and extracted data for research and recovery. Those files remain subject to their original terms and must not be treated as redistributable open-source code.
