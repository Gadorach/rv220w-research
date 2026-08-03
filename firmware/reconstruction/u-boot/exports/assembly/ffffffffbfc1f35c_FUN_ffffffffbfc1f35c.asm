# RV220W U-Boot v1.1.0 entry=ffffffffbfc1f35c function=FUN_ffffffffbfc1f35c
ffffffffbfc1f35c	lui a1,0x2
ffffffffbfc1f360	sll v1,a0,0x2
ffffffffbfc1f364	addu a1,a1,t9
ffffffffbfc1f368	slti a0,a0,0x3
ffffffffbfc1f36c	addiu a1,a1,0x4384
ffffffffbfc1f370	lw v0,0x318(a1)
ffffffffbfc1f374	addu v1,v1,v0
ffffffffbfc1f378	beq a0,zero,0xffffffffbfc1f390
ffffffffbfc1f37c	_li v0,-0x1
ffffffffbfc1f380	lw v0,0x0(v1)
ffffffffbfc1f384	lw t9,0x20(v0)
ffffffffbfc1f388	jr t9
ffffffffbfc1f38c	_nop
ffffffffbfc1f390	jr ra
ffffffffbfc1f394	_nop
