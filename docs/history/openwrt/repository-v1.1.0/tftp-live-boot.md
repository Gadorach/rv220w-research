# Proven TFTP RAM boot

## Current command

```fish
cd openwrt
./rv220w.fish build rj45-full
./rv220w.fish tftp-boot \
    --profile rj45-full \
    --interface <host-interface> \
    --configure-interface
```

The profile selector uses:

```text
$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-rj45-initramfs.elf
```

The direct-link defaults are host `192.168.240.1/24` and router LAN `192.168.240.2/24`.

## What is proven

- Serial interruption reaches `rv200w#`.
- U-Boot transfers the ELF by TFTP into RAM.
- `bootoctlinux` launches the modern kernel.
- OpenWrt reaches a running userspace.
- The live image initializes and operates LAN1–LAN4 and WAN.
- Reboot returns to stock firmware because no flash command is issued.

## Safety behavior

The helper only changes temporary environment variables, starts TFTP, and executes `bootoctlinux`. It never runs `saveenv` or a flash erase/program command.

Each test should retain the generated serial and TFTP logs. Record the toolkit version, source lock, artifact SHA-256, physical jack used for U-Boot transfer, and post-boot port-validation results.
