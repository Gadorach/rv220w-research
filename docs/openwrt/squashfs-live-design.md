# RAM-only SquashFS live design

## Purpose

Validate a SquashFS-based userspace without writing NOR and without requiring the modern kernel to understand the stock flash layout during the first boot.

## Boot sequence

1. U-Boot TFTP-loads a big-endian Octeon ELF.
2. The kernel starts with a minimal initramfs.
3. The initramfs copies the embedded SquashFS image into tmpfs.
4. It loop-mounts the SquashFS read-only.
5. It creates tmpfs-backed overlay upper/work directories.
6. It mounts overlayfs and preserves the read-only lower tree as `/rom`.
7. It uses `switch_root` into the live OpenWrt system.

## Safety properties

- No NOR root mount.
- No persistent overlay.
- Reboot discards all changes.
- Failure returns to the initramfs emergency shell rather than writing storage.

## Memory budget

The board has 128 MiB installed and roughly 120 MiB available to the stock kernel. Keep the kernel, initramfs launcher, embedded SquashFS, copied SquashFS, tmpfs overlay, and runtime memory comfortably below that limit. Strip LuCI, WLAN, VPN suites, and nonessential packages from the first image.
