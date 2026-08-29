# Flash layout and image policy

The RV220W uses 32 MiB x16 parallel CFI NOR with 128 KiB erase blocks.

```text
offset      size        name              policy
0x00000000  0x00080000  boot-chain        preserved; focused U-Boot tool only
0x00080000  0x00600000  openwrt-kernel    gzip-compressed ELF
0x00680000  0x01960000  rootfs            SquashFS plus split JFFS2 overlay
0x01fe0000  0x00020000  uboot-env          preserved; U-Boot helper only
```

The full OpenWrt layout reclaims the old stock data partition, legacy gap, and erased vendor tail into `rootfs`. A complete stock backup is therefore the only full Cisco-firmware rollback source.

The standard sysupgrade tar contains exactly `CONTROL`, `kernel`, and `root` under `sysupgrade-cisco,rv220w/`. First installation runs from initramfs and writes rootfs first, verifies it, then writes kernel last. Normal later sysupgrade preserves configuration through the platform JFFS2 insertion path.

The retained `prebuilt/` directory contains only the initramfs ELF and sysupgrade tar needed by the guided workflow. `prebuilt/SHA256SUMS` is authoritative for those files.
