# RV220W U-Boot v1.1.0 entry=ffffffffbfc0bec8 function=FUN_ffffffffbfc0bec8
ffffffffbfc0bec8	addiu sp,sp,-0x20
ffffffffbfc0becc	sd gp,0x10(sp)
ffffffffbfc0bed0	lui gp,0x3
ffffffffbfc0bed4	addu gp,gp,t9
ffffffffbfc0bed8	sd ra,0x18(sp)
ffffffffbfc0bedc	addiu gp,gp,0x7818
ffffffffbfc0bee0	lw t9,0x840(gp)
ffffffffbfc0bee4	jalr t9
ffffffffbfc0bee8	_daddu a1,sp,zero
ffffffffbfc0beec	lw t9,0x758(gp)
ffffffffbfc0bef0	jalr t9
ffffffffbfc0bef4	_daddu a0,sp,zero
ffffffffbfc0bef8	ld ra,0x18(sp)
ffffffffbfc0befc	ld gp,0x10(sp)
ffffffffbfc0bf00	jr ra
ffffffffbfc0bf04	_addiu sp,sp,0x20
