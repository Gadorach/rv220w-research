/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc143bc
 * Function: FUN_ffffffffbfc143bc
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

long FUN_ffffffffbfc143bc(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int *piVar5;
  undefined8 in_ra;
  int iVar6;
  
  iVar6 = (int)&stack0x00000000;
  piVar5 = (int *)(long)(iVar6 + -0x30);
  *(undefined1 **)(piVar5 + 8) = &_gp;
  iVar2 = DAT_ffffffffbfc436fc;
  *(undefined8 *)(piVar5 + 6) = unaff_s1;
  *(undefined8 *)(piVar5 + 4) = unaff_s0;
  *(undefined8 *)(piVar5 + 10) = in_ra;
  lVar1 = (*(code *)(long)(iVar2 + 0x4250))(param_2,param_3,piVar5,iVar6 + -0x2c,iVar6 + -0x28);
  if (piVar5[2] == 0) {
    if (lVar1 == 0) {
      lVar1 = 1;
      (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x4aa8);
    }
  }
  else if (lVar1 == 0) {
    iVar2 = *piVar5;
    if ((*(int *)((long)DAT_ffffffffbfc43fc4 + 8) == 0xffff) || (iVar6 = piVar5[1], iVar2 < 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      if (iVar2 <= iVar6) {
        iVar4 = iVar6 - iVar2;
        iVar3 = iVar2 + DAT_ffffffffbfc43fc4 + 0x80c;
        do {
          *(char *)(long)iVar3 = (char)param_1;
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar2 <= iVar6);
        iVar4 = iVar4 + 1;
      }
    }
    if (param_1 == 0) {
      iVar2 = DAT_ffffffffbfc436f4 + -0x4ac8;
    }
    else {
      iVar2 = DAT_ffffffffbfc436f4 + -0x3ca8;
    }
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4ac0,iVar2,iVar4);
  }
  return lVar1;
}

