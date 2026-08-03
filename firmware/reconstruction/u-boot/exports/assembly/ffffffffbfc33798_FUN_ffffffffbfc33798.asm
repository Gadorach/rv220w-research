# RV220W U-Boot v1.1.0 entry=ffffffffbfc33798 function=FUN_ffffffffbfc33798
ffffffffbfc33798	sd a1,0x0(a0)
ffffffffbfc3379c	lui v0,0x80
ffffffffbfc337a0	dsrl32 a0,a0,0x8
ffffffffbfc337a4	ori v0,v0,0x118
ffffffffbfc337a8	bne a0,v0,0xffffffffbfc337c0
ffffffffbfc337ac	_lui v0,0xfff0
ffffffffbfc337b0	ori v0,v0,0x23
ffffffffbfc337b4	dsll32 v0,v0,0xb
ffffffffbfc337b8	ori v0,v0,0xf8
ffffffffbfc337bc	ld v0,0x0(v0)
ffffffffbfc337c0	jr ra
ffffffffbfc337c4	_nop
