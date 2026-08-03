# RV220W U-Boot v1.1.0 entry=ffffffffbfc111b4 function=FUN_ffffffffbfc111b4
ffffffffbfc111b4	lui a1,0x3
ffffffffbfc111b8	addu a1,a1,t9
ffffffffbfc111bc	addiu a1,a1,0x252c
ffffffffbfc111c0	lw v0,0x14(a1)
ffffffffbfc111c4	b 0xffffffffbfc111d0
ffffffffbfc111c8	_addiu v0,v0,0x4aa0
ffffffffbfc111cc	daddu v0,v1,zero
ffffffffbfc111d0	lw v1,0x0(v0)
ffffffffbfc111d4	bne v1,zero,0xffffffffbfc111cc
ffffffffbfc111d8	_nop
ffffffffbfc111dc	sw zero,0x0(a0)
ffffffffbfc111e0	jr ra
ffffffffbfc111e4	_sw a0,0x0(v0)
