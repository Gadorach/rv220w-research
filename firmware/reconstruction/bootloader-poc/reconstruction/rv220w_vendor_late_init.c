/* Clean-room pseudocode reconstructed from the RV220W boot-chain binary.
 * It is intentionally not linked into the stage2 monitor. */
#include "rv220w_board_reconstruction.h"

typedef int (*command_wrapper_t)(const char *name, const char *value);
typedef int (*firmware_check_t)(const void *image);
typedef int (*recovery_t)(unsigned long loadaddr, const char *mode);

static const char stock_bootcmd[] =
    "cp.b BDC80000 0x2a00000 580000;bootoctlinux 0x2a00200 "
    "mtdparts=phys_mapped_flash:512k(bootloader)ro,6M(kernel),16M(rootfs),"
    "1024k(data),128k(bootload-env)";

int rv220w_board_late_init_reconstructed(void)
{
    command_wrapper_t set_environment = (command_wrapper_t)RV220W_SETENV_WRAP_VA;
    firmware_check_t check_firmware = (firmware_check_t)RV220W_FW_CHECK_VA;
    recovery_t run_download = (recovery_t)RV220W_DOWNLOAD_VA;
    recovery_t run_http = (recovery_t)RV220W_HTTP_VA;
    int push_button;
    int valid;

    rv220w_disable_bcm53115();
    rv220w_set_reg_sc();
    push_button = rv220w_read_recovery_button();
    rv220w_print_push_button(push_button);

    /* GPIO 1 is active low. Hardware validation confirms this path remains
     * functional after the selective HTTP-recovery bypass. */
    if (push_button == 0)
        run_download(0x03000000UL, "download");

    valid = check_firmware((const void *)0xffffffffbdc80000ULL);
    if (valid < 0)
        run_http(0x03000000UL, "http");

    /* Proven final tail call at VA bfc13168. It runs after env_relocate(). */
    return set_environment("bootcmd", stock_bootcmd);
}

/* Hardware-validated patch policy:
 *
 *   0x13138: bgez v0,success -> b success
 *             Skip only run_http() after a failed proprietary-format check.
 *             The active-low run_download() path above is preserved.
 *
 *   0x13168: jr t9 -> jr ra
 *             Return after the existing epilogue instead of calling
 *             set_environment("bootcmd", stock_bootcmd).
 */
