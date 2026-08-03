# RV220W U-Boot v1.1.0 entry=ffffffffbfc03264 function=FUN_ffffffffbfc03264
ffffffffbfc03264	lui a1,0x4
ffffffffbfc03268	li v1,-0x1
ffffffffbfc0326c	addu a1,a1,t9
ffffffffbfc03270	addiu a1,a1,0x47c
ffffffffbfc03274	lw v0,0x2dc(a1)
ffffffffbfc03278	lw t9,0x540(a1)
ffffffffbfc0327c	sw a0,0x0(v0)
ffffffffbfc03280	lw v0,0x938(a1)
ffffffffbfc03284	sw v1,0x0(v0)
ffffffffbfc03288	lw v0,0x418(a1)
ffffffffbfc0328c	jr t9
ffffffffbfc03290	_sw zero,0x0(v0)
