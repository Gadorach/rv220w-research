# RV220W OpenWrt promotion plan

## Completed stages

### P0 — preservation and console

- two byte-identical complete NOR captures;
- stock boot chain, partitions, filesystems, kernel, and actual environment sector preserved;
- JP1 UART and U-Boot interruption qualified.

### P1 — reproducible build and transport

- CachyOS/fish orchestration;
- Ubuntu 24.04 Distrobox build environment;
- pinned OpenWrt v25.12.5 source baseline;
- automated source preparation, build logging, artifact validation, TFTP service, UART interruption, and `bootoctlinux` launch;
- complete modern OpenWrt TFTP RAM boot proven.

### P2 — RV220W board support and read-only flash

- RV220W device tree and profile;
- 128 MiB RAM, UART, PCI, MDIO, native Octeon Ethernet, MAC source, and BootBus NOR represented;
- 32 MiB x16 CFI NOR exposed through the verified seven-partition read-only layout;
- no Linux MTD write path included in the validation policy.

### P3 — switch discovery and port mapping

Hardware-proven map:

```text
WAN  -> BCM53115 port 0 -> CPU port 5 -> Octeon eth1
LAN1 -> BCM53115 port 1 \
LAN2 -> BCM53115 port 2  \
LAN3 -> BCM53115 port 3   > CPU port 8 -> Octeon eth0
LAN4 -> BCM53115 port 4  /
```

The switch-management endpoint is pseudo-PHY `0x1e`; both CPU links use `rgmii-rxid`.

### P4 — B53/DSA ownership

- upstream-style B53/DSA owns the BCM53115 in RAM;
- LAN1–LAN4 operate through port 8/`eth0`;
- WAN operates through port 5/`eth1`;
- patch 998 merges firmware-described DSA CPU ports into B53's active-port mask before default VLAN/PVID initialization;
- all five RJ45 ports initialize and operate in the v1.9.0 image.

### P5 — complete wired RAM profile

The hardware-proven `rj45-full` profile provides:

- LAN1–LAN4 in `br-lan` at `192.168.240.2/24`;
- LAN DHCP and IPv6 service;
- WAN DHCP and DHCPv6 clients;
- firewall4 LAN/WAN separation;
- LAN-to-WAN forwarding and masquerading;
- PPP and PPPoE packages;
- no LuCI, WLAN, or flash-write automation.

## Current project boundary

The project is still experimental RAM-only firmware. No persistent image, installer, sysupgrade path, onboard NOR erase/program operation, or boot-from-flash attempt has been made.

## Next stages

### P6 — preserve a formal regression baseline

Store the final source lock, expanded config, artifact hash, build log, complete TFTP/UART boot log, interface state, five-port traffic results, and routed/firewall test results.

### P7 — board services

Promote LEDs, reset input, and watchdog behavior. Keep destructive reset/factory-erase semantics disabled until separately qualified.

### P8 — optional LuCI

Measure image size and runtime memory before adding LuCI. Keep the minimal no-LuCI recovery/test profile available.

### P9 — WLAN

Investigate BCM4322 `b43` firmware/SPROM/calibration and RF operation, or qualify a better-supported replacement Mini PCI card.

### P10 — persistent layout design

Design a recovery-preserving partition and image format while retaining the stock boot chain and actual final U-Boot environment sector.

### P11 — installation and recovery qualification

Before any installer is offered, prove complete restoration, bad-image rejection, interrupted-write behavior, power-loss handling, repeated cold boots, and recovery on additional hardware where possible.
