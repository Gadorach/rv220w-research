# Changelog

## 1.4.0-r1 — 2026-08-02

- Hardware-validated the forced-`bootcmd` suppression at offset `0x13168`.
- Hardware-validated the selective invalid-magic HTTP recovery bypass at
  offset `0x13138`.
- Confirmed the combined sector CRC32 `b77a94de` and full post-write comparison.
- Confirmed saved `bootcmd` persistence across `saveenv` and reset.
- Confirmed automatic OpenWrt boot from NOR with the recovery button released.
- Confirmed the active-low physical recovery button still enters Sercomm
  download mode.
- Recorded the final environment policy: no `preboot`, `bootdelay=3`, and
  `bootcmd=run openwrt_boot`.
- Integrated the combined distribution flasher and its offline tests.
- Documented the precise distinction between hardware-validated target/runtime
  behavior and the not-yet-exercised one-step destructive combined transition
  from a completely stock sector.

## 1.4.0 — 2026-07-29

- Scanned eleven D-Link DSR/DWC Cavium source packages.
- Confirmed the complete U-Boot/`bootoctlinux` tree is absent.
- Recovered private board IDs, exact boot descriptor/bootinfo ABI and Linux
  entry-register contract.
- Added direct RV200W/RV220W TeamF1 lineage evidence.
- Documented CN50XX RGMII clock-preservation and USB-clock donor behavior.
- Added host and stage2 ELF validation, including rejection of non-empty
  `PT_NOTE` program headers.
- Added `bootabi` and `elfcheck` stage2 commands.
- Rebuilt the RAM-only stage2 ELF and expanded regressions.

## 1.3.0 — 2026-07-29

- Integrated first DWC/DSR Cavium donor-source analysis.
- Added read-only stage2 inspection commands and source-level reconstructions.

Earlier history is retained in prior release packages.
