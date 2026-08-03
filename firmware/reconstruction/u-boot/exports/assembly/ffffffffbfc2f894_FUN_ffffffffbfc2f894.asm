# RV220W U-Boot v1.1.0 entry=ffffffffbfc2f894 function=FUN_ffffffffbfc2f894
ffffffffbfc2f894	slti v0,a0,0x10
ffffffffbfc2f898	bne v0,zero,0xffffffffbfc2f8c4
ffffffffbfc2f89c	_addiu a1,a0,-0x10
ffffffffbfc2f8a0	sltiu v0,a1,0x10
ffffffffbfc2f8a4	bne v0,zero,0xffffffffbfc2f8c4
ffffffffbfc2f8a8	_addiu v1,a0,-0x20
ffffffffbfc2f8ac	sltiu v0,v1,0x4
ffffffffbfc2f8b0	bne v0,zero,0xffffffffbfc2f8c4
ffffffffbfc2f8b4	_addiu v1,a0,-0x24
ffffffffbfc2f8b8	sltiu v1,v1,0x4
ffffffffbfc2f8bc	ori v0,zero,0xffff
ffffffffbfc2f8c0	movz a0,v0,v1
ffffffffbfc2f8c4	jr ra
ffffffffbfc2f8c8	_daddu v0,a0,zero
