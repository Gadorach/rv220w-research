# RV220W U-Boot v1.1.0 entry=ffffffffbfc12420 function=FUN_ffffffffbfc12420
ffffffffbfc12420	lw t1,0x110(a0)
ffffffffbfc12424	addiu a2,a0,0x14
ffffffffbfc12428	clear t0
ffffffffbfc1242c	daddu a1,a0,zero
ffffffffbfc12430	sw zero,0x134(a0)
ffffffffbfc12434	li t2,0x1
ffffffffbfc12438	sw zero,0x138(a0)
ffffffffbfc1243c	b 0xffffffffbfc124b4
ffffffffbfc12440	_daddu a3,a2,zero
ffffffffbfc12444	lw v0,0x20(a1)
ffffffffbfc12448	beq v0,zero,0xffffffffbfc12480
ffffffffbfc1244c	_nop
ffffffffbfc12450	bne v0,t2,0xffffffffbfc124a4
ffffffffbfc12454	_nop
ffffffffbfc12458	lw v0,0x138(a0)
ffffffffbfc1245c	beq v0,zero,0xffffffffbfc12478
ffffffffbfc12460	_nop
ffffffffbfc12464	lw v0,0x8(v0)
ffffffffbfc12468	lw v1,0x1c(a1)
ffffffffbfc1246c	sltu v0,v0,v1
ffffffffbfc12470	beq v0,zero,0xffffffffbfc124a4
ffffffffbfc12474	_nop
ffffffffbfc12478	b 0xffffffffbfc124a4
ffffffffbfc1247c	_sw a3,0x138(a0)
ffffffffbfc12480	lw v0,0x134(a0)
ffffffffbfc12484	beq v0,zero,0xffffffffbfc124a0
ffffffffbfc12488	_nop
ffffffffbfc1248c	lw v0,0x8(v0)
ffffffffbfc12490	lw v1,0x1c(a1)
ffffffffbfc12494	sltu v0,v0,v1
ffffffffbfc12498	beq v0,zero,0xffffffffbfc124a4
ffffffffbfc1249c	_nop
ffffffffbfc124a0	sw a2,0x134(a0)
ffffffffbfc124a4	addiu t0,t0,0x1
ffffffffbfc124a8	addiu a3,a3,0x24
ffffffffbfc124ac	addiu a2,a2,0x24
ffffffffbfc124b0	addiu a1,a1,0x24
ffffffffbfc124b4	slt v0,t0,t1
ffffffffbfc124b8	bne v0,zero,0xffffffffbfc12444
ffffffffbfc124bc	_nop
ffffffffbfc124c0	lw v1,0x134(a0)
ffffffffbfc124c4	beq v1,zero,0xffffffffbfc124d4
ffffffffbfc124c8	_nop
ffffffffbfc124cc	lw v0,0x0(v1)
ffffffffbfc124d0	sw v0,0x20(v1)
ffffffffbfc124d4	lw a0,0x138(a0)
ffffffffbfc124d8	beq a0,zero,0xffffffffbfc124e8
ffffffffbfc124dc	_nop
ffffffffbfc124e0	lw v0,0x0(a0)
ffffffffbfc124e4	sw v0,0x20(a0)
ffffffffbfc124e8	jr ra
ffffffffbfc124ec	_nop
