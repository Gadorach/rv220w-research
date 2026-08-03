# RV220W U-Boot v1.1.0 entry=ffffffffbfc525b8 function=FUN_ffffffffbfc525b8
ffffffffbfc525b8	addiu sp,sp,-0x10
ffffffffbfc525bc	sd gp,0x0(sp)
ffffffffbfc525c0	lui gp,0x0
ffffffffbfc525c4	sd ra,0x8(sp)
ffffffffbfc525c8	addu gp,gp,t9
ffffffffbfc525cc	addiu gp,gp,0x3668
ffffffffbfc525d0	lw a0,0x8(gp)
ffffffffbfc525d4	lw t9,0x1b4(gp)
ffffffffbfc525d8	jalr t9
ffffffffbfc525dc	_addiu a0,a0,0x4e58
ffffffffbfc525e0	lw t9,0x148(gp)
ffffffffbfc525e4	jalr t9
ffffffffbfc525e8	_nop
ffffffffbfc525ec	li v1,0x1
ffffffffbfc525f0	bgez v0,0xffffffffbfc52608
ffffffffbfc525f4	_lw t9,0x1b4(gp)
ffffffffbfc525f8	lw a0,0x8(gp)
ffffffffbfc525fc	jalr t9
ffffffffbfc52600	_addiu a0,a0,0x4e80
ffffffffbfc52604	clear v1
ffffffffbfc52608	ld ra,0x8(sp)
ffffffffbfc5260c	daddu v0,v1,zero
ffffffffbfc52610	ld gp,0x0(sp)
ffffffffbfc52614	jr ra
ffffffffbfc52618	_addiu sp,sp,0x10
