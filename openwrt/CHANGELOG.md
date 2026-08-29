# Changelog

## 1.16.0-rc7

**Release status: hardware-qualified and release-ready.** The final RC7 hardware run completed the direct-initramfs installer end-to-end: low-memory validation passed, the rootfs-first write/readback passed, the kernel-last write/readback passed, the router rebooted normally from NOR, and the release defaults/normal persistent functionality were accepted for release.

- fix the direct initramfs installer failing before any NOR write while sourcing OpenWrt `/lib/functions.sh` with `set -u`;
- explicitly initialize/export `IPKG_INSTROOT` before loading OpenWrt shell libraries, and keep nounset disabled while those libraries are in scope because they are not written to be nounset-clean;
- add a BusyBox `ash -u` compatibility regression which sources a synthetic OpenWrt-style library that dereferences `IPKG_INSTROOT`, proving the installer preamble supplies the variable even under strict nounset semantics;
- retain the RC5/RC6 direct-initramfs rootfs-first/kernel-last write/readback implementation unchanged; the captured RC6 hardware run failed before `RV220W_DIRECT_INSTALL_BEGIN`, so no NOR write was attempted;
- retain RC6 cache-preserving source-worktree migration.

## 1.16.0-rc6

Release-worktree migration hotfix after the RC5 `make all` test found an RC4 ownership marker in the cached OpenWrt worktree:

- when `build/sources/openwrt/.rv220w-release` identifies an earlier known `1.16.0-rcN` tree, automatically return only the release-owned tracked OpenWrt integration files to the pinned `v25.12.5` base and apply the current release delta;
- preserve expensive untracked OpenWrt state including `dl/`, `build_dir/`, `staging_dir/`, feed checkouts and toolchain caches; do not use a broad `git clean`;
- remove only known RV220W-owned untracked DTS and `900-rv220w-*` patch injections during migration;
- fail closed if the prior tree contains any tracked modification outside the four release-owned integration paths, so local source edits cannot be silently discarded;
- add an executable synthetic migration regression proving caches survive, known injections are removed, tracked release changes return to base, and an unrelated tracked user edit is preserved by refusing migration.

RC6 is a host/source-preparation-only change. The RC5 direct-initramfs installer, kernel/DTS/b43/DSA patches, U-Boot bytes, NOR geometry, image configuration and first-boot defaults are unchanged. A current RC5 artifact would therefore not need reflashing solely for RC6, but the reported RC5 build never reached compilation, so the next step is simply `make all` from RC6.

## 1.16.0-rc5

Direct live-initramfs installer correction after the RC4 hardware run:

- RC4 hardware-qualified the slim LAN-only initramfs and low-memory stream validator: `sysupgrade -T` passed, and the same validator passed again immediately before destructive dispatch;
- post-reset NOR evidence showed the predecessor rootfs_data split at `0x00c20000`, proving the stage2 failure happened before the first rootfs erase/write and therefore did not partially flash the device;
- stop invoking `sysupgrade -n` from the RAM installer. The router is already fully resident in initramfs, so a second OpenWrt ramfs pivot is unnecessary and adds a failure boundary;
- add the initramfs-only `/usr/sbin/rv220w-install-from-ram` helper. It refuses to run outside the release initramfs or while a persistent MTD root/overlay is mounted, revalidates the sysupgrade tar, streams/reads-back rootfs first, then kernel last, and reboots only after both SHA-256 checks pass;
- keep procd/watchdog alive during the direct flash operation instead of killing services for stage2;
- keep the host UART open through the entire destructive operation and subsequent reboot, with explicit validation/rootfs/kernel/PASS markers so any future failure is captured at the exact phase;
- change the second confirmation token from `SYSUPGRADE RV220W` to `INSTALL RV220W` so the UI accurately describes the direct installer while still using a standard validated OpenWrt sysupgrade image;
- retain normal OpenWrt/LuCI sysupgrade for already-installed systems, including the previously hardware-qualified configuration-preserving path.

RC5 changes the initramfs overlay/orchestration and release identity. Rebuild both public artifacts with `make all` before the next hardware run. Kernel/DTS/b43/DSA patch content, U-Boot patch bytes, NOR geometry, persistent first-boot defaults and normal configuration-preservation policy remain unchanged from RC4.

## 1.16.0-rc4

Liveboot-to-sysupgrade memory-pressure correction after the first RC3 RAM-boot hardware run:

- the RC3 initramfs TFTP/liveboot path itself hardware-qualified, including appended-DTS boot, persistent MTD geometry, BCM53115 DSA and BCM4322 discovery;
- fix the subsequent `sysupgrade -T` OOM by replacing RV220W target validation that extracted kernel + padded root + stripped root into `/tmp` with a streaming validator;
- for clean-install `sysupgrade -n` (no configuration backup), stream the root member directly from the sysupgrade tar into `rootfs`, verify its written prefix by SHA-256 readback, then stream/write/verify the kernel last;
- retain the previously hardware-qualified extraction/JFFS2 insertion path for normal configuration-preserving OpenWrt-to-OpenWrt upgrades;
- explicitly copy `sha256sum` into the sysupgrade stage2 RAMFS for streamed readback verification;
- slim the initramfs into a LAN-only installer/recovery profile: remove LuCI/uhttpd, b43/Wi-Fi/wpad and other production-facing services from the RAM image while leaving the persistent sysupgrade image unchanged in feature scope;
- make liveboot distinguish OOM evidence from a genuinely rejected/corrupt image and report expected failures without a Python traceback;
- request exclusive UART ownership in both the TFTP boot helper and post-boot serial shell;
- add a synthetic fake-MTD regression that exercises the complete streaming validate -> rootfs write/readback -> kernel write/readback sequence, plus validation against a real previously generated RV220W sysupgrade tar during release preparation.

