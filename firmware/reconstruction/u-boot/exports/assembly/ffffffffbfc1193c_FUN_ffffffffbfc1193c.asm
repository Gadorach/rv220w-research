# RV220W U-Boot v1.1.0 entry=ffffffffbfc1193c function=FUN_ffffffffbfc1193c
ffffffffbfc1193c	lw v0,0x114(a0)
ffffffffbfc11940	b 0xffffffffbfc119c0
ffffffffbfc11944	_andi a1,a1,0xffff
ffffffffbfc11948	beq v1,a0,0xffffffffbfc11958
ffffffffbfc1194c	_nop
ffffffffbfc11950	bne v1,a2,0xffffffffbfc119bc
ffffffffbfc11954	_nop
ffffffffbfc11958	lw v1,0x4(v0)
ffffffffbfc1195c	beq v1,a0,0xffffffffbfc1196c
ffffffffbfc11960	_nop
ffffffffbfc11964	bne v1,a3,0xffffffffbfc119bc
ffffffffbfc11968	_nop
ffffffffbfc1196c	lw v1,0x8(v0)
ffffffffbfc11970	beq v1,a0,0xffffffffbfc11980
ffffffffbfc11974	_nop
ffffffffbfc11978	bne v1,a1,0xffffffffbfc119bc
ffffffffbfc1197c	_nop
ffffffffbfc11980	lw v1,0xc(v0)
ffffffffbfc11984	beq v1,a0,0xffffffffbfc11994
ffffffffbfc11988	_nop
ffffffffbfc1198c	bne v1,t0,0xffffffffbfc119bc
ffffffffbfc11990	_nop
ffffffffbfc11994	lw v1,0x10(v0)
ffffffffbfc11998	beq v1,a0,0xffffffffbfc119a8
ffffffffbfc1199c	_nop
ffffffffbfc119a0	bne v1,t1,0xffffffffbfc119bc
ffffffffbfc119a4	_nop
ffffffffbfc119a8	lw v1,0x14(v0)
ffffffffbfc119ac	beq v1,a0,0xffffffffbfc119d8
ffffffffbfc119b0	_nop
ffffffffbfc119b4	beq v1,t2,0xffffffffbfc119d8
ffffffffbfc119b8	_nop
ffffffffbfc119bc	addiu v0,v0,0x28
ffffffffbfc119c0	beq v0,zero,0xffffffffbfc119d8
ffffffffbfc119c4	_nop
ffffffffbfc119c8	lw v1,0x0(v0)
ffffffffbfc119cc	bne v1,zero,0xffffffffbfc11948
ffffffffbfc119d0	_li a0,-0x1
ffffffffbfc119d4	clear v0
ffffffffbfc119d8	jr ra
ffffffffbfc119dc	_nop
