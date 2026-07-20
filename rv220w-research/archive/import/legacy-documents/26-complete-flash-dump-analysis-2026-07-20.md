# Complete 32 MiB flash dump analysis — 2026-07-20

## Capture integrity

The dump is complete and internally validated:

- Size: `0x02000000` / 33,554,432 bytes
- Host CRC32: `ce96f3e0`
- Target CRC32 before capture: `ce96f3e0`
- Target CRC32 after capture: `ce96f3e0`
- SHA-256: `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5`
- 512 × 64 KiB chunks
- Zero retries in the completed v0.8.1 run

This is strong evidence that the image is a faithful read of the complete NOR contents. A second independently captured image is still recommended before any flash write.

## Physical and logical map

| Flash offset | Size | Contents |
|---:|---:|---|
| `0x00000000` | `0x30000` | Early boot stub / stage 1 |
| `0x00030000` | `0x50000` | U-Boot proper |
| `0x00080000` | `0x600000` | Kernel partition: 512-byte firmware header, ELF64 kernel and padding |
| `0x00680000` | `0x1000000` | Big-endian SquashFS 3.0 rootfs |
| `0x01680000` | `0x100000` | Big-endian JFFS2 data/config |
| `0x01780000` | `0x20000` | Linux command-line partition named `bootload-env`; erased |
| `0x017a0000` | `0x840000` | Erased/unmapped vendor tail |
| `0x01fe0000` | `0x20000` | Actual U-Boot environment sector from `env_addr=0xbfbe0000` |

The Linux `bootload-env` partition and U-Boot's real environment are **not the same sector**. The bootloader reports a bad environment CRC and uses compiled defaults. Do not run `saveenv` until the final sector is preserved and understood.

## Bootloader region

The first 512 KiB divides cleanly according to U-Boot's own variables:

- `0x00000000–0x0002ffff`: early boot/stage-1 material
- `0x00030000–0x0007ffff`: U-Boot proper

The U-Boot banner occurs inside the second region. The first four 128 KiB sectors were shown read-only by `flinfo`; this overlaps stage 1 and the first part of U-Boot.

## Firmware container and kernel

The stock upgrade image can be recovered byte-for-byte beginning at flash offset `0x00080000`.

Header observations:

- Header size in flash: 512 bytes
- Header's declared image size: `0x01528080` / 22,184,064 bytes
- Version: `1.0.4.17`
- Hardware version: `1.0`
- Family: `RV220W-Firmware`
- Build time: `Thu Jul 12 12:04:51 2012`
- Name: `RV220W-Firmware-1.0.4.17.img`
- Trailer marker: `FWCHKADDISABABA\n`, located 128 bytes before image end

The 32-bit big-endian value at header offset `0x14` is confirmed to be an additive byte checksum over the complete declared image while the checksum field itself is treated as zero. It recomputes exactly to `0x9ca9c3e0`. The purposes of header fields at `0x04` and `0x08` remain unresolved.

The kernel begins at flash offset `0x00080200` and is a complete ELF64 big-endian MIPS executable:

- Octeon / MIPS64r2 flags
- Entry point `0xffffffff804b0000`
- One loadable segment
- Complete ELF extent: `0x573160` bytes, including all 33 section headers

The stock boot command copies `0x580000` bytes beginning at the firmware header to RAM at `0x02a00000`, then invokes `bootoctlinux` at `0x02a00200`. Thus the 512-byte vendor header is retained in the RAM copy and the ELF begins at the address passed to `bootoctlinux`.

## Root filesystem

The rootfs partition is:

- SquashFS version 3.0
- Big-endian
- 4,060 inodes
- 64 KiB data block size
- 298 fragments
- Filesystem bytes used: `0x00f27cfa` / 15,891,706
- Created `2012-07-12T06:34:50Z`

The extracted current tree contains:

- 3,789 regular files
- 86 directories
- 185 symbolic links
- Approximately 51 MiB of regular-file data

The rootfs contains the stock userspace, unstripped Octeon kernel modules, switch-management scripts, proprietary Broadcom WLAN driver, web UI, VPN services, and factory configuration database.

## JFFS2 data partition

The current JFFS2 tree after factory reset contains:

- `tmp/logs.ascii`
- `tmp/https.crt`
- `tmp/https.key`
- `tmp/factoryDefault`
- `tmp/bonjourInterfaceList`

A deleted latest dirent for `tmp/teamf1.cfg.ascii` explains why the reset boot selected defaults. The partition contains a device/private TLS key and logs; treat both raw and extracted forms as sensitive.

## Actual environment sector and vendor tail

The Linux-named environment partition is fully erased. The unmapped tail before the actual environment sector is also erased in this unit. The real final 128 KiB sector is nearly erased and fails its environment CRC, consistent with the U-Boot warning. The final 16 bytes are not `0xff`:

```text
00 00 c0 7f 10 00 90 f7 65 52 63 4f 6d 4d 00 00
```

Their function is unknown. Preserve them exactly; do not assume they are disposable merely because the environment CRC is bad.

## Extraction artifacts

The analysis tools generate:

- non-overlapping physical partitions,
- boot stub and U-Boot subregions,
- exact stock update image,
- complete Linux ELF,
- firmware header report,
- SquashFS superblock report,
- JFFS2 current-tree report,
- full hash manifest.

See `scripts/host/analyze_extract_rv220w_flash.py`, `scripts/host/extract_jffs2_be.py`, and `hardware/flash/partition-map.csv`.
