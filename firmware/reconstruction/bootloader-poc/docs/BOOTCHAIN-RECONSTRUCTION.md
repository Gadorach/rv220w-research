# Boot-chain reconstruction

## Preserved binary map

```text
NOR offset       Size       Reconstructed content
0x00000000       0x80000    complete boot-chain region
0x00000000       0x30000    lower boot/reset/U-Boot code region
0x00030000       0x50000    stock bootloader-update range
0x0006ff00       0x00100    base-MAC/board-data vicinity
0x00080000       ...        firmware slot
0x01fe0000       0x20000    actual U-Boot environment sector
```

The authoritative 512 KiB input has SHA-256:

```text
0630714e3e86edfeeed064088266c59524d970e0b74780e903b68b45e8982e7d
```

The exact `0x30000–0x7ffff` extraction has SHA-256:

```text
1b68453e055dee56a8724b17a927df36ff201a44c8e450c5d17a3b8e9117000d
```

## Why the update range is not a stage boundary

The vendor environment advertises:

```text
uboot_flash_addr=0xbdc30000
uboot_flash_size=0x50000
```

That identifies the region the vendor updater chooses to rewrite. It does not imply that offsets below `0x30000` are only a small immutable ROM stub. Recovered functions below that boundary include:

- `board_init_r` at `0xffffffffbfc01298`;
- environment and command-processing helpers;
- `rv220w_board_late_init` at `0xffffffffbfc13084`;
- `do_bootelf` at `0xffffffffbfc140ec`;
- the environment-setting core at `0xffffffffbfc190f4`;
- `do_bootoctlinux` at `0xffffffffbfc1d950`;
- the Sercomm firmware checker at `0xffffffffbfc22834`.

The upper region contains additional executable code, strings, tables, the HTTP recovery application and board-specific persistent bytes. A replacement must therefore treat the entire 512 KiB as a linked image even when only a subrange is being updated.

## Reconstructed late-init order

The recovered `rv220w_board_late_init` performs the following sequence:

1. selects/initializes the board network path;
2. configures GPIO 1 as input and reads it;
3. prints `PUSH_BUTTON-->` and invokes the button download path when active low;
4. validates the Sercomm firmware wrapper at flash offset `0x80000`;
5. invokes HTTP recovery when validation returns negative;
6. unconditionally tail-calls the environment setter with `bootcmd` and the compiled stock command.

The final operation occurs after environment relocation. This explains why a CRC-valid environment is imported and custom variables survive while `bootcmd` alone is replaced.

## Firmware wrapper checker

The checker at `0xffffffffbfc22834` reads:

```text
image name: flash 0xffffffffbdc80074, 32 bytes
image size: flash 0xffffffffbdc80010, big-endian 32-bit
trailer:    flash_start + image_size - 0x80
magic:      FWCHKADDISABABA
```

It rejects sizes above 32 MiB and returns `0` on a matching trailer, `-1` otherwise. The later update path is responsible for the full-image additive checksum. The stock header checksum is the modulo-2^32 sum of all image bytes after zeroing header field `0x14–0x17`.

## Cold-start replacement gap

The reconstruction does not yet provide an independent implementation of:

- reset-vector and exception entry;
- CP0, cache and TLB initialization;
- CN5010 PLL/clock setup;
- DDR2 controller programming and training;
- BootBus chip-select timing;
- early UART before DRAM;
- watchdog/reset control;
- complete PIP/PKO Ethernet setup.

Those functions are the reason the initial PoC deliberately retains the vendor cold-start path.
