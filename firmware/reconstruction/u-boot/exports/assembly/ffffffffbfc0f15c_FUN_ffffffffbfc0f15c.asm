# RV220W U-Boot v1.1.0 entry=ffffffffbfc0f15c function=FUN_ffffffffbfc0f15c
ffffffffbfc0f15c	lbu v0,0xa0c(a0)
ffffffffbfc0f160	lw v1,0xc(a0)
ffffffffbfc0f164	mul a0,a1,v0
ffffffffbfc0f168	addu a1,a0,v1
ffffffffbfc0f16c	addu a1,a1,v0
ffffffffbfc0f170	jr ra
ffffffffbfc0f174	_lbu v0,-0x1(a1)
