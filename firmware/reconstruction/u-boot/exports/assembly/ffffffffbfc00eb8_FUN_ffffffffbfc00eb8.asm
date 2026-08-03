# RV220W U-Boot v1.1.0 entry=ffffffffbfc00eb8 function=FUN_ffffffffbfc00eb8
ffffffffbfc00eb8	lui t0,0x4
ffffffffbfc00ebc	addu t0,t0,t9
ffffffffbfc00ec0	addiu t0,t0,0x2828
ffffffffbfc00ec4	lw a2,0x14(t0)
ffffffffbfc00ec8	lw v0,0x14(t0)
ffffffffbfc00ecc	lw a1,0x47f0(a2)
ffffffffbfc00ed0	lw v0,0x47e8(v0)
ffffffffbfc00ed4	addu v1,a1,a0
ffffffffbfc00ed8	sltu v0,v1,v0
ffffffffbfc00edc	bne v0,zero,0xffffffffbfc00f00
ffffffffbfc00ee0	_clear a3
ffffffffbfc00ee4	lw v0,0x14(t0)
ffffffffbfc00ee8	lw v0,0x47ec(v0)
ffffffffbfc00eec	sltu v0,v0,v1
ffffffffbfc00ef0	bne v0,zero,0xffffffffbfc00f00
ffffffffbfc00ef4	_nop
ffffffffbfc00ef8	sw v1,0x47f0(a2)
ffffffffbfc00efc	daddu a3,a1,zero
ffffffffbfc00f00	jr ra
ffffffffbfc00f04	_daddu v0,a3,zero
