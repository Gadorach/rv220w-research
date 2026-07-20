# Firmware acquisition and validation

## Confirmed acquisition path

The complete 32 MiB memory-mapped NOR can be read from U-Boot through JP1 with `md.b`, with target-side `crc32` verification for each chunk and the complete range.

The canonical tool is:

```text
tools/uart/dump_uboot_flash_uart.py
```

It whitelists only read-oriented commands:

- `base 0`
- `md.b`
- `crc32`
- temporary `setenv baudrate`

It never invokes `saveenv`, `erase`, `protect off`, `cp`, `mw`, or a firmware update command.

## Recommended capture

```fish
python tools/uart/dump_uboot_flash_uart.py \
    /dev/serial/by-id/<adapter> \
    --target-baud 460800 \
    --output rv220w-flash-read1.bin
```

Repeat into a second file and compare SHA-256 and `cmp` output.

## Verified result

Two independent captures matched:

```text
CRC32:   ce96f3e0
SHA-256: 03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5
```

Both full target CRCs matched the host images before and after acquisition. Read 2 started at offset zero, completed all 512 64 KiB chunks, and required no retries.

## Preservation policy

- Keep the canonical full image and partition manifest together.
- Preserve the first 512 KiB boot chain and final 128 KiB environment/footer exactly.
- Do not run `saveenv`; the stock environment CRC is bad and U-Boot currently uses compiled defaults.
- Treat all flash writes as recoverability tests, not routine development steps.
