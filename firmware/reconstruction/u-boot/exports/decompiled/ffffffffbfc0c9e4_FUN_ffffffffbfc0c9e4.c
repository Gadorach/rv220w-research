/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0c9e4
 * Function: FUN_ffffffffbfc0c9e4
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

bool FUN_ffffffffbfc0c9e4
               (undefined4 param_1,long param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  int iVar3;
  undefined8 uVar2;
  undefined8 unaff_s0;
  int iVar4;
  undefined8 unaff_s1;
  undefined4 uVar5;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int *piVar6;
  undefined8 unaff_s5;
  int *piVar7;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar8;
  undefined8 *puVar9;
  undefined8 unaff_s8;
  int iVar10;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x60);
  puVar9[8] = &_gp;
  puVar9[7] = unaff_s7;
  puVar9[6] = unaff_s6;
  puVar9[3] = unaff_s3;
  puVar9[2] = unaff_s2;
  puVar9[1] = unaff_s1;
  puVar9[10] = in_ra;
  puVar9[9] = unaff_s8;
  puVar9[5] = unaff_s5;
  puVar9[4] = unaff_s4;
  *puVar9 = unaff_s0;
  if (param_2 == 0) {
    param_2 = -1;
    uVar5 = DAT_ffffffffbfc43e14;
  }
  else {
    uVar5 = param_1;
    if (param_2 == -1) {
      uVar5 = DAT_ffffffffbfc43e14;
    }
  }
  piVar6 = (int *)(long)DAT_ffffffffbfc43e40;
  iVar10 = (int)param_5 + 0x1c;
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43ab4)(uVar5,DAT_ffffffffbfc43a74,6);
  piVar7 = (int *)(long)DAT_ffffffffbfc43904;
  pcVar8 = (code *)(long)DAT_ffffffffbfc43cf8;
  if (lVar1 != 0) {
    iVar4 = *piVar7;
    iVar3 = (*pcVar8)(iVar4,uVar5,0x800);
    iVar4 = iVar4 + iVar3;
    (*(code *)(long)DAT_ffffffffbfc43a4c)(iVar4,param_2,param_3,param_4,param_5);
    (*(code *)(long)DAT_ffffffffbfc4376c)(*piVar7,(iVar4 - *piVar7) + iVar10);
  }
  else {
    iVar4 = *piVar6;
    *(int *)(long)DAT_ffffffffbfc43dcc = (int)param_2;
    *(undefined4 *)(long)DAT_ffffffffbfc44010 = uVar5;
    iVar3 = (*pcVar8)(iVar4,uVar5,0x800);
    iVar4 = iVar4 + iVar3;
    (*(code *)(long)DAT_ffffffffbfc43a4c)(iVar4,param_2,param_3,param_4,param_5);
    (*(code *)(long)DAT_ffffffffbfc43e84)(iVar4 + 0x1c,(iVar4 - *piVar6) + *piVar7 + 0x1c,param_5);
    pcVar8 = (code *)(long)DAT_ffffffffbfc43d0c;
    *(int *)(long)DAT_ffffffffbfc43e74 = (iVar4 - *piVar6) + iVar10;
    *(undefined4 *)(long)DAT_ffffffffbfc44020 = 1;
    uVar2 = (*pcVar8)(0);
    pcVar8 = (code *)(long)DAT_ffffffffbfc43b90;
    *(undefined8 *)(long)DAT_ffffffffbfc4372c = uVar2;
    (*pcVar8)();
  }
  return lVar1 == 0;
}

