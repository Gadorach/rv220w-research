# RV220W U-Boot v1.1.0 entry=ffffffffbfc174cc function=do_nm
ffffffffbfc174cc	lui v1,0x3
ffffffffbfc174d0	daddu v0,a2,zero
ffffffffbfc174d4	addu v1,v1,t9
ffffffffbfc174d8	daddu t0,a3,zero
ffffffffbfc174dc	addiu v1,v1,-0x3dec
ffffffffbfc174e0	daddu a2,a1,zero
ffffffffbfc174e4	lw t9,0x1c(v1)
ffffffffbfc174e8	daddu a3,v0,zero
ffffffffbfc174ec	addiu t9,t9,0x72d8
ffffffffbfc174f0	jr t9
ffffffffbfc174f4	_clear a1
