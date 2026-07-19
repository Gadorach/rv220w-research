# Flash analysis workflow

## Initial inventory

```sh
python3 scripts/host/firmware_inventory.py full-flash.bin --json full-flash.inventory.json
sha256sum full-flash.bin
file full-flash.bin
binwalk full-flash.bin
```

## Search targets

- Bootloader strings: `U-Boot`, `OCTEON`, `Cavium`, `bootcmd`, `bootoctlinux`.
- Kernel markers and command line.
- MTD partition tables.
- SquashFS, CramFS, JFFS2, gzip, LZMA/XZ, uImage, ELF.
- Board identifiers: `RV220W`, `YK910A`, MAC OUI, serial fields.
- BCM53115 register access, Broadcom RoboSwitch, MDIO, SPI, pseudo-PHY.
- GPIO names and LEDs/buttons.

## Analysis products

Commit derived metadata, not private configuration content:

- `mtd-map.csv`
- signature/offset report
- extracted kernel configuration if recoverable
- device-tree or board-file fragments
- symbol/string index
- checksums and tool versions

Keep original full dumps in secure offline storage and outside public Git history.
