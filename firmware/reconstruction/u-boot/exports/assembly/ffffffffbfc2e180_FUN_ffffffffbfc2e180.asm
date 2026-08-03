# RV220W U-Boot v1.1.0 entry=ffffffffbfc2e180 function=FUN_ffffffffbfc2e180
ffffffffbfc2e180	sync 0x0
ffffffffbfc2e184	li a0,0x21
ffffffffbfc2e188	li a1,0x8
ffffffffbfc2e18c	dmfc0 a2,cop0_reg9.7
ffffffffbfc2e190	ori t0,a2,0x2000
ffffffffbfc2e194	dmtc0 t0,cop0_reg9.7
ffffffffbfc2e198	lui a3,0x8001
ffffffffbfc2e19c	ori a3,a3,0x4f00
ffffffffbfc2e1a0	dsll32 a3,a3,0x0
ffffffffbfc2e1a4	ori a3,a3,0x18
ffffffffbfc2e1a8	lui t4,0x8001
ffffffffbfc2e1ac	ori t4,t4,0x4f00
ffffffffbfc2e1b0	dsll32 t4,t4,0x0
ffffffffbfc2e1b4	ori t4,t4,0x338
ffffffffbfc2e1b8	li t2,0x24
ffffffffbfc2e1bc	li t3,0x28
ffffffffbfc2e1c0	li v0,0x0
ffffffffbfc2e1c4	nop
ffffffffbfc2e1c8	nop
ffffffffbfc2e1cc	nop
ffffffffbfc2e1d0	nop
ffffffffbfc2e1d4	nop
ffffffffbfc2e1d8	nop
ffffffffbfc2e1dc	nop
ffffffffbfc2e1e0	nop
ffffffffbfc2e1e4	nop
ffffffffbfc2e1e8	nop
ffffffffbfc2e1ec	nop
ffffffffbfc2e1f0	nop
ffffffffbfc2e1f4	nop
ffffffffbfc2e1f8	nop
ffffffffbfc2e1fc	nop
ffffffffbfc2e200	beq v0,t3,0xffffffffbfc2e248
ffffffffbfc2e204	_li t1,0x0
ffffffffbfc2e208	ld t0,0x0(t4)
ffffffffbfc2e20c	nop
ffffffffbfc2e210	ddivu t0,t2
ffffffffbfc2e214	nop
ffffffffbfc2e218	mfhi t0
ffffffffbfc2e21c	nop
ffffffffbfc2e220	dsub t0,t0,a0
ffffffffbfc2e224	nop
ffffffffbfc2e228	movz t1,a1,t0
ffffffffbfc2e22c	nop
ffffffffbfc2e230	nop
ffffffffbfc2e234	nop
ffffffffbfc2e238	sd t1,0x0(a3)
ffffffffbfc2e23c	nop
ffffffffbfc2e240	beq t1,zero,0xffffffffbfc2e200
ffffffffbfc2e244	_addi v0,v0,0x1
ffffffffbfc2e248	sd zero,0x0(a3)
ffffffffbfc2e24c	jr ra
ffffffffbfc2e250	_dmtc0 a2,cop0_reg9.7
