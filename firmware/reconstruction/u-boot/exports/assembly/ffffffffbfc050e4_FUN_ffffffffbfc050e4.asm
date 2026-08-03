# RV220W U-Boot v1.1.0 entry=ffffffffbfc050e4 function=FUN_ffffffffbfc050e4
ffffffffbfc050e4	lui t0,0x4
ffffffffbfc050e8	addu t0,t0,t9
ffffffffbfc050ec	addiu t0,t0,-0x1a04
ffffffffbfc050f0	ld v0,0x0(a1)
ffffffffbfc050f4	and v0,v0,a3
ffffffffbfc050f8	daddu a1,a0,zero
ffffffffbfc050fc	lw a0,0x10(t0)
ffffffffbfc05100	xor v0,v0,a2
ffffffffbfc05104	lw v1,0x14(t0)
ffffffffbfc05108	daddu a2,v0,zero
ffffffffbfc0510c	beq v0,zero,0xffffffffbfc05128
ffffffffbfc05110	_addiu a0,a0,0x7fe8
ffffffffbfc05114	lw v0,0x4800(v1)
ffffffffbfc05118	lw t9,0x92c(t0)
ffffffffbfc0511c	addiu v0,v0,0x1
ffffffffbfc05120	jr t9
ffffffffbfc05124	_sw v0,0x4800(v1)
ffffffffbfc05128	jr ra
ffffffffbfc0512c	_nop
