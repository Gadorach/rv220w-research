# RV220W U-Boot v1.1.0 entry=ffffffffbfc21ed4 function=FUN_ffffffffbfc21ed4
ffffffffbfc21ed4	addiu sp,sp,-0x30
ffffffffbfc21ed8	sd gp,0x18(sp)
ffffffffbfc21edc	lui gp,0x2
ffffffffbfc21ee0	sd ra,0x20(sp)
ffffffffbfc21ee4	addu gp,gp,t9
ffffffffbfc21ee8	sd s2,0x10(sp)
ffffffffbfc21eec	addiu gp,gp,0x180c
ffffffffbfc21ef0	lw t9,0x73c(gp)
ffffffffbfc21ef4	daddu s2,a0,zero
ffffffffbfc21ef8	sd s1,0x8(sp)
ffffffffbfc21efc	jalr t9
ffffffffbfc21f00	_sd s0,0x0(sp)
ffffffffbfc21f04	li a0,0x8
ffffffffbfc21f08	lw t9,0x73c(gp)
ffffffffbfc21f0c	jalr t9
ffffffffbfc21f10	_daddu s1,v0,zero
ffffffffbfc21f14	daddu a0,s1,zero
ffffffffbfc21f18	lw t9,0x54(gp)
ffffffffbfc21f1c	beq v0,zero,0xffffffffbfc21f44
ffffffffbfc21f20	_daddu s0,v0,zero
ffffffffbfc21f24	bne s1,zero,0xffffffffbfc21f34
ffffffffbfc21f28	_nop
ffffffffbfc21f2c	bne s2,zero,0xffffffffbfc21f44
ffffffffbfc21f30	_nop
ffffffffbfc21f34	sw s1,0x0(s0)
ffffffffbfc21f38	daddu v0,s0,zero
ffffffffbfc21f3c	b 0xffffffffbfc21f5c
ffffffffbfc21f40	_sw s2,0x4(s0)
ffffffffbfc21f44	jalr t9
ffffffffbfc21f48	_nop
ffffffffbfc21f4c	lw t9,0x54(gp)
ffffffffbfc21f50	jalr t9
ffffffffbfc21f54	_daddu a0,s0,zero
ffffffffbfc21f58	clear v0
ffffffffbfc21f5c	ld ra,0x20(sp)
ffffffffbfc21f60	ld gp,0x18(sp)
ffffffffbfc21f64	ld s2,0x10(sp)
ffffffffbfc21f68	ld s1,0x8(sp)
ffffffffbfc21f6c	ld s0,0x0(sp)
ffffffffbfc21f70	jr ra
ffffffffbfc21f74	_addiu sp,sp,0x30
