# Known unknowns

## Boot chain

- Exact bootloader and version.
- Bootloader storage offsets and environment format.
- Signed-image or secure-boot behavior, if any.
- Kernel load/entry addresses and compression format.

## CPU/board

- CN5010 GPIO assignments.
- BootBus chip-select, bus width, and timing values.
- Board type value in the OCTEON boot-info structure.
- UART controller/header mapping.
- Watchdog implementation.

## Ethernet

- CN5010 GMX interface used for BCM53115.
- CPU-port mode and port number.
- Switch management bus and address.
- Reset and power-control pins.
- WAN/LAN logical-to-physical mapping.

## Storage

- MTD partition offsets.
- Factory-data and calibration locations.
- Root filesystem and writable configuration design.

## Debug

- J2 EJTAG pinout and I/O voltage.
- JP1/JP2 exact functions.
- Whether bootloader recovery supports TFTP, serial, USB, or web recovery.
