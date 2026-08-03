# RV220W U-Boot v1.1.0 entry=ffffffffbfc3118c function=FUN_ffffffffbfc3118c
ffffffffbfc3118c	lui v1,0xfff0
ffffffffbfc31190	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc31194	ori v1,v1,0x23
ffffffffbfc31198	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc3119c	dsll v1,v1,0x10
ffffffffbfc311a0	ori v1,v1,0x1
ffffffffbfc311a4	dsll v1,v1,0x1b
ffffffffbfc311a8	ori v1,v1,0x228
ffffffffbfc311ac	daddu v0,v0,v1
ffffffffbfc311b0	jr ra
ffffffffbfc311b4	_daddu v0,a1,v0
