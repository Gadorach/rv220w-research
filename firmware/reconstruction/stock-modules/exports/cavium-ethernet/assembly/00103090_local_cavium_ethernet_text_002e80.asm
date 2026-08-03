# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00103090 function=local_cavium_ethernet_text_002e80
00103090	lui t9,0x0
00103094	lui at,0x11
00103098	daddiu t9,t9,0x0
0010309c	daddiu at,at,0x2050
001030a0	dsll32 t9,t9,0x0
001030a4	daddu t9,t9,at
001030a8	jr t9
001030ac	_daddiu a0,a0,0x7a8
