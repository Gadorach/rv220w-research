# RV220W U-Boot v1.1.0 entry=ffffffffbfc231f4 function=FUN_ffffffffbfc231f4
ffffffffbfc231f4	daddu v1,a0,zero
ffffffffbfc231f8	lb v0,0x0(v1)
ffffffffbfc231fc	bne v0,zero,0xffffffffbfc231f8
ffffffffbfc23200	_addiu v1,v1,0x1
ffffffffbfc23204	addiu v1,v1,-0x1
ffffffffbfc23208	jr ra
ffffffffbfc2320c	_subu v0,v1,a0
