# RV220W U-Boot v1.1.0 entry=ffffffffbfc0bf68 function=FUN_ffffffffbfc0bf68
ffffffffbfc0bf68	addiu sp,sp,-0x10
ffffffffbfc0bf6c	sd gp,0x0(sp)
ffffffffbfc0bf70	lui gp,0x3
ffffffffbfc0bf74	sd ra,0x8(sp)
ffffffffbfc0bf78	addu gp,gp,t9
ffffffffbfc0bf7c	addiu gp,gp,0x7778
ffffffffbfc0bf80	lw t9,0x82c(gp)
ffffffffbfc0bf84	jalr t9
ffffffffbfc0bf88	_nop
ffffffffbfc0bf8c	lw t9,0x340(gp)
ffffffffbfc0bf90	jalr t9
ffffffffbfc0bf94	_daddu a0,v0,zero
ffffffffbfc0bf98	ld ra,0x8(sp)
ffffffffbfc0bf9c	ld gp,0x0(sp)
ffffffffbfc0bfa0	jr ra
ffffffffbfc0bfa4	_addiu sp,sp,0x10
