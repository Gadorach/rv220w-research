# RV220W U-Boot v1.1.0 entry=ffffffffbfc1f978 function=FUN_ffffffffbfc1f978
ffffffffbfc1f978	addiu sp,sp,-0x10
ffffffffbfc1f97c	sd gp,0x0(sp)
ffffffffbfc1f980	lui gp,0x2
ffffffffbfc1f984	sd ra,0x8(sp)
ffffffffbfc1f988	addu gp,gp,t9
ffffffffbfc1f98c	addiu gp,gp,0x3d68
ffffffffbfc1f990	lw v0,0x14(gp)
ffffffffbfc1f994	lw v0,0x4f34(v0)
ffffffffbfc1f998	bne v0,zero,0xffffffffbfc1f9e4
ffffffffbfc1f99c	_clear v0
ffffffffbfc1f9a0	lw v0,0xc(k0)
ffffffffbfc1f9a4	beq v0,zero,0xffffffffbfc1f9e0
ffffffffbfc1f9a8	_lw t9,0x57c(gp)
ffffffffbfc1f9ac	jalr t9
ffffffffbfc1f9b0	_nop
ffffffffbfc1f9b4	beq v0,zero,0xffffffffbfc1f9e0
ffffffffbfc1f9b8	_lw t9,0x7b4(gp)
ffffffffbfc1f9bc	jalr t9
ffffffffbfc1f9c0	_nop
ffffffffbfc1f9c4	li v1,0x3
ffffffffbfc1f9c8	bne v0,v1,0xffffffffbfc1f9e0
ffffffffbfc1f9cc	_lw v0,0x14(gp)
ffffffffbfc1f9d0	li v1,0x1
ffffffffbfc1f9d4	sw v1,0x4f30(v0)
ffffffffbfc1f9d8	b 0xffffffffbfc1f9e4
ffffffffbfc1f9dc	_li v0,0x1
ffffffffbfc1f9e0	clear v0
ffffffffbfc1f9e4	ld ra,0x8(sp)
ffffffffbfc1f9e8	ld gp,0x0(sp)
ffffffffbfc1f9ec	jr ra
ffffffffbfc1f9f0	_addiu sp,sp,0x10
