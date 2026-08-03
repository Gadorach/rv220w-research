# Bootloader PoC validation — v1.4.0-r1

`tests/run_all.py` validates:

- byte-exact bootcmd and selective HTTP-recovery patch sites;
- combined known sector identities and exact three-byte stock-to-combined delta;
- integrated combined-flasher offline policy and command construction;
- stage2 cryptographic primitives and MIPS64 static safety policy;
- donor reports and source-lineage facts;
- Octeon descriptor and bootinfo offsets;
- ELF parsing and non-empty `PT_NOTE` rejection.

Hardware validation establishes:

```text
combined sector CRC32: b77a94de
0xbdc13138: 10 00 00 03
0xbdc13168: 03 e0 00 08
```

It also establishes persistent `bootcmd`, normal OpenWrt auto-boot and preserved
active-low button recovery. The combined tool's already-target no-write path is
hardware validated. Its one-step destructive stock-to-combined transition has
not been separately run.

The separate stage2 artifact remains 93,096 bytes with SHA-256
`1369e9c240aedd33e624498a8932b076074e105a45785f19e8e658ceb9caed1a`
and has not been executed on the board.
