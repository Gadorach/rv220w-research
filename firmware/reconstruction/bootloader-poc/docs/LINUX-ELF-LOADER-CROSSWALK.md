# Vendor `bootoctlinux` reconstruction crosswalk

## Command handler

```text
entry: 0xffffffffbfc1d950
size:  1860 bytes
command-table maxargs: 32
```

The recovered handler accepts an ELF address followed by policy arguments such
as `coremask=`, `numcores=`, `skipcores=`, `forceboot`, `debug` and
`endbootargs`. It then validates the ELF, reserves every loadable segment in
Octeon bootmem, loads/clears sections, allocates per-core stacks and descriptor
blocks, programs boot vectors, shuts networking down and releases the selected
core mask.

## Recovered helper map

| Address | High-confidence role | Evidence |
|---|---|---|
| `bfc13d10` | validate ELF and determine 32/64-bit class | exact `ELF file is 32/64 bit` strings |
| `bfc13de8` | load/clear 64-bit-address ELF sections | `%08qx`, `Clear`, section range string |
| `bfc13f8c` | load/clear 32-bit-address ELF sections | `%08lx`, same loader string shape |
| `bfc0acec` | bootmem named/allocation primitive | bootmem descriptor/version errors |
| `bfc0ac08` | bootmem descriptor access/validation | same descriptor compatibility error |
| `bfc03f70` | validate and mask requested cores | available-coremask and override warnings |
| `bfc03ea4` | reduce requested core count | only-N-cores-available warning |
| `bfc04134` | allocate per-core stack | exact stack allocation failure string |
| `bfc04678` | allocate/fill boot descriptor and `cvmx_bootinfo_t` | descriptor, bootinfo and argv allocation failures |
| `bfc2bc94` | shut down network before transfer | fatal network-shutdown string |

Other called helpers remain address-labeled until types and side effects are
proven. The reconstruction deliberately avoids optimistic renaming.

## D-Link SDK handoff match

DWC/DSR `cvmx-app-init.c` consumes the structures produced by this loader. It
copies from the boot descriptor/`cvmx_bootinfo_t` into runtime `cvmx_sysinfo_t`:

```text
core mask
heap base/end
stack top/size
physical bootmem descriptor
exception base
CPU and DDR clocks
board type/revisions
base MAC/count
serial number
DRAM size
bootloader flags
```

This provides an independent structural map for the descriptor-producing helper
at `bfc04678`.

## Independent-loader implementation plan

The next implementation should not begin by cloning the complete command. For a
single-core Linux boot, implement the minimum proven subset:

1. Validate big-endian MIPS ELF32/ELF64 headers and program headers.
2. For each `PT_LOAD`, convert XKPHYS/KSEG virtual addresses to physical DRAM,
   reserve the full `p_memsz` range, copy `p_filesz`, and clear the remainder.
3. Reserve one core-0 stack and exception-vector block.
4. Allocate and populate an SDK-1.7-compatible boot descriptor and bootinfo
   block, preserving the vendor board type, clocks, DRAM size and MAC data.
5. Install core-0 boot vector/setup trampoline.
6. Quiesce Octeon Ethernet/PKO only after a serial recovery path remains.
7. Transfer to the Linux ELF entry with the expected descriptor argument ABI.

The first independent loader should support exactly core 0 and no `forceboot`,
multicore or hotplug features. Every allocated address should be printed and
checked against DRAM and the stage2 residence window.
