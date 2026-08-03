# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=001031b0 function=local_cavium_ethernet_text_002fa0
001031b0	lui v0,0xfff0
001031b4	lui v1,0x1
001031b8	ori v0,v0,0x23
001031bc	dins v1,a1,0x8,0x5
001031c0	dsll32 v0,v0,0xb
001031c4	daddiu sp,sp,-0x20
001031c8	sd s1,0x8(sp)
001031cc	dins v1,a2,0x0,0x5
001031d0	sd s0,0x0(sp)
001031d4	ori a0,v0,0x1800
001031d8	sd ra,0x18(sp)
001031dc	ori a1,v0,0xf8
001031e0	sd s2,0x10(sp)
001031e4	ori s0,v0,0x1810
001031e8	sd v1,0x0(a0)
001031ec	lui s1,0x0
001031f0	lui at,0x11
001031f4	daddiu s1,s1,0x0
001031f8	daddiu at,at,0x2020
001031fc	dsll32 s1,s1,0x0
00103200	daddu s1,s1,at
00103204	ld v1,0x0(a1)
00103208	j 0x00103220
0010320c	_lw v0,0x24(gp)
00103210	ld v0,0x0(s0)
00103214	lwc2 s1,0xa(v0)
00103218	nop
0010321c	lw v0,0x24(gp)
00103220	dext v0,v0,0x8,0x14
00103224	bne v0,zero,0x00103210
00103228	_nop
0010322c	jalr s1
00103230	_nop
00103234	ld v0,0x0(s0)
00103238	swc2 hint17,-0x8(v0)
0010323c	nop
00103240	lwc2 s0,0x7(v0)
00103244	ld ra,0x18(sp)
00103248	andi v0,v0,0xffff
0010324c	ld s2,0x10(sp)
00103250	ld s1,0x8(sp)
00103254	ld s0,0x0(sp)
00103258	jr ra
0010325c	_daddiu sp,sp,0x20
