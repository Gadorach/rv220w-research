# RV220W U-Boot v1.1.0 entry=ffffffffbfc2e280 function=FUN_ffffffffbfc2e280
ffffffffbfc2e280	srl v0,a0,0x10
ffffffffbfc2e284	andi v1,a0,0xf
ffffffffbfc2e288	sll v0,v0,0x4
ffffffffbfc2e28c	dext a0,a0,0x4,0x4
ffffffffbfc2e290	addu v0,v0,v1
ffffffffbfc2e294	sll v0,v0,0x4
ffffffffbfc2e298	jr ra
ffffffffbfc2e29c	_addu v0,v0,a0
