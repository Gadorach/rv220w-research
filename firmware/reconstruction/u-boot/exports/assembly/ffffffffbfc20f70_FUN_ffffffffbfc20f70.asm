# RV220W U-Boot v1.1.0 entry=ffffffffbfc20f70 function=FUN_ffffffffbfc20f70
ffffffffbfc20f70	lw v1,0x20(k0)
ffffffffbfc20f74	lui a1,0x2
ffffffffbfc20f78	addu a1,a1,t9
ffffffffbfc20f7c	addiu a1,a1,0x2770
ffffffffbfc20f80	lw v0,0x56c(a1)
ffffffffbfc20f84	beq v1,zero,0xffffffffbfc20f9c
ffffffffbfc20f88	_addu v0,a0,v0
ffffffffbfc20f8c	lw v0,0x1c(k0)
ffffffffbfc20f90	addu v0,v0,a0
ffffffffbfc20f94	jr ra
ffffffffbfc20f98	_lb v0,0x0(v0)
ffffffffbfc20f9c	jr ra
ffffffffbfc20fa0	_lb v0,0x0(v0)
