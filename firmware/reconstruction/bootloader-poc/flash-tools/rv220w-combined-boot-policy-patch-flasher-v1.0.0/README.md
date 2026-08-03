# RV220W combined boot-policy patch flasher v1.0.0

This is the one-step distribution flasher for a stock Cisco RV220W boot chain.
It applies both hardware-validated policy patches to NOR erase sector 0:

```text
0x13138: 04 41 00 03 -> 10 00 00 03
           bypass only invalid-firmware Sercomm HTTP recovery

0x13168: 03 20 00 08 -> 03 e0 00 08
           stop the vendor late-init hook from overwriting bootcmd
```

The active-low physical recovery-button path remains unchanged and still enters
Sercomm download mode.

The flasher accepts these hash-gated starting states:

- stock;
- bootcmd-only patched;
- HTTP-bypass-only patched;
- already combined.

It copies the exact live sector to a rollback RAM buffer, constructs the target
in a second RAM buffer, validates CRC32 and both instructions, and writes only
the first 128 KiB NOR sector. It does not use TFTP, save the environment, or
reset the router.

## Dry run

```fish
./flash-combined-boot-policy.fish
```

## Non-destructive staging validation

```fish
./flash-combined-boot-policy.fish --stage-only
```

## Apply both patches

```fish
./flash-combined-boot-policy.fish \
    --execute \
    --external-recovery-ready \
    --confirm RV220W_FLASH_COMBINED_BOOT_POLICY_PATCHES
```

## Restore the completely stock sector

```fish
./flash-combined-boot-policy.fish \
    --target stock \
    --execute \
    --external-recovery-ready \
    --confirm RV220W_RESTORE_STOCK_BOOT_SECTOR0
```

## Restore the bootcmd-only state

```fish
./flash-combined-boot-policy.fish \
    --target bootcmd-only \
    --execute \
    --external-recovery-ready \
    --confirm RV220W_RESTORE_BOOTCMD_ONLY_POLICY
```

## Expected combined state

```text
crc32 0xbdc00000 0x20000  -> b77a94de
md.b 0xbdc13138 4          -> 10 00 00 03
md.b 0xbdc13168 4          -> 03 e0 00 08
```

Hardware validation already established that the combined target automatically
boots OpenWrt while retaining active-low recovery-button download mode. This
new wrapper is an offline-reworked distribution tool; its target bytes are
identical to the already hardware-validated combined sector.
