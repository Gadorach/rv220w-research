# RV220W U-Boot v1.1.0 entry=ffffffffbfc0bf08 function=FUN_ffffffffbfc0bf08
ffffffffbfc0bf08	addiu sp,sp,-0x10
ffffffffbfc0bf0c	li v1,0xfff
ffffffffbfc0bf10	sd gp,0x0(sp)
ffffffffbfc0bf14	lui gp,0x3
ffffffffbfc0bf18	sd ra,0x8(sp)
ffffffffbfc0bf1c	addu gp,gp,t9
ffffffffbfc0bf20	beq a0,zero,0xffffffffbfc0bf54
ffffffffbfc0bf24	_addiu gp,gp,0x77d8
ffffffffbfc0bf28	lbu v0,0x0(a0)
ffffffffbfc0bf2c	clear a1
ffffffffbfc0bf30	lw t9,0x1d0(gp)
ffffffffbfc0bf34	addiu v0,v0,-0x30
ffffffffbfc0bf38	andi v0,v0,0xff
ffffffffbfc0bf3c	sltiu v0,v0,0xa
ffffffffbfc0bf40	beq v0,zero,0xffffffffbfc0bf54
ffffffffbfc0bf44	_li a2,0xa
ffffffffbfc0bf48	jalr t9
ffffffffbfc0bf4c	_nop
ffffffffbfc0bf50	andi v1,v0,0xffff
ffffffffbfc0bf54	ld ra,0x8(sp)
ffffffffbfc0bf58	daddu v0,v1,zero
ffffffffbfc0bf5c	ld gp,0x0(sp)
ffffffffbfc0bf60	jr ra
ffffffffbfc0bf64	_addiu sp,sp,0x10
