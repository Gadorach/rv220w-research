# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00103050 function=local_cavium_ethernet_text_002e40
00103050	lui t9,0x0
00103054	lui at,0x11
00103058	daddiu t9,t9,0x0
0010305c	daddiu at,at,0x2028
00103060	dsll32 t9,t9,0x0
00103064	daddu t9,t9,at
00103068	jr t9
0010306c	_daddiu a0,a0,0x7a8
