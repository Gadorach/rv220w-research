# RV220W Stage 3 physical-port map

The run1 campaign used a true cable-free snapshot plus before/after traffic snapshots for WAN and LAN1-LAN4.

| Jack | Host-visible Octeon interface | Observed result |
|---|---|---|
| WAN | `eth1` | 90 RX packets / 7,720 RX bytes during the failed IPv4 ping window |
| LAN1 | `eth0` | 73 RX packets / 7,126 RX bytes; ping successful |
| LAN2 | `eth0` | 84 RX packets / 7,868 RX bytes; ping successful |
| LAN3 | `eth0` | 79 RX packets / 7,548 RX bytes; ping successful |
| LAN4 | `eth0` | 92 RX packets / 8,418 RX bytes; ping successful |
| none | `eth2` | no link and zero counters throughout |

All interfaces retained zero RX/TX errors and drops. The MDIO, module, MTD, device-tree, and relevant-dmesg sections were byte-identical across all eleven snapshots.

This proves the broad CPU-facing topology but does not yet identify BCM53115 management/PHY addresses, internal port numbers, CPU port numbers, or tagging mode.
