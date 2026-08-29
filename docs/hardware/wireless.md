# WLAN subsystem

## Hardware

- Broadcom BCM4322 Mini PCI module, PCI ID `14e4:432b`.
- Three antenna connectors and two SiGe `2547A / 2069CHF` front-end devices.
- Physical SPROM and board WLAN MAC recovered through the SSB/MTD path.

## Qualified OpenWrt support

Release `1.16.0-rc7` includes the consolidated b43 rev4 N-PHY work and has qualified startup, AP/client operation, persistent configuration, and the mainboard WLAN LED. Fresh installation enables an open 2.4 GHz `OpenWrt` AP; production users must configure WPA2/WPA3 immediately.

Research-only calibration diagnostics and `B43_DEBUG` are excluded from the production image. Their source, stock-driver crosswalk, and historical captures remain under `openwrt/history/`, `docs/history/openwrt/toolkit-v1.15.10/`, and the research evidence tree.

5 GHz behavior, long-duration RF stability, detailed antenna mapping, and comparative throughput remain research topics rather than release guarantees.
