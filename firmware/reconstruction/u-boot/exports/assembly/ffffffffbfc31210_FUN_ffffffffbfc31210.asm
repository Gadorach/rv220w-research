# RV220W U-Boot v1.1.0 entry=ffffffffbfc31210 function=FUN_ffffffffbfc31210
ffffffffbfc31210	lui v1,0xfffc
ffffffffbfc31214	SPECIAL2 at,a0,v0,0xa,0x32
ffffffffbfc31218	ori v1,v1,0x9
ffffffffbfc3121c	SPECIAL2 zero,a1,a1,0x1b,0x32
ffffffffbfc31220	dsll v1,v1,0x11
ffffffffbfc31224	daddiu v1,v1,-0x7ff5
ffffffffbfc31228	dsll v1,v1,0x1c
ffffffffbfc3122c	ori v1,v1,0x1040
ffffffffbfc31230	daddu v0,v0,v1
ffffffffbfc31234	jr ra
ffffffffbfc31238	_daddu v0,a1,v0
