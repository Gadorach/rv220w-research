# RV220W U-Boot v1.1.0 entry=ffffffffbfc035bc function=octeon_gpio_set_mask
ffffffffbfc035bc	lui v0,0x4
ffffffffbfc035c0	li a1,0x1
ffffffffbfc035c4	addu v0,v0,t9
ffffffffbfc035c8	sllv a1,a1,a0
ffffffffbfc035cc	addiu v0,v0,0x124
ffffffffbfc035d0	lui a0,0xff80
ffffffffbfc035d4	lw t9,0xc(v0)
ffffffffbfc035d8	ori a0,a0,0x107
ffffffffbfc035dc	dsll32 a0,a0,0x8
ffffffffbfc035e0	addiu t9,t9,0x30b8
ffffffffbfc035e4	jr t9
ffffffffbfc035e8	_ori a0,a0,0x890
