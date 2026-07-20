# Firmware acquisition and preservation

## Preferred acquisition order

1. Read through stock Linux MTD devices if a privileged shell becomes available.
2. Read the complete memory-mapped NOR through the confirmed U-Boot console.
3. Read through verified EJTAG memory access.
4. Desolder and read the TSOP56 device externally.

## Current immediate method

JP1 is confirmed as the primary 115200-8N1 UART: pin 1 VCC/VREF (leave NC), pin 2 target TX, pin 3 target RX, and pin 4 GND. U-Boot can be interrupted with Ctrl-C despite `bootdelay=0`. Use:

```text
scripts/host/dump_uboot_flash_uart.py
```

The script reads the full range:

```text
0xbdc00000..0xbfc00000 exclusive
```

using `md.b` and validates it using target-side `crc32`. See
`docs/24-uboot-flash-dump-over-uart.md`.

## Why software dumping is preferred

The MX29GL256E is a parallel NOR on a shared CPU BootBus. In-circuit external
programming risks bus contention with the CN5010 and U3 latch. A CH341A SPI
programmer is not applicable.

## Linux collection

Run `scripts/target/collect-linux-inventory.sh`, then
`scripts/target/dump-mtd.sh` from writable temporary storage. Copy the output
off the device immediately.

Do not assume that the Linux command-line MTD partition named `bootload-env`
contains the active U-Boot environment. U-Boot's `env_addr` points instead to
the final flash sector at `0xbfbe0000`. A physical full-flash dump is mandatory.

## Validation requirements

- Acquire two complete images after separate reboots where possible.
- Require matching target and host CRC32 for each acquisition.
- SHA-256 both images.
- Use `cmp` to confirm byte equality.
- Preserve per-partition dumps in addition to the full image.
- Preserve the UART transcript and JSON session metadata.
- Record exact command output and any retries/read errors.

## Factory-data caution

Do not overwrite regions containing:

- base MAC and MAC count;
- device serial/board identity;
- either environment-like 128 KiB region;
- WLAN calibration/NVRAM;
- certificates or unique keys;
- redundant configuration stores;
- the kernel-unpartitioned tail from `0xbf3a0000` through `0xbfbe0000`.

Public firmware images normally do not contain all factory-specific data.
