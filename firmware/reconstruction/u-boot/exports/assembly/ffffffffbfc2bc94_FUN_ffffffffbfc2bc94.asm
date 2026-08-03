# RV220W U-Boot v1.1.0 entry=ffffffffbfc2bc94 function=FUN_ffffffffbfc2bc94
ffffffffbfc2bc94	addiu sp,sp,-0x20
ffffffffbfc2bc98	sd gp,0x8(sp)
ffffffffbfc2bc9c	lui gp,0x1
ffffffffbfc2bca0	sd s0,0x0(sp)
ffffffffbfc2bca4	addu gp,gp,t9
ffffffffbfc2bca8	sd ra,0x10(sp)
ffffffffbfc2bcac	addiu gp,gp,0x7a4c
ffffffffbfc2bcb0	lw t9,0x7c4(gp)
ffffffffbfc2bcb4	jalr t9
ffffffffbfc2bcb8	_nop
ffffffffbfc2bcbc	clear a1
ffffffffbfc2bcc0	lw a0,0x14(gp)
ffffffffbfc2bcc4	daddu s0,v0,zero
ffffffffbfc2bcc8	lw t9,0x2b0(gp)
ffffffffbfc2bccc	jalr t9
ffffffffbfc2bcd0	_addiu a0,a0,0x1c28
ffffffffbfc2bcd4	bgez s0,0xffffffffbfc2bcf4
ffffffffbfc2bcd8	_ld ra,0x10(sp)
ffffffffbfc2bcdc	lw a0,0x14(gp)
ffffffffbfc2bce0	lw t9,0x92c(gp)
ffffffffbfc2bce4	jalr t9
ffffffffbfc2bce8	_addiu a0,a0,0x1c38
ffffffffbfc2bcec	b 0xffffffffbfc2bcec
ffffffffbfc2bcf0	_nop
ffffffffbfc2bcf4	daddu v0,s0,zero
ffffffffbfc2bcf8	ld gp,0x8(sp)
ffffffffbfc2bcfc	ld s0,0x0(sp)
ffffffffbfc2bd00	jr ra
ffffffffbfc2bd04	_addiu sp,sp,0x20
