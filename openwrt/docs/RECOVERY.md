# RV220W recovery and backup notes

## Backup choices

`make u-boot-patches` offers two scopes before a bootloader write.

### Full 32 MiB NOR

Best archival option. Preserves the original vendor bootloader, firmware partitions and configuration exactly as read.

### Fast bootloader-only backup

Saves:

```text
512 KiB  boot-chain
128 KiB  U-Boot environment
640 KiB  total
```

This is warning-gated because it cannot reconstruct the original Cisco kernel/rootfs/config. It does, however, preserve every NOR region modified by the release U-Boot onboarding helper.

## Compatibility boundary

Bootloader patch compatibility is intentionally checked from the boot-chain region and known instruction state only. A full 32 MiB image is **not** expected to match between routers or vendor firmware revisions.

The helper fails closed on unknown instruction bytes or a sector that cannot reproduce the qualified patched CRC.

## Direct-installer failure boundaries

The direct initramfs installer emits phase markers. They are also useful for deciding whether it is safe to reboot after an unexpected failure.

### Failure before `RV220W_DIRECT_INSTALL_ROOTFS_BEGIN`

No rootfs write has started. Persistent kernel/rootfs should still be unchanged.

### `ROOTFS_BEGIN` without `ROOTFS_PASS`

The rootfs partition may be erased or incomplete. **Do not intentionally reboot/power-cycle.** Keep the initramfs running, preserve the UART log, and repeat/recover the rootfs write from RAM.

### `ROOTFS_PASS` without `KERNEL_PASS`

The new rootfs passed readback verification; the kernel has not yet been verified. Keep the RAM environment running and recover/retry before rebooting.

### `KERNEL_PASS` and `RV220W_DIRECT_INSTALL_PASS`

Both persistent image members passed readback SHA-256 verification. The installer will sync and reboot normally.

## Why rootfs is written first and kernel last

The existing bootable kernel remains available as long as possible. The kernel is only replaced after the complete rootfs write has succeeded and passed readback verification.

The boot-chain and final U-Boot environment are not part of the direct image installer and remain untouched.

## RAM recovery/liveboot

A prepared/patched U-Boot can always use:

```console
make initramfs-liveboot
```

and decline permanent installation. This provides a LAN-only OpenWrt recovery environment in RAM while leaving persistent kernel/rootfs untouched.

## UART ownership

If the helper says the UART is busy, close the owning terminal/process and rerun the command. Do not have multiple host tools driving RX/TX simultaneously.
