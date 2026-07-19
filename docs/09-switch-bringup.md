# BCM53115 Ethernet-switch bring-up

## Known component capability

The BCM53115 is a five-port 10/100/1000 RoboSwitch with integrated PHYs. Linux's `b53` DSA driver lists BCM53115 as supported, but 531x5 devices require managed-mode and configuration considerations when Broadcom tagging is unavailable or inappropriate.

## Unknown board wiring

- CPU port number.
- GMII/RGMII/MII mode.
- RX/TX clock delays and voltage.
- Reset polarity and source.
- Management interface: MDIO/pseudo-PHY, SPI, or other indirect path.
- WAN/LAN physical-port ordering.
- Whether the bootloader seeds switch state.

## Evidence collection

From stock firmware, capture:

- kernel module names and loaded symbols;
- GPIO transitions during switch reset;
- MDIO/SPI transactions during boot;
- interface and VLAN configuration;
- register dumps before and after link-up;
- packet captures at CPU and user ports where possible.

## Promotion order

1. Read chip ID and revision.
2. Assert/deassert reset and verify clock.
3. Enable CPU port only.
4. Enable one copper user port in a flat VLAN.
5. Verify ARP, ping, and sustained bidirectional traffic.
6. Add remaining LAN ports.
7. Add WAN separation and VLAN filtering.
8. Validate FDB learning, multicast, MTU, and link renegotiation.
