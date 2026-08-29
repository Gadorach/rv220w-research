# Current status

**Research package:** 3.0.0

**OpenWrt release:** 1.16.0-rc7

**Boot-chain reconstruction:** 1.4.0-r1

**Snapshot:** 2026-08-29

**Board:** Cisco RV220W-A V01 / PCB `YK910A-1.6`

## Hardware-qualified release

The RC7 workflow completed a clean build, guarded U-Boot handling, TFTP initramfs boot, low-memory image validation, direct rootfs-first/kernel-last installation, full partition readback, normal NOR reboot, persistent networking/Wi-Fi, and configuration-preserving sysupgrade.

Persistent flash layout:

```text
0x00000000  0x00080000  boot-chain       preserved
0x00080000  0x00600000  openwrt-kernel   gzip-compressed ELF
0x00680000  0x01960000  rootfs           SquashFS + split JFFS2 rootfs_data
0x01fe0000  0x00020000  uboot-env        preserved
```

Qualified U-Boot policy:

```text
bootdelay=3
bootcmd=run openwrt_boot
openwrt_boot=cp.b 0xbdc80000 0x05500000 0x600000; gunzip 0x05500000 0x600000 0x06500000 0x1a00000; bootoctlinux 0x06500000 console=ttyS0,115200
```

## Verified behavior

- Fresh LAN and LuCI at `192.168.1.1/24` and `http://192.168.1.1/`.
- LAN1-LAN4 through BCM53115 CPU port 8/Octeon `eth0`.
- WAN through BCM53115 CPU port 5/Octeon `eth1`.
- DHCP, firewall4, routing/NAT, WAN isolation, and DSA affinity policy.
- BCM4322/b43 2.4 GHz AP/client operation using physical SPROM and the board WLAN MAC.
- POWER, DIAG, WLAN, and DMZ GPIO LEDs; WLAN defaults to `phy0-ap0` TX/RX activity.
- Persistent JFFS2 overlay and LuCI configuration-preserving sysupgrade.
- Physical-button Sercomm recovery after the combined boot-policy patch.

## Remaining limitations

- Untouched-stock U-Boot classification is deterministic and regression-tested, while destructive writes were qualified by rewriting an already-qualified unit.
- Reset-button Linux policy, watchdog behavior, remaining GPIO details, long-duration reliability, and upstream-quality patch separation remain incomplete.
- Fresh Wi-Fi is intentionally open and must be secured immediately.
