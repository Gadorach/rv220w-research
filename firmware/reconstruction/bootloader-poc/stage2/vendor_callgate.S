/* SPDX-License-Identifier: GPL-2.0-or-later */
.set noreorder
.set noat
.set mips64

.text
.align 5
.globl vendor_bootoctlinux_call
.ent vendor_bootoctlinux_call
/*
 * a0 = low 32-bit address of the n32-style argv table
 * a1 = argc
 *
 * The vendor U-Boot command handlers use the conventional command ABI:
 *   handler(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
 * but load argv entries with lw, proving 32-bit pointers. This wrapper creates
 * the register-level bridge from our n64 freestanding monitor.
 */
vendor_bootoctlinux_call:
    daddiu  $sp, $sp, -0x20
    sd      $ra, 0x18($sp)
    sd      $gp, 0x10($sp)
    /* Sign-extend the 32-bit n32 argv-table pointer into KSEG0. */
    dsll    $a3, $a0, 32
    dsra    $a3, $a3, 32
    move    $a2, $a1
    move    $a0, $zero
    move    $a1, $zero
    dli     $t9, 0xffffffffbfc1d950
    jalr    $t9
    nop
    ld      $gp, 0x10($sp)
    ld      $ra, 0x18($sp)
    jr      $ra
    daddiu  $sp, $sp, 0x20
.end vendor_bootoctlinux_call
