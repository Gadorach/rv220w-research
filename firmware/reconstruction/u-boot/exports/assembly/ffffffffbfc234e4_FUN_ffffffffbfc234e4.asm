# RV220W U-Boot v1.1.0 entry=ffffffffbfc234e4 function=FUN_ffffffffbfc234e4
ffffffffbfc234e4	daddu v1,a0,zero
ffffffffbfc234e8	b 0xffffffffbfc23500
ffffffffbfc234ec	_li a3,-0x1
ffffffffbfc234f0	lbu v0,0x0(a1)
ffffffffbfc234f4	addiu a1,a1,0x1
ffffffffbfc234f8	sb v0,0x0(v1)
ffffffffbfc234fc	addiu v1,v1,0x1
ffffffffbfc23500	addiu a2,a2,-0x1
ffffffffbfc23504	bne a2,a3,0xffffffffbfc234f0
ffffffffbfc23508	_daddu v0,a0,zero
ffffffffbfc2350c	jr ra
ffffffffbfc23510	_nop
