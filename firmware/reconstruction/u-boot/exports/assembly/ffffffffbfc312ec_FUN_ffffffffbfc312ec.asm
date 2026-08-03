# RV220W U-Boot v1.1.0 entry=ffffffffbfc312ec function=FUN_ffffffffbfc312ec
ffffffffbfc312ec	sd a1,0x0(a0)
ffffffffbfc312f0	lui v0,0x80
ffffffffbfc312f4	dsrl32 a0,a0,0x8
ffffffffbfc312f8	ori v0,v0,0x118
ffffffffbfc312fc	bne a0,v0,0xffffffffbfc31314
ffffffffbfc31300	_lui v0,0xfff0
ffffffffbfc31304	ori v0,v0,0x23
ffffffffbfc31308	dsll32 v0,v0,0xb
ffffffffbfc3130c	ori v0,v0,0xf8
ffffffffbfc31310	ld v0,0x0(v0)
ffffffffbfc31314	jr ra
ffffffffbfc31318	_nop
