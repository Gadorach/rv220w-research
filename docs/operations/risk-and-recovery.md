# Risk and recovery

## Present safety boundary

The hardware-proven OpenWrt image is loaded by TFTP and runs entirely from RAM. No persistent flash attempt has been made. Keep this boundary until installation and complete recovery are independently qualified.

## Highest-risk actions

- `saveenv` while the stock environment is not fully understood.
- Erasing or rewriting the first 512 KiB boot chain.
- Modifying the actual final environment/footer sector at `0x01fe0000`.
- Flashing an OpenWrt image before a tested partition plan and restore process exist.
- Enabling destructive reset-button semantics.
- Driving J2 before VREF and signal mapping are confirmed.

## Recovery tiers

1. **UART/U-Boot:** interrupt boot and TFTP-load a known-good RAM image.
2. **U-Boot flash restore:** future work; permit only after region addressing, verification, and interruption handling are scripted and tested.
3. **EJTAG:** use after J2 is fully verified.
4. **External flash programming:** isolate or remove the TSOP56 NOR and restore the complete verified image with suitable hardware.

## Required preservation

- Canonical complete flash image and hashes.
- Boot stub and U-Boot regions.
- Actual final U-Boot environment/footer sector.
- Recovered stock upgrade image.
- Partition map and extraction reports.
- JP1 pinout and U-Boot command transcript.
- Proven OpenWrt artifact, source lock, build log, and TFTP/serial validation logs.
