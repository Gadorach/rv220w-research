# RV220W U-Boot v1.1.0 entry=ffffffffbfc27cc0 function=FUN_ffffffffbfc27cc0
ffffffffbfc27cc0	addiu sp,sp,-0x20
ffffffffbfc27cc4	sd gp,0x8(sp)
ffffffffbfc27cc8	lui gp,0x2
ffffffffbfc27ccc	sd s0,0x0(sp)
ffffffffbfc27cd0	addu gp,gp,t9
ffffffffbfc27cd4	sd ra,0x10(sp)
ffffffffbfc27cd8	addiu gp,gp,-0x45e0
ffffffffbfc27cdc	b 0xffffffffbfc27cec
ffffffffbfc27ce0	_daddu s0,a0,zero
ffffffffbfc27ce4	jalr t9
ffffffffbfc27ce8	_nop
ffffffffbfc27cec	lb a0,0x0(s0)
ffffffffbfc27cf0	addiu s0,s0,0x1
ffffffffbfc27cf4	bne a0,zero,0xffffffffbfc27ce4
ffffffffbfc27cf8	_lw t9,0x474(gp)
ffffffffbfc27cfc	ld ra,0x10(sp)
ffffffffbfc27d00	ld gp,0x8(sp)
ffffffffbfc27d04	ld s0,0x0(sp)
ffffffffbfc27d08	jr ra
ffffffffbfc27d0c	_addiu sp,sp,0x20
