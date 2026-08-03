# RV220W U-Boot v1.1.0 entry=ffffffffbfc0c2ac function=FUN_ffffffffbfc0c2ac
ffffffffbfc0c2ac	addiu sp,sp,-0x20
ffffffffbfc0c2b0	li a2,0x4
ffffffffbfc0c2b4	sd gp,0x10(sp)
ffffffffbfc0c2b8	lui gp,0x3
ffffffffbfc0c2bc	sd ra,0x18(sp)
ffffffffbfc0c2c0	addu gp,gp,t9
ffffffffbfc0c2c4	sw a1,0x0(sp)
ffffffffbfc0c2c8	addiu gp,gp,0x7434
ffffffffbfc0c2cc	lw t9,0x7a4(gp)
ffffffffbfc0c2d0	jalr t9
ffffffffbfc0c2d4	_daddu a1,sp,zero
ffffffffbfc0c2d8	ld ra,0x18(sp)
ffffffffbfc0c2dc	ld gp,0x10(sp)
ffffffffbfc0c2e0	jr ra
ffffffffbfc0c2e4	_addiu sp,sp,0x20
