# RV220W U-Boot v1.1.0 entry=ffffffffbfc5224c function=FUN_ffffffffbfc5224c
ffffffffbfc5224c	addiu sp,sp,-0x10
ffffffffbfc52250	sd gp,0x0(sp)
ffffffffbfc52254	lui gp,0x0
ffffffffbfc52258	sd ra,0x8(sp)
ffffffffbfc5225c	addu gp,gp,t9
ffffffffbfc52260	addiu gp,gp,0x39d4
ffffffffbfc52264	lw a1,0x8(gp)
ffffffffbfc52268	lw t9,0x100(gp)
ffffffffbfc5226c	jalr t9
ffffffffbfc52270	_addiu a1,a1,0x4c00
ffffffffbfc52274	beq v0,zero,0xffffffffbfc522c4
ffffffffbfc52278	_nop
ffffffffbfc5227c	addiu a0,v0,0xa
ffffffffbfc52280	li a2,0xd
ffffffffbfc52284	lw v0,0x8(gp)
ffffffffbfc52288	li a1,0xa
ffffffffbfc5228c	b 0xffffffffbfc5229c
ffffffffbfc52290	_lw v1,0x6e64(v0)
ffffffffbfc52294	addiu a0,a0,0x1
ffffffffbfc52298	addiu v1,v1,0x1
ffffffffbfc5229c	lb v0,0x0(a0)
ffffffffbfc522a0	bne v0,a2,0xffffffffbfc52294
ffffffffbfc522a4	_nop
ffffffffbfc522a8	lb v0,0x1(a0)
ffffffffbfc522ac	bne v0,a1,0xffffffffbfc52298
ffffffffbfc522b0	_addiu a0,a0,0x1
ffffffffbfc522b4	addiu a0,a0,-0x1
ffffffffbfc522b8	lw v0,0x8(gp)
ffffffffbfc522bc	addiu v1,v1,0x2
ffffffffbfc522c0	sw v1,0x6e64(v0)
ffffffffbfc522c4	lw v0,0x8(gp)
ffffffffbfc522c8	ld ra,0x8(sp)
ffffffffbfc522cc	lw v0,0x6e64(v0)
ffffffffbfc522d0	ld gp,0x0(sp)
ffffffffbfc522d4	jr ra
ffffffffbfc522d8	_addiu sp,sp,0x10
