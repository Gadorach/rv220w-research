# RV220W U-Boot v1.1.0 entry=ffffffffbfc042d8 function=FUN_ffffffffbfc042d8
ffffffffbfc042d8	lui v0,0xff80
ffffffffbfc042dc	lui v1,0x4
ffffffffbfc042e0	ori v0,v0,0x107
ffffffffbfc042e4	addu v1,v1,t9
ffffffffbfc042e8	dsll32 v0,v0,0x8
ffffffffbfc042ec	SPECIAL2 v1,a0,a0,0x3,0x32
ffffffffbfc042f0	ori v0,v0,0x800
ffffffffbfc042f4	addiu v1,v1,-0xbf8
ffffffffbfc042f8	daddu a0,a0,v0
ffffffffbfc042fc	ld a1,0x0(a0)
ffffffffbfc04300	lw t9,0xc(v1)
ffffffffbfc04304	addiu t9,t9,0x30b8
ffffffffbfc04308	jr t9
ffffffffbfc0430c	_ori a1,a1,0x1
