#ifndef RV220W_STAGE2_OCTEON_BOOT_ABI_H
#define RV220W_STAGE2_OCTEON_BOOT_ABI_H
#include "types.h"

#define OCTEON_CURRENT_DESC_VERSION 6U
#define OCTEON_ARGV_MAX_ARGS 64U
#define OCTEON_BOOT_DESCRIPTOR_SIZE 400U
#define CVMX_BOOTINFO_V1_2_SIZE 152U

/* Entry register contract used by the Linux Octeon kernel entry macro. */
#define OCTEON_ENTRY_A0_ARGC 0
#define OCTEON_ENTRY_A1_ARGV 1
#define OCTEON_ENTRY_A2_INIT_CORE 2
#define OCTEON_ENTRY_A3_BOOT_DESC 3

#endif
