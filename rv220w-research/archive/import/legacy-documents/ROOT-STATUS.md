# Research status

**Package version:** 0.9.0  
**Snapshot date:** 2026-07-20  
**Physical board:** Cisco RV220W-A V01, PCB `YK910A-1.6`

## Completed

- Full photographic evidence set and direct high-resolution stitches.
- Major component inventory and JP1 primary UART confirmation.
- U-Boot 1.1.1 command/environment/flash inventory.
- Complete 32 MiB UART flash acquisition at 460800 baud.
- Host and target CRC32 match before and after capture: `ce96f3e0`.
- Full-image SHA-256: `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5`.
- 512 chunks completed with zero retries.
- Physical partition map and actual U-Boot environment location resolved.
- Boot stub, U-Boot, kernel partition, complete ELF kernel, rootfs, data, tail and environment regions extracted.
- Exact stock `RV220W-Firmware-1.0.4.17.img` recovered from flash.
- SquashFS 3.0 rootfs extracted: 3,789 files, 86 directories and 185 symlinks.
- Current JFFS2 tree extracted and marked sensitive.
- Stock Ethernet/switch/WLAN/GPIO module architecture reviewed.
- Initial OpenWrt port strategy documented.

## Immediate next actions

1. Capture a second independent 32 MiB image and compare SHA-256.
2. Collect privileged stock-Linux inventories and MDIO/switch traces.
3. Establish physical connector-to-Octeon-interface mapping.
4. Create a minimal RV220W OpenWrt Octeon initramfs profile.
5. TFTP/RAM boot it without touching NOR.
6. Add read-only NOR and serial-only bring-up before switch or WLAN work.

## Not yet completed

- Second independent full-flash acquisition.
- Exact meaning of firmware header fields at offsets `0x04` and `0x08`.
- Exact meaning of the final 16 non-erased bytes in the actual environment sector.
- JP2 powered characterization.
- J2 active EJTAG confirmation.
- Complete GPIO/LED/reset map.
- BCM53115 MDIO address, CPU-port number and RGMII timing map.
- Verified custom RAM boot.
- OpenWrt device tree/profile implementation.
- Safe persistent OpenWrt layout and recovery-tested sysupgrade path.

## Confirmed platform facts

- Cavium OCTEON Plus CN5010-SCP pass 1.1, 400 MHz, one active core.
- 128 MiB DDR2.
- 32 MiB x16 CFI NOR at U-Boot window `0xbdc00000`.
- Linux 2.6.21.7-Cavium-Octeon, big-endian MIPS64/Octeon.
- Firmware `RV220W-Firmware-1.0.4.17.img`, declared size `0x01528080`.
- Rootfs is big-endian SquashFS 3.0; data is big-endian JFFS2.
- Broadcom BCM53115 is controlled through an MDIO/pseudo-PHY module chain.
- WLAN PCI ID is `14e4:432b` and stock WLAN support is proprietary `wl.ko`.
- Actual U-Boot env is the final sector at flash offset `0x01fe0000`, not the Linux-named partition at `0x01780000`.
