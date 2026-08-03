# RV220W U-Boot v1.1.0 entry=ffffffffbfc00ba8 function=FUN_ffffffffbfc00ba8
ffffffffbfc00ba8	addiu sp,sp,-0x20
ffffffffbfc00bac	sd gp,0x10(sp)
ffffffffbfc00bb0	lui gp,0x4
ffffffffbfc00bb4	sd s0,0x0(sp)
ffffffffbfc00bb8	addu gp,gp,t9
ffffffffbfc00bbc	sd s1,0x8(sp)
ffffffffbfc00bc0	addiu gp,gp,0x2b38
ffffffffbfc00bc4	lui s0,0xfff0
ffffffffbfc00bc8	daddu s1,a0,zero
ffffffffbfc00bcc	lw t9,0xc(gp)
ffffffffbfc00bd0	ori s0,s0,0x23
ffffffffbfc00bd4	dsll32 s0,s0,0xb
ffffffffbfc00bd8	dext v0,s1,0x3,0x8
ffffffffbfc00bdc	sd ra,0x18(sp)
ffffffffbfc00be0	ori a0,s0,0x1500
ffffffffbfc00be4	addiu t9,t9,0xb78
ffffffffbfc00be8	jalr t9
ffffffffbfc00bec	_ori a1,v0,0x1000
ffffffffbfc00bf0	ori s0,s0,0x1500
ffffffffbfc00bf4	ld v0,0x0(s0)
ffffffffbfc00bf8	beq v0,zero,0xffffffffbfc00c08
ffffffffbfc00bfc	_nop
ffffffffbfc00c00	swc2 hint12,-0x4(v0)
ffffffffbfc00c04	nop
ffffffffbfc00c08	dext v0,v0,0x10,0x8
ffffffffbfc00c0c	andi v1,s1,0x3
ffffffffbfc00c10	ld ra,0x18(sp)
ffffffffbfc00c14	andi v0,v0,0xff
ffffffffbfc00c18	ld gp,0x10(sp)
ffffffffbfc00c1c	srav v0,v0,v1
ffffffffbfc00c20	ld s1,0x8(sp)
ffffffffbfc00c24	andi v0,v0,0x1
ffffffffbfc00c28	ld s0,0x0(sp)
ffffffffbfc00c2c	jr ra
ffffffffbfc00c30	_addiu sp,sp,0x20
