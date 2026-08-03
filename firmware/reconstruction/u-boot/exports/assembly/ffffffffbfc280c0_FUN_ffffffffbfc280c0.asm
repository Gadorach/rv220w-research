# RV220W U-Boot v1.1.0 entry=ffffffffbfc280c0 function=FUN_ffffffffbfc280c0
ffffffffbfc280c0	sd a1,0x0(a0)
ffffffffbfc280c4	lui v0,0x80
ffffffffbfc280c8	dsrl32 a0,a0,0x8
ffffffffbfc280cc	ori v0,v0,0x118
ffffffffbfc280d0	bne a0,v0,0xffffffffbfc280e8
ffffffffbfc280d4	_lui v0,0xfff0
ffffffffbfc280d8	ori v0,v0,0x23
ffffffffbfc280dc	dsll32 v0,v0,0xb
ffffffffbfc280e0	ori v0,v0,0xf8
ffffffffbfc280e4	ld v0,0x0(v0)
ffffffffbfc280e8	jr ra
ffffffffbfc280ec	_nop
