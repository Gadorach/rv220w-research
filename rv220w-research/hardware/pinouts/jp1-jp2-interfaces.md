# JP1 and JP2 interfaces

## JP1 — confirmed primary UART

Pin 1 is the square pad furthest from the `JP1` reference designator.

| Pin | Target role | USB-UART | Resistance to GND |
|---:|---|---|---:|
| 1 | VCC/VREF | NC | ~346 Ω |
| 2 | TX | Adapter RX | ~8 kΩ |
| 3 | RX | Adapter TX | ~600 kΩ |
| 4 | GND | Adapter GND | 0 Ω |

Protocol: 115200 8N1, no flow control. U-Boot prompt: `rv200w#`. Temporary 230400 and 460800 baud are supported without `saveenv`.

## JP2 — separate interface candidate

JP2’s two signal nets are independent from JP1. Each corresponding cross-header resistance is approximately the sum of the two nodes’ individual resistances to ground, and the four signal traces route separately toward the CPU.

JP2 may be the second CN5010 UART or a manufacturing interface. Its pin numbering, voltage, direction, and protocol remain unconfirmed.
