# WLAN subsystem

## Hardware

- Full-size Mini PCI module.
- Broadcom `BCM4322LKFBG`.
- PCI ID `14e4:432b`.
- Three antenna connectors.
- Two RF front-end devices marked `SiGe / 2547A / 2069CHF`.
- Module PCB marking appears to be `YK910MO-1.0`.

## Current OpenWrt status

PCI enumeration is proven, but Wi-Fi support is not implemented in the current image. No `b43` firmware selection, SPROM/calibration validation, interface creation, association, throughput, or RF testing has been completed.

The `rj45-full` profile intentionally omits WLAN so wired boot and routing remain isolated from radio work.

## Likely paths

1. Investigate `b43` support with separately supplied firmware and preserved calibration data.
2. Replace the removable card with a better-supported Mini PCI device, such as an ath9k-compatible model, if electrical and mechanical compatibility are confirmed.

A replacement card should not be treated as a substitute for preserving the original module's antenna mapping, calibration material, and PCI behavior.
