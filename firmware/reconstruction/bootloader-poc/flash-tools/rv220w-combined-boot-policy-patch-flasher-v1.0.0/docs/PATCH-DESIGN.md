# Combined RV220W boot-policy patch design

## Patch 1: preserve user bootcmd

The vendor late-init routine tail-calls the environment setter with `bootcmd`
and the compiled stock command. At sector offset `0x13168`, replacing `jr t9`
with `jr ra` returns after the already-restored function epilogue:

```text
03 20 00 08 -> 03 e0 00 08
```

Only byte `0x13169` changes from `0x20` to `0xe0`.

## Patch 2: tolerate non-Sercomm firmware

After the firmware checker, the original conditional branch skips `do_http`
only when the checker returns nonnegative. Replacing it with an unconditional
branch to the same target skips only the invalid-image HTTP recovery call:

```text
0x13138: 04 41 00 03  bgez v0,+3
          10 00 00 03  b +3
```

The earlier active-low GPIO branch and `do_download` recovery call are not
modified.

## Combined target

Relative to stock sector 0, exactly three bytes change:

```text
0x13138: 04 -> 10
0x13139: 41 -> 00
0x13169: 20 -> e0
```

Known identities:

```text
stock         CRC32 ce86d667
bootcmd-only  CRC32 36db247b
HTTP-only     CRC32 4f2766c2
combined      CRC32 b77a94de
```
