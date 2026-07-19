# Firmware acquisition and preservation

## Preferred acquisition order

1. Read through stock Linux MTD devices.
2. Read through a bootloader memory/flash command.
3. Read through verified EJTAG memory access.
4. Desolder and read the TSOP56 device externally.

## Why software dumping is preferred

The MX29GL256E is a parallel NOR on a shared CPU BootBus. In-circuit external programming risks bus contention with the CN5010 and U3 latch. A CH341A SPI programmer is not applicable.

## Linux collection

Run `scripts/target/collect_linux_inventory.sh`, then `scripts/target/dump_mtd.sh` from writable temporary storage. Copy the output off the device immediately.

## Validation requirements

- Acquire two complete images after separate reboots where possible.
- SHA-256 both images.
- Use `cmp` to confirm byte equality.
- Preserve per-partition dumps in addition to the full image.
- Record exact command output and any read errors.

## Factory-data caution

Do not overwrite regions containing:

- base MAC and MAC count;
- device serial/board identity;
- bootloader environment;
- WLAN calibration/NVRAM;
- certificates or unique keys;
- redundant configuration stores.

Public firmware images normally do not contain all factory-specific data.
