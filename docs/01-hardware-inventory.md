# Hardware inventory

## Board identity

- Product: Cisco RV220W Wireless-N Network Security Firewall.
- Product label: `RV220W-A V01`.
- PCB marking: `YK910A-1.6`, “Manufactured for Cisco.”
- Evidence: `evidence/photos/original/board-overview.jpg`.

## Major components

| Ref./area | Marking | Interpretation | Confidence | Notes |
|---|---|---|---:|---|
| CPU, under central heatsink | `CN5010-400BG564-SCP-G` | Cavium OCTEON Plus single-core 400 MHz MIPS64/32 SoC | High | User-recorded top marking; independently reported for RV220W. |
| U6, U12 | `EM68B16CWQD-25H` | 32M×16 DDR2 each, 64 MiB each | High | Two devices form a 32-bit-wide 128 MiB memory subsystem. |
| U4 | `MX29GL256EHT2I-90Q` | 256 Mbit / 32 MiB 3 V parallel NOR | High | Main firmware storage; not SPI flash. |
| Switch, under upper-left heatsink | `BCM53115SKFBG` | Five-port Gigabit RoboSwitch with integrated PHYs | High | Four LAN + one WAN topology is consistent. |
| Removable WLAN card | `BCM4322LKFBG` | Mini PCI dual-band 802.11a/b/g/n | High | Defer until wired platform is stable. |
| U3 | `LC373A ... G4` | Likely TI SN74LVC373A octal transparent latch | Medium-high | Placement beside U4 suggests BootBus address/data latching. |
| U11 | `840A125L` | Likely ICS840-125 125 MHz oscillator replacement | Medium-high | Located near 25 MHz crystal and network logic. |
| U23 | `8809 DEHA` | Likely AME8809-family 600 mA CMOS LDO | Medium-high | Confirm output voltage at C314/C3151/C316/C313. |
| Magnetics ×2 | `HN4821CG` | Likely dual-port Gigabit Ethernet transformer modules | Medium-high | Two modules cover four ports. |
| Magnetics ×1 | `HN2411CG` | Likely single-port Gigabit Ethernet transformer | Medium-high | Likely WAN port. |

## Clock observations

- Y3 and Y4 are marked 25.000 MHz.
- U11 likely synthesizes or buffers 125 MHz for Gigabit Ethernet logic.
- Additional oscillators U13 and U84 are visible but not yet identified.

## Power observations

Visible switching inductors and multiple LDO/buck areas indicate separate rails likely including:

- input-derived intermediate rail;
- 3.3 V I/O/flash rail;
- 2.5 V DDR-related rail;
- 1.8 V DDR2 rail;
- CPU core rail;
- switch core/analog rails.

These voltage assignments are hypotheses until measured.
