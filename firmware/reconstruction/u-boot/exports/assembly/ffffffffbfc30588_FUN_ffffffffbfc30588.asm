# RV220W U-Boot v1.1.0 entry=ffffffffbfc30588 function=FUN_ffffffffbfc30588
ffffffffbfc30588	lui v1,0xfffc
ffffffffbfc3058c	SPECIAL2 at,a0,v0,0x3,0x32
ffffffffbfc30590	ori v1,v1,0x9
ffffffffbfc30594	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc30598	dsll v1,v1,0x11
ffffffffbfc3059c	daddiu v1,v1,-0x7ff5
ffffffffbfc305a0	dsll v1,v1,0x1c
ffffffffbfc305a4	ori v1,v1,0x20
ffffffffbfc305a8	daddu v0,v0,v1
ffffffffbfc305ac	jr ra
ffffffffbfc305b0	_daddu v0,a1,v0
