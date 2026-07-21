# JP1 primary UART and stock boot analysis — 2026-07-20

## Confirmed JP1 physical pinout

JP1 is the primary U-Boot and Linux serial console.

Pin 1 is the square pad and is furthest from the `JP1` silkscreen reference
designator. Number toward the `JP1` text:

| Physical pin | Target role | USB-UART connection | Status |
|---:|---|---|---|
| 1 | VCC/VREF | NC | Confirmed rail position; powered voltage not yet recorded |
| 2 | TX | Adapter RX | Confirmed from boot output |
| 3 | RX | Adapter TX | Confirmed from Ctrl-C and interactive commands |
| 4 | GND | Adapter GND | Confirmed |

Console settings are **115200 baud, 8 data bits, no parity, 1 stop bit**, with
no flow control. Never connect the USB-UART adapter VCC output to JP1.1.

The earlier resistance worksheet enumerated the pads from the opposite end. Its
row order is therefore physical JP1 pins 4, 3, 2, 1.

## Bootloader access

- U-Boot `1.1.1`, development build, `svnversion: 193M`.
- Build timestamp: `2012-06-14 15:20:38`.
- Prompt: `rv200w# `.
- `bootdelay=0`, but holding or repeatedly sending Ctrl-C during the firmware
  check reaches the prompt.
- Persistent environment CRC is bad, so U-Boot loads its compiled-in default
  environment.
- Do **not** run `saveenv` before the final flash sector has been preserved.

## Confirmed platform data

- Board string: `CUST_RV200W`, revision 1.0.
- SoC: OCTEON `CN5010-SCP`, pass 1.1.
- Core clock: 400 MHz.
- DDR clock: 266 MHz / 532 MT/s.
- DRAM: 128 MiB.
- Flash: 32 MiB CFI parallel NOR on a x16 bus.
- Flash IDs: manufacturer `0xc2`; device words `0x227e`, `0x2222`, `0x2201`.
- PCI device: Broadcom vendor `0x14e4`, device `0x432b`, matching the removable
  BCM4322-family Mini PCI WLAN card.
- U-Boot exposes `octeth0`, `octeth1`, and `octeth2`.
- Linux reports interface 0 with three RGMII ports.

## Stock firmware and Linux

- Firmware image: `RV220W-Firmware-1.0.4.17.img`.
- Reported image size: 22,184,064 bytes (`0x01528080`).
- Vendor magic: `FWCHKADDISABABA`.
- Kernel image is a 64-bit ELF.
- Linux: `2.6.21.7-Cavium-Octeon`.
- Toolchain: GCC 4.1.2, Cavium Networks 1.6.0 build 34.
- Cavium Ethernet SDK: 1.7.3 build 264.
- Linux console: `ttyS0`, MMIO `0x1180000000800`, IRQ 42, 16550A.
- SquashFS 3.0 and JFFS2 support are present.

## Default boot command

```text
cp.b BDC80000 0x2a00000 580000;
bootoctlinux 0x2a00200 \
  mtdparts=phys_mapped_flash:512k(bootloader)ro,6M(kernel),16M(rootfs),1024k(data),128k(bootload-env)
```

Interpretation:

1. Copy `0x580000` bytes from flash `0xbdc80000` to RAM `0x02a00000`.
2. Start the Cavium Linux ELF loader at `0x02a00200`.
3. Pass the five-part MTD map to Linux.

The first `0x200` bytes of the copied vendor object precede the ELF load address
and likely contain a Cisco/SerComm image header.

## Flash geometry

U-Boot reports:

```text
flash_base_addr=0xbdc00000
flash_size=0x02000000
env_addr=0xbfbe0000
env_size=0x00020000
```

`flinfo` confirms:

- range `0xbdc00000..0xbfc00000` exclusive;
- 256 sectors;
- `0x20000` / 128 KiB per sector;
- first four sectors protected;
- final sector at `0xbfbe0000` protected.

### Environment-address discrepancy

The Linux MTD partition named `bootload-env` is at offset `0x01780000`, CPU
address `0xbf380000`. U-Boot's active environment pointer is instead the final
sector at offset `0x01fe0000`, CPU address `0xbfbe0000`.

The kernel MTD map stops at offset `0x017a0000`, leaving `0x00860000` bytes of
the physical flash outside the Linux command-line partition table. The region
from `0xbf3a0000` through `0xbfbe0000` must be preserved and analyzed rather
than assumed blank.

## Available transfer commands

The command inventory includes `md`, `crc32`, `loadb`, `loads`, TFTP/BOOTP and
HTTP download commands. It does not list `saves`, `tftpput`, or another command
to upload arbitrary memory from the board.

Therefore the immediately available read-only full-flash acquisition path is:

1. read the memory-mapped flash with `md.b`;
2. parse the hex display on the host;
3. compare target and host CRC32 values;
4. acquire two independent full images.

See `docs/24-uboot-flash-dump-over-uart.md` and
`scripts/host/dump_uboot_flash_uart.py`.

## Hardware factory-reset observation

After the populated hardware reset button was used while Linux was running,
userspace performed an orderly shutdown and reboot. The next boot reported
`PUSH_BUTTON--> 1`, later printed `Loading default configurations...`, and
created hostname `routerB142A6`.

This confirms factory-default handling through the populated button. It does
not identify the unpopulated SW2 footprint and does not reveal the default
serial-console password.
