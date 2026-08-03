# RV220W U-Boot v1.1.0 entry=ffffffffbfc32a40 function=FUN_ffffffffbfc32a40
ffffffffbfc32a40	addiu sp,sp,-0x10
ffffffffbfc32a44	sd gp,0x0(sp)
ffffffffbfc32a48	lui gp,0x1
ffffffffbfc32a4c	sd ra,0x8(sp)
ffffffffbfc32a50	addu gp,gp,t9
ffffffffbfc32a54	addiu gp,gp,0xca0
ffffffffbfc32a58	lw t9,0x680(gp)
ffffffffbfc32a5c	jalr t9
ffffffffbfc32a60	_li a1,0x1
ffffffffbfc32a64	li v0,0x1
ffffffffbfc32a68	ld ra,0x8(sp)
ffffffffbfc32a6c	ld gp,0x0(sp)
ffffffffbfc32a70	jr ra
ffffffffbfc32a74	_addiu sp,sp,0x10
