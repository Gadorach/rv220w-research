# RV220W U-Boot v1.1.0 entry=ffffffffbfc23284 function=FUN_ffffffffbfc23284
ffffffffbfc23284	daddu v1,a0,zero
ffffffffbfc23288	li a2,-0x1
ffffffffbfc2328c	addiu a1,a1,-0x1
ffffffffbfc23290	beq a1,a2,0xffffffffbfc232a8
ffffffffbfc23294	_nop
ffffffffbfc23298	lb v0,0x0(v1)
ffffffffbfc2329c	bne v0,zero,0xffffffffbfc2328c
ffffffffbfc232a0	_addiu v1,v1,0x1
ffffffffbfc232a4	addiu v1,v1,-0x1
ffffffffbfc232a8	jr ra
ffffffffbfc232ac	_subu v0,v1,a0
