# RV220W OpenWrt promotion toolkit

This directory contains the CachyOS/fish/Distrobox workflow for source preparation, OpenWrt and Linux builds, UART capture, extraction, and automated TFTP RAM boot.

Canonical low-level tools live at repository root under `tools/`; they are not duplicated here.

## Entry point

```fish
./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
./rv220w.fish dump --from-power-cycle --baud 460800 --double --extract
./rv220w.fish extract ../firmware/images/rv220w-flash-32MiB-canonical.bin
./rv220w.fish build initramfs
./rv220w.fish build squashfs-live
./rv220w.fish tftp-boot --interface <interface> --configure-interface <image.elf>
```

## Layout

- `config/` — OpenWrt build configs and user-overridable fish environment.
- `files/base/` — common OpenWrt root overlay.
- `files/squashfs-live/` — RAM-only SquashFS launcher.
- `scaffold/` — RV220W device-tree/profile placeholders.
- `scripts/` — fish workflows and TFTP serial automation.

See the canonical plan and procedures in `../docs/openwrt/`.
