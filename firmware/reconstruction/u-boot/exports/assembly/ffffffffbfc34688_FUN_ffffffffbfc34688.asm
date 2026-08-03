# RV220W U-Boot v1.1.0 entry=ffffffffbfc34688 function=FUN_ffffffffbfc34688
ffffffffbfc34688	lui v1,0xfffc
ffffffffbfc3468c	SPECIAL2 at,a0,v0,0x3,0x32
ffffffffbfc34690	ori v1,v1,0x9
ffffffffbfc34694	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc34698	dsll v1,v1,0x11
ffffffffbfc3469c	daddiu v1,v1,-0x7ff5
ffffffffbfc346a0	dsll v1,v1,0x1c
ffffffffbfc346a4	ori v1,v1,0x20
ffffffffbfc346a8	daddu v0,v0,v1
ffffffffbfc346ac	jr ra
ffffffffbfc346b0	_daddu v0,a1,v0
