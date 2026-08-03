# RV220W U-Boot v1.1.0 entry=ffffffffbfc32018 function=FUN_ffffffffbfc32018
ffffffffbfc32018	sd a1,0x0(a0)
ffffffffbfc3201c	lui v0,0x80
ffffffffbfc32020	dsrl32 a0,a0,0x8
ffffffffbfc32024	ori v0,v0,0x118
ffffffffbfc32028	bne a0,v0,0xffffffffbfc32040
ffffffffbfc3202c	_lui v0,0xfff0
ffffffffbfc32030	ori v0,v0,0x23
ffffffffbfc32034	dsll32 v0,v0,0xb
ffffffffbfc32038	ori v0,v0,0xf8
ffffffffbfc3203c	ld v0,0x0(v0)
ffffffffbfc32040	jr ra
ffffffffbfc32044	_nop
