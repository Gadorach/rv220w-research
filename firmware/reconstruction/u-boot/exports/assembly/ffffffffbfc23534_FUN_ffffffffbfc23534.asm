# RV220W U-Boot v1.1.0 entry=ffffffffbfc23534 function=FUN_ffffffffbfc23534
ffffffffbfc23534	sltu v0,a1,a0
ffffffffbfc23538	bne v0,zero,0xffffffffbfc23570
ffffffffbfc2353c	_nop
ffffffffbfc23540	daddu v1,a0,zero
ffffffffbfc23544	b 0xffffffffbfc2355c
ffffffffbfc23548	_li a3,-0x1
ffffffffbfc2354c	lbu v0,0x0(a1)
ffffffffbfc23550	addiu a1,a1,0x1
ffffffffbfc23554	sb v0,0x0(v1)
ffffffffbfc23558	addiu v1,v1,0x1
ffffffffbfc2355c	addiu a2,a2,-0x1
ffffffffbfc23560	bne a2,a3,0xffffffffbfc2354c
ffffffffbfc23564	_daddu v0,a0,zero
ffffffffbfc23568	b 0xffffffffbfc2359c
ffffffffbfc2356c	_nop
ffffffffbfc23570	addu a1,a1,a2
ffffffffbfc23574	addu v1,a0,a2
ffffffffbfc23578	b 0xffffffffbfc23588
ffffffffbfc2357c	_li a3,-0x1
ffffffffbfc23580	lbu v0,0x0(a1)
ffffffffbfc23584	sb v0,0x0(v1)
ffffffffbfc23588	addiu a2,a2,-0x1
ffffffffbfc2358c	addiu a1,a1,-0x1
ffffffffbfc23590	bne a2,a3,0xffffffffbfc23580
ffffffffbfc23594	_addiu v1,v1,-0x1
ffffffffbfc23598	daddu v0,a0,zero
ffffffffbfc2359c	jr ra
ffffffffbfc235a0	_nop
