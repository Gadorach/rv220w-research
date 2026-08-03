/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc19bb4
 * Function: do_printenv
 * Subsystem: nor-environment
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: nor-environment
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
 * 
 * Recovered from U-Boot command table: command='printenv', maxargs=64, repeatable=1, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: nor-environment
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='printenv', maxargs=64, repeatable=1, usage=''. */

int do_printenv(undefined8 param_1,undefined8 param_2,int param_3,long param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  undefined8 unaff_s0;
  int iVar6;
  undefined8 unaff_s1;
  int iVar7;
  undefined8 unaff_s2;
  int iVar8;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  int iVar9;
  undefined8 unaff_s7;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar10[8] = &_gp;
  puVar10[7] = unaff_s7;
  puVar10[9] = in_ra;
  puVar10[6] = unaff_s6;
  puVar10[5] = unaff_s5;
  puVar10[4] = unaff_s4;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  *puVar10 = unaff_s0;
  if (param_3 == 1) {
    iVar6 = 0;
    do {
      lVar4 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar6);
      iVar9 = iVar6;
      if (lVar4 == 0) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2058,iVar6,0x1fffc);
        return 0;
      }
      do {
        iVar8 = iVar9;
        lVar4 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar8);
        iVar9 = iVar8 + 1;
      } while (lVar4 != 0);
      while (iVar6 < iVar8) {
        uVar3 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar6);
        (*(code *)(long)DAT_ffffffffbfc439f0)(uVar3);
        iVar6 = iVar6 + 1;
      }
      (*(code *)(long)DAT_ffffffffbfc439f0)(10);
      lVar4 = (*(code *)(long)DAT_ffffffffbfc43b08)();
      iVar6 = iVar8 + 1;
    } while (lVar4 == 0);
    iVar6 = 1;
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x2068);
  }
  else {
    iVar6 = 0;
    for (iVar9 = 1; iVar8 = 0, iVar9 < param_3; iVar9 = iVar9 + 1) {
      uVar1 = *(undefined4 *)(param_4 + 4);
      iVar5 = -1;
      while( true ) {
        lVar4 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar8);
        iVar2 = iVar8;
        if (lVar4 == 0) goto LAB_ffffffffbfc19d90;
        do {
          iVar7 = iVar2;
          lVar4 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar7);
          iVar2 = iVar7 + 1;
        } while (lVar4 != 0);
        iVar5 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x71f0))(uVar1,iVar8);
        if (-1 < iVar5) break;
        iVar8 = iVar7 + 1;
      }
      (*(code *)(long)DAT_ffffffffbfc43e38)(uVar1);
      uVar3 = 0x3d;
      while( true ) {
        (*(code *)(long)DAT_ffffffffbfc439f0)(uVar3);
        if (iVar7 <= iVar5) break;
        uVar3 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar5);
        iVar5 = iVar5 + 1;
      }
      (*(code *)(long)DAT_ffffffffbfc439f0)(10);
LAB_ffffffffbfc19d90:
      if (iVar5 < 0) {
        iVar6 = iVar6 + 1;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5310,uVar1);
      }
      param_4 = (long)((int)param_4 + 4);
    }
  }
  return iVar6;
}

