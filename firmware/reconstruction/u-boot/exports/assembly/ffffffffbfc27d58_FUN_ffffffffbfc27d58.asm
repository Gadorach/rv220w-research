# RV220W U-Boot v1.1.0 entry=ffffffffbfc27d58 function=FUN_ffffffffbfc27d58
ffffffffbfc27d58	lw v0,0x38(k0)
ffffffffbfc27d5c	lui v1,0xfff0
ffffffffbfc27d60	ori v1,v1,0x23
ffffffffbfc27d64	dsll32 v1,v1,0xb
ffffffffbfc27d68	sll v0,v0,0xa
ffffffffbfc27d6c	ori v1,v1,0x828
ffffffffbfc27d70	daddu v0,v0,v1
ffffffffbfc27d74	ld v0,0x0(v0)
ffffffffbfc27d78	dext v0,v0,0x0,0x1
ffffffffbfc27d7c	jr ra
ffffffffbfc27d80	_andi v0,v0,0x1
