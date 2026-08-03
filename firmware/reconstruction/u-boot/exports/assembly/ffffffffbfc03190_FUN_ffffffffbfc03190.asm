# RV220W U-Boot v1.1.0 entry=ffffffffbfc03190 function=FUN_ffffffffbfc03190
ffffffffbfc03190	dmfc0 v1,cop0_reg9.6
ffffffffbfc03194	dadd v0,v1,zero
ffffffffbfc03198	dsrl32 v0,v0,0x0
ffffffffbfc0319c	dsll32 v1,v1,0x0
ffffffffbfc031a0	dsrl32 v1,v1,0x0
ffffffffbfc031a4	dext v1,v1,0x0,0x20
ffffffffbfc031a8	dsll32 v0,v0,0x0
ffffffffbfc031ac	jr ra
ffffffffbfc031b0	_daddu v0,v0,v1
