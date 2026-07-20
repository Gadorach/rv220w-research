# Header and switch resistance survey — 2026-07-20

## Source evidence

The user supplied an unpowered resistance-to-ground survey for J2, JP1, JP2,
and SW2:

- `evidence/measurements/pin-assumptions-RV220W-2026-07-20.csv`

Normalized maps:

- `hardware/pinout/j2-resistance-map-2026-07-20.csv`
- `hardware/pinout/jp1-jp2-resistance-map-2026-07-20.csv`
- `hardware/pinout/sw2-resistance-map-2026-07-20.csv`

The raw JP1 worksheet was recorded from the end nearest the `JP1` refdes. The
later confirmed physical numbering starts at the square pad at the opposite
end. Raw survey rows 1–4 therefore correspond to physical JP1 pins 4–1.

## J2 finding

J2 has five consecutive ground positions in one column, followed by an open/key
position and a probable VREF position. The opposite column contains seven
non-ground positions. Under the assumed pin-1 orientation this closely matches
the conventional 14-pin MIPS EJTAG topology.

This promotes J2 from probable-by-geometry to high-confidence-by-electrical-
topology, but powered VREF and active signals remain unconfirmed.

## JP1 finding — now confirmed

After correcting physical numbering, the measured and observed JP1 map is:

| Physical pin | Resistance to GND | Confirmed function |
|---:|---:|---|
| 1 | ~346 ohm | VCC/VREF; leave adapter VCC disconnected |
| 2 | ~8 kohm | Target TX |
| 3 | ~600 kohm | Target RX |
| 4 | 0 ohm | GND |

JP1 is the primary 115200-8N1 U-Boot/Linux UART.

## JP1/JP2 separate-net finding

The matching middle survey rows on JP1 and JP2 are not directly connected:

- each ~600 kohm-to-ground node measures about 1.2 Mohm to its counterpart;
- each ~8 kohm-to-ground node measures about 16 kohm to its counterpart.

These approximately additive readings indicate two independent signal nodes
connected only through their separate ground-referenced circuitry. Trace
inspection also shows the four data-signal traces routing separately toward the
CPU.

JP2 remains a second-UART/manufacturing-interface candidate. Its physical
numbering and protocol should be verified independently rather than inferred
from JP1.

## SW2 finding

SW2 consists of a ground side and a common signal side measuring approximately
16 kohm to ground. A fitted switch would ground the signal. Reset, recovery,
boot-mode, WPS, and manufacturing-test functions remain possible.

## Promotion impact

1. JP1 console promotion is complete.
2. Record powered JP1.1 voltage without attaching adapter VCC.
3. Characterize JP2 passively during a JP1-captured cold boot.
4. Record powered J2 VREF and active debug signals before attaching JTAG.
5. Preserve the complete flash through U-Boot before active experiments.
