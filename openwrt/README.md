# RV220W OpenWrt promotion toolkit

Fish-first tooling for building, validating, and TFTP RAM-booting experimental modern OpenWrt on the Cisco RV220W from a CachyOS host and Ubuntu 24.04 Distrobox.

## Current result

Toolkit v1.9.0 is hardware-proven to boot completely from RAM and operate all five RJ45 ports. The `rj45-full` profile uses separate B53/DSA CPU conduits for four LAN ports and WAN, with LAN DHCP, WAN DHCP/DHCPv6, firewall4, NAT, and PPPoE support.

**LuCI is not included. Wi-Fi is not implemented. Persistent flash has not been attempted.** The supplied workflows do not run `saveenv`, erase NOR, or write through Linux MTD.

See [`docs/CURRENT_STATUS.md`](docs/CURRENT_STATUS.md) and [`docs/README.md`](docs/README.md) for details.

## Quick start

```fish
cp config/toolkit.env.fish.example config/toolkit.env.fish

./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
./rv220w.fish platform verify
./rv220w.fish build rj45-full
./rv220w.fish tftp-boot \
    --profile rj45-full \
    --interface <host-interface> \
    --configure-interface
```

Expected image:

```text
$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-rj45-initramfs.elf
```

## Other profiles

- `initramfs` — generic Octeon transport/kernel regression.
- `discovery` — passive board, MDIO, and switch discovery.
- `dsa-lan` — four-port LAN DSA baseline.
- `dsa-dual` — dual-conduit diagnostic profile without normal router policy.
- `squashfs-live` — RAM-only SquashFS/overlay design validation.

## Safety

The TFTP helper temporarily sets U-Boot network variables, transfers the ELF, and calls `bootoctlinux`. It does not persist environment changes or issue a flash command. Reboot returns to the untouched stock firmware.
