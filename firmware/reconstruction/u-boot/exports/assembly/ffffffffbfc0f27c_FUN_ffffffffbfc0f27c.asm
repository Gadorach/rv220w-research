# RV220W U-Boot v1.1.0 entry=ffffffffbfc0f27c function=FUN_ffffffffbfc0f27c
ffffffffbfc0f27c	andi a1,a1,0xff
ffffffffbfc0f280	b 0xffffffffbfc0f2a8
ffffffffbfc0f284	_clear a3
ffffffffbfc0f288	lbu v0,0xa0d(a0)
ffffffffbfc0f28c	clear t0
ffffffffbfc0f290	addu v1,a2,a3
ffffffffbfc0f294	div a3,v0
ffffffffbfc0f298	teq v0,zero
ffffffffbfc0f29c	mfhi v0
ffffffffbfc0f2a0	movz t0,a1,v0
ffffffffbfc0f2a4	sb t0,-0x1(v1)
ffffffffbfc0f2a8	lbu v0,0xa0c(a0)
ffffffffbfc0f2ac	slt v0,a3,v0
ffffffffbfc0f2b0	bne v0,zero,0xffffffffbfc0f288
ffffffffbfc0f2b4	_addiu a3,a3,0x1
ffffffffbfc0f2b8	jr ra
ffffffffbfc0f2bc	_nop
