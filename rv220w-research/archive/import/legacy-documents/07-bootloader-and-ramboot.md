# Bootloader and RAM-boot research

## Confirmed bootloader facts

- U-Boot 1.1.1 development build, SVN revision string `193M`.
- Build time: 2012-06-14 15:20:38.
- Prompt: `rv200w# `.
- JP1 primary console: 115200 8N1; physical pin 1 VCC/NC, pin 2 TX, pin 3 RX, pin 4 GND.
- `bootdelay=0`, but Ctrl-C during the firmware-check/autoboot transition works.
- 128 MiB DRAM and 32 MiB x16 CFI NOR are initialized before the prompt.
- Persistent environment CRC is bad; the built-in default environment is active.
- The command set supports `loadb`, TFTP/HTTP downloads, Cavium ELF/Linux boot,
  memory display, CRC32, and direct flash commands.
- No native arbitrary-memory upload command such as `saves` or `tftpput` is listed.

See `docs/23-confirmed-uart-uboot-and-flash-dump-2026-07-20.md`.

## Non-destructive command policy

For preservation, use only:

- `help`, `version`, `printenv`, `flinfo`, `coninfo`, `pci`;
- `base 0`;
- `md.b`;
- `crc32`;
- temporary `setenv baudrate` without `saveenv`.

Avoid `saveenv`, `erase`, `protect off`, `cp`, `mw`, `burn_app`,
`bootloader_flash_update`, or commands whose persistence is unclear.

## Current boot path

```text
cp.b 0xbdc80000 0x02a00000 0x580000
bootoctlinux 0x02a00200 <mtdparts...>
```

The Linux object is a 64-bit ELF loaded by Cavium-specific U-Boot code.

## RAM-boot promotion

1. Finish two verified 32 MiB flash acquisitions.
2. Obtain a bootloader/free-memory map using read-only commands and known boot
   allocations.
3. Select a load range outside U-Boot, stack, boot-info structures, and the
   normal kernel copy area.
4. Load a tiny known payload or initramfs kernel over TFTP or `loadb`.
5. Verify checksum before execution.
6. Preserve the OCTEON boot-info structure expected by Linux.
7. Boot without writing flash.
8. Reboot to stock firmware and confirm no persistent changes.

A RAM-resident raw flash dumper is a useful later optimization, but the initial
preservation image should use the simpler `md.b` plus CRC32 workflow.
