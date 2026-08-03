# RV220W U-Boot v1.1.0 entry=ffffffffbfc31b90 function=FUN_ffffffffbfc31b90
ffffffffbfc31b90	sd a1,0x0(a0)
ffffffffbfc31b94	lui v0,0x80
ffffffffbfc31b98	dsrl32 a0,a0,0x8
ffffffffbfc31b9c	ori v0,v0,0x118
ffffffffbfc31ba0	bne a0,v0,0xffffffffbfc31bb8
ffffffffbfc31ba4	_lui v0,0xfff0
ffffffffbfc31ba8	ori v0,v0,0x23
ffffffffbfc31bac	dsll32 v0,v0,0xb
ffffffffbfc31bb0	ori v0,v0,0xf8
ffffffffbfc31bb4	ld v0,0x0(v0)
ffffffffbfc31bb8	jr ra
ffffffffbfc31bbc	_nop
