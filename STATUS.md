# Research status

**Package version:** 0.1.0  
**Snapshot date:** 2026-07-19  
**Physical board:** Cisco RV220W-A V01, PCB `YK910A-1.6`

## Completed

- Photographic component inventory.
- Major CPU, RAM, flash, switch, WLAN, clock, latch, and regulator identifications.
- Candidate debug-header classification.
- Public documentation and GPL-notice index.
- Non-destructive UART, Linux inventory, and MTD-dump procedures.
- Stage-gated hardware promotion plan.

## Not yet completed

- Underside photography and full board coordinate map.
- JP1/JP2 electrical characterization.
- UART boot capture or bootloader identification.
- J2 continuity map and EJTAG confirmation.
- Complete flash dump and partition map.
- Switch management-bus identification.
- GPIO, reset, LED, watchdog, and button maps.
- Verified RAM boot.
- Device-tree or board-file implementation.

## Working hypotheses requiring evidence

- J2 is MIPS EJTAG.
- One of JP1/JP2 is the primary console and the other may be a secondary UART or manufacturing interface.
- U3 latches BootBus address/data signals for the parallel NOR.
- The BCM53115 CPU port is connected to a CN5010 GMII/RGMII interface.
- Stock firmware is big-endian Linux, likely using a Cavium SDK-derived bootloader and Linux 2.6.21-era board code.
