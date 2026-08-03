# RV220W U-Boot v1.1.0 entry=ffffffffbfc346b4 function=FUN_ffffffffbfc346b4
ffffffffbfc346b4	lui v1,0xfffc
ffffffffbfc346b8	SPECIAL2 at,a0,v0,0x3,0x32
ffffffffbfc346bc	ori v1,v1,0x9
ffffffffbfc346c0	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc346c4	dsll v1,v1,0x11
ffffffffbfc346c8	daddiu v1,v1,-0x7ff5
ffffffffbfc346cc	dsll v1,v1,0x1c
ffffffffbfc346d0	ori v1,v1,0x48
ffffffffbfc346d4	daddu v0,v0,v1
ffffffffbfc346d8	jr ra
ffffffffbfc346dc	_daddu v0,a1,v0
