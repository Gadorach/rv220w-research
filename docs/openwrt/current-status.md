# Current OpenWrt status

## Hardware-qualified

- OpenWrt `v25.12.5`, release `1.16.0-rc7`, Linux 6.12.94.
- Automatic compressed-kernel boot through the patched stock U-Boot chain.
- Persistent SquashFS root with split JFFS2 `rootfs_data` overlay.
- LuCI at `http://192.168.1.1/`, immutable package management, and configuration-preserving sysupgrade.
- LAN1-LAN4, independent WAN, DHCP, firewall4, routing/NAT, and BCM53115 DSA.
- BCM4322/b43 physical-SPROM initialization and 2.4 GHz AP/client operation.
- POWER, DIAG, WLAN, and DMZ GPIO LEDs.
- Guarded direct installer with streamed validation, rootfs-first/kernel-last writes, and SHA-256 readback.
- Physical-button Sercomm recovery retained.

## Release boundary

The production configurations disable `B43_DEBUG`, omit retired diagnostic packages, and keep the RAM installer LAN-only to preserve memory. Untouched-stock U-Boot classification is logic-tested; unknown bootloader bytes fail closed.

See [`../../openwrt/docs/HARDWARE-QUALIFICATION.md`](../../openwrt/docs/HARDWARE-QUALIFICATION.md) for the complete qualification matrix.
