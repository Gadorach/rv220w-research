# RV220W U-Boot v1.1.0 entry=ffffffffbfc23170 function=FUN_ffffffffbfc23170
ffffffffbfc23170	beq a2,zero,0xffffffffbfc231b8
ffffffffbfc23174	_daddu v1,a0,zero
ffffffffbfc23178	lb v0,0x0(v1)
ffffffffbfc2317c	bne v0,zero,0xffffffffbfc23178
ffffffffbfc23180	_addiu v1,v1,0x1
ffffffffbfc23184	addiu v1,v1,-0x1
ffffffffbfc23188	b 0xffffffffbfc231a4
ffffffffbfc2318c	_lb v0,0x0(a1)
ffffffffbfc23190	bne a2,zero,0xffffffffbfc231a0
ffffffffbfc23194	_nop
ffffffffbfc23198	b 0xffffffffbfc231b8
ffffffffbfc2319c	_sb zero,0x0(v1)
ffffffffbfc231a0	lb v0,0x0(a1)
ffffffffbfc231a4	addiu a2,a2,-0x1
ffffffffbfc231a8	addiu a1,a1,0x1
ffffffffbfc231ac	sb v0,0x0(v1)
ffffffffbfc231b0	bne v0,zero,0xffffffffbfc23190
ffffffffbfc231b4	_addiu v1,v1,0x1
ffffffffbfc231b8	jr ra
ffffffffbfc231bc	_daddu v0,a0,zero
