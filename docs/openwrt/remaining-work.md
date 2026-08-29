# Remaining OpenWrt work

## Platform services

- Define and qualify Linux reset-button behavior and watchdog policy.
- Complete the remaining GPIO map and safe board-service semantics.
- Characterize long-duration stability, throughput, thermal behavior, and repeated cold boots.
- Separate generic Octeon/B53/b43 fixes from board-specific support for upstream review.

## Release engineering

- Exercise untouched-stock U-Boot classification on another stock unit while retaining the current fail-closed policy.
- Add automated CI for static release checks and documentation links.
- Expand interrupted-write and repeated upgrade/restore testing.

## Wireless follow-up

- Characterize long-duration b43 stability, throughput, 5 GHz feasibility, and antenna-chain behavior.
- Evaluate newer Mini PCI alternatives without discarding original-module evidence.
