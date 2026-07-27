# Current status

**Research package:** 1.1.0

**OpenWrt toolkit:** 1.9.0

**Snapshot:** 2026-07-27

**Board:** Cisco RV220W-A V01 / PCB `YK910A-1.6`

## Hardware-proven OpenWrt state

The current experimental OpenWrt initramfs image has been built and fully booted from RAM through the stock U-Boot TFTP path. The onboard NOR was not modified.

The live system initializes and operates all five front-panel RJ45 ports:

```text
WAN  -> BCM53115 port 0 -> CPU port 5 -> Octeon eth1 -> DSA wan
LAN1 -> BCM53115 port 1 \
LAN2 -> BCM53115 port 2  \
LAN3 -> BCM53115 port 3   > CPU port 8 -> Octeon eth0 -> DSA -> br-lan
LAN4 -> BCM53115 port 4  /
```

The working timing mode is `rgmii-rxid` for both switch CPU links. The v1.9.0 B53 patch includes firmware-described DSA CPU ports in the active-port mask so both CPU conduits receive normal default VLAN/PVID setup.

The `rj45-full` profile provides a conventional wired-router policy in RAM:

- LAN1–LAN4 in `br-lan` at `192.168.240.2/24`;
- DHCP service on LAN;
- DHCP and DHCPv6 clients on WAN;
- firewall4 LAN/WAN separation;
- LAN-to-WAN forwarding and masquerading;
- PPP and PPPoE packages.

## Deliberately absent or untested

- **LuCI:** not added or tested.
- **Wi-Fi:** the BCM4322 Mini PCI device enumerates, but no driver, firmware, radio, or RF validation has been completed.
- **Persistent installation:** no NOR erase, program, sysupgrade, or boot-from-flash attempt has been made.
- **Persistent root filesystem:** only RAM-loaded experimental images are qualified.
- **Board services:** status LEDs, reset-button integration, watchdog behavior, and remaining GPIOs are not fully promoted.

## Preservation baseline

- Two independent 32 MiB UART flash acquisitions match byte-for-byte.
- Boot stub, U-Boot, stock kernel ELF, SquashFS rootfs, JFFS2 data, and the actual final environment sector are preserved.
- The automated TFTP path changes only temporary U-Boot variables and never calls `saveenv` or a flash command.

## Recommended next work

1. Preserve the final full-RJ45 boot and traffic-validation logs as a named regression baseline.
2. Add optional LuCI only after measuring image and runtime-memory impact.
3. Promote LEDs, reset input, and watchdog behavior without enabling destructive reset semantics.
4. Investigate BCM4322 `b43` firmware support or a better-supported replacement Mini PCI card.
5. Design a recovery-preserving flash layout only after repeated RAM-boot regression testing and a complete restore procedure are qualified.
