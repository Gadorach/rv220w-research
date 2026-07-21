# OpenWrt promotion plan

## Principle

All development begins as RAM-only boot. NOR remains unchanged until recovery, board support, and installation are independently proven.

## P0 — preservation — complete

- Two identical full-flash captures.
- Bootloader, partitions, stock ELF, rootfs, and data extracted.
- JP1 console confirmed.

## P1 — reproducible build environment

- CachyOS host with fish, Podman, and Distrobox.
- Ubuntu 24.04 build container.
- Pinned OpenWrt, Linux, and reference repository revisions.
- Build logs and source-lock manifest.

## P1.5 — TFTP transport proof

TFTP the recovered stock ELF into RAM and boot it using `bootoctlinux`. This separates network transport and physical-port issues from OpenWrt kernel issues.

## P2 — generic Octeon initramfs

Build a minimal OpenWrt Octeon ELF with serial console, BusyBox, proc/sysfs/devtmpfs, and no persistent storage. Success is a stable shell over JP1.

## P3 — RV220W board support

Add board identity and a device tree or equivalent Octeon board description for:

- CN5010 and 128 MiB RAM,
- UART,
- PCI/Mini PCI,
- clocks and reset,
- read-only BootBus NOR,
- MAC-address source.

## P4 — read-only NOR

Expose the 32 MiB CFI device and verified partition map. Reject writes in the first bring-up configuration.

## P5 — native Ethernet

Determine `octeth0/1/2` mapping, RGMII mode, MAC addresses, and whether any path can operate without external-switch configuration.

## P6 — BCM53115

Identify MDIO/pseudo-PHY address, CPU/IMP port, RGMII delays, VLAN defaults, and tag behavior. Establish one untagged forwarding path, then promote toward B53/DSA.

## P7 — board services

Map reset button, LEDs, watchdog, and any GPIO-controlled resets or power enables.

## P8 — RAM-only SquashFS live root

Embed a generated SquashFS inside an initramfs launcher, mount it read-only, add a tmpfs overlay, and `switch_root`. Reboot must discard all changes.

## P9 — persistent layout

Preserve at minimum:

```text
0x00000000–0x0007ffff  stock boot chain
0x01fe0000–0x01ffffff  actual environment/footer
```

Use only the middle application area after RAM-only validation and recovery qualification.

## P10 — installation/recovery qualification

Test interrupted writes, bad images, serial recovery, full restoration, and repeated cold boots before calling a sysupgrade path safe.

## P11 — WLAN

Bring up PCI and wired routing first. Prefer an ath9k-compatible replacement Mini PCI card over reconstructing the old proprietary BCM4322 stack.
