# RV220W U-Boot v1.1.0 entry=ffffffffbfc165ac function=do_freeprint
ffffffffbfc165ac	addiu sp,sp,-0x10
ffffffffbfc165b0	sd gp,0x0(sp)
ffffffffbfc165b4	lui gp,0x3
ffffffffbfc165b8	sd ra,0x8(sp)
ffffffffbfc165bc	addu gp,gp,t9
ffffffffbfc165c0	addiu gp,gp,-0x2ecc
ffffffffbfc165c4	lw t9,0x144(gp)
ffffffffbfc165c8	jalr t9
ffffffffbfc165cc	_nop
ffffffffbfc165d0	clear v0
ffffffffbfc165d4	ld ra,0x8(sp)
ffffffffbfc165d8	ld gp,0x0(sp)
ffffffffbfc165dc	jr ra
ffffffffbfc165e0	_addiu sp,sp,0x10
