# RV220W U-Boot v1.1.0 entry=ffffffffbfc2f818 function=FUN_ffffffffbfc2f818
ffffffffbfc2f818	lui v1,0xfff0
ffffffffbfc2f81c	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc2f820	ori v1,v1,0x23
ffffffffbfc2f824	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc2f828	dsll v1,v1,0x10
ffffffffbfc2f82c	ori v1,v1,0x1
ffffffffbfc2f830	dsll v1,v1,0x1b
ffffffffbfc2f834	ori v1,v1,0x38
ffffffffbfc2f838	daddu v0,v0,v1
ffffffffbfc2f83c	jr ra
ffffffffbfc2f840	_daddu v0,a1,v0
