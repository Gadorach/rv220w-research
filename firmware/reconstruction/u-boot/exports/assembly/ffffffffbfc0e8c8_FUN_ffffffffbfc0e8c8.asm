# RV220W U-Boot v1.1.0 entry=ffffffffbfc0e8c8 function=FUN_ffffffffbfc0e8c8
ffffffffbfc0e8c8	lui a1,0x3
ffffffffbfc0e8cc	addu a1,a1,t9
ffffffffbfc0e8d0	addiu a1,a1,0x4e18
ffffffffbfc0e8d4	lw v0,0x14(a1)
ffffffffbfc0e8d8	lw v1,0x4a74(v0)
ffffffffbfc0e8dc	beq v1,zero,0xffffffffbfc0e918
ffffffffbfc0e8e0	_li a0,-0x1
ffffffffbfc0e8e4	lw v0,0x14(a1)
ffffffffbfc0e8e8	clear a0
ffffffffbfc0e8ec	lw v0,0x4a78(v0)
ffffffffbfc0e8f0	beq v1,v0,0xffffffffbfc0e90c
ffffffffbfc0e8f4	_nop
ffffffffbfc0e8f8	lw v1,0x30(v1)
ffffffffbfc0e8fc	beq v1,zero,0xffffffffbfc0e914
ffffffffbfc0e900	_addiu a0,a0,0x1
ffffffffbfc0e904	b 0xffffffffbfc0e8f0
ffffffffbfc0e908	_nop
ffffffffbfc0e90c	bne v1,zero,0xffffffffbfc0e918
ffffffffbfc0e910	_nop
ffffffffbfc0e914	clear a0
ffffffffbfc0e918	jr ra
ffffffffbfc0e91c	_daddu v0,a0,zero
