# RV220W U-Boot v1.1.0 entry=ffffffffbfc29ad0 function=FUN_ffffffffbfc29ad0
ffffffffbfc29ad0	lui v1,0xfff0
ffffffffbfc29ad4	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc29ad8	ori v1,v1,0x23
ffffffffbfc29adc	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc29ae0	dsll v1,v1,0x10
ffffffffbfc29ae4	ori v1,v1,0x1
ffffffffbfc29ae8	dsll v1,v1,0x1b
ffffffffbfc29aec	ori v1,v1,0x100
ffffffffbfc29af0	daddu v0,v0,v1
ffffffffbfc29af4	jr ra
ffffffffbfc29af8	_daddu v0,a1,v0
