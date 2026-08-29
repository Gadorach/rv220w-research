# v1.16.0-rc7 release notes

**Release freeze:** 2026-08-28

`1.16.0-rc7` is the release-ready candidate produced from the hardware-qualified RV220W promotion tree.

## Highlights

- reproducible Makefile-first build from pinned OpenWrt `v25.12.5`;
- four active/minimal logical patch groups;
- full persistent OpenWrt image with LuCI, package management and qualified BCM4322/b43 support;
- LAN-only initramfs installer/recovery image to preserve RAM;
- guided UART U-Boot verification/patching with full-NOR or fast bootloader-only backups;
- compatibility based only on the bootloader region, not vendor firmware partitions;
- guarded direct initramfs installation with low-memory validation, rootfs-first/kernel-last writes and SHA-256 readback verification;
- normal configuration-preserving LuCI/sysupgrade after installation;
- production defaults of `192.168.1.1`, `OpenWrt` 2.4 GHz AP and WLAN `netdev` TX/RX LED policy;
- `B43_DEBUG` disabled and standalone research/debug tooling removed from the runtime image;
- complete research provenance retained under `history/`.

## RC7 fix

RC7 fixes the last direct-installer startup issue: OpenWrt `/lib/functions.sh` expects `IPKG_INSTROOT` to exist and is not nounset-clean. The installer initializes/exports the expected variable before sourcing OpenWrt libraries and does not place those libraries under global `set -u` semantics.

The final hardware run completed the direct installer successfully, including persistent rootfs write/readback, kernel-last write/readback and normal reboot. RC7 is therefore marked release-ready.

## Fresh-install defaults

```text
LAN:        192.168.1.1/24
LuCI:       http://192.168.1.1/
SSID:       OpenWrt (2.4 GHz)
Security:   open initially
WLAN LED:   netdev phy0-ap0 TX+RX
```

Users should set a root password and secure Wi-Fi immediately after installation.

## Upgrade behavior

- **Stock Cisco firmware:** use `make u-boot-patches` followed by `make initramfs-liveboot`.
- **Already converted RV220W:** use normal OpenWrt/LuCI sysupgrade. Configuration-preserving upgrade is hardware-qualified.
- **Recovery/live testing:** use `make initramfs-liveboot` and decline permanent installation.

## Known limitations / scope

- This release targets the Cisco RV220W hardware described in the project documentation.
- The public installer build path is supported on CachyOS/Arch + fish + Podman/Distrobox.
- Fresh Wi-Fi is intentionally open for standard OpenWrt-style onboarding; secure it immediately.
- The fast 640 KiB U-Boot backup is sufficient for the regions modified by the U-Boot helper but is not a full Cisco firmware archive.
- Untouched-stock U-Boot classification is covered by deterministic regressions; the destructive U-Boot write machinery was hardware-qualified on an already-patched unit through a forced rewrite.

## Integrity

Run:

```console
make verify
```

before building, and:

```console
make artifacts-check
```

after building. Source release archives contain an internal `SOURCE-SHA256SUMS` manifest and are accompanied by an external archive SHA-256 file.
