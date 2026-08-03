# RV220W U-Boot v1.1.0 entry=ffffffffbfc0f1f4 function=FUN_ffffffffbfc0f1f4
ffffffffbfc0f1f4	lbu a0,0xa0c(a0)
ffffffffbfc0f1f8	li v0,0x2
ffffffffbfc0f1fc	beq a0,v0,0xffffffffbfc0f23c
ffffffffbfc0f200	_andi v1,a2,0xff
ffffffffbfc0f204	sltiu v0,a0,0x3
ffffffffbfc0f208	beq v0,zero,0xffffffffbfc0f224
ffffffffbfc0f20c	_li v0,0x4
ffffffffbfc0f210	li v0,0x1
ffffffffbfc0f214	bne a0,v0,0xffffffffbfc0f274
ffffffffbfc0f218	_nop
ffffffffbfc0f21c	jr ra
ffffffffbfc0f220	_sb v1,0x0(a1)
ffffffffbfc0f224	beq a0,v0,0xffffffffbfc0f250
ffffffffbfc0f228	_li v0,0x8
ffffffffbfc0f22c	bne a0,v0,0xffffffffbfc0f274
ffffffffbfc0f230	_nop
ffffffffbfc0f234	b 0xffffffffbfc0f264
ffffffffbfc0f238	_ld v0,0x0(a1)
ffffffffbfc0f23c	lhu v0,0x0(a1)
ffffffffbfc0f240	sll v0,v0,0x8
ffffffffbfc0f244	or v0,v0,v1
ffffffffbfc0f248	jr ra
ffffffffbfc0f24c	_sh v0,0x0(a1)
ffffffffbfc0f250	lw v0,0x0(a1)
ffffffffbfc0f254	sll v0,v0,0x8
ffffffffbfc0f258	or v0,v0,v1
ffffffffbfc0f25c	jr ra
ffffffffbfc0f260	_sw v0,0x0(a1)
ffffffffbfc0f264	andi v1,v1,0xff
ffffffffbfc0f268	dsll v0,v0,0x8
ffffffffbfc0f26c	or v0,v0,v1
ffffffffbfc0f270	sd v0,0x0(a1)
ffffffffbfc0f274	jr ra
ffffffffbfc0f278	_nop
