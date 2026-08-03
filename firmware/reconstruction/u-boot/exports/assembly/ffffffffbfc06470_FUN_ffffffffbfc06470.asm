# RV220W U-Boot v1.1.0 entry=ffffffffbfc06470 function=FUN_ffffffffbfc06470
ffffffffbfc06470	lui v1,0x4
ffffffffbfc06474	andi a0,a0,0xff
ffffffffbfc06478	addu v1,v1,t9
ffffffffbfc0647c	daddu a1,a0,zero
ffffffffbfc06480	addiu v1,v1,-0x2d90
ffffffffbfc06484	lw t9,0x560(v1)
ffffffffbfc06488	jr t9
ffffffffbfc0648c	_li a0,0x60
