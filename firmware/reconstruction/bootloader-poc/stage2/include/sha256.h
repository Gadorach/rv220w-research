#ifndef RV220W_SHA256_H
#define RV220W_SHA256_H
#include "types.h"
void sha256_compute(const void *data, usize length, u8 digest[32]);
#endif
