# RV220W U-Boot v1.1.0 entry=ffffffffbfc1f320 function=FUN_ffffffffbfc1f320
ffffffffbfc1f320	lui a1,0x2
ffffffffbfc1f324	sll v1,a0,0x2
ffffffffbfc1f328	addu a1,a1,t9
ffffffffbfc1f32c	slti a0,a0,0x3
ffffffffbfc1f330	addiu a1,a1,0x43c0
ffffffffbfc1f334	lw v0,0x318(a1)
ffffffffbfc1f338	addu v1,v1,v0
ffffffffbfc1f33c	beq a0,zero,0xffffffffbfc1f354
ffffffffbfc1f340	_li v0,-0x1
ffffffffbfc1f344	lw v0,0x0(v1)
ffffffffbfc1f348	lw t9,0x24(v0)
ffffffffbfc1f34c	jr t9
ffffffffbfc1f350	_nop
ffffffffbfc1f354	jr ra
ffffffffbfc1f358	_nop
