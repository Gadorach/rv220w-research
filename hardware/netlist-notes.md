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

Number from square pad upward until continuity proves a different convention.
