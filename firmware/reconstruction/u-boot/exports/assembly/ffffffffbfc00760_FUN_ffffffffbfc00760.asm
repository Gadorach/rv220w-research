# RV220W U-Boot v1.1.0 entry=ffffffffbfc00760 function=FUN_ffffffffbfc00760
ffffffffbfc00760	daddu gp,ra,zero
ffffffffbfc00764	lw t1,0x0(ra)
ffffffffbfc00768	lw t2,0x4(ra)
ffffffffbfc0076c	sub t1,t1,t2
ffffffffbfc00770	add gp,gp,t1
ffffffffbfc00774	lw t9,0x2a4(gp)
ffffffffbfc00778	jr t9
ffffffffbfc0077c	_nop
