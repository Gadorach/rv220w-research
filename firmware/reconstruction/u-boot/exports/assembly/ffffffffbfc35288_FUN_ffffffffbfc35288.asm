# RV220W U-Boot v1.1.0 entry=ffffffffbfc35288 function=FUN_ffffffffbfc35288
ffffffffbfc35288	sd a1,0x0(a0)
ffffffffbfc3528c	lui v0,0x80
ffffffffbfc35290	dsrl32 a0,a0,0x8
ffffffffbfc35294	ori v0,v0,0x118
ffffffffbfc35298	bne a0,v0,0xffffffffbfc352b0
ffffffffbfc3529c	_lui v0,0xfff0
ffffffffbfc352a0	ori v0,v0,0x23
ffffffffbfc352a4	dsll32 v0,v0,0xb
ffffffffbfc352a8	ori v0,v0,0xf8
ffffffffbfc352ac	ld v0,0x0(v0)
ffffffffbfc352b0	jr ra
ffffffffbfc352b4	_nop
