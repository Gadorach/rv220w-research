# Current status

**Organized package:** 1.0.0  
**Research snapshot:** 2026-07-20  
**Board:** Cisco RV220W-A V01 / `YK910A-1.6`

## Complete

- Board and component photography, including direct high-resolution stitched views.
- Major component inventory.
- JP1 primary UART pinout and U-Boot access.
- J2 high-confidence MIPS14/EJTAG electrical topology.
- Two independently verified 32 MiB flash captures.
- Physical flash map, actual U-Boot environment location, and firmware container format.
- Boot stub, U-Boot, kernel ELF, SquashFS rootfs, JFFS2 data, and environment/tail extraction.
- Stock kernel/module architecture review.
- CachyOS/Distrobox/OpenWrt promotion toolkit.
- Duplicate scripts and overlapping documentation consolidated.

## Immediate work

1. Prove TFTP transport by loading the recovered stock ELF into RAM.
2. Build and boot a minimal generic Octeon OpenWrt initramfs.
3. Add an RV220W board description and read-only BootBus NOR support.
4. Map the Octeon RGMII interfaces to physical ports.
5. Bring up the BCM53115 CPU/IMP port and switch management path.
6. Map LEDs, reset input, JP2, J2, and watchdog behavior.
7. Design persistent storage only after RAM boot and recovery are reliable.

## Unresolved

- Firmware header fields at offsets `0x04` and `0x08`.
- Meaning of the final 16 non-erased bytes in the actual U-Boot environment sector.
- Exact JP2 protocol and physical pin numbering.
- Active confirmation of every J2 EJTAG signal.
- Complete GPIO, LED, reset, and watchdog map.
- BCM53115 MDIO address, CPU port, Broadcom tag behavior, and RGMII delays.
- A tested RV220W device tree and OpenWrt image profile.
