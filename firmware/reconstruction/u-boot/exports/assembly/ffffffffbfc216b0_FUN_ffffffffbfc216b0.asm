# RV220W U-Boot v1.1.0 entry=ffffffffbfc216b0 function=FUN_ffffffffbfc216b0
ffffffffbfc216b0	lhu t0,0x4(a3)
ffffffffbfc216b4	lw t2,0xc(a3)
ffffffffbfc216b8	lw t1,0x0(a3)
ffffffffbfc216bc	addiu v0,t0,-0x1
ffffffffbfc216c0	beq t0,zero,0xffffffffbfc21774
ffffffffbfc216c4	_seh t3,v0
ffffffffbfc216c8	beq t1,zero,0xffffffffbfc21774
ffffffffbfc216cc	_sltu v0,a2,a1
ffffffffbfc216d0	bne v0,zero,0xffffffffbfc21774
ffffffffbfc216d4	_ori v0,zero,0xffff
ffffffffbfc216d8	lw v1,0x8(a3)
ffffffffbfc216dc	beq v1,v0,0xffffffffbfc21774
ffffffffbfc216e0	_sltu v0,a2,t2
ffffffffbfc216e4	bne v0,zero,0xffffffffbfc21774
ffffffffbfc216e8	_addu v0,t2,t1
ffffffffbfc216ec	addiu v0,v0,-0x1
ffffffffbfc216f0	sltu v0,v0,a1
ffffffffbfc216f4	bne v0,zero,0xffffffffbfc21774
ffffffffbfc216f8	_daddu t2,t0,zero
ffffffffbfc216fc	andi t1,a0,0x1
ffffffffbfc21700	clear t0
ffffffffbfc21704	andi a0,a0,0x2
ffffffffbfc21708	li t4,0x1
ffffffffbfc2170c	b 0xffffffffbfc21768
ffffffffbfc21710	_addiu v1,a3,0x80c
ffffffffbfc21714	beq t0,t3,0xffffffffbfc21730
ffffffffbfc21718	_nop
ffffffffbfc2171c	lw v0,0x10(a3)
ffffffffbfc21720	addiu v0,v0,-0x1
ffffffffbfc21724	sltu v0,v0,a1
ffffffffbfc21728	bne v0,zero,0xffffffffbfc2175c
ffffffffbfc2172c	_nop
ffffffffbfc21730	lw v0,0xc(a3)
ffffffffbfc21734	sltu v0,a2,v0
ffffffffbfc21738	bne v0,zero,0xffffffffbfc2175c
ffffffffbfc2173c	_nop
ffffffffbfc21740	beq a0,zero,0xffffffffbfc21750
ffffffffbfc21744	_nop
ffffffffbfc21748	b 0xffffffffbfc2175c
ffffffffbfc2174c	_sb zero,0x0(v1)
ffffffffbfc21750	beq t1,zero,0xffffffffbfc2175c
ffffffffbfc21754	_nop
ffffffffbfc21758	sb t4,0x0(v1)
ffffffffbfc2175c	addiu t0,t0,0x1
ffffffffbfc21760	addiu v1,v1,0x1
ffffffffbfc21764	addiu a3,a3,0x4
ffffffffbfc21768	slt v0,t0,t2
ffffffffbfc2176c	bne v0,zero,0xffffffffbfc21714
ffffffffbfc21770	_nop
ffffffffbfc21774	jr ra
ffffffffbfc21778	_nop
