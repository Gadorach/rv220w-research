# RV220W full OpenWrt persistent flash layout

## Approved v1.12.0 layout

| Offset | Size | Name | Policy |
|---:|---:|---|---|
| `0x00000000` | `0x00080000` | `boot-chain` | read-only |
| `0x00080000` | `0x00600000` | `openwrt-kernel` | guarded maintenance write |
| `0x00680000` | `0x01960000` | `rootfs` | padded SquashFS plus automatic JFFS2 split |
| `0x01fe0000` | `0x00020000` | `uboot-env` | read-only to Linux |

All boundaries are aligned to the 128 KiB NOR erase size. The rootfs partition
is 25.375 MiB (`25984 KiB`) and ends immediately before the real U-Boot
environment.

## Reclaimed stock regions

The following former stock regions are now part of `rootfs`:

| Original offset | Size | Previous role |
|---:|---:|---|
| `0x01680000` | `0x00100000` | Cisco big-endian JFFS2 data/config |
| `0x01780000` | `0x00020000` | misleading Linux-named environment gap; blank |
| `0x017a0000` | `0x00840000` | unmapped vendor tail; blank |

The complete 32 MiB NOR dumps preserve all original bytes. The Cisco JFFS2
partition is also independently extracted as `03-data.jffs2-be.bin`.

## Kernel command line

```text
mtdparts=phys_mapped_flash:512k(boot-chain)ro,6m(openwrt-kernel),25984k(rootfs),128k(uboot-env)ro
root=/dev/mtdblock2 rootfstype=squashfs
```

The RAM writer uses the same map without `root=` and remains initramfs-rooted.

## Automatic overlay

The rootfs partition image contains the unpadded SquashFS source followed by
`0xff` through the end of the 25.375 MiB partition. OpenWrt aligns the end of
SquashFS to the next 128 KiB erase boundary and creates one `rootfs_data` child
from that boundary through `0x01fe0000`.

For the hardware-built v1.11.8 SquashFS source size `0x003ff1e4`, the expected
split is:

```text
0x00680000-0x00a7ffff  SquashFS area, padded to 4 MiB
0x00a80000-0x01fdffff  rootfs_data, 0x01560000 bytes (21.375 MiB)
```

A full rootfs write therefore resets the overlay. A separate overlay erase is
neither required nor safe as a standalone layout operation.


## v1.13.0 sysupgrade policy

The sysupgrade archive contains the unpadded gzip kernel and unpadded SquashFS
root. Runtime stage2 erases the entire physical rootfs before writing the
SquashFS, so the automatic JFFS2 child is recreated without stale nodes. With
configuration preservation enabled, `mtd -j` inserts the standard sysupgrade
backup into the fresh JFFS2 area. Rootfs is verified before the 6 MiB kernel is
erased, written and verified. `boot-chain` and `uboot-env` remain outside every
write command.
