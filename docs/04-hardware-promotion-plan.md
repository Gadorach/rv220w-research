# Required hardware promotion steps

This plan promotes the board from an unknown appliance to a reproducible research platform. A stage is complete only when its exit criteria are met and evidence is committed.

## P0 — Preservation baseline

**Required hardware:** camera, ESD mat, DMM, known-good OEM power supply, isolated test network.

**Actions**

- Record board revision, device labels, MAC addresses, firmware version, and factory configuration.
- Photograph both PCB sides and the WLAN card.
- Create a project evidence manifest and hash every capture.
- Verify normal boot and front-panel behavior before probing.

**Exit criteria:** complete photographic record, identity record, normal-function baseline, and no modifications.

## P1 — Power, reset, and clock characterization

**Required hardware:** DMM, ≥100 MHz oscilloscope, high-impedance probes, current-limited bench supply only if input requirements are verified.

**Actions**

- Map input voltage and all major rails at inductors/capacitors.
- Record startup sequencing and steady-state current.
- Confirm 25 MHz and likely 125 MHz clocks.
- Identify system reset nets and reset timing.
- Measure header I/O voltage domains.

**Exit criteria:** rail table, startup waveform set, clock inventory, and safe logic-level determination.

## P2 — Passive serial-console access

**Required hardware:** adjustable 1.8/2.5/3.3 V USB-UART, oscilloscope/logic analyzer, 1–4.7 kΩ resistors, pogo leads.

**Actions**

- Map JP1 and JP2 ground/VCC/TX/RX candidates.
- Capture cold boot without driving any signal.
- Determine baud, framing, bootloader name, kernel command line, and console device.
- Test whether the bootloader is interruptible without changing persistent state.

**Exit criteria:** repeatable cold-boot log and confirmed UART pinout.

## P3 — Stock Linux inventory

**Required hardware:** serial console and/or isolated Ethernet management access.

**Actions**

- Collect `/proc/cpuinfo`, `/proc/cmdline`, `/proc/mtd`, `/proc/interrupts`, mounts, modules, `dmesg`, network state, PCI/Mini PCI enumeration, and boot environment where readable.
- Record CPU endianness, kernel version, root filesystem type, and partition offsets.
- Capture GPIO, MTD, switch, and WLAN-related messages.

**Exit criteria:** complete read-only system inventory tied to a firmware version.

## P4 — Verified flash preservation

**Required hardware:** stock Linux or bootloader read command; storage/transfer path; external parallel-NOR programmer and TSOP56 adapter reserved for recovery.

**Actions**

- Dump every MTD partition and the full 32 MiB address space twice.
- Hash and byte-compare both acquisitions.
- Identify bootloader, environment, kernel, rootfs, config, MAC, and WLAN calibration regions.
- Store immutable backups off-device.

**Exit criteria:** two identical full-flash images and documented partition/factory-data map.

## P5 — Recovery path qualification

**Required hardware:** hot-air rework capability, flux, preheater as needed, TSOP56 parallel-NOR adapter/programmer, donor flash or spare board, JTAG adapter.

**Actions**

- Confirm the external programmer can read and program the exact MX29GL256E variant.
- Practice on a donor device or spare flash.
- Document chip orientation, removal, cleaning, programming, and reinstallation.
- Determine whether EJTAG can halt/reset/read memory and whether it can restore flash.

**Exit criteria:** a tested method that can restore a deliberately altered noncritical region or spare-board flash.

## P6 — Bootloader control and RAM boot

**Required hardware:** UART, TFTP/BOOTP host, isolated switch, recovery method from P5.

**Actions**

- Inventory bootloader commands and environment without saving changes.
- Identify load addresses, memory test limits, image formats, and boot-info handoff.
- Load a minimal payload or known kernel into RAM.
- Boot without writing flash.

**Exit criteria:** repeatable RAM boot and documented boot ABI/addresses.

## P7 — Minimal modern Linux baseline

**Required hardware:** cross-compilation host, UART, RAM-boot path.

**Actions**

- Build a big-endian MIPS64/Octeon kernel matching CN5010 requirements.
- Establish early console, timer, interrupts, DDR size, and initramfs shell.
- Add device-tree or legacy board data as required by the chosen kernel baseline.

**Exit criteria:** stable initramfs shell from RAM with correct CPU/RAM reporting and no flash writes.

## P8 — BootBus NOR and persistent storage

**Required hardware:** P7 baseline plus recovery path.

**Actions**

- Configure CN5010 BootBus timing for MX29GL256E.
- Expose read-only MTD partitions first.
- Verify every partition against the preserved image.
- Add writable overlay/config support only after factory partitions are protected.

**Exit criteria:** correct read-only NOR map and guarded writable test partition.

## P9 — Ethernet MAC and BCM53115 switch

**Required hardware:** two test hosts, managed capture switch or TAP, packet capture, optional MDIO/SPI logic analysis.

**Actions**

- Identify CN5010 MAC interface and switch CPU-port mode: GMII/RGMII/MII.
- Identify the switch management path: MDIO/pseudo-PHY, SPI, or indirect access.
- Confirm reset GPIO and reference clocks.
- Start with one user port and CPU port, then promote VLANs and all five ports.
- Validate RX/TX, link negotiation, VLAN isolation, tagging behavior, and MTU.

**Exit criteria:** sustained bidirectional traffic through each port, reproducible switch initialization, and captured register/DT configuration.

## P10 — Board GPIO, LEDs, buttons, watchdog, and reset

**Required hardware:** logic analyzer, current-limited probes, front-panel observation.

**Actions**

- Map all LEDs and active polarities.
- Map reset/WPS buttons with debounce behavior.
- Identify switch/WLAN reset lines and power enables.
- Identify and exercise the watchdog under controlled recovery conditions.
- Verify clean reboot, poweroff behavior, and factory-reset handling.

**Exit criteria:** deterministic GPIO map and successful watchdog recovery test.

## P11 — Mini PCI and WLAN

**Required hardware:** stock BCM4322 card, optional well-supported Mini PCI test card, RF shielded/low-power test environment where appropriate.

**Actions**

- Confirm PCI enumeration, reset, clock, and power.
- Preserve calibration/NVRAM data before driver experiments.
- Try mainline-compatible drivers where feasible; otherwise document proprietary dependency.
- Consider replacing the card with a better-supported Mini PCI radio for the open platform.

**Exit criteria:** reliable PCI enumeration and either functional WLAN or a documented supported replacement path.

## P12 — Production-hardening gate

**Required hardware:** automated power control, traffic generator, thermal monitoring, long-duration logging.

**Actions**

- Run repeated cold/warm boot cycles and power-failure tests.
- Validate flash-write interruption behavior.
- Stress CPU, memory, Ethernet, and WLAN.
- Verify watchdog, recovery image, config rollback, MAC preservation, and thermal limits.
- Produce reproducible build and installation documentation.

**Exit criteria:** no unexplained boot failures, recoverable update process, protected factory data, and repeatable builds from a clean host.
