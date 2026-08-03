# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00100680 function=local_cavium_ethernet_text_000470
00100680	daddu a0,a1,zero
00100684	lui a1,0x0
00100688	lui at,0x10
0010068c	daddiu a1,a1,0x0
00100690	daddiu at,at,0xbb8
00100694	dsll32 a1,a1,0x0
00100698	daddu a1,a1,at
0010069c	lui t9,0x0
001006a0	lui at,0x11
001006a4	daddiu t9,t9,0x0
001006a8	daddiu at,at,0x22b0
001006ac	dsll32 t9,t9,0x0
001006b0	daddu t9,t9,at
001006b4	jr t9
001006b8	_clear a2
