# RV220W U-Boot v1.1.0 entry=ffffffffbfc0df6c function=FUN_ffffffffbfc0df6c
ffffffffbfc0df6c	addiu sp,sp,-0x20
ffffffffbfc0df70	li a2,0x4
ffffffffbfc0df74	sd gp,0x10(sp)
ffffffffbfc0df78	lui gp,0x3
ffffffffbfc0df7c	sd ra,0x18(sp)
ffffffffbfc0df80	addu gp,gp,t9
ffffffffbfc0df84	sw a1,0x0(sp)
ffffffffbfc0df88	addiu gp,gp,0x5774
ffffffffbfc0df8c	lw t9,0x7a4(gp)
ffffffffbfc0df90	jalr t9
ffffffffbfc0df94	_daddu a1,sp,zero
ffffffffbfc0df98	ld ra,0x18(sp)
ffffffffbfc0df9c	ld gp,0x10(sp)
ffffffffbfc0dfa0	jr ra
ffffffffbfc0dfa4	_addiu sp,sp,0x20
