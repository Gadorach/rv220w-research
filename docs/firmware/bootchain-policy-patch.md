# Boot-chain policy patch

## Requirement

The combined boot-policy patch must be installed and verified **before** the
OpenWrt firmware slot is promoted to automatic boot.

The unmodified vendor boot chain enforces two incompatible policies:

1. it overwrites the saved `bootcmd` during late board initialization;
2. it launches Sercomm HTTP recovery when the image at `0xbdc80000` lacks the proprietary wrapper.

## Validated patch

Only the first 128 KiB NOR sector is modified:

```text
0x13138: 04 41 00 03 -> 10 00 00 03
           follow the existing firmware-check success path

0x13168: 03 20 00 08 -> 03 e0 00 08
           return instead of tail-calling the forced bootcmd setter
```

Expected combined identity:

```text
range:  0xbdc00000-0xbdc1ffff
CRC32:  b77a94de
branch: 10 00 00 03 at 0xbdc13138
return: 03 e0 00 08 at 0xbdc13168
```

## Flasher location

```text
firmware/reconstruction/bootloader-poc/flash-tools/
  rv220w-combined-boot-policy-patch-flasher-v1.0.0/
```

Run non-destructive checks first:

```fish
cd firmware/reconstruction/bootloader-poc/flash-tools/rv220w-combined-boot-policy-patch-flasher-v1.0.0
./flash-combined-boot-policy.fish
./flash-combined-boot-policy.fish --stage-only
```

Apply the combined target only with external recovery ready:

```fish
./flash-combined-boot-policy.fish \
    --execute \
    --external-recovery-ready \
    --confirm RV220W_FLASH_COMBINED_BOOT_POLICY_PATCHES
```

The flasher recognizes stock, bootcmd-only, HTTP-only, and already-combined
sector identities. It stages the live protected sector in RAM, constructs and
verifies the target in a second buffer, writes exactly one 128 KiB sector,
compares the full result, verifies CRC and instruction bytes, and restores
sector protection.

## Hardware validation boundary

Hardware testing proved the exact combined bytes, full sector read-back,
bootcmd persistence, automatic OpenWrt launch, and retained physical-button
recovery. The distribution wrapper correctly recognized an already-combined
sector and performed no write. The wrapper's single-step destructive transition
from an entirely stock sector was not separately repeated because the board had
already reached the same validated combined state through the component patch
operations.

Detailed proof is retained under
[`../../firmware/reconstruction/bootloader-poc/docs/COMBINED-BOOT-POLICY-PATCH-HARDWARE-VALIDATION.md`](../../firmware/reconstruction/bootloader-poc/docs/COMBINED-BOOT-POLICY-PATCH-HARDWARE-VALIDATION.md).
