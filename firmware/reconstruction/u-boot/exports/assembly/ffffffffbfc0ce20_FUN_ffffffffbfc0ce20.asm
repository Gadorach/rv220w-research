# RV220W U-Boot v1.1.0 entry=ffffffffbfc0ce20 function=FUN_ffffffffbfc0ce20
ffffffffbfc0ce20	addiu sp,sp,-0x20
ffffffffbfc0ce24	sd gp,0x8(sp)
ffffffffbfc0ce28	lui gp,0x3
ffffffffbfc0ce2c	sd ra,0x10(sp)
ffffffffbfc0ce30	addu gp,gp,t9
ffffffffbfc0ce34	sd s0,0x0(sp)
ffffffffbfc0ce38	addiu gp,gp,0x68c0
ffffffffbfc0ce3c	lw t9,0x80c(gp)
ffffffffbfc0ce40	lw s0,0x0(k0)
ffffffffbfc0ce44	jalr t9
ffffffffbfc0ce48	_nop
ffffffffbfc0ce4c	lw t9,0x39c(gp)
ffffffffbfc0ce50	jalr t9
ffffffffbfc0ce54	_nop
ffffffffbfc0ce58	daddu a0,s0,zero
ffffffffbfc0ce5c	lw t9,0x194(gp)
ffffffffbfc0ce60	ld gp,0x8(sp)
ffffffffbfc0ce64	ld ra,0x10(sp)
ffffffffbfc0ce68	ld s0,0x0(sp)
ffffffffbfc0ce6c	jr t9
ffffffffbfc0ce70	_addiu sp,sp,0x20
