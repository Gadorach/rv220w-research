# RV220W U-Boot v1.1.0 entry=ffffffffbfc22b0c function=octeon_gpio_read_pin
ffffffffbfc22b0c	lui v1,0x2
ffffffffbfc22b10	addu v1,v1,t9
ffffffffbfc22b14	addiu v1,v1,0xbd4
ffffffffbfc22b18	lw t9,0x2ec(v1)
ffffffffbfc22b1c	jr t9
ffffffffbfc22b20	_nop
