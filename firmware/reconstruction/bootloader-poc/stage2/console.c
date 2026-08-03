/* SPDX-License-Identifier: GPL-2.0-or-later */
#include "include/console.h"
#include "include/platform.h"
#include "include/mini_lib.h"

static inline u64 csr_read(u64 address)
{
    volatile u64 *reg = (volatile u64 *)(uintptr)address;
    u64 value = *reg;
    __asm__ volatile("sync" ::: "memory");
    return value;
}

static inline void csr_write(u64 address, u64 value)
{
    volatile u64 *reg = (volatile u64 *)(uintptr)address;
    *reg = value;
    __asm__ volatile("sync" ::: "memory");
}

void console_init(void)
{
    /* UART0 was initialized by the retained vendor boot stage. */
    mips_sync();
}

void console_putc(char c)
{
    if (c == '\n')
        console_putc('\r');
    while ((csr_read(UART_REG(UART_LSR)) & UART_LSR_THRE) == 0)
        ;
    csr_write(UART_REG(UART_THR), (u8)c);
}

void console_puts(const char *s)
{
    while (*s)
        console_putc(*s++);
}

int console_tstc(void)
{
    return (csr_read(UART_REG(UART_LSR)) & UART_LSR_DR) != 0;
}

char console_getc(void)
{
    while (!console_tstc())
        ;
    return (char)(csr_read(UART_REG(UART_RBR)) & 0xff);
}

int console_readline(char *buffer, usize capacity)
{
    usize used = 0;
    if (capacity == 0)
        return -1;
    for (;;) {
        char c = console_getc();
        if (c == '\r' || c == '\n') {
            console_putc('\n');
            buffer[used] = 0;
            return (int)used;
        }
        if (c == 3) {
            console_puts("^C\n");
            buffer[0] = 0;
            return -1;
        }
        if (c == 8 || c == 127) {
            if (used) {
                used--;
                console_puts("\b \b");
            }
            continue;
        }
        if (c < 0x20 || c > 0x7e)
            continue;
        if (used + 1 < capacity) {
            buffer[used++] = c;
            console_putc(c);
        }
    }
}

static const char hex_digits[] = "0123456789abcdef";

void print_hex8(u8 value)
{
    console_putc(hex_digits[(value >> 4) & 0xf]);
    console_putc(hex_digits[value & 0xf]);
}

void print_hex32(u32 value)
{
    int shift;
    console_puts("0x");
    for (shift = 28; shift >= 0; shift -= 4)
        console_putc(hex_digits[(value >> shift) & 0xf]);
}

void print_hex64(u64 value)
{
    int shift;
    console_puts("0x");
    for (shift = 60; shift >= 0; shift -= 4)
        console_putc(hex_digits[(value >> shift) & 0xf]);
}

void print_dec_u64(u64 value)
{
    char tmp[24];
    int n = 0;
    if (value == 0) {
        console_putc('0');
        return;
    }
    while (value && n < (int)sizeof(tmp)) {
        tmp[n++] = (char)('0' + value % 10);
        value /= 10;
    }
    while (n)
        console_putc(tmp[--n]);
}
