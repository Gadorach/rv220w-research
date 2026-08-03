#ifndef RV220W_OCTEON_BOOT_ABI_V6_H
#define RV220W_OCTEON_BOOT_ABI_V6_H

/*
 * Clean-room layout record for the Octeon application boot ABI used by the
 * RV220W's SDK 1.7.3 build-264 lineage.  This file contains field names,
 * scalar types and verified offsets only; it does not copy donor algorithms.
 */
#include <stddef.h>
#include <stdint.h>

#define RV220W_OCTEON_DESC_VERSION 6u
#define RV220W_OCTEON_ARGV_MAX 64u
#define RV220W_OCTEON_SERIAL_LEN 20u

typedef struct {
    uint32_t desc_version;
    uint32_t desc_size;
    uint64_t stack_top;
    uint64_t heap_base;
    uint64_t heap_end;
    uint64_t entry_point;
    uint64_t desc_vaddr;
    uint32_t exception_base_addr;
    uint32_t stack_size;
    uint32_t heap_size;
    uint32_t argc;
    uint32_t argv[RV220W_OCTEON_ARGV_MAX];
    uint32_t flags;
    uint32_t core_mask;
    uint32_t dram_size;
    uint32_t phy_mem_desc_addr;
    uint32_t debugger_flags_base_addr;
    uint32_t eclock_hz;
    uint32_t dclock_hz;
    uint32_t spi_clock_hz;
    uint16_t board_type;
    uint8_t board_rev_major;
    uint8_t board_rev_minor;
    uint16_t chip_type;
    uint8_t chip_rev_major;
    uint8_t chip_rev_minor;
    uint8_t board_serial_number[RV220W_OCTEON_SERIAL_LEN];
    uint8_t mac_addr_base[6];
    uint8_t mac_addr_count;
    uint8_t reserved_align_387_391[5];
    uint64_t cvmx_desc_vaddr;
} rv220w_octeon_boot_descriptor_v6;

typedef struct {
    uint32_t major_version;
    uint32_t minor_version;
    uint64_t stack_top;
    uint64_t heap_base;
    uint64_t heap_end;
    uint64_t desc_vaddr;
    uint32_t exception_base_addr;
    uint32_t stack_size;
    uint32_t flags;
    uint32_t core_mask;
    uint32_t dram_size;
    uint32_t phy_mem_desc_addr;
    uint32_t debugger_flags_base_addr;
    uint32_t eclock_hz;
    uint32_t dclock_hz;
    uint32_t reserved0;
    uint16_t board_type;
    uint8_t board_rev_major;
    uint8_t board_rev_minor;
    uint16_t reserved1;
    uint8_t reserved2;
    uint8_t reserved3;
    uint8_t board_serial_number[RV220W_OCTEON_SERIAL_LEN];
    uint8_t mac_addr_base[6];
    uint8_t mac_addr_count;
    uint8_t reserved_align_115_119[5];
    uint64_t compact_flash_common_base_addr;
    uint64_t compact_flash_attribute_base_addr;
    uint64_t led_display_base_addr;
    uint32_t dfa_ref_clock_hz;
    uint32_t config_flags;
} rv220w_cvmx_bootinfo_v1_2;

#define RV220W_ABI_ASSERT(name, expression) _Static_assert((expression), #name)
RV220W_ABI_ASSERT(desc_size, sizeof(rv220w_octeon_boot_descriptor_v6) == 400);
RV220W_ABI_ASSERT(desc_argv, offsetof(rv220w_octeon_boot_descriptor_v6, argv) == 64);
RV220W_ABI_ASSERT(desc_flags, offsetof(rv220w_octeon_boot_descriptor_v6, flags) == 320);
RV220W_ABI_ASSERT(desc_board_type, offsetof(rv220w_octeon_boot_descriptor_v6, board_type) == 352);
RV220W_ABI_ASSERT(desc_serial, offsetof(rv220w_octeon_boot_descriptor_v6, board_serial_number) == 360);
RV220W_ABI_ASSERT(desc_mac, offsetof(rv220w_octeon_boot_descriptor_v6, mac_addr_base) == 380);
RV220W_ABI_ASSERT(desc_cvmx, offsetof(rv220w_octeon_boot_descriptor_v6, cvmx_desc_vaddr) == 392);
RV220W_ABI_ASSERT(bootinfo_size, sizeof(rv220w_cvmx_bootinfo_v1_2) == 152);
RV220W_ABI_ASSERT(bootinfo_board_type, offsetof(rv220w_cvmx_bootinfo_v1_2, board_type) == 80);
RV220W_ABI_ASSERT(bootinfo_serial, offsetof(rv220w_cvmx_bootinfo_v1_2, board_serial_number) == 88);
RV220W_ABI_ASSERT(bootinfo_mac, offsetof(rv220w_cvmx_bootinfo_v1_2, mac_addr_base) == 108);
RV220W_ABI_ASSERT(bootinfo_cf, offsetof(rv220w_cvmx_bootinfo_v1_2, compact_flash_common_base_addr) == 120);
RV220W_ABI_ASSERT(bootinfo_flags, offsetof(rv220w_cvmx_bootinfo_v1_2, config_flags) == 148);
#undef RV220W_ABI_ASSERT

#endif
