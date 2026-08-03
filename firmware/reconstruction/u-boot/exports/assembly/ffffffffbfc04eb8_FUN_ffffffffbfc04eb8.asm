# RV220W U-Boot v1.1.0 entry=ffffffffbfc04eb8 function=FUN_ffffffffbfc04eb8
ffffffffbfc04eb8	sd a1,0x0(a0)
ffffffffbfc04ebc	lui v0,0x80
ffffffffbfc04ec0	dsrl32 a0,a0,0x8
ffffffffbfc04ec4	ori v0,v0,0x118
ffffffffbfc04ec8	bne a0,v0,0xffffffffbfc04ee0
ffffffffbfc04ecc	_lui v0,0xfff0
ffffffffbfc04ed0	ori v0,v0,0x23
ffffffffbfc04ed4	dsll32 v0,v0,0xb
ffffffffbfc04ed8	ori v0,v0,0xf8
ffffffffbfc04edc	ld v0,0x0(v0)
ffffffffbfc04ee0	jr ra
ffffffffbfc04ee4	_nop
