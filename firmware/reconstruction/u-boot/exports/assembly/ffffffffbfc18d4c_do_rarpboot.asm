# RV220W U-Boot v1.1.0 entry=ffffffffbfc18d4c function=do_rarpboot
ffffffffbfc18d4c	lui v1,0x3
ffffffffbfc18d50	daddu a1,a0,zero
ffffffffbfc18d54	addu v1,v1,t9
ffffffffbfc18d58	addiu v1,v1,-0x566c
ffffffffbfc18d5c	lw t9,0x20(v1)
ffffffffbfc18d60	addiu t9,t9,-0x7540
ffffffffbfc18d64	jr t9
ffffffffbfc18d68	_li a0,0x1
