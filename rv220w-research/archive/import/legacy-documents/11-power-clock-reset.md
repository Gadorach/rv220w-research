# Power, clock, and reset mapping

## Measurement record

Use `hardware/voltage-rail-template.csv` and commit scope screenshots/raw CSV captures.

For every rail record:

- test point/component;
- voltage before, during, and after reset;
- startup delay and monotonicity;
- ripple under idle and Ethernet load;
- suspected consumers;
- regulator controller/inductor association.

## Clock targets

- Y3: 25 MHz.
- Y4: 25 MHz.
- U11 output: likely 125 MHz.
- U13/U84: unidentified oscillators.
- CN5010 reference/DDR clocks: recover from boot log or probe only with appropriate loading.

## Reset targets

- CN5010 system reset.
- BCM53115 switch reset.
- Mini PCI reset.
- Front-panel reset button.
- Watchdog-triggered reset.

Never probe BGA clock nets with long ground leads or low-impedance probes.
