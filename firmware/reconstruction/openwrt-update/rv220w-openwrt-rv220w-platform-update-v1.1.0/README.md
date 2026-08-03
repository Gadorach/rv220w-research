# Cisco RV220W OpenWrt platform update v1.1.0

This package promotes the proven generic Octeon RAM boot to a conservative Cisco RV220W-specific OpenWrt validation profile. It contains no flash installer and the RV220W device profile emits no sysupgrade image.

## What changes

- Adds `cisco,rv220w` / `Cisco RV220W` board identity.
- Appends `cn5010_cisco_rv220w.dtb` to the ELF kernel.
- Keeps the three CN5010 RGMII/PIP ports represented; ports 0 and 1 retain the 1000/full fixed-link behavior already validated by the generic live tree.
- Disables the Octeon USB node that previously hung in `octeon_usb_probe()`.
- Disables DT-driven BootBus reconfiguration for the first board-specific build; the already validated legacy `phys_mapped_flash` path is retained.
- Splits the complete 32 MiB NOR into read-only command-line partitions, including the actual final 128 KiB U-Boot environment sector.
- Represents the BCM53115 at pseudo-PHY MDIO address `0x1e`, but leaves its Linux driver node disabled so U-Boot's working switch state is preserved.
- Represents the U-Boot-proven GPIO 1 active-low reset/recovery input, but leaves the Linux key node disabled for safety.
- Prevents Ubiquiti-only device-tree pruning from running on non-UBNT boards.
- Adds a toolkit build mode named `rv220w-initramfs`.

## Apply

From the extracted update package:

```fish
./scripts/apply-rv220w-platform-update.fish \
    --openwrt ~/src/rv220w-openwrt/sources/openwrt \
    --toolkit ~/src/rv220w-research/rv220w-research/promotion-toolkit
```

The script performs both `git apply --check` operations before modifying either repository.

## Build

```fish
cd ~/src/rv220w-research/rv220w-research/promotion-toolkit
./rv220w.fish build rv220w-initramfs
```

Expected staged artifact:

```text
~/src/rv220w-openwrt/artifacts/rv220w-openwrt-rv220w-initramfs.elf
```

## RAM-only boot

```fish
set nic enp0s31f6
set uart /dev/serial/by-id/usb-FTDI_FT232R_USB_UART_A50285BI-if00-port0
set image ~/src/rv220w-openwrt/artifacts/rv220w-openwrt-rv220w-initramfs.elf

./rv220w.fish tftp-boot \
    --interface "$nic" \
    --configure-interface \
    --device-ip 192.168.240.2 \
    --ethact octeth0 \
    --port "$uart" \
    "$image"
```

Do not pass alternate boot arguments on the first run: the device profile embeds the USB guard and read-only MTD layout.

## Safety boundary

- No `saveenv`.
- No MTD writes or erases.
- No sysupgrade image is emitted for this profile.
- BCM53115 B53/DSA management remains disabled.
- Reset-button and software LED activation remain disabled.
- DT BootBus timing remains disabled until independently confirmed.

## Evidence notes

See `docs/U-BOOT-CONFIRMATIONS.md` for the U-Boot-derived hardware facts and `docs/DT-EVIDENCE-MATRIX.md` for confidence boundaries. The profile is intentionally a high-confidence **boot/validation DT**, not yet a final B53/DSA topology.

The included `artifacts/cn5010_cisco_rv220w.dtb` is a structurally validated reference generated from the captured generic OpenWrt DTB. During a real build, OpenWrt compiles `cn5010_cisco_rv220w.dts` using the kernel build system and appends that compiled DTB to the initramfs ELF.
