# Bootloader, RAM boot, and persistent launch

## U-Boot baseline

The board uses U-Boot 1.1.1 with 32 MiB of parallel NOR at `0xbdc00000` and qualified RAM staging addresses at `0x05500000` and `0x06500000`. Ctrl+C during startup reaches the `rv200w#` prompt.

## TFTP/RAM boot

The release helper interrupts U-Boot, sets temporary networking variables, TFTP-loads the installer ELF, and invokes `bootoctlinux`. This is a non-persistent recovery and validation path until the operator accepts the separate install prompt.

## Persistent launch

The 6 MiB kernel partition begins at `0xbdc80000` and contains a gzip-compressed ELF. The qualified environment uses:

```text
cp.b 0xbdc80000 0x05500000 0x600000
gunzip 0x05500000 0x600000 0x06500000 0x1a00000
bootoctlinux 0x06500000 console=ttyS0,115200
```

The fixed partition copy length replaces the old initramfs design's image-specific ELF byte count. The combined boot-policy patch and environment remain prerequisites for automatic startup.

Use `make -C openwrt u-boot-verify` for a read-only check and `make -C openwrt u-boot-patches` for the guarded backup/repair workflow.
