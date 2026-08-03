# RV220W U-Boot v1.1.0 entry=ffffffffbfc22a2c function=FUN_ffffffffbfc22a2c
ffffffffbfc22a2c	addiu sp,sp,-0x20
ffffffffbfc22a30	sd gp,0x8(sp)
ffffffffbfc22a34	lui gp,0x2
ffffffffbfc22a38	sd ra,0x10(sp)
ffffffffbfc22a3c	addu gp,gp,t9
ffffffffbfc22a40	sd s0,0x0(sp)
ffffffffbfc22a44	addiu gp,gp,0xcb4
ffffffffbfc22a48	lw t9,0x80c(gp)
ffffffffbfc22a4c	lw s0,0x0(k0)
ffffffffbfc22a50	jalr t9
ffffffffbfc22a54	_nop
ffffffffbfc22a58	lw t9,0x39c(gp)
ffffffffbfc22a5c	jalr t9
ffffffffbfc22a60	_nop
ffffffffbfc22a64	lw t9,0x194(gp)
ffffffffbfc22a68	jalr t9
ffffffffbfc22a6c	_daddu a0,s0,zero
ffffffffbfc22a70	li v1,-0x1
ffffffffbfc22a74	bltz v0,0xffffffffbfc22a88
ffffffffbfc22a78	_lw t9,0x6c0(gp)
ffffffffbfc22a7c	jalr t9
ffffffffbfc22a80	_nop
ffffffffbfc22a84	clear v1
ffffffffbfc22a88	ld ra,0x10(sp)
ffffffffbfc22a8c	daddu v0,v1,zero
ffffffffbfc22a90	ld gp,0x8(sp)
ffffffffbfc22a94	ld s0,0x0(sp)
ffffffffbfc22a98	jr ra
ffffffffbfc22a9c	_addiu sp,sp,0x20
