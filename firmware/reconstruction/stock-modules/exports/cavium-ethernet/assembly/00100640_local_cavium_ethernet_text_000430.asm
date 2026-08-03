# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00100640 function=local_cavium_ethernet_text_000430
00100640	daddu a0,a1,zero
00100644	lui a1,0x0
00100648	lui at,0x10
0010064c	daddiu a1,a1,0x0
00100650	daddiu at,at,0xde8
00100654	dsll32 a1,a1,0x0
00100658	daddu a1,a1,at
0010065c	lui t9,0x0
00100660	lui at,0x11
00100664	daddiu t9,t9,0x0
00100668	daddiu at,at,0x22b0
0010066c	dsll32 t9,t9,0x0
00100670	daddu t9,t9,at
00100674	jr t9
00100678	_clear a2
