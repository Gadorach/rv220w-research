# RV220W U-Boot v1.1.0 entry=ffffffffbfc0b5c0 function=FUN_ffffffffbfc0b5c0
ffffffffbfc0b5c0	lui v0,0xfff0
ffffffffbfc0b5c4	li a1,0x1000
ffffffffbfc0b5c8	ori v0,v0,0x23
ffffffffbfc0b5cc	dins a1,a0,0x0,0x8
ffffffffbfc0b5d0	dsll32 v0,v0,0xb
ffffffffbfc0b5d4	ori v0,v0,0x1500
ffffffffbfc0b5d8	sd a1,0x0(v0)
ffffffffbfc0b5dc	lui v1,0xfff0
ffffffffbfc0b5e0	ori v1,v1,0x23
ffffffffbfc0b5e4	dsll32 v1,v1,0xb
ffffffffbfc0b5e8	ori v0,v1,0xf8
ffffffffbfc0b5ec	ld v0,0x0(v0)
ffffffffbfc0b5f0	ori v1,v1,0x1500
ffffffffbfc0b5f4	ld a1,0x0(v1)
ffffffffbfc0b5f8	beq a1,zero,0xffffffffbfc0b608
ffffffffbfc0b5fc	_dext v0,a1,0x10,0x8
ffffffffbfc0b600	swc2 hint12,-0x4(a1)
ffffffffbfc0b604	nop
ffffffffbfc0b608	jr ra
ffffffffbfc0b60c	_andi v0,v0,0xff
