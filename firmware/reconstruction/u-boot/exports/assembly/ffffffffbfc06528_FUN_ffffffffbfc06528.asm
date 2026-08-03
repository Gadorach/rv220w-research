# RV220W U-Boot v1.1.0 entry=ffffffffbfc06528 function=FUN_ffffffffbfc06528
ffffffffbfc06528	addiu sp,sp,-0x20
ffffffffbfc0652c	li a1,-0x7f
ffffffffbfc06530	sd gp,0x8(sp)
ffffffffbfc06534	lui gp,0x4
ffffffffbfc06538	sd s0,0x0(sp)
ffffffffbfc0653c	addu gp,gp,t9
ffffffffbfc06540	addiu gp,gp,-0x2e48
ffffffffbfc06544	lui s0,0xfff0
ffffffffbfc06548	lw t9,0xc(gp)
ffffffffbfc0654c	ori s0,s0,0x23
ffffffffbfc06550	dsll32 s0,s0,0xb
ffffffffbfc06554	SPECIAL2 a3,a0,a0,0x8,0x33
ffffffffbfc06558	sd ra,0x10(sp)
ffffffffbfc0655c	dsll32 a1,a1,0x18
ffffffffbfc06560	or a1,a0,a1
ffffffffbfc06564	addiu t9,t9,0x62c8
ffffffffbfc06568	ori a0,s0,0x1000
ffffffffbfc0656c	jalr t9
ffffffffbfc06570	_ori s0,s0,0x1000
ffffffffbfc06574	ld v0,0x0(s0)
ffffffffbfc06578	bltz v0,0xffffffffbfc06574
ffffffffbfc0657c	_nop
ffffffffbfc06580	ld v0,0x0(s0)
ffffffffbfc06584	sdc2 t8,0x3(v0)
ffffffffbfc06588	nop
ffffffffbfc0658c	b 0xffffffffbfc06598
ffffffffbfc06590	_li v0,-0x1
ffffffffbfc06598	ld ra,0x10(sp)
ffffffffbfc0659c	ld gp,0x8(sp)
ffffffffbfc065a0	ld s0,0x0(sp)
ffffffffbfc065a4	jr ra
ffffffffbfc065a8	_addiu sp,sp,0x20
