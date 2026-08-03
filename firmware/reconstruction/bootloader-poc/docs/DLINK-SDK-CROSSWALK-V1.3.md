# D-Link Cavium SDK crosswalk

## Source hierarchy

The supplied DWC-1000 archive is the primary donor. Its `cvmx-version.h` says
`Cavium Networks Octeon SDK version 1.7.3, build 264`, exactly matching the string
inside the preserved RV220W boot chain. The supplied DSR archive contains SDK
2.0.0 build 366 and is a secondary donor for later boot metadata and generated
CSR definitions.

The DWC release corresponds to the DWC-1000 A1 and firmware 4.1.0.2_10204. It is
from the same 2012 product generation as the RV220W vendor build.

## Directly transferable knowledge

| RV220W need | DWC/DSR evidence | Reconstruction use |
|---|---|---|
| MIO UART | SDK UART CSR macros and 64-bit I/O segment rules | Stage2 direct UART driver and CSR allowlist |
| BootBus CS0 | `CVMX_MIO_BOOT_REG_CFGX(0)` and `TIMX(0)` | Live read-only decoding in the `bootbus` command |
| Flash mapping | DWC Linux `flash_setup.c` reads CS0 base and maps flash below `0x1fc00000` | Confirms the working `0x1dc00000`, 32 MiB model |
| CN50xx config fields | generated `cvmx_mio_boot_reg_cfgx_cn50xx` union | Base, size, width, enable, timing-field decoding |
| Board network topology | DWC helper board cases for DSR/DWC private boards | Ports 0/1 are BCM53115 RGMII links; interface 0 exposes three ports |
| Application handoff | `cvmx-app-init.c`, boot descriptors and `cvmx_bootinfo_t` | Blueprint for replacing the vendor Linux loader later |
| Boot headers | SDK 2.0 `cvmx-bootloader.h` | Useful for Cavium stage2/stage3 image discovery, not the Sercomm wrapper |

## Particularly strong board match

DWC SDK 1.7.3 private-board support groups DSR1000N, DSR500N, DSR500, DSR1000
and DWC1000 together. For these boards it states:

- Octeon IPD ports 0 and 1 connect to a BCM53115 and have no direct PHY address;
- those ports are treated as 1000 Mb/s, full duplex and link-up;
- port 2 connects to a Broadcom B5081 at PHY address 8;
- interface 0 contains three ports.

The first, second and fourth facts independently match the RV220W boot log and
modern Linux topology. The RV220W differs at port 2: current hardware evidence
indicates the third Octeon path reaches unpopulated/prototype pads rather than a
populated B5081 PHY.

## What the packages do not provide

A complete Cavium U-Boot tree and `bootoctlinux` command source are absent. SDK
2.0 files refer to a missing `bootloader/u-boot` directory, proving that D-Link
built against an external/private bootloader tree not present in these releases.
The donors therefore cannot simply be configured and compiled as an RV220W
U-Boot.

Still missing for a native reset-vector replacement:

- CN5010 reset entry and exception-vector placement;
- board-specific DDR2 initialization/training tables;
- initial BootBus timing programmed before C execution;
- vendor global-data/relocation integration;
- complete ELF segment/TLB/boot descriptor setup used by `bootoctlinux`;
- reset button, watchdog and BCM53115 early policy.

## Provenance

`donors/dlink-cavium-source-report.json` contains source archive fingerprints,
individual relevant-file hashes, matching line records, and the result of the
full-tree U-Boot-source search. Donor source itself is intentionally not copied
into this repository.
