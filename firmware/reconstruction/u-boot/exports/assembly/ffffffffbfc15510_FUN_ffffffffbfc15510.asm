# RV220W U-Boot v1.1.0 entry=ffffffffbfc15510 function=FUN_ffffffffbfc15510
ffffffffbfc15510	addiu sp,sp,-0x20
ffffffffbfc15514	sd gp,0x8(sp)
ffffffffbfc15518	lui gp,0x3
ffffffffbfc1551c	sd s0,0x0(sp)
ffffffffbfc15520	addu gp,gp,t9
ffffffffbfc15524	addiu gp,gp,-0x1e30
ffffffffbfc15528	lw t9,0x190(gp)
ffffffffbfc1552c	sd ra,0x10(sp)
ffffffffbfc15530	jalr t9
ffffffffbfc15534	_daddu s0,a0,zero
ffffffffbfc15538	b 0xffffffffbfc1554c
ffffffffbfc1553c	_lb a0,0x0(s0)
ffffffffbfc15540	jalr t9
ffffffffbfc15544	_nop
ffffffffbfc15548	lb a0,0x0(s0)
ffffffffbfc1554c	addiu s0,s0,0x1
ffffffffbfc15550	bne a0,zero,0xffffffffbfc15540
ffffffffbfc15554	_lw t9,0x310(gp)
ffffffffbfc15558	ld ra,0x10(sp)
ffffffffbfc1555c	ld gp,0x8(sp)
ffffffffbfc15560	ld s0,0x0(sp)
ffffffffbfc15564	jr ra
ffffffffbfc15568	_addiu sp,sp,0x20
