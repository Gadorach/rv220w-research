# RV220W device-tree evidence matrix

| Device-tree decision | Confidence | Evidence and treatment |
|---|---|---|
| `model = "Cisco RV220W"` | High | U-Boot retains `CVMX_BOARD_TYPE_CUST_RV200W`; chassis and preserved firmware identity agree. |
| `compatible = "cisco,rv220w", "cavium,octeon-3860"` | High | Board identity plus CN5010/Octeon+ live boot. |
| UART0 at `0x1180000000800`, 115200 | High | Stock and modern kernels both use this console successfully. |
| MDIO controller 0 at `0x1180000001800` | High | U-Boot, passive scans and B53 runtime binding agree. |
| BCM53115 pseudo-PHY address `0x1e` | Hardware proven | B53 identifies BCM53115 revision 8 and creates the DSA tree at this address. |
| PIP interface 0, ports 0–2 | High | U-Boot reports three RGMII ports; Linux creates `eth0`–`eth2`. Per-port OF association is now exposed by the Octeon driver patch. |
| `eth0` -> BCM53115 CPU port 8 | Hardware proven | DSA creates LAN1-LAN4 on `eth0`; every LAN port passes 1000/full traffic and full-MTU ping. Use `rgmii-rxid`. |
| `eth1` -> BCM53115 CPU port 5 | Hardware proven | Passive mapping, live conduit changes, and run9 VID-0/VID-1 domains prove bidirectional WAN traffic through port 5. Use `rgmii-rxid`; patch 998 includes the firmware-described CPU port in B53 default VLAN setup. |
| `eth2` disabled | Strong board-level inference | No runtime traffic or link; mainboard has an unpopulated optional RJ45/magnetics footprint consistent with the third Octeon MAC. |
| Switch port 0 / PHY0 = WAN | High | Direct PHY link-state changes and vendor PVLAN membership prove the external WAN port. |
| Switch ports 1–4 / PHY1–4 = LAN1–LAN4 | Hardware proven | Direct PHY scans, DSA link transitions and successful traffic on every jack agree. |
| Switch ports 6–7 unused | High | No captured vendor membership, link or external function. |
| Broadcom DSA tag protocol on ports 5 and 8 | Hardware proven | Port 8 carries all LAN traffic. Run9 restores ordinary/full-MTU WAN traffic through port 5 once ordinary VLAN membership is consistent; Broadcom header control remains enabled for both CPU ports. |
| USB disabled | High | Generic USB node caused a hard boot stall; no external USB connectors are present. |
| Read-only NOR partitions | High | Offsets are proven by two dumps and modern-kernel region hashes; final environment is at `0x1fe0000`. |
| Reset/recovery input GPIO 1 active low | High but not promoted | U-Boot reads GPIO1 for recovery. Linux node remains disabled until non-destructive behavior is qualified. |
| Base MAC at NOR offset `0x6ff00` | High | U-Boot copies and validates six bytes from physical `0xbdc6ff00`. |
| GPIO LEDs | Not promoted | Ethernet LEDs are switch-controlled; logical board LED-to-pin tables remain unresolved. |
| BCM4322 Mini PCI WLAN | PCI enumeration proven; radio not promoted | Device `14e4:432b` enumerates on PCI. Driver/firmware and RF operation are deferred until the v1.9.0 full-RJ45 routed/firewalled candidate passes. |
