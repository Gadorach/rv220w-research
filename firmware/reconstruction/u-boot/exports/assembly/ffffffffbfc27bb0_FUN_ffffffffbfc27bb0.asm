# RV220W U-Boot v1.1.0 entry=ffffffffbfc27bb0 function=FUN_ffffffffbfc27bb0
ffffffffbfc27bb0	addiu sp,sp,-0x40
ffffffffbfc27bb4	sd a1,0x8(sp)
ffffffffbfc27bb8	sd a2,0x10(sp)
ffffffffbfc27bbc	sd a3,0x18(sp)
ffffffffbfc27bc0	sd t0,0x20(sp)
ffffffffbfc27bc4	sd t1,0x28(sp)
ffffffffbfc27bc8	sd t2,0x30(sp)
ffffffffbfc27bcc	sd t3,0x38(sp)
ffffffffbfc27bd0	sync 0x0
ffffffffbfc27bd4	daddi t9,zero,0x6
ffffffffbfc27bd8	lui t7,0x8000
ffffffffbfc27bdc	ori t7,t7,0xf
ffffffffbfc27be0	dsll t7,t7,0x10
ffffffffbfc27be4	ori t7,t7,0xeffe
ffffffffbfc27be8	dsll t7,t7,0x10
ffffffffbfc27bec	dadd t8,ra,zero
ffffffffbfc27bf0	jalr t7
ffffffffbfc27bf4	_nop
ffffffffbfc27bf8	dadd ra,t8,zero
ffffffffbfc27bfc	jr ra
ffffffffbfc27c00	_addiu sp,sp,0x40
