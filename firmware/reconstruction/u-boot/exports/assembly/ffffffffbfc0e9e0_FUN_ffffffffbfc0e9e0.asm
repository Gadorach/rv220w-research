# RV220W U-Boot v1.1.0 entry=ffffffffbfc0e9e0 function=FUN_ffffffffbfc0e9e0
ffffffffbfc0e9e0	lui a0,0x3
ffffffffbfc0e9e4	addu a0,a0,t9
ffffffffbfc0e9e8	addiu a0,a0,0x4d00
ffffffffbfc0e9ec	lw v0,0x14(a0)
ffffffffbfc0e9f0	lw v1,0x4a78(v0)
ffffffffbfc0e9f4	lw v0,0x14(a0)
ffffffffbfc0e9f8	beq v1,zero,0xffffffffbfc0ea04
ffffffffbfc0e9fc	_addiu v0,v0,-0x59e0
ffffffffbfc0ea00	daddu v0,v1,zero
ffffffffbfc0ea04	jr ra
ffffffffbfc0ea08	_nop
