# Persistent OpenWrt installation

This operation can modify U-Boot and the OpenWrt kernel/rootfs partitions. Preserve recovery material and read [`../operations/risk-and-recovery.md`](../operations/risk-and-recovery.md) first.

## Requirements

- 3.3 V USB-UART on JP1 at 115200 8N1, with VCC disconnected.
- Direct Ethernet connection to one of the four LAN ports.
- Verified boot-chain/environment backup and external NOR recovery capability.

## Guided workflow

```console
make -C openwrt u-boot-verify
make -C openwrt u-boot-patches
make -C openwrt initramfs-liveboot
```

The liveboot helper finds the complete `prebuilt/` pair and asks whether to use it. Accept to validate and use the retained release images. Decline to use `openwrt/build/artifacts/`; missing source artifacts are built automatically.

The U-Boot helper recognizes known stock, partial, and qualified states, backs up either the full 32 MiB NOR or the 640 KiB bootloader-owned regions, and requires explicit confirmation before writing. Unknown content stops the workflow.

The RAM installer validates the sysupgrade stream, writes and verifies rootfs first, writes and verifies kernel last, and reboots only after both checks pass. Expected final markers are:

```text
RV220W_DIRECT_INSTALL_VALIDATION_PASS
RV220W_DIRECT_INSTALL_ROOTFS_PASS
RV220W_DIRECT_INSTALL_KERNEL_PASS
RV220W_DIRECT_INSTALL_PASS
```

Fresh defaults are LAN/LuCI at `192.168.1.1`, an open 2.4 GHz `OpenWrt` AP, and WLAN activity on `phy0-ap0`. Set a root password and secure Wi-Fi immediately.

For exact prompts, backup scopes, and failure handling, use [`../../openwrt/docs/INSTALL.md`](../../openwrt/docs/INSTALL.md).
