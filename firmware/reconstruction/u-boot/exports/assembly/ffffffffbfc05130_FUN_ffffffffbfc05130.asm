# RV220W U-Boot v1.1.0 entry=ffffffffbfc05130 function=FUN_ffffffffbfc05130
ffffffffbfc05130	addiu sp,sp,-0x10
ffffffffbfc05134	sd gp,0x0(sp)
ffffffffbfc05138	lui gp,0x4
ffffffffbfc0513c	sd ra,0x8(sp)
ffffffffbfc05140	addu gp,gp,t9
ffffffffbfc05144	addiu gp,gp,-0x1a50
ffffffffbfc05148	lw t9,0x80(gp)
ffffffffbfc0514c	jalr t9
ffffffffbfc05150	_nop
ffffffffbfc05154	ld ra,0x8(sp)
ffffffffbfc05158	SPECIAL2 ra,v0,v0,0x1,0x3a
ffffffffbfc0515c	ld gp,0x0(sp)
ffffffffbfc05160	andi v0,v0,0x1
ffffffffbfc05164	jr ra
ffffffffbfc05168	_addiu sp,sp,0x10
