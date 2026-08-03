# RV220W U-Boot v1.1.0 entry=ffffffffbfc226d8 function=FUN_ffffffffbfc226d8
ffffffffbfc226d8	lui v0,0x2
ffffffffbfc226dc	lui a0,0xff80
ffffffffbfc226e0	addu v0,v0,t9
ffffffffbfc226e4	ori a0,a0,0x107
ffffffffbfc226e8	addiu v0,v0,0x1008
ffffffffbfc226ec	dsll32 a0,a0,0x8
ffffffffbfc226f0	lw t9,0x20(v0)
ffffffffbfc226f4	li a1,0x1
ffffffffbfc226f8	addiu t9,t9,0x26a0
ffffffffbfc226fc	jr t9
ffffffffbfc22700	_ori a0,a0,0x740
