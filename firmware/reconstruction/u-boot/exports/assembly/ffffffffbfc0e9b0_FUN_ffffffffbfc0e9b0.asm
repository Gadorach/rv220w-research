# RV220W U-Boot v1.1.0 entry=ffffffffbfc0e9b0 function=FUN_ffffffffbfc0e9b0
ffffffffbfc0e9b0	lui a1,0x3
ffffffffbfc0e9b4	addu a1,a1,t9
ffffffffbfc0e9b8	addiu a1,a1,0x4d30
ffffffffbfc0e9bc	lw v1,0x14(a1)
ffffffffbfc0e9c0	lw a0,0x4a78(v1)
ffffffffbfc0e9c4	beq a0,zero,0xffffffffbfc0e9d8
ffffffffbfc0e9c8	_li v0,-0x1
ffffffffbfc0e9cc	lw t9,0x28(a0)
ffffffffbfc0e9d0	jr t9
ffffffffbfc0e9d4	_nop
ffffffffbfc0e9d8	jr ra
ffffffffbfc0e9dc	_nop
