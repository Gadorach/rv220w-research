# Bootloader reconstruction v1.3

## Current executable boundary

The buildable stage2 monitor starts only after the stock bootloader has trained
DDR, configured caches/TLBs and BootBus, initialized UART, and loaded the ELF.
This is intentional: it proves reconstructed services without risking the reset
vector.

The v1.3 monitor adds read-only commands derived from the D-Link/Cavium donors:

```text
bootbus       read/decode live MIO_BOOT_REG_CFG0 and TIM0
csr           read a small allowlist of known-safe CSRs
env           verify CRC and list the real final 128 KiB environment sector
fwcheck       inspect Sercomm size/name/additive checksum/trailer
mac           read the preserved base MAC at flash offset 0x6ff00
bootcmd-audit show persistent bootcmd, compiled command and force-patch bytes
```

No command writes flash, environment, GPIO, MDIO or arbitrary CSRs.

## Forced bootcmd location

The recovered late initialization entry is `0xffffffffbfc13084`. Its final
basic block resolves `bootcmd`, the stock command string, and the ordinary
environment wrapper. At flash offset `0x13168`, instruction `jr t9` tail-calls
that wrapper after all saved registers are restored.

The minimal suppression is:

```text
flash offset 0x13168
03 20 00 08  jr t9
03 e0 00 08  jr ra
```

Only offset `0x13169` changes from `0x20` to `0xe0`. The delay slot remains
`addiu sp,sp,0x20`, so the function returns with a balanced stack and without
calling the setter.

This explains the observed behavior precisely: a CRC-valid environment imports
normally and custom variables survive, but late board code selectively replaces
`bootcmd` before autoboot.

## Why the upper 320 KiB is not a standalone U-Boot

The vendor variables advertise an update range beginning at `0xbdc30000`, but
binary mapping places core command, environment, ELF-loader and board-late-init
code below offset `0x30000`. The upper range contains additional code, recovery
application, strings, GOT/data and board data. It is an update policy boundary,
not an executable boundary.

A safe replacement strategy therefore remains:

1. RAM-only stage2 monitor;
2. independently reconstructed Linux ELF loader and boot descriptor setup;
3. RAM-loaded full U-Boot port using retained vendor DDR/BootBus state;
4. only then, a carefully linked flash replacement preserving board data;
5. native reset/DDR replacement last.

## Next executable milestone

The next meaningful PoC is `bootoctlinux` independence. Reconstruct its behavior
from the decompiled function plus SDK boot descriptors, bootmem allocator and
TLB helpers, then launch the same proven OpenWrt ELF without calling any vendor
function. That separates the monitor from stock U-Boot while still relying on
its low-level hardware initialization.
