# Flash layout and extraction

## Physical map

| Offset | Size | Role |
|---:|---:|---|
| `0x00000000` | `0x00030000` | Early boot stub / stage 1 |
| `0x00030000` | `0x00050000` | U-Boot proper |
| `0x00080000` | `0x00600000` | Firmware header, Linux ELF, and padding |
| `0x00680000` | `0x01000000` | Big-endian SquashFS 3.0 rootfs |
| `0x01680000` | `0x00100000` | Big-endian JFFS2 data/config |
| `0x01780000` | `0x00020000` | Linux-named `bootload-env`; erased |
| `0x017a0000` | `0x00840000` | Unmapped erased vendor tail |
| `0x01fe0000` | `0x00020000` | Actual U-Boot environment/footer sector |

Flash geometry is 256 sectors of 128 KiB. U-Boot maps the 32 MiB device at `0xbdc00000`.

## Environment discrepancy

Linux names the region at offset `0x01780000` as `bootload-env`, but U-Boot uses `env_addr=0xbfbe0000`, corresponding to offset `0x01fe0000`. The Linux-named partition is erased; the actual final sector has a bad environment CRC and 16 non-`FF` bytes at the end.

## Canonical artifacts

- `firmware/images/rv220w-flash-32MiB-canonical.bin`
- `firmware/images/RV220W-Firmware-1.0.4.17-recovered.img`
- `firmware/partitions/` — non-overlapping physical regions.
- `firmware/derived/` — boot stub, U-Boot, header, ELF kernel, and boot-copy extent.
- `firmware/filesystems/rootfs/` — extracted SquashFS.
- `firmware/filesystems/data-jffs2/` — extracted factory-reset configuration, unredacted.
- `firmware/analysis/` — manifests, strings, module reports, and file inventories.

## Firmware container

The recovered stock image begins at flash offset `0x00080000`, declares size `0x01528080`, and identifies:

```text
Firmware: 1.0.4.17
Hardware: 1.0
Family:   RV220W-Firmware
Name:     RV220W-Firmware-1.0.4.17.img
Trailer:  FWCHKADDISABABA
```

The stored big-endian checksum at header offset `0x14` equals the additive byte sum over the declared image when that checksum field is zeroed.

## Extraction

```fish
python tools/firmware/extract_rv220w_flash.py \
    firmware/images/rv220w-flash-32MiB-canonical.bin \
    work/extracted
```

The custom read-only extractors support the observed big-endian SquashFS 3.0 and JFFS2 formats. Canonical reports and hashes are already included.
