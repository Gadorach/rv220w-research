# RV220W U-Boot v1.1.0 entry=ffffffffbfc305e0 function=FUN_ffffffffbfc305e0
ffffffffbfc305e0	lui v1,0xfff0
ffffffffbfc305e4	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc305e8	ori v1,v1,0x23
ffffffffbfc305ec	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc305f0	dsll v1,v1,0x10
ffffffffbfc305f4	ori v1,v1,0x1
ffffffffbfc305f8	dsll v1,v1,0x1b
ffffffffbfc305fc	ori v1,v1,0x10
ffffffffbfc30600	daddu v0,v0,v1
ffffffffbfc30604	jr ra
ffffffffbfc30608	_daddu v0,a1,v0
