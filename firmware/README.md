# Firmware artifacts

## Images

- `images/rv220w-flash-32MiB-canonical.bin` — canonical full NOR image reconstructed from the independently verified physical partition set.
- `images/RV220W-Firmware-1.0.4.17-recovered.img` — exact stock upgrade image recovered from flash.

## Partitions

`partitions/` contains the seven non-overlapping physical regions that concatenate into the canonical full image.

## Derived components

`derived/` contains overlapping analysis objects such as the boot stub, U-Boot proper, firmware header, complete Linux ELF, and exact boot-copy range.

## Filesystems

- `filesystems/rootfs/` — extracted stock SquashFS 3.0 tree.
- `filesystems/data-jffs2/` — unredacted factory-reset JFFS2 tree, including obsolete HTTPS key material.

## Analysis

- `analysis/manifests/` — compact structured metadata.
- `analysis/reports/` — readelf, strings, module reports, file lists, and flash-map analysis.

Authoritative full-image checksum:

```text
SHA-256 03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5
CRC32   ce96f3e0
```
