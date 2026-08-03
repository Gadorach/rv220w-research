# RV220W U-Boot v1.1.0 entry=ffffffffbfc2e0c0 function=FUN_ffffffffbfc2e0c0
ffffffffbfc2e0c0	mfc0 k0,EBase
ffffffffbfc2e0c4	andi k0,k0,0xff
ffffffffbfc2e0c8	sll k0,k0,0xc
ffffffffbfc2e0cc	addiu k0,k0,0x4000
ffffffffbfc2e0d0	addiu k0,k0,0x4000
ffffffffbfc2e0d4	addiu k0,k0,0x4000
ffffffffbfc2e0d8	addiu k0,k0,0x4000
ffffffffbfc2e0dc	rotr k0,k0,0x1f
ffffffffbfc2e0e0	addi k0,k0,0x1
ffffffffbfc2e0e4	rotr k0,k0,0x1
ffffffffbfc2e0e8	ld zero,0x0(k0)
ffffffffbfc2e0ec	sd t0,0x0(k0)
ffffffffbfc2e0f0	dmfc0 t0,DEPC
ffffffffbfc2e0f4	sd t1,0x8(k0)
ffffffffbfc2e0f8	dmfc0 t1,PerfCnt.1
ffffffffbfc2e0fc	sd t2,0x10(k0)
ffffffffbfc2e100	dmfc0 t2,PerfCnt.3
ffffffffbfc2e104	sd t0,0x128(k0)
ffffffffbfc2e108	ld t0,0x0(k0)
ffffffffbfc2e10c	sd t1,0x238(k0)
ffffffffbfc2e110	ld t1,0x8(k0)
ffffffffbfc2e114	sd t2,0x240(k0)
ffffffffbfc2e118	ld t2,0x10(k0)
ffffffffbfc2e11c	sync 0x4
ffffffffbfc2e120	dmfc0 k0,DESAVE
ffffffffbfc2e124	deret
