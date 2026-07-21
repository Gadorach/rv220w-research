# Cisco RV220W reverse-engineering workspace

This repository consolidates the Cisco RV220W research package into one coherent workspace. It covers the physical board, debug interfaces, verified firmware capture, extracted filesystems, stock software architecture, and an OpenWrt promotion toolkit for CachyOS.

The source unit is a retired display/research device. The archive therefore retains the full factory-reset JFFS2 contents, including the original HTTPS certificate and private key. Nothing in the canonical package is redacted, but the key is obsolete and must not be reused.

## Confirmed platform

| Subsystem | Identification |
|---|---|
| Board | Cisco RV220W-A V01, PCB `YK910A-1.6` |
| CPU | Cavium OCTEON Plus `CN5010-400BG564-SCP-G`, pass 1.1, 400 MHz |
| RAM | 2 × Etron `EM68B16CWQD-25H`, 128 MiB total, DDR2-532 data rate |
| NOR | Macronix `MX29GL256EHT2I-90Q`, 32 MiB, x16 CFI parallel flash |
| Ethernet switch | Broadcom `BCM53115SKFBG` |
| WLAN | Full-size Mini PCI Broadcom `BCM4322LKFBG`, PCI ID `14e4:432b` |
| Bootloader | U-Boot 1.1.1 development build, revision `193M`, 2012-06-14 |
| Stock kernel | Linux 2.6.21.7-Cavium-Octeon, big-endian MIPS64 |
| Primary UART | JP1, 115200 8N1; temporary 230400/460800 supported |

## Verified firmware baseline

Two independent UART acquisitions matched byte-for-byte:

```text
Size:    0x02000000 / 33,554,432 bytes
CRC32:   ce96f3e0
SHA-256: 03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5
```

The canonical image in `firmware/images/rv220w-flash-32MiB-canonical.bin` is reconstructed from the verified non-overlapping partition images and has the same SHA-256.

## Workspace map

- `docs/` — canonical documentation. Start with [`docs/README.md`](docs/README.md).
- `hardware/` — BOM, pinouts, resistance measurements, flash map, and worksheet templates.
- `evidence/` — photographs, stitches, measurement evidence, and dump-validation records.
- `firmware/` — canonical flash image, stock upgrade image, partitions, derived components, extracted filesystems, and analysis reports.
- `tools/` — one canonical copy of each UART, extraction, evidence, target, and photo-stitching tool.
- `openwrt/` — CachyOS/Distrobox build and TFTP live-boot toolkit. Start with [`openwrt/README.md`](openwrt/README.md).
- `sources/` — source links and GPL request material.
- `tests/` — regression tests for the UART dumper and future tooling.
- `archive/import/` — import provenance and mapping from the earlier package.

## Safe next milestone

The next useful milestone remains a RAM-only OpenWrt initramfs ELF loaded through U-Boot/TFTP. Do not write NOR until serial boot, TFTP transport, board identity, Ethernet mapping, and recovery have been validated.

```fish
cd openwrt
./rv220w.fish doctor
./rv220w.fish setup-box
./rv220w.fish prepare-sources
./rv220w.fish build initramfs
./rv220w.fish tftp-boot --interface <direct-link-interface> --configure-interface <image.elf>
```

## Licensing

The consolidated research code and documentation use the repository MIT license unless a subdirectory states otherwise. The OpenWrt promotion toolkit retains its GPL-3.0 license in `openwrt/LICENSE.GPL-3.0`. Vendor firmware and extracted binaries remain subject to their original terms.
