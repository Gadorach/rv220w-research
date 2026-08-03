# RV220W U-Boot v1.1.0 entry=ffffffffbfc2f7ec function=FUN_ffffffffbfc2f7ec
ffffffffbfc2f7ec	lui v1,0xfff0
ffffffffbfc2f7f0	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc2f7f4	ori v1,v1,0x23
ffffffffbfc2f7f8	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc2f7fc	dsll v1,v1,0x10
ffffffffbfc2f800	ori v1,v1,0x1
ffffffffbfc2f804	dsll v1,v1,0x1b
ffffffffbfc2f808	ori v1,v1,0x10
ffffffffbfc2f80c	daddu v0,v0,v1
ffffffffbfc2f810	jr ra
ffffffffbfc2f814	_daddu v0,a1,v0
