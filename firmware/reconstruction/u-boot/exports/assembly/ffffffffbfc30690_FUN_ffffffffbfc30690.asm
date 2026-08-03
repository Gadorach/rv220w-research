# RV220W U-Boot v1.1.0 entry=ffffffffbfc30690 function=FUN_ffffffffbfc30690
ffffffffbfc30690	lui v1,0xfff0
ffffffffbfc30694	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc30698	ori v1,v1,0x23
ffffffffbfc3069c	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc306a0	dsll v1,v1,0x10
ffffffffbfc306a4	ori v1,v1,0x1
ffffffffbfc306a8	dsll v1,v1,0x1b
ffffffffbfc306ac	ori v1,v1,0x220
ffffffffbfc306b0	daddu v0,v0,v1
ffffffffbfc306b4	jr ra
ffffffffbfc306b8	_daddu v0,a1,v0
