# RV220W U-Boot v1.1.0 entry=ffffffffbfc00fb4 function=FUN_ffffffffbfc00fb4
ffffffffbfc00fb4	addiu sp,sp,-0x10
ffffffffbfc00fb8	sd gp,0x0(sp)
ffffffffbfc00fbc	lui gp,0x4
ffffffffbfc00fc0	sd ra,0x8(sp)
ffffffffbfc00fc4	addu gp,gp,t9
ffffffffbfc00fc8	addiu gp,gp,0x272c
ffffffffbfc00fcc	lw a0,0x10(gp)
ffffffffbfc00fd0	lw t9,0x92c(gp)
ffffffffbfc00fd4	lw a1,0x950(gp)
ffffffffbfc00fd8	jalr t9
ffffffffbfc00fdc	_addiu a0,a0,0x6da0
ffffffffbfc00fe0	clear v0
ffffffffbfc00fe4	ld ra,0x8(sp)
ffffffffbfc00fe8	ld gp,0x0(sp)
ffffffffbfc00fec	jr ra
ffffffffbfc00ff0	_addiu sp,sp,0x10
