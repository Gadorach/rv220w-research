# RV220W U-Boot v1.1.0 entry=ffffffffbfc1fa3c function=FUN_ffffffffbfc1fa3c
ffffffffbfc1fa3c	addiu sp,sp,-0x10
ffffffffbfc1fa40	daddu a1,a0,zero
ffffffffbfc1fa44	sd gp,0x0(sp)
ffffffffbfc1fa48	lui gp,0x2
ffffffffbfc1fa4c	addu gp,gp,t9
ffffffffbfc1fa50	clear a2
ffffffffbfc1fa54	sd ra,0x8(sp)
ffffffffbfc1fa58	addiu gp,gp,0x3ca4
ffffffffbfc1fa5c	lw v0,0x344(gp)
ffffffffbfc1fa60	lw t9,0x5b8(gp)
ffffffffbfc1fa64	jalr t9
ffffffffbfc1fa68	_lw a0,0x0(v0)
ffffffffbfc1fa6c	clear v0
ffffffffbfc1fa70	ld ra,0x8(sp)
ffffffffbfc1fa74	ld gp,0x0(sp)
ffffffffbfc1fa78	jr ra
ffffffffbfc1fa7c	_addiu sp,sp,0x10
