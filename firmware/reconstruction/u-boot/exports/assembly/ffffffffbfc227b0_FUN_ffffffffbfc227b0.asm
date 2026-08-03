# RV220W U-Boot v1.1.0 entry=ffffffffbfc227b0 function=FUN_ffffffffbfc227b0
ffffffffbfc227b0	addiu sp,sp,-0x10
ffffffffbfc227b4	sd gp,0x0(sp)
ffffffffbfc227b8	lui gp,0x2
ffffffffbfc227bc	sd ra,0x8(sp)
ffffffffbfc227c0	addu gp,gp,t9
ffffffffbfc227c4	addiu gp,gp,0xf30
ffffffffbfc227c8	lw a0,0x14(gp)
ffffffffbfc227cc	lw t9,0x92c(gp)
ffffffffbfc227d0	jalr t9
ffffffffbfc227d4	_addiu a0,a0,0x1060
ffffffffbfc227d8	lw v0,0x918(gp)
ffffffffbfc227dc	ld ra,0x8(sp)
ffffffffbfc227e0	ld gp,0x0(sp)
ffffffffbfc227e4	addiu sp,sp,0x10
ffffffffbfc227e8	jr ra
ffffffffbfc227ec	_sw zero,0x0(v0)
