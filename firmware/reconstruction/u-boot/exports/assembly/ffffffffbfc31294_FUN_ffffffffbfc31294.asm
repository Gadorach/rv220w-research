# RV220W U-Boot v1.1.0 entry=ffffffffbfc31294 function=FUN_ffffffffbfc31294
ffffffffbfc31294	lui v1,0xfffc
ffffffffbfc31298	SPECIAL2 at,a0,v0,0xa,0x32
ffffffffbfc3129c	ori v1,v1,0x9
ffffffffbfc312a0	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc312a4	dsll v1,v1,0x11
ffffffffbfc312a8	daddiu v1,v1,-0x7ff5
ffffffffbfc312ac	dsll v1,v1,0x1c
ffffffffbfc312b0	ori v1,v1,0x1008
ffffffffbfc312b4	daddu v0,v0,v1
ffffffffbfc312b8	jr ra
ffffffffbfc312bc	_daddu v0,a1,v0
