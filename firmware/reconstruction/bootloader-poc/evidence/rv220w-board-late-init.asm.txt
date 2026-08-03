# RV220W U-Boot v1.1.0 entry=ffffffffbfc13084 function=rv220w_board_late_init
ffffffffbfc13084	addiu sp,sp,-0x20
ffffffffbfc13088	sd gp,0x8(sp)
ffffffffbfc1308c	lui gp,0x3
ffffffffbfc13090	sd ra,0x10(sp)
ffffffffbfc13094	addu gp,gp,t9
ffffffffbfc13098	sd s0,0x0(sp)
ffffffffbfc1309c	addiu gp,gp,0x65c
ffffffffbfc130a0	lw a0,0x14(gp)
ffffffffbfc130a4	lw a1,0x14(gp)
ffffffffbfc130a8	lw t9,0x434(gp)
ffffffffbfc130ac	addiu a0,a0,-0x59d8
ffffffffbfc130b0	jalr t9
ffffffffbfc130b4	_addiu a1,a1,-0x52a0
ffffffffbfc130b8	lw t9,0x30c(gp)
ffffffffbfc130bc	jalr t9
ffffffffbfc130c0	_nop
ffffffffbfc130c4	lw t9,0x240(gp)
ffffffffbfc130c8	jalr t9
ffffffffbfc130cc	_li a0,0x1
ffffffffbfc130d0	lw t9,0x5c8(gp)
ffffffffbfc130d4	jalr t9
ffffffffbfc130d8	_li a0,0x1
ffffffffbfc130dc	lw t9,0x2ec(gp)
ffffffffbfc130e0	jalr t9
ffffffffbfc130e4	_li a0,0x1
ffffffffbfc130e8	lw a0,0x14(gp)
ffffffffbfc130ec	daddu a1,v0,zero
ffffffffbfc130f0	lw t9,0x92c(gp)
ffffffffbfc130f4	daddu s0,v0,zero
ffffffffbfc130f8	jalr t9
ffffffffbfc130fc	_addiu a0,a0,-0x5298
ffffffffbfc13100	bne s0,zero,0xffffffffbfc1312c
ffffffffbfc13104	_lw t9,0x92c(gp)
ffffffffbfc13108	lw a0,0x14(gp)
ffffffffbfc1310c	jalr t9
ffffffffbfc13110	_addiu a0,a0,-0x5280
ffffffffbfc13114	lw t9,0x32c(gp)
ffffffffbfc13118	jalr t9
ffffffffbfc1311c	_nop
ffffffffbfc13120	lw t9,0x4ac(gp)
ffffffffbfc13124	jalr t9
ffffffffbfc13128	_nop
ffffffffbfc1312c	lw t9,0x34c(gp)
ffffffffbfc13130	jalr t9
ffffffffbfc13134	_nop
ffffffffbfc13138	bgez v0,0xffffffffbfc13148
ffffffffbfc1313c	_lw t9,0x2d0(gp)
ffffffffbfc13140	jalr t9
ffffffffbfc13144	_nop
ffffffffbfc13148	lw a0,0x14(gp)
ffffffffbfc1314c	lw a1,0x10(gp)
ffffffffbfc13150	lw t9,0x434(gp)
ffffffffbfc13154	addiu a0,a0,-0x5260
ffffffffbfc13158	ld gp,0x8(sp)
ffffffffbfc1315c	addiu a1,a1,0x63b0
ffffffffbfc13160	ld ra,0x10(sp)
ffffffffbfc13164	ld s0,0x0(sp)
ffffffffbfc13168	jr t9
ffffffffbfc1316c	_addiu sp,sp,0x20
