# RV220W U-Boot v1.1.0 entry=ffffffffbfc04f74 function=FUN_ffffffffbfc04f74
ffffffffbfc04f74	lhu v1,0x44(k0)
ffffffffbfc04f78	li v0,0x2
ffffffffbfc04f7c	bne v1,v0,0xffffffffbfc04fd0
ffffffffbfc04f80	_lui v0,0x1d02
ffffffffbfc04f84	lbu v1,0x46(k0)
ffffffffbfc04f88	li v0,0x1
ffffffffbfc04f8c	bne v1,v0,0xffffffffbfc04fd0
ffffffffbfc04f90	_lui v0,0x1d02
ffffffffbfc04f94	li a2,0x20
ffffffffbfc04f98	ori a1,v0,0x3
ffffffffbfc04f9c	ori v0,v0,0x7
ffffffffbfc04fa0	lb v1,0x0(a0)
ffffffffbfc04fa4	beq v1,zero,0xffffffffbfc04fb8
ffffffffbfc04fa8	_nop
ffffffffbfc04fac	sb v1,0x0(v0)
ffffffffbfc04fb0	b 0xffffffffbfc04fbc
ffffffffbfc04fb4	_addiu a0,a0,0x1
ffffffffbfc04fb8	sb a2,0x0(v0)
ffffffffbfc04fbc	addiu v0,v0,-0x1
ffffffffbfc04fc0	bne v0,a1,0xffffffffbfc04fa0
ffffffffbfc04fc4	_nop
ffffffffbfc04fc8	jr ra
ffffffffbfc04fcc	_nop
ffffffffbfc04fd0	li a2,0x20
ffffffffbfc04fd4	ori a1,v0,0x100
ffffffffbfc04fd8	ori v0,v0,0xf8
ffffffffbfc04fdc	lb v1,0x0(a0)
ffffffffbfc04fe0	beq v1,zero,0xffffffffbfc04ff4
ffffffffbfc04fe4	_nop
ffffffffbfc04fe8	sb v1,0x0(v0)
ffffffffbfc04fec	b 0xffffffffbfc04ff8
ffffffffbfc04ff0	_addiu a0,a0,0x1
ffffffffbfc04ff4	sb a2,0x0(v0)
ffffffffbfc04ff8	addiu v0,v0,0x1
ffffffffbfc04ffc	bne v0,a1,0xffffffffbfc04fdc
ffffffffbfc05000	_nop
ffffffffbfc05004	jr ra
ffffffffbfc05008	_nop
