# RV220W U-Boot v1.1.0 entry=ffffffffbfc04278 function=octeon_gpio_read_pin
ffffffffbfc04278	lui v0,0xff80
ffffffffbfc0427c	ori v0,v0,0x107
ffffffffbfc04280	dsll32 v0,v0,0x8
ffffffffbfc04284	ori v0,v0,0x880
ffffffffbfc04288	ld v0,0x0(v0)
ffffffffbfc0428c	dsrlv v0,v0,a0
ffffffffbfc04290	sll v0,v0,0x0
ffffffffbfc04294	jr ra
ffffffffbfc04298	_andi v0,v0,0x1
