# RV220W U-Boot v1.1.0 entry=ffffffffbfc32ca8 function=FUN_ffffffffbfc32ca8
ffffffffbfc32ca8	lui v0,0xfff0
ffffffffbfc32cac	ori v0,v0,0x23
ffffffffbfc32cb0	dsll32 v0,v0,0xb
ffffffffbfc32cb4	ori v1,v0,0x1000
ffffffffbfc32cb8	ld v0,0x0(v1)
ffffffffbfc32cbc	bltz v0,0xffffffffbfc32cb8
ffffffffbfc32cc0	_nop
ffffffffbfc32cc4	sdc2 t8,0x2(v0)
ffffffffbfc32cc8	nop
ffffffffbfc32ccc	dins v0,zero,0x0,0x20
ffffffffbfc32cd0	jr ra
ffffffffbfc32cd4	_nop
