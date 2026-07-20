# Stock software architecture

## Boot chain

```text
Boot stub → U-Boot 1.1.1 → Cisco/Sercomm image header → ELF64 Octeon kernel → SquashFS rootfs + JFFS2 data
```

Kernel details:

- Linux 2.6.21.7-Cavium-Octeon.
- Cavium toolchain 4.1.2 / SDK-era platform code.
- Board type string `CVMX_BOARD_TYPE_CUST_RV200W`.
- Serial console `ttyS0` at 115200.
- 120 MiB usable from the 128 MiB installed RAM.

## Filesystems

The SquashFS 3.0 root contains roughly 3,789 regular files, 86 directories, and 185 symlinks. The factory-reset JFFS2 tree includes logs, HTTPS certificate/key, factory-default marker, and Bonjour data.

## Ethernet

Key modules and paths:

- `cavium-ethernet.ko` — Octeon packet I/O, RGMII, hardware offload, Broadcom tag hooks.
- `mii.ko` — switch MDIO wrapper.
- `bcm5398.ko` — BCM53115 register, port, VLAN, and mirror configuration despite the generic module name.

Useful unstripped symbols include switch register reads/writes and port/VLAN setters. Module and kernel string reports are under `firmware/analysis/reports/`.

## WLAN

The stock system uses proprietary `wl.ko` and extensive TeamF1-style WLAN userspace commands.

## Buttons and LEDs

- `push_button.ko` handles the reset/factory-default button path.
- `scm-led.ko` handles board LEDs.
- A hardware reset produced orderly userspace shutdown, `PUSH_BUTTON--> 1` on the next boot, and loading of default configuration.

## Reimplementation strategy

Do not recreate Cisco’s proprietary management stack. Replace it with standard OpenWrt components: `procd`, `ubus`, `netifd`, `firewall4`, `dnsmasq`, `dropbear`, and a B53/DSA-based switch path.
