# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00100600 function=local_cavium_ethernet_text_0003f0
00100600	daddu a0,a1,zero
00100604	lui a1,0x0
00100608	lui at,0x10
0010060c	daddiu a1,a1,0x0
00100610	daddiu at,at,0xec8
00100614	dsll32 a1,a1,0x0
00100618	daddu a1,a1,at
0010061c	lui t9,0x0
00100620	lui at,0x11
00100624	daddiu t9,t9,0x0
00100628	daddiu at,at,0x22b0
0010062c	dsll32 t9,t9,0x0
00100630	daddu t9,t9,at
00100634	jr t9
00100638	_clear a2
