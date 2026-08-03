#ifndef RV220W_CONSOLE_H
#define RV220W_CONSOLE_H

#include "types.h"

void console_init(void);
void console_putc(char c);
void console_puts(const char *s);
int console_tstc(void);
char console_getc(void);
int console_readline(char *buffer, usize capacity);
void print_hex8(u8 value);
void print_hex32(u32 value);
void print_hex64(u64 value);
void print_dec_u64(u64 value);

#endif
