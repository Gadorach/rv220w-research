# RV220W U-Boot v1.1.0 entry=ffffffffbfc0e920 function=FUN_ffffffffbfc0e920
ffffffffbfc0e920	addiu sp,sp,-0x20
ffffffffbfc0e924	sd gp,0x8(sp)
ffffffffbfc0e928	lui gp,0x3
ffffffffbfc0e92c	sd s0,0x0(sp)
ffffffffbfc0e930	addu gp,gp,t9
ffffffffbfc0e934	sd ra,0x10(sp)
ffffffffbfc0e938	addiu gp,gp,0x4dc0
ffffffffbfc0e93c	lw s0,0x14(gp)
ffffffffbfc0e940	lw a0,0x4a78(s0)
ffffffffbfc0e944	beq a0,zero,0xffffffffbfc0e968
ffffffffbfc0e948	_ld ra,0x10(sp)
ffffffffbfc0e94c	lw t9,0x2c(a0)
ffffffffbfc0e950	jalr t9
ffffffffbfc0e954	_nop
ffffffffbfc0e958	li v0,0x1
ffffffffbfc0e95c	lw v1,0x4a78(s0)
ffffffffbfc0e960	sw v0,0x1c(v1)
ffffffffbfc0e964	ld ra,0x10(sp)
ffffffffbfc0e968	ld gp,0x8(sp)
ffffffffbfc0e96c	ld s0,0x0(sp)
ffffffffbfc0e970	jr ra
ffffffffbfc0e974	_addiu sp,sp,0x20
