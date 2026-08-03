# RV220W U-Boot v1.1.0 entry=ffffffffbfc0bd44 function=FUN_ffffffffbfc0bd44
ffffffffbfc0bd44	lui a1,0x3
ffffffffbfc0bd48	addu a1,a1,t9
ffffffffbfc0bd4c	addiu a1,a1,0x799c
ffffffffbfc0bd50	lw v0,0x150(a1)
ffffffffbfc0bd54	lhu v1,0x0(v0)
ffffffffbfc0bd58	ori v0,zero,0xffff
ffffffffbfc0bd5c	beq v1,v0,0xffffffffbfc0bd78
ffffffffbfc0bd60	_li a0,0xe
ffffffffbfc0bd64	andi v1,v1,0xfff
ffffffffbfc0bd68	li v0,0xfff
ffffffffbfc0bd6c	beq v1,v0,0xffffffffbfc0bd78
ffffffffbfc0bd70	_nop
ffffffffbfc0bd74	li a0,0x12
ffffffffbfc0bd78	jr ra
ffffffffbfc0bd7c	_daddu v0,a0,zero
