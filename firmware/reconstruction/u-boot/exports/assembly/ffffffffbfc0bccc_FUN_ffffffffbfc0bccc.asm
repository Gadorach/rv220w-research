# RV220W U-Boot v1.1.0 entry=ffffffffbfc0bccc function=FUN_ffffffffbfc0bccc
ffffffffbfc0bccc	b 0xffffffffbfc0bce4
ffffffffbfc0bcd0	_clear a2
ffffffffbfc0bcd4	lhu v0,0x0(a0)
ffffffffbfc0bcd8	addiu a1,a1,-0x1
ffffffffbfc0bcdc	addiu a0,a0,0x2
ffffffffbfc0bce0	addu a2,a2,v0
ffffffffbfc0bce4	bgtz a1,0xffffffffbfc0bcd4
ffffffffbfc0bce8	_srl v1,a2,0x10
ffffffffbfc0bcec	andi v0,a2,0xffff
ffffffffbfc0bcf0	addu v0,v0,v1
ffffffffbfc0bcf4	srl v1,v0,0x10
ffffffffbfc0bcf8	addu v0,v0,v1
ffffffffbfc0bcfc	jr ra
ffffffffbfc0bd00	_andi v0,v0,0xffff
