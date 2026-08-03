# RV220W U-Boot v1.1.0 entry=ffffffffbfc227f0 function=FUN_ffffffffbfc227f0
ffffffffbfc227f0	addiu sp,sp,-0x10
ffffffffbfc227f4	sd gp,0x0(sp)
ffffffffbfc227f8	lui gp,0x2
ffffffffbfc227fc	sd ra,0x8(sp)
ffffffffbfc22800	addu gp,gp,t9
ffffffffbfc22804	addiu gp,gp,0xef0
ffffffffbfc22808	lw a0,0x14(gp)
ffffffffbfc2280c	lw t9,0x92c(gp)
ffffffffbfc22810	jalr t9
ffffffffbfc22814	_addiu a0,a0,0x1070
ffffffffbfc22818	li v1,0x1
ffffffffbfc2281c	lw v0,0x918(gp)
ffffffffbfc22820	ld ra,0x8(sp)
ffffffffbfc22824	ld gp,0x0(sp)
ffffffffbfc22828	addiu sp,sp,0x10
ffffffffbfc2282c	jr ra
ffffffffbfc22830	_sw v1,0x0(v0)
