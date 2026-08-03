# RV220W U-Boot v1.1.0 entry=ffffffffbfc31268 function=FUN_ffffffffbfc31268
ffffffffbfc31268	lui v1,0xfffc
ffffffffbfc3126c	SPECIAL2 at,a0,v0,0xa,0x32
ffffffffbfc31270	ori v1,v1,0x9
ffffffffbfc31274	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc31278	dsll v1,v1,0x11
ffffffffbfc3127c	daddiu v1,v1,-0x7ff5
ffffffffbfc31280	dsll v1,v1,0x1c
ffffffffbfc31284	ori v1,v1,0x1000
ffffffffbfc31288	daddu v0,v0,v1
ffffffffbfc3128c	jr ra
ffffffffbfc31290	_daddu v0,a1,v0
