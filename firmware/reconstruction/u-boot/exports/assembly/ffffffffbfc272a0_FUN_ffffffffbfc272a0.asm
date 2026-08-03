# RV220W U-Boot v1.1.0 entry=ffffffffbfc272a0 function=FUN_ffffffffbfc272a0
ffffffffbfc272a0	lui v0,0xff80
ffffffffbfc272a4	lui v1,0x2
ffffffffbfc272a8	ori v0,v0,0x107
ffffffffbfc272ac	addu v1,v1,t9
ffffffffbfc272b0	dsll32 v0,v0,0x8
ffffffffbfc272b4	SPECIAL2 v1,a0,a0,0x3,0x32
ffffffffbfc272b8	ori v0,v0,0x800
ffffffffbfc272bc	addiu v1,v1,-0x3bc0
ffffffffbfc272c0	daddu a0,a0,v0
ffffffffbfc272c4	ld a1,0x0(a0)
ffffffffbfc272c8	lw t9,0x20(v1)
ffffffffbfc272cc	addiu t9,t9,0x7210
ffffffffbfc272d0	jr t9
ffffffffbfc272d4	_ori a1,a1,0x1
