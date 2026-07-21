# Linux and OpenWrt porting strategy

## Existing upstream building blocks

- Mainline Linux retains `arch/mips/cavium-octeon` platform code and OCTEON boot-info definitions.
- Mainline DSA includes the Broadcom `b53` driver with BCM53115 support.
- OpenWrt retains an Octeon target, but no ready-made RV220W board definition has been identified.

## Recommended baseline sequence

1. Start with a kernel known to boot on CN50XX/OCTEON Plus.
2. Use the stock bootloader and RAM boot rather than replacing the bootloader early.
3. Bring up early UART and initramfs only.
4. Add BootBus NOR read-only.
5. Add one CN5010 Ethernet interface and switch CPU port.
6. Add GPIO/reset/LED/watchdog.
7. Add writable storage and sysupgrade only after recovery is proven.
8. Add Mini PCI/WLAN last.

## Device-tree data to recover

- CPU clock and boot-info behavior.
- UART base/interrupt/clock.
- BootBus chip-select, width, and timing.
- NOR partitions and protection.
- CN5010 GMX interface mode and RGMII delays.
- BCM53115 bus, address, reset GPIO, CPU/user port mapping.
- LEDs, buttons, watchdog, and WLAN reset/power.
- MAC address source.

## Compatibility risk

The original GPL notice identifies a Linux 2.6.21-era software base. Vendor Cavium SDK code may use legacy board files and out-of-tree APIs. Port findings into modern subsystems rather than copying proprietary or obsolete code wholesale.
