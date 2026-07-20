# Changelog

## 0.9.0 — 2026-07-20

- Added the completed 32 MiB flash acquisition and integrity record.
- Confirmed target CRC before/after and host CRC all equal `ce96f3e0`; SHA-256 is `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5`.
- Added exact physical partition and boot-region maps.
- Extracted the boot stub, U-Boot proper, kernel container, complete ELF64 kernel, SquashFS rootfs, JFFS2 data, vendor tail and both environment-like sectors.
- Recovered the exact stock `RV220W-Firmware-1.0.4.17.img` from flash.
- Identified and verified the firmware container's additive image checksum field at header offset `0x14`.
- Added rootfs and JFFS2 inventory reports and sensitive-data warnings.
- Documented the stock Octeon Ethernet, MDIO, BCM53115, GPIO and WLAN module architecture.
- Added a staged, RAM-first OpenWrt port plan.
- Added reproducible flash/partition and JFFS2 extraction scripts.

## 0.8.1 — 2026-07-20

- Diagnosed the repeatable `0xbdc38640` failure as a host parser bug rather than UART data loss.
- Fixed `md.b` parsing so whitespace matching cannot cross CR/LF boundaries.
- Changed parsing to operate one physical line at a time.
- Added detection of conflicting duplicate address rows.
- Added regression tests for all-space ASCII columns.
- Confirmed 921600 baud is rejected, while 460800 and 230400 are supported.
- Updated the recommended full-dump rate to 460800 baud.

## 0.8.0 — 2026-07-20

- Corrected JP1 physical numbering from the earlier reverse-order resistance worksheet.
- Confirmed final JP1 pinout: pin 1 VCC/VREF (NC), pin 2 target TX, pin 3 target RX, pin 4 GND.
- Added the square-pad/refdes orientation rule: pin 1 is the square pad furthest from the `JP1` silkscreen.
- Updated all header, netlist, promotion, acquisition, and status documentation to use the confirmed physical numbering.
- Expanded the U-Boot analysis with the full command inventory, flash geometry, boot command, PCI identification, and active-environment/MTD discrepancy.
- Added a detailed staged UART flash-dump procedure: 64 KiB at 115200, 64 KiB at 921600, then two independently verified 32 MiB acquisitions.
- Hardened the read-only dumper's prompt detection and resume validation.

## 0.7.0 — 2026-07-20

- Confirmed JP1 as the primary 115200-8N1 U-Boot/Linux UART.
- Added the hardware-factory-reset boot log and U-Boot command inventory.
- Recorded U-Boot 1.1.1 development build `193M`, firmware 1.0.4.17, Linux 2.6.21.7-Cavium-Octeon, and Cavium SDK details.
- Documented the full 32 MiB x16 CFI NOR geometry and protected-sector map.
- Documented the mismatch between the MTD partition named `bootload-env` and U-Boot's active final-sector `env_addr`.
- Added `scripts/host/dump_uboot_flash_uart.py`, a read-only, resumable `md.b` dump tool with per-chunk and full CRC32 validation.
- Added an automated temporary console-baud handshake supporting a 921600-baud attempt without `saveenv`.

## 0.6.0 — 2026-07-20

- Corrected the JP1/JP2 duplicate-header interpretation.
- Recorded that JP1.2/JP2.2 and JP1.3/JP2.3 are four separate CPU-routed signal nets.
- Recorded additive cross-header resistance: approximately 1.2 MΩ for the 600 kΩ pair and approximately 16 kΩ for the 8 kΩ pair.
- Promoted two independent, pin-compatible UART-style interfaces as the leading hypothesis.
- Updated the powered-capture plan to observe all four signal nodes independently.

## 0.5.0 — 2026-07-20

- Added the user-supplied J2, JP1, JP2, and SW2 resistance/continuity survey.
- Promoted J2 to a high-confidence standard MIPS14 EJTAG candidate based on the exact ground/key/VREF topology.
- Recorded a provisional signal-by-signal J2 map while retaining verification requirements.
- Initially recorded JP1 and JP2 as duplicate four-net headers; this interpretation is superseded by the v0.6.0 correction.
- Added normalized resistance maps and a safe powered-verification procedure.
- Added SW2 as an active-low control candidate; reset remains unproven.

## 0.4.0 — 2026-07-20

- Replaced the earlier block-overlay overview approach with direct photograph stitching.
- Added high-resolution stitched JPEG references for both sides of the logic board and Wi-Fi module.
- Added the alignment methodology, transform records, and working photo-stitch scripts.
- Removed the two poorly positioned archive block-overview derivatives.
- Added an explicit prohibition on generative fill, component reconstruction, and marking replacement in evidence images.
- Recorded the photographed SiGe front-end marking as `SiGe / 2547A / 2069CHF` pending independent verification.

## 0.3.0 — 2026-07-19

- Added the full 72-image `RV220W-BOARD-PHOTOS.zip` archive as extracted evidence under `evidence/photos/archive-2026-07-19/raw/`.
- Added generated derivatives:
  - full-archive contact sheet,
  - improved topside overview crop,
  - annotated topside overview,
  - bottom-side overview,
  - annotated bottom-side overview.
- Added archive index and README for the new board-photo set.
- Added `docs/19-full-board-photo-archive-review.md`.
- Updated board-layout and photo-review notes to reflect both-side board coverage and heatsink-removed documentation.
- Updated status to mark main-board underside photography complete.

## 0.2.0 — 2026-07-19

- Added exposed topside main-board photos.
- Added WLAN-module topside photos.
- Added annotated board/module maps and redacted public-safe images.
- Expanded documentation for CPU, switch, RAM, flash, J2, and WLAN RF section observations.

## 0.1.0 — 2026-07-19

- Initial Git-packaged research workspace.
- Hardware inventory, promotion plan, source index, and preservation notes.
- Initial close-up photo set and candidate chip identifications.
