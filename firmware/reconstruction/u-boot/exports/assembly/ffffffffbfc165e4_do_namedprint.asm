# RV220W U-Boot v1.1.0 entry=ffffffffbfc165e4 function=do_namedprint
ffffffffbfc165e4	addiu sp,sp,-0x10
ffffffffbfc165e8	sd gp,0x0(sp)
ffffffffbfc165ec	lui gp,0x3
ffffffffbfc165f0	sd ra,0x8(sp)
ffffffffbfc165f4	addu gp,gp,t9
ffffffffbfc165f8	addiu gp,gp,-0x2f04
ffffffffbfc165fc	lw t9,0x95c(gp)
ffffffffbfc16600	jalr t9
ffffffffbfc16604	_nop
ffffffffbfc16608	clear v0
ffffffffbfc1660c	ld ra,0x8(sp)
ffffffffbfc16610	ld gp,0x0(sp)
ffffffffbfc16614	jr ra
ffffffffbfc16618	_addiu sp,sp,0x10
