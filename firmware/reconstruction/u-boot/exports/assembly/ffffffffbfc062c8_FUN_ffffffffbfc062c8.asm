# RV220W U-Boot v1.1.0 entry=ffffffffbfc062c8 function=FUN_ffffffffbfc062c8
ffffffffbfc062c8	sd a1,0x0(a0)
ffffffffbfc062cc	lui v0,0x80
ffffffffbfc062d0	dsrl32 a0,a0,0x8
ffffffffbfc062d4	ori v0,v0,0x118
ffffffffbfc062d8	bne a0,v0,0xffffffffbfc062f0
ffffffffbfc062dc	_lui v0,0xfff0
ffffffffbfc062e0	ori v0,v0,0x23
ffffffffbfc062e4	dsll32 v0,v0,0xb
ffffffffbfc062e8	ori v0,v0,0xf8
ffffffffbfc062ec	ld v0,0x0(v0)
ffffffffbfc062f0	jr ra
ffffffffbfc062f4	_nop
