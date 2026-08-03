# RV220W U-Boot v1.1.0 entry=ffffffffbfc0def0 function=FUN_ffffffffbfc0def0
ffffffffbfc0def0	addiu sp,sp,-0x20
ffffffffbfc0def4	slt v0,a2,a1
ffffffffbfc0def8	sd gp,0x8(sp)
ffffffffbfc0defc	lui gp,0x3
ffffffffbfc0df00	addu gp,gp,t9
ffffffffbfc0df04	daddu a3,a1,zero
ffffffffbfc0df08	addiu gp,gp,0x57f0
ffffffffbfc0df0c	daddu v1,a2,zero
ffffffffbfc0df10	sd s0,0x0(sp)
ffffffffbfc0df14	daddu s0,a1,zero
ffffffffbfc0df18	sd ra,0x10(sp)
ffffffffbfc0df1c	daddu a1,a0,zero
ffffffffbfc0df20	lw a0,0x14(gp)
ffffffffbfc0df24	lw t9,0x92c(gp)
ffffffffbfc0df28	bne v0,zero,0xffffffffbfc0df3c
ffffffffbfc0df2c	_addiu a0,a0,-0x5a88
ffffffffbfc0df30	jalr t9
ffffffffbfc0df34	_nop
ffffffffbfc0df38	addiu v1,s0,-0x1
ffffffffbfc0df3c	ld ra,0x10(sp)
ffffffffbfc0df40	daddu v0,v1,zero
ffffffffbfc0df44	ld gp,0x8(sp)
ffffffffbfc0df48	ld s0,0x0(sp)
ffffffffbfc0df4c	jr ra
ffffffffbfc0df50	_addiu sp,sp,0x20
