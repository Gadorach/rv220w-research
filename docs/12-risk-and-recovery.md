# Risk and recovery plan

## Highest-risk actions

- Driving unknown header pins.
- Attaching 5 V UART logic.
- Letting a JTAG adapter power the board.
- Flash erase/program commands before a full verified backup.
- In-circuit parallel-NOR programming with active bus masters.
- Removing heatsinks or TSOP flash without thermal/rework control.
- Publishing configuration dumps containing keys or identifiers.

## Recovery tiers

1. **Normal reboot:** stock firmware remains unchanged.
2. **Bootloader recovery:** TFTP/serial load and flash restore.
3. **EJTAG recovery:** halt CPU, load recovery stub, read/program BootBus.
4. **External flash recovery:** remove or isolate U4 and program with a verified TSOP56 parallel-NOR programmer.
5. **Board replacement:** spare unit or donor board.

Do not begin persistent firmware work until at least one tier beyond normal boot has been tested.
