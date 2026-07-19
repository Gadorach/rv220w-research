# Research matrix

| Subsystem | Identification | Electrical map | Stock-software map | Modern-driver path | Status |
|---|---:|---:|---:|---:|---|
| CN5010 CPU | Yes | Partial | No | Existing OCTEON platform | Inventory only |
| DDR2 | Yes | No | No | SoC memory controller | Inventory only |
| Parallel NOR | Yes | Partial | No | CFI/physmap + BootBus | Inventory only |
| UART | Candidate headers | No | No | 8250/OCTEON UART likely | Pending P2 |
| EJTAG | Candidate J2 | No | No | Adapter/tool support TBD | Pending P5 |
| BCM53115 | Yes | No | No | Linux DSA b53 | Pending P9 |
| LEDs/buttons | Visible | No | No | gpio-leds/gpio-keys | Pending P10 |
| Watchdog | Unknown | No | No | OCTEON or external | Pending P10 |
| Mini PCI WLAN | Yes | Partial | No | b43/proprietary/replacement | Pending P11 |
| Regulators | Partial | No | N/A | fixed regulators where needed | Pending P1 |
