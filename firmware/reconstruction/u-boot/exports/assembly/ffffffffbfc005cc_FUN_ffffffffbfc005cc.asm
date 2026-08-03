# RV220W U-Boot v1.1.0 entry=ffffffffbfc005cc function=FUN_ffffffffbfc005cc
ffffffffbfc005cc	mtc0 zero,WatchLo
ffffffffbfc005d0	mtc0 zero,WatchHi
ffffffffbfc005d4	mfc0 k0,Status
ffffffffbfc005d8	li k1,-0x2
ffffffffbfc005dc	and k0,k0,k1
ffffffffbfc005e0	mtc0 k0,Status
ffffffffbfc005e4	mtc0 zero,Cause
ffffffffbfc005e8	dmtc0 zero,Count
ffffffffbfc005ec	dmtc0 zero,Compare
ffffffffbfc005f0	mfc0 t1,Status
ffffffffbfc005f4	li v0,0xe0
ffffffffbfc005f8	or v0,v0,t1
ffffffffbfc005fc	mtc0 v0,Status
ffffffffbfc00600	lui v0,0x2000
ffffffffbfc00604	mtc0 v0,PageGrain
ffffffffbfc00608	dmtc0 zero,EntryLo0
ffffffffbfc0060c	mfc0 a0,Config1
ffffffffbfc00610	dmtc0 zero,EntryLo1
ffffffffbfc00614	srl a0,a0,0x19
ffffffffbfc00618	mtc0 zero,PageMask
ffffffffbfc0061c	lui v0,0x9000
ffffffffbfc00620	andi a0,a0,0x3f
ffffffffbfc00624	dmtc0 zero,Context
ffffffffbfc00628	dmtc0 zero,XContext
ffffffffbfc0062c	mtc0 zero,Wired
ffffffffbfc00630	dmtc0 v0,EntryHi
ffffffffbfc00634	nop
ffffffffbfc00638	nop
ffffffffbfc0063c	tlbp
ffffffffbfc00640	nop
ffffffffbfc00644	nop
ffffffffbfc00648	mfc0 v1,Index
ffffffffbfc0064c	daddiu v0,v0,0x2000
ffffffffbfc00650	bgez v1,0xffffffffbfc00630
ffffffffbfc00654	_nop
ffffffffbfc00658	nop
ffffffffbfc0065c	mtc0 a0,Index
ffffffffbfc00660	nop
ffffffffbfc00664	nop
ffffffffbfc00668	tlbwi
ffffffffbfc0066c	nop
ffffffffbfc00670	nop
ffffffffbfc00674	bne a0,zero,0xffffffffbfc00630
ffffffffbfc00678	_addiu a0,a0,-0x1
ffffffffbfc0067c	mthi zero
ffffffffbfc00680	mtlo zero
ffffffffbfc00684	mfc0 v0,Status
ffffffffbfc00688	lui t0,0x1000
ffffffffbfc0068c	or v0,v0,t0
ffffffffbfc00690	lui t0,0x4000
ffffffffbfc00694	or v0,v0,t0
ffffffffbfc00698	lui t0,0xffff
ffffffffbfc0069c	ori t0,t0,0xff
ffffffffbfc006a0	and v0,v0,t0
ffffffffbfc006a4	li t0,-0x100
ffffffffbfc006a8	and v0,v0,t0
ffffffffbfc006ac	ori v0,v0,0xe5
ffffffffbfc006b0	mtc0 v0,Status
ffffffffbfc006b4	ori v0,zero,0xc000
ffffffffbfc006b8	dsll v0,v0,0x10
ffffffffbfc006bc	ori v0,v0,0xf
ffffffffbfc006c0	mtc0 v0,HWREna
ffffffffbfc006c4	dmfc0 v0,cop0_reg9.7
ffffffffbfc006c8	mfc0 t0,PRId
ffffffffbfc006cc	lui t1,0xd
ffffffffbfc006d0	bne t0,t1,0xffffffffbfc006dc
ffffffffbfc006d4	_nop
ffffffffbfc006d8	ori v0,v0,0x2000
ffffffffbfc006dc	ori v0,v0,0x4000
ffffffffbfc006e0	dmtc0 v0,cop0_reg9.7
ffffffffbfc006e4	dmfc0 v0,cop0_reg11.7
ffffffffbfc006e8	ori v0,v0,0x104
ffffffffbfc006ec	dmtc0 v0,cop0_reg11.7
ffffffffbfc006f0	dmtc0 zero,Compare
ffffffffbfc006f4	dmtc0 zero,Count
ffffffffbfc006f8	dmtc0 zero,PerfCnt.1
ffffffffbfc006fc	dmtc0 zero,PerfCnt.3
ffffffffbfc00700	mfc0 a0,EBase
ffffffffbfc00704	andi a0,a0,0xff
ffffffffbfc00708	beq a0,zero,0xffffffffbfc00738
ffffffffbfc0070c	_nop
ffffffffbfc00710	li a1,0x8
ffffffffbfc00714	sll a1,a1,0x2
ffffffffbfc00718	mul a0,a0,a1
ffffffffbfc0071c	lui a1,0x8000
ffffffffbfc00720	ori a1,a1,0x800
ffffffffbfc00724	add a1,a1,a0
ffffffffbfc00728	lw t9,0x8(a1)
ffffffffbfc0072c	lw k0,0xc(a1)
ffffffffbfc00730	jr t9
ffffffffbfc00734	_nop
ffffffffbfc00738	dmfc0 v0,cop0_reg11.7
ffffffffbfc0073c	srl v0,v0,0x9
ffffffffbfc00740	sll v0,v0,0x9
ffffffffbfc00744	ori v0,v0,0x136
ffffffffbfc00748	dmtc0 v0,cop0_reg11.7
ffffffffbfc0074c	li sp,-0x6500
ffffffffbfc00750	bal 0xffffffffbfc00760
ffffffffbfc00754	_nop
ffffffffbfc00758	cache 0x4,0x36e0(s8)
ffffffffbfc0075c	cache 0x0,0x758(s8)
