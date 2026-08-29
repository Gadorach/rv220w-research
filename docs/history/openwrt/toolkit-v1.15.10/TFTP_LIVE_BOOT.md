# Automated TFTP live boot

## Safety properties

The helper permits only these U-Boot prompt commands:

```text
base 0
setenv autoload no
setenv ipaddr ...
setenv serverip ...
setenv netmask ...
setenv ethact ...
tftpboot ...
```

After transfer, it issues one `bootoctlinux` command.  It never runs `saveenv` or any flash command.

## Image requirements

The helper accepts:

- an ELF64 big-endian MIPS image at file offset zero, or
- a Cisco-style image with ELF magic at offset `0x200`.

It refuses unknown formats.  With the default load address `0x05500000`, it also refuses a source image extending beyond `0x07f00000`.

## Direct-link example

```fish
./rv220w.fish tftp-boot \
  --interface enp5s0 \
  --configure-interface \
  "$RV220W_WORKSPACE/artifacts/rv220w-openwrt-generic-initramfs.elf"
```

The temporary direct-link defaults are:

```text
host/server: 192.168.240.1/24
device:      192.168.240.2/24
```

If the interface already has IPv4, its address and netmask are used automatically and the helper chooses an unused-looking peer address in the same subnet.

## Physical port uncertainty

U-Boot reports three Octeon interfaces but also prints `disable 53115 ... Done`.  Until the port map is proven, the helper tries:

```text
octeth0
octeth1
octeth2
```

A TFTP request visible in the server log proves that the selected U-Boot interface and current physical jack provide a path.  If all three fail, move the cable to another RV220W jack and repeat.  Do not infer the final Linux port map from U-Boot numbering alone.

## Logs

Each run produces:

```text
rv220w-tftp-boot-<UTC>.serial.log
rv220w-tftp-boot-<UTC>.tftp.log
```

Keep complete logs, including failures.  The first useful milestone is kernel output over JP1, even if network or rootfs later fails.

## Manual equivalent

Once the server and addresses are known, the automated sequence is equivalent to:

```text
base 0
setenv autoload no
setenv ipaddr 192.168.240.2
setenv serverip 192.168.240.1
setenv netmask 255.255.255.0
setenv ethact octeth0
tftpboot 0x05500000 rv220w-openwrt-generic-initramfs.elf
bootoctlinux 0x05500000 console=ttyS0,115200
```

All settings disappear on power cycle because `saveenv` is not called.


## Transport validation with the stock ELF

The extractor produces `partitions/01b-linux-kernel.elf`. Booting that known stock kernel through TFTP is a useful promotion gate before trying OpenWrt:

```fish
set stock_args 'mtdparts=phys_mapped_flash:512k(bootloader)ro,6M(kernel),16M(rootfs),1024k(data),128k(bootload-env) console=ttyS0,115200'

./rv220w.fish tftp-boot   --interface enp5s0   --configure-interface   --bootargs "$stock_args"   /path/to/partitions/01b-linux-kernel.elf
```

A successful result proves the UART interruption, U-Boot network interface, physical jack, host address selection, TFTP service, transfer-size verification, RAM load address, and `bootoctlinux` path independently of OpenWrt.

## Limits of automation

The helper can try `octeth0`, `octeth1`, and `octeth2`, but it cannot move the physical cable. U-Boot also reports that it disables the BCM53115 during startup. If no jack produces a TFTP request, capture `help bcmmii`, `help mii`, and read-only switch-register observations before adding any switch-control command to the automation. Unknown `bcmmii` writes are intentionally not guessed.
