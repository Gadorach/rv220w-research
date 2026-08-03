# RV220W U-Boot v1.1.0 entry=ffffffffbfc2f874 function=FUN_ffffffffbfc2f874
ffffffffbfc2f874	srl v0,a0,0x10
ffffffffbfc2f878	andi v1,a0,0xf
ffffffffbfc2f87c	sll v0,v0,0x4
ffffffffbfc2f880	dext a0,a0,0x4,0x4
ffffffffbfc2f884	addu v0,v0,v1
ffffffffbfc2f888	sll v0,v0,0x4
ffffffffbfc2f88c	jr ra
ffffffffbfc2f890	_addu v0,v0,a0
