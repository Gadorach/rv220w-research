# RV220W U-Boot v1.1.0 entry=ffffffffbfc15194 function=do_itest
ffffffffbfc15194	addiu sp,sp,-0x20
ffffffffbfc15198	li v0,0x4
ffffffffbfc1519c	sd gp,0x10(sp)
ffffffffbfc151a0	lui gp,0x3
ffffffffbfc151a4	sd s1,0x8(sp)
ffffffffbfc151a8	addu gp,gp,t9
ffffffffbfc151ac	sd s0,0x0(sp)
ffffffffbfc151b0	addiu gp,gp,-0x1ab4
ffffffffbfc151b4	sd ra,0x18(sp)
ffffffffbfc151b8	daddu s1,a2,zero
ffffffffbfc151bc	beq a2,v0,0xffffffffbfc151e0
ffffffffbfc151c0	_daddu s0,a3,zero
ffffffffbfc151c4	lw a1,0x10(a0)
ffffffffbfc151c8	lw a0,0x14(gp)
ffffffffbfc151cc	lw t9,0x92c(gp)
ffffffffbfc151d0	jalr t9
ffffffffbfc151d4	_addiu a0,a0,-0x5320
ffffffffbfc151d8	b 0xffffffffbfc15260
ffffffffbfc151dc	_li v0,0x1
ffffffffbfc151e0	lw a0,0x0(a3)
ffffffffbfc151e4	lw t9,0x408(gp)
ffffffffbfc151e8	jalr t9
ffffffffbfc151ec	_li a1,0x4
ffffffffbfc151f0	daddu a3,v0,zero
ffffffffbfc151f4	slti v0,v0,0x3
ffffffffbfc151f8	beq v0,zero,0xffffffffbfc1521c
ffffffffbfc151fc	_nop
ffffffffbfc15200	bgtz a3,0xffffffffbfc15224
ffffffffbfc15204	_nop
ffffffffbfc15208	li v0,-0x2
ffffffffbfc1520c	bne a3,v0,0xffffffffbfc15248
ffffffffbfc15210	_nop
ffffffffbfc15214	b 0xffffffffbfc1522c
ffffffffbfc15218	_lw a2,0xc(s0)
ffffffffbfc1521c	bne a3,s1,0xffffffffbfc15248
ffffffffbfc15220	_nop
ffffffffbfc15224	b 0xffffffffbfc15230
ffffffffbfc15228	_lw a2,0xc(s0)
ffffffffbfc1522c	clear a3
ffffffffbfc15230	lw t9,0x5fc(gp)
ffffffffbfc15234	lw a0,0x8(s0)
ffffffffbfc15238	jalr t9
ffffffffbfc1523c	_lw a1,0x4(s0)
ffffffffbfc15240	b 0xffffffffbfc15260
ffffffffbfc15244	_sltiu v0,v0,0x1
ffffffffbfc15248	lw a0,0x14(gp)
ffffffffbfc1524c	lw t9,0x758(gp)
ffffffffbfc15250	jalr t9
ffffffffbfc15254	_addiu a0,a0,-0x4468
ffffffffbfc15258	clear v0
ffffffffbfc1525c	sltiu v0,v0,0x1
ffffffffbfc15260	ld ra,0x18(sp)
ffffffffbfc15264	ld gp,0x10(sp)
ffffffffbfc15268	ld s1,0x8(sp)
ffffffffbfc1526c	ld s0,0x0(sp)
ffffffffbfc15270	jr ra
ffffffffbfc15274	_addiu sp,sp,0x20
