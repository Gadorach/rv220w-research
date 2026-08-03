# Build and TFTP RAM boot

## Build environment

The supported workflow is CachyOS with fish and an Ubuntu 24.04 Distrobox.

```fish
cd openwrt
cp config/toolkit.env.fish.example config/toolkit.env.fish
./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
```

## Current profiles

```text
rj45-full   Routed five-port image, no LuCI, all NOR read-only
rj45-luci   Routed five-port image with LuCI, all NOR read-only
nor-writer  RAM-only maintenance image; only openwrt-slot writable
```

Build and RAM-boot the LuCI image:

```fish
./rv220w.fish build rj45-luci
./rv220w.fish tftp-boot \
    --profile rj45-luci \
    --interface <host-interface> \
    --configure-interface
```

TFTP RAM boot remains the primary recovery path even after persistent
installation. It changes only temporary U-Boot networking variables and invokes
`bootoctlinux`; it does not write NOR or save the environment.
