# Known unknowns

## Boot and flash

- Header fields at offsets `0x04` and `0x08`.
- Meaning of the final 16 non-erased bytes in the actual environment sector.
- Exact stage-1 boot-stub responsibilities.
- Whether all stock image-validation paths use the same additive checksum.

## Debug and controls

- JP2 protocol and powered behavior.
- J2 VREF voltage and active EJTAG confirmation.
- Exact SW2 function.
- Complete reset/watchdog topology.

## Ethernet

- Physical jack-to-Octeon interface mapping.
- BCM53115 MDIO address, CPU port, RGMII delays, and tag mode.
- U-Boot switch state required for TFTP.

## Board services

- Complete GPIO/LED map.
- MAC-address storage and board identity source.
- Power-enable/reset GPIOs for switch and Mini PCI.

## WLAN

- Antenna-chain mapping.
- Calibration/SPROM location.
- Exact identity of the SiGe-marked front-end devices.
