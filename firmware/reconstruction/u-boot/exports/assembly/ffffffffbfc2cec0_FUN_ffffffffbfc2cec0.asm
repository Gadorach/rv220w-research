# RV220W U-Boot v1.1.0 entry=ffffffffbfc2cec0 function=FUN_ffffffffbfc2cec0
ffffffffbfc2cec0	sd a1,0x0(a0)
ffffffffbfc2cec4	lui v0,0x80
ffffffffbfc2cec8	dsrl32 a0,a0,0x8
ffffffffbfc2cecc	ori v0,v0,0x118
ffffffffbfc2ced0	bne a0,v0,0xffffffffbfc2cee8
ffffffffbfc2ced4	_lui v0,0xfff0
ffffffffbfc2ced8	ori v0,v0,0x23
ffffffffbfc2cedc	dsll32 v0,v0,0xb
ffffffffbfc2cee0	ori v0,v0,0xf8
ffffffffbfc2cee4	ld v0,0x0(v0)
ffffffffbfc2cee8	jr ra
ffffffffbfc2ceec	_nop
