# RV220W U-Boot v1.1.0 entry=ffffffffbfc30664 function=FUN_ffffffffbfc30664
ffffffffbfc30664	lui v1,0xfff0
ffffffffbfc30668	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc3066c	ori v1,v1,0x23
ffffffffbfc30670	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc30674	dsll v1,v1,0x10
ffffffffbfc30678	ori v1,v1,0x1
ffffffffbfc3067c	dsll v1,v1,0x1b
ffffffffbfc30680	ori v1,v1,0x208
ffffffffbfc30684	daddu v0,v0,v1
ffffffffbfc30688	jr ra
ffffffffbfc3068c	_daddu v0,a1,v0
