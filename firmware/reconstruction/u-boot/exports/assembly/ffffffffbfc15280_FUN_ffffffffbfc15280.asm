# RV220W U-Boot v1.1.0 entry=ffffffffbfc15280 function=FUN_ffffffffbfc15280
ffffffffbfc15280	seb a0,a0
ffffffffbfc15284	li v1,-0x41
ffffffffbfc15288	andi v0,a0,0xff
ffffffffbfc1528c	and a1,a0,v1
ffffffffbfc15290	andi a2,v0,0x7f
ffffffffbfc15294	li v1,0x40
ffffffffbfc15298	andi v0,v0,0x60
ffffffffbfc1529c	beq v0,v1,0xffffffffbfc152b4
ffffffffbfc152a0	_nop
ffffffffbfc152a4	li v0,0x3f
ffffffffbfc152a8	beq a2,v0,0xffffffffbfc152b4
ffffffffbfc152ac	_ori a1,a0,0x40
ffffffffbfc152b0	daddu a1,a0,zero
ffffffffbfc152b4	jr ra
ffffffffbfc152b8	_daddu v0,a1,zero
