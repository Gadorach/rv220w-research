# Cisco RV220W stock-module annotated Ghidra package v1.0.0

This package contains a complete Ghidra-oriented reverse-engineering pass over five stock Cisco RV220W Linux 2.6.21.7 Cavium/Octeon kernel modules:

- `bcm5398.ko` — Broadcom BCM53xx/BCM53115 switch policy and pseudo-PHY register access
- `mii.ko` — thin MDIO wrapper exported to the switch module
- `cavium-ethernet.ko` — vendor Octeon Ethernet, RGMII, Broadcom tag, RX/TX, MDIO, and offload paths
- `scm-led.ko` — software-controlled front-panel LED and GPIO routines
- `push_button.ko` — reset/reboot button polling, proc/sysctl control, and LED feedback

## Validation summary

- Architecture: ELF64, MIPS64r2, big-endian, relocatable modules
- Ghidra: 12.1.2 PUBLIC
- Processor: `MIPS:BE:64:64-32addr`
- Functions reconstructed: **159**
- Successful C decompilations: **159**
- Decompiler failures: **0**
- Missing function boundaries restored from compiler `.pdr`: **55**
- Packed Ghidra snapshots: all five modules
- Native Ghidra projects: all five modules

The output is reconstructed pseudocode, not original Cisco source. Every function is annotated with subsystem, evidence class, confidence, interpretation, and safety limitations. Stripped local functions retain conservative `local_*` names when their exact role cannot be proven.

## Layout

- `RESULTS.md` — hardware-relevant conclusions and limits
- `exports/<module>/decompiled/` — one annotated reconstructed-C file per function
- `exports/<module>/assembly/` — one instruction export per function
- `exports/<module>/FUNCTION-ANNOTATIONS.md` — all functions indexed with interpretations and recognized calls
- `exports/<module>/functions.tsv` — machine-readable function inventory
- `exports/<module>/decompiler-callgraph.tsv` — recognized direct/import call tokens from reconstructed C
- `ghidra/*.gzf` — packed Ghidra database snapshots
- `projects/` — native `.gpr/.rep` projects
- `originals/` — exact extracted stock modules
- `reports/source-symbols/` — ELF sections, symbols, relocations, strings, and export strings
- `reports/*-r_mips_26-control-transfers.tsv` — raw relocation-derived control transfers; not a semantic call graph
- `tools/` — extractor, Ghidra scripts, maps, postprocessor, and reproducible rebuild script
- `provenance/` — source hashes and tool provenance

## Opening the analysis

The most direct path is to open a native project in Ghidra 12.1.2 using its `.gpr` file under `projects/<module>/`. Packed `.gzf` snapshots are also included as portable convenience copies and can be imported into a new Ghidra project.

Start with these functions:

- `bcm5398:miiSwitchRegisterRead`
- `bcm5398:miiSwitchRegisterWrite`
- `bcm5398:configWanPort`
- `bcm5398:init_module`
- `cavium-ethernet:cvm_oct_rgmii_init`
- `cavium-ethernet:brcmTagAdd`
- `cavium-ethernet:brcmTagDelete`
- `scm-led:blink_wlan`
- `push_button:set_input`
- `push_button:local_push_button_timer_callback`

## Safety

The package performs static analysis only. Register operations shown in the pseudocode must not be replayed on hardware until addresses, widths, side effects, switch variant, and reset semantics have been independently verified.
