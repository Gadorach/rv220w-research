# Cisco RV220W OpenWrt release

**Release:** `1.16.0-rc7`

**Status:** **release-ready / hardware-qualified RC**

**Pinned OpenWrt:** `v25.12.5`

**Build host:** CachyOS/Arch Linux + fish, Podman and Distrobox

**Build container:** Ubuntu 24.04 (`rv220w-openwrt-release`)

This tree is the release-oriented form of the Cisco RV220W OpenWrt port. The long promotion/debug campaign has been collapsed into a small reproducible build and onboarding workflow; research material and retired diagnostics remain available under `history/` but are not installed in the normal image.

The RC7 release workflow has completed end-to-end hardware qualification on an RV220W: clean build, guarded U-Boot tooling, RAM liveboot, low-memory image validation, direct initramfs rootfs-first/kernel-last installation with readback verification, normal NOR reboot, production networking/Wi-Fi, first-boot defaults, and configuration-preserving LuCI sysupgrade.

## Supported hardware

- Cisco RV220W
- Cavium OCTEON Plus CN5010
- 128 MiB RAM
- 32 MiB parallel NOR
- Broadcom BCM53115 Ethernet switch
- Broadcom BCM4322 2.4/5 GHz WLAN device; this release configures the qualified 2.4 GHz AP path by default

The active port provides:

- BCM53115 DSA networking with `wan`, `lan1` ... `lan4`;
- BCM4322/b43 support using the physical SPROM, board WLAN MAC and qualified N-PHY startup/calibration path;
- full-NOR SquashFS + JFFS2 overlay layout;
- standard configuration-preserving OpenWrt sysupgrade after installation;
- LuCI and package management in the persistent image;
- DTS-defined POWER, DIAG, WLAN and DMZ GPIO LEDs;
- normal production logging with `B43_DEBUG` disabled and research-only target diagnostics removed.

## Quick start

To build from source, enter the OpenWrt subtree and run:

```console
make all
```

`make all` verifies the release tree, provisions the isolated Ubuntu 24.04 Distrobox, downloads the pinned OpenWrt source/feeds, applies the four active RV220W patch groups, builds both public images, verifies their checksums and prints the onboarding commands.

Artifacts are written to:

```text
build/artifacts/
```

Expected output:

```text
rv220w-openwrt-release-initramfs.elf
rv220w-openwrt-release-kernel.elf.gz
rv220w-openwrt-release-rootfs.squashfs
rv220w-openwrt-release-sysupgrade.tar
SHA256SUMS
```

The qualified OpenWrt/feed revisions are pinned in `source-lock.json`. Source preparation checks out those exact commits and records the verified result in `build/source-lock.json`.

For an unmodified router, the normal flow is:

```console
make u-boot-patches
make initramfs-liveboot
```

In this research repository, `make initramfs-liveboot` detects the hardware-qualified image pair under `../prebuilt/` and asks whether to use it. Answering no uses `build/artifacts/` instead and builds a missing source artifact automatically. `--prebuilt` and `--built` select either path non-interactively.

For a read-only bootloader check first:

```console
make u-boot-verify
```

See **[docs/INSTALL.md](docs/INSTALL.md)** for the full guided procedure and **[docs/RECOVERY.md](docs/RECOVERY.md)** before intentionally modifying U-Boot/NOR.

## Fresh-install defaults

| Setting | Value |
|---|---|
| LAN | `192.168.1.1/24` |
| LuCI | `http://192.168.1.1/` |
| 2.4 GHz SSID | `OpenWrt` |
| Initial Wi-Fi security | Open / no password |
| WLAN LED | `netdev` on `phy0-ap0`, TX + RX |

Set a root password and enable Wi-Fi security immediately after first boot.

The first-boot wireless policy enables OpenWrt's pristine generated AP template but leaves a genuinely customized wireless configuration untouched on later upgrades. The WLAN front-panel LED is a DTS-defined mainboard GPIO LED; the default `netdev` trigger is userspace policy rather than a requirement for a b43-specific hardware LED.

## Build workspace reuse

The release uses a dedicated Distrobox named `rv220w-openwrt-release`. It does not reuse or modify the historical research container.

A `build/` workspace from an earlier `1.16.0-rcN` can be carried forward. The source preparer automatically migrates only a worktree marked as one of this project's earlier RCs and only when tracked edits are confined to the release-owned OpenWrt integration surface. It preserves expensive untracked state such as `dl/`, `build_dir/`, `staging_dir/`, feeds and toolchain caches. Unrelated tracked source edits cause a fail-closed stop instead of being discarded.

Container provisioning is logged at:

```text
build/logs/distrobox-provision.log
```

## Public Make targets

```text
make all                 complete setup + initramfs + sysupgrade build
make verify              static release/source policy checks
make setup               host dependencies + Ubuntu 24.04 Distrobox
make recreate-box        recreate the dedicated build container
make sources             fetch/pin OpenWrt and apply the RV220W release delta
make initramfs           build the LAN-only RAM installer/recovery image
make sysupgrade          build the persistent NOR sysupgrade image
make artifacts-check     verify checksums of completed build artifacts
make u-boot-verify       read-only bootloader backup + compatibility/environment check
make u-boot-patches      guarded U-Boot onboarding/repair workflow
make initramfs-liveboot  guided UART/TFTP RAM boot + optional direct NOR install
make package             build deterministic source-release ZIP + checksums
make clean               remove generated artifacts/logs only
make distclean           remove the complete local build workspace
```

## Release documentation

- **[docs/INSTALL.md](docs/INSTALL.md)** — build, stock-router onboarding, first boot and normal upgrades.
- **[docs/RECOVERY.md](docs/RECOVERY.md)** — backup scopes, recovery boundaries and failure-phase guidance.
- **[docs/HARDWARE-QUALIFICATION.md](docs/HARDWARE-QUALIFICATION.md)** — what was actually hardware-qualified and what remains logic-tested only.
- **[docs/RELEASE-NOTES.md](docs/RELEASE-NOTES.md)** — RC7 release notes, defaults and known limitations.
- **[patches/README.md](patches/README.md)** — the four active/minimal patch groups.
- **[history/README.md](history/README.md)** — retired research/debug material retained for provenance.

## Release layout

```text
config/              release OpenWrt configurations
files/               persistent target overlay
installer-files/     initramfs-only direct installer
patches/              four active logical patch groups
platform/             RV220W DTS and sysupgrade platform implementation
scripts/release/      public build/bootstrap orchestration
scripts/host/         low-level qualified host helpers
docs/                 release/install/recovery/qualification documentation
history/debug-tools/  retired diagnostics and collectors; reference only
history/research/     superseded research source; reference only
../docs/history/      historical milestone/evidence notes
```

The final promotion toolkit is retained as normalized historical sources and documents rather than as a duplicate nested ZIP.

## Safety

`make u-boot-patches` and the confirmed install phase of `make initramfs-liveboot` can modify NOR flash. Preserve the generated backups and do not interrupt power during a confirmed write. Unknown U-Boot contents fail closed rather than being patched heuristically.

The U-Boot helper can make either a full 32 MiB archival backup or a warning-gated 640 KiB bootloader-only backup (512 KiB boot-chain + 128 KiB U-Boot environment). The fast backup preserves every NOR region the helper can modify, but it cannot reconstruct the original Cisco kernel/rootfs/config partitions.

This project is not affiliated with Cisco Systems or OpenWrt.
