# RV220W U-Boot v1.1.0 entry=ffffffffbfc27c5c function=FUN_ffffffffbfc27c5c
ffffffffbfc27c5c	addiu sp,sp,-0x20
ffffffffbfc27c60	li v0,0xa
ffffffffbfc27c64	sd gp,0x8(sp)
ffffffffbfc27c68	lui gp,0x2
ffffffffbfc27c6c	sd s0,0x0(sp)
ffffffffbfc27c70	addu gp,gp,t9
ffffffffbfc27c74	sd ra,0x10(sp)
ffffffffbfc27c78	seb s0,a0
ffffffffbfc27c7c	addiu gp,gp,-0x457c
ffffffffbfc27c80	bne s0,v0,0xffffffffbfc27c9c
ffffffffbfc27c84	_li a1,0xd
ffffffffbfc27c88	lw t9,0x20(gp)
ffffffffbfc27c8c	lw a0,0x38(k0)
ffffffffbfc27c90	addiu t9,t9,0x7c04
ffffffffbfc27c94	jalr t9
ffffffffbfc27c98	_nop
ffffffffbfc27c9c	lw t9,0x20(gp)
ffffffffbfc27ca0	andi a1,s0,0xff
ffffffffbfc27ca4	ld gp,0x8(sp)
ffffffffbfc27ca8	lw a0,0x38(k0)
ffffffffbfc27cac	addiu t9,t9,0x7c04
ffffffffbfc27cb0	ld ra,0x10(sp)
ffffffffbfc27cb4	ld s0,0x0(sp)
ffffffffbfc27cb8	jr t9
ffffffffbfc27cbc	_addiu sp,sp,0x20
