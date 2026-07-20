# Platform overview

## Goal

Develop a reproducible, evidence-based understanding of the RV220W sufficient to preserve the original firmware, recover the board, boot modern Linux entirely from RAM, and promote hardware support toward OpenWrt.

## Evidence vocabulary

- **Observed:** directly photographed, measured, or captured.
- **Confirmed:** reproduced or independently supported by authoritative documentation.
- **Inferred:** the best current explanation, but not yet proven.
- **Unknown:** insufficient evidence.

## Confirmed platform

- Cisco RV220W-A V01, PCB `YK910A-1.6`.
- Cavium OCTEON Plus CN5010-SCP pass 1.1, one active core at 400 MHz.
- 128 MiB DDR2, 266 MHz clock / 532 MT/s data rate.
- 32 MiB x16 CFI NOR at U-Boot window `0xbdc00000`.
- Broadcom BCM53115 five-port Gigabit switch.
- BCM4322 Mini PCI WLAN module, PCI ID `14e4:432b`.
- U-Boot 1.1.1 development build, revision `193M`.
- Linux 2.6.21.7-Cavium-Octeon, big-endian MIPS64.
- JP1 primary UART at 115200 8N1.

## Research order

1. Preserve identifiers and firmware.
2. Establish passive serial access.
3. Verify a complete flash read path.
4. Qualify recovery and RAM boot.
5. Add modern Linux support one subsystem at a time.
6. Write persistent storage only after the RAM-only path is repeatable.

## Current disposition

The source router is a retired display/research unit. The package therefore preserves all factory-reset configuration data without redaction. This includes an obsolete device HTTPS private key in the JFFS2 extraction. It is retained as historical evidence and must not be reused.
