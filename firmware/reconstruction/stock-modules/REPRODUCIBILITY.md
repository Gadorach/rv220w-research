# Reproducibility

## Inputs

The five original modules are included under `originals/` and verified by `provenance/INPUT-SHA256SUMS.txt`. They were extracted from the preserved RV220W SquashFS 3.0 big-endian root filesystem with `tools/extract_rv220w_squashfs3_modules.py`.

## Ghidra rebuild

Install or unpack Ghidra 12.1.2 and Java 21, then run:

```bash
export GHIDRA_HOME=/path/to/ghidra_12.1.2_PUBLIC
./tools/rebuild-ghidra-projects.sh
```

The rebuild script deliberately uses `-noanalysis`, then restores function boundaries from compiler `.pdr` records, recovers the two `mii.ko` exports from `__ksymtab`, adds semantic annotations, exports every function to C and assembly, and packs each database into `.gzf`.

## Important interpretation boundary

`reports/*-r_mips_26-control-transfers.tsv` records raw `R_MIPS_26` relocation destinations. MIPS PIC/GOT setup and local control transfers can resemble calls, so those reports must not be treated as semantic call graphs. `exports/*/decompiler-callgraph.tsv` is a separate conservative token-based view of calls visible in reconstructed C.
