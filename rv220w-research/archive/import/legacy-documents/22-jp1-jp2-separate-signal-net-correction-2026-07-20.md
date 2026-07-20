# JP1/JP2 separate-signal-net correction — 2026-07-20

## Electrical correction

The initial interpretation treated JP1 and JP2 as duplicate access footprints
for one four-net interface. That interpretation was incorrect.

The resistance relationship between corresponding survey rows is additive, not
near-zero:

| Nodes | Each node to GND | Cross-header measurement | Interpretation |
|---|---:|---:|---|
| high-impedance pair | approximately 600 kohm each | approximately 1.2 Mohm | Separate nodes with a meter path through ground-referenced networks |
| biased pair | approximately 8 kohm each | approximately 16 kohm | Separate nodes with a meter path through ground-referenced networks |

A direct duplicated net would read near zero ohms. Physical trace inspection
also shows the four data-signal traces routing independently toward the CPU.

## Later physical-numbering correction

The original resistance worksheet enumerated the JP1 pads from the end nearest
the `JP1` silkscreen. Confirmed physical numbering starts at the square pad,
which is furthest from the refdes. The resulting confirmed JP1 map is:

```text
JP1.1  VCC/VREF
JP1.2  target TX
JP1.3  target RX
JP1.4  GND
```

This physical pinout supersedes the earlier provisional model that called the
first listed worksheet row pin 1.

## Current model

JP1 is the confirmed primary 115200-8N1 UART. JP2 remains a separate,
similarly biased CPU-routed interface candidate; it is not redundant with JP1.
