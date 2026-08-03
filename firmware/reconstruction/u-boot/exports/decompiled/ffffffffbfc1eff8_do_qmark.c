/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1eff8
 * Function: do_qmark
 * Subsystem: u-boot-command
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: u-boot-command
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
 * Recovered from U-Boot command table: command='help', maxargs=64, repeatable=1, usage=''.
 * 
 * Recovered from U-Boot command table: command='?', maxargs=64, repeatable=1, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: u-boot-command
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
   
   Recovered from U-Boot command table: command='help', maxargs=64, repeatable=1, usage=''.
   
   Recovered from U-Boot command table: command='?', maxargs=64, repeatable=1, usage=''. */

undefined8 do_qmark(undefined8 param_1,undefined8 param_2,int param_3,long param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  bool bVar5;
  byte *pbVar6;
  long lVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 uVar14;
  undefined8 unaff_s3;
  int iVar15;
  undefined8 unaff_s4;
  long lVar16;
  int *piVar17;
  undefined8 unaff_s8;
  undefined8 in_ra;
  int iVar18;
  
  iVar18 = (int)&stack0x00000000 + -0x60;
  lVar16 = (long)iVar18;
  *(undefined1 **)(lVar16 + 0x48) = &_gp;
  *(undefined8 *)(lVar16 + 0x50) = unaff_s8;
  *(undefined8 *)(lVar16 + 0x40) = unaff_s4;
  *(undefined8 *)(lVar16 + 0x58) = in_ra;
  *(undefined8 *)(lVar16 + 0x38) = unaff_s3;
  *(undefined8 *)(lVar16 + 0x30) = unaff_s2;
  *(undefined8 *)(lVar16 + 0x28) = unaff_s1;
  *(undefined8 *)(lVar16 + 0x20) = unaff_s0;
  if (param_3 == 1) {
    iVar11 = 0;
    iVar15 = DAT_ffffffffbfc43b1c - DAT_ffffffffbfc4404c >> 5;
    piVar17 = (int *)(long)(int)(iVar18 + (iVar15 * 4 + 0x1eU >> 4) * -0x10);
    piVar9 = piVar17;
    iVar18 = DAT_ffffffffbfc4404c;
    while( true ) {
      bVar5 = iVar15 <= iVar11;
      piVar9 = (int *)(long)((int)piVar9 + 4);
      iVar11 = iVar11 + 1;
      if (bVar5) break;
      *(int *)((long)piVar9 + -4) = iVar18;
      iVar18 = iVar18 + 0x20;
    }
    iVar18 = iVar15 + -1;
    do {
      if (iVar18 < 1) break;
      iVar13 = 0;
      piVar9 = piVar17;
      iVar11 = 0;
      do {
        iVar12 = iVar11;
        iVar4 = *piVar9;
        iVar11 = iVar12 + 1;
        pbVar6 = (byte *)(long)*(int *)(long)iVar4;
        iVar10 = *(int *)(long)piVar9[1];
        bVar1 = *pbVar6;
        do {
          bVar2 = *(byte *)(long)iVar10;
          pbVar6 = (byte *)(long)((int)pbVar6 + 1);
          iVar10 = iVar10 + 1;
          bVar3 = bVar1;
          if (bVar2 != bVar1) break;
          bVar5 = bVar1 != 0;
          bVar1 = *pbVar6;
          bVar3 = bVar2;
        } while (bVar5);
        if (0 < (int)((uint)bVar3 - (uint)bVar2)) {
          *piVar9 = piVar9[1];
          iVar13 = iVar13 + 1;
          piVar9[1] = iVar4;
        }
        piVar9 = (int *)(long)((int)piVar9 + 4);
      } while (iVar11 != iVar18);
      iVar18 = iVar12;
    } while (iVar13 != 0);
    iVar18 = 0;
    while (iVar18 < iVar15) {
      iVar11 = *piVar17;
      iVar18 = iVar18 + 1;
      piVar17 = (int *)(long)((int)piVar17 + 4);
      iVar11 = *(int *)((long)iVar11 + 0x10);
      lVar7 = (*(code *)(long)DAT_ffffffffbfc43b08)();
      if (lVar7 != 0) {
        return 1;
      }
      if (iVar11 != 0) {
        (*(code *)(long)DAT_ffffffffbfc43e38)(iVar11);
      }
    }
    uVar14 = 0;
  }
  else {
    uVar14 = 0;
    for (iVar18 = 1; iVar18 < param_3; iVar18 = iVar18 + 1) {
      puVar8 = (undefined4 *)(*(code *)(long)DAT_ffffffffbfc43be8)(*(undefined4 *)(param_4 + 4));
      if (puVar8 == (undefined4 *)0x0) {
        uVar14 = 1;
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + 0xb90,*(undefined4 *)(param_4 + 4));
      }
      else {
        (*(code *)(long)DAT_ffffffffbfc43e38)(*puVar8);
        (*(code *)(long)DAT_ffffffffbfc439f0)(0x20);
        if (puVar8[5] == 0) {
          uVar14 = 1;
          (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + 0xb78);
        }
        else {
          (*(code *)(long)DAT_ffffffffbfc43e38)(puVar8[5]);
        }
        (*(code *)(long)DAT_ffffffffbfc439f0)(10);
      }
      param_4 = (long)((int)param_4 + 4);
    }
  }
  return uVar14;
}

