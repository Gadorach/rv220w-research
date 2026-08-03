# RV220W U-Boot v1.1.0 entry=ffffffffbfc00b78 function=FUN_ffffffffbfc00b78
ffffffffbfc00b78	sd a1,0x0(a0)
ffffffffbfc00b7c	lui v0,0x80
ffffffffbfc00b80	dsrl32 a0,a0,0x8
ffffffffbfc00b84	ori v0,v0,0x118
ffffffffbfc00b88	bne a0,v0,0xffffffffbfc00ba0
ffffffffbfc00b8c	_lui v0,0xfff0
ffffffffbfc00b90	ori v0,v0,0x23
ffffffffbfc00b94	dsll32 v0,v0,0xb
ffffffffbfc00b98	ori v0,v0,0xf8
ffffffffbfc00b9c	ld v0,0x0(v0)
ffffffffbfc00ba0	jr ra
ffffffffbfc00ba4	_nop
