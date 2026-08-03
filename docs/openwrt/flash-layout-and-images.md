# Flash layout and image policy

The board uses 32 MiB x16 parallel CFI NOR, not NAND.

## Writer partition policy

```text
0x00000000  0x00080000  boot-chain       read-only except focused sector-0 patch tool
0x00080000  0x01600000  openwrt-slot     writable only in nor-writer profile
0x01680000  0x00100000  stock-data       read-only
0x01780000  0x00020000  legacy-env-gap   read-only
0x017a0000  0x00840000  vendor-tail      read-only
0x01fe0000  0x00020000  uboot-env        read-only from Linux
```

Normal OpenWrt profiles expose every region read-only. The dedicated writer
exposes only `openwrt-slot` for writes.

## Current payload

The slot artifact is exactly 22 MiB and contains the LuCI initramfs ELF followed
by `0xff` padding. The JSON manifest records:

- source ELF path and SHA-256;
- exact `source_size`;
- padded slot size and SHA-256;
- NOR source address;
- validated RAM destination;
- generated U-Boot copy and launch commands.

The current design is not a persistent SquashFS/overlay installation and is not
a supported sysupgrade target.
