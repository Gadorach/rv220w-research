# Bootloader and RAM boot

## Confirmed U-Boot environment

Important variables:

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

Default boot command:

```text
cp.b BDC80000 0x2a00000 580000;
bootoctlinux 0x2a00200 mtdparts=phys_mapped_flash:512k(bootloader)ro,6M(kernel),16M(rootfs),1024k(data),128k(bootload-env)
```

The firmware container starts at `0xbdc80000`; the ELF begins 0x200 bytes later. U-Boot copies 0x580000 bytes to RAM and calls `bootoctlinux 0x2a00200`.

## Useful commands

Available commands include `tftpboot`, `bootp`, `http`, `loadb`, `loads`, `cp`, `crc32`, `md`, `flinfo`, `pci`, `mii`, `bcmmii`, `bootoctlinux`, and `bootelf`. There is no `bootm` and no outbound TFTP upload command.

## RAM-boot rules

- Use TFTP or serial download to place a complete big-endian Octeon ELF in RAM.
- Use a source/load buffer around `0x05500000` unless image-size analysis proves another safe range.
- Do not overwrite the stock kernel copy area or U-Boot structures.
- Begin with serial-only initramfs and no NOR writes.
- Prove transport with the recovered stock ELF before blaming a custom kernel.

## Recovery

Ctrl+C during firmware checking reaches U-Boot. The first 512 KiB and final environment sector must remain preserved until JTAG and external programming recovery are qualified.
