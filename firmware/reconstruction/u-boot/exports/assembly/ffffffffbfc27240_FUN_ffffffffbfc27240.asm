# RV220W U-Boot v1.1.0 entry=ffffffffbfc27240 function=FUN_ffffffffbfc27240
ffffffffbfc27240	lui v0,0x2
ffffffffbfc27244	li a1,0x1
ffffffffbfc27248	addu v0,v0,t9
ffffffffbfc2724c	sllv a1,a1,a0
ffffffffbfc27250	addiu v0,v0,-0x3b60
ffffffffbfc27254	lui a0,0xff80
ffffffffbfc27258	lw t9,0x20(v0)
ffffffffbfc2725c	ori a0,a0,0x107
ffffffffbfc27260	dsll32 a0,a0,0x8
ffffffffbfc27264	addiu t9,t9,0x7210
ffffffffbfc27268	jr t9
ffffffffbfc2726c	_ori a0,a0,0x890
