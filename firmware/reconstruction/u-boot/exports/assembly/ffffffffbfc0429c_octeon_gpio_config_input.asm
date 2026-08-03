# RV220W U-Boot v1.1.0 entry=ffffffffbfc0429c function=octeon_gpio_config_input
ffffffffbfc0429c	lui v0,0xff80
ffffffffbfc042a0	lui v1,0x4
ffffffffbfc042a4	ori v0,v0,0x107
ffffffffbfc042a8	addu v1,v1,t9
ffffffffbfc042ac	dsll32 v0,v0,0x8
ffffffffbfc042b0	SPECIAL2 v1,a0,a0,0x3,0x32
ffffffffbfc042b4	ori v0,v0,0x800
ffffffffbfc042b8	addiu v1,v1,-0xbbc
ffffffffbfc042bc	daddu a0,a0,v0
ffffffffbfc042c0	ld v0,0x0(a0)
ffffffffbfc042c4	lw t9,0xc(v1)
ffffffffbfc042c8	li a1,-0x2
ffffffffbfc042cc	addiu t9,t9,0x30b8
ffffffffbfc042d0	jr t9
ffffffffbfc042d4	_and a1,v0,a1
