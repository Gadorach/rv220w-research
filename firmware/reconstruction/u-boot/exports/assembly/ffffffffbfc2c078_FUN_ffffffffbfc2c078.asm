# RV220W U-Boot v1.1.0 entry=ffffffffbfc2c078 function=FUN_ffffffffbfc2c078
ffffffffbfc2c078	sd a1,0x0(a0)
ffffffffbfc2c07c	lui v0,0x80
ffffffffbfc2c080	dsrl32 a0,a0,0x8
ffffffffbfc2c084	ori v0,v0,0x118
ffffffffbfc2c088	bne a0,v0,0xffffffffbfc2c0a0
ffffffffbfc2c08c	_lui v0,0xfff0
ffffffffbfc2c090	ori v0,v0,0x23
ffffffffbfc2c094	dsll32 v0,v0,0xb
ffffffffbfc2c098	ori v0,v0,0xf8
ffffffffbfc2c09c	ld v0,0x0(v0)
ffffffffbfc2c0a0	jr ra
ffffffffbfc2c0a4	_nop
