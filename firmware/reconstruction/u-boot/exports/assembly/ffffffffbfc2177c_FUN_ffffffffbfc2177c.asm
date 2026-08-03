# RV220W U-Boot v1.1.0 entry=ffffffffbfc2177c function=FUN_ffffffffbfc2177c
ffffffffbfc2177c	lui a3,0x2
ffffffffbfc21780	ori v0,zero,0xffff
ffffffffbfc21784	addu a3,a3,t9
ffffffffbfc21788	addiu a3,a3,0x1f64
ffffffffbfc2178c	lw a1,0x8e4(a3)
ffffffffbfc21790	lw v1,0x8(a1)
ffffffffbfc21794	beq v1,v0,0xffffffffbfc217c8
ffffffffbfc21798	_clear a2
ffffffffbfc2179c	lw v1,0xc(a1)
ffffffffbfc217a0	sltu v0,a0,v1
ffffffffbfc217a4	bne v0,zero,0xffffffffbfc217c8
ffffffffbfc217a8	_nop
ffffffffbfc217ac	lw v0,0x0(a1)
ffffffffbfc217b0	addu v0,v1,v0
ffffffffbfc217b4	addiu v0,v0,-0x1
ffffffffbfc217b8	sltu v0,v0,a0
ffffffffbfc217bc	bne v0,zero,0xffffffffbfc217c8
ffffffffbfc217c0	_nop
ffffffffbfc217c4	daddu a2,a1,zero
ffffffffbfc217c8	jr ra
ffffffffbfc217cc	_daddu v0,a2,zero
