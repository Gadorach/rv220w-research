# RV220W U-Boot v1.1.0 entry=ffffffffbfc306bc function=FUN_ffffffffbfc306bc
ffffffffbfc306bc	sd a1,0x0(a0)
ffffffffbfc306c0	lui v0,0x80
ffffffffbfc306c4	dsrl32 a0,a0,0x8
ffffffffbfc306c8	ori v0,v0,0x118
ffffffffbfc306cc	bne a0,v0,0xffffffffbfc306e4
ffffffffbfc306d0	_lui v0,0xfff0
ffffffffbfc306d4	ori v0,v0,0x23
ffffffffbfc306d8	dsll32 v0,v0,0xb
ffffffffbfc306dc	ori v0,v0,0xf8
ffffffffbfc306e0	ld v0,0x0(v0)
ffffffffbfc306e4	jr ra
ffffffffbfc306e8	_nop
