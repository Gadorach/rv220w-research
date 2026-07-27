# RAM-only SquashFS live design

The toolkit retains a `squashfs-live` mode that embeds a generated SquashFS root inside a small initramfs launcher, copies it into RAM, mounts it read-only, adds a tmpfs overlay, and switches root without touching NOR.

```fish
cd openwrt
./rv220w.fish build squashfs-live
./rv220w.fish tftp-boot --profile squashfs-live --interface <host-interface> --configure-interface
```

## Current qualification boundary

The proven complete wired profile is the `rj45-full` initramfs image. This document does not claim that a persistent SquashFS/sysupgrade layout has been tested on the onboard flash.

## Safety properties

- no NOR root mount;
- no persistent overlay;
- reboot discards changes;
- failed root transition returns to a RAM-resident recovery shell rather than writing storage.

LuCI, WLAN, VPN suites, and other large packages should remain excluded from minimal RAM validation images until memory use is measured.
