# UART `md.b` parser regression — 2026-07-20

## Symptom

The v0.8.0 dumper repeatedly stopped while reading the chunk beginning at
`0xbdc30000`, reporting:

```text
missing md.b line at 0xbdc38640
```

The same address failed on every retry at both 460800 and 230400 baud. The
first `0x30000` bytes had already been written and their host CRC32
`208d4c20` matched the target prefix CRC32.

## Root cause

This was **not a UART data-loss event**.

The raw transcript contains a complete `bdc38640` row on all nine recorded
attempts. Each complete attempt produced the same 64 KiB chunk content.

The old line expression used `\s` for spacing. Python treats CR and LF as
whitespace for `\s`. The preceding row at `bdc38630` contained sixteen
`0x20` bytes, so its ASCII rendering was entirely spaces. The expression's
optional ASCII-column matcher consumed those spaces, the CR/LF, and the next
`bdc38640` row. The parser therefore falsely reported that the next row was
missing even though it was present in the serial log.

Representative transcript:

```text
bdc38630: 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20
bdc38640: 20 20 20 20 20 20 3a 20 25 36 64 20 70 73 0a 00
```

## Fix in v0.8.1

- Parse one physical line at a time with `splitlines()`.
- Restrict spacing expressions to horizontal whitespace `[ \t]`.
- Reject conflicting duplicate rows instead of silently overwriting them.
- Add a regression test covering an all-space ASCII column followed by another
  data row.

The fixed parser successfully reconstructs all nine previously failed
`0xbdc30000` responses. Their reconstructed 64 KiB payloads are identical and
have SHA-256:

```text
8ad9b1188218a3b11ad8c0635de9cd78b630b2b6d209ec6c1825d777c5af38ff
```

## Confirmed console-rate result

- 921600 baud: rejected by this U-Boot build.
- 460800 baud: accepted and prompt synchronization confirmed.
- 230400 baud: accepted.

Use 460800 as the preferred dump rate. The observed effective payload rate of
approximately 9 KiB/s is expected because `md.b` expands every 16 raw bytes
into roughly 80 transmitted characters.

## Resume command

The existing `0x30000`-byte output is valid and should be resumed rather than
discarded:

```bash
python rv220w_dump_uboot_flash_uart_v0.8.1.py \
  /dev/serial/by-id/usb-FTDI_FT232R_USB_UART_A50285BI-if00-port0 \
  --target-baud 460800 \
  --output rv220w-flash-32MiB-read1.bin
```

The script will recalculate the host prefix CRC32, compare it with the target,
and continue at `0xbdc30000`.
