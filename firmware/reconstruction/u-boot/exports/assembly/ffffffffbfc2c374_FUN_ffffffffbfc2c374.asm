# RV220W U-Boot v1.1.0 entry=ffffffffbfc2c374 function=FUN_ffffffffbfc2c374
ffffffffbfc2c374	lui a1,0x1
ffffffffbfc2c378	addu a1,a1,t9
ffffffffbfc2c37c	addiu a1,a1,0x736c
ffffffffbfc2c380	sync 0x4
ffffffffbfc2c384	sync 0x4
ffffffffbfc2c388	lw v0,0x5e8(a1)
ffffffffbfc2c38c	dext v1,a0,0x0,0x20
ffffffffbfc2c390	ld a0,0x0(v0)
ffffffffbfc2c394	daddu a0,a0,v1
ffffffffbfc2c398	lw a0,0x0(a0)
ffffffffbfc2c39c	lw t9,0x10(a1)
ffffffffbfc2c3a0	addiu t9,t9,-0x4128
ffffffffbfc2c3a4	jr t9
ffffffffbfc2c3a8	_nop
