# Research matrix

| Subsystem | Identification | Electrical map | Stock-software map | Modern-driver path | Status |
|---|---:|---:|---:|---:|---|
| CN5010 CPU | Yes; directly photographed and boot-confirmed | Partial | Clocks/revision/boot ABI partly known | Existing OCTEON platform | Active analysis |
| DDR2 | Yes | No | 128 MiB; 266 MHz / 532 MT/s boot-confirmed | SoC memory controller | Inventory confirmed |
| Parallel NOR | Yes | Physical window/sector map known | MTD map plus conflicting env locations documented | CFI/physmap + BootBus | Dump ready; preservation pending |
| UART JP1 | Confirmed primary console | Pin 1 VCC/NC, pin 2 TX, pin 3 RX, pin 4 GND; VREF voltage pending | U-Boot + Linux ttyS0 at 115200 | 8250/OCTEON UART | P2 complete |
| UART/interface JP2 | Separate CPU-routed candidate | Unpowered resistance map | Unknown | 8250 or manufacturing interface TBD | Optional follow-on |
| EJTAG | High-confidence MIPS14 J2 | Resistance topology mapped | No | Adapter/tool support TBD | Pending powered verification |
| BCM53115 | Yes; directly photographed | No | U-Boot disable and Linux/userspace bring-up observed | Linux DSA b53 | Pending P9 |
| LEDs/buttons | Visible | Partial | Push-button factory-reset behavior observed | gpio-leds/gpio-keys | Pending P10 |
| Watchdog | Unknown | No | No | OCTEON or external | Pending P10 |
| Mini PCI WLAN | BCM4322 + photographed RF inventory | Partial | PCI 14e4:432b confirmed | b43/proprietary/replacement | Pending P11 |
| Regulators | Partial | No | N/A | fixed regulators where needed | Pending P1 |
