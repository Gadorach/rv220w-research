# RV220W U-Boot v1.1.0 entry=ffffffffbfc16350 function=FUN_ffffffffbfc16350
ffffffffbfc16350	sd a1,0x0(a0)
ffffffffbfc16354	lui v0,0x80
ffffffffbfc16358	dsrl32 a0,a0,0x8
ffffffffbfc1635c	ori v0,v0,0x118
ffffffffbfc16360	bne a0,v0,0xffffffffbfc16378
ffffffffbfc16364	_lui v0,0xfff0
ffffffffbfc16368	ori v0,v0,0x23
ffffffffbfc1636c	dsll32 v0,v0,0xb
ffffffffbfc16370	ori v0,v0,0xf8
ffffffffbfc16374	ld v0,0x0(v0)
ffffffffbfc16378	jr ra
ffffffffbfc1637c	_nop
