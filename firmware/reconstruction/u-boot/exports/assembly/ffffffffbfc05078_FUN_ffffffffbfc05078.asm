# RV220W U-Boot v1.1.0 entry=ffffffffbfc05078 function=FUN_ffffffffbfc05078
ffffffffbfc05078	lui t2,0x4
ffffffffbfc0507c	daddu a3,a0,zero
ffffffffbfc05080	addu t2,t2,t9
ffffffffbfc05084	daddu t0,a1,zero
ffffffffbfc05088	addiu t2,t2,-0x1998
ffffffffbfc0508c	dmfc0 v1,cop0_reg11.7
ffffffffbfc05090	dadd v0,v1,zero
ffffffffbfc05094	dsrl32 v0,v0,0x0
ffffffffbfc05098	dsll32 v1,v1,0x0
ffffffffbfc0509c	dsrl32 v1,v1,0x0
ffffffffbfc050a0	dsll32 v0,v0,0x0
ffffffffbfc050a4	dext v1,v1,0x0,0x20
ffffffffbfc050a8	or v0,v0,v1
ffffffffbfc050ac	daddu a1,a3,zero
ffffffffbfc050b0	lw a0,0x10(t2)
ffffffffbfc050b4	and v0,v0,a2
ffffffffbfc050b8	lw t1,0x14(t2)
ffffffffbfc050bc	xor a2,v0,t0
ffffffffbfc050c0	beq a2,zero,0xffffffffbfc050dc
ffffffffbfc050c4	_addiu a0,a0,0x7fc0
ffffffffbfc050c8	lw v0,0x4800(t1)
ffffffffbfc050cc	lw t9,0x92c(t2)
ffffffffbfc050d0	addiu v0,v0,0x1
ffffffffbfc050d4	jr t9
ffffffffbfc050d8	_sw v0,0x4800(t1)
ffffffffbfc050dc	jr ra
ffffffffbfc050e0	_nop
