/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc218e8
 * Function: FUN_ffffffffbfc218e8
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

long FUN_ffffffffbfc218e8(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  long lVar5;
  int *piVar6;
  int *piVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  uint uVar8;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  code *pcVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar10[6] = &_gp;
  puVar10[7] = in_ra;
  puVar10[5] = unaff_s5;
  pcVar9 = (code *)(long)DAT_ffffffffbfc438a8;
  puVar10[4] = unaff_s4;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  uVar8 = (param_2 + param_3) - 1;
  *puVar10 = unaff_s0;
  piVar3 = (int *)(*pcVar9)(param_2);
  piVar4 = (int *)(*(code *)(long)DAT_ffffffffbfc438a8)(uVar8);
  if (param_3 != 0) {
    if ((piVar3 == (int *)0x0) || (piVar6 = piVar3, piVar4 == (int *)0x0)) {
      return 8;
    }
    for (; piVar6 <= piVar4; piVar6 = (int *)(long)((int)piVar6 + 0xa24)) {
      piVar7 = piVar6;
      for (lVar5 = 0; lVar5 < (long)(ulong)*(ushort *)(piVar6 + 1); lVar5 = (long)((int)lVar5 + 1))
      {
        uVar2 = piVar6[3] + *piVar6;
        if (lVar5 != (short)(*(ushort *)(piVar6 + 1) - 1)) {
          uVar2 = piVar7[4];
        }
        puVar1 = (uint *)(piVar7 + 3);
        piVar7 = (int *)(long)((int)piVar7 + 4);
        if (((*puVar1 <= uVar8) && (param_2 < uVar2)) &&
           (*(char *)((long)((int)piVar6 + (int)lVar5) + 0x80c) != '\0')) {
          return 4;
        }
      }
    }
    while ((piVar3 <= piVar4 && (param_3 != 0))) {
      uVar8 = (piVar3[3] + *piVar3) - param_2;
      if (param_3 <= uVar8) {
        uVar8 = param_3;
      }
      lVar5 = (*(code *)(long)DAT_ffffffffbfc4373c)(piVar3,param_1,param_2,uVar8);
      param_3 = param_3 - uVar8;
      if (lVar5 != 0) {
        return lVar5;
      }
      param_2 = param_2 + uVar8;
      piVar3 = (int *)(long)((int)piVar3 + 0xa24);
      param_1 = param_1 + uVar8;
    }
  }
  return 0;
}

