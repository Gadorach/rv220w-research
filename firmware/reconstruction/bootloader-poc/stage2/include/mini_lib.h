#ifndef RV220W_MINI_LIB_H
#define RV220W_MINI_LIB_H

#include "types.h"

void *mem_copy(void *dst, const void *src, usize length);
void *mem_set(void *dst, int value, usize length);
int mem_compare(const void *a, const void *b, usize length);
usize str_length(const char *s);
int str_equal(const char *a, const char *b);
int str_prefix(const char *s, const char *prefix);
int split_args(char *line, char **argv, int max_args);
int parse_u64(const char *s, u64 *value);
u64 canonicalize_mips_address(u64 address);
int address_to_dram_phys(u64 address, u64 length, u64 *phys_start);
int address_is_known_readable(u64 address, u64 length);
void mips_sync(void);

#endif
