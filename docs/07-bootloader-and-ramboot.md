# Bootloader and RAM-boot research

## Questions the first UART log should answer

- Bootloader family and version.
- Console baud and device.
- DRAM size and clock.
- Board type/revision passed in Cavium boot info.
- BootBus chip-select and NOR geometry.
- Kernel load/entry address and image format.
- Kernel command line and rootfs selection.
- Recovery/TFTP commands.
- Environment storage location and redundancy.

## Non-destructive command policy

Initially use only information and read commands. Avoid `saveenv`, `erase`, `protect off`, `cp`, `mw`, or commands whose persistence is unclear.

## RAM-boot promotion

1. Obtain a bootloader memory map.
2. Select a load range outside bootloader, stack, FDT, and reserved memory.
3. Load a tiny known payload or initramfs kernel over TFTP/serial.
4. Verify checksum before execution.
5. Preserve the boot-info structure expected by Linux.
6. Reboot to stock firmware and confirm no persistent changes.

The Cavium Linux platform consumes an OCTEON boot-information structure containing DRAM size, clocks, board type/revision, serial data, MAC base/count, and optionally an FDT address. Preserve this handoff when replacing only the kernel.
