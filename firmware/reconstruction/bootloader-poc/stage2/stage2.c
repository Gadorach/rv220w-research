/* SPDX-License-Identifier: GPL-2.0-or-later */
#include "include/types.h"
#include "include/platform.h"
#include "include/console.h"
#include "include/mini_lib.h"
#include "include/crc32.h"
#include "include/sha256.h"
#include "include/vendor_callgate.h"
#include "include/inspection.h"
#include "include/elf_inspection.h"

extern u8 __image_start[];
extern u8 __image_end[];
extern u8 __bss_start[];
extern u8 __bss_end[];
extern u8 __stack_bottom[];
extern u8 __stack_top[];

static char line_buffer[192];
static char *argv_buffer[12];

static const u8 expected_openwrt_sha256[32] = {
    0xc8, 0x80, 0x07, 0x7e, 0xeb, 0xb0, 0xaa, 0x43,
    0x90, 0x1a, 0x2b, 0xb5, 0x37, 0xc6, 0x47, 0xf7,
    0x43, 0xf6, 0x0b, 0x44, 0x76, 0xa7, 0x9e, 0x51,
    0xf1, 0x33, 0xab, 0x5c, 0xcc, 0x21, 0x67, 0xf0
};

static void print_digest(const u8 digest[32])
{
    int i;
    for (i = 0; i < 32; i++)
        print_hex8(digest[i]);
}

static void print_range(const char *name, u64 start, u64 end)
{
    console_puts(name);
    console_puts(": ");
    print_hex64(start);
    console_puts(" - ");
    print_hex64(end);
    console_putc('\n');
}

static int parse_address_length(int argc, char **argv, u64 *address, u64 *length)
{
    if (argc != 3 || !parse_u64(argv[1], address) || !parse_u64(argv[2], length)) {
        console_puts("error: expected <address> <length>\n");
        return 0;
    }
    *address = canonicalize_mips_address(*address);
    if (*length == 0 || *address > ~0ULL - (*length - 1)) {
        console_puts("error: invalid or overflowing range\n");
        return 0;
    }
    return 1;
}

static void command_help(void)
{
    console_puts(
        "Commands:\n"
        "  help                         show this list\n"
        "  info                         platform and reconstruction constants\n"
        "  md <addr> <len>              read-only byte dump (maximum 0x1000)\n"
        "  nor <offset> <len>           read-only dump from 32 MiB NOR\n"
        "  crc32 <addr> <len>           CRC-32 over memory/NOR\n"
        "  sha256 <addr> <len>          SHA-256 over memory/NOR\n"
        "  copy <src> <dst> <len>       copy into checked DRAM only\n"
        "  bootbus                      decode live CN50xx CS0 registers\n"
        "  csr <allowlisted-name>       read one safe named CSR\n"
        "  env                          verify/list persistent environment\n"
        "  fwcheck                      inspect Sercomm header/checksum/trailer\n"
        "  mac                          read preserved board base MAC\n"
        "  bootcmd-audit                compare env, compiled command, patch site\n"
        "  bootabi                      show recovered Octeon Linux boot ABI\n"
        "  elfcheck <addr> [len]        validate vendor-loader ELF compatibility\n"
        "  bootlinux <ram-elf>          call vendor bootoctlinux loader\n"
        "  boot-openwrt                 copy proven NOR ELF and boot it\n"
        "  return                       return to the vendor U-Boot shell\n"
        "\n"
        "No command can erase/program NOR or save the environment.\n");
}

static void command_info(void)
{
    u32 prid;
    __asm__ volatile("mfc0 %0,$15" : "=r"(prid));
    console_puts("RV220W stage2 proof-of-concept\n");
    console_puts("policy=RAM-only, NOR-read-only, no saveenv, no GPIO/MDIO writes\n");
    console_puts("cp0_prid="); print_hex32(prid); console_putc('\n');
    console_puts("dram_bytes="); print_dec_u64(RV220W_DRAM_SIZE); console_putc('\n');
    print_range("nor", RV220W_NOR_KSEG1, RV220W_NOR_KSEG1 + RV220W_NOR_SIZE - 1);
    print_range("stage2_image", (u64)(uintptr)__image_start, (u64)(uintptr)__image_end - 1);
    print_range("stage2_stack", (u64)(uintptr)__stack_bottom, (u64)(uintptr)__stack_top - 1);
    console_puts("vendor_bootoctlinux="); print_hex64(RV220W_VENDOR_BOOTOCTLINUX); console_putc('\n');
    console_puts("openwrt_nor="); print_hex64(RV220W_OPENWRT_SLOT_ADDR); console_putc('\n');
    console_puts("openwrt_ram="); print_hex64(RV220W_OPENWRT_RAM_ADDR); console_putc('\n');
    console_puts("openwrt_elf_bytes="); print_hex64(RV220W_OPENWRT_ELF_SIZE); console_putc('\n');
}

