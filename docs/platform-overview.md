# Platform overview

## Platform

- Cisco RV220W-A V01, PCB `YK910A-1.6`.
- Cavium OCTEON Plus CN5010-SCP pass 1.1, one active core at 400 MHz.
- 128 MiB DDR2.
- 32 MiB x16 CFI parallel NOR at `0xbdc00000`.
- Broadcom BCM53115 Gigabit switch.
- Broadcom BCM4322 Mini PCI WLAN, PCI ID `14e4:432b`.
- U-Boot 1.1.1 development build revision `193M`.
- JP1 UART at 115200 8N1.

## Current OpenWrt architecture

OpenWrt 25.12.5 with Linux 6.12.94 is stored as an ELF in the 22 MiB
`openwrt-slot` beginning at NOR offset `0x00080000`. U-Boot cannot execute this
Linux ELF directly in place with `bootoct`; it copies the exact ELF byte count
to RAM at `0x05500000` and launches it with `bootoctlinux`.

The combined boot-policy patch is a prerequisite for automatic boot. It stops
the vendor late-init routine from replacing the saved `bootcmd` and skips only
the invalid-proprietary-image HTTP recovery branch. Physical-button Sercomm
recovery remains functional.

## Wired topology

```text
LAN1-LAN4 -> switch ports 1-4 -> CPU port 8 -> Octeon eth0 -> br-lan
WAN        -> switch port 0   -> CPU port 5 -> Octeon eth1 -> wan
```

Both CPU links use `rgmii-rxid`. LuCI is LAN-only at
`http://192.168.240.2/` in the current profile.

## Persistence boundary

The firmware ELF is persistent in NOR, but it is an initramfs image. Runtime
configuration is volatile and returns to image defaults at every boot. A
persistent writable overlay and supported sysupgrade format remain future work.
