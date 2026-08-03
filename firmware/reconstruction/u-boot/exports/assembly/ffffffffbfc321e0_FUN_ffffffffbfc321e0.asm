# RV220W U-Boot v1.1.0 entry=ffffffffbfc321e0 function=FUN_ffffffffbfc321e0
ffffffffbfc321e0	li v0,0x1
ffffffffbfc321e4	beq a0,v0,0xffffffffbfc32224
ffffffffbfc321e8	_nop
ffffffffbfc321ec	slti v0,a0,0x2
ffffffffbfc321f0	beq v0,zero,0xffffffffbfc32208
ffffffffbfc321f4	_li v0,0x2
ffffffffbfc321f8	beq a0,zero,0xffffffffbfc32238
ffffffffbfc321fc	_nop
ffffffffbfc32200	b 0xffffffffbfc32238
ffffffffbfc32204	_li a1,-0x1
ffffffffbfc32208	beq a0,v0,0xffffffffbfc3222c
ffffffffbfc3220c	_nop
ffffffffbfc32210	li v0,0x3
ffffffffbfc32214	beq a0,v0,0xffffffffbfc32234
ffffffffbfc32218	_nop
ffffffffbfc3221c	b 0xffffffffbfc32238
ffffffffbfc32220	_li a1,-0x1
ffffffffbfc32224	b 0xffffffffbfc32238
ffffffffbfc32228	_addiu a1,a1,0x10
ffffffffbfc3222c	b 0xffffffffbfc32238
ffffffffbfc32230	_addiu a1,a1,0x20
ffffffffbfc32234	addiu a1,a1,0x24
ffffffffbfc32238	jr ra
ffffffffbfc3223c	_daddu v0,a1,zero
