# RV220W U-Boot v1.1.0 entry=ffffffffbfc2c730 function=FUN_ffffffffbfc2c730
ffffffffbfc2c730	addiu sp,sp,-0x10
ffffffffbfc2c734	daddu a0,a1,zero
ffffffffbfc2c738	sd gp,0x0(sp)
ffffffffbfc2c73c	lui gp,0x1
ffffffffbfc2c740	addu gp,gp,t9
ffffffffbfc2c744	daddu a1,a2,zero
ffffffffbfc2c748	addiu gp,gp,0x6fb0
ffffffffbfc2c74c	lw t9,0x10(gp)
ffffffffbfc2c750	sd ra,0x8(sp)
ffffffffbfc2c754	addiu t9,t9,-0x3998
ffffffffbfc2c758	jalr t9
ffffffffbfc2c75c	_li a2,0x4
ffffffffbfc2c760	clear v0
ffffffffbfc2c764	ld ra,0x8(sp)
ffffffffbfc2c768	ld gp,0x0(sp)
ffffffffbfc2c76c	jr ra
ffffffffbfc2c770	_addiu sp,sp,0x10
