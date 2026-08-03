# RV220W bootloader proof of concept — v1.4.0-r1

This directory contains the RAM-resident stage2 monitor, byte-exact vendor
boot-chain reconstruction, hardware-validated policy patches and a focused
combined distribution flasher.

## Hardware-validated vendor boot-chain policy

```text
0x13138: 10 00 00 03  skip invalid-format Sercomm HTTP recovery
0x13168: 03 e0 00 08  return without overwriting bootcmd
sector-0 CRC32: b77a94de
```

Validated behavior:

- saved custom `bootcmd` persists;
- normal released-button startup boots OpenWrt despite proprietary-header
  rejection;
- the active-low physical recovery button still launches Sercomm download mode.

The integrated tool is located at:

```text
flash-tools/rv220w-combined-boot-policy-patch-flasher-v1.0.0/
```

Read `docs/COMBINED-BOOT-POLICY-PATCH-HARDWARE-VALIDATION.md` before use.

## RAM stage2 status

The monitor is linked at `0xffffffff84000000` and uses direct UART0. It provides
read-only inspection, hashing, checked DRAM copies and a vendor-loader callgate.
It has no NOR erase/program, `saveenv`, GPIO write, MDIO write or CSR write
surface.

The stage2 ELF remains untested on hardware. Its status is independent of the
validated vendor-sector policy patches.
