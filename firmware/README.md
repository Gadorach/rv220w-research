# Firmware artifacts

## Preserved stock images

- `images/rv220w-flash-32MiB-canonical.bin` — canonical complete NOR image.
- `images/RV220W-Firmware-1.0.4.17-recovered.img` — recovered stock upgrade image.
- `partitions/` — seven non-overlapping physical regions.
- `derived/` — overlapping boot stub, U-Boot, firmware header, and Linux ELF objects.
- `filesystems/` — extracted stock SquashFS and sensitive JFFS2 trees.
- `analysis/` — structured manifests and reverse-engineering reports.

## Current boot-chain reconstruction

`reconstruction/` contains v1.4.0-r1 U-Boot and stock-module reconstruction,
combined boot-policy patch artifacts, the distribution flasher, tests, and
hardware-validation logs. Its focused patch path is required before automatic
OpenWrt boot from the firmware slot.

Authoritative stock full-image checksum:

```text
SHA-256 03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5
CRC32   ce96f3e0
```
