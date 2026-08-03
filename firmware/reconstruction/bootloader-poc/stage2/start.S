/* SPDX-License-Identifier: GPL-2.0-or-later */
.set noreorder
.set noat
.set mips64

.section .text.entry, "ax", @progbits
.align 5
.globl _start
.ent _start
_start:
    /* Preserve the U-Boot bootelf caller's callee-saved state. */
    daddiu  $sp, $sp, -0x70
    sd      $ra, 0x68($sp)
    sd      $gp, 0x60($sp)
    sd      $s8, 0x58($sp)
    sd      $s7, 0x50($sp)
    sd      $s6, 0x48($sp)
    sd      $s5, 0x40($sp)
    sd      $s4, 0x38($sp)
    sd      $s3, 0x30($sp)
    sd      $s2, 0x28($sp)
    sd      $s1, 0x20($sp)
    sd      $s0, 0x18($sp)
    move    $s7, $sp

    /* Move to the private stage2 stack before touching C code. */
    dla     $sp, __stack_top

    /* Clear BSS. */
    dla     $t0, __bss_start
    dla     $t1, __bss_end
1:
    sltu    $t2, $t0, $t1
    beqz    $t2, 2f
    nop
    sd      $zero, 0($t0)
    b       1b
    daddiu  $t0, $t0, 8
2:
    dla     $t0, saved_return_frame
    sd      $s7, 0($t0)

    jal     stage2_main
    nop

    /* Returning is an explicit supported recovery operation. */
    dla     $t0, saved_return_frame
    ld      $sp, 0($t0)
    ld      $s0, 0x18($sp)
    ld      $s1, 0x20($sp)
    ld      $s2, 0x28($sp)
    ld      $s3, 0x30($sp)
    ld      $s4, 0x38($sp)
    ld      $s5, 0x40($sp)
    ld      $s6, 0x48($sp)
    ld      $s7, 0x50($sp)
    ld      $s8, 0x58($sp)
    ld      $gp, 0x60($sp)
    ld      $ra, 0x68($sp)
    move    $v0, $zero
    jr      $ra
    daddiu  $sp, $sp, 0x70
.end _start

.section .bss, "aw", @nobits
.align 3
.globl saved_return_frame
saved_return_frame:
    .dword 0
