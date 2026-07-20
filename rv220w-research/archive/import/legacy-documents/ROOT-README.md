# Cisco RV220W Hardware Research

Stage-gated reverse-engineering workspace for the Cisco RV220W Wireless-N Network Security Firewall, board revision `YK910A-1.6` / `RV220W-A V01`.

This repository records the current hardware inventory, evidence photographs, header hypotheses, preservation procedures, firmware-acquisition workflow, and a promotion plan toward a reproducible Linux/OpenWrt-class board port.

## Current platform summary

| Subsystem | Current identification | Confidence |
|---|---|---:|
| CPU | Cavium OCTEON Plus `CN5010-400BG564-SCP-G`, 400 MHz MIPS64/32 networking SoC | High |
| RAM | 2 × Etron `EM68B16CWQD-25H`, 32M×16 DDR2 each; 128 MiB total | High |
| Flash | Macronix `MX29GL256EHT2I-90Q`, 256 Mbit / 32 MiB, 3 V parallel NOR | High |
| Ethernet switch | Broadcom `BCM53115SKFBG`, five-port Gigabit RoboSwitch | High |
| WLAN | Removable full-size Mini PCI Broadcom `BCM4322LKFBG`; three U.FL connectors; two photographed SiGe `2547A / 2069CHF` RF front-end devices | High / medium-high |
| J2 | 2×7 test-pad header; probable MIPS EJTAG, not yet traced | Medium |
| JP1 | Confirmed primary UART: pin 1 VCC/NC, pin 2 TX, pin 3 RX, pin 4 GND; 115200 8N1 | High |
| JP2 | Separate secondary UART/manufacturing interface candidate | Medium |

## Safety rule

**Preserve before modifying.** Do not write flash, connect an unverified JTAG pinout, or drive an unknown header until power rails, grounds, and signal direction have been measured and a verified backup exists.

The main NOR is parallel flash. A CH341A SPI programmer and SOIC clip are not suitable for it.

## Repository map

- `docs/` — research notes, procedures, stage gates, and porting plan.
- `hardware/` — BOM, header tables, candidate pinouts, and measurement templates.
- `evidence/` — source photographs and placeholders for captures, logs, and flash dumps.
- `scripts/` — safe capture, collection, and indexing helpers.
- `templates/` — repeatable test records and promotion checklists.
- `sources/` — public reference index and a fetch helper; third-party documents are not redistributed.

## Current photographic baseline

The package now includes:

- the initial component close-up set,
- the exposed main-board topside set,
- the WLAN-module topside set,
- the full 72-image board photo archive with both board sides,
- a generated contact sheet for the entire archive, and
- direct high-resolution stitches for both sides of the logic board and Wi-Fi module.

The earlier block-overlay diagrams are superseded. New diagrams must use the direct stitched photographs as their board layer and may not synthesize or redraw board content.

See:

- [`docs/20-direct-photo-stitching.md`](docs/20-direct-photo-stitching.md)

- [`docs/18-topside-and-wlan-photo-review.md`](docs/18-topside-and-wlan-photo-review.md)
- [`docs/19-full-board-photo-archive-review.md`](docs/19-full-board-photo-archive-review.md)
- [`evidence/photos/archive-2026-07-19/README.md`](evidence/photos/archive-2026-07-19/README.md)

Outstanding photography still required:

1. WLAN module underside.
2. Sharper, perpendicular macro views of JP1, JP2, J2, U3, U4, and Mini PCI connector vias.
3. At least one low-glare, square-on underside overview.

## Current practical milestone

A complete, validated 32 MiB flash image has now been acquired and analyzed.

```text
CRC32:   ce96f3e0
SHA-256: 03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5
```

The target CRC before and after acquisition matched the host image, all 512 chunks completed at 460800 baud, and the completed run required zero retries.

The image has been divided into the boot stub, U-Boot, kernel container, complete ELF kernel, SquashFS rootfs, JFFS2 data partition, both environment-like regions, and the erased vendor tail. The exact stock upgrade image `RV220W-Firmware-1.0.4.17.img` was recovered from flash.

Current work is now focused on a safe OpenWrt port:

1. Acquire a second independent dump before any write.
2. Boot a custom Octeon OpenWrt initramfs ELF entirely from RAM using TFTP.
3. Add read-only BootBus NOR support.
4. Bring up Octeon RGMII and map physical interfaces.
5. Integrate BCM53115 through B53 DSA or a narrowly scoped compatibility path.
6. Add LEDs, reset button and persistent flash only after recovery is proven.

See:

- [`docs/26-complete-flash-dump-analysis-2026-07-20.md`](docs/26-complete-flash-dump-analysis-2026-07-20.md)
- [`docs/27-stock-software-architecture-2026-07-20.md`](docs/27-stock-software-architecture-2026-07-20.md)
- [`docs/28-openwrt-port-plan.md`](docs/28-openwrt-port-plan.md)
- [`firmware-analysis/README.md`](firmware-analysis/README.md)
- [`hardware/flash/partition-map.csv`](hardware/flash/partition-map.csv)
