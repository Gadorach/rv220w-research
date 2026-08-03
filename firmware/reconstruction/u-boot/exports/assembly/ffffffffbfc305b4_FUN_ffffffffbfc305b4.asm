# RV220W U-Boot v1.1.0 entry=ffffffffbfc305b4 function=FUN_ffffffffbfc305b4
ffffffffbfc305b4	lui v1,0xfffc
ffffffffbfc305b8	SPECIAL2 at,a0,v0,0x3,0x32
ffffffffbfc305bc	ori v1,v1,0x9
ffffffffbfc305c0	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc305c4	dsll v1,v1,0x11
ffffffffbfc305c8	daddiu v1,v1,-0x7ff5
ffffffffbfc305cc	dsll v1,v1,0x1c
ffffffffbfc305d0	ori v1,v1,0x48
ffffffffbfc305d4	daddu v0,v0,v1
ffffffffbfc305d8	jr ra
ffffffffbfc305dc	_daddu v0,a1,v0
