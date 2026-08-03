# RV220W U-Boot v1.1.0 entry=ffffffffbfc337c8 function=FUN_ffffffffbfc337c8
ffffffffbfc337c8	rdhwr v0,HW_RESIM31
ffffffffbfc337cc	daddu v1,v0,a0
ffffffffbfc337d0	rdhwr v0,HW_RESIM31
ffffffffbfc337d4	sltu v0,v0,v1
ffffffffbfc337d8	bne v0,zero,0xffffffffbfc337d0
ffffffffbfc337dc	_nop
ffffffffbfc337e0	jr ra
ffffffffbfc337e4	_nop
