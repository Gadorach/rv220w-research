# RV220W U-Boot v1.1.0 entry=ffffffffbfc0358c function=FUN_ffffffffbfc0358c
ffffffffbfc0358c	lui v0,0x4
ffffffffbfc03590	li a1,0x1
ffffffffbfc03594	addu v0,v0,t9
ffffffffbfc03598	sllv a1,a1,a0
ffffffffbfc0359c	addiu v0,v0,0x154
ffffffffbfc035a0	lui a0,0xff80
ffffffffbfc035a4	lw t9,0xc(v0)
ffffffffbfc035a8	ori a0,a0,0x107
ffffffffbfc035ac	dsll32 a0,a0,0x8
ffffffffbfc035b0	addiu t9,t9,0x30b8
ffffffffbfc035b4	jr t9
ffffffffbfc035b8	_ori a0,a0,0x888
