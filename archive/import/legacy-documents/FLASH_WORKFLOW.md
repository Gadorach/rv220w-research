# Stock flash capture and extraction workflow

## UART capture

JP1 is confirmed as:

| Pin | Function | USB-UART |
|---:|---|---|
| 1 | VCC/VREF | NC |
| 2 | target TX | RX |
| 3 | target RX | TX |
| 4 | GND | GND |

Pin 1 is the square pad furthest from the `JP1` reference marking.

The dumper uses `md.b` and target-side `crc32`, validates every chunk, and validates the full image before and after reading.  It supports resume and temporary 460800-baud operation.

## Known physical map

| Offset | Size | Content |
|---:|---:|---|
| `0x00000000` | `0x00030000` | boot stub |
| `0x00030000` | `0x00050000` | U-Boot |
| `0x00080000` | `0x00600000` | vendor header + Linux ELF + padding |
| `0x00680000` | `0x01000000` | SquashFS 3.0 big-endian rootfs |
| `0x01680000` | `0x00100000` | JFFS2 data/config |
| `0x01780000` | `0x00020000` | erased Linux-named `bootload-env` |
| `0x017a0000` | `0x00840000` | erased vendor tail |
| `0x01fe0000` | `0x00020000` | actual final U-Boot environment/footer sector |

The extractor preserves overlapping derived objects such as the complete kernel ELF and recovered Cisco upgrade image in addition to the physical regions.


## Automated cold-start capture

The fish wrapper can capture U-Boot from a user-initiated power cycle before starting the dump:

```fish
./rv220w.fish dump --from-power-cycle --baud 460800 --double --extract
```

The pre-capture helper sends only carriage return and Ctrl+C. It exits at `rv200w#`; the separate validated dumper then performs the read-only `md.b`/`crc32` acquisition.
