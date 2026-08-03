# RV220W U-Boot v1.1.0 entry=ffffffffbfc3060c function=FUN_ffffffffbfc3060c
ffffffffbfc3060c	lui v1,0xfff0
ffffffffbfc30610	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc30614	ori v1,v1,0x23
ffffffffbfc30618	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc3061c	dsll v1,v1,0x10
ffffffffbfc30620	ori v1,v1,0x1
ffffffffbfc30624	dsll v1,v1,0x1b
ffffffffbfc30628	ori v1,v1,0x18
ffffffffbfc3062c	daddu v0,v0,v1
ffffffffbfc30630	jr ra
ffffffffbfc30634	_daddu v0,a1,v0
