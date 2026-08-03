/* Clean-room behavioral reconstruction, not copied vendor source. */
#include <stdint.h>
#include <stddef.h>

#define SERCOMM_HEADER_BYTES 0x200u
#define SERCOMM_TRAILER_BACK 0x80u
#define SERCOMM_MAGIC "FWCHKADDISABABA"

struct rv220w_sercomm_header_reconstructed {
    uint8_t unknown_00[0x0c];
    uint32_t used_length_be;
    uint32_t image_size_be;
    uint32_t additive_checksum_be;
    uint8_t reserved_18[4];
    char firmware_version[12];
    char hardware_version[12];
    char family[32];
    char build_time[32];
    char image_name[64];
    uint8_t remainder[SERCOMM_HEADER_BYTES - 0xb4];
};

/* Upgrade-time additive check proven from the preserved stock image. */
uint32_t rv220w_sercomm_additive_checksum(const uint8_t *image, uint32_t size)
{
    uint32_t sum = 0;
    uint32_t i;
    for (i = 0; i < size; ++i) {
        if (i >= 0x14 && i < 0x18)
            continue;
        sum += image[i];
    }
    return sum;
}

/* Early startup appears to use size/name/trailer structure before autoboot.
 * Whether it also enforces the additive checksum at this point is not proven. */
int rv220w_sercomm_early_structure_valid(const uint8_t *image, uint32_t flash_limit)
{
    uint32_t size = ((uint32_t)image[0x10] << 24) |
                    ((uint32_t)image[0x11] << 16) |
                    ((uint32_t)image[0x12] << 8) | image[0x13];
    const uint8_t *trailer;
    unsigned i;
    if (size < SERCOMM_TRAILER_BACK || size > flash_limit)
        return -1;
    trailer = image + size - SERCOMM_TRAILER_BACK;
    for (i = 0; i < sizeof(SERCOMM_MAGIC)-1; ++i)
        if (trailer[i] != (uint8_t)SERCOMM_MAGIC[i])
            return -1;
    return 0;
}
