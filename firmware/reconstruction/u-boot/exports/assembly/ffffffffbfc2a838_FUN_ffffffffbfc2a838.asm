# RV220W U-Boot v1.1.0 entry=ffffffffbfc2a838 function=FUN_ffffffffbfc2a838
ffffffffbfc2a838	lui v0,0x80
ffffffffbfc2a83c	lui v1,0x2
ffffffffbfc2a840	ori v0,v0,0x128
ffffffffbfc2a844	addu v1,v1,t9
ffffffffbfc2a848	or v0,a0,v0
ffffffffbfc2a84c	addiu v1,v1,-0x7158
ffffffffbfc2a850	dsll32 v0,v0,0x8
ffffffffbfc2a854	ld v0,0x0(v0)
ffffffffbfc2a858	beq v0,zero,0xffffffffbfc2a870
ffffffffbfc2a85c	_daddu a0,v0,zero
ffffffffbfc2a860	lw t9,0x10(v1)
ffffffffbfc2a864	addiu t9,t9,-0x581c
ffffffffbfc2a868	jr t9
ffffffffbfc2a86c	_nop
ffffffffbfc2a870	jr ra
ffffffffbfc2a874	_clear v0
