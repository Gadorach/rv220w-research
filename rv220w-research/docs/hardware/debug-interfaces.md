# Debug interfaces and controls

## JP1 — confirmed primary UART

Physical numbering starts at the square pad furthest from the `JP1` silkscreen.

| Pin | Function | USB-UART connection |
|---:|---|---|
| 1 | VCC/VREF | Leave disconnected |
| 2 | Target TX | Adapter RX |
| 3 | Target RX | Adapter TX |
| 4 | GND | Adapter GND |

Confirmed behavior:

- 115200 baud, 8N1.
- U-Boot and Linux console.
- Ctrl+C during firmware checking reaches `rv200w#` despite `bootdelay=0`.
- U-Boot accepts temporary 230400 and 460800 baud; 921600 is rejected.
- Never connect adapter VCC.

## JP2 — independent interface candidate

JP2 has the same resistance pattern as JP1 but its two signal pins are not directly connected to JP1. Cross-header resistance is approximately the sum of each node’s resistance to ground, proving separate CPU-routed nets rather than duplicated access.

Current hypothesis: second UART or manufacturing interface. Characterize all pins passively during a JP1-recorded cold boot before driving it.

## J2 — high-confidence MIPS14 EJTAG footprint

Assuming the boxed upper-left pad is pin 1, the electrical topology matches the common 2×7 MIPS EJTAG arrangement:

| Pin | Resistance to GND | Candidate |
|---:|---:|---|
| 1 | ~975 Ω | `TRST_N` |
| 2 | 0 Ω | GND |
| 3 | ~1.314 kΩ | `TDI` |
| 4 | 0 Ω | GND |
| 5 | OL | `TDO` |
| 6 | 0 Ω | GND |
| 7 | ~1.315 kΩ | `TMS` |
| 8 | 0 Ω | GND |
| 9 | ~1.325 kΩ | `TCK` |
| 10 | 0 Ω | GND |
| 11 | ~4.979 kΩ | `SRST_N` |
| 12 | OL | Key/NC |
| 13 | OL | `DINT` or NC |
| 14 | ~346 Ω | VREF |

Before attaching an adapter, confirm powered VREF, reset behavior, and continuity of TCK/TMS/TDI/TDO toward the CN5010. Use a target-voltage-aware adapter with target power disabled and a very low initial TCK.

## SW2 — active-low control candidate

The four-pad tactile-switch footprint has two grounded pads and two common signal pads measuring about 16 kΩ to ground. A fitted switch would ground the signal. Possible roles include recovery, boot mode, WPS, manufacturing test, or reset. Observe powered voltage and UART behavior before asserting it.

## Evidence

Canonical measurements and pinout files are under `hardware/measurements/` and `hardware/pinouts/`.
