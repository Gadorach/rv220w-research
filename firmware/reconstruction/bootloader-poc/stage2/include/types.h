#ifndef RV220W_TYPES_H
#define RV220W_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef unsigned long usize;
typedef unsigned long uintptr;

#define NULL ((void *)0)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#endif
