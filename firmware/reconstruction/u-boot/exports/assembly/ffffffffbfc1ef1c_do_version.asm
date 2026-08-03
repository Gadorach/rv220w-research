# RV220W U-Boot v1.1.0 entry=ffffffffbfc1ef1c function=do_version
ffffffffbfc1ef1c	addiu sp,sp,-0x10
ffffffffbfc1ef20	sd gp,0x0(sp)
ffffffffbfc1ef24	lui gp,0x2
ffffffffbfc1ef28	sd ra,0x8(sp)
ffffffffbfc1ef2c	addu gp,gp,t9
ffffffffbfc1ef30	addiu gp,gp,0x47c4
ffffffffbfc1ef34	lw a0,0x14(gp)
ffffffffbfc1ef38	lw t9,0x92c(gp)
ffffffffbfc1ef3c	lw a1,0x950(gp)
ffffffffbfc1ef40	jalr t9
ffffffffbfc1ef44	_addiu a0,a0,0xb70
ffffffffbfc1ef48	clear v0
ffffffffbfc1ef4c	ld ra,0x8(sp)
ffffffffbfc1ef50	ld gp,0x0(sp)
ffffffffbfc1ef54	jr ra
ffffffffbfc1ef58	_addiu sp,sp,0x10
