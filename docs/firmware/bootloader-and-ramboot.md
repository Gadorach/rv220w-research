# Bootloader and RAM boot

## Confirmed U-Boot environment

Important variables include:

```text
bootdelay=0
baudrate=115200
loadaddr=0x5500000
numcores=1
flash_base_addr=0xbdc00000
flash_size=0x2000000
uboot_flash_addr=0xbdc30000
uboot_flash_size=0x50000
env_addr=0xbfbe0000
env_size=0x20000
ethact=octeth0
```

The stock firmware container starts at `0xbdc80000`; its ELF begins at offset `0x200`.

## Proven modern RAM-boot contract

The current OpenWrt ELF is loaded by TFTP around `0x05500000` and started with `bootoctlinux`. This path has been proven to boot the complete experimental OpenWrt system and initialize all five RJ45 ports.

The automated helper uses temporary U-Boot variables only:

```text
base 0
setenv autoload no
setenv ipaddr ...
setenv serverip ...
setenv netmask ...
setenv ethact ...
tftpboot ...
bootoctlinux ...
```

It does not call `saveenv`, `erase`, `protect`, `cp` to NOR, or a flash-update script. Power cycling returns to the original firmware.

## Current image profile

```fish
cd openwrt
./rv220w.fish build rj45-full
./rv220w.fish tftp-boot \
    --profile rj45-full \
    --interface <host-interface> \
    --configure-interface
```

The profile is an initramfs-based experimental image. It is not a persistent installation image.

## Recovery baseline

Ctrl+C during startup reaches `rv200w#`. Preserve the first 512 KiB boot chain, the final environment sector, and the complete verified flash image until independent flash restore and external-programmer recovery are qualified.
