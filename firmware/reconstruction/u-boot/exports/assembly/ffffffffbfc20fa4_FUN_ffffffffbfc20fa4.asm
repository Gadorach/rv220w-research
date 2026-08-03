# RV220W U-Boot v1.1.0 entry=ffffffffbfc20fa4 function=FUN_ffffffffbfc20fa4
ffffffffbfc20fa4	lw v0,0x20(k0)
ffffffffbfc20fa8	lui v1,0x2
ffffffffbfc20fac	addu v1,v1,t9
ffffffffbfc20fb0	beq v0,zero,0xffffffffbfc20fc4
ffffffffbfc20fb4	_addiu v1,v1,0x273c
ffffffffbfc20fb8	lw v0,0x1c(k0)
ffffffffbfc20fbc	jr ra
ffffffffbfc20fc0	_addu v0,v0,a0
ffffffffbfc20fc4	lw v0,0x56c(v1)
ffffffffbfc20fc8	jr ra
ffffffffbfc20fcc	_addu v0,a0,v0
