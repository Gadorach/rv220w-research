# RV220W U-Boot v1.1.0 entry=ffffffffbfc044a0 function=FUN_ffffffffbfc044a0
ffffffffbfc044a0	dmfc0 v0,cop0_reg9.6
ffffffffbfc044a4	dadd v1,v0,zero
ffffffffbfc044a8	dsrl32 v1,v1,0x0
ffffffffbfc044ac	dsll32 v0,v0,0x0
ffffffffbfc044b0	dsrl32 v0,v0,0x0
ffffffffbfc044b4	dext v0,v0,0x0,0x20
ffffffffbfc044b8	dsll32 v1,v1,0x0
ffffffffbfc044bc	daddu a0,a0,v0
ffffffffbfc044c0	daddu a0,v1,a0
ffffffffbfc044c4	dmfc0 v1,cop0_reg9.6
ffffffffbfc044c8	dadd v0,v1,zero
ffffffffbfc044cc	dsrl32 v0,v0,0x0
ffffffffbfc044d0	dsll32 v1,v1,0x0
ffffffffbfc044d4	dsrl32 v1,v1,0x0
ffffffffbfc044d8	dsll32 v0,v0,0x0
ffffffffbfc044dc	dext v1,v1,0x0,0x20
ffffffffbfc044e0	daddu v0,v0,v1
ffffffffbfc044e4	sltu v0,v0,a0
ffffffffbfc044e8	bne v0,zero,0xffffffffbfc044c4
ffffffffbfc044ec	_nop
ffffffffbfc044f0	jr ra
ffffffffbfc044f4	_nop
