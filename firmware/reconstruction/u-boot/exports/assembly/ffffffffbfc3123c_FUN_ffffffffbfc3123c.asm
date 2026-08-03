# RV220W U-Boot v1.1.0 entry=ffffffffbfc3123c function=FUN_ffffffffbfc3123c
ffffffffbfc3123c	lui v1,0xfffc
ffffffffbfc31240	SPECIAL2 at,a0,v0,0xa,0x32
ffffffffbfc31244	ori v1,v1,0x9
ffffffffbfc31248	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc3124c	dsll v1,v1,0x11
ffffffffbfc31250	daddiu v1,v1,-0x7ff5
ffffffffbfc31254	dsll v1,v1,0x1c
ffffffffbfc31258	ori v1,v1,0x1078
ffffffffbfc3125c	daddu v0,v0,v1
ffffffffbfc31260	jr ra
ffffffffbfc31264	_daddu v0,a1,v0