static void dump_bytes(u64 address, u64 length)
{
    const volatile u8 *p = (const volatile u8 *)(uintptr)address;
    u64 row;
    if (length > 0x1000) {
        console_puts("error: md is limited to 0x1000 bytes\n");
        return;
    }
    for (row = 0; row < length; row += 16) {
        u64 i;
        print_hex64(address + row);
        console_puts(": ");
        for (i = 0; i < 16; i++) {
            if (row + i < length)
                print_hex8(p[row + i]);
            else
                console_puts("  ");
            console_putc(i == 7 ? '-' : ' ');
        }
        console_puts("|");
        for (i = 0; i < 16 && row + i < length; i++) {
            u8 c = p[row + i];
            console_putc((c >= 0x20 && c <= 0x7e) ? (char)c : '.');
        }
        console_puts("|\n");
    }
}

static int nor_range(u64 offset, u64 length, u64 *address)
{
    if (length == 0 || offset >= RV220W_NOR_SIZE || length > RV220W_NOR_SIZE - offset) {
        console_puts("error: range exceeds 32 MiB NOR\n");
        return 0;
    }
    *address = RV220W_NOR_KSEG1 + offset;
    return 1;
}

static void command_md(int argc, char **argv)
{
    u64 address, length;
    if (!parse_address_length(argc, argv, &address, &length))
        return;
    if (!address_is_known_readable(address, length)) {
        console_puts("error: range is outside known DRAM/NOR mappings\n");
        return;
    }
    dump_bytes(address, length);
}

static void command_nor(int argc, char **argv)
{
    u64 offset, length, address;
    if (argc != 3 || !parse_u64(argv[1], &offset) || !parse_u64(argv[2], &length)) {
        console_puts("error: expected nor <offset> <length>\n");
        return;
    }
    if (nor_range(offset, length, &address))
        dump_bytes(address, length);
}

static void command_crc32(int argc, char **argv)
{
    u64 address, length;
    u32 value;
    if (!parse_address_length(argc, argv, &address, &length))
        return;
    if (!address_is_known_readable(address, length)) {
        console_puts("error: range is outside known DRAM/NOR mappings\n");
        return;
    }
    console_puts("crc32: reading "); print_dec_u64(length); console_puts(" bytes...\n");
    value = crc32_compute((const void *)(uintptr)address, (usize)length);
    console_puts("crc32="); print_hex32(value); console_putc('\n');
}

static void command_sha256(int argc, char **argv)
{
    u64 address, length;
    u8 digest[32];
    if (!parse_address_length(argc, argv, &address, &length))
        return;
    if (!address_is_known_readable(address, length)) {
        console_puts("error: range is outside known DRAM/NOR mappings\n");
        return;
    }
    console_puts("sha256: reading "); print_dec_u64(length); console_puts(" bytes...\n");
    sha256_compute((const void *)(uintptr)address, (usize)length, digest);
    console_puts("sha256="); print_digest(digest); console_putc('\n');
}

static void command_copy(int argc, char **argv)
{
    u64 src, dst, length, dst_phys;
    if (argc != 4 || !parse_u64(argv[1], &src) || !parse_u64(argv[2], &dst) ||
        !parse_u64(argv[3], &length)) {
        console_puts("error: expected copy <src> <dst> <length>\n");
        return;
    }
    src = canonicalize_mips_address(src);
    dst = canonicalize_mips_address(dst);
    if (length == 0 || src > ~0ULL - (length - 1)) {
        console_puts("error: invalid source range\n");
        return;
    }
    if (!address_is_known_readable(src, length)) {
        console_puts("error: source must be within known DRAM/NOR mappings\n");
        return;
    }
    if (!address_to_dram_phys(dst, length, &dst_phys)) {
        console_puts("error: destination must be DRAM and may not overlap stage2\n");
        return;
    }
    console_puts("copy: "); print_hex64(src); console_puts(" -> "); print_hex64(dst);
    console_puts(" bytes="); print_dec_u64(length); console_putc('\n');
    mem_copy((void *)(uintptr)dst, (const void *)(uintptr)src, (usize)length);
    mips_sync();
    console_puts("copy=ok\n");
}

static void command_bootlinux(int argc, char **argv)
{
    u64 address;
    elf64_inspection inspection;
    if (argc != 2 || !parse_u64(argv[1], &address)) {
        console_puts("error: expected bootlinux <ram-elf>\n");
        return;
    }
    address = canonicalize_mips_address(address);
    if (!inspect_elf64_be_mips(address, 0, &inspection, 1)) {
        console_puts("error: refusing vendor loader handoff\n");
        return;
    }
    console_puts("Calling recovered vendor do_bootoctlinux at ");
    print_hex64(RV220W_VENDOR_BOOTOCTLINUX); console_putc('\n');
    (void)boot_linux_elf(address, "console=ttyS0,115200");
    console_puts("error: bootoctlinux returned\n");
}

