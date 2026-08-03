# RV220W U-Boot v1.1.0 entry=ffffffffbfc03318 function=FUN_ffffffffbfc03318
ffffffffbfc03318	dsra32 v1,a0,0x0
ffffffffbfc0331c	bne v1,zero,0xffffffffbfc03330
ffffffffbfc03320	_sll a0,a0,0x0
ffffffffbfc03324	slti v0,a0,0x0
ffffffffbfc03328	li v1,-0x1
ffffffffbfc0332c	movz v1,zero,v0
ffffffffbfc03330	dsll32 v1,v1,0x0
ffffffffbfc03334	dsll32 a0,a0,0x0
ffffffffbfc03338	dsrl32 a0,a0,0x0
ffffffffbfc0333c	daddu v1,v1,a0
ffffffffbfc03340	lb v0,0x0(v1)
ffffffffbfc03344	jr ra
ffffffffbfc03348	_andi v0,v0,0xff
