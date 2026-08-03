# RV220W U-Boot v1.1.0 entry=ffffffffbfc30638 function=FUN_ffffffffbfc30638
ffffffffbfc30638	lui v1,0xfff0
ffffffffbfc3063c	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc30640	ori v1,v1,0x23
ffffffffbfc30644	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc30648	dsll v1,v1,0x10
ffffffffbfc3064c	ori v1,v1,0x1
ffffffffbfc30650	dsll v1,v1,0x1b
ffffffffbfc30654	ori v1,v1,0x228
ffffffffbfc30658	daddu v0,v0,v1
ffffffffbfc3065c	jr ra
ffffffffbfc30660	_daddu v0,a1,v0
