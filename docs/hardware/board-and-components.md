# Board and component inventory

## Identity

- Product: Cisco RV220W Wireless-N Network Security Firewall.
- Label: `RV220W-A V01`.
- PCB: `YK910A-1.6`, marked “Manufactured for Cisco.”

## Major components

| Area/refdes | Marking | Function | Confidence |
|---|---|---|---:|
| CPU | `CN5010-400BG564-SCP-G` | Cavium OCTEON Plus networking SoC | Confirmed |
| U6/U12 | `EM68B16CWQD-25H` | 32M×16 DDR2, 64 MiB each | Confirmed |
| U4 | `MX29GL256EHT2I-90Q` | 32 MiB 3 V x16 parallel NOR | Confirmed |
| Switch | `BCM53115SKFBG` | Five-port Gigabit RoboSwitch | Confirmed |
| WLAN | `BCM4322LKFBG` | Full-size Mini PCI 802.11a/b/g/n controller | Confirmed |
| U3 | `LC373A ... G4` | TI SN74LVC373A-class octal latch; likely BootBus glue | High inference |
| U11 | `840A125L` | 125 MHz Ethernet clock source | High inference |
| U23 | `8809 DEHA` | AME8809-family LDO | High inference |
| Magnetics | `HN4821CG` ×2, `HN2411CG` ×1 | Five Ethernet-port isolation transformers | Confirmed |

## Layout

- Ethernet connectors and magnetics occupy the jack edge.
- BCM53115 is between the magnetics and CN5010, consistent with a direct CPU/IMP-port connection.
- The DDR2 devices sit adjacent to the CN5010 with length-matched routing.
- U4 and U3 occupy the BootBus/parallel-flash region.
- J2 is close to the CPU/memory side and electrically matches a MIPS14 debug header.
- Power conversion is distributed around the DC input, CPU, and Mini PCI socket.

## Clock and power targets

Characterize at minimum:

- DC input rail.
- 3.3 V I/O/Mini PCI rail.
- DDR2 1.8 V and termination/reference rails.
- CN5010 core rail.
- BCM53115 core and I/O rails.
- 25 MHz switch reference and 125 MHz Ethernet clock.
- CN5010 reference clock and WLAN crystal.

## Reset targets

Trace and observe:

- populated hardware reset button,
- SW2 unpopulated active-low switch footprint,
- CN5010 reset,
- BCM53115 reset,
- Mini PCI reset,
- J2 candidate `SRST_N` and `TRST_N`.
