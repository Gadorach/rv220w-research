# RV220W U-Boot v1.1.0 entry=ffffffffbfc0bd80 function=FUN_ffffffffbfc0bd80
ffffffffbfc0bd80	lb v1,0x0(a1)
ffffffffbfc0bd84	li v0,0x22
ffffffffbfc0bd88	bne v1,v0,0xffffffffbfc0bda4
ffffffffbfc0bd8c	_nop
ffffffffbfc0bd90	addiu a1,a1,0x1
ffffffffbfc0bd94	b 0xffffffffbfc0bda4
ffffffffbfc0bd98	_addiu a2,a2,-0x1
ffffffffbfc0bd9c	sb v1,0x0(a0)
ffffffffbfc0bda0	addiu a0,a0,0x1
ffffffffbfc0bda4	addiu a2,a2,-0x1
ffffffffbfc0bda8	blez a2,0xffffffffbfc0bdc8
ffffffffbfc0bdac	_nop
ffffffffbfc0bdb0	lb v1,0x0(a1)
ffffffffbfc0bdb4	beq v1,zero,0xffffffffbfc0bdc8
ffffffffbfc0bdb8	_addiu a1,a1,0x1
ffffffffbfc0bdbc	li v0,0x22
ffffffffbfc0bdc0	bne v1,v0,0xffffffffbfc0bd9c
ffffffffbfc0bdc4	_nop
ffffffffbfc0bdc8	jr ra
ffffffffbfc0bdcc	_sb zero,0x0(a0)
