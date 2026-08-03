# RV220W U-Boot v1.1.0 entry=ffffffffbfc2a7b4 function=FUN_ffffffffbfc2a7b4
ffffffffbfc2a7b4	lui v1,0x2
ffffffffbfc2a7b8	addu v1,v1,t9
ffffffffbfc2a7bc	addiu v1,v1,-0x70d4
ffffffffbfc2a7c0	rdhwr v0,HW_RESIM30
ffffffffbfc2a7c4	bne v0,zero,0xffffffffbfc2a7dc
ffffffffbfc2a7c8	_daddu a1,a0,zero
ffffffffbfc2a7cc	lw a0,0x14(v1)
ffffffffbfc2a7d0	lw t9,0x504(v1)
ffffffffbfc2a7d4	jr t9
ffffffffbfc2a7d8	_addiu a0,a0,0x1930
ffffffffbfc2a7dc	jr ra
ffffffffbfc2a7e0	_nop
