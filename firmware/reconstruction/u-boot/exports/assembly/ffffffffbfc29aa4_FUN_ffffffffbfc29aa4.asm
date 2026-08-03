# RV220W U-Boot v1.1.0 entry=ffffffffbfc29aa4 function=FUN_ffffffffbfc29aa4
ffffffffbfc29aa4	lui v1,0xfff0
ffffffffbfc29aa8	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc29aac	ori v1,v1,0x23
ffffffffbfc29ab0	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc29ab4	dsll v1,v1,0x10
ffffffffbfc29ab8	ori v1,v1,0x1
ffffffffbfc29abc	dsll v1,v1,0x1b
ffffffffbfc29ac0	ori v1,v1,0x108
ffffffffbfc29ac4	daddu v0,v0,v1
ffffffffbfc29ac8	jr ra
ffffffffbfc29acc	_daddu v0,a1,v0
