# RV220W U-Boot v1.1.0 entry=ffffffffbfc29a78 function=FUN_ffffffffbfc29a78
ffffffffbfc29a78	lui v1,0xfff0
ffffffffbfc29a7c	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc29a80	ori v1,v1,0x23
ffffffffbfc29a84	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc29a88	dsll v1,v1,0x10
ffffffffbfc29a8c	ori v1,v1,0x1
ffffffffbfc29a90	dsll v1,v1,0x1b
ffffffffbfc29a94	ori v1,v1,0x10
ffffffffbfc29a98	daddu v0,v0,v1
ffffffffbfc29a9c	jr ra
ffffffffbfc29aa0	_daddu v0,a1,v0
