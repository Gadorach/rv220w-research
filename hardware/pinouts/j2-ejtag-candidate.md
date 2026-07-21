# J2 — 14-pin MIPS EJTAG candidate

## Current status

The 2026-07-20 unpowered resistance survey substantially strengthens the EJTAG hypothesis. If the boxed upper-left J2 pad is pin 1 and the two columns are numbered in the conventional odd/even pattern, the measured topology matches the common MIPS EJTAG 2×7 layout almost exactly:

| Candidate pin | Measurement to GND | Candidate function | Status |
|---:|---:|---|---|
| 1 | 975 Ω | `TRST_N` | Candidate |
| 2 | 0 Ω | GND | Confirmed ground |
| 3 | 1.314 kΩ | `TDI` | Candidate |
| 4 | 0 Ω | GND | Confirmed ground |
| 5 | OL | `TDO` | Candidate |
| 6 | 0 Ω | GND | Confirmed ground |
| 7 | 1.315 kΩ | `TMS` | Candidate |
| 8 | 0 Ω | GND | Confirmed ground |
| 9 | 1.325 kΩ | `TCK` | Candidate |
| 10 | 0 Ω | GND | Confirmed ground |
| 11 | 4.979 kΩ | `SRST_N` | Candidate |
| 12 | OL | Key / NC | Strong match |
| 13 | OL | `DINT` | Candidate / possibly NC |
| 14 | 346 Ω | `VREF` | Strong candidate |

This is now a **high-confidence MIPS14 footprint match**, not merely a geometry-based guess. Individual active signal names remain provisional until continuity or powered behavior confirms them.

## Evidence files

- `hardware/measurements/pin-assumptions-RV220W-2026-07-20.csv`
- `hardware/pinouts/j2-resistance-map.csv`

## Required confirmation before attaching an adapter

1. Measure powered voltage on candidate pin 14 and confirm the actual target I/O voltage.
2. Confirm that candidate pin 12 remains unconnected or is physically absent/keyed.
3. Observe candidate pin 11 during reset to verify `SRST_N` behavior.
4. Continuity-trace candidate TCK/TMS/TDI/TDO pads through their series resistors toward the CN5010.
5. Verify TDO is not driven above the adapter's permitted voltage.
6. Use a voltage-sensing adapter with target power output disabled and begin at a very low TCK rate.

Do not infer that 346 Ω to ground is a safe power-source impedance. The adapter must sense VREF only and must not power the board.
