# RV220W U-Boot v1.1.0 entry=ffffffffbfc0500c function=FUN_ffffffffbfc0500c
ffffffffbfc0500c	lui t2,0x4
ffffffffbfc05010	daddu a3,a0,zero
ffffffffbfc05014	addu t2,t2,t9
ffffffffbfc05018	daddu t0,a1,zero
ffffffffbfc0501c	addiu t2,t2,-0x192c
ffffffffbfc05020	dmfc0 v1,CacheErr
ffffffffbfc05024	dadd v0,v1,zero
ffffffffbfc05028	dsrl32 v0,v0,0x0
ffffffffbfc0502c	dsll32 v1,v1,0x0
ffffffffbfc05030	dsrl32 v1,v1,0x0
ffffffffbfc05034	dsll32 v0,v0,0x0
ffffffffbfc05038	dext v1,v1,0x0,0x20
ffffffffbfc0503c	or v0,v0,v1
ffffffffbfc05040	daddu a1,a3,zero
ffffffffbfc05044	lw a0,0x10(t2)
ffffffffbfc05048	and v0,v0,a2
ffffffffbfc0504c	lw t1,0x14(t2)
ffffffffbfc05050	xor a2,v0,t0
ffffffffbfc05054	beq a2,zero,0xffffffffbfc05070
ffffffffbfc05058	_addiu a0,a0,0x7fc0
ffffffffbfc0505c	lw v0,0x4800(t1)
ffffffffbfc05060	lw t9,0x92c(t2)
ffffffffbfc05064	addiu v0,v0,0x1
ffffffffbfc05068	jr t9
ffffffffbfc0506c	_sw v0,0x4800(t1)
ffffffffbfc05070	jr ra
ffffffffbfc05074	_nop
