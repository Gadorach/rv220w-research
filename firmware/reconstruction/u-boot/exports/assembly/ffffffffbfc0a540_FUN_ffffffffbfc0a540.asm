# RV220W U-Boot v1.1.0 entry=ffffffffbfc0a540 function=FUN_ffffffffbfc0a540
ffffffffbfc0a540	lui a2,0x4
ffffffffbfc0a544	clear v0
ffffffffbfc0a548	addu a2,a2,t9
ffffffffbfc0a54c	addiu a2,a2,-0x6e60
ffffffffbfc0a550	lw a1,0x14(a2)
ffffffffbfc0a554	lw v1,0x4830(a1)
ffffffffbfc0a558	movz v1,a0,v1
ffffffffbfc0a55c	jr ra
ffffffffbfc0a560	_sw v1,0x4830(a1)
