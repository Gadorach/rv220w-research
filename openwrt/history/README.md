# Historical RV220W research material

Nothing below `history/` is copied into the normal release image or OpenWrt worktree. It is retained solely for provenance, regression archaeology and future hardware research.

- `debug-tools/host/` — retired collectors, analyzers, GPIO survey tools and persistent-Wi-Fi diagnostic helpers.
- `debug-tools/target/` — retired SSB-NVMEM / Octeon PCI IRQ diagnostic packages, capture helpers and the debug-only RX-IQ verification patch.
- `research/` — superseded RX-IQ calibration scaffolding, stock-driver crosswalk material and historical candidate code.
- `../../docs/history/openwrt/toolkit-v1.15.10/` — milestone notes and hardware evidence documentation from the promotion phase.
- `debug-tools/` and `research/` are the normalized contents of the final promotion toolkit; the redundant nested ZIP is intentionally omitted.

The public RC release uses only the files outside `history/`.
