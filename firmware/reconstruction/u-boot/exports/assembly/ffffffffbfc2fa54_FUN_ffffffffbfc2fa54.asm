# RV220W U-Boot v1.1.0 entry=ffffffffbfc2fa54 function=FUN_ffffffffbfc2fa54
ffffffffbfc2fa54	lui v0,0x80
ffffffffbfc2fa58	lui v1,0x1
ffffffffbfc2fa5c	ori v0,v0,0x128
ffffffffbfc2fa60	addu v1,v1,t9
ffffffffbfc2fa64	or v0,a0,v0
ffffffffbfc2fa68	addiu v1,v1,0x3c8c
ffffffffbfc2fa6c	dsll32 v0,v0,0x8
ffffffffbfc2fa70	ld v0,0x0(v0)
ffffffffbfc2fa74	beq v0,zero,0xffffffffbfc2fa8c
ffffffffbfc2fa78	_daddu a0,v0,zero
ffffffffbfc2fa7c	lw t9,0x10(v1)
ffffffffbfc2fa80	addiu t9,t9,-0x704
ffffffffbfc2fa84	jr t9
ffffffffbfc2fa88	_nop
ffffffffbfc2fa8c	jr ra
ffffffffbfc2fa90	_clear v0
