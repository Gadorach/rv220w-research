# RV220W U-Boot v1.1.0 entry=ffffffffbfc27b90 function=FUN_ffffffffbfc27b90
ffffffffbfc27b90	sll v0,a1,0x3
ffffffffbfc27b94	sll a1,a1,0x4
ffffffffbfc27b98	addu v0,a0,v0
ffffffffbfc27b9c	divu v0,a1
ffffffffbfc27ba0	teq a1,zero
ffffffffbfc27ba4	mflo v0
ffffffffbfc27ba8	jr ra
ffffffffbfc27bac	_andi v0,v0,0xffff
