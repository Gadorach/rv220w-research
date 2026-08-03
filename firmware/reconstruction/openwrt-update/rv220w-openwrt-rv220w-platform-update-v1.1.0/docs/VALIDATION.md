# Package validation

Completed against the captured OpenWrt 25.12.5 Octeon target and the promotion-toolkit v1.0.4 tree:

- OpenWrt patch: `git apply --check` passed.
- Promotion-toolkit patch: `git apply --check` passed.
- The embedded Linux DTS patch applies cleanly to the captured Linux 6.12 Cavium-Octeon DTS directory.
- The modified inner OpenWrt build helper passes `bash -n` after patch application.
- The precompiled reference DTB is FDT version 17 and parses back successfully.
- Python DTB construction helper passes `python3 -m py_compile`.
- Fish apply/revert scripts passed static structure checks; the analysis container did not have a Fish interpreter, so execute-time Fish syntax validation remains for the CachyOS host.
- No sysupgrade image is declared for the RV220W profile.
- B53/DSA, gpio-keys activation, DT BootBus programming, and flash writes remain deliberately disabled.

The reference DTB is included for inspection and comparison. The OpenWrt build compiles the included DTS through the normal kernel device-tree build and appends that result to the ELF.
