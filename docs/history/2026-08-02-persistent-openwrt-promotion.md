# 2026-08-02 persistent OpenWrt promotion

This milestone superseded the 2026-07-27 RAM-only project status.

Completed on hardware:

- LuCI-enabled OpenWrt RAM boot.
- Guarded 22 MiB `openwrt-slot` backup, write, and full read-back verification.
- Correction from invalid direct flash `bootoct` to copy-to-RAM plus `bootoctlinux`.
- Bootcmd-overwrite suppression at boot-chain offset `0x13168`.
- Selective invalid-format HTTP-recovery bypass at offset `0x13138`.
- Saved automatic OpenWrt boot policy with a three-second interrupt window.
- Normal automatic OpenWrt boot from NOR.
- Retention of active-low physical-button Sercomm recovery.

Historical v1.10.3 documents still describe manual first boot and prohibit
`saveenv` because those were the correct boundaries before the boot-policy
patch was validated. Current requirements are in `../openwrt/installation.md`.
