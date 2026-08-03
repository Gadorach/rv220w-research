# Octeon Linux boot ABI reconstruction — v1.4

The exact SDK 1.7.3 build-264 application header establishes descriptor version
6 and a maximum of 64 argument pointers. A clean-room field-layout record with
compile-time offset assertions is provided in
`reconstruction/octeon_boot_abi_v6.h`.

## Kernel entry registers

The Octeon Linux entry macro expects only the low 32 bits to be initialized by
the bootloader:

- `a0`: argument count;
- `a1`: `argv` in the KSEG0 compatibility mapping;
- `a2`: one for the initialization core, zero for other cores;
- `a3`: physical address of the 400-byte boot descriptor.

The kernel immediately stores `a3` as its boot-descriptor pointer before normal
entry processing.

## Known structure sizes

- Octeon boot descriptor v6: 400 bytes.
- `cvmx_bootinfo` v1.2: 152 bytes.
- Descriptor `argv`: offset 64, 64 entries of 32-bit compatibility addresses.
- Descriptor flags/core-mask: offsets 320/324.
- Board identity begins at offset 352.
- `cvmx_desc_vaddr`: offset 392.

## Remaining clean-room loader work

The ABI no longer blocks reconstruction, but a standalone loader still needs
hardware-validated policy for bootmem allocation, descriptor placement, TLB
mapping, core vectors, exception base, cache synchronization and final network
shutdown. v1.4 continues to call the recovered vendor loader after stronger ELF
validation.
