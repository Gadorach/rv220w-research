# RV220W U-Boot v1.1.0 entry=ffffffffbfc231c0 function=FUN_ffffffffbfc231c0
ffffffffbfc231c0	daddu v0,a0,zero
ffffffffbfc231c4	b 0xffffffffbfc231e0
ffffffffbfc231c8	_seb a1,a1
ffffffffbfc231cc	bne v1,zero,0xffffffffbfc231e0
ffffffffbfc231d0	_addiu v0,v0,0x1
ffffffffbfc231d4	addiu v0,v0,-0x1
ffffffffbfc231d8	jr ra
ffffffffbfc231dc	_clear v0
ffffffffbfc231e0	lb v1,0x0(v0)
ffffffffbfc231e4	bne v1,a1,0xffffffffbfc231cc
ffffffffbfc231e8	_nop
ffffffffbfc231ec	jr ra
ffffffffbfc231f0	_nop
