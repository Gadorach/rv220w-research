# RV220W U-Boot v1.1.0 entry=ffffffffbfc1b738 function=FUN_ffffffffbfc1b738
ffffffffbfc1b738	li v0,0x1
ffffffffbfc1b73c	bne a2,v0,0xffffffffbfc1b794
ffffffffbfc1b740	_clear v1
ffffffffbfc1b744	beq a3,zero,0xffffffffbfc1b794
ffffffffbfc1b748	_li a2,0xc
ffffffffbfc1b74c	li t2,0x1
ffffffffbfc1b750	li t1,-0x1
ffffffffbfc1b754	li t0,0x18
ffffffffbfc1b758	addiu v0,a2,0x1
ffffffffbfc1b75c	sllv v1,t2,a2
ffffffffbfc1b760	dsllv v0,t1,v0
ffffffffbfc1b764	SPECIAL2 s8,v1,v1,0x1,0x32
ffffffffbfc1b768	and v0,a0,v0
ffffffffbfc1b76c	daddu v0,v1,v0
ffffffffbfc1b770	sltu v0,a1,v0
ffffffffbfc1b774	bne v0,zero,0xffffffffbfc1b790
ffffffffbfc1b778	_nop
ffffffffbfc1b77c	addiu a2,a2,0x2
ffffffffbfc1b780	bne a2,t0,0xffffffffbfc1b758
ffffffffbfc1b784	_lui v1,0x200
ffffffffbfc1b788	b 0xffffffffbfc1b794
ffffffffbfc1b78c	_sw a2,0x0(a3)
ffffffffbfc1b790	sw a2,0x0(a3)
ffffffffbfc1b794	jr ra
ffffffffbfc1b798	_daddu v0,v1,zero
