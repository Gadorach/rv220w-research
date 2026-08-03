# RV220W U-Boot v1.1.0 entry=ffffffffbfc306ec function=FUN_ffffffffbfc306ec
ffffffffbfc306ec	rdhwr v0,HW_RESIM31
ffffffffbfc306f0	daddu v1,v0,a0
ffffffffbfc306f4	rdhwr v0,HW_RESIM31
ffffffffbfc306f8	sltu v0,v0,v1
ffffffffbfc306fc	bne v0,zero,0xffffffffbfc306f4
ffffffffbfc30700	_nop
ffffffffbfc30704	jr ra
ffffffffbfc30708	_nop
