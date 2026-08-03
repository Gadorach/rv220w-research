# RV220W U-Boot v1.1.0 entry=ffffffffbfc030b8 function=FUN_ffffffffbfc030b8
ffffffffbfc030b8	sd a1,0x0(a0)
ffffffffbfc030bc	lui v0,0x80
ffffffffbfc030c0	dsrl32 a0,a0,0x8
ffffffffbfc030c4	ori v0,v0,0x118
ffffffffbfc030c8	bne a0,v0,0xffffffffbfc030e0
ffffffffbfc030cc	_lui v0,0xfff0
ffffffffbfc030d0	ori v0,v0,0x23
ffffffffbfc030d4	dsll32 v0,v0,0xb
ffffffffbfc030d8	ori v0,v0,0xf8
ffffffffbfc030dc	ld v0,0x0(v0)
ffffffffbfc030e0	jr ra
ffffffffbfc030e4	_nop
