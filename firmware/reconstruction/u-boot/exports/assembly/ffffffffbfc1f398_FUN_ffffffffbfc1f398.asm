# RV220W U-Boot v1.1.0 entry=ffffffffbfc1f398 function=FUN_ffffffffbfc1f398
ffffffffbfc1f398	lui a2,0x2
ffffffffbfc1f39c	sll v1,a0,0x2
ffffffffbfc1f3a0	addu a2,a2,t9
ffffffffbfc1f3a4	slti a0,a0,0x3
ffffffffbfc1f3a8	addiu a2,a2,0x4348
ffffffffbfc1f3ac	seb a1,a1
ffffffffbfc1f3b0	lw v0,0x318(a2)
ffffffffbfc1f3b4	beq a0,zero,0xffffffffbfc1f3cc
ffffffffbfc1f3b8	_addu v0,v1,v0
ffffffffbfc1f3bc	lw v0,0x0(v0)
ffffffffbfc1f3c0	lw t9,0x18(v0)
ffffffffbfc1f3c4	jr t9
ffffffffbfc1f3c8	_daddu a0,a1,zero
ffffffffbfc1f3cc	jr ra
ffffffffbfc1f3d0	_nop
