# RV220W U-Boot v1.1.0 entry=ffffffffbfc2f844 function=FUN_ffffffffbfc2f844
ffffffffbfc2f844	sd a1,0x0(a0)
ffffffffbfc2f848	lui v0,0x80
ffffffffbfc2f84c	dsrl32 a0,a0,0x8
ffffffffbfc2f850	ori v0,v0,0x118
ffffffffbfc2f854	bne a0,v0,0xffffffffbfc2f86c
ffffffffbfc2f858	_lui v0,0xfff0
ffffffffbfc2f85c	ori v0,v0,0x23
ffffffffbfc2f860	dsll32 v0,v0,0xb
ffffffffbfc2f864	ori v0,v0,0xf8
ffffffffbfc2f868	ld v0,0x0(v0)
ffffffffbfc2f86c	jr ra
ffffffffbfc2f870	_nop
