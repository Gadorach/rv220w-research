# RV220W U-Boot v1.1.0 entry=ffffffffbfc152bc function=FUN_ffffffffbfc152bc
ffffffffbfc152bc	b 0xffffffffbfc152c8
ffffffffbfc152c0	_clear v1
ffffffffbfc152c4	addu v1,v1,v0
ffffffffbfc152c8	lb v0,0x0(a0)
ffffffffbfc152cc	bne v0,zero,0xffffffffbfc152c4
ffffffffbfc152d0	_addiu a0,a0,0x1
ffffffffbfc152d4	dext v0,v1,0x6,0x2
ffffffffbfc152d8	addu v0,v1,v0
ffffffffbfc152dc	jr ra
ffffffffbfc152e0	_andi v0,v0,0x3f
