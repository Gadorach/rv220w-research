/* SPDX-License-Identifier: GPL-2.0-or-later */
#include "include/types.h"
#include "include/platform.h"
#include "include/console.h"
#include "include/mini_lib.h"
#include "include/crc32.h"
#include "include/inspection.h"

static u32 read_be32(const volatile u8 *p)
{
    return ((u32)p[0] << 24) | ((u32)p[1] << 16) | ((u32)p[2] << 8) | p[3];
}

static u64 read_csr(u64 address)
{
    return *(const volatile u64 *)(uintptr)address;
}

static void print_ascii_field(const volatile u8 *p, usize limit)
{
    usize i;
    for (i = 0; i < limit && p[i]; i++) {
        u8 c = p[i];
        console_putc((c >= 0x20 && c <= 0x7e) ? (char)c : '.');
    }
}

static int bytes_equal(const volatile u8 *a, const char *b, usize n)
{
    usize i;
    for (i = 0; i < n; i++)
        if (a[i] != (u8)b[i])
            return 0;
    return 1;
}

static int env_crc_valid(const volatile u8 **data_out)
{
    const volatile u8 *sector = (const volatile u8 *)(uintptr)(RV220W_NOR_KSEG1 + RV220W_ENV_OFFSET);
    u32 stored = read_be32(sector);
    u32 computed = crc32_compute((const void *)(uintptr)(sector + 4), RV220W_ENV_SIZE - 4);
    console_puts("env_addr="); print_hex64((u64)(uintptr)sector); console_putc('\n');
    console_puts("env_bytes="); print_dec_u64(RV220W_ENV_SIZE); console_putc('\n');
    console_puts("stored_crc="); print_hex32(stored); console_putc('\n');
    console_puts("computed_crc="); print_hex32(computed); console_putc('\n');
    console_puts("crc_valid="); console_puts(stored == computed ? "yes\n" : "no\n");
    if (data_out)
        *data_out = sector + 4;
    return stored == computed;
}

static const volatile u8 *env_find(const volatile u8 *data, const char *name)
{
    usize pos = 0;
    usize name_len = str_length(name);
    while (pos + 1 < RV220W_ENV_SIZE - 4) {
        const volatile u8 *entry = data + pos;
        usize len = 0;
        if (!entry[0])
            return NULL;
        while (pos + len < RV220W_ENV_SIZE - 4 && entry[len])
            len++;
        if (len > name_len && entry[name_len] == '=' &&
            mem_compare((const void *)(uintptr)entry, name, name_len) == 0)
            return entry + name_len + 1;
        pos += len + 1;
    }
    return NULL;
}

void command_env(void)
{
    const volatile u8 *data;
    usize pos = 0;
    if (!env_crc_valid(&data)) {
        console_puts("Persistent environment is invalid; vendor compiled defaults are active.\n");
        return;
    }
    console_puts("environment:\n");
    while (pos + 1 < RV220W_ENV_SIZE - 4) {
        const volatile u8 *entry = data + pos;
        usize len = 0;
        if (!entry[0])
            break;
        while (pos + len < RV220W_ENV_SIZE - 4 && entry[len])
            len++;
        console_puts("  ");
        print_ascii_field(entry, len);
        console_putc('\n');
        pos += len + 1;
    }
}

void command_mac(void)
{
    const volatile u8 *mac = (const volatile u8 *)(uintptr)(RV220W_NOR_KSEG1 + RV220W_BASE_MAC_OFFSET);
    int i;
    console_puts("base_mac_offset="); print_hex64(RV220W_BASE_MAC_OFFSET); console_putc('\n');
    console_puts("base_mac=");
    for (i = 0; i < 6; i++) {
        print_hex8(mac[i]);
        if (i != 5)
            console_putc(':');
    }
    console_putc('\n');
}

void command_bootbus(void)
{
    u64 cfg = read_csr(CVMX_MIO_BOOT_REG_CFGX(0));
    u64 tim = read_csr(CVMX_MIO_BOOT_REG_TIMX(0));
    u64 base = (cfg & 0xffffULL) << 16;
    u64 size = (((cfg >> 16) & 0xfffULL) + 1ULL) << 16;
    console_puts("sdk_source=Cavium-Octeon-SDK-1.7.3-build-264\n");
    console_puts("cfg0_addr="); print_hex64(CVMX_MIO_BOOT_REG_CFGX(0)); console_putc('\n');
    console_puts("cfg0_raw="); print_hex64(cfg); console_putc('\n');
    console_puts("tim0_addr="); print_hex64(CVMX_MIO_BOOT_REG_TIMX(0)); console_putc('\n');
    console_puts("tim0_raw="); print_hex64(tim); console_putc('\n');
    console_puts("enabled="); print_dec_u64((cfg >> 31) & 1ULL); console_putc('\n');
    console_puts("base="); print_hex64(base); console_putc('\n');
    console_puts("region_bytes="); print_hex64(size); console_putc('\n');
    console_puts("width_bit="); print_dec_u64((cfg >> 28) & 1ULL); console_puts(" (CN50xx: 1 selects 16-bit boot-bus width)\n");
    console_puts("rv220w_flash_phys="); print_hex64(RV220W_NOR_PHYS); console_putc('\n');
    console_puts("rv220w_flash_bytes="); print_hex64(RV220W_NOR_SIZE); console_putc('\n');
}

