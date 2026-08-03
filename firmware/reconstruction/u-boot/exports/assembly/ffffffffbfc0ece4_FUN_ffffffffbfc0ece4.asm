# RV220W U-Boot v1.1.0 entry=ffffffffbfc0ece4 function=FUN_ffffffffbfc0ece4
ffffffffbfc0ece4	lui v1,0x3
ffffffffbfc0ece8	addu v1,v1,t9
ffffffffbfc0ecec	addiu v1,v1,0x49fc
ffffffffbfc0ecf0	lw v0,0x14(v1)
ffffffffbfc0ecf4	lw a0,0x4a78(v0)
ffffffffbfc0ecf8	beq a0,zero,0xffffffffbfc0ed08
ffffffffbfc0ecfc	_lw t9,0x4bc(v1)
ffffffffbfc0ed00	jr t9
ffffffffbfc0ed04	_nop
ffffffffbfc0ed08	jr ra
ffffffffbfc0ed0c	_nop
