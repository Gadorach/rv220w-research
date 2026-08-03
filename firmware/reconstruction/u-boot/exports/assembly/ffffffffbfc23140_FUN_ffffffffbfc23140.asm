# RV220W U-Boot v1.1.0 entry=ffffffffbfc23140 function=FUN_ffffffffbfc23140
ffffffffbfc23140	daddu v1,a0,zero
ffffffffbfc23144	lb v0,0x0(v1)
ffffffffbfc23148	bne v0,zero,0xffffffffbfc23144
ffffffffbfc2314c	_addiu v1,v1,0x1
ffffffffbfc23150	addiu v1,v1,-0x1
ffffffffbfc23154	lb v0,0x0(a1)
ffffffffbfc23158	addiu a1,a1,0x1
ffffffffbfc2315c	sb v0,0x0(v1)
ffffffffbfc23160	bne v0,zero,0xffffffffbfc23154
ffffffffbfc23164	_addiu v1,v1,0x1
ffffffffbfc23168	jr ra
ffffffffbfc2316c	_daddu v0,a0,zero
