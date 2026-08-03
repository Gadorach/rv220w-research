# RV220W U-Boot v1.1.0 entry=ffffffffbfc06290 function=FUN_ffffffffbfc06290
ffffffffbfc06290	lui v1,0xfff0
ffffffffbfc06294	andi a1,a1,0x1
ffffffffbfc06298	ori v1,v1,0x23
ffffffffbfc0629c	dsll v0,a1,0x1f
ffffffffbfc062a0	dsll v1,v1,0x10
ffffffffbfc062a4	dsll a1,a1,0x1d
ffffffffbfc062a8	ori v1,v1,0x11
ffffffffbfc062ac	SPECIAL2 at,a0,a0,0x3,0x32
ffffffffbfc062b0	dsll v1,v1,0x1b
ffffffffbfc062b4	dsubu v0,v0,a1
ffffffffbfc062b8	ori v1,v1,0x100
ffffffffbfc062bc	daddu a0,a0,v1
ffffffffbfc062c0	jr ra
ffffffffbfc062c4	_daddu v0,v0,a0
