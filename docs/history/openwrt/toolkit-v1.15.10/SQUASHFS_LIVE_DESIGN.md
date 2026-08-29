# RAM-only SquashFS live design

## Purpose

A conventional OpenWrt initramfs proves the kernel and early userspace.  It does not validate the intended SquashFS runtime root.  The `squashfs-live` build embeds a separately generated SquashFS image in a small initramfs launcher.

## Boot sequence

1. U-Boot TFTP-loads one ELF into RAM.
2. `bootoctlinux` starts the OpenWrt kernel.
3. The embedded initramfs mounts `devtmpfs`, proc, sysfs, and tmpfs.
4. It copies `/rv220w/rootfs.squashfs` into tmpfs.
5. It loop-mounts that image read-only at `/lower`.
6. It mounts overlayfs with tmpfs upper/work directories.
7. It moves runtime mounts into the new root.
8. It executes `switch_root /newroot /sbin/init`.

No MTD device is needed.  Rebooting discards all changes.

## Memory budget

The stock boot log reports roughly 120 MiB usable RAM.  The default U-Boot source address `0x05500000` leaves a conservative source-buffer window of approximately 42 MiB before `0x07f00000`.  The build helper rejects a larger ELF.

The live image therefore remains minimal:

- no LuCI,
- no VPN applications,
- no WLAN firmware,
- no broad package collection,
- only the filesystem modules and basic OpenWrt userspace.

If the combined image exceeds the source-buffer window, reduce packages before selecting a lower load address.  A lower address should not be chosen until U-Boot's active RAM allocations are understood.

## Failure behavior

If tmpfs, loop, SquashFS, or overlay mounting fails, the launcher prints a stage-specific error and drops to an initramfs rescue shell over JP1.  That shell is itself useful evidence.

## Validation commands after boot

```sh
mount
cat /proc/mounts
df -h
cat /etc/rv220w-build
sha256sum /run/rv220w/rootfs.squashfs
```

After rebooting into stock firmware, recalculate the complete NOR hash before any promotion to persistent storage.
