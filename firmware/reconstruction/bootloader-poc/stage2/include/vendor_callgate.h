#ifndef RV220W_VENDOR_CALLGATE_H
#define RV220W_VENDOR_CALLGATE_H
#include "types.h"
int vendor_bootoctlinux_call(u32 argv_address, int argc);
int boot_linux_elf(u64 address, const char *bootargs);
#endif
