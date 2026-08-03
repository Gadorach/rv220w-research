# D-Link/TeamF1 Cavium donor analysis

## Why these sources matter

The D-Link DSR-500N is a close public donor platform. Published boot logs identify:

- U-Boot 1.1.1;
- `CUST_DSR500N`;
- CN5010-SCP pass 1.1;
- 128 MiB DRAM;
- 32 MiB flash;
- three RGMII Octeon Ethernet interfaces;
- a Cavium Linux ELF handoff.

The DSR v1.08B51 GPL README describes `sdk-2.0`, `install-sdk-2.0` and a `tools-gcc-4.3` toolchain. DWC-1000 GPL documentation separately names `tools-linux-octeon-sdk-1.7.3-264` and GCC 4.1. These are much closer architectural donors than generic U-Boot 1.1.1.

## Priority donor components

When an extracted GPL bundle is available, search in this order:

1. CN50xx reset and cache/TLB entry assembly;
2. DDR2 board configuration and training tables;
3. MIO UART and timer code;
4. BootBus/CFI NOR initialization;
5. board descriptor and MAC-address storage;
6. `bootoctlinux` and ELF64 loading;
7. PIP/PKO Ethernet and TFTP;
8. GPIO/reset-button and watchdog handling.

## What may transfer directly

Likely high-value common code includes:

- Cavium executive headers and CSR definitions;
- CN50xx cache/TLB primitives;
- MIO UART register programming;
- generic Octeon BootBus and CFI support;
- Octeon Linux ELF loading;
- PIP/PKO networking framework.

## What remains board-specific

Do not copy without RV220W evidence:

- DDR timing values and SPD assumptions;
- core and DDR PLL values;
- BootBus chip-select timing;
- recovery GPIO polarity;
- switch reset/enable sequence;
- flash partitioning;
- board descriptor location;
- MAC location;
- firmware wrapper and update policy.

The RV220W boot log provides its own DDR timing report and 400/266 MHz clock pair. Those values must override DSR defaults.

## Acquisition

The donor catalog is in `donors/dlink-cavium-donors.json`. Donor code is not redistributed in this package. After extraction, inventory it with:

```sh
python3 tools/inspect_dlink_donor.py \
  /path/to/D-Link_DSR_GPL-SRC_v1.08B51 \
  --output /tmp/dsr-donor-inventory.json
```

A later release can import only license-compatible source portions with provenance and exact path/hash records.
