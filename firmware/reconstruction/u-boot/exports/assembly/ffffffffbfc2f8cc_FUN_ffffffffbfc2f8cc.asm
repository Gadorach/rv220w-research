# RV220W U-Boot v1.1.0 entry=ffffffffbfc2f8cc function=FUN_ffffffffbfc2f8cc
ffffffffbfc2f8cc	lui v1,0x1
ffffffffbfc2f8d0	addu v1,v1,t9
ffffffffbfc2f8d4	addiu v1,v1,0x3e14
ffffffffbfc2f8d8	rdhwr v0,HW_RESIM30
ffffffffbfc2f8dc	bne v0,zero,0xffffffffbfc2f8f4
ffffffffbfc2f8e0	_daddu a1,a0,zero
ffffffffbfc2f8e4	lw a0,0x14(v1)
ffffffffbfc2f8e8	lw t9,0x504(v1)
ffffffffbfc2f8ec	jr t9
ffffffffbfc2f8f0	_addiu a0,a0,0x1930
ffffffffbfc2f8f4	jr ra
ffffffffbfc2f8f8	_nop
