# RV220W U-Boot v1.1.0 entry=ffffffffbfc00de4 function=FUN_ffffffffbfc00de4
ffffffffbfc00de4	addiu sp,sp,-0x20
ffffffffbfc00de8	sd gp,0x10(sp)
ffffffffbfc00dec	lui gp,0x4
ffffffffbfc00df0	sd s1,0x8(sp)
ffffffffbfc00df4	addu gp,gp,t9
ffffffffbfc00df8	sd s0,0x0(sp)
ffffffffbfc00dfc	addiu gp,gp,0x28fc
ffffffffbfc00e00	lw v0,0xc(gp)
ffffffffbfc00e04	lui s0,0x30d
ffffffffbfc00e08	sd ra,0x18(sp)
ffffffffbfc00e0c	addiu s1,v0,0xa00
ffffffffbfc00e10	daddu t9,s1,zero
ffffffffbfc00e14	jalr t9
ffffffffbfc00e18	_ori a0,s0,0x1
ffffffffbfc00e1c	bne v0,zero,0xffffffffbfc00e4c
ffffffffbfc00e20	_ori a0,s0,0x100
ffffffffbfc00e24	daddu t9,s1,zero
ffffffffbfc00e28	jalr t9
ffffffffbfc00e2c	_nop
ffffffffbfc00e30	bne v0,zero,0xffffffffbfc00e4c
ffffffffbfc00e34	_ori a0,s0,0x300
ffffffffbfc00e38	daddu t9,s1,zero
ffffffffbfc00e3c	jalr t9
ffffffffbfc00e40	_nop
ffffffffbfc00e44	beq v0,zero,0xffffffffbfc00e84
ffffffffbfc00e48	_clear v0
ffffffffbfc00e4c	lw t9,0xc(gp)
ffffffffbfc00e50	lui a0,0x10d
ffffffffbfc00e54	addiu t9,t9,0xa00
ffffffffbfc00e58	jalr t9
ffffffffbfc00e5c	_ori a0,a0,0x110
ffffffffbfc00e60	bne v0,zero,0xffffffffbfc00e80
ffffffffbfc00e64	_li a0,0x78
ffffffffbfc00e68	lw t9,0xc(gp)
ffffffffbfc00e6c	addiu t9,t9,0xba8
ffffffffbfc00e70	jalr t9
ffffffffbfc00e74	_nop
ffffffffbfc00e78	b 0xffffffffbfc00e84
ffffffffbfc00e7c	_sltiu v0,v0,0x1
ffffffffbfc00e80	clear v0
ffffffffbfc00e84	ld ra,0x18(sp)
ffffffffbfc00e88	ld gp,0x10(sp)
ffffffffbfc00e8c	ld s1,0x8(sp)
ffffffffbfc00e90	ld s0,0x0(sp)
ffffffffbfc00e94	jr ra
ffffffffbfc00e98	_addiu sp,sp,0x20
