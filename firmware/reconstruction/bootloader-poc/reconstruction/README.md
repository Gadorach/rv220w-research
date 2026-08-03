# Clean-room board reconstruction

These files express the behavior recovered from the RV220W binary in readable C.
They are documentation and implementation scaffolding, not decompiled vendor
source and not currently a cold-start bootloader.

- `rv220w_vendor_late_init.c` maps the recovered late-board initialization,
  firmware-recovery branch, and forced `bootcmd` tail call.
- `sercomm_firmware_check.c` records the proven wrapper layout and additive
  checksum algorithm.
- `rv220w_board_reconstruction.h` centralizes the hardware-proven constants and
  recovered vendor function addresses.

Unresolved calls are deliberately named by observed effect rather than assigned
false identities. The next reconstruction gate is a RAM-run stage2 monitor, then
an independently linked Linux ELF loader, and only afterward cold-start DDR and
BootBus initialization.
