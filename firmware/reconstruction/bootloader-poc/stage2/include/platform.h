#ifndef RV220W_PLATFORM_H
#define RV220W_PLATFORM_H

#include "types.h"

/* Hardware-proven RV220W/CN5010 addresses. */
#define RV220W_DRAM_SIZE             0x08000000ULL
#define RV220W_NOR_PHYS              0x1dc00000ULL
#define RV220W_NOR_KSEG1             0xffffffffbdc00000ULL
#define RV220W_NOR_SIZE              0x02000000ULL
#define RV220W_OPENWRT_SLOT_OFFSET   0x00080000ULL
#define RV220W_OPENWRT_SLOT_ADDR     (RV220W_NOR_KSEG1 + RV220W_OPENWRT_SLOT_OFFSET)
#define RV220W_OPENWRT_ELF_SIZE      0x011565d0ULL
#define RV220W_OPENWRT_RAM_ADDR      0x05500000ULL

/* Stage2 occupies physical 64-67 MiB. Keep user copies out of this window. */
#define RV220W_STAGE2_LINK_VA        0xffffffff84000000ULL
#define RV220W_STAGE2_PHYS_START     0x04000000ULL
#define RV220W_STAGE2_PHYS_END       0x04300000ULL

/* Octeon MIO UART0 CSR block, XKPHYS uncached alias. */
#define CVMX_MIO_UART0_BASE          0x8001180000000800ULL
#define UART_RBR                     0
#define UART_THR                     0
#define UART_LSR                     5
#define UART_REG(n)                  (CVMX_MIO_UART0_BASE + ((u64)(n) << 3))
#define UART_LSR_DR                  0x01
#define UART_LSR_THRE                0x20


/* Exact-generation Cavium SDK 1.7.3/264 donor-derived CSR addresses. */
#define CVMX_MIO_BOOT_REG_CFGX(n)    (0x8001180000000000ULL + (((u64)(n) & 7ULL) << 3))
#define CVMX_MIO_BOOT_REG_TIMX(n)    (0x8001180000000040ULL + (((u64)(n) & 7ULL) << 3))
#define RV220W_ENV_OFFSET            0x01fe0000ULL
#define RV220W_ENV_SIZE              0x00020000ULL
#define RV220W_BOARD_DATA_OFFSET     0x0006f000ULL
#define RV220W_BASE_MAC_OFFSET       0x0006ff00ULL
#define RV220W_VENDOR_HEADER_OFFSET  0x00080000ULL
#define RV220W_VENDOR_REGION_SIZE    0x01600000ULL
#define RV220W_COMPILED_BOOTCMD_OFF  0x000363b0ULL
#define RV220W_BOOTCMD_PATCH_OFF     0x00013168ULL
#define RV220W_FW_HEADER_SIZE        0x200ULL

/* Function address recovered from the stock U-Boot command table. */
#define RV220W_VENDOR_BOOTOCTLINUX   0xffffffffbfc1d950ULL

#endif
