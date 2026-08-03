/* SPDX-License-Identifier: GPL-2.0-or-later */
#include "include/crc32.h"

u32 crc32_compute(const void *data, usize length)
{
    const u8 *p = (const u8 *)data;
    u32 crc = 0xffffffffU;
    usize i;
    int bit;
    for (i = 0; i < length; i++) {
        crc ^= p[i];
        for (bit = 0; bit < 8; bit++)
            crc = (crc >> 1) ^ (0xedb88320U & (0U - (crc & 1U)));
    }
    return crc ^ 0xffffffffU;
}
