# OpenWrt promotion plan

## Completed

### Preservation and recovery baseline

- Two matching complete NOR captures.
- Stock partitions, kernel, root filesystems, and environment preserved.
- JP1 console and U-Boot interruption proven.

### Reproducible build and RAM boot

- CachyOS/fish host workflow with Ubuntu 24.04 Distrobox.
- Pinned OpenWrt v25.12.5 source baseline.
- Automated build, artifact validation, TFTP service, serial interruption, and `bootoctlinux` launch.
- Complete OpenWrt boot from RAM proven on hardware.

### RV220W platform and wired networking

- RV220W device tree and board profile.
- Read-only CFI NOR partition exposure.
- Octeon `eth0`/`eth1` mapping.
- BCM53115 at pseudo-PHY `0x1e`.
- LAN DSA path through CPU port 8.
- WAN DSA path through CPU port 5.
- All five RJ45 ports operational.
- Full wired-router `rj45-full` policy in RAM.

## Current boundary

The project is still a RAM-only experimental firmware. No persistent installation has been attempted, and no claim is made that flash installation or recovery after an interrupted write is safe.

## Next gates

### P7 — board services

Map and promote status LEDs, reset input, and watchdog behavior. Destructive reset or factory-erase semantics must remain disabled until explicitly qualified.

### P8 — optional user interface and package budget

Evaluate LuCI only after recording the size and memory budget of the proven no-LuCI image. LuCI must remain optional so the minimal recovery/test image stays small.

### P9 — WLAN

Validate BCM4322 SPROM/calibration, choose `b43` firmware, and test radio behavior, or qualify a replacement Mini PCI card.

### P10 — persistent layout design

Design a recovery-preserving partition and image format. Keep the stock boot chain and actual final U-Boot environment sector untouched.

### P11 — installation and recovery qualification

Before any installer is offered, prove complete restoration, interrupted-write behavior, bad-image rejection, repeated cold boots, and recovery on more than one unit where possible.
