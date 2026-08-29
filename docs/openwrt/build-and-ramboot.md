# Build and TFTP RAM boot

## Reproducible source build

The supported host workflow is CachyOS/Arch with fish, Podman, and an Ubuntu 24.04 Distrobox.

```console
make -C openwrt all
```

`openwrt/source-lock.json` pins OpenWrt and all five feeds. Source preparation checks out those commits before feed installation. Build products are written to `openwrt/build/artifacts/`.

Public profiles are:

- LAN-only initramfs installer/recovery ELF.
- Persistent LuCI/Wi-Fi sysupgrade image.

## RAM boot

```console
make -C openwrt initramfs-liveboot
```

If the retained pair exists, the helper prompts to use `prebuilt/`; declining selects source-built artifacts. The host uses `192.168.240.1/24` only for U-Boot TFTP, while OpenWrt starts at `192.168.1.1`.

TFTP RAM boot does not write NOR. A separate prompt, image validation, and exact `INSTALL RV220W` confirmation guard permanent installation.
