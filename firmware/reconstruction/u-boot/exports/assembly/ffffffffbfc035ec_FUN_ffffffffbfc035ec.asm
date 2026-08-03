# RV220W U-Boot v1.1.0 entry=ffffffffbfc035ec function=FUN_ffffffffbfc035ec
ffffffffbfc035ec	addiu sp,sp,-0x10
ffffffffbfc035f0	sd gp,0x0(sp)
ffffffffbfc035f4	lui gp,0x4
ffffffffbfc035f8	sd ra,0x8(sp)
ffffffffbfc035fc	addu gp,gp,t9
ffffffffbfc03600	addiu gp,gp,0xf4
ffffffffbfc03604	lw t9,0x3e8(gp)
ffffffffbfc03608	jalr t9
ffffffffbfc0360c	_nop
ffffffffbfc03610	lui t0,0xf
ffffffffbfc03614	lhu a1,0x44(k0)
ffffffffbfc03618	daddu a0,v0,zero
ffffffffbfc0361c	lbu a2,0x46(k0)
ffffffffbfc03620	ori t0,t0,0x4240
ffffffffbfc03624	lbu a3,0x47(k0)
ffffffffbfc03628	andi a1,a1,0xffff
ffffffffbfc0362c	lw v0,0x24(k0)
ffffffffbfc03630	andi a2,a2,0xff
ffffffffbfc03634	lw t9,0x488(gp)
ffffffffbfc03638	andi a3,a3,0xff
ffffffffbfc0363c	ld gp,0x0(sp)
ffffffffbfc03640	mul t0,v0,t0
ffffffffbfc03644	ld ra,0x8(sp)
ffffffffbfc03648	jr t9
ffffffffbfc0364c	_addiu sp,sp,0x10
