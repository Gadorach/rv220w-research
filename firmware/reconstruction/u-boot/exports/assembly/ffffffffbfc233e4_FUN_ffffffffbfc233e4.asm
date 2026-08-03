# RV220W U-Boot v1.1.0 entry=ffffffffbfc233e4 function=FUN_ffffffffbfc233e4
ffffffffbfc233e4	addiu sp,sp,-0x20
ffffffffbfc233e8	sd gp,0x10(sp)
ffffffffbfc233ec	lui gp,0x2
ffffffffbfc233f0	sd s0,0x0(sp)
ffffffffbfc233f4	addu gp,gp,t9
ffffffffbfc233f8	lw s0,0x0(a0)
ffffffffbfc233fc	addiu gp,gp,0x2fc
ffffffffbfc23400	sd s1,0x8(sp)
ffffffffbfc23404	daddu s1,a0,zero
ffffffffbfc23408	sd ra,0x18(sp)
ffffffffbfc2340c	beq s0,zero,0xffffffffbfc23430
ffffffffbfc23410	_lw t9,0x60(gp)
ffffffffbfc23414	jalr t9
ffffffffbfc23418	_daddu a0,s0,zero
ffffffffbfc2341c	beq v0,zero,0xffffffffbfc2342c
ffffffffbfc23420	_nop
ffffffffbfc23424	sb zero,0x0(v0)
ffffffffbfc23428	addiu v0,v0,0x1
ffffffffbfc2342c	sw v0,0x0(s1)
ffffffffbfc23430	ld ra,0x18(sp)
ffffffffbfc23434	daddu v0,s0,zero
ffffffffbfc23438	ld gp,0x10(sp)
ffffffffbfc2343c	ld s1,0x8(sp)
ffffffffbfc23440	ld s0,0x0(sp)
ffffffffbfc23444	jr ra
ffffffffbfc23448	_addiu sp,sp,0x20
