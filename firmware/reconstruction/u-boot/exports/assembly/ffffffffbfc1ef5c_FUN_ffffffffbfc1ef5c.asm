# RV220W U-Boot v1.1.0 entry=ffffffffbfc1ef5c function=FUN_ffffffffbfc1ef5c
ffffffffbfc1ef5c	lui t6,0x2
ffffffffbfc1ef60	daddu t3,t0,zero
ffffffffbfc1ef64	addu t6,t6,t9
ffffffffbfc1ef68	daddu t4,a0,zero
ffffffffbfc1ef6c	addiu t6,t6,0x4784
ffffffffbfc1ef70	daddu t2,a3,zero
ffffffffbfc1ef74	lw a0,0x14(t6)
ffffffffbfc1ef78	seb t1,a2
ffffffffbfc1ef7c	lw t0,0x14(t6)
ffffffffbfc1ef80	daddu t5,a1,zero
ffffffffbfc1ef84	addiu a0,a0,-0x3ca8
ffffffffbfc1ef88	li a3,0x200
ffffffffbfc1ef8c	addiu t0,t0,0x4c30
ffffffffbfc1ef90	daddu a2,t3,zero
ffffffffbfc1ef94	daddu a1,t2,zero
ffffffffbfc1ef98	beq t1,zero,0xffffffffbfc1efb4
ffffffffbfc1ef9c	_clear v0
ffffffffbfc1efa0	li v1,0x20
ffffffffbfc1efa4	beq t1,v1,0xffffffffbfc1efb4
ffffffffbfc1efa8	_li v1,0x9
ffffffffbfc1efac	bne t1,v1,0xffffffffbfc1efd8
ffffffffbfc1efb0	_li v1,0x2
ffffffffbfc1efb4	li v1,0x1
ffffffffbfc1efb8	bne t4,v1,0xffffffffbfc1eff0
ffffffffbfc1efbc	_lw t9,0x468(t6)
ffffffffbfc1efc0	b 0xffffffffbfc1efd0
ffffffffbfc1efc4	_nop
ffffffffbfc1efc8	lw a0,0x4(t5)
ffffffffbfc1efcc	lw t9,0x468(t6)
ffffffffbfc1efd0	jr t9
ffffffffbfc1efd4	_nop
ffffffffbfc1efd8	lw t0,0x14(t6)
ffffffffbfc1efdc	daddu a1,t2,zero
ffffffffbfc1efe0	daddu a2,t3,zero
ffffffffbfc1efe4	addiu t0,t0,0x4c30
ffffffffbfc1efe8	beq t4,v1,0xffffffffbfc1efc8
ffffffffbfc1efec	_li a3,0x200
ffffffffbfc1eff0	jr ra
ffffffffbfc1eff4	_nop
