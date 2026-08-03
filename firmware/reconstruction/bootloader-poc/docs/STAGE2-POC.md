# RAM stage2 proof-of-concept

## Goal

The PoC is a small recovery monitor, not yet a complete U-Boot replacement. It proves that an independently built payload can:

- enter through the vendor `bootelf` path;
- use UART0 without calling vendor console code;
- read and hash NOR without modifying it;
- copy a checked image into DRAM;
- bridge from an n64 monitor into the vendor n32-style command ABI;
- invoke the recovered `do_bootoctlinux` implementation;
- return safely to the vendor shell when requested.

## Memory layout

```text
ELF virtual address: 0xffffffff84000000
physical DRAM:       0x04000000
reserved window:     0x04000000–0x042fffff
private stack:       linked after image, 128 KiB
OpenWrt source:      0xffffffffbdc80000
OpenWrt RAM buffer:  0x05500000
```

The monitor rejects destination copies that overlap its reserved physical window.

## UART

UART0 is already initialized by the vendor cold-start stage. The monitor accesses the Octeon MIO UART CSR block directly at:

```text
0x8001180000000800
```

It performs no divisor, GPIO or pin-mux writes.

## Vendor ABI bridge

The recovered command handlers consume a four-argument command ABI:

```c
handler(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
```

Their assembly loads argv entries with 32-bit `lw`, indicating n32-style pointers. The monitor is compiled n64. The bridge therefore:

1. constructs a table of 32-bit KSEG0 pointers;
2. sign-extends the argv-table address before placing it in `a3`;
3. places `argc` in `a2` and zeroes `a0/a1`;
4. calls `0xffffffffbfc1d950` through `t9`, allowing the vendor PIC prologue to reconstruct its own `gp`.

This bridge is the highest-risk untested part of the RAM payload and is why `return`, console and hashing tests precede `boot-openwrt`.

## Commands

```text
help
info
md <address> <length>
nor <offset> <length>
crc32 <address> <length>
sha256 <address> <length>
copy <source> <destination> <length>
bootlinux <ram-elf>
boot-openwrt
return
```

Read and copy-source operations are limited to known DRAM and NOR mappings. Copy destinations must be DRAM and may not overlap stage2. There is no erase, program, protection, environment, GPIO or MDIO command.

## Build

Required host tools:

```text
clang
ld.lld
llvm-objcopy
readelf
python3
```

Build:

```sh
cd stage2
make clean all
```

The verifier checks ELF64, big-endian MIPS, entry address, PT_LOAD bounds, maximum size and destructive string policy.

## Hardware promotion sequence

### Gate S0 — transfer only

```text
tftpboot 0x05500000 rv220w-stage2-poc.elf
```

Confirm the exact transferred byte count before launching.

### Gate S1 — console and return

```text
bootelf 0x05500000
info
return
```

The original U-Boot prompt must resume and remain usable.

### Gate S2 — read-only NOR proof

```text
crc32 ffffffffbdc00000 80000
sha256 ffffffffbdc00000 80000
```

Expected:

```text
crc32=0x483548c0
sha256=0630714e3e86edfeeed064088266c59524d970e0b74780e903b68b45e8982e7d
```

### Gate S3 — generic RAM ELF handoff

TFTP a known-good OpenWrt ELF to a separate RAM buffer, re-enter stage2 and use `bootlinux <address>`.

### Gate S4 — NOR OpenWrt handoff

Use `boot-openwrt`. It performs exact SHA-256 validation before and after the copy, then invokes the vendor loader.

## Current validation boundary

The ELF builds and passes static/host regression tests. It has not yet been executed on the RV220W. The `bootelf` entry/return path and cross-ABI callgate require hardware confirmation.


## v1.4.0 donor-derived inspection

The stage2 monitor now has a strict read-only CSR allowlist and commands for
`bootbus`, `csr`, `env`, `fwcheck`, `mac`, and `bootcmd-audit`. See
`HARDWARE-TEST-PLAN-V1.3.md` for the ordered test sequence. These commands add no
NOR, environment, GPIO, MDIO or CSR write primitive.


## v1.4 ELF guard

`bootabi` displays the recovered descriptor ABI. `elfcheck <addr> [length]` validates the ELF64 big-endian MIPS program-header table and rejects non-empty `PT_NOTE` segments before vendor-loader handoff.
