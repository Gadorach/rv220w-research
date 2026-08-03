# RV220W U-Boot v1.1.0 entry=ffffffffbfc0bd04 function=FUN_ffffffffbfc0bd04
ffffffffbfc0bd04	addiu sp,sp,-0x10
ffffffffbfc0bd08	sd gp,0x0(sp)
ffffffffbfc0bd0c	lui gp,0x3
ffffffffbfc0bd10	sd ra,0x8(sp)
ffffffffbfc0bd14	addu gp,gp,t9
ffffffffbfc0bd18	addiu gp,gp,0x79dc
ffffffffbfc0bd1c	lw t9,0x37c(gp)
ffffffffbfc0bd20	jalr t9
ffffffffbfc0bd24	_nop
ffffffffbfc0bd28	ld ra,0x8(sp)
ffffffffbfc0bd2c	addiu v0,v0,0x1
ffffffffbfc0bd30	ld gp,0x0(sp)
ffffffffbfc0bd34	andi v0,v0,0xfffe
ffffffffbfc0bd38	sltiu v0,v0,0x1
ffffffffbfc0bd3c	jr ra
ffffffffbfc0bd40	_addiu sp,sp,0x10
