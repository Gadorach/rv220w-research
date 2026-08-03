# RV220W U-Boot v1.1.0 entry=ffffffffbfc1b79c function=FUN_ffffffffbfc1b79c
ffffffffbfc1b79c	sll v0,a0,0x0
ffffffffbfc1b7a0	dsra32 a0,a0,0x0
ffffffffbfc1b7a4	dsll32 a0,a0,0x0
ffffffffbfc1b7a8	dsll32 v0,v0,0x0
ffffffffbfc1b7ac	dsrl32 v0,v0,0x0
ffffffffbfc1b7b0	daddu a0,a0,v0
ffffffffbfc1b7b4	dmtc0 a0,EntryHi
ffffffffbfc1b7b8	sll v0,a1,0x0
ffffffffbfc1b7bc	dsra32 a1,a1,0x0
ffffffffbfc1b7c0	dsll32 a1,a1,0x0
ffffffffbfc1b7c4	dsll32 v0,v0,0x0
ffffffffbfc1b7c8	dsrl32 v0,v0,0x0
ffffffffbfc1b7cc	daddu a1,a1,v0
ffffffffbfc1b7d0	dmtc0 a1,EntryLo0
ffffffffbfc1b7d4	sll v0,a2,0x0
ffffffffbfc1b7d8	dsra32 a2,a2,0x0
ffffffffbfc1b7dc	dsll32 a2,a2,0x0
ffffffffbfc1b7e0	dsll32 v0,v0,0x0
ffffffffbfc1b7e4	dsrl32 v0,v0,0x0
ffffffffbfc1b7e8	daddu a2,a2,v0
ffffffffbfc1b7ec	dmtc0 a2,EntryLo1
ffffffffbfc1b7f0	sll v0,a3,0x0
ffffffffbfc1b7f4	dsra32 a3,a3,0x0
ffffffffbfc1b7f8	dsll32 a3,a3,0x0
ffffffffbfc1b7fc	dsll32 v0,v0,0x0
ffffffffbfc1b800	dsrl32 v0,v0,0x0
ffffffffbfc1b804	daddu a3,a3,v0
ffffffffbfc1b808	dmtc0 a3,PageMask
ffffffffbfc1b80c	dsra32 v1,t0,0x0
ffffffffbfc1b810	sll v0,t0,0x0
ffffffffbfc1b814	dsll32 v1,v1,0x0
ffffffffbfc1b818	dsll32 v0,v0,0x0
ffffffffbfc1b81c	dsrl32 v0,v0,0x0
ffffffffbfc1b820	daddu v1,v1,v0
ffffffffbfc1b824	dmtc0 v1,Index
ffffffffbfc1b828	daddiu t0,t0,0x1
ffffffffbfc1b82c	sll v0,t0,0x0
ffffffffbfc1b830	dsra32 t0,t0,0x0
ffffffffbfc1b834	dsll32 t0,t0,0x0
ffffffffbfc1b838	dsll32 v0,v0,0x0
ffffffffbfc1b83c	dsrl32 v0,v0,0x0
ffffffffbfc1b840	daddu t0,t0,v0
ffffffffbfc1b844	dmtc0 t0,Wired
ffffffffbfc1b848	ehb
ffffffffbfc1b84c	tlbwi
ffffffffbfc1b850	ehb
ffffffffbfc1b854	jr ra
ffffffffbfc1b858	_nop
