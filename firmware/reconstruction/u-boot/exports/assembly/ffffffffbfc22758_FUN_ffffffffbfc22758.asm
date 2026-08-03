# RV220W U-Boot v1.1.0 entry=ffffffffbfc22758 function=FUN_ffffffffbfc22758
ffffffffbfc22758	lui a2,0x2
ffffffffbfc2275c	addu a2,a2,t9
ffffffffbfc22760	addiu a2,a2,0xf88
ffffffffbfc22764	lw a1,0x224(a2)
ffffffffbfc22768	lw v0,0x0(a1)
ffffffffbfc2276c	bne v0,zero,0xffffffffbfc227a4
ffffffffbfc22770	_nop
ffffffffbfc22774	lw v0,0xe4(a2)
ffffffffbfc22778	li v1,-0x20
ffffffffbfc2277c	lw a0,0x764(a2)
ffffffffbfc22780	addiu v0,v0,0x1f
ffffffffbfc22784	and v0,v0,v1
ffffffffbfc22788	addiu v1,a0,0x10
ffffffffbfc2278c	sw v0,0x0(a1)
ffffffffbfc22790	addiu v0,v0,0x600
ffffffffbfc22794	sw v0,0x0(a0)
ffffffffbfc22798	addiu a0,a0,0x4
ffffffffbfc2279c	bne a0,v1,0xffffffffbfc22794
ffffffffbfc227a0	_addiu v0,v0,0x600
ffffffffbfc227a4	lw v0,0x224(a2)
ffffffffbfc227a8	jr ra
ffffffffbfc227ac	_lw v0,0x0(v0)
