# RV220W platform reconstruction v1.4.0-r1

This is a hardware-validation revision of the v1.4.0 reconstruction. It retains
the D-Link/Cavium multiversion analysis and RAM stage2 work, and integrates the
validated persistent boot-policy patch path used on the Cisco RV220W.

## Hardware-validated boot-policy result

The first 128 KiB NOR erase sector was validated with both policy patches:

```text
0x13138: 04 41 00 03 -> 10 00 00 03
           skip only invalid-firmware Sercomm HTTP recovery

0x13168: 03 20 00 08 -> 03 e0 00 08
           return instead of forcibly overwriting bootcmd
```

Validated combined sector identity:

```text
flash range: 0xbdc00000-0xbdc1ffff
CRC32:      b77a94de
```

Observed hardware behavior:

- a saved custom `bootcmd` survives `saveenv` and reset;
- a non-Sercomm OpenWrt image proceeds to the saved boot command;
- OpenWrt boots automatically from NOR;
- holding the active-low recovery button still launches Sercomm download mode;
- released-button invalid-magic HTTP recovery is bypassed;
- the final environment uses `bootdelay=3`, no `preboot`, and
  `bootcmd=run openwrt_boot`.

## Integrated distribution tool

The validated target and idempotent recognition path are included at:

```text
bootloader-poc/flash-tools/
  rv220w-combined-boot-policy-patch-flasher-v1.0.0/
```

Start with its non-destructive mode:

```fish
./flash-combined-boot-policy.fish --stage-only
```

The package writes only the first 128 KiB sector, retains the exact live sector
in RAM for rollback, performs full comparisons, restores flash protection, does
not save the environment, and does not reset the router.

Important validation distinction: the combined target bytes, final runtime
policy, underlying erase/program/compare sequence, and combined tool's
idempotent no-write path were exercised on hardware. A single destructive
combined-tool run starting from a completely stock sector was not separately
performed because the board was already in the validated combined state.

See `bootloader-poc/docs/COMBINED-BOOT-POLICY-PATCH-HARDWARE-VALIDATION.md`.

## v1.4 analysis retained

- Eleven D-Link DSR/DWC Cavium packages were scanned.
- No complete U-Boot/`bootoctlinux` source tree was present.
- Exact private board IDs, CN5010/BCM53115 topology evidence, Octeon descriptor
  ABI and Linux entry contract were recovered.
- Host and RAM-stage2 ELF checks reject non-empty `PT_NOTE` program headers.
- Generic CN50XX ASXX timing writes remain prohibited without board proof.

## Safety boundary

The integrated combined flasher is deliberately narrow but destructive when
run with `--execute`. It is hash/CRC/byte gated to recognized sector states and
requires explicit confirmation. External parallel-NOR recovery remains the
final safety net.

The RAM stage2 monitor remains read-only with respect to NOR, GPIO, MDIO and
CSRs. Its v1.4.0 ELF has not been hardware-tested; do not confuse stage2 status
with the separately validated vendor boot-chain patches.
