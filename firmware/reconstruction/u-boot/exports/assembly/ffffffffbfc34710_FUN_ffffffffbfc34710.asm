# RV220W U-Boot v1.1.0 entry=ffffffffbfc34710 function=FUN_ffffffffbfc34710
ffffffffbfc34710	rdhwr v0,HW_RESIM31
ffffffffbfc34714	daddu v1,v0,a0
ffffffffbfc34718	rdhwr v0,HW_RESIM31
ffffffffbfc3471c	sltu v0,v0,v1
ffffffffbfc34720	bne v0,zero,0xffffffffbfc34718
ffffffffbfc34724	_nop
ffffffffbfc34728	jr ra
ffffffffbfc3472c	_nop
