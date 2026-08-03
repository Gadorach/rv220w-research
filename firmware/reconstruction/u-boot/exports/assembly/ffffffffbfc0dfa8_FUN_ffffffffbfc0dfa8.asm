# RV220W U-Boot v1.1.0 entry=ffffffffbfc0dfa8 function=FUN_ffffffffbfc0dfa8
ffffffffbfc0dfa8	addiu sp,sp,-0x20
ffffffffbfc0dfac	daddu a1,a0,zero
ffffffffbfc0dfb0	sd gp,0x10(sp)
ffffffffbfc0dfb4	lui gp,0x3
ffffffffbfc0dfb8	addu gp,gp,t9
ffffffffbfc0dfbc	daddu a0,sp,zero
ffffffffbfc0dfc0	addiu gp,gp,0x5738
ffffffffbfc0dfc4	lw t9,0x7a4(gp)
ffffffffbfc0dfc8	sd ra,0x18(sp)
ffffffffbfc0dfcc	jalr t9
ffffffffbfc0dfd0	_li a2,0x4
ffffffffbfc0dfd4	lw v0,0x0(sp)
ffffffffbfc0dfd8	ld ra,0x18(sp)
ffffffffbfc0dfdc	ld gp,0x10(sp)
ffffffffbfc0dfe0	jr ra
ffffffffbfc0dfe4	_addiu sp,sp,0x20
