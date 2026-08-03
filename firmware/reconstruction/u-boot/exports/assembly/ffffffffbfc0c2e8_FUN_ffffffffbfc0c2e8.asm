# RV220W U-Boot v1.1.0 entry=ffffffffbfc0c2e8 function=FUN_ffffffffbfc0c2e8
ffffffffbfc0c2e8	addiu sp,sp,-0x20
ffffffffbfc0c2ec	daddu a1,a0,zero
ffffffffbfc0c2f0	sd gp,0x10(sp)
ffffffffbfc0c2f4	lui gp,0x3
ffffffffbfc0c2f8	addu gp,gp,t9
ffffffffbfc0c2fc	daddu a0,sp,zero
ffffffffbfc0c300	addiu gp,gp,0x73f8
ffffffffbfc0c304	lw t9,0x7a4(gp)
ffffffffbfc0c308	sd ra,0x18(sp)
ffffffffbfc0c30c	jalr t9
ffffffffbfc0c310	_li a2,0x4
ffffffffbfc0c314	lw v0,0x0(sp)
ffffffffbfc0c318	ld ra,0x18(sp)
ffffffffbfc0c31c	ld gp,0x10(sp)
ffffffffbfc0c320	jr ra
ffffffffbfc0c324	_addiu sp,sp,0x20
