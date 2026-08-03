# RV220W U-Boot v1.1.0 entry=ffffffffbfc29afc function=FUN_ffffffffbfc29afc
ffffffffbfc29afc	sd a1,0x0(a0)
ffffffffbfc29b00	lui v0,0x80
ffffffffbfc29b04	dsrl32 a0,a0,0x8
ffffffffbfc29b08	ori v0,v0,0x118
ffffffffbfc29b0c	bne a0,v0,0xffffffffbfc29b24
ffffffffbfc29b10	_lui v0,0xfff0
ffffffffbfc29b14	ori v0,v0,0x23
ffffffffbfc29b18	dsll32 v0,v0,0xb
ffffffffbfc29b1c	ori v0,v0,0xf8
ffffffffbfc29b20	ld v0,0x0(v0)
ffffffffbfc29b24	jr ra
ffffffffbfc29b28	_nop
