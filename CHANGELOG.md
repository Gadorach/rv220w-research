# Changelog


## 2.0.0 — persistent LuCI, NOR, and boot-chain promotion

- Rebased the tree on the reorganized research layout.
- Replaced the OpenWrt v1.9.0 tree with the authoritative v1.10.3 toolkit.
- Integrated platform reconstruction v1.4.0-r1 under `firmware/reconstruction/`.
- Recorded hardware-proven LuCI operation, verified 22 MiB NOR slot writing, and full read-back verification.
- Recorded the corrected flash launch path: copy the exact ELF bytes to RAM and invoke `bootoctlinux`.
- Integrated the hardware-validated combined boot-policy patch and distribution flasher.
- Made the patch-before-firmware order mandatory in all primary installation documentation.
- Recorded automatic OpenWrt boot, persistent `bootcmd`, and retained physical-button Sercomm recovery.
- Moved superseded RAM-only, stage, version, and failure documents into `docs/history/`.
- Kept remaining limitations explicit: initramfs runtime state, no persistent overlay/sysupgrade, no Wi-Fi, and incomplete board services.

## 1.1.0 — hardware-proven OpenWrt RAM-boot merge

- Replaced the early `openwrt/` scaffold with the complete v1.9.0 promotion toolkit.
- Recorded the hardware-proven full TFTP RAM boot of the experimental OpenWrt image.
- Recorded successful initialization and operation of all five RJ45 ports.
- Updated the current topology: LAN1–LAN4 through switch CPU port 8/`eth0`, WAN through CPU port 5/`eth1`.
- Made the absence of LuCI, Wi-Fi support, and persistent flash testing explicit.
- Rewrote the root README as a minimal project outline and status pointer.
- Replaced stale canonical OpenWrt, Ethernet, wireless, risk, and known-unknown documentation with the current state.
- Retained version-specific toolkit documents as historical implementation and regression records.

## 1.0.0 — organized research baseline

- Rebuilt the chat-derived package into a coherent directory hierarchy.
- Replaced 29 overlapping numbered documents with canonical topic documents and a small history section.
- Removed duplicate copies of the UART dumper and JFFS2 extractor.
- Moved all executable tools into `tools/` and adjusted the OpenWrt fish workflows to use them.
- Unpacked nested firmware archives into canonical images, partitions, derived components, reports, and filesystems.
- Reconstructed the verified canonical 32 MiB image from the partition set.
- Retained unredacted factory-reset JFFS2 contents, including the obsolete HTTPS private key.
- Removed stale apply notes, nested release ZIPs, duplicate release artifacts, and broken documentation links.
- Added import provenance, legacy-document mapping, package manifests, and split distribution volumes.
