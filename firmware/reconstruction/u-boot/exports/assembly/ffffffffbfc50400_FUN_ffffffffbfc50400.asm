# RV220W U-Boot v1.1.0 entry=ffffffffbfc50400 function=FUN_ffffffffbfc50400
ffffffffbfc50400	addiu sp,sp,-0x20
ffffffffbfc50404	sd gp,0x10(sp)
ffffffffbfc50408	lui gp,0x0
ffffffffbfc5040c	sd s1,0x8(sp)
ffffffffbfc50410	addu gp,gp,t9
ffffffffbfc50414	sd s0,0x0(sp)
ffffffffbfc50418	addiu gp,gp,0x5820
ffffffffbfc5041c	sd ra,0x18(sp)
ffffffffbfc50420	daddu s1,a1,zero
ffffffffbfc50424	b 0xffffffffbfc50458
ffffffffbfc50428	_daddu s0,a0,zero
ffffffffbfc5042c	jalr t9
ffffffffbfc50430	_nop
ffffffffbfc50434	li a0,0x6
ffffffffbfc50438	swc2 load,0x6(s0)
ffffffffbfc5043c	lw t9,0x18c(gp)
ffffffffbfc50440	jalr t9
ffffffffbfc50444	_nop
ffffffffbfc50448	lw t9,0x18c(gp)
ffffffffbfc5044c	jalr t9
ffffffffbfc50450	_li a0,0x7
ffffffffbfc50454	addiu s0,s0,0x1
ffffffffbfc50458	lw t9,0x138(gp)
ffffffffbfc5045c	slt v0,s1,s0
ffffffffbfc50460	daddu a1,s0,zero
ffffffffbfc50464	beq v0,zero,0xffffffffbfc5042c
ffffffffbfc50468	_daddu a0,s0,zero
ffffffffbfc5046c	ld ra,0x18(sp)
ffffffffbfc50470	ld gp,0x10(sp)
ffffffffbfc50474	ld s1,0x8(sp)
ffffffffbfc50478	ld s0,0x0(sp)
ffffffffbfc5047c	jr ra
ffffffffbfc50480	_addiu sp,sp,0x20
