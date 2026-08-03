# RV220W U-Boot v1.1.0 entry=ffffffffbfc346e0 function=FUN_ffffffffbfc346e0
ffffffffbfc346e0	sd a1,0x0(a0)
ffffffffbfc346e4	lui v0,0x80
ffffffffbfc346e8	dsrl32 a0,a0,0x8
ffffffffbfc346ec	ori v0,v0,0x118
ffffffffbfc346f0	bne a0,v0,0xffffffffbfc34708
ffffffffbfc346f4	_lui v0,0xfff0
ffffffffbfc346f8	ori v0,v0,0x23
ffffffffbfc346fc	dsll32 v0,v0,0xb
ffffffffbfc34700	ori v0,v0,0xf8
ffffffffbfc34704	ld v0,0x0(v0)
ffffffffbfc34708	jr ra
ffffffffbfc3470c	_nop
