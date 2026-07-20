# Topside and WLAN photo review — 2026-07-19

This note records findings from the second photographic evidence set:

- `evidence/photos/original/topside-exposed-01.jpg`
- `evidence/photos/original/topside-exposed-02.jpg`
- `evidence/photos/original/topside-exposed-03.jpg`
- `evidence/photos/original/wlan-module-topside-01.jpg`
- `evidence/photos/original/wlan-module-topside-02.jpg`
- `evidence/photos/original/wlan-module-topside-03.jpg`

Derived maps are available as:

- `evidence/photos/annotated/topside-exposed-labelled.jpg`
- `evidence/photos/annotated/wlan-module-topside-labelled.jpg`
- `evidence/photos/public/topside-exposed-redacted.jpg`

A later, larger board-photo archive supersedes these as the best current whole-board evidence for physical layout; see `docs/19-full-board-photo-archive-review.md`.

## Main board observations

The heatsinks and WLAN card are removed in this evidence set, exposing the major devices and their physical relationships.

### Confirmed directly from visible markings

- PCB revision: `YK910A-1.6`, marked “Manufactured for Cisco.”
- CPU: Cavium OCTEON Plus `CN5010-400BG564-SCP-G`.
- Ethernet switch: Broadcom `BCM53115SKFBG`.
- RAM: two Etron `EM68B16CWQD-25H` devices.
- Parallel NOR: Macronix `MX29GL256EHT2I-90Q` at U4.
- Full-size Mini PCI socket between the switch/flash region and the lower half of the PCB.
- J2 is a 2×7 array of exposed test pads near the RAM and board edge.

### Layout implications

- The BCM53115 sits between the Ethernet magnetics and CN5010, strongly supporting a direct CPU-port connection between the SoC and switch.
- Dense parallel routing between U4, the adjacent latch/glue logic, and the CN5010 region is consistent with a BootBus parallel-NOR implementation.
- The two DDR2 devices are placed close to the CN5010 with closely length-matched routing.
- J2 is physically close to the CPU/RAM side of the board, which remains consistent with the EJTAG hypothesis, but no pin function is proven by placement alone.
- The front-panel LED/transistor network is concentrated along the board edge opposite the Ethernet connectors.
- Multiple switching and linear regulator sections are distributed around the CPU, Mini PCI socket, and input connector; rail assignments still require measurement.

## WLAN module observations

### Board identity and form factor

- Full-size Mini PCI card, not Mini PCI Express.
- Module PCB marking appears to be `YK910MO-1.0`.
- Additional PCB marking: `CK77 94V-0`.
- Three U.FL-style antenna connectors are populated and labelled J2, J4, and J1 on the module PCB.

### Visible active devices

- Main WLAN controller: Broadcom `BCM4322LKFBG`.
- Two matching RF devices are marked `SiGe / 2547A / 2069CHF`. They are provisionally treated as RF front-end amplifiers; the exact part number remains unverified and must not be replaced with an imagined Broadcom or SE2598L identity.
- U3 is an unidentified 8-pin RF/control device with a top marking that appears to include `A766A`.
- The right side of the module contains a dedicated switching-regulator / power-conditioning section.
- Y1 is the visible RF/controller reference crystal; its exact frequency should be read from a sharper perpendicular macro photograph or measured.

### Current limits of the evidence

- Only the module topside is documented. The module underside may contain additional RF front-end, EEPROM/SPROM, or calibration-related components.
- The three-connector antenna topology is visible, but diversity/MIMO chain routing has not been traced.
- No host-side Mini PCI power-enable, reset, interrupt, or clock signal has been mapped.

## Promotion consequences

1. Treat the main-board major-component inventory as photographically confirmed rather than heatsink-location inference.
2. Preserve the WLAN card and any stock firmware/NVRAM data before testing replacement cards.
3. Add a WLAN-module underside photograph before declaring the photographic baseline fully complete.
4. Map Mini PCI connector rails and reset/clock behaviour only after the main-board power domains are known.
5. Defer any RF transmission testing until the correct antenna connection and regulatory-safe test setup are established.
