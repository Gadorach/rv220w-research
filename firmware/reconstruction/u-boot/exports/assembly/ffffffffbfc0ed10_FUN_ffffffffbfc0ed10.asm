# RV220W U-Boot v1.1.0 entry=ffffffffbfc0ed10 function=FUN_ffffffffbfc0ed10
ffffffffbfc0ed10	lui v1,0x3
ffffffffbfc0ed14	daddu a1,a0,zero
ffffffffbfc0ed18	addu v1,v1,t9
ffffffffbfc0ed1c	addiu v1,v1,0x49d0
ffffffffbfc0ed20	lw v0,0x14(v1)
ffffffffbfc0ed24	lw a0,0x4a78(v0)
ffffffffbfc0ed28	beq a0,zero,0xffffffffbfc0ed3c
ffffffffbfc0ed2c	_li v0,-0x1
ffffffffbfc0ed30	lw t9,0x158(v1)
ffffffffbfc0ed34	jr t9
ffffffffbfc0ed38	_nop
ffffffffbfc0ed3c	jr ra
ffffffffbfc0ed40	_nop
