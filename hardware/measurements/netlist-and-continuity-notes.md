# Netlist and continuity notes

Use this file for trace-level findings that do not yet justify a schematic.

## U4/U3 BootBus region

- U4 is the MX29GL256E parallel NOR.
- U3 is a likely 74LVC373A latch.
- Dense parallel routing runs between the U4/U3 region and the CN5010 area.
- Determine which address bits are multiplexed/latch-controlled and record U3 LE/OE sources.

## J2

No functional pins are confirmed. Record every pad using a consistent coordinate convention:

```text
J2-L1  J2-R1
J2-L2  J2-R2
...
J2-L7  J2-R7
```

## JP1/JP2

### Confirmed JP1 physical numbering — 2026-07-20

- JP1.1 is the square pad furthest from the refdes and is VCC/VREF.
- JP1.2 is target TX.
- JP1.3 is target RX.
- JP1.4 is GND, nearest the refdes.
- JP1 is the primary 115200-8N1 UART.

### Separate-net clarification

- The raw survey's ~600 kohm pair measures ~1.2 Mohm across headers.
- The raw survey's ~8 kohm pair measures ~16 kohm across headers.
- The cross-header readings are additive through separate ground-referenced paths, not direct continuity.
- All four JP1/JP2 data traces route independently toward the CPU.
- JP2 remains an independent interface candidate; do not infer its physical numbering solely from JP1.
