# RV220W U-Boot v1.1.0 entry=ffffffffbfc02e50 function=FUN_ffffffffbfc02e50
ffffffffbfc02e50	lw v0,0x24(k0)
ffffffffbfc02e54	rdhwr v1,HW_RESIM31
ffffffffbfc02e58	multu a0,v0
ffffffffbfc02e5c	mflo a1
ffffffffbfc02e60	mfhi a0
ffffffffbfc02e64	dsll32 a1,a1,0x0
ffffffffbfc02e68	dsrl32 a1,a1,0x0
ffffffffbfc02e6c	dsll32 a0,a0,0x0
ffffffffbfc02e70	or a0,a0,a1
ffffffffbfc02e74	daddu v1,v1,a0
ffffffffbfc02e78	rdhwr v0,HW_RESIM31
ffffffffbfc02e7c	sltu v0,v0,v1
ffffffffbfc02e80	bne v0,zero,0xffffffffbfc02e78
ffffffffbfc02e84	_nop
ffffffffbfc02e88	jr ra
ffffffffbfc02e8c	_nop
