/* SPDX-License-Identifier: GPL-2.0-or-later */
#include "include/mini_lib.h"
#include "include/platform.h"

void *mem_copy(void *dst, const void *src, usize length)
{
    u8 *d = (u8 *)dst;
    const u8 *s = (const u8 *)src;
    while (length--)
        *d++ = *s++;
    return dst;
}

void *mem_set(void *dst, int value, usize length)
{
    u8 *d = (u8 *)dst;
    while (length--)
        *d++ = (u8)value;
    return dst;
}

int mem_compare(const void *a, const void *b, usize length)
{
    const u8 *x = (const u8 *)a;
    const u8 *y = (const u8 *)b;
    while (length--) {
        if (*x != *y)
            return (int)*x - (int)*y;
        x++;
        y++;
    }
    return 0;
}

usize str_length(const char *s)
{
    usize n = 0;
    while (s[n])
        n++;
    return n;
}

int str_equal(const char *a, const char *b)
{
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return *a == *b;
}

int str_prefix(const char *s, const char *prefix)
{
    while (*prefix) {
        if (*s++ != *prefix++)
            return 0;
    }
    return 1;
}

int split_args(char *line, char **argv, int max_args)
{
    int argc = 0;
    while (*line) {
        while (*line == ' ' || *line == '\t')
            *line++ = 0;
        if (!*line)
            break;
        if (argc >= max_args)
            return argc;
        argv[argc++] = line;
        while (*line && *line != ' ' && *line != '\t')
            line++;
    }
    return argc;
}

int parse_u64(const char *s, u64 *value)
{
    u64 result = 0;
    int base = 10;
    int digit;
    if (!s || !*s)
        return 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        base = 16;
        s += 2;
    }
    if (!*s)
        return 0;
    while (*s) {
        if (*s >= '0' && *s <= '9')
            digit = *s - '0';
        else if (*s >= 'a' && *s <= 'f')
            digit = *s - 'a' + 10;
        else if (*s >= 'A' && *s <= 'F')
            digit = *s - 'A' + 10;
        else
            return 0;
        if (digit >= base)
            return 0;
        if (result > (~0ULL - (u64)digit) / (u64)base)
            return 0;
        result = result * (u64)base + (u64)digit;
        s++;
    }
    *value = result;
    return 1;
}

u64 canonicalize_mips_address(u64 address)
{
    if (address <= 0xffffffffULL && (address & 0x80000000ULL))
        return 0xffffffff00000000ULL | address;
    return address;
}

static int range_end(u64 start, u64 length, u64 *end)
{
    if (length == 0 || start > ~0ULL - (length - 1))
        return 0;
    *end = start + length - 1;
    return 1;
}


static int map_dram_phys(u64 address, u64 *phys_start)
{
    u64 low = address & 0xffffffffULL;

    if (address < RV220W_DRAM_SIZE) {
        *phys_start = address;
        return 1;
    }
    if ((address >> 32) == 0xffffffffULL &&
        low >= 0x80000000ULL && low < 0xc0000000ULL) {
        *phys_start = low & 0x1fffffffULL;
        return 1;
    }
    if (address >= 0x8000000000000000ULL &&
        address < 0x8000000000000000ULL + RV220W_DRAM_SIZE) {
        *phys_start = address - 0x8000000000000000ULL;
        return 1;
    }
    return 0;
}

int address_to_dram_phys(u64 address, u64 length, u64 *phys_start)
{
    u64 phys;
    u64 end;
    if (!map_dram_phys(address, &phys))
        return 0;
    if (!range_end(phys, length, &end) || end >= RV220W_DRAM_SIZE)
        return 0;
    if (!(end < RV220W_STAGE2_PHYS_START || phys >= RV220W_STAGE2_PHYS_END))
        return 0;
    *phys_start = phys;
    return 1;
}

int address_is_known_readable(u64 address, u64 length)
{
    u64 end;
    u64 phys;

    if (!range_end(address, length, &end))
        return 0;
    if (map_dram_phys(address, &phys))
        return phys <= RV220W_DRAM_SIZE - length;
    if (address >= RV220W_NOR_KSEG1 &&
        address <= RV220W_NOR_KSEG1 + RV220W_NOR_SIZE - 1)
        return end <= RV220W_NOR_KSEG1 + RV220W_NOR_SIZE - 1;
    return 0;
}

void mips_sync(void)
{
    __asm__ volatile("sync" ::: "memory");
}
