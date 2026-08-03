#ifndef RV220W_BOARD_RECONSTRUCTION_H
#define RV220W_BOARD_RECONSTRUCTION_H

/* Clean-room reconstruction constants derived from preserved binaries and
 * independently published Cavium executive headers. This is not vendor source. */
#define RV220W_BOARD_TYPE_PRIVATE_UNKNOWN 0 /* stock string identifies CUST_RV200W */
#define RV220W_CORE_CLOCK_HZ 400000000ULL
#define RV220W_DDR_CLOCK_HZ  266000000ULL
#define RV220W_DRAM_BYTES    0x08000000ULL
#define RV220W_FLASH_PHYS    0x1dc00000ULL
#define RV220W_FLASH_BYTES   0x02000000ULL
#define RV220W_ENV_OFFSET    0x01fe0000ULL
#define RV220W_ENV_BYTES     0x00020000ULL
#define RV220W_MAC_OFFSET    0x0006ff00ULL
#define RV220W_LATE_INIT_VA  0xffffffffbfc13084ULL
#define RV220W_FW_CHECK_VA   0xffffffffbfc22834ULL
#define RV220W_HTTP_VA       0xffffffffbfc22bd4ULL
#define RV220W_DOWNLOAD_VA   0xffffffffbfc22d1cULL
#define RV220W_SETENV_WRAP_VA 0xffffffffbfc19b60ULL
#define RV220W_BOOTOCTLINUX_VA 0xffffffffbfc1d950ULL

#endif
