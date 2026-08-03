> Historical pre-validation plan. The exact combined policy patch was subsequently hardware-validated on 2026-08-02.

# Stage2 v1.3 hardware test plan

All steps are nonpersistent.

## Gate 1: return path

TFTP-load `rv220w-stage2-poc.elf`, execute it with `bootelf`, then run:

```text
info
return
```

The stock `rv200w#` prompt must resume. Do not continue if it does not.

## Gate 2: donor-derived read-only state

Re-enter stage2 and record:

```text
bootbus
csr bootcfg0
csr boottim0
csr uartlsr
mac
bootcmd-audit
env
fwcheck
return
```

Expected highlights:

- CS0 enabled, base `0x1dc00000`, 16-bit width and a region covering the NOR;
- base MAC matches the chassis/current OpenWrt MAC source;
- `bootcmd-audit` reports `03 20 00 08` on an unpatched boot chain;
- `env` reports the currently saved sector CRC accurately;
- `fwcheck` reports no Sercomm wrapper while the raw OpenWrt ELF occupies the slot.

## Gate 3: existing Linux handoff

After power cycling and reloading stage2:

```text
boot-openwrt
```

This still calls the recovered vendor loader and is a regression of the current
known-good path, not proof of an independent bootloader.

## Prohibited actions

- Do not flash any boot-chain patch.
- Do not invoke `saveenv` as part of stage2 validation.
- Do not erase the lower 512 KiB.
- Do not use a generic SPI programmer on the parallel TSOP56 NOR.
