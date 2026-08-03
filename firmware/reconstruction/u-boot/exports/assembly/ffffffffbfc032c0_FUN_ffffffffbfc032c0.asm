# RV220W U-Boot v1.1.0 entry=ffffffffbfc032c0 function=FUN_ffffffffbfc032c0
ffffffffbfc032c0	addiu sp,sp,-0x10
ffffffffbfc032c4	dsra32 v0,a0,0x0
ffffffffbfc032c8	sll a0,a0,0x0
ffffffffbfc032cc	andi a1,a1,0xff
ffffffffbfc032d0	sw a0,0x0(sp)
ffffffffbfc032d4	sw v0,0x4(sp)
ffffffffbfc032d8	lw v0,0x4(sp)
ffffffffbfc032dc	bne v0,zero,0xffffffffbfc032f4
ffffffffbfc032e0	_nop
ffffffffbfc032e4	lw v0,0x0(sp)
ffffffffbfc032e8	bgez v0,0xffffffffbfc032f4
ffffffffbfc032ec	_li v0,-0x1
ffffffffbfc032f0	sw v0,0x4(sp)
ffffffffbfc032f4	lw v1,0x4(sp)
ffffffffbfc032f8	lw v0,0x0(sp)
ffffffffbfc032fc	dsll32 v1,v1,0x0
ffffffffbfc03300	dsll32 v0,v0,0x0
ffffffffbfc03304	dsrl32 v0,v0,0x0
ffffffffbfc03308	daddu v1,v1,v0
ffffffffbfc0330c	sb a1,0x0(v1)
ffffffffbfc03310	jr ra
ffffffffbfc03314	_addiu sp,sp,0x10
