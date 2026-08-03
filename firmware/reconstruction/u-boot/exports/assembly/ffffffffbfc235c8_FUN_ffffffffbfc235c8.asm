# RV220W U-Boot v1.1.0 entry=ffffffffbfc235c8 function=FUN_ffffffffbfc235c8
ffffffffbfc235ac	lbu v1,0x0(a0)
ffffffffbfc235b0	addiu a2,a2,-0x1
ffffffffbfc235b4	lbu v0,0x0(a1)
ffffffffbfc235b8	addiu a0,a0,0x1
ffffffffbfc235bc	subu v0,v1,v0
ffffffffbfc235c0	bne v0,zero,0xffffffffbfc235d0
ffffffffbfc235c4	_addiu a1,a1,0x1
ffffffffbfc235c8	bne a2,zero,0xffffffffbfc235ac
ffffffffbfc235cc	_clear v0
ffffffffbfc235d0	jr ra
ffffffffbfc235d4	_nop
