/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc251f4
 * Function: FUN_ffffffffbfc251f4
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

long FUN_ffffffffbfc251f4(long param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 unaff_s0;
  uint uVar7;
  uint uVar8;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  int iVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  uVar5 = *(uint *)(param_1 + 0x34);
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar10[3] = unaff_s3;
  uVar8 = *(uint *)(param_1 + 0x30);
  puVar10[6] = &_gp;
  puVar10[5] = unaff_s5;
  puVar10[4] = unaff_s4;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  puVar10[7] = in_ra;
  *puVar10 = unaff_s0;
  iVar9 = *(int *)(param_2 + 0xc);
  if (uVar5 < uVar8) {
    uVar5 = *(uint *)(param_1 + 0x2c);
  }
  uVar1 = *(uint *)(param_2 + 0x10);
  uVar7 = uVar5 - uVar8;
  if (uVar1 <= uVar5 - uVar8) {
    uVar7 = uVar1;
  }
  if ((uVar7 != 0) && (param_3 == -5)) {
    param_3 = 0;
  }
  iVar6 = *(int *)(param_1 + 0x38);
  *(uint *)(param_2 + 0x10) = uVar1 - uVar7;
  *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar7;
  if ((code *)(long)iVar6 != (code *)0x0) {
    uVar3 = (*(code *)(long)iVar6)(*(undefined4 *)(param_1 + 0x3c),uVar8,uVar7);
    *(undefined4 *)(param_1 + 0x3c) = uVar3;
  }
  if ((code *)(long)*(int *)(param_2 + 0x30) != (code *)0x0) {
    (*(code *)(long)*(int *)(param_2 + 0x30))(uVar8,uVar7);
  }
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar9,uVar8,uVar7);
  iVar6 = uVar8 + uVar7;
  iVar9 = iVar9 + uVar7;
  if (iVar6 == *(int *)(param_1 + 0x2c)) {
    iVar4 = *(int *)(param_1 + 0x34);
    iVar2 = *(int *)(param_1 + 0x28);
    if (iVar4 == iVar6) {
      *(int *)(param_1 + 0x34) = iVar2;
      iVar4 = *(int *)(param_1 + 0x34);
    }
    uVar5 = *(uint *)(param_2 + 0x10);
    uVar8 = iVar4 - iVar2;
    if (uVar5 <= (uint)(iVar4 - iVar2)) {
      uVar8 = uVar5;
    }
    if ((uVar8 != 0) && (param_3 == -5)) {
      param_3 = 0;
    }
    iVar6 = *(int *)(param_1 + 0x38);
    *(uint *)(param_2 + 0x10) = uVar5 - uVar8;
    *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar8;
    if ((code *)(long)iVar6 != (code *)0x0) {
      uVar3 = (*(code *)(long)iVar6)(*(undefined4 *)(param_1 + 0x3c),iVar2,uVar8);
      *(undefined4 *)(param_1 + 0x3c) = uVar3;
    }
    if ((code *)(long)*(int *)(param_2 + 0x30) != (code *)0x0) {
      (*(code *)(long)*(int *)(param_2 + 0x30))(iVar2,uVar8);
    }
    (*(code *)(long)DAT_ffffffffbfc43e84)(iVar9,iVar2,uVar8);
    iVar9 = iVar9 + uVar8;
    iVar6 = iVar2 + uVar8;
  }
  *(int *)(param_2 + 0xc) = iVar9;
  *(int *)(param_1 + 0x30) = iVar6;
  return param_3;
}

