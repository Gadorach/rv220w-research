# RV220W U-Boot v1.1.0 entry=ffffffffbfc0e978 function=FUN_ffffffffbfc0e978
ffffffffbfc0e978	lui v1,0x3
ffffffffbfc0e97c	daddu a2,a1,zero
ffffffffbfc0e980	addu v1,v1,t9
ffffffffbfc0e984	daddu a1,a0,zero
ffffffffbfc0e988	addiu v1,v1,0x4d68
ffffffffbfc0e98c	lw v0,0x14(v1)
ffffffffbfc0e990	lw a0,0x4a78(v0)
ffffffffbfc0e994	beq a0,zero,0xffffffffbfc0e9a8
ffffffffbfc0e998	_li v0,-0x1
ffffffffbfc0e99c	lw t9,0x24(a0)
ffffffffbfc0e9a0	jr t9
ffffffffbfc0e9a4	_nop
ffffffffbfc0e9a8	jr ra
ffffffffbfc0e9ac	_nop
