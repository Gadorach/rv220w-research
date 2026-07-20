# WLAN subsystem

## Hardware

- Full-size Mini PCI module.
- Main controller: Broadcom `BCM4322LKFBG`.
- PCI ID observed by U-Boot: `14e4:432b`.
- Three U.FL-style antenna connectors.
- Two RF front-end devices marked `SiGe / 2547A / 2069CHF`.
- Module PCB marking appears `YK910MO-1.0`.

## Stock implementation

The factory system uses proprietary `wl.ko` and userspace WLAN control utilities. Calibration/NVRAM location has not been fully resolved.

## Open-source strategy

WLAN is deliberately last. The old BCM4322 has only partial support through `b43`, requires external firmware, and does not provide a clean modern 802.11n experience. Since the card is removable, a compatible ath9k-based Mini PCI card is likely the best fully open-source route.

Before replacement:

1. Preserve card orientation and antenna mapping.
2. Inventory stock firmware, NVRAM, and calibration files.
3. Capture PCI configuration and reset/clock behavior.
4. Confirm Mini PCI 3.3 V power and host reset signals.
