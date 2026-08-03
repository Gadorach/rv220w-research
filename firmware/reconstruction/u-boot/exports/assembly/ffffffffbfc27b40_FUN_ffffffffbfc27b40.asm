# RV220W U-Boot v1.1.0 entry=ffffffffbfc27b40 function=FUN_ffffffffbfc27b40
ffffffffbfc27b40	sd a1,0x0(a0)
ffffffffbfc27b44	lui v0,0x80
ffffffffbfc27b48	dsrl32 a0,a0,0x8
ffffffffbfc27b4c	ori v0,v0,0x118
ffffffffbfc27b50	bne a0,v0,0xffffffffbfc27b68
ffffffffbfc27b54	_lui v0,0xfff0
ffffffffbfc27b58	ori v0,v0,0x23
ffffffffbfc27b5c	dsll32 v0,v0,0xb
ffffffffbfc27b60	ori v0,v0,0xf8
ffffffffbfc27b64	ld v0,0x0(v0)
ffffffffbfc27b68	jr ra
ffffffffbfc27b6c	_nop
