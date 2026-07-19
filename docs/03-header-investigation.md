# Header investigation

## JP1 and JP2 — UART candidates

Both headers are 1×4 through-hole footprints. At least one is likely a 3.3 V CMOS UART based on the public RV220W board inventory and common Cavium board practice.

### Passive characterization

1. Disconnect power and identify ground by continuity to shield/mounting ground.
2. Power the board normally and measure every remaining pad relative to ground.
3. Probe with an oscilloscope or logic analyzer during cold boot.
4. Look for an idle-high line with immediate burst activity: probable target TX.
5. Connect only target ground and adapter RX at first.
6. Test 115200 8N1 first, then 57600, 38400, 19200, and 9600.
7. Determine target RX only after TX is proven; insert a 1–4.7 kΩ series resistor.
8. Never connect USB-UART VCC.

The square pad is probably pin 1, but this is not a functional assignment.

## J2 — probable MIPS EJTAG

J2 is a 2×7 test-pad array. A public hardware inventory reports a fourteen-pin JTAG connection on the RV220W, making EJTAG the leading hypothesis.

### Required map before connection

- Ground pads.
- VREF and target I/O voltage.
- TCK, TMS, TDI, TDO.
- TRST_N and/or SRST_N where present.
- Any no-connect or manufacturing signals.

### Safe procedure

1. Produce a resistance-to-ground table with the board unpowered.
2. Measure powered DC voltage on all pads.
3. Observe reset-time transitions.
4. Trace through resistors/vias to the CN5010 using the hardware reference manual.
5. Use a target-voltage-aware adapter and begin below 100 kHz.
6. Do not let the adapter power the target.

JTAG is a recovery/debug path, not the preferred first access method.
