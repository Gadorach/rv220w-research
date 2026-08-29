# RV220W installation guide

This guide covers a clean build, first installation on a Cisco RV220W, and later OpenWrt upgrades.

## 1. Build the release

Supported host: CachyOS/Arch Linux with fish, Podman and Distrobox.

From the release root:

```console
make all
```

Building is optional when using the hardware-qualified images retained in the repository-level `prebuilt/` directory.

The build creates/reuses the isolated `rv220w-openwrt-release` Ubuntu 24.04 Distrobox, checks out OpenWrt `v25.12.5` and every feed at the exact commits in `source-lock.json`, applies the four active RV220W patch groups and builds:

```text
build/artifacts/rv220w-openwrt-release-initramfs.elf
build/artifacts/rv220w-openwrt-release-sysupgrade.tar
```

Verify completed artifacts at any time with:

```console
make artifacts-check
```

## 2. Hardware connections

For onboarding you need:

- a 3.3 V USB-UART adapter connected to RV220W JP1 at **115200 8N1**;
- UART VCC **left disconnected**;
- an Ethernet cable directly between the host and one of the four RV220W LAN ports.

Close picocom, minicom, screen or any other process using the selected UART before running the helpers. The release tries to detect/claim the serial device exclusively and fails before router interaction if another visible process owns it.

## 3. Optional read-only U-Boot verification

```console
make u-boot-verify
```

This performs a read-only check and captures:

- 512 KiB `boot-chain`;
- 128 KiB U-Boot environment.

Compatibility is intentionally based only on the preserved bootloader code/known patch sites. The Cisco kernel/rootfs/config areas are ignored because they can legitimately differ between vendor firmware revisions.

## 4. Prepare U-Boot

```console
make u-boot-patches
```

The helper will:

1. ask for the UART;
2. offer either a full 32 MiB backup or the warning-gated 640 KiB bootloader-only backup;
3. ask you to power-cycle the router and automatically interrupt U-Boot;
4. identify stock-compatible, partially-patched-compatible or qualified-patched code;
5. verify the two known instruction locations and the qualified sector-0 CRC;
6. inspect `openwrt_boot`, `bootcmd`, `bootdelay` and `preboot` separately;
7. stop before any write for an unknown bootloader state;
8. require the explicit destructive confirmation before a sector/environment write;
9. verify the rewritten sector and saved environment after the operation.

An already-qualified unit can be left unchanged, have only its OpenWrt environment repaired, or be deliberately force-rewritten to exercise the automation.

The qualified U-Boot policy uses:

```text
bootdelay=3
bootcmd=run openwrt_boot
```

with `preboot` removed and the qualified `openwrt_boot` command installed.

## 5. RAM liveboot and permanent install

```console
make initramfs-liveboot
```

When the complete `../prebuilt/` pair exists, the helper asks whether to use it. Accept to verify and flash the bundled release. Decline to use `build/artifacts/`; missing source artifacts are built automatically. Use `make initramfs-liveboot LIVEBOOT_ARGS=--prebuilt` or `LIVEBOOT_ARGS=--built` for non-interactive source selection.

The host temporarily uses:

```text
host TFTP:  192.168.240.1/24
U-Boot IP:  192.168.240.2
```

These addresses are only for U-Boot/TFTP. The OpenWrt installer itself comes up at `192.168.1.1`.

The helper automatically intercepts U-Boot, TFTP-loads the LAN-only initramfs and watches UART until the OpenWrt RAM boot is confirmed.

The initramfs intentionally omits production LuCI/Wi-Fi/wpad to preserve RAM for validation and the NOR install. You can stop here for a recovery/live environment without touching persistent firmware.

If you choose permanent installation, the host:

1. serves/downloads the persistent sysupgrade tar;
2. compares its target SHA-256 with the host artifact;
3. runs the low-memory `sysupgrade -T` compatibility check;
4. requires the explicit confirmation `INSTALL RV220W`;
5. invokes `/usr/sbin/rv220w-install-from-ram` directly from the already-running initramfs.

The direct installer deliberately avoids OpenWrt's second stage2/ramfs pivot. It keeps procd/watchdog alive, revalidates the image, writes **rootfs first**, verifies the written bytes by SHA-256 readback, writes **kernel last**, verifies that readback, then reboots.

Expected destructive-phase markers are:

```text
RV220W_DIRECT_INSTALL_BEGIN
RV220W_DIRECT_INSTALL_VALIDATION_PASS
RV220W_DIRECT_INSTALL_ROOTFS_BEGIN
RV220W_DIRECT_INSTALL_ROOTFS_PASS
RV220W_DIRECT_INSTALL_KERNEL_BEGIN
RV220W_DIRECT_INSTALL_KERNEL_PASS
RV220W_DIRECT_INSTALL_PASS
RV220W_DIRECT_INSTALL_REBOOTING
```

UART capture remains open through the write and subsequent U-Boot/Linux reboot.

## 6. First persistent boot

Expected defaults:

```text
LAN:        192.168.1.1/24
LuCI:       http://192.168.1.1/
Wi-Fi:      OpenWrt, 2.4 GHz, initially open
WLAN LED:   netdev, device phy0-ap0, TX + RX
```

Immediately:

1. set a root password;
2. enable WPA2/WPA3 security and choose your own SSID/passphrase;
3. configure WAN/LAN as appropriate for your network.

## 7. Later upgrades

Once the router is already running this RV220W OpenWrt port, use normal OpenWrt sysupgrade. LuCI's **System -> Backup / Flash Firmware** flow has been hardware-qualified with configuration preservation.

The direct initramfs installer is intended for first installation/recovery, not as a replacement for normal OpenWrt-to-OpenWrt upgrades.
