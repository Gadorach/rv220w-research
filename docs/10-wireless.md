# WLAN subsystem

The WLAN module is a removable Mini PCI card based on Broadcom BCM4322, a dual-band 802.11a/b/g/n device.

## Priorities

- Preserve any card-specific SPROM/NVRAM or host-side calibration data.
- Confirm PCI bus, clock, reset, interrupt, and power enable.
- Inventory stock driver/firmware files and module parameters.
- Defer RF bring-up until CPU, storage, and Ethernet are stable.

## Practical option

The removable form factor permits a supported replacement card. A replacement may be a better engineering path than depending on an old proprietary Broadcom stack, provided the board supplies compatible Mini PCI voltage, clock, reset, and antenna connections.
