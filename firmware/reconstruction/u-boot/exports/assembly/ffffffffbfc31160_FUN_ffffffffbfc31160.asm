# RV220W U-Boot v1.1.0 entry=ffffffffbfc31160 function=FUN_ffffffffbfc31160
ffffffffbfc31160	lui v1,0xfff0
ffffffffbfc31164	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc31168	ori v1,v1,0x23
ffffffffbfc3116c	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc31170	dsll v1,v1,0x10
ffffffffbfc31174	ori v1,v1,0x1
ffffffffbfc31178	dsll v1,v1,0x1b
ffffffffbfc3117c	ori v1,v1,0x10
ffffffffbfc31180	daddu v0,v0,v1
ffffffffbfc31184	jr ra
ffffffffbfc31188	_daddu v0,a1,v0
