# RV220W U-Boot v1.1.0 entry=ffffffffbfc0c054 function=FUN_ffffffffbfc0c054
ffffffffbfc0c054	addiu sp,sp,-0x10
ffffffffbfc0c058	sd gp,0x0(sp)
ffffffffbfc0c05c	lui gp,0x3
ffffffffbfc0c060	sd ra,0x8(sp)
ffffffffbfc0c064	addu gp,gp,t9
ffffffffbfc0c068	addiu gp,gp,0x768c
ffffffffbfc0c06c	lw t9,0x82c(gp)
ffffffffbfc0c070	jalr t9
ffffffffbfc0c074	_nop
ffffffffbfc0c078	lw t9,0x6e8(gp)
ffffffffbfc0c07c	daddu a0,v0,zero
ffffffffbfc0c080	ld gp,0x0(sp)
ffffffffbfc0c084	ld ra,0x8(sp)
ffffffffbfc0c088	jr t9
ffffffffbfc0c08c	_addiu sp,sp,0x10
