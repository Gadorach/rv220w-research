# Current OpenWrt status

## Working on hardware

- OpenWrt 25.12.5 / Linux 6.12.94.
- Automatic boot from the onboard parallel NOR through the patched stock U-Boot chain.
- LuCI and uHTTPd on LAN at `http://192.168.240.2/`.
- LAN1-LAN4 bridged as `br-lan` with DHCP service.
- Independent WAN conduit with DHCP/DHCPv6 client support.
- firewall4 LAN/WAN separation, LAN-to-WAN forwarding, and masquerading.
- All five RJ45 jacks through B53/DSA.
- Guarded 22 MiB OpenWrt slot backup, write, and full read-back verification.
- Physical-button Sercomm recovery retained after the boot-chain patch.

## Current image type

The persistent slot contains a padded initramfs ELF. The image survives power
cycles, but runtime configuration does not. Every boot recreates the root
filesystem and UCI state from the image.

## Mandatory external state

Automatic boot depends on:

- combined boot-policy sector CRC32 `b77a94de`;
- a valid `openwrt-slot` image at `0xbdc80000`;
- an `openwrt_boot` variable whose copy length matches the current ELF manifest;
- `bootcmd=run openwrt_boot` and no duplicate `preboot` launch.

## Not implemented

- persistent writable overlay;
- supported sysupgrade/factory image format;
- Wi-Fi driver, firmware, calibration, association, or RF validation;
- complete LEDs, reset-button Linux policy, watchdog, and GPIO promotion.
