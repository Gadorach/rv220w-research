/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1d700
 * Function: FUN_ffffffffbfc1d700
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void FUN_ffffffffbfc1d700(void)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 unaff_s0;
  long lVar6;
  undefined8 unaff_s1;
  code *pcVar7;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar8[2] = &_gp;
  puVar8[1] = unaff_s1;
  puVar8[3] = in_ra;
  pcVar7 = (code *)(long)DAT_ffffffffbfc4385c;
  *puVar8 = unaff_s0;
  lVar2 = (*pcVar7)();
  lVar3 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x2a80))(0xd0000);
  lVar6 = _DAT_80014f0000000338;
  if (lVar3 != 0) {
    if (lVar2 == 0) goto LAB_ffffffffbfc1d790;
    pcVar7 = (code *)(long)DAT_ffffffffbfc43b98;
    lVar3 = *(long *)(long)DAT_ffffffffbfc43d94 + 0x58;
    *(long *)(long)DAT_ffffffffbfc43d94 = lVar3;
    lVar6 = (*pcVar7)();
    lVar6 = lVar3 + lVar6;
  }
  (*(code *)(long)DAT_ffffffffbfc43bc4)(lVar6);
LAB_ffffffffbfc1d790:
  lVar6 = (long)*(int *)((long)((int)lVar2 * 0x20 + -0x80000000) + 0x814);
  (*(code *)(long)DAT_ffffffffbfc43f78)(*(undefined4 *)(lVar6 + 0x518));
  uVar4 = (*(code *)(long)DAT_ffffffffbfc43f64)();
  uVar1 = getCopReg(2,0);
  *(undefined4 *)(*(long *)(lVar6 + 0x528) + 9) = uVar1;
  lVar6 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x2a80))(0xd0000);
  uVar5 = uVar4 | 0x2000;
  if (lVar6 == 0) {
    uVar5 = uVar4 & 0xffffffffffffdfff;
  }
  (*(code *)(long)DAT_ffffffffbfc43ae0)(uVar5 & 0xfffff3);
  lVar6 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x2a80))(0xd0001);
  if (lVar6 != 0) {
    uVar4 = (*(code *)(long)DAT_ffffffffbfc44034)();
    (*(code *)(long)DAT_ffffffffbfc43adc)(uVar4 | 0x20000000);
  }
  (*(code *)(long)DAT_ffffffffbfc43bd0)();
  return;
}

