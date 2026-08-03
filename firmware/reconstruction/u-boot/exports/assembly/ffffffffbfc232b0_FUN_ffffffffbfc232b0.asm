# RV220W U-Boot v1.1.0 entry=ffffffffbfc232b0 function=FUN_ffffffffbfc232b0
ffffffffbfc232b0	b 0xffffffffbfc232dc
ffffffffbfc232b4	_clear v0
ffffffffbfc232b8	beq a3,a2,0xffffffffbfc232d4
ffffffffbfc232bc	_nop
ffffffffbfc232c0	lb a2,0x0(v1)
ffffffffbfc232c4	bne a2,zero,0xffffffffbfc232b8
ffffffffbfc232c8	_addiu v1,v1,0x1
ffffffffbfc232cc	jr ra
ffffffffbfc232d0	_nop
ffffffffbfc232d4	addiu v0,v0,0x1
ffffffffbfc232d8	addiu a0,a0,0x1
ffffffffbfc232dc	lb a3,0x0(a0)
ffffffffbfc232e0	bne a3,zero,0xffffffffbfc232c0
ffffffffbfc232e4	_daddu v1,a1,zero
ffffffffbfc232e8	jr ra
ffffffffbfc232ec	_nop
