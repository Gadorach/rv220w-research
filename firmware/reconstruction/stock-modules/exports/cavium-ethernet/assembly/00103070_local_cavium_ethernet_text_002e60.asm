# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00103070 function=local_cavium_ethernet_text_002e60
00103070	lui t9,0x0
00103074	lui at,0x11
00103078	daddiu t9,t9,0x0
0010307c	daddiu at,at,0x21b8
00103080	dsll32 t9,t9,0x0
00103084	daddu t9,t9,at
00103088	jr t9
0010308c	_daddiu a0,a0,0x7a8
