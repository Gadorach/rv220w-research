# RV220W OpenWrt port workspace

This directory is a planning scaffold, not a flashable implementation.

## Current target

Create a new `octeon/generic` device profile for the Cisco RV220W using a RAM-only initramfs ELF as the first deliverable.

## Do not yet guess

The following values must be derived from stock firmware or hardware measurements before a DTS is committed:

- Octeon board-type number expected by modern kernel code
- RGMII port-to-connector mapping
- RX/TX delays
- BCM53115 MDIO/pseudo-PHY address
- BCM53115 CPU/IMP port number
- fixed-link speed/duplex/pause properties
- GPIO numbers and active levels
- NOR timing properties
- MAC-address storage format and offset

## Reference implementation structure

The OpenWrt Ubiquiti USG CN5020 port is the closest upstream example for:

- Octeon device profile layout
- DTS attachment to an ELF kernel
- Octeon custom board IDs
- UART and PIP nodes

It is not electrically equivalent to the RV220W.

## Initial profile package policy

Start with a deliberately small initramfs:

- serial console
- MTD read support
- PCI enumeration
- basic Octeon Ethernet dependencies
- no LuCI
- no Wi-Fi
- no VPN suites
- no flash-writing utilities in the first test image
