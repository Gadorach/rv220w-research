# RV220W U-Boot v1.1.0 entry=ffffffffbfc29b2c function=FUN_ffffffffbfc29b2c
ffffffffbfc29b2c	rdhwr v0,HW_RESIM31
ffffffffbfc29b30	daddu v1,v0,a0
ffffffffbfc29b34	rdhwr v0,HW_RESIM31
ffffffffbfc29b38	sltu v0,v0,v1
ffffffffbfc29b3c	bne v0,zero,0xffffffffbfc29b34
ffffffffbfc29b40	_nop
ffffffffbfc29b44	jr ra
ffffffffbfc29b48	_nop
