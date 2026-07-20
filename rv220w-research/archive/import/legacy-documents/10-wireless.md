# WLAN subsystem

The WLAN subsystem is a removable **full-size Mini PCI** module based on Broadcom `BCM4322LKFBG`, a dual-band 802.11a/b/g/n controller.

## Photographic identification

The module topside is documented in:

- `evidence/photos/original/wlan-module-topside-01.jpg`
- `evidence/photos/original/wlan-module-topside-02.jpg`
- `evidence/photos/original/wlan-module-topside-03.jpg`
- `evidence/photos/annotated/wlan-module-topside-labelled.jpg`

Visible module details:

- PCB marking appears to be `YK910MO-1.0`.
- Three U.FL-style antenna connectors are populated and labelled J2, J4, and J1.
- Two matching RF front-end devices are marked `SiGe / 2547A / 2069CHF`. They are probable front-end amplifiers, but the exact commercial part number remains unverified.
- U3 is an unidentified 8-pin RF/control device with an apparent `A766A` marking.
- A dedicated switching regulator/power section is present on the card.
- The module underside has not yet been photographed.

## Preservation priorities

- Preserve the original module and record which antenna lead connects to J1/J2/J4 before disassembly.
- Inventory any host filesystem firmware, NVRAM, regulatory, or calibration files.
- Read PCI configuration space and driver/module parameters under the stock firmware.
- Determine whether calibration is stored on the card, in host flash, or in both locations.
- Photograph and inventory the module underside before powered experimentation.

## Host-interface promotion steps

1. Confirm Mini PCI 3.3 V power and ground pins with power removed and then powered.
2. Record reset, clock-request/clock, interrupt, and PCI bus activity during boot.
3. Capture stock `lspci -nnvv`, module list, kernel messages, firmware requests, and NVRAM paths.
4. Verify the original card enumerates consistently before testing another card.
5. If using a replacement card, confirm voltage, keying, antenna compatibility, and driver support before installation.

## RF promotion steps

- Do not transmit without the original antennas or suitable 50-ohm loads attached.
- Map the three U.FL connectors to antenna locations and radio chains.
- Identify whether the third connector is diversity, a separate band path, or an auxiliary chain.
- Confirm the visible RF PA identifications from sharper images or board tracing.
- Keep initial validation at minimum transmit power in a controlled environment.

## Practical option

The removable form factor permits a supported replacement Mini PCI card. A replacement may be a better engineering path than relying on an old proprietary Broadcom stack, provided the host supplies compatible Mini PCI power, clock, reset, interrupt, and antenna connections.
