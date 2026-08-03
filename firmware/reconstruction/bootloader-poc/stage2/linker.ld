OUTPUT_ARCH(mips)
ENTRY(_start)

SECTIONS
{
    . = 0xffffffff84000000;
    __image_start = .;

    .text : ALIGN(16) {
        KEEP(*(.text.entry))
        *(.text .text.*)
    }

    .rodata : ALIGN(16) {
        *(.rodata .rodata.*)
    }

    .data : ALIGN(16) {
        *(.data .data.*)
    }

    .got : ALIGN(16) {
        *(.got .got.*)
    }

    __bss_start = .;
    .bss (NOLOAD) : ALIGN(16) {
        *(.bss .bss.* COMMON)
    }
    __bss_end = ALIGN(16);

    . = ALIGN(4096);
    __stack_bottom = .;
    . += 0x20000;
    __stack_top = .;
    __image_end = .;

    /DISCARD/ : {
        *(.comment)
        *(.note*)
        *(.eh_frame*)
        *(.MIPS.abiflags)
        *(.gnu.attributes)
    }
}
