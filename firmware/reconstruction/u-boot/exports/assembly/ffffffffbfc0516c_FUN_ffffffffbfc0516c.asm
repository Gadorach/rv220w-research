# RV220W U-Boot v1.1.0 entry=ffffffffbfc0516c function=FUN_ffffffffbfc0516c
ffffffffbfc0516c	addiu sp,sp,-0x10
ffffffffbfc05170	andi a0,a0,0xff
ffffffffbfc05174	sd gp,0x0(sp)
ffffffffbfc05178	lui gp,0x4
ffffffffbfc0517c	addu gp,gp,t9
ffffffffbfc05180	sd ra,0x8(sp)
ffffffffbfc05184	addiu gp,gp,-0x1a8c
ffffffffbfc05188	lw t9,0x7fc(gp)
ffffffffbfc0518c	jalr t9
ffffffffbfc05190	_clear a1
ffffffffbfc05194	ld ra,0x8(sp)
ffffffffbfc05198	srl v0,v0,0x1f
ffffffffbfc0519c	ld gp,0x0(sp)
ffffffffbfc051a0	jr ra
ffffffffbfc051a4	_addiu sp,sp,0x10
