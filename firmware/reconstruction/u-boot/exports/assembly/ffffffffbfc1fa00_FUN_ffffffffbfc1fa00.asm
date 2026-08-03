# RV220W U-Boot v1.1.0 entry=ffffffffbfc1fa00 function=FUN_ffffffffbfc1fa00
ffffffffbfc1fa00	addiu sp,sp,-0x10
ffffffffbfc1fa04	sd gp,0x0(sp)
ffffffffbfc1fa08	lui gp,0x2
ffffffffbfc1fa0c	sd ra,0x8(sp)
ffffffffbfc1fa10	addu gp,gp,t9
ffffffffbfc1fa14	addiu gp,gp,0x3ce0
ffffffffbfc1fa18	lw v0,0x344(gp)
ffffffffbfc1fa1c	lw t9,0x870(gp)
ffffffffbfc1fa20	jalr t9
ffffffffbfc1fa24	_lw a0,0x0(v0)
ffffffffbfc1fa28	clear v0
ffffffffbfc1fa2c	ld ra,0x8(sp)
ffffffffbfc1fa30	ld gp,0x0(sp)
ffffffffbfc1fa34	jr ra
ffffffffbfc1fa38	_addiu sp,sp,0x10
