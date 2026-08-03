# Bootloader promotion gates

## P0 — static reconstruction

Complete:

- exact boot-chain hashes;
- 737-function decompilation;
- command table and callgraph;
- forced-`bootcmd` function resolved;
- firmware checker resolved;
- patch sites reproduced by script.

## P1 — RAM stage2 console

Required:

- TFTP exact stage2 ELF;
- `bootelf` enters monitor;
- UART input/output is stable;
- `return` resumes vendor shell repeatedly;
- no flash hash changes after power cycle.

## P2 — RAM read/verification

Required:

- stage2 reproduces boot-chain CRC32/SHA-256;
- known DRAM reads work;
- invalid ranges are rejected;
- monitor survives repeated entry/exit.

## P3 — Linux handoff

Required:

- `bootlinux` launches a TFTP-loaded known-good ELF;
- `boot-openwrt` verifies, copies and launches the existing NOR ELF;
- serial logs show the same kernel entry and hardware state as the manual vendor path.

## P4 — donor-backed second-stage U-Boot

Required before replacing vendor policy:

- import/provenance review of Cavium donor code;
- native timer, UART, CFI and Linux loader;
- TFTP recovery;
- environment read support with writes disabled;
- RAM-only soak testing.

## P5 — upper update-range experiment

First persistent experiment should avoid lower code changes where possible. Requirements:

- exact erase-sector map, including sectors that contain `0x6ff00` board data;
- complete pre-write backup and read-back;
- external programmer ready;
- automatic boot disabled;
- patched image manually invoked and recoverable.

## P6 — lower code policy patch

Hardware-completed for the exact first-sector policy changes documented here:

- stock and intermediate sector identities verified;
- exact 128 KiB sector-level write plan used;
- live-sector RAM rollback copy retained during each operation;
- one sector unprotected, erased, programmed, fully compared and re-protected;
- final CRC32 `b77a94de` and both instruction words verified;
- normal OpenWrt boot and active-low button recovery validated.

The distribution wrapper's idempotent already-combined path is hardware tested.
A single destructive wrapper transition directly from stock remains untested.
This completion does not authorize unrelated lower-boot-chain modification.

## P7 — native cold-start replacement

Deferred until independent reset, cache/TLB, DDR, BootBus, UART and watchdog initialization is hardware-proven from RAM or a replaceable flash device.
