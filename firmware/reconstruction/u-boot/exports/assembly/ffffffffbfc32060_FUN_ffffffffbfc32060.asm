# RV220W U-Boot v1.1.0 entry=ffffffffbfc32060 function=FUN_ffffffffbfc32060
ffffffffbfc32060	lui a1,0x1
ffffffffbfc32064	sltiu v0,a0,0xa
ffffffffbfc32068	addu a1,a1,t9
ffffffffbfc3206c	beq v0,zero,0xffffffffbfc320a0
ffffffffbfc32070	_addiu a1,a1,0x1680
ffffffffbfc32074	lw v1,0x10(a1)
ffffffffbfc32078	sll v0,a0,0x2
ffffffffbfc3207c	addiu v1,v1,0x6cd0
ffffffffbfc32080	addu v0,v0,v1
ffffffffbfc32084	lw v0,0x0(v0)
ffffffffbfc32088	addu v0,v0,a1
ffffffffbfc3208c	jr v0
ffffffffbfc32090	_nop
ffffffffbfc320a0	lw v0,0x10(a1)
ffffffffbfc320a4	jr ra
ffffffffbfc320a8	_addiu v0,v0,0x7590
