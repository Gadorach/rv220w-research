# RV220W U-Boot v1.1.0 entry=ffffffffbfc329fc function=FUN_ffffffffbfc329fc
ffffffffbfc329fc	sd a1,0x0(a0)
ffffffffbfc32a00	lui v0,0x80
ffffffffbfc32a04	dsrl32 a0,a0,0x8
ffffffffbfc32a08	ori v0,v0,0x118
ffffffffbfc32a0c	bne a0,v0,0xffffffffbfc32a24
ffffffffbfc32a10	_lui v0,0xfff0
ffffffffbfc32a14	ori v0,v0,0x23
ffffffffbfc32a18	dsll32 v0,v0,0xb
ffffffffbfc32a1c	ori v0,v0,0xf8
ffffffffbfc32a20	ld v0,0x0(v0)
ffffffffbfc32a24	jr ra
ffffffffbfc32a28	_nop
