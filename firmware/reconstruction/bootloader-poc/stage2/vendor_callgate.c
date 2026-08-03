/* SPDX-License-Identifier: GPL-2.0-or-later */
#include "include/vendor_callgate.h"
#include "include/mini_lib.h"

static char command_name[] = "bootoctlinux";
static char address_buffer[19];
static char default_bootargs[] = "console=ttyS0,115200";
static u32 argv32[4];

static void hex_address(char *out, u64 value)
{
    static const char digits[] = "0123456789abcdef";
    int i;
    out[0]='0'; out[1]='x';
    for(i=0;i<16;i++) out[2+i]=digits[(value >> ((15-i)*4)) & 0xf];
    out[18]=0;
}

int boot_linux_elf(u64 address, const char *bootargs)
{
    hex_address(address_buffer,address);
    argv32[0]=(u32)(uintptr)command_name;
    argv32[1]=(u32)(uintptr)address_buffer;
    argv32[2]=(u32)(uintptr)(bootargs ? bootargs : default_bootargs);
    argv32[3]=0;
    mips_sync();
    return vendor_bootoctlinux_call((u32)(uintptr)argv32,3);
}
