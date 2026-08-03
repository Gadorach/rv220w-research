# RV220W U-Boot v1.1.0 entry=ffffffffbfc18d6c function=do_bootp
ffffffffbfc18d6c	lui v1,0x3
ffffffffbfc18d70	daddu a1,a0,zero
ffffffffbfc18d74	addu v1,v1,t9
ffffffffbfc18d78	addiu v1,v1,-0x568c
ffffffffbfc18d7c	lw t9,0x20(v1)
ffffffffbfc18d80	addiu t9,t9,-0x7540
ffffffffbfc18d84	jr t9
ffffffffbfc18d88	_clear a0
