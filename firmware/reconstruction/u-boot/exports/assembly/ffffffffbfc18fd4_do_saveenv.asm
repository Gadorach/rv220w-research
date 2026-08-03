# RV220W U-Boot v1.1.0 entry=ffffffffbfc18fd4 function=do_saveenv
ffffffffbfc18fd4	addiu sp,sp,-0x10
ffffffffbfc18fd8	sd gp,0x0(sp)
ffffffffbfc18fdc	lui gp,0x3
ffffffffbfc18fe0	sd ra,0x8(sp)
ffffffffbfc18fe4	addu gp,gp,t9
ffffffffbfc18fe8	addiu gp,gp,-0x58f4
ffffffffbfc18fec	lw v0,0x774(gp)
ffffffffbfc18ff0	lw a0,0x14(gp)
ffffffffbfc18ff4	lw t9,0x92c(gp)
ffffffffbfc18ff8	lw a1,0x0(v0)
ffffffffbfc18ffc	jalr t9
ffffffffbfc19000	_addiu a0,a0,-0x21e8
ffffffffbfc19004	lw t9,0x6c8(gp)
ffffffffbfc19008	jalr t9
ffffffffbfc1900c	_nop
ffffffffbfc19010	ld ra,0x8(sp)
ffffffffbfc19014	sltu v0,zero,v0
ffffffffbfc19018	ld gp,0x0(sp)
ffffffffbfc1901c	jr ra
ffffffffbfc19020	_addiu sp,sp,0x10
