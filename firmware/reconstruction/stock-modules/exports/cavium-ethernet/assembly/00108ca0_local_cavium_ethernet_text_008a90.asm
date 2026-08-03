# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00108ca0 function=local_cavium_ethernet_text_008a90
00108ca0	lui v0,0xff80
00108ca4	daddiu sp,sp,-0x20
00108ca8	sd ra,0x10(sp)
00108cac	ori v0,v0,0x11f
00108cb0	sd s1,0x8(sp)
00108cb4	dsll32 v0,v0,0x8
00108cb8	sd s0,0x0(sp)
00108cbc	ld s1,0x0(v0)
00108cc0	swc2 hint19,0x39(s1)
00108cc4	lui v0,0xfff0
00108cc8	clear a2
00108ccc	lwc2 s2,0x30(s1)
00108cd0	lui v0,0xfffc
00108cd4	lui v1,0xfff0
00108cd8	ori v0,v0,0x9
00108cdc	ori v1,v1,0x23
00108ce0	dsll v0,v0,0x11
00108ce4	dsll32 v1,v1,0xb
00108ce8	daddiu v0,v0,-0x7ff7
00108cec	ori a2,v1,0xf8
00108cf0	dsll a1,v0,0x1c
00108cf4	ori v1,a1,0x300
00108cf8	ld s0,0x0(v1)
00108cfc	sd s0,0x0(v1)
00108d00	lui v0,0x0
00108d04	lui at,0x11
00108d08	daddiu v0,v0,0x0
00108d0c	dsll32 v0,v0,0x0
00108d10	daddu v0,v0,at
00108d14	lw v0,0x13c8(v0)
00108d18	ld a0,0x0(a2)
00108d1c	beq v0,zero,0x00108e58
00108d20	_ori v0,a1,0x308
00108d24	ori v0,a1,0x698
00108d28	ld v1,0x0(v0)
00108d2c	sd s0,0x0(v0)
00108d30	ld v1,0x0(a2)
00108d34	lui v0,0xfffc
00108d38	lui v1,0xfff0
00108d3c	ori v0,v0,0x9
00108d40	ori v1,v1,0x23
00108d44	dsll v0,v0,0x11
00108d48	dsll32 v1,v1,0xb
00108d4c	daddiu v0,v0,-0x7ff7
00108d50	ori v1,v1,0xf8
00108d54	dsll v0,v0,0x1c
00108d58	li a2,0x1
00108d5c	ori a0,v0,0x308
00108d60	ori v0,v0,0x6a0
00108d64	sd zero,0x0(a0)
00108d68	ld a0,0x0(v1)
00108d6c	sd zero,0x0(v0)
00108d70	li v0,0x1
00108d74	ld a0,0x0(v1)
00108d78	lui at,0x0
00108d7c	daddiu at,at,0x0
00108d80	dsll at,at,0x10
00108d84	daddiu at,at,0x11
00108d88	dsll at,at,0x10
00108d8c	sw v0,0x13c8(at)
00108d90	ld ra,0x10(sp)
00108d94	daddu v0,a2,zero
00108d98	ld s1,0x8(sp)
00108d9c	ld s0,0x0(sp)
00108da0	jr ra
00108da4	_daddiu sp,sp,0x20
00108e58	ld v1,0x0(v0)
00108e5c	and s0,s0,v1
00108e60	swc2 hint31,0x119(s0)
00108e64	nop
00108e68	swc2 hint11,0x14d(s0)
00108e6c	nop
00108e70	swc2 hint10,0x139(s0)
00108e74	nop
00108e78	swc2 hint9,0x125(s0)
00108e7c	nop
00108e80	swc2 hint8,0xcd(s0)
00108e84	nop
00108e88	swc2 store_retained,0xb9(s0)
00108e8c	nop
00108e90	swc2 load_retained,0xa5(s0)
00108e94	nop
00108e98	swc2 store_streamed,0x91(s0)
00108e9c	nop
00108ea0	swc2 load_streamed,0xf7(s0)
00108ea4	nop
00108ea8	swc2 store,0xd5(s0)
00108eac	nop
00108eb0	swc2 load,0xe3(s0)
00108eb4	nop
00108eb8	lui v0,0xfffc
00108ebc	ori v0,v0,0x9
00108ec0	dsll v0,v0,0x11
00108ec4	daddiu v0,v0,-0x7ff7
00108ec8	dsll a2,v0,0x1c
00108ecc	lui v0,0xfff0
00108ed0	ori v1,a2,0x698
00108ed4	ori v0,v0,0x23
00108ed8	ld a1,0x0(v1)
00108edc	dsll32 v0,v0,0xb
00108ee0	sd s0,0x0(v1)
00108ee4	ori v0,v0,0xf8
00108ee8	lui v1,0x0
00108eec	lui at,0x11
00108ef0	daddiu v1,v1,0x0
00108ef4	dsll32 v1,v1,0x0
00108ef8	daddu v1,v1,at
00108efc	lw v1,0x13c8(v1)
00108f00	ld a0,0x0(v0)
00108f04	bne v1,zero,0x00108d38
00108f08	_lui v0,0xfffc
00108f0c	ori v0,a2,0x6a0
00108f10	ld v1,0x0(v0)
00108f14	and s0,a1,v1
00108f18	swc2 hint8,0x1f7(s0)
00108f1c	nop
00108f20	swc2 store_retained,0x239(s0)
00108f24	nop
00108f28	swc2 load_retained,0x247(s0)
00108f2c	nop
00108f30	swc2 store_streamed,0x255(s0)
00108f34	nop
00108f38	swc2 load_streamed,0x263(s0)
00108f3c	nop
00108f40	swc2 hint3,0x20f(s0)
00108f44	nop
00108f48	swc2 hint2,0x21d(s0)
00108f4c	nop
00108f50	swc2 store,0x1fb(s0)
00108f54	nop
00108f58	lwc2 zero,-0x8a(s0)
00108f5c	nop
00108f60	lui a0,0x0
00108f64	lui at,0x11
00108f68	daddiu a0,a0,0x0
00108f6c	daddiu at,at,-0x938
00108f70	dsll32 a0,a0,0x0
00108f74	daddu a0,a0,at
00108f78	lui v0,0x0
00108f7c	lui at,0x11
00108f80	daddiu v0,v0,0x0
00108f84	daddiu at,at,0x21b0
00108f88	dsll32 v0,v0,0x0
00108f8c	daddu v0,v0,at
00108f90	jalr v0
00108f94	_nop
00108f98	j 0x00108d38
00108f9c	_lui v0,0xfffc
