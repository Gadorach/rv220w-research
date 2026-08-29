# Platform overview

## Platform

- Cisco RV220W-A V01, PCB `YK910A-1.6`.
- Cavium OCTEON Plus CN5010-SCP pass 1.1, one active core at 400 MHz.
- 128 MiB DDR2 and 32 MiB x16 CFI parallel NOR at `0xbdc00000`.
- Broadcom BCM53115 Gigabit switch and BCM4322 Mini PCI WLAN (`14e4:432b`).
- U-Boot 1.1.1 development build revision `193M`; JP1 UART at 115200 8N1.

## OpenWrt architecture

OpenWrt `v25.12.5` with Linux 6.12.94 uses a 6 MiB compressed-kernel partition and a 25,984 KiB rootfs partition. U-Boot copies the complete kernel partition to RAM, decompresses the ELF, and launches it with `bootoctlinux`. OpenWrt mounts the SquashFS root and creates a JFFS2 `rootfs_data` child at the next erase boundary.

The combined boot-policy patch prevents vendor late initialization from replacing `bootcmd` and skips only the invalid-proprietary-image recovery branch. Holding the physical recovery button still enters Sercomm download mode.

## Network and wireless

```text
LAN1-LAN4 -> switch ports 1-4 -> CPU port 8 -> Octeon eth0 -> br-lan
WAN        -> switch port 0   -> CPU port 5 -> Octeon eth1 -> wan
BCM4322    -> PCI slot 3 INT0 -> b43 N-PHY -> phy0
```

Fresh installations expose LuCI at `http://192.168.1.1/` and enable an open 2.4 GHz `OpenWrt` AP. Configure credentials immediately.
