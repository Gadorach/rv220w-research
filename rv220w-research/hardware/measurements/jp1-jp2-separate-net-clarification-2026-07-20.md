# JP1/JP2 measurement clarification — 2026-07-20

The raw CSV's wording was initially interpreted as zero-ohm continuity between
corresponding JP1 and JP2 signal rows. The user clarified that this was not the
intended electrical result.

Correct interpretation of the two middle survey rows:

- each approximately 600 kohm-to-ground node measures approximately 1.2 Mohm
  to the corresponding node on the other header;
- each approximately 8 kohm-to-ground node measures approximately 16 kohm to
  the corresponding node on the other header;
- the approximately two-times cross-header values reflect a path through each
  signal's separate ground-referenced circuitry;
- the four signal traces route independently toward the CPU.

A later powered test confirmed JP1's physical numbering and functions:

```text
JP1.1  VCC/VREF
JP1.2  TX
JP1.3  RX
JP1.4  GND
```

The original CSV is retained unchanged as source evidence. The normalized map
records that the raw worksheet row order is the reverse of physical JP1 pin
numbering.
