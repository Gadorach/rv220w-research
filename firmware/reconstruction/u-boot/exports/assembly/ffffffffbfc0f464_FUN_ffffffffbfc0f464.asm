# RV220W U-Boot v1.1.0 entry=ffffffffbfc0f464 function=FUN_ffffffffbfc0f464
ffffffffbfc0f464	addiu sp,sp,-0x30
ffffffffbfc0f468	sll v0,a1,0x2
ffffffffbfc0f46c	sd gp,0x20(sp)
ffffffffbfc0f470	addu v0,v0,a0
ffffffffbfc0f474	sd s1,0x18(sp)
ffffffffbfc0f478	lui gp,0x3
ffffffffbfc0f47c	sd s0,0x10(sp)
ffffffffbfc0f480	addu gp,gp,t9
ffffffffbfc0f484	sd ra,0x28(sp)
ffffffffbfc0f488	andi a1,a3,0xff
ffffffffbfc0f48c	lw v1,0xc(v0)
ffffffffbfc0f490	addiu gp,gp,0x427c
ffffffffbfc0f494	lbu v0,0xa0c(a0)
ffffffffbfc0f498	daddu s0,a0,zero
ffffffffbfc0f49c	lw t9,0x1c(gp)
ffffffffbfc0f4a0	mul a3,a2,v0
ffffffffbfc0f4a4	daddu a2,sp,zero
ffffffffbfc0f4a8	addiu t9,t9,-0xd84
ffffffffbfc0f4ac	jalr t9
ffffffffbfc0f4b0	_addu s1,a3,v1
ffffffffbfc0f4b4	li v0,0x2
ffffffffbfc0f4b8	lbu v1,0xa0c(s0)
ffffffffbfc0f4bc	beq v1,v0,0xffffffffbfc0f510
ffffffffbfc0f4c0	_nop
ffffffffbfc0f4c4	sltiu v0,v1,0x3
ffffffffbfc0f4c8	beq v0,zero,0xffffffffbfc0f4e4
ffffffffbfc0f4cc	_li v0,0x4
ffffffffbfc0f4d0	li v0,0x1
ffffffffbfc0f4d4	bne v1,v0,0xffffffffbfc0f4f8
ffffffffbfc0f4d8	_nop
ffffffffbfc0f4dc	b 0xffffffffbfc0f500
ffffffffbfc0f4e0	_nop
ffffffffbfc0f4e4	beq v1,v0,0xffffffffbfc0f524
ffffffffbfc0f4e8	_nop
ffffffffbfc0f4ec	li v0,0x8
ffffffffbfc0f4f0	beq v1,v0,0xffffffffbfc0f530
ffffffffbfc0f4f4	_nop
ffffffffbfc0f4f8	b 0xffffffffbfc0f53c
ffffffffbfc0f4fc	_clear v0
ffffffffbfc0f500	lbu v0,0x0(s1)
ffffffffbfc0f504	lbu v1,0x0(sp)
ffffffffbfc0f508	b 0xffffffffbfc0f51c
ffffffffbfc0f50c	_andi v0,v0,0xff
ffffffffbfc0f510	lhu v0,0x0(s1)
ffffffffbfc0f514	lhu v1,0x0(sp)
ffffffffbfc0f518	andi v0,v0,0xffff
ffffffffbfc0f51c	b 0xffffffffbfc0f53c
ffffffffbfc0f520	_SPECIAL2 v0,v1,v0,0x0,0x2a
ffffffffbfc0f524	lw v1,0x0(s1)
ffffffffbfc0f528	b 0xffffffffbfc0f51c
ffffffffbfc0f52c	_lw v0,0x0(sp)
ffffffffbfc0f530	ld v1,0x0(s1)
ffffffffbfc0f534	ld v0,0x0(sp)
ffffffffbfc0f538	SPECIAL2 v0,v1,v0,0x0,0x2a
ffffffffbfc0f53c	ld ra,0x28(sp)
ffffffffbfc0f540	ld gp,0x20(sp)
ffffffffbfc0f544	ld s1,0x18(sp)
ffffffffbfc0f548	ld s0,0x10(sp)
ffffffffbfc0f54c	jr ra
ffffffffbfc0f550	_addiu sp,sp,0x30
