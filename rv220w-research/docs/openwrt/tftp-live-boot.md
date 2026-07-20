# Automated TFTP live boot

## Workflow

The `openwrt/rv220w.fish tftp-boot` action:

1. Detects or accepts the host interface and IPv4 address.
2. Optionally assigns a temporary direct-link address.
3. Starts a temporary `dnsmasq` TFTP server.
4. Opens JP1 at 115200 baud.
5. Sends Ctrl+C until `rv200w#` is captured.
6. Sets temporary `ipaddr`, `serverip`, and `netmask` values without `saveenv`.
7. Tries selected `octeth` interfaces.
8. Runs `tftpboot` to the configured RAM address.
9. Verifies the transferred byte count and ELF placement.
10. Calls `bootoctlinux` and records serial/TFTP logs.
11. Restores temporary host network state.

## Transport proof

First test with the recovered stock ELF:

```fish
./rv220w.fish tftp-boot \
    --interface enp5s0 \
    --configure-interface \
    ../firmware/derived/01b-linux-kernel.elf
```

Use the stock command line from the boot log when testing the factory kernel.

## OpenWrt test

```fish
./rv220w.fish build initramfs
./rv220w.fish tftp-boot \
    --interface enp5s0 \
    --configure-interface \
    "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-generic-initramfs.elf"
```

## Limits

U-Boot disables the BCM53115 during startup. If no front-panel port generates TFTP traffic, collect read-only `mii`/`bcmmii` evidence instead of guessing switch writes.