void command_csr(int argc, char **argv)
{
    u64 address = 0;
    if (argc != 2) {
        console_puts("error: csr accepts bootcfg0, boottim0, or uartlsr\n");
        return;
    }
    if (str_equal(argv[1], "bootcfg0"))
        address = CVMX_MIO_BOOT_REG_CFGX(0);
    else if (str_equal(argv[1], "boottim0"))
        address = CVMX_MIO_BOOT_REG_TIMX(0);
    else if (str_equal(argv[1], "uartlsr"))
        address = UART_REG(UART_LSR);
    else {
        console_puts("error: CSR name not in the read-only allowlist\n");
        return;
    }
    console_puts("csr_addr="); print_hex64(address); console_putc('\n');
    console_puts("csr_value="); print_hex64(read_csr(address)); console_putc('\n');
}

void command_fwcheck(void)
{
    const volatile u8 *image = (const volatile u8 *)(uintptr)(RV220W_NOR_KSEG1 + RV220W_VENDOR_HEADER_OFFSET);
    u32 used = read_be32(image + 0x0c);
    u32 image_size = read_be32(image + 0x10);
    u32 stored_sum = read_be32(image + 0x14);
    u32 sum = 0;
    u32 i;
    int size_ok = image_size >= 0x80 && image_size <= RV220W_VENDOR_REGION_SIZE;
    int trailer_ok = 0;
    console_puts("header_addr="); print_hex64((u64)(uintptr)image); console_putc('\n');
    console_puts("header_used_length="); print_hex32(used); console_putc('\n');
    console_puts("image_size="); print_dec_u64(image_size); console_putc('\n');
    console_puts("stored_additive_checksum="); print_hex32(stored_sum); console_putc('\n');
    console_puts("image_name="); print_ascii_field(image + 0x74, 64); console_putc('\n');
    if (size_ok) {
        for (i = 0; i < image_size; i++) {
            if (i >= 0x14 && i < 0x18)
                continue;
            sum += image[i];
        }
        trailer_ok = bytes_equal(image + image_size - 0x80, "FWCHKADDISABABA", 15);
        console_puts("computed_additive_checksum="); print_hex32(sum); console_putc('\n');
        console_puts("checksum_valid="); console_puts(sum == stored_sum ? "yes\n" : "no\n");
        console_puts("trailer_valid="); console_puts(trailer_ok ? "yes\n" : "no\n");
    } else {
        console_puts("size_valid=no\n");
        console_puts("The slot is likely a raw OpenWrt ELF rather than a Sercomm wrapper.\n");
    }
}

void command_bootcmd_audit(void)
{
    const volatile u8 *data;
    const volatile u8 *value = NULL;
    const volatile u8 *compiled = (const volatile u8 *)(uintptr)(RV220W_NOR_KSEG1 + RV220W_COMPILED_BOOTCMD_OFF);
    const volatile u8 *patch = (const volatile u8 *)(uintptr)(RV220W_NOR_KSEG1 + RV220W_BOOTCMD_PATCH_OFF);
    int valid = env_crc_valid(&data);
    if (valid)
        value = env_find(data, "bootcmd");
    console_puts("compiled_bootcmd_addr="); print_hex64((u64)(uintptr)compiled); console_putc('\n');
    console_puts("compiled_bootcmd="); print_ascii_field(compiled, 256); console_putc('\n');
    console_puts("late_init_tailcall_addr="); print_hex64((u64)(uintptr)patch); console_putc('\n');
    console_puts("late_init_tailcall_bytes=");
    print_hex8(patch[0]); print_hex8(patch[1]); print_hex8(patch[2]); print_hex8(patch[3]); console_putc('\n');
    console_puts("tailcall_state=");
    if (patch[0] == 0x03 && patch[1] == 0x20 && patch[2] == 0x00 && patch[3] == 0x08)
        console_puts("vendor-force-enabled (jr t9)\n");
    else if (patch[0] == 0x03 && patch[1] == 0xe0 && patch[2] == 0x00 && patch[3] == 0x08)
        console_puts("force-suppressed (jr ra)\n");
    else
        console_puts("unknown bytes; do not patch\n");
    console_puts("persistent_bootcmd=");
    if (value)
        print_ascii_field(value, 512);
    else
        console_puts("<unavailable>");
    console_putc('\n');
    console_puts("interpretation=late board initialization overwrites imported bootcmd after CRC validation\n");
}
