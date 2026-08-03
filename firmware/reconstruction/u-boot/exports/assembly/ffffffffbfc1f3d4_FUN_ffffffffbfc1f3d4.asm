# RV220W U-Boot v1.1.0 entry=ffffffffbfc1f3d4 function=FUN_ffffffffbfc1f3d4
ffffffffbfc1f3d4	lui a2,0x2
ffffffffbfc1f3d8	sll v1,a0,0x2
ffffffffbfc1f3dc	addu a2,a2,t9
ffffffffbfc1f3e0	slti a0,a0,0x3
ffffffffbfc1f3e4	addiu a2,a2,0x430c
ffffffffbfc1f3e8	lw v0,0x318(a2)
ffffffffbfc1f3ec	beq a0,zero,0xffffffffbfc1f404
ffffffffbfc1f3f0	_addu v0,v1,v0
ffffffffbfc1f3f4	lw v0,0x0(v0)
ffffffffbfc1f3f8	lw t9,0x1c(v0)
ffffffffbfc1f3fc	jr t9
ffffffffbfc1f400	_daddu a0,a1,zero
ffffffffbfc1f404	jr ra
ffffffffbfc1f408	_nop
