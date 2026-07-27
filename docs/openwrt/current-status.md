# Current OpenWrt status

## Proven on hardware

- OpenWrt v25.12.5-based sources build for the RV220W through the v1.9.0 toolkit.
- The resulting big-endian Octeon ELF boots through U-Boot/TFTP and runs entirely from RAM.
- UART console, board device tree, read-only flash visibility, native Octeon Ethernet, B53/DSA, and both CPU conduits operate.
- LAN1–LAN4 operate through `eth0` and switch CPU port 8.
- WAN operates through `eth1` and switch CPU port 5.
- The `rj45-full` profile configures LAN DHCP, WAN DHCP/DHCPv6, firewall4, NAT, and PPP/PPPoE packages.

## Explicit limitations

- LuCI was not built into or tested on this platform.
- Wi-Fi is unavailable; only BCM4322 PCI enumeration is known.
- No persistent flash image, installer, sysupgrade path, or onboard NOR write has been attempted.
- The image is experimental test firmware and is not a polished release.
- LED, reset-button, and watchdog integration remains incomplete.

## Source of truth

- Toolkit overview: [`../../openwrt/README.md`](../../openwrt/README.md)
- Current toolkit status: [`../../openwrt/docs/CURRENT_STATUS.md`](../../openwrt/docs/CURRENT_STATUS.md)
- Device-tree evidence: [`../../openwrt/docs/RV220W-DT-EVIDENCE-MATRIX.md`](../../openwrt/docs/RV220W-DT-EVIDENCE-MATRIX.md)
- Run9 VLAN proof: [`../../openwrt/docs/RV220W-RUN9-VLAN-PVID-PROOF.md`](../../openwrt/docs/RV220W-RUN9-VLAN-PVID-PROOF.md)
