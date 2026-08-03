# RV220W U-Boot v1.1.0 entry=ffffffffbfc2bed8 function=FUN_ffffffffbfc2bed8
ffffffffbfc2bed8	srl a1,a0,0x8
ffffffffbfc2bedc	andi v1,a0,0xff00
ffffffffbfc2bee0	sll v1,v1,0x8
ffffffffbfc2bee4	andi a1,a1,0xff00
ffffffffbfc2bee8	sll v0,a0,0x18
ffffffffbfc2beec	srl a0,a0,0x18
ffffffffbfc2bef0	or v0,v0,v1
ffffffffbfc2bef4	or a0,a0,a1
ffffffffbfc2bef8	jr ra
ffffffffbfc2befc	_or v0,v0,a0
