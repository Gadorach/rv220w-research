# RV220W U-Boot v1.1.0 entry=ffffffffbfc232f0 function=FUN_ffffffffbfc232f0
ffffffffbfc232f0	b 0xffffffffbfc23310
ffffffffbfc232f4	_daddu v0,a0,zero
ffffffffbfc232f8	beq a2,a0,0xffffffffbfc23320
ffffffffbfc232fc	_nop
ffffffffbfc23300	lb a0,0x0(v1)
ffffffffbfc23304	bne a0,zero,0xffffffffbfc232f8
ffffffffbfc23308	_addiu v1,v1,0x1
ffffffffbfc2330c	addiu v0,v0,0x1
ffffffffbfc23310	lb a2,0x0(v0)
ffffffffbfc23314	bne a2,zero,0xffffffffbfc23300
ffffffffbfc23318	_daddu v1,a1,zero
ffffffffbfc2331c	clear v0
ffffffffbfc23320	jr ra
ffffffffbfc23324	_nop
