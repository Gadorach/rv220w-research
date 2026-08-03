# Build and RAM boot

See [`../../docs/openwrt/build-and-ramboot.md`](../../docs/openwrt/build-and-ramboot.md).

Core commands:

```fish
./rv220w.fish build rj45-luci
./rv220w.fish build nor-writer
./rv220w.fish tftp-boot --profile nor-writer --interface <host-interface> --configure-interface
```
