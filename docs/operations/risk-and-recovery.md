# Risk and recovery

## Required recovery material

- A verified complete 32 MiB stock NOR image for full Cisco-firmware rollback.
- JP1 serial access and a proven U-Boot interruption path.
- External parallel-NOR programming capability.
- Current 512 KiB boot-chain and 128 KiB U-Boot-environment backups before bootloader changes.
- Verified SHA-256 values for every initramfs/sysupgrade image used.

## Recovery paths

1. TFTP RAM-boot the retained initramfs without writing NOR.
2. Use the guided installer to recover valid kernel/rootfs partitions.
3. Hold the physical recovery button to enter preserved Sercomm download mode.
4. Use the U-Boot helper to verify or repair recognized boot-policy/environment states.
5. Externally restore the complete NOR when U-Boot cannot run.

## Write ordering and stop conditions

The first installer writes rootfs before kernel so the previously bootable kernel remains intact until the new rootfs passes SHA-256 readback. Stop and inspect the UART transcript if validation, rootfs, or kernel PASS markers are missing.

Never continue when U-Boot bytes or geometry are unknown, a backup hash differs, the sysupgrade image is rejected, a partition readback fails, another process owns UART, or physical-button recovery no longer works. Do not interrupt power during a confirmed write.

See [`../../openwrt/docs/RECOVERY.md`](../../openwrt/docs/RECOVERY.md) for phase-specific recovery guidance.
