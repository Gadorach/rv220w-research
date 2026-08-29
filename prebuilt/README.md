# Hardware-qualified RC7 images

This directory contains the two images needed by the guided first-install workflow:

- `rv220w-openwrt-release-initramfs.elf` is the RAM-resident installer and recovery image.
- `rv220w-openwrt-release-sysupgrade.tar` is the persistent kernel/rootfs image.

Run `make -C openwrt prebuilt-check` before manual use. `make -C openwrt initramfs-liveboot` detects this complete pair and asks whether to use it. Declining uses existing `openwrt/build/artifacts/` output or builds the missing source artifacts.

The images are for the Cisco RV220W only. Read [`../openwrt/docs/INSTALL.md`](../openwrt/docs/INSTALL.md) and [`../openwrt/docs/RECOVERY.md`](../openwrt/docs/RECOVERY.md) before allowing any NOR write.
