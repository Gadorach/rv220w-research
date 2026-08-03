# RV220W U-Boot v1.1.0 entry=ffffffffbfc03148 function=FUN_ffffffffbfc03148
ffffffffbfc03148	dmfc0 v1,cop0_reg11.7
ffffffffbfc0314c	dadd v0,v1,zero
ffffffffbfc03150	dsrl32 v0,v0,0x0
ffffffffbfc03154	dsll32 v1,v1,0x0
ffffffffbfc03158	dsrl32 v1,v1,0x0
ffffffffbfc0315c	dext v1,v1,0x0,0x20
ffffffffbfc03160	dsll32 v0,v0,0x0
ffffffffbfc03164	jr ra
ffffffffbfc03168	_daddu v0,v0,v1
