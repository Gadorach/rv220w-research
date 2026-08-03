# RV220W U-Boot v1.1.0 entry=ffffffffbfc27210 function=FUN_ffffffffbfc27210
ffffffffbfc27210	sd a1,0x0(a0)
ffffffffbfc27214	lui v0,0x80
ffffffffbfc27218	dsrl32 a0,a0,0x8
ffffffffbfc2721c	ori v0,v0,0x118
ffffffffbfc27220	bne a0,v0,0xffffffffbfc27238
ffffffffbfc27224	_lui v0,0xfff0
ffffffffbfc27228	ori v0,v0,0x23
ffffffffbfc2722c	dsll32 v0,v0,0xb
ffffffffbfc27230	ori v0,v0,0xf8
ffffffffbfc27234	ld v0,0x0(v0)
ffffffffbfc27238	jr ra
ffffffffbfc2723c	_nop
