# RV220W U-Boot v1.1.0 entry=ffffffffbfc141f0 function=FUN_ffffffffbfc141f0
ffffffffbfc141f0	lhu v0,0x4(a0)
ffffffffbfc141f4	addiu v1,v0,-0x1
ffffffffbfc141f8	sll v0,v1,0x2
ffffffffbfc141fc	daddu a3,v1,zero
ffffffffbfc14200	addu v0,v0,a0
ffffffffbfc14204	addiu a2,v0,0xc
ffffffffbfc14208	lw v0,0x0(a2)
ffffffffbfc1420c	sltu v0,a1,v0
ffffffffbfc14210	beq v0,zero,0xffffffffbfc14220
ffffffffbfc14214	_addiu a2,a2,-0x4
ffffffffbfc14218	b 0xffffffffbfc14208
ffffffffbfc1421c	_addiu v1,v1,-0x1
ffffffffbfc14220	bne v1,a3,0xffffffffbfc1423c
ffffffffbfc14224	_nop
ffffffffbfc14228	lw v1,0x0(a0)
ffffffffbfc1422c	lw v0,0xc(a0)
ffffffffbfc14230	addu v0,v0,v1
ffffffffbfc14234	jr ra
ffffffffbfc14238	_addiu v0,v0,-0x1
ffffffffbfc1423c	sll v0,v1,0x2
ffffffffbfc14240	addu v0,v0,a0
ffffffffbfc14244	lw v0,0x10(v0)
ffffffffbfc14248	jr ra
ffffffffbfc1424c	_addiu v0,v0,-0x1
