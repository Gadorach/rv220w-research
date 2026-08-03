# RV220W U-Boot v1.1.0 entry=ffffffffbfc329d0 function=FUN_ffffffffbfc329d0
ffffffffbfc329d0	lui v1,0xfff0
ffffffffbfc329d4	SPECIAL2 at,a0,v0,0xb,0x32
ffffffffbfc329d8	ori v1,v1,0x23
ffffffffbfc329dc	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc329e0	dsll v1,v1,0x10
ffffffffbfc329e4	ori v1,v1,0x1
ffffffffbfc329e8	dsll v1,v1,0x1b
ffffffffbfc329ec	ori v1,v1,0x10
ffffffffbfc329f0	daddu v0,v0,v1
ffffffffbfc329f4	jr ra
ffffffffbfc329f8	_daddu v0,a1,v0
