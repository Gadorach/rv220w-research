# rv220w-stock-modules-v1.0.0 module=cavium-ethernet entry=001005c0 function=local_cavium_ethernet_text_0003b0
001005c0	daddu a0,a1,zero
001005c4	lui a1,0x0
001005c8	lui at,0x10
001005cc	daddiu a1,a1,0x0
001005d0	daddiu at,at,0xf48
001005d4	dsll32 a1,a1,0x0
001005d8	daddu a1,a1,at
001005dc	lui t9,0x0
001005e0	lui at,0x11
001005e4	daddiu t9,t9,0x0
001005e8	daddiu at,at,0x22b0
001005ec	dsll32 t9,t9,0x0
001005f0	daddu t9,t9,at
001005f4	jr t9
001005f8	_clear a2
