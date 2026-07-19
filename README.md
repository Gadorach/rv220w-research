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
| WLAN | Removable Mini PCI Broadcom `BCM4322LKFBG`, dual-band 802.11a/b/g/n | High |
| J2 | 2×7 test-pad header; probable MIPS EJTAG, not yet traced | Medium |
| JP1/JP2 | 1×4 through-hole headers; at least one probable 3.3 V UART | Medium |

## Safety rule

**Preserve before modifying.** Do not write flash, connect an unverified JTAG pinout, or drive an unknown header until power rails, grounds, and signal direction have been measured and a verified backup exists.

The main NOR is parallel flash. A CH341A SPI programmer and SOIC clip are not suitable for it.

## Repository map

- `docs/` — research notes, procedures, stage gates, and porting plan.
- `hardware/` — BOM, header tables, candidate pinouts, and measurement templates.
- `evidence/` — source photographs and placeholders for captures, logs, and flash dumps.
- `scripts/host/` — safe host-side capture and firmware inventory utilities.
- `scripts/target/` — read-only collection scripts intended for the stock Linux system.
- `templates/` — repeatable test records and promotion checklists.
- `sources/` — public reference index and a fetch helper; third-party documents are not redistributed.

## First practical milestone

The minimum useful evidence set is:

1. Complete power-on UART log from cold boot.
2. Voltage and direction map for every JP1/JP2 pin.
3. `/proc/cpuinfo`, `/proc/cmdline`, `/proc/mtd`, `dmesg`, and mount inventory.
4. Two independently acquired, byte-identical 32 MiB flash images.
5. Record of MAC addresses, board identity, calibration/configuration regions, and bootloader environment.

See [`docs/04-hardware-promotion-plan.md`](docs/04-hardware-promotion-plan.md) for the full stage-gated roadmap.
