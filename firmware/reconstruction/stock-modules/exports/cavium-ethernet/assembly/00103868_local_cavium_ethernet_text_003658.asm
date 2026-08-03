# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=00103868 function=local_cavium_ethernet_text_003658
00103868	daddu a0,a1,zero
0010386c	lui a1,0x0
00103870	lui at,0x10
00103874	daddiu a1,a1,0x0
00103878	daddiu at,at,0x38a8
0010387c	dsll32 a1,a1,0x0
00103880	daddu a1,a1,at
00103884	lui t9,0x0
00103888	lui at,0x11
0010388c	daddiu t9,t9,0x0
00103890	daddiu at,at,0x22b0
00103894	dsll32 t9,t9,0x0
00103898	daddu t9,t9,at
0010389c	jr t9
001038a0	_clear a2
