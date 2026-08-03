# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00103030 function=local_cavium_ethernet_text_002e20
00103030	lui t9,0x0
00103034	lui at,0x11
00103038	daddiu t9,t9,0x0
0010303c	daddiu at,at,0x22d8
00103040	dsll32 t9,t9,0x0
00103044	daddu t9,t9,at
00103048	jr t9
0010304c	_daddiu a0,a0,0x7a8
