# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00104c08 function=local_cavium_ethernet_text_0049f8
00104c08	ld v0,0x0(a2)
00104c0c	lui t9,0x0
00104c10	lui at,0x10
00104c14	daddiu t9,t9,0x0
00104c18	daddiu at,at,0x4af8
00104c1c	dsll32 t9,t9,0x0
00104c20	daddu t9,t9,at
00104c24	daddiu v0,v0,0x1
00104c28	jr t9
00104c2c	_sd v0,0x0(a2)
