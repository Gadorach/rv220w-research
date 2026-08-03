# RV220W U-Boot v1.1.0 entry=ffffffffbfc27b70 function=FUN_ffffffffbfc27b70
ffffffffbfc27b70	rdhwr v0,HW_RESIM31
ffffffffbfc27b74	daddu v1,v0,a0
ffffffffbfc27b78	rdhwr v0,HW_RESIM31
ffffffffbfc27b7c	sltu v0,v0,v1
ffffffffbfc27b80	bne v0,zero,0xffffffffbfc27b78
ffffffffbfc27b84	_nop
ffffffffbfc27b88	jr ra
ffffffffbfc27b8c	_nop
