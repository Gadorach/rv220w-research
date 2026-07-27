# Current hardware status

## Proven result

Toolkit v1.9.0 builds an experimental RV220W OpenWrt initramfs that fully boots through the stock U-Boot TFTP path and runs from RAM. Hardware testing confirms that the live system initializes and operates all five RJ45 ports.

```text
WAN  -> port 0 -> CPU port 5 -> eth1 -> wan
LAN1 -> port 1 \
LAN2 -> port 2  \
LAN3 -> port 3   > CPU port 8 -> eth0 -> br-lan
LAN4 -> port 4  /
```

Both CPU links use `rgmii-rxid`. Patch 998 ensures every firmware-described DSA CPU port participates in B53's active-port and default VLAN/PVID initialization.

## Current profile

```fish
./rv220w.fish build rj45-full
./rv220w.fish tftp-boot --profile rj45-full --interface <host-interface> --configure-interface
```

The RAM image provides LAN DHCP, WAN DHCP/DHCPv6, firewall4 separation, LAN-to-WAN NAT, and PPP/PPPoE packages.

## Not implemented or attempted

- LuCI was not included or tested.
- BCM4322 Wi-Fi is not operational.
- No persistent flash build, installer, sysupgrade, erase, or onboard NOR program attempt has been made.
- The firmware remains experimental and unpolished.
- LEDs, reset-button integration, and watchdog support remain incomplete.
