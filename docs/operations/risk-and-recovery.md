# Risk and recovery

## Highest-risk actions

- `saveenv` while the stock environment CRC is bad.
- Erasing or rewriting the first 512 KiB boot chain.
- Driving J2 before VREF and signal mapping are confirmed.
- Flashing an image before RAM boot and recovery are qualified.
- Guessing BCM53115 writes that may isolate the only network path.

## Recovery tiers

1. **UART/U-Boot:** interrupt boot, TFTP or serial-load an image, restore selected regions.
2. **EJTAG:** halt/reset and inspect memory once J2 is verified.
3. **External flash programming:** desolder or isolate the TSOP56 parallel NOR and program with supported hardware.

## Required preservation

- Canonical full image and hashes.
- Boot stub and U-Boot images.
- Actual final U-Boot environment/footer sector.
- Recovered stock upgrade image.
- Partition manifest.
- JP1 pinout and U-Boot command transcript.
