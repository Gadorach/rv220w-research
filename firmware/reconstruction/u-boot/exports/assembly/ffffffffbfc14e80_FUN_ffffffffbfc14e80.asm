# RV220W U-Boot v1.1.0 entry=ffffffffbfc14e80 function=FUN_ffffffffbfc14e80
ffffffffbfc14e80	lb a3,0x0(a0)
ffffffffbfc14e84	lui t0,0x3
ffffffffbfc14e88	addu t0,t0,t9
ffffffffbfc14e8c	li v1,0x2a
ffffffffbfc14e90	daddu v0,a0,zero
ffffffffbfc14e94	addiu t0,t0,-0x17a0
ffffffffbfc14e98	addiu a0,a0,0x1
ffffffffbfc14e9c	clear a1
ffffffffbfc14ea0	bne a3,v1,0xffffffffbfc14eb4
ffffffffbfc14ea4	_li a2,0x10
ffffffffbfc14ea8	lw t9,0x1d0(t0)
ffffffffbfc14eac	jr t9
ffffffffbfc14eb0	_nop
ffffffffbfc14eb4	jr ra
ffffffffbfc14eb8	_nop
