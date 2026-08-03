# Cisco RV220W OpenWrt toolkit

Integrated v1.10.3 build, TFTP, LuCI, and guarded parallel-NOR tooling for the
Cisco RV220W.

## Current hardware result

- OpenWrt 25.12.5 / Linux 6.12.94.
- LuCI at `http://192.168.240.2/` on LAN.
- All five RJ45 ports through B53/DSA.
- Verified 22 MiB `openwrt-slot` write and full read-back SHA-256.
- Automatic boot from NOR after the separate combined boot-policy patch.
- Physical-button Sercomm recovery retained.
- Wi-Fi and persistent writable root/overlay remain unsupported.

## Mandatory prerequisite

Apply and verify the combined boot-policy patch before persistent firmware
promotion. See [`../docs/openwrt/installation.md`](../docs/openwrt/installation.md).
The toolkit intentionally does not patch the boot chain or save the U-Boot
environment automatically.

## Profiles

```text
rj45-full   Routed five-port RAM image; all NOR read-only
rj45-luci   Routed five-port LuCI image; all NOR read-only
nor-writer  TFTP/RAM-only maintenance image; only openwrt-slot writable
```

## Build

```fish
cp config/toolkit.env.fish.example config/toolkit.env.fish
./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
./rv220w.fish build rj45-luci
./rv220w.fish build nor-writer
```

## Guarded slot write

```fish
./rv220w.fish tftp-boot --profile nor-writer --interface <host-interface> --configure-interface
./rv220w.fish nor-stage status
./rv220w.fish nor-stage backup
./rv220w.fish nor-stage write --confirm RV220W_WRITE_OPENWRT_SLOT
./rv220w.fish nor-stage boot-plan
```

The boot plan copies the manifest's exact ELF byte count from `0xbdc80000` to
`0x05500000` and invokes `bootoctlinux`. Direct `bootoct` from flash is invalid.
After a successful manual test, configure the patched U-Boot environment as
documented in the repository installation guide.

## Documentation

- [`docs/README.md`](docs/README.md)
- [`docs/CURRENT_STATUS.md`](docs/CURRENT_STATUS.md)
- [`docs/INSTALLATION.md`](docs/INSTALLATION.md)
- [`docs/BUILD_AND_RAMBOOT.md`](docs/BUILD_AND_RAMBOOT.md)
- [`docs/FLASH_LAYOUT.md`](docs/FLASH_LAYOUT.md)
- [`docs/VALIDATION.md`](docs/VALIDATION.md)

Original v1.10.3 version and stage notes are preserved under
[`../docs/history/openwrt/toolkit-v1.10.3/`](../docs/history/openwrt/toolkit-v1.10.3/).
