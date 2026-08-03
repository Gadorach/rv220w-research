# RV220W U-Boot v1.1.0 entry=ffffffffbfc352c0 function=FUN_ffffffffbfc352c0
ffffffffbfc352c0	lui a0,0xfffc
ffffffffbfc352c4	lui v1,0x1
ffffffffbfc352c8	ori a0,a0,0x9
ffffffffbfc352cc	addu v1,v1,t9
ffffffffbfc352d0	dsll a0,a0,0x11
ffffffffbfc352d4	addiu v1,v1,-0x1be0
ffffffffbfc352d8	daddiu a0,a0,-0x7ffb
ffffffffbfc352dc	dsll a0,a0,0x1c
ffffffffbfc352e0	ld v0,0x0(a0)
ffffffffbfc352e4	lw t9,0x10(v1)
ffffffffbfc352e8	li a1,-0x2
ffffffffbfc352ec	addiu t9,t9,0x5288
ffffffffbfc352f0	jr t9
ffffffffbfc352f4	_and a1,v0,a1
