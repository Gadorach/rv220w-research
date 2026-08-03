# RV220W device-tree evidence matrix

| Device-tree decision | Confidence | Evidence and treatment |
|---|---|---|
| `model = "Cisco RV220W"` | High | U-Boot retains `CVMX_BOARD_TYPE_CUST_RV200W`; chassis and preserved firmware identity agree. |
| `compatible = "cisco,rv220w", "cavium,octeon-3860"` | High | Board identity plus CN5010/Octeon+ live boot. |
| UART0 at `0x1180000000800`, 115200 | High | Stock and modern kernels both use this console successfully. |
| MDIO controller 0 at `0x1180000001800` | High | Stock module and U-Boot low-level MDIO operations agree. |
| BCM53115 pseudo-PHY address `0x1e` | High | Independently recovered from U-Boot and `bcm5398.ko`/`mii.ko`. Node remains disabled pending DSA topology proof. |
| PIP interface 0, ports 0–2 | High | U-Boot reports three RGMII ports; Linux creates `eth0`–`eth2`. |
| Fixed 1000/full on PIP ports 0 and 1 | Medium-high | This was present in the working generic live tree; both interfaces reported 1000/full. Exact external role of port 1 remains unproven. |
| USB disabled | High | Generic USB node caused a hard boot stall; `usbcore.nousb` eliminated it; no external USB connectors are present. |
| DT BootBus disabled | High for safety | U-Boot leaves working timing, and legacy Linux reads the x16 32 MiB NOR stably. Exact timing need not be guessed for this stage. |
| Read-only NOR partitions | High | Offsets are proven by two dumps and modern-kernel region hashes; final environment is at `0x1fe0000`, not the stock Linux label at `0x1780000`. |
| Reset/recovery input GPIO 1 active low | High | U-Boot configures input 1, reads it, prints `PUSH_BUTTON`, and enters recovery when zero. Linux node remains disabled. |
| Base MAC at NOR offset `0x6ff00` | High | U-Boot copies and validates six bytes from physical `0xbdc6ff00`. OpenWrt continues using bootloader-provided MAC fixups in this revision. |
| GPIO LEDs | Not promoted | Stock LED module proves GPIO control exists, but logical LED-to-pin tables remain unresolved. Ethernet LEDs are BCM53115 hardware LEDs. |
| WAN/LAN1–4 DSA port numbers | Not promoted | Switch module contains WAN variants 5/8 and Broadcom tagging, but exact RV220W internal mapping and IMP port are not yet proven. |
