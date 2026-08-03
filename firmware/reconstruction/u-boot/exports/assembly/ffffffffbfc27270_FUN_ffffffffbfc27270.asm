# RV220W U-Boot v1.1.0 entry=ffffffffbfc27270 function=FUN_ffffffffbfc27270
ffffffffbfc27270	lui v0,0x2
ffffffffbfc27274	li a1,0x1
ffffffffbfc27278	addu v0,v0,t9
ffffffffbfc2727c	sllv a1,a1,a0
ffffffffbfc27280	addiu v0,v0,-0x3b90
ffffffffbfc27284	lui a0,0xff80
ffffffffbfc27288	lw t9,0x20(v0)
ffffffffbfc2728c	ori a0,a0,0x107
ffffffffbfc27290	dsll32 a0,a0,0x8
ffffffffbfc27294	addiu t9,t9,0x7210
ffffffffbfc27298	jr t9
ffffffffbfc2729c	_ori a0,a0,0x888
