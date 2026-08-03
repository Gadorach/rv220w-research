# RV220W U-Boot v1.1.0 entry=ffffffffbfc2eaf8 function=FUN_ffffffffbfc2eaf8
ffffffffbfc2eaf8	sd a1,0x0(a0)
ffffffffbfc2eafc	lui v0,0x80
ffffffffbfc2eb00	dsrl32 a0,a0,0x8
ffffffffbfc2eb04	ori v0,v0,0x118
ffffffffbfc2eb08	bne a0,v0,0xffffffffbfc2eb20
ffffffffbfc2eb0c	_lui v0,0xfff0
ffffffffbfc2eb10	ori v0,v0,0x23
ffffffffbfc2eb14	dsll32 v0,v0,0xb
ffffffffbfc2eb18	ori v0,v0,0xf8
ffffffffbfc2eb1c	ld v0,0x0(v0)
ffffffffbfc2eb20	jr ra
ffffffffbfc2eb24	_nop
