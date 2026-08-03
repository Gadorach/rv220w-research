# RV220W U-Boot v1.1.0 entry=ffffffffbfc02ed0 function=FUN_ffffffffbfc02ed0
ffffffffbfc02ed0	addiu sp,sp,-0x20
ffffffffbfc02ed4	sd gp,0x8(sp)
ffffffffbfc02ed8	lui gp,0x4
ffffffffbfc02edc	sd ra,0x10(sp)
ffffffffbfc02ee0	addu gp,gp,t9
ffffffffbfc02ee4	sd s0,0x0(sp)
ffffffffbfc02ee8	addiu gp,gp,0x810
ffffffffbfc02eec	lw t9,0xc(gp)
ffffffffbfc02ef0	addiu t9,t9,0x2e9c
ffffffffbfc02ef4	jalr t9
ffffffffbfc02ef8	_daddu s0,a0,zero
ffffffffbfc02efc	ld ra,0x10(sp)
ffffffffbfc02f00	dsubu v0,v0,s0
ffffffffbfc02f04	ld gp,0x8(sp)
ffffffffbfc02f08	ld s0,0x0(sp)
ffffffffbfc02f0c	jr ra
ffffffffbfc02f10	_addiu sp,sp,0x20
