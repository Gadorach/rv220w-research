# RV220W U-Boot v1.1.0 entry=ffffffffbfc311b8 function=FUN_ffffffffbfc311b8
ffffffffbfc311b8	lui v1,0xfff0
ffffffffbfc311bc	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc311c0	ori v1,v1,0x23
ffffffffbfc311c4	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc311c8	dsll v1,v1,0x10
ffffffffbfc311cc	ori v1,v1,0x1
ffffffffbfc311d0	dsll v1,v1,0x1b
ffffffffbfc311d4	ori v1,v1,0x220
ffffffffbfc311d8	daddu v0,v0,v1
ffffffffbfc311dc	jr ra
ffffffffbfc311e0	_daddu v0,a1,v0
