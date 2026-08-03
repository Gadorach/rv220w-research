# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00100580 function=local_cavium_ethernet_text_000370
00100580	daddu a0,a1,zero
00100584	lui a1,0x0
00100588	lui at,0x10
0010058c	daddiu a1,a1,0x0
00100590	daddiu at,at,0x6c0
00100594	dsll32 a1,a1,0x0
00100598	daddu a1,a1,at
0010059c	lui t9,0x0
001005a0	lui at,0x11
001005a4	daddiu t9,t9,0x0
001005a8	daddiu at,at,0x22b0
001005ac	dsll32 t9,t9,0x0
001005b0	daddu t9,t9,at
001005b4	jr t9
001005b8	_clear a2
