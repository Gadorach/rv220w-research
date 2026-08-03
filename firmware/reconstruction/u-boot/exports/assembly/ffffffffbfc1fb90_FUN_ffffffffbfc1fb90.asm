# RV220W U-Boot v1.1.0 entry=ffffffffbfc1fb90 function=FUN_ffffffffbfc1fb90
ffffffffbfc1fb90	lui a3,0x2
ffffffffbfc1fb94	daddu a1,k0,zero
ffffffffbfc1fb98	addu a3,a3,t9
ffffffffbfc1fb9c	addiu a3,a3,0x3b50
ffffffffbfc1fba0	lw v0,0x14(a3)
ffffffffbfc1fba4	addiu a0,v0,0x32b0
ffffffffbfc1fba8	lw v0,0x14(a3)
ffffffffbfc1fbac	addiu a2,v0,0x36b0
ffffffffbfc1fbb0	lw v0,0x0(a0)
ffffffffbfc1fbb4	lw v1,0x18(a1)
ffffffffbfc1fbb8	addu v0,v0,v1
ffffffffbfc1fbbc	sw v0,0x0(a0)
ffffffffbfc1fbc0	addiu a0,a0,0x4
ffffffffbfc1fbc4	bne a0,a2,0xffffffffbfc1fbb0
ffffffffbfc1fbc8	_nop
ffffffffbfc1fbcc	jr ra
ffffffffbfc1fbd0	_nop
