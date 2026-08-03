# RV220W U-Boot v1.1.0 entry=ffffffffbfc229dc function=FUN_ffffffffbfc229dc
ffffffffbfc229dc	lui v1,0x2
ffffffffbfc229e0	daddu v0,a0,zero
ffffffffbfc229e4	addu v1,v1,t9
ffffffffbfc229e8	daddu a2,a1,zero
ffffffffbfc229ec	addiu v1,v1,0xd04
ffffffffbfc229f0	daddu a1,v0,zero
ffffffffbfc229f4	lw t9,0x700(v1)
ffffffffbfc229f8	jr t9
ffffffffbfc229fc	_lw a0,0x8e4(v1)
