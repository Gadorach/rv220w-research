# Reproducibility — v1.4.0-r1

Run the full regression suite:

```sh
python3 bootloader-poc/tests/run_all.py
```

Run the integrated combined-flasher tests directly:

```sh
python3 bootloader-poc/flash-tools/rv220w-combined-boot-policy-patch-flasher-v1.0.0/tests/test_offline.py
```

Perform its non-destructive hardware staging path:

```fish
cd bootloader-poc/flash-tools/rv220w-combined-boot-policy-patch-flasher-v1.0.0
./flash-combined-boot-policy.fish --stage-only
```

Build and test the separate RAM stage2 monitor:

```sh
cd bootloader-poc
make clean
make all
```

Check an Octeon ELF on the host:

```sh
python3 tools/check_octeon_elf.py artifacts/rv220w-stage2-poc.elf
```

The D-Link report records source archive names, hashes and derived facts without
redistributing donor trees. The stage2 build requires Clang/LLD with a MIPS64
target, `llvm-objcopy`, `readelf`, `llvm-objdump`, Python 3 and GNU Make.
