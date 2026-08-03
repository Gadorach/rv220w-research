# RV220W U-Boot v1.1.0 entry=ffffffffbfc29b6c function=FUN_ffffffffbfc29b6c
ffffffffbfc29b6c	slti v0,a0,0x10
ffffffffbfc29b70	bne v0,zero,0xffffffffbfc29b9c
ffffffffbfc29b74	_addiu a1,a0,-0x10
ffffffffbfc29b78	sltiu v0,a1,0x10
ffffffffbfc29b7c	bne v0,zero,0xffffffffbfc29b9c
ffffffffbfc29b80	_addiu v1,a0,-0x20
ffffffffbfc29b84	sltiu v0,v1,0x4
ffffffffbfc29b88	bne v0,zero,0xffffffffbfc29b9c
ffffffffbfc29b8c	_addiu v1,a0,-0x24
ffffffffbfc29b90	sltiu v1,v1,0x4
ffffffffbfc29b94	ori v0,zero,0xffff
ffffffffbfc29b98	movz a0,v0,v1
ffffffffbfc29b9c	jr ra
ffffffffbfc29ba0	_daddu v0,a0,zero
