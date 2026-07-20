# Known unknowns

## Boot chain

Confirmed:

- U-Boot 1.1.1 development build `193M`.
- Ctrl-C interruption despite `bootdelay=0`.
- Kernel source address, RAM copy address, copy size, and Linux ELF entry offset.
- Firmware image name, size, and magic string.

Still unknown:

- Exact format of the first `0x200` bytes before the Linux ELF.
- Contents/function of flash offset `0x00000000..0x00030000` before the U-Boot update body.
- Exact firmware-check header/layout and whether any cryptographic verification exists.
- Full OCTEON boot-info contents and board-type enum.

## CPU/board

- CN5010 GPIO assignments.
- Exact BootBus timing values.
- Watchdog implementation.
- Powered JP1.1 VREF voltage.
- JP2 protocol and controller mapping.

## Ethernet

- CN5010 GMX interface and exact lane used for BCM53115 CPU/IMP port.
- CPU-port mode and port number.
- Switch management bus and address.
- Reset and power-control pins.
- WAN/LAN logical-to-physical mapping.

## Storage

Confirmed:

- 32 MiB x16 CFI NOR at `0xbdc00000..0xbfc00000`.
- 256 × 128 KiB sectors.
- Linux command-line MTD offsets.
- Active U-Boot environment pointer at final sector `0xbfbe0000`.

Still unknown:

- Why the MTD partition named `bootload-env` is at `0xbf380000` instead of the active `env_addr`.
- Contents of both 128 KiB environment-like regions.
- Exact boundaries and formats of factory data, certificates, MAC data, and WLAN calibration.
- Purpose of the `0xbf3a0000..0xbfbe0000` kernel-unpartitioned/vendor region.
- Rootfs/config extraction details pending the first verified dump.

## Debug and recovery

- J2 EJTAG powered VREF and active-signal verification.
- Whether EJTAG can halt/read/write this production configuration.
- Highest console baud compiled into the vendor U-Boot baud table.
- Whether a later RAM-loaded raw UART/Ethernet dumper can safely return to U-Boot.
- Recovery-server behavior of the vendor `download`, `assign`, and `http` commands.

## Buttons

- Exact GPIO and debounce behavior of the populated factory-reset button.
- Relationship, if any, between the populated button and unpopulated SW2.
- SW2 function: reset, recovery strap, WPS/user input, or manufacturing mode.

## WLAN module

- Module underside component inventory.
- Independent part-number confirmation for the two photographed `SiGe / 2547A / 2069CHF` devices.
- Function of module U3 (`A766A`-like marking).
- J1/J2/J4 antenna-chain and band mapping.
- Location and format of SPROM/NVRAM/calibration data.
- Host Mini PCI reset, clock, interrupt, and power-enable controls.
