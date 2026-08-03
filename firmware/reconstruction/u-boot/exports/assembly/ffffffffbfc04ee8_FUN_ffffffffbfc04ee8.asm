# RV220W U-Boot v1.1.0 entry=ffffffffbfc04ee8 function=FUN_ffffffffbfc04ee8
ffffffffbfc04ee8	addiu sp,sp,-0x20
ffffffffbfc04eec	sd gp,0x10(sp)
ffffffffbfc04ef0	lui gp,0x4
ffffffffbfc04ef4	sd s0,0x0(sp)
ffffffffbfc04ef8	addu gp,gp,t9
ffffffffbfc04efc	sd s1,0x8(sp)
ffffffffbfc04f00	addiu gp,gp,-0x1808
ffffffffbfc04f04	lui s0,0xfff0
ffffffffbfc04f08	daddu s1,a0,zero
ffffffffbfc04f0c	lw t9,0xc(gp)
ffffffffbfc04f10	ori s0,s0,0x23
ffffffffbfc04f14	dsll32 s0,s0,0xb
ffffffffbfc04f18	dext v0,s1,0x3,0x8
ffffffffbfc04f1c	sd ra,0x18(sp)
ffffffffbfc04f20	ori a0,s0,0x1500
ffffffffbfc04f24	addiu t9,t9,0x4eb8
ffffffffbfc04f28	jalr t9
ffffffffbfc04f2c	_ori a1,v0,0x1000
ffffffffbfc04f30	ori s0,s0,0x1500
ffffffffbfc04f34	ld v0,0x0(s0)
ffffffffbfc04f38	beq v0,zero,0xffffffffbfc04f48
ffffffffbfc04f3c	_nop
ffffffffbfc04f40	swc2 hint12,-0x4(v0)
ffffffffbfc04f44	nop
ffffffffbfc04f48	dext v0,v0,0x10,0x8
ffffffffbfc04f4c	andi v1,s1,0x3
ffffffffbfc04f50	ld ra,0x18(sp)
ffffffffbfc04f54	andi v0,v0,0xff
ffffffffbfc04f58	ld gp,0x10(sp)
ffffffffbfc04f5c	srav v0,v0,v1
ffffffffbfc04f60	ld s1,0x8(sp)
ffffffffbfc04f64	andi v0,v0,0x1
ffffffffbfc04f68	ld s0,0x0(sp)
ffffffffbfc04f6c	jr ra
ffffffffbfc04f70	_addiu sp,sp,0x20
