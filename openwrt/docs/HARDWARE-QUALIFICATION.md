# RV220W hardware qualification status

**Release:** `1.16.0-rc7`

**Status:** release-ready RC

The final RC7 workflow completed end-to-end hardware qualification on a Cisco RV220W. The table distinguishes direct hardware evidence from logic/synthetic coverage where appropriate.

| Area | Status | Qualification |
|---|---|---|
| Clean `make all` build workflow | PASS | Clean release build completed on supported CachyOS/Distrobox host workflow. |
| Dedicated Ubuntu 24.04 Distrobox | PASS | Provisioning and cached release-worktree reuse exercised. |
| Minimal four-patch release stack | PASS | Built into working images after collapse from promotion tree. |
| U-Boot automatic interception | PASS | Real RV220W UART hardware. |
| UART-busy handling | PASS/policy | Fail-clean behavior implemented at all public serial entry points; exclusive-open enforcement retained. |
| 640 KiB bootloader-only backup | PASS | 512 KiB boot-chain + 128 KiB environment captured and target/host CRC verified. |
| Full 32 MiB backup path | PASS/baseline | Full-NOR UART dump workflow was qualified during development and remains available as archival option. |
| Already-patched U-Boot detection | PASS | Qualified sector identified correctly on hardware. |
| Forced qualified sector rewrite | PASS | TFTP load, RAM CRC, erase/write, NOR CRC, reprotect and `saveenv` all exercised on hardware. |
| Stock-U-Boot byte-state recognition | LOGIC-TESTED | Stock/partial/unknown states are covered by deterministic synthetic regressions; destructive stock-unit branch shares the hardware-qualified write machinery. |
| Initramfs TFTP liveboot | PASS | ELF transfer, Octeon load and Linux boot observed on hardware. |
| Persistent MTD geometry | PASS | 512 KiB boot-chain, 6 MiB kernel, 25,984 KiB rootfs, 128 KiB environment observed. |
| BCM53115 DSA / LAN | PASS | Switch discovery, DSA tree and LAN forwarding observed. |
| BCM4322/b43 | PASS | SPROM/MAC path, N-PHY startup, AP/client operation and normal persistent lifecycle qualified during V1158/release testing. |
| Low-memory `sysupgrade -T` validation | PASS | Real RC image validated from slim initramfs without OOM. |
| Direct initramfs installer startup | PASS | RC7 shell-library compatibility fix exercised successfully. |
| Rootfs direct write + readback | PASS | Rootfs-first streamed write completed and SHA-256 readback passed. |
| Kernel-last direct write + readback | PASS | Kernel write completed after rootfs and SHA-256 readback passed. |
| Normal NOR reboot after direct install | PASS | Router returned through qualified patched U-Boot into persistent OpenWrt. |
| Fresh LAN default `192.168.1.1/24` | PASS | Release default retained and qualified in final workflow. |
| Fresh 2.4 GHz `OpenWrt` AP | PASS | Release first-boot policy qualified. |
| WLAN LED `netdev` TX+RX on `phy0-ap0` | PASS | Mainboard GPIO LED policy qualified. |
| POWER/DIAG/WLAN/DMZ GPIO LEDs | PASS | DTS-defined class devices qualified by v1.15.10 hardware gate and retained in release. |
| LuCI + immutable package management | PASS | Qualified persistent image functionality. |
| LuCI configuration-preserving sysupgrade | PASS | Hardware-qualified; settings survive ordinary OpenWrt-to-OpenWrt upgrade. |
| `B43_DEBUG` disabled / research tools absent | PASS | Release configuration/static verifier; no historical diagnostic payload in runtime image. |

## Release boundary

RC7 is considered ready for public release. The one intentionally narrower evidence item is the untouched-stock U-Boot **classification branch**: its exact byte-state logic is regression-tested, while the actual destructive erase/write/environment machinery was hardware-qualified by a forced rewrite of an already-qualified unit. Unknown bootloader content remains fail-closed.

No historical RF discovery/calibration tooling is required for normal release use; it remains under `history/` for provenance.
