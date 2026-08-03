# WLAN subsystem

## Hardware

- Broadcom BCM4322 Mini PCI module, PCI ID `14e4:432b`.
- Three antenna connectors.
- Two SiGe `2547A / 2069CHF` RF front-end devices.

## Current status

The device enumerates on PCI, but the current persistent LuCI image does not
provide an operational radio. No driver/firmware selection, SPROM/calibration
validation, interface creation, association, throughput, or RF test has passed.

Wired OpenWrt support is independent and complete enough for current persistent
boot testing. Wireless remains a separate unfinished workstream.
