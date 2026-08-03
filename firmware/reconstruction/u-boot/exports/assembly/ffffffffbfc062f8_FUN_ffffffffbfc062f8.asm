# RV220W U-Boot v1.1.0 entry=ffffffffbfc062f8 function=FUN_ffffffffbfc062f8
ffffffffbfc062f8	div a0,a1
ffffffffbfc062fc	teq a1,zero
ffffffffbfc06300	mflo v0
ffffffffbfc06304	mul a1,v0,a1
ffffffffbfc06308	SPECIAL2 a0,a0,a1,0x0,0x2b
ffffffffbfc0630c	jr ra
ffffffffbfc06310	_addu v0,a0,v0
