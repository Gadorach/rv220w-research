# RV220W U-Boot v1.1.0 entry=ffffffffbfc03100 function=FUN_ffffffffbfc03100
ffffffffbfc03100	dmfc0 v1,cop0_reg9.7
ffffffffbfc03104	dadd v0,v1,zero
ffffffffbfc03108	dsrl32 v0,v0,0x0
ffffffffbfc0310c	dsll32 v1,v1,0x0
ffffffffbfc03110	dsrl32 v1,v1,0x0
ffffffffbfc03114	dext v1,v1,0x0,0x20
ffffffffbfc03118	dsll32 v0,v0,0x0
ffffffffbfc0311c	jr ra
ffffffffbfc03120	_daddu v0,v0,v1
