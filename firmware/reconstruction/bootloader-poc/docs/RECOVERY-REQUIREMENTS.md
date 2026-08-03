# Recovery requirements before boot-chain experiments

## Mandatory before any lower-region write

- Stable 3.3 V UART access with continuous logging.
- Proven U-Boot interruption and TFTP RAM boot.
- At least two matching complete 32 MiB NOR dumps on separate storage.
- Independently preserved and hashed copies of:
  - complete 512 KiB boot chain;
  - 320 KiB vendor update range;
  - `0x6f000–0x6ffff` board-data block;
  - final 128 KiB environment sector;
  - current OpenWrt slot and stock firmware slot.
- External programmer explicitly supporting Macronix `MX29GL256EHT2I`.
- Correct TSOP56 parallel-NOR adapter.
- Ability to electrically isolate or remove the NOR.
- A known-good spare flash programmed and verified with the original full image.

An ordinary SPI-only CH341A is not suitable for this x16 parallel NOR.

## Strongly recommended

- Sacrificial or spare RV220W board.
- Verified J2 EJTAG pinout and MIPS64-capable debugger.
- Logic analyzer on reset, NOR CS/OE/WE and UART TX.
- Remote or repeatable power switching.
- Current-limited bench supply.
- A scripted external-programmer restore procedure tested against a spare chip.

## Recovery tiers

```text
Tier 1  vendor U-Boot UART + TFTP RAM boot
Tier 2  OpenWrt RAM writer restoring non-boot-chain regions
Tier 3  vendor U-Boot flash restore, only after command/sector validation
Tier 4  EJTAG halt/debug, after pinout validation
Tier 5  external TSOP56 programming
```

A damaged reset vector, DDR setup or BootBus configuration cannot be recovered through UART or TFTP. External NOR programming is the final required safety net.
