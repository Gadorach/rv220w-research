# Project scope and research rules

## Goal

Develop a complete, reproducible understanding of the RV220W hardware sufficient to:

- preserve and recover the factory firmware;
- obtain stable bootloader and Linux access;
- boot an experimental kernel/root filesystem from RAM;
- describe the board using modern Linux device-tree conventions where practical;
- initialize flash, Ethernet MAC, BCM53115 switch, LEDs, reset button, watchdog, and Mini PCI WLAN;
- produce a clean upstream- or OpenWrt-oriented board support patch set.

## Out of scope for the initial baseline

- Circumventing remote-service credentials or extracting user secrets.
- Modifying the device before backups and recovery paths exist.
- Reconstructing proprietary Cisco applications.
- Treating the board as production-ready before watchdog, thermal, reset, and recovery tests pass.

## Evidence vocabulary

- **Observed:** directly visible, measured, captured, or read from the device.
- **Confirmed:** independently reproduced or supported by an authoritative component document.
- **Inferred:** the most likely explanation based on routing, placement, or platform conventions.
- **Unknown:** no sufficient evidence.

## Research order

1. Preserve identifiers and current firmware.
2. Obtain a passive serial log.
3. Establish a non-destructive full-flash read path.
4. Build a tested recovery method.
5. Map debug headers and low-level buses.
6. Boot from RAM.
7. Promote hardware one subsystem at a time.
