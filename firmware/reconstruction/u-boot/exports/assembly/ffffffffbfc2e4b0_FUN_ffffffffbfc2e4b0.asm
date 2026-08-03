# RV220W U-Boot v1.1.0 entry=ffffffffbfc2e4b0 function=FUN_ffffffffbfc2e4b0
ffffffffbfc2e4b0	addiu sp,sp,-0x10
ffffffffbfc2e4b4	sd gp,0x0(sp)
ffffffffbfc2e4b8	lui gp,0x1
ffffffffbfc2e4bc	sd ra,0x8(sp)
ffffffffbfc2e4c0	addu gp,gp,t9
ffffffffbfc2e4c4	addiu gp,gp,0x5230
ffffffffbfc2e4c8	lw t9,0x10(gp)
ffffffffbfc2e4cc	addiu t9,t9,-0x1d60
ffffffffbfc2e4d0	jalr t9
ffffffffbfc2e4d4	_nop
ffffffffbfc2e4d8	beq v0,zero,0xffffffffbfc2e508
ffffffffbfc2e4dc	_ld ra,0x8(sp)
ffffffffbfc2e4e0	ld v0,0x8(v0)
ffffffffbfc2e4e4	dextu v0,v0,0x20,0x1d
ffffffffbfc2e4e8	beq v0,zero,0xffffffffbfc2e508
ffffffffbfc2e4ec	_lw t9,0x10(gp)
ffffffffbfc2e4f0	dsll a0,v0,0x7
ffffffffbfc2e4f4	ld gp,0x0(sp)
ffffffffbfc2e4f8	ld ra,0x8(sp)
ffffffffbfc2e4fc	addiu t9,t9,-0x1ba4
ffffffffbfc2e500	jr t9
ffffffffbfc2e504	_addiu sp,sp,0x10
ffffffffbfc2e508	clear v0
ffffffffbfc2e50c	ld gp,0x0(sp)
ffffffffbfc2e510	jr ra
ffffffffbfc2e514	_addiu sp,sp,0x10
