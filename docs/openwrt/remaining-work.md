# Remaining OpenWrt work

## Storage and upgrades

- Design and validate a persistent SquashFS root plus writable overlay.
- Define factory and sysupgrade image formats with power-loss-safe rollback.
- Automate environment updates without hiding the manifest-derived copy length.
- Qualify interrupted writes and repeated upgrade/restore cycles.

## Platform services

- Promote status LEDs, reset input, and watchdog behavior.
- Complete GPIO mapping and safe reset semantics.
- Characterize long-duration stability, throughput, thermal behavior, and repeated cold boots.
- Prepare upstream-quality separation of generic Octeon/B53 fixes and board-specific support.

## Wireless

- Resolve BCM4322 firmware and SPROM/calibration requirements.
- Validate interface creation, association, security, throughput, and RF behavior.
- Alternatively qualify a better-supported Mini PCI replacement while preserving the original module evidence.

## Validation nuance

The combined target and its component destructive transitions are hardware
validated. The packaged combined wrapper has hardware-validated staging and
idempotent no-write behavior, but its one-command stock-to-combined destructive
transition has not been separately repeated.
