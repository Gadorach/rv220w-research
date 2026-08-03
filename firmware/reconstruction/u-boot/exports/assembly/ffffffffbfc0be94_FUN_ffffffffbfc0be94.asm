# RV220W U-Boot v1.1.0 entry=ffffffffbfc0be94 function=FUN_ffffffffbfc0be94
ffffffffbfc0be94	lui v1,0x3
ffffffffbfc0be98	daddu a2,a0,zero
ffffffffbfc0be9c	addu v1,v1,t9
ffffffffbfc0bea0	daddu a0,a1,zero
ffffffffbfc0bea4	addiu v1,v1,0x784c
ffffffffbfc0bea8	dext a3,a2,0x10,0x8
ffffffffbfc0beac	lw a1,0x14(v1)
ffffffffbfc0beb0	dext t0,a2,0x8,0x8
ffffffffbfc0beb4	lw t9,0x2c4(v1)
ffffffffbfc0beb8	andi t1,a2,0xff
ffffffffbfc0bebc	addiu a1,a1,-0x5ec0
ffffffffbfc0bec0	jr t9
ffffffffbfc0bec4	_srl a2,a2,0x18
