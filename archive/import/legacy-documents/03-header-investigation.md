# Header investigation

## Evidence update — 2026-07-20

See:

- `docs/21-header-resistance-survey-2026-07-20.md`
- `docs/22-jp1-jp2-separate-signal-net-correction-2026-07-20.md`
- `docs/23-confirmed-uart-uboot-and-flash-dump-2026-07-20.md`
- normalized maps under `hardware/pinout/`

## JP1 — confirmed primary UART

Physical numbering starts at the square pad, furthest from the `JP1`
silkscreen reference designator:

| Pin | Target role | USB-UART connection |
|---:|---|---|
| 1 | VCC/VREF | NC |
| 2 | TX | RX |
| 3 | RX | TX |
| 4 | GND | GND |

The console is 115200 8N1. Holding Ctrl-C during firmware checking reaches the
`rv200w# ` U-Boot prompt despite `bootdelay=0`.

Never connect USB-UART VCC to JP1.1.

## JP2 — separate CPU-routed interface candidate

JP2's two signal nodes are not duplicates of JP1:

- each high-impedance node measures about 600 kohm to GND and about 1.2 Mohm
  across headers;
- each biased node measures about 8 kohm to GND and about 16 kohm across
  headers;
- the additive cross-header relationship is consistent with two independent
  ground-referenced signal paths;
- all four signal traces route separately toward the CPU.

JP2 may be a second UART or manufacturing interface. Its physical numbering,
voltage, direction, and protocol still require powered characterization.

## J2 — high-confidence MIPS14 EJTAG candidate

J2 is a 2x7 test-pad array. Its measured topology closely matches the common
MIPS EJTAG 14-pin arrangement:

- even column: GND on pins 2/4/6/8/10, open/key at 12, candidate VREF at 14;
- odd column: seven debug/control candidates at pins 1/3/5/7/9/11/13.

Required before connection:

- powered VREF voltage;
- pin-1 orientation confirmation;
- TCK/TMS/TDI/TDO continuity or dynamic behavior;
- reset-signal behavior;
- confirmation of whether DINT is connected.

JTAG remains a recovery/debug path rather than the first acquisition method.

## SW2 — active-low control candidate

The unpopulated four-pad switch footprint has two grounded pads and two common
signal-side pads measuring approximately 16 kohm to GND. A populated switch
would ground the signal. Reset, recovery, boot mode, WPS, factory reset, and
manufacturing-test functions remain possible.
