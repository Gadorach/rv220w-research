# RV220W U-Boot v1.1.0 entry=ffffffffbfc22704 function=FUN_ffffffffbfc22704
ffffffffbfc22704	lui t0,0x2
ffffffffbfc22708	clear a1
ffffffffbfc2270c	addu t0,t0,t9
ffffffffbfc22710	addiu t0,t0,0xfdc
ffffffffbfc22714	lw v0,0x8e4(t0)
ffffffffbfc22718	lhu a2,0x4(v0)
ffffffffbfc2271c	b 0xffffffffbfc2273c
ffffffffbfc22720	_daddu a3,v0,zero
ffffffffbfc22724	sll v0,v1,0x2
ffffffffbfc22728	addu v0,v0,a3
ffffffffbfc2272c	lw v0,0xc(v0)
ffffffffbfc22730	sltu v0,a0,v0
ffffffffbfc22734	beq v0,zero,0xffffffffbfc22750
ffffffffbfc22738	_nop
ffffffffbfc2273c	sll v0,a1,0x0
ffffffffbfc22740	subu v0,a2,v0
ffffffffbfc22744	addiu v1,v0,-0x1
ffffffffbfc22748	bgez v1,0xffffffffbfc22724
ffffffffbfc2274c	_daddiu a1,a1,0x1
ffffffffbfc22750	jr ra
ffffffffbfc22754	_daddu v0,v1,zero