RC4 changes the initramfs and the target-side platform sysupgrade implementation, so both initramfs and persistent sysupgrade artifacts must be rebuilt. Production first-boot defaults, U-Boot patch bytes/geometry, DTS, b43 hardware patch and normal configuration-preservation policy are otherwise unchanged.

## 1.16.0-rc3

U-Boot onboarding/verification hardening after the first successful clean RC2 build:

- fail cleanly before router interaction when the selected UART is already held by picocom/minicom/screen or another process; use exclusive serial opens throughout the prompt/dump/write helpers and report likely holder PIDs when visible;
- add `make u-boot-verify` for a read-only compatibility/environment check;
- define patch compatibility only from the preserved 512 KiB boot-chain region and qualified 128 KiB sector-0 CRC; Cisco kernel/rootfs/config bytes elsewhere in NOR are never compared;
- add a warning-gated fast backup mode that saves the 512 KiB boot-chain plus final 128 KiB U-Boot environment (640 KiB total) instead of the complete 32 MiB NOR;
- retain the complete 32 MiB backup as the default/safest archival option;
- detect stock-compatible, partially patched and fully qualified patched U-Boot states;
- inspect the saved OpenWrt U-Boot environment independently of the code patch;
- when an already-qualified patch is detected, offer verify-only/no-change, environment re-save/repair, or an explicit forced sector rewrite so the automated write path can be tested on an already-patched development unit;
- remove Python traceback leakage for expected UART/prompt/dump failures.

No kernel, DTS, OpenWrt image configuration, Wi-Fi/LED defaults, U-Boot patch bytes, flash geometry, or sysupgrade implementation changed from rc2.

## 1.16.0-rc2

Build-environment reliability hotfix after first clean `make all` qualification:

- isolate the release container as `rv220w-openwrt-release` instead of reusing the promotion/research Distrobox;
- remove `head -1` pipelines from `set -o pipefail` provisioning and artifact-selection paths, eliminating possible SIGPIPE/status-141 false failures;
- make apt-cache cleanup non-fatal after the build environment has already validated;
- add exact failing-command/status/line diagnostics to container provisioning;
- retain a complete provisioning transcript at `build/logs/distrobox-provision.log`;
- make Python release helpers derive the release version from `VERSION` to prevent future RC version-skew mistakes.

No RV220W kernel, DTS, OpenWrt patch, image configuration, first-boot defaults, U-Boot patch bytes, or flash geometry changed from rc1.

## 1.16.0-rc1

First release-oriented tree after the RV220W promotion/research phase.

### Release structure

- Replaced the promotion-toolkit-first workflow with a top-level Makefile.
- Added `make all`, `make u-boot-patches`, and `make initramfs-liveboot` as the normal public entry points.
- Pinned the base source to OpenWrt `v25.12.5`; the release also records the exact pinned feed checkouts in `build/source-lock.json`.
- Collapsed the active platform delta into four subsystem patch groups: OpenWrt integration, generic SSB/SPROM, Octeon platform/DSA, and b43/BCM4322.
- Reduced the target overlay to production runtime files only.
- Moved historical collectors, analyzers, diagnostic modules, debug interfaces, experiments, and documentation under `history/`.

### Production defaults

- Fresh LAN defaults to `192.168.1.1/24`.
- Fresh wireless defaults to an enabled open 2.4 GHz `OpenWrt` AP.
- The first-boot wireless migration recognizes OpenWrt's pristine disabled generated template and enables it, while preserving real administrator wireless configuration on later sysupgrades.
- The mainboard WLAN GPIO LED defaults to `netdev` TX+RX activity on `phy0-ap0`.
- Mainboard LED trigger selection remains userspace policy rather than a b43 hardware requirement.

### Runtime cleanup

- `B43_DEBUG` is disabled in both release profiles, eliminating the historical b43 debug chatter from production builds.
- Standalone SSB-NVMEM, Octeon PCI IRQ and other research diagnostics are not packaged in the release image.
- `tcpdump-mini` and the promotion data-collection payloads are not part of the default image.
- Full `wpad`, LuCI and LuCI package management remain in the immutable rootfs.

### Stock-device onboarding

- Added a guarded U-Boot bootstrap that captures U-Boot automatically after power-cycle, dumps the complete 32 MiB NOR before writing, validates the two qualified instruction sites and final sector CRC, then applies the known minimal policy patch and OpenWrt boot environment only after explicit confirmation.
- Added a guided initramfs TFTP liveboot that monitors UART for successful OpenWrt startup.
- Added an optional first-install sysupgrade path with host/target SHA-256 comparison, `sysupgrade -T`, and a separate destructive confirmation before `sysupgrade -n`.

### Baseline

The hardware implementation is derived from the V1158 image qualified by the v1.15.10 host gate. That baseline proved normal NOR boot, persistent b43 Wi-Fi/AP operation, immutable full-wpad/LuCI package management, configuration-preserving sysupgrade, and DTS-defined POWER/DIAG/WLAN/DMZ GPIO LEDs.

RC1 intentionally changes image defaults and the public build flow, so the collapsed release workflow requires one clean end-to-end qualification run before promotion to final `1.16.0`.
