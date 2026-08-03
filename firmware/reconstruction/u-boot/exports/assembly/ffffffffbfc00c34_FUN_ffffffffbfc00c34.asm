# RV220W U-Boot v1.1.0 entry=ffffffffbfc00c34 function=FUN_ffffffffbfc00c34
ffffffffbfc00c34	addiu sp,sp,-0x20
ffffffffbfc00c38	sltiu v0,a0,0x7
ffffffffbfc00c3c	sd gp,0x10(sp)
ffffffffbfc00c40	lui gp,0x4
ffffffffbfc00c44	sd ra,0x18(sp)
ffffffffbfc00c48	addu gp,gp,t9
ffffffffbfc00c4c	sd s1,0x8(sp)
ffffffffbfc00c50	addiu gp,gp,0x2aac
ffffffffbfc00c54	beq v0,zero,0xffffffffbfc00da4
ffffffffbfc00c58	_sd s0,0x0(sp)
ffffffffbfc00c5c	lw v1,0x10(gp)
ffffffffbfc00c60	sll v0,a0,0x2
ffffffffbfc00c64	addiu v1,v1,0x5c90
ffffffffbfc00c68	addu v0,v0,v1
ffffffffbfc00c6c	lw v0,0x0(v0)
ffffffffbfc00c70	addu v0,v0,gp
ffffffffbfc00c74	jr v0
ffffffffbfc00c78	_nop
ffffffffbfc00da4	b 0xffffffffbfc00db0
ffffffffbfc00da8	_clear v0
ffffffffbfc00db0	ld ra,0x18(sp)
ffffffffbfc00db4	ld gp,0x10(sp)
ffffffffbfc00db8	ld s1,0x8(sp)
ffffffffbfc00dbc	ld s0,0x0(sp)
ffffffffbfc00dc0	jr ra
ffffffffbfc00dc4	_addiu sp,sp,0x20
