# OpenWrt port plan for Cisco RV220W

## Feasibility conclusion

An OpenWrt port is technically plausible and preferable to reimplementing Cisco's TeamF1 userspace. The strongest reasons are:

- OpenWrt already has an Octeon target and a supported CN5020 Ubiquiti USG profile.
- Mainline Linux retains Cavium Octeon platform support.
- Linux's B53 DSA driver recognizes BCM53115.
- The board has 128 MiB RAM and a complete interruptible U-Boot with TFTP and ELF Linux boot commands.
- The stock kernel, Ethernet and switch modules are unstripped enough to recover board-specific wiring and register behavior.

This is still a **new board port**, not a compatible-image substitution. The CN5010 board ID, BootBus NOR, BCM53115 CPU-port wiring, RGMII delays, MDIO addressing, GPIO map and image layout must be implemented and validated.

## Primary development strategy: never flash first

The first OpenWrt deliverable should be a serial-only, initramfs ELF booted entirely from RAM.

Recommended gates:

### Gate 0 — preservation

- Capture a second independent 32 MiB dump.
- Verify identical SHA-256.
- Keep an external recovery programmer plan for the x16 NOR.
- Never run `saveenv` or erase/protect commands during early work.

### Gate 1 — stock-system evidence

- Record `cat /proc/cpuinfo`, `/proc/mtd`, `/proc/interrupts`, `/proc/iomem`, `/proc/pci`, and loaded modules.
- Enumerate MDIO addresses and capture switch register reads through the stock tools.
- Map which physical connector corresponds to each `octeth`/Linux interface.
- Trace reset button and LED GPIOs.

### Gate 2 — minimal OpenWrt Octeon profile

Fork current OpenWrt and add a new Octeon device profile rather than modifying the Ubiquiti USG profile in place. Initial changes will likely include:

- `target/linux/octeon/image/Makefile` device stanza
- an RV220W DTS under the Octeon device-tree directory
- board-name/preinit/network setup
- any CN5010 custom-board-type recognition required by Octeon platform code
- a kernel command line with `console=ttyS0,115200`

Use the USG port as a structural reference for appended-DTB ELF creation and Octeon board-type integration, not as a source of RV220W PHY addresses or GPIO values.

### Gate 3 — RAM-only serial boot

Build only:

- initramfs
- BusyBox/ash
- serial console
- proc/sysfs/devtmpfs
- no LuCI
- no Wi-Fi
- no writable flash
- no automatic network configuration

Load by TFTP to a safe RAM address such as the existing `loadaddr=0x05500000`, then boot with `bootoctlinux`. The exact generated image filename and command must be verified against the custom OpenWrt image recipe before execution.

### Gate 4 — read-only NOR support

Implement the 32 MiB BootBus NOR and expose partitions read-only. Preserve:

- `0x00000000–0x0007ffff` boot chain
- `0x01fe0000–0x01ffffff` actual environment/footer sector
- the original JFFS2 data partition until device identity and key storage are understood

Do not initially write any MTD device from OpenWrt.

### Gate 5 — Octeon Ethernet without the external switch

Bring up Octeon packet I/O/RGMII and identify each interface. Validate:

- MAC-address source
- RX/TX delays
- PHY or fixed-link configuration
- raw packet TX/RX
- link state on any directly connected port

### Gate 6 — BCM53115 management

The stock firmware proves the switch is managed through MDIO/pseudo-PHY operations. Port the board using B53 DSA where possible:

- identify MDIO bus and pseudo-PHY address
- define `brcm,bcm53115`
- define the CPU/IMP port and RGMII/fixed-link parameters
- determine whether the kernel's BCM53115 non-tagged/managed-mode path is sufficient
- compare stock Broadcom-tag behavior with modern B53 limitations

Do not copy register constants from `imp_status.sh` without validating them on BCM53115.

### Gate 7 — GPIO, reset and LEDs

Add gpio-keys and gpio-leds only after the exact GPIO numbers and polarities are proven. Keep factory-reset behavior disabled until persistent storage is safe.

### Gate 8 — persistent OpenWrt layout

Only after reliable RAM boot and recovery:

- choose a kernel/rootfs layout inside `0x00080000–0x01fdffff`
- preserve U-Boot and its final environment sector
- create an OpenWrt sysupgrade format with explicit compatibility checks
- retain a stock recovery image and documented UART/TFTP recovery path

A minimal modern build is required because the device has only 32 MiB NOR and 128 MiB RAM. Do not assume a feature-rich LuCI/VPN/WLAN image will fit.

### Gate 9 — WLAN

Treat the removable Mini PCI card as optional:

1. First try wired-only OpenWrt.
2. Evaluate b43 with user-supplied firmware for PCI `14e4:432b`, accepting reduced feature support.
3. Prefer replacing the card with an ath9k-supported Mini PCI module if full open-source Wi-Fi is desired.

## First code milestone

A successful milestone is:

- custom RV220W OpenWrt initramfs ELF,
- loaded by TFTP,
- boots without changing flash,
- stable serial shell,
- correct 128 MiB RAM detection,
- PCI enumeration sees `14e4:432b`,
- NOR visible read-only,
- no switch or WLAN requirement.

That separates core Octeon/board support from the most difficult peripherals and provides a safe platform for iterative hardware discovery.
