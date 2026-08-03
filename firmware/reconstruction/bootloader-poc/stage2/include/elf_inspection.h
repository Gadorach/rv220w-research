#ifndef RV220W_ELF_INSPECTION_H
#define RV220W_ELF_INSPECTION_H
#include "types.h"

typedef struct {
    u64 entry;
    u64 phoff;
    u16 phentsize;
    u16 phnum;
    u16 load_segments;
    u16 note_segments;
    u16 nonempty_note_segments;
    u16 invalid_load_segments;
} elf64_inspection;

int inspect_elf64_be_mips(u64 address, u64 known_length, elf64_inspection *result, int verbose);
void command_elfcheck(int argc, char **argv);
void command_bootabi(void);

#endif
