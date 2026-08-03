# RV220W U-Boot v1.1.0 entry=ffffffffbfc3131c function=FUN_ffffffffbfc3131c
ffffffffbfc3131c	rdhwr v0,HW_RESIM31
ffffffffbfc31320	daddu v1,v0,a0
ffffffffbfc31324	rdhwr v0,HW_RESIM31
ffffffffbfc31328	sltu v0,v0,v1
ffffffffbfc3132c	bne v0,zero,0xffffffffbfc31324
ffffffffbfc31330	_nop
ffffffffbfc31334	jr ra
ffffffffbfc31338	_nop
