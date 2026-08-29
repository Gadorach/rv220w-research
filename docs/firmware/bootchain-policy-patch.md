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

## Guarded release tooling

```console
make -C openwrt u-boot-verify
make -C openwrt u-boot-patches
```

The first command performs a read-only bootloader/environment backup and compatibility check. The second provides the current guarded onboarding, repair, and forced-qualified-rewrite workflow. Earlier reconstruction flash tools remain under `firmware/reconstruction/` for provenance.

The helper recognizes stock, bootcmd-only, HTTP-only, and already-combined
sector identities. It stages the live protected sector in RAM, constructs and
verifies the target in a second buffer, writes exactly one 128 KiB sector,
compares the full result, verifies CRC and instruction bytes, and restores
sector protection. It can create either a complete 32 MiB backup or a warning-gated 640 KiB backup of the regions it can modify.

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
