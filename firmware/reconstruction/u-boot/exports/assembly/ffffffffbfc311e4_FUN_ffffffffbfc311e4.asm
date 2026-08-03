# RV220W U-Boot v1.1.0 entry=ffffffffbfc311e4 function=FUN_ffffffffbfc311e4
ffffffffbfc311e4	lui v1,0xfffc
ffffffffbfc311e8	SPECIAL2 at,a0,v0,0xa,0x32
ffffffffbfc311ec	ori v1,v1,0x9
ffffffffbfc311f0	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc311f4	dsll v1,v1,0x11
ffffffffbfc311f8	daddiu v1,v1,-0x7ff5
ffffffffbfc311fc	dsll v1,v1,0x1c
ffffffffbfc31200	ori v1,v1,0x1010
ffffffffbfc31204	daddu v0,v0,v1
ffffffffbfc31208	jr ra
ffffffffbfc3120c	_daddu v0,a1,v0
