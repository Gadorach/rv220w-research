# RV220W U-Boot v1.1.0 entry=ffffffffbfc00780 function=FUN_ffffffffbfc00780
ffffffffbfc00780	daddu sp,a0,zero
ffffffffbfc00784	lui t0,0xbfc0
ffffffffbfc00788	lw t3,0x8(gp)
ffffffffbfc0078c	lw t2,-0xc(t3)
ffffffffbfc00790	daddu t1,a2,zero
ffffffffbfc00794	daddu t6,gp,zero
ffffffffbfc00798	lui at,0xbfc0
ffffffffbfc0079c	sub gp,gp,at
ffffffffbfc007a0	add gp,gp,a2
ffffffffbfc007a4	sub t6,gp,t6
ffffffffbfc007a8	beq t0,t1,0xffffffffbfc007c4
ffffffffbfc007ac	_ld t3,0x0(t0)
ffffffffbfc007b0	sd t3,0x0(t1)
ffffffffbfc007b4	addiu t0,t0,0x8
ffffffffbfc007b8	slt at,t2,t0
ffffffffbfc007bc	beq at,zero,0xffffffffbfc007ac
ffffffffbfc007c0	_addiu t1,t1,0x8
ffffffffbfc007c4	addi t0,a2,0x7e0
ffffffffbfc007c8	synci 0x0(zero)
ffffffffbfc007cc	jr t0
ffffffffbfc007d0	_nop
