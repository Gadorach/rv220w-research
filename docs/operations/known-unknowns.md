# Known unknowns

## Boot chain

- Exact stage-1 boot-stub responsibilities beyond the reconstructed functions.
- Meaning of firmware-header fields at offsets `0x04` and `0x08`.
- Meaning of the final 16 non-erased bytes in the environment sector.
- Hardware exercise of untouched-stock classification on another unit; unknown states already fail closed.

## Board services

- U3 BootBus latch address multiplexing and LE/OE control sources.
- JP2 powered protocol and complete J2 EJTAG confirmation.
- Remaining GPIO details, Linux reset-button semantics, and watchdog policy.

## Reliability and performance

- Long-duration wired and wireless stability, thermal behavior, and repeated cold boots.
- Tagged-ISP cases, maximum routed throughput, and upstream patch quality.
- BCM4322 5 GHz operation, antenna-chain mapping, and comparative b43 performance.

Persistent SquashFS/JFFS2, configuration-preserving sysupgrade, and BCM4322 2.4 GHz operation are no longer unknowns; they are part of the RC7 hardware-qualified release boundary.
