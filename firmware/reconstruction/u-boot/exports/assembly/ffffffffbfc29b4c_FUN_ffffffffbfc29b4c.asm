# RV220W U-Boot v1.1.0 entry=ffffffffbfc29b4c function=FUN_ffffffffbfc29b4c
ffffffffbfc29b4c	srl v0,a0,0x10
ffffffffbfc29b50	andi v1,a0,0xf
ffffffffbfc29b54	sll v0,v0,0x4
ffffffffbfc29b58	dext a0,a0,0x4,0x4
ffffffffbfc29b5c	addu v0,v0,v1
ffffffffbfc29b60	sll v0,v0,0x4
ffffffffbfc29b64	jr ra
ffffffffbfc29b68	_addu v0,v0,a0
