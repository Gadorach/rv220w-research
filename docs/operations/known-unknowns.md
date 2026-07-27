# Known unknowns

## Boot and flash

- Meaning of firmware header fields at offsets `0x04` and `0x08`.
- Meaning of the final 16 non-erased bytes in the actual environment sector.
- Exact stage-1 boot-stub responsibilities.
- A safe persistent OpenWrt partition, image, installer, and rollback design.
- Interrupted-write and power-loss behavior for any future installer.

## Debug and board services

- JP2 protocol and powered behavior.
- Active confirmation of all J2 EJTAG signals.
- Complete status-LED and GPIO map.
- Safe Linux reset-button semantics.
- Watchdog timeout, enable, and recovery behavior.

## Ethernet

The front-panel topology, B53 address, CPU ports, RGMII timing, and five-port operation are now proven. Remaining work is primarily long-duration regression, tagged-WAN cases, performance characterization, and upstream-quality patch review.

## WLAN

- Exact BCM4322 SPROM/calibration source and required firmware set.
- Antenna-chain mapping.
- Practical `b43` stability and performance on this board.
- Best electrically compatible replacement Mini PCI card, if replacement is preferred.
