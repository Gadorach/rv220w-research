# RV220W U-Boot v1.1.0 entry=ffffffffbfc111e8 function=FUN_ffffffffbfc111e8
ffffffffbfc111e8	lui a1,0x3
ffffffffbfc111ec	addu a1,a1,t9
ffffffffbfc111f0	addiu a1,a1,0x24f8
ffffffffbfc111f4	lw v0,0x14(a1)
ffffffffbfc111f8	b 0xffffffffbfc11224
ffffffffbfc111fc	_lw v1,0x4aa0(v0)
ffffffffbfc11200	lw v0,0x4(v1)
ffffffffbfc11204	slt v0,a0,v0
ffffffffbfc11208	bne v0,zero,0xffffffffbfc11220
ffffffffbfc1120c	_nop
ffffffffbfc11210	lw v0,0x8(v1)
ffffffffbfc11214	slt v0,v0,a0
ffffffffbfc11218	beq v0,zero,0xffffffffbfc1122c
ffffffffbfc1121c	_nop
ffffffffbfc11220	lw v1,0x0(v1)
ffffffffbfc11224	bne v1,zero,0xffffffffbfc11200
ffffffffbfc11228	_nop
ffffffffbfc1122c	jr ra
ffffffffbfc11230	_daddu v0,v1,zero