static void command_boot_openwrt(void)
{
    const void *source = (const void *)(uintptr)RV220W_OPENWRT_SLOT_ADDR;
    void *destination = (void *)(uintptr)RV220W_OPENWRT_RAM_ADDR;
    u64 dst_phys;
    u8 source_digest[32];
    u8 destination_digest[32];
    elf64_inspection inspection;
    if (!inspect_elf64_be_mips(RV220W_OPENWRT_SLOT_ADDR, RV220W_OPENWRT_ELF_SIZE,
                               &inspection, 1)) {
        console_puts("error: staged NOR slot is not vendor-loader compatible\n");
        return;
    }
    if (!address_to_dram_phys(RV220W_OPENWRT_RAM_ADDR, RV220W_OPENWRT_ELF_SIZE, &dst_phys)) {
        console_puts("error: compiled OpenWrt copy range failed the DRAM safety check\n");
        return;
    }
    console_puts("Verifying the exact staged OpenWrt ELF in NOR...\n");
    sha256_compute(source, (usize)RV220W_OPENWRT_ELF_SIZE, source_digest);
    if (mem_compare(source_digest, expected_openwrt_sha256, sizeof(source_digest)) != 0) {
        console_puts("error: staged ELF SHA-256 mismatch\n  expected=");
        print_digest(expected_openwrt_sha256);
        console_puts("\n  actual=");
        print_digest(source_digest);
        console_putc('\n');
        return;
    }
    console_puts("NOR ELF hash=ok\n");
    console_puts("Copying proven OpenWrt ELF from NOR to RAM...\n");
    console_puts("  source="); print_hex64(RV220W_OPENWRT_SLOT_ADDR); console_putc('\n');
    console_puts("  dest="); print_hex64(RV220W_OPENWRT_RAM_ADDR); console_putc('\n');
    console_puts("  bytes="); print_dec_u64(RV220W_OPENWRT_ELF_SIZE); console_putc('\n');
    mem_copy(destination, source, (usize)RV220W_OPENWRT_ELF_SIZE);
    mips_sync();
    if (!inspect_elf64_be_mips(RV220W_OPENWRT_RAM_ADDR, RV220W_OPENWRT_ELF_SIZE,
                               &inspection, 1)) {
        console_puts("error: RAM copy failed ELF compatibility validation\n");
        return;
    }
    sha256_compute(destination, (usize)RV220W_OPENWRT_ELF_SIZE, destination_digest);
    if (mem_compare(destination_digest, expected_openwrt_sha256, sizeof(destination_digest)) != 0) {
        console_puts("error: RAM-copy SHA-256 mismatch\n  actual=");
        print_digest(destination_digest);
        console_putc('\n');
        return;
    }
    console_puts("copy=ok hash=ok elfcheck=ok; handing off to vendor Linux ELF loader\n");
    (void)boot_linux_elf(RV220W_OPENWRT_RAM_ADDR, "console=ttyS0,115200");
    console_puts("error: bootoctlinux returned\n");
}

static int execute(int argc, char **argv)
{
    if (argc == 0)
        return 1;
    if (str_equal(argv[0], "help") || str_equal(argv[0], "?")) command_help();
    else if (str_equal(argv[0], "info")) command_info();
    else if (str_equal(argv[0], "md")) command_md(argc, argv);
    else if (str_equal(argv[0], "nor")) command_nor(argc, argv);
    else if (str_equal(argv[0], "crc32")) command_crc32(argc, argv);
    else if (str_equal(argv[0], "sha256")) command_sha256(argc, argv);
    else if (str_equal(argv[0], "copy")) command_copy(argc, argv);
    else if (str_equal(argv[0], "bootbus")) command_bootbus();
    else if (str_equal(argv[0], "csr")) command_csr(argc, argv);
    else if (str_equal(argv[0], "env")) command_env();
    else if (str_equal(argv[0], "fwcheck")) command_fwcheck();
    else if (str_equal(argv[0], "mac")) command_mac();
    else if (str_equal(argv[0], "bootcmd-audit")) command_bootcmd_audit();
    else if (str_equal(argv[0], "bootabi")) command_bootabi();
    else if (str_equal(argv[0], "elfcheck")) command_elfcheck(argc, argv);
    else if (str_equal(argv[0], "bootlinux")) command_bootlinux(argc, argv);
    else if (str_equal(argv[0], "boot-openwrt")) command_boot_openwrt();
    else if (str_equal(argv[0], "return") || str_equal(argv[0], "exit")) return 0;
    else console_puts("error: unknown command; type help\n");
    return 1;
}

int stage2_main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    console_init();
    console_puts("\nRV220W recovery stage2 PoC v1.4.0\n");
    console_puts("Retained vendor boot stage; direct UART; read-only NOR policy.\n");
    console_puts("Type help. Use return to resume the vendor U-Boot shell.\n\n");
    while (1) {
        int count;
        int n;
        console_puts("rv220w-stage2> ");
        count = console_readline(line_buffer, sizeof(line_buffer));
        if (count < 0)
            continue;
        n = split_args(line_buffer, argv_buffer, ARRAY_SIZE(argv_buffer));
        if (!execute(n, argv_buffer))
            break;
    }
    console_puts("Returning to vendor U-Boot.\n");
    return 0;
}
