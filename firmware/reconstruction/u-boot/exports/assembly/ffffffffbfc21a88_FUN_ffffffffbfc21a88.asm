# RV220W U-Boot v1.1.0 entry=ffffffffbfc21a88 function=FUN_ffffffffbfc21a88
ffffffffbfc21a88	li v0,-0x1
ffffffffbfc21a8c	bne a1,v0,0xffffffffbfc21a9c
ffffffffbfc21a90	_nop
ffffffffbfc21a94	b 0xffffffffbfc21aac
ffffffffbfc21a98	_li a1,0x1
ffffffffbfc21a9c	bne a1,zero,0xffffffffbfc21aac
ffffffffbfc21aa0	_nop
ffffffffbfc21aa4	lw v0,0x0(a0)
ffffffffbfc21aa8	lw a1,0x14(v0)
ffffffffbfc21aac	lw v0,0x0(a0)
ffffffffbfc21ab0	addiu a0,a1,-0x1
ffffffffbfc21ab4	lw v1,0x10(v0)
ffffffffbfc21ab8	addiu v0,v0,0x18
ffffffffbfc21abc	mul a1,a0,v1
ffffffffbfc21ac0	jr ra
ffffffffbfc21ac4	_addu v0,a1,v0
