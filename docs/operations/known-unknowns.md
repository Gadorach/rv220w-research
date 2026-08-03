# Known unknowns

## Persistent filesystem and upgrade design

- Final SquashFS/overlay partitioning and writable-root design.
- Supported factory/sysupgrade format and rollback metadata.
- Power-loss behavior during slot or future overlay updates.
- Safe automation of manifest-derived U-Boot environment changes.

## Boot chain

- Exact stage-1 boot-stub responsibilities beyond the reconstructed functions.
- Meaning of firmware-header fields at offsets `0x04` and `0x08`.
- Meaning of the final 16 non-erased bytes in the environment sector.
- Single-run validation of the packaged combined wrapper from a completely stock sector.

## Board services

- U3 BootBus latch address multiplexing and its LE/OE control sources.
- JP2 powered protocol and complete J2 EJTAG confirmation.
- Complete status-LED and GPIO map.
- Linux reset-button semantics and watchdog policy.

## Ethernet

The five-port topology and functional routed data path are proven. Remaining
questions are long-duration reliability, performance, tagged-ISP cases, and
upstream patch quality.

## Wireless

- BCM4322 firmware and calibration source.
- Antenna-chain mapping.
- Practical `b43` stability and performance.
- Best compatible replacement Mini PCI card if the original radio is not practical.
