# Validation — v1.4.0-r1

## Hardware validated

- sector 0 stock identity before modification: CRC32 `ce86d667`;
- bootcmd-only identity after the first patch: CRC32 `36db247b`;
- combined identity after both patches: CRC32 `b77a94de`;
- combined words:
  - `0xbdc13138 = 10 00 00 03`;
  - `0xbdc13168 = 03 e0 00 08`;
- full 131,072-byte RAM-to-flash comparison after programming;
- re-protection of the first NOR sector;
- saved `bootcmd` persistence across reset;
- automatic OpenWrt boot after invalid Sercomm-format checking;
- active-low physical recovery-button download mode;
- combined distribution flasher recognition of an already-combined sector and
  safe idempotent no-write exit.

## Validated offline

- all prior boot-chain byte proofs and patch-generation tests;
- combined flasher artifacts, state identities, exact three-byte stock-to-target
  delta, serial-only policy and command construction;
- stage2 clean build as ELF64 big-endian MIPS64r2/n64;
- no runtime relocations or undefined symbols;
- RAM/NOR/CSR write-surface policy regressions for stage2;
- CRC-32 and SHA-256 vectors;
- D-Link multiversion report facts and archive count;
- Octeon boot ABI sizes and offsets;
- host and stage2 ELF compatibility checks.

## Not directly exercised

- a single destructive combined-flasher run starting from a completely stock
  sector; the board was already combined when the distribution wrapper was
  tested;
- entry into or return from the v1.4.0 RAM stage2 ELF;
- `bootabi`/`elfcheck` UART output from stage2.

The combined tool is destructive only with `--execute`, external-recovery
acknowledgement and the exact confirmation token. Its dry-run and stage-only
modes do not modify NOR.
