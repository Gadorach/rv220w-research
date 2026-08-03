# Forced `bootcmd` analysis and patch sites

## Proof of the override

`rv220w_board_late_init` reconstructs `_gp` as `0xffffffffbfc436e0`. Its last basic block resolves:

```text
GOT 0xffffffffbfc43b14 -> 0xffffffffbfc19b60  setenv wrapper
GOT 0xffffffffbfc436f4 -> 0xffffffffbfc40000  string base
GOT 0xffffffffbfc436f0 -> 0xffffffffbfc30000  command-data base
```

The instructions then form:

```text
0xffffffffbfc40000 - 0x5260 = 0xffffffffbfc3ada0 -> "bootcmd"
0xffffffffbfc30000 + 0x63b0 = 0xffffffffbfc363b0 -> stock command
```

The target at `0xffffffffbfc19b60` builds a 32-bit argv array and calls the ordinary environment setter at `0xffffffffbfc190f4`. This is not CRC fallback behavior.

The final instructions are:

```text
file offset  instruction
0x13148      lw a0,0x14(gp)
0x1314c      lw a1,0x10(gp)
0x13150      lw t9,0x434(gp)
0x13154      addiu a0,a0,-0x5260
0x13158      ld gp,0x8(sp)
0x1315c      addiu a1,a1,0x63b0
0x13160      ld ra,0x10(sp)
0x13164      ld s0,0x0(sp)
0x13168      jr t9
0x1316c      addiu sp,sp,0x20
```

## Exact suppression patch

Original big-endian instruction at combined-image offset `0x13168`:

```text
03 20 00 08    jr t9
```

Replacement:

```text
03 e0 00 08    jr ra
```

Only byte `0x13169` changes (`0x20 -> 0xe0`). The existing delay slot restores `sp`; `ra`, `gp` and `s0` have already been restored. The function therefore returns normally without calling `setenv`.

Generated artifact:

```text
artifacts/rv220w-boot-chain-no-force-bootcmd.bin
```

This patch allows a CRC-valid saved `bootcmd` to remain intact, but it does not disable the firmware-wrapper check.

Hardware validation on 2026-08-02 confirmed that the patched word reads back as
`03 e0 00 08`, the sector CRC32 becomes `36db247b`, and a saved
`bootcmd=version` survives reset.

## Recovery diversion patch

The checker call and branch are:

```text
0x1312c  lw t9,0x34c(gp)   # 0xffffffffbfc22834
0x13130  jalr t9
0x13138  bgez v0,0x13148
0x1313c  lw t9,0x2d0(gp)   # 0xffffffffbfc22bd4 HTTP recovery
0x13140  jalr t9
```

Hardware-validated replacement at offset `0x13138`:

```text
04 41 00 03    bgez v0,...
10 00 00 03    b    ...
```

Changed bytes are `0x13138` and `0x13139`. This bypasses only the
invalid-firmware `do_http` call. The earlier active-low recovery-button branch
and `do_download` path remain unchanged and were confirmed on hardware.

The combined sector, including the validated `bootcmd` patch, has CRC32
`b77a94de`. Released-button startup boots OpenWrt; holding the button still
launches Sercomm download mode.

## Upper-region alternative

The stock command occupies a 154-byte NUL-terminated field at combined offset `0x363b0`, or upper-slice offset `0x63b0`. It can be replaced without changing lower code:

```text
run openwrt_boot
```

Generated artifact:

```text
artifacts/rv220w-u-boot-redirect-openwrt-env.bin
```

This is structurally less invasive, but it still depends on:

- a valid persistent `openwrt_boot` variable;
- the firmware wrapper passing, or a separate recovery bypass;
- preservation of board-specific data in any erased upper-region sectors.

## Patch generator safety

`tools/patch_vendor_bootchain.py`:

- accepts only the exact preserved baseline SHA-256 and size;
- verifies every original byte at every patch site;
- requires `--ack-lower-boot-risk` for code below offset `0x30000`;
- writes a new file rather than modifying the input;
- emits a JSON manifest listing original and replacement bytes;
- has no hardware or MTD access.

Example reconstruction only:

```sh
python3 tools/patch_vendor_bootchain.py \
  ../u-boot/originals/rv220w-boot-chain.bin \
  /tmp/rv220w-no-force.bin \
  --suppress-force \
  --ack-lower-boot-risk
```

The integrated combined distribution flasher is the supported narrow patch
path. It still requires external recovery readiness and explicit confirmation.
See `COMBINED-BOOT-POLICY-PATCH-HARDWARE-VALIDATION.md` for the exact hardware
validation boundary.
