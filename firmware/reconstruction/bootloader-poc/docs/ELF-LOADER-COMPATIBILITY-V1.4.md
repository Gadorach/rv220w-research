# Vendor `bootoctlinux` ELF compatibility — v1.4

A D-Link Cavium BSP patch documents a concrete limitation: the associated
U-Boot cannot load a kernel whose ELF contains a non-empty `PT_NOTE` program
header. The build system therefore disables GNU build IDs.

Two validators implement that rule:

- host: `tools/check_octeon_elf.py`;
- target: stage2 command `elfcheck <addr> [known-length]`.

Both require an ELF64, big-endian, executable MIPS image with a valid program
header table, at least one valid `PT_LOAD`, and no non-empty `PT_NOTE`.

`bootlinux` and `boot-openwrt` now run the same validation before invoking the
vendor loader. This does not prove every ELF accepted by the parser will boot;
it removes one known failure mode and malformed-image handoffs.
