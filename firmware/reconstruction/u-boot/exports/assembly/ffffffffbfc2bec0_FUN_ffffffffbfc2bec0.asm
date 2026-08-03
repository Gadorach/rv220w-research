# RV220W U-Boot v1.1.0 entry=ffffffffbfc2bec0 function=FUN_ffffffffbfc2bec0
ffffffffbfc2bec0	andi a0,a0,0xffff
ffffffffbfc2bec4	andi v0,a0,0xff
ffffffffbfc2bec8	srl a0,a0,0x8
ffffffffbfc2becc	sll v0,v0,0x8
ffffffffbfc2bed0	jr ra
ffffffffbfc2bed4	_or v0,v0,a0
