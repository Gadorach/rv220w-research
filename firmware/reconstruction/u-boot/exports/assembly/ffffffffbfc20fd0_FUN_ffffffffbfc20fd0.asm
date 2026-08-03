# RV220W U-Boot v1.1.0 entry=ffffffffbfc20fd0 function=FUN_ffffffffbfc20fd0
ffffffffbfc20fd0	lw a1,0x20(k0)
ffffffffbfc20fd4	addiu sp,sp,-0x10
ffffffffbfc20fd8	sd gp,0x0(sp)
ffffffffbfc20fdc	lui gp,0x2
ffffffffbfc20fe0	sd ra,0x8(sp)
ffffffffbfc20fe4	addu gp,gp,t9
ffffffffbfc20fe8	addiu gp,gp,0x2710
ffffffffbfc20fec	lw v1,0x56c(gp)
ffffffffbfc20ff0	lw t9,0x64c(gp)
ffffffffbfc20ff4	beq a1,zero,0xffffffffbfc2100c
ffffffffbfc20ff8	_addu v0,a0,v1
ffffffffbfc20ffc	jalr t9
ffffffffbfc21000	_nop
ffffffffbfc21004	b 0xffffffffbfc21014
ffffffffbfc21008	_ld ra,0x8(sp)
ffffffffbfc2100c	lbu v0,0x0(v0)
ffffffffbfc21010	ld ra,0x8(sp)
ffffffffbfc21014	seb v0,v0
ffffffffbfc21018	ld gp,0x0(sp)
ffffffffbfc2101c	jr ra
ffffffffbfc21020	_addiu sp,sp,0x10
