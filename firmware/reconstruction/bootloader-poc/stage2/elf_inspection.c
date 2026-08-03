/* SPDX-License-Identifier: GPL-2.0-or-later */
#include "include/elf_inspection.h"
#include "include/octeon_boot_abi.h"
#include "include/platform.h"
#include "include/mini_lib.h"
#include "include/console.h"

#define PT_LOAD 1U
#define PT_NOTE 4U
#define EM_MIPS 8U
#define ET_EXEC 2U
#define ELF64_EHDR_SIZE 64U
#define ELF64_PHDR_SIZE 56U
#define MAX_PHNUM 128U

static u16 be16(const volatile u8 *p)
{
    return (u16)(((u16)p[0] << 8) | p[1]);
}

static u32 be32(const volatile u8 *p)
{
    return ((u32)p[0] << 24) | ((u32)p[1] << 16) | ((u32)p[2] << 8) | p[3];
}

static u64 be64(const volatile u8 *p)
{
    return ((u64)be32(p) << 32) | be32(p + 4);
}

static int range_inside_known_length(u64 offset, u64 size, u64 known_length)
{
    if (known_length == 0)
        return 1;
    return offset <= known_length && size <= known_length - offset;
}

static void reason(const char *message, int verbose)
{
    if (verbose) {
        console_puts("elfcheck_error=");
        console_puts(message);
        console_putc('\n');
    }
}

int inspect_elf64_be_mips(u64 address, u64 known_length, elf64_inspection *result, int verbose)
{
    const volatile u8 *elf = (const volatile u8 *)(uintptr)address;
    u64 table_size;
    u16 i;

    mem_set(result, 0, sizeof(*result));
    if (!address_is_known_readable(address, ELF64_EHDR_SIZE)) {
        reason("ELF header is outside known DRAM/NOR", verbose);
        return 0;
    }
    if (elf[0] != 0x7f || elf[1] != 'E' || elf[2] != 'L' || elf[3] != 'F') {
        reason("ELF magic absent", verbose);
        return 0;
    }
    if (elf[4] != 2 || elf[5] != 2 || elf[6] != 1) {
        reason("requires ELF64, big-endian, current version", verbose);
        return 0;
    }
    if (be16(elf + 16) != ET_EXEC || be16(elf + 18) != EM_MIPS) {
        reason("requires an executable MIPS ELF", verbose);
        return 0;
    }
    if (be16(elf + 52) != ELF64_EHDR_SIZE) {
        reason("unexpected ELF header size", verbose);
        return 0;
    }

    result->entry = be64(elf + 24);
    result->phoff = be64(elf + 32);
    result->phentsize = be16(elf + 54);
    result->phnum = be16(elf + 56);
    if (result->phentsize != ELF64_PHDR_SIZE || result->phnum == 0 || result->phnum > MAX_PHNUM) {
        reason("invalid program-header geometry", verbose);
        return 0;
    }
    table_size = (u64)result->phentsize * result->phnum;
    if (result->phoff > ~0ULL - table_size ||
        !range_inside_known_length(result->phoff, table_size, known_length) ||
        !address_is_known_readable(address + result->phoff, table_size)) {
        reason("program-header table is outside readable image data", verbose);
        return 0;
    }

    for (i = 0; i < result->phnum; i++) {
        const volatile u8 *ph = elf + result->phoff + (u64)i * result->phentsize;
        u32 type = be32(ph);
        u64 offset = be64(ph + 8);
        u64 filesz = be64(ph + 32);
        u64 memsz = be64(ph + 40);
        if (type == PT_LOAD) {
            result->load_segments++;
            if (filesz > memsz || offset > ~0ULL - filesz ||
                !range_inside_known_length(offset, filesz, known_length) ||
                !address_is_known_readable(address + offset, filesz))
                result->invalid_load_segments++;
        } else if (type == PT_NOTE) {
            result->note_segments++;
            if (filesz != 0)
                result->nonempty_note_segments++;
        }
    }
    if (result->load_segments == 0 || result->invalid_load_segments != 0) {
        reason("missing or invalid PT_LOAD segments", verbose);
        return 0;
    }
    if (result->nonempty_note_segments != 0) {
        reason("non-empty PT_NOTE is rejected by this vendor U-Boot lineage", verbose);
        return 0;
    }
    if (verbose)
        console_puts("vendor_loader_compatible=yes\n");
    return 1;
}

void command_elfcheck(int argc, char **argv)
{
    u64 address;
    u64 length = 0;
    elf64_inspection result;
    int ok;
    if ((argc != 2 && argc != 3) || !parse_u64(argv[1], &address) ||
        (argc == 3 && !parse_u64(argv[2], &length))) {
        console_puts("error: expected elfcheck <addr> [known-length]\n");
        return;
    }
    address = canonicalize_mips_address(address);
    ok = inspect_elf64_be_mips(address, length, &result, 1);
    console_puts("entry="); print_hex64(result.entry); console_putc('\n');
    console_puts("phoff="); print_hex64(result.phoff); console_putc('\n');
    console_puts("phentsize="); print_dec_u64(result.phentsize); console_putc('\n');
    console_puts("phnum="); print_dec_u64(result.phnum); console_putc('\n');
    console_puts("pt_load="); print_dec_u64(result.load_segments); console_putc('\n');
    console_puts("pt_note="); print_dec_u64(result.note_segments); console_putc('\n');
    console_puts("pt_note_nonempty="); print_dec_u64(result.nonempty_note_segments); console_putc('\n');
    console_puts("elfcheck="); console_puts(ok ? "pass\n" : "fail\n");
}

void command_bootabi(void)
{
    console_puts("sdk_lineage=Octeon SDK 1.7.3 build 264\n");
    console_puts("boot_descriptor_version="); print_dec_u64(OCTEON_CURRENT_DESC_VERSION); console_putc('\n');
    console_puts("boot_descriptor_bytes="); print_dec_u64(OCTEON_BOOT_DESCRIPTOR_SIZE); console_putc('\n');
    console_puts("cvmx_bootinfo_v1_2_bytes="); print_dec_u64(CVMX_BOOTINFO_V1_2_SIZE); console_putc('\n');
    console_puts("argv_max="); print_dec_u64(OCTEON_ARGV_MAX_ARGS); console_putc('\n');
    console_puts("entry_a0=argc\n");
    console_puts("entry_a1=argv_kseg0_compat_low32\n");
    console_puts("entry_a2=init_core_flag\n");
    console_puts("entry_a3=physical_boot_descriptor_low32\n");
    console_puts("implementation=vendor loader remains the active handoff path\n");
}
