# Dumping the complete flash through U-Boot and JP1 UART

## Objective

Acquire the entire 32 MiB parallel NOR without changing flash contents.

The supplied host tool is:

```text
scripts/host/dump_uboot_flash_uart.py
```

## Confirmed JP1 connection

```text
JP1.1  VCC/VREF     leave NC
JP1.2  target TX    USB-UART RX
JP1.3  target RX    USB-UART TX
JP1.4  GND          USB-UART GND
```

JP1.1 is the square pad furthest from the `JP1` silkscreen. Use 115200 8N1 and
no flow control. Never connect adapter VCC.

## Why `md.b` is the first preservation method

This U-Boot build has memory display and CRC32 commands, but no listed serial or
network upload command. `loadb`, `loads`, TFTP, BOOTP, and HTTP move data into
the board rather than uploading arbitrary flash data.

The script therefore uses the memory-mapped NOR window and only these commands:

```text
base 0
md.b <address> <length>
crc32 <address> <length>
setenv baudrate <rate>       # optional, RAM-only environment change
```

It refuses non-whitelisted commands and never issues `saveenv`, `erase`,
`protect off`, `cp`, `mw`, or vendor update macros.

## Required dump range

```text
start: 0xbdc00000
size:  0x02000000
end:   0xbfc00000 exclusive
```

Do not dump only the five Linux MTD partitions. The final active U-Boot
environment sector and an 8.375 MiB kernel-unpartitioned tail would be missed.

## Host setup

CachyOS / fish:

```fish
python -m venv .venv
source .venv/bin/activate.fish
python -m pip install -r scripts/host/requirements-uart-dump.txt
```

Bash-compatible shells:

```bash
python -m venv .venv
source .venv/bin/activate
python -m pip install -r scripts/host/requirements-uart-dump.txt
```

Stop the board at `rv200w# ` by holding Ctrl-C during the firmware-check stage,
then close any terminal program using the serial device.

## Stage 1 — prove the parser at 115200

Dump the first 64 KiB:

```bash
python scripts/host/dump_uboot_flash_uart.py \
  /dev/serial/by-id/<adapter> \
  --size 0x10000 \
  --output rv220w-first-64KiB-115200.bin
```

The script must report matching target and host CRC32 values and create:

- the binary image;
- a JSON metadata file;
- a gzip-compressed raw UART transcript.

## Stage 2 — use the confirmed 460800-baud console

This U-Boot build rejects `921600` but accepts `460800` and `230400`. Use
`460800` as the preferred dump rate:

```bash
python scripts/host/dump_uboot_flash_uart.py \
  /dev/serial/by-id/<adapter> \
  --target-baud 460800 \
  --size 0x10000 \
  --output rv220w-first-64KiB-460800.bin
```

The baud change is RAM-only because the script never invokes `saveenv`. A power
cycle returns the console to 115200.

### v0.8.0 parser regression

A repeated failure at `0xbdc38640` was caused by the host parser, not dropped
serial data. The v0.8.0 regular expression used `\s`, which allowed an
all-space ASCII column to consume CR/LF and the following `md.b` row. Version
0.8.1 parses one physical line at a time and uses horizontal whitespace only.
See `docs/25-uart-md-parser-regression-2026-07-20.md`.

## Stage 3 — full dump

```bash
python scripts/host/dump_uboot_flash_uart.py \
  /dev/serial/by-id/<adapter> \
  --target-baud 460800 \
  --output rv220w-flash-32MiB-read1.bin
```

Approximate transfer times for text-formatted `md.b` output:

| Baud | Approximate duration |
|---:|---:|
| 115200 | about 4 hours |
| 230400 | about 2 hours |
| 460800 | about 1 hour |

The estimate includes address, hexadecimal, ASCII, and line-ending overhead.
Actual time depends on the USB-UART adapter, retry count, and the vendor UART implementation.

## Validation behavior

For every chunk, the script:

1. requests `md.b` output;
2. validates each displayed address;
3. reconstructs the exact byte count;
4. calculates host CRC32;
5. asks U-Boot for CRC32 over the same range;
6. retries on parsing or CRC mismatch;
7. flushes and fsyncs the output.

For the whole image it records target CRC32 before and after transfer, host
CRC32, host SHA-256, timestamps, baud, range, chunk size, and retry count. A
successful full dump requires matching target and host CRC32 values.

## Resume behavior

Re-run the same command with the same output filename. The script verifies the
existing prefix against target flash before continuing. Use `--restart` only to
discard an incomplete image deliberately.

## Required final acquisition set

Acquire two images in separate sessions:

```text
rv220w-flash-32MiB-read1.bin
rv220w-flash-32MiB-read2.bin
```

Verify:

```bash
sha256sum rv220w-flash-32MiB-read*.bin
cmp rv220w-flash-32MiB-read1.bin rv220w-flash-32MiB-read2.bin
```

Do not begin flash writes until the two full images are byte-identical and
stored off-device.

## Manual smoke test

At the U-Boot prompt:

```text
base 0
md.b bdc00000 100
crc32 bdc00000 100
```

U-Boot numeric arguments are hexadecimal, so `100` means `0x100` bytes.

## Later faster path

After the first verified baseline exists, `loadb` can place a custom RAM-only
MIPS64/Octeon dumper on the board. A framed raw transfer at the highest reliable supported baud could be
substantially faster than `md.b`, or a RAM payload could upload over Ethernet.
That optimization requires a known-safe RAM range, a matching big-endian
Octeon toolchain, framing/CRC, and a tested return/reboot path. It is not the
recommended first preservation method.
