# Automated TFTP RAM boot

## Proven current workflow

```fish
./rv220w.fish build rj45-full
./rv220w.fish tftp-boot \
    --profile rj45-full \
    --interface <host-interface> \
    --configure-interface
```

The profile selects:

```text
$RV220W_WORKSPACE/artifacts/rv220w-openwrt-rv220w-rj45-initramfs.elf
```

The temporary direct-link defaults are:

```text
host/server: 192.168.240.1/24
device/LAN:  192.168.240.2/24
```

This workflow is hardware-proven to transfer the image, launch it with `bootoctlinux`, reach running OpenWrt, and initialize and operate all five RJ45 ports.

## Safety properties

The helper permits temporary U-Boot network setup, `tftpboot`, and one `bootoctlinux` launch. It does not run `saveenv`, disable flash protection, erase NOR, copy an image into NOR, or write through Linux MTD.

Accepted image formats are:

- ELF64 big-endian MIPS at file offset zero;
- a Cisco-style image with ELF magic at offset `0x200`.

With the default load address `0x05500000`, images extending beyond the conservative `0x07f00000` source-buffer limit are rejected.

## Proven Linux topology

```text
LAN1-LAN4 -> BCM53115 CPU port 8 -> eth0 -> br-lan
WAN        -> BCM53115 CPU port 5 -> eth1 -> wan
```

U-Boot uses its own `octeth` naming and may transfer through a different apparent interface name. Do not infer Linux DSA topology from the U-Boot name.

## Logs

Each run produces timestamped serial and TFTP logs. Preserve them with the artifact SHA-256, source lock, build log, physical test connection, and post-boot port results.

## Manual equivalent

For the current profile, the automated sequence is conceptually:

```text
base 0
setenv autoload no
setenv ipaddr 192.168.240.2
setenv serverip 192.168.240.1
setenv netmask 255.255.255.0
setenv ethact <working U-Boot octeth interface>
tftpboot 0x05500000 rv220w-openwrt-rv220w-rj45-initramfs.elf
bootoctlinux 0x05500000 console=ttyS0,115200
```

All temporary settings disappear on power cycle because `saveenv` is not called.

## Stock-kernel transport regression

The extracted stock ELF remains useful for separating U-Boot/TFTP transport from modern-kernel regressions:

```fish
set stock_args 'mtdparts=phys_mapped_flash:512k(bootloader)ro,6M(kernel),16M(rootfs),1024k(data),128k(bootload-env) console=ttyS0,115200'

./rv220w.fish tftp-boot \
    --interface <host-interface> \
    --configure-interface \
    --bootargs "$stock_args" \
    /path/to/partitions/01b-linux-kernel.elf
```
