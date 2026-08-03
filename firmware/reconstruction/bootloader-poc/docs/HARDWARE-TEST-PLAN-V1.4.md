> Historical pre-validation plan. The exact combined policy patch was subsequently hardware-validated on 2026-08-02.

# RV220W stage2 v1.4 hardware test plan

## Gate 1 — entry and return only

TFTP-load the stage2 ELF at `0x05500000`, launch it with the already proven
vendor ELF command, then run:

```text
info
bootabi
return
```

A clean return to `rv200w#` is mandatory.

## Gate 2 — read-only inspection

On a second launch:

```text
bootbus
csr bootcfg0
csr boottim0
mac
bootcmd-audit
env
fwcheck
elfcheck 0xffffffffbdc80000 0x11565d0
return
```

The OpenWrt ELF should report at least one `PT_LOAD`, zero non-empty `PT_NOTE`
segments, and `elfcheck=pass`.

## Gate 3 — existing vendor loader

Only after gates 1 and 2 pass, run `boot-openwrt`. This still uses the recovered
vendor `bootoctlinux` implementation; v1.4 merely adds malformed-ELF and
non-empty-NOTES rejection before handoff.

Do not run `saveenv`. Do not write the first 512 KiB boot chain. Do not add any
ASXX/CSR write based on generic SDK defaults; first preserve and record the
late-stage values established by the stock boot chain.
