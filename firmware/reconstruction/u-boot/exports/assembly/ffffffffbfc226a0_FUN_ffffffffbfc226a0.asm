# RV220W U-Boot v1.1.0 entry=ffffffffbfc226a0 function=FUN_ffffffffbfc226a0
ffffffffbfc226a0	sd a1,0x0(a0)
ffffffffbfc226a4	lui v0,0x80
ffffffffbfc226a8	dsrl32 a0,a0,0x8
ffffffffbfc226ac	ori v0,v0,0x118
ffffffffbfc226b0	bne a0,v0,0xffffffffbfc226c8
ffffffffbfc226b4	_lui v0,0xfff0
ffffffffbfc226b8	ori v0,v0,0x23
ffffffffbfc226bc	dsll32 v0,v0,0xb
ffffffffbfc226c0	ori v0,v0,0xf8
ffffffffbfc226c4	ld v0,0x0(v0)
ffffffffbfc226c8	jr ra
ffffffffbfc226cc	_nop
