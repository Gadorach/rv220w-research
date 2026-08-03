/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc17c88
 * Function: do_md
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
 * Recovered from U-Boot command table: command='md', maxargs=3, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='md', maxargs=3, repeatable=1, usage=''. */

undefined8 do_md(long param_1,long param_2,long param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  long lVar6;
  int iVar8;
  int iVar9;
  long lVar7;
  undefined8 uVar10;
  int iVar11;
  undefined8 unaff_s0;
  uint uVar12;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  uint uVar13;
  undefined8 unaff_s4;
  undefined4 *puVar14;
  undefined8 unaff_s5;
  undefined4 *puVar15;
  undefined8 unaff_s6;
  undefined4 *puVar16;
  undefined8 unaff_s7;
  uint uVar17;
  code *pcVar18;
  undefined4 *puVar19;
  undefined8 unaff_s8;
  undefined8 in_ra;
  int iVar20;
  
  iVar20 = (int)&stack0x00000000 + -0x80;
  puVar19 = (undefined4 *)(long)iVar20;
  *(undefined1 **)(puVar19 + 0x18) = &_gp;
  *(undefined8 *)(puVar19 + 10) = unaff_s1;
  *(undefined8 *)(puVar19 + 0xe) = unaff_s3;
  *(undefined8 *)(puVar19 + 0x1a) = unaff_s8;
  puVar4 = (undefined4 *)(long)DAT_ffffffffbfc44088;
  *(undefined8 *)(puVar19 + 8) = unaff_s0;
  uVar1 = *puVar4;
  piVar5 = (int *)(long)DAT_ffffffffbfc43f98;
  *(undefined8 *)(puVar19 + 0x1c) = in_ra;
  *(undefined8 *)(puVar19 + 0x16) = unaff_s7;
  *(undefined8 *)(puVar19 + 0x14) = unaff_s6;
  *(undefined8 *)(puVar19 + 0x12) = unaff_s5;
  *(undefined8 *)(puVar19 + 0x10) = unaff_s4;
  *(undefined8 *)(puVar19 + 0xc) = unaff_s2;
  iVar9 = *piVar5;
  if (param_3 < 2) {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
    uVar10 = 1;
  }
  else {
    uVar2 = getCopReg(2,0);
    *(undefined4 *)(param_2 + 0x1b) = uVar2;
    lVar6 = (*(code *)(long)DAT_ffffffffbfc43ae8)(*param_4,4,uVar1);
    if (lVar6 < 0) {
      uVar10 = 1;
    }
    else {
      iVar8 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[1],0,0x10);
      puVar4 = (undefined4 *)(long)(iVar8 + *(int *)((long)DAT_ffffffffbfc436f4 + 0x4bf0));
      if (param_3 != 2) {
        iVar9 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[2],0,0x10);
      }
      iVar8 = (int)lVar6;
      uVar13 = iVar9 * iVar8;
      do {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3ca0,puVar4);
        uVar17 = 0x10;
        if (uVar13 < 0x11) {
          uVar17 = uVar13;
        }
        puVar19[4] = iVar20;
        uVar12 = 0;
        puVar14 = puVar19;
        puVar15 = puVar19;
        puVar16 = puVar19;
        while( true ) {
          iVar3 = DAT_ffffffffbfc436f4;
          pcVar18 = (code *)(long)DAT_ffffffffbfc4400c;
          iVar11 = DAT_ffffffffbfc436f4 + -0x3c98;
          if (uVar17 <= uVar12) break;
          if (lVar6 == 4) {
            *puVar16 = *puVar4;
            puVar16 = (undefined4 *)(long)((int)puVar16 + 4);
          }
          else if (lVar6 == 2) {
            *(undefined2 *)puVar15 = *(undefined2 *)puVar4;
            puVar15 = (undefined4 *)(long)((int)puVar15 + 2);
            iVar11 = iVar3 + -0x3c90;
          }
          else {
            *(undefined1 *)puVar14 = *(undefined1 *)puVar4;
            puVar14 = (undefined4 *)(long)((int)puVar14 + 1);
            iVar11 = iVar3 + -0x3c88;
          }
          puVar4 = (undefined4 *)(long)((int)puVar4 + iVar8);
          (*pcVar18)(iVar11);
          uVar12 = uVar12 + iVar8;
        }
        uVar12 = 0;
        (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x3b48);
        pcVar18 = (code *)(long)DAT_ffffffffbfc439f0;
        while( true ) {
          if (uVar12 == uVar17) break;
          if ((byte)(*(char *)(long)(int)(puVar19[4] + uVar12) - 0x20U) < 0x5f) {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3b40);
            uVar12 = uVar12 + 1;
            pcVar18 = (code *)(long)DAT_ffffffffbfc439f0;
          }
          else {
            uVar12 = uVar12 + 1;
            (*pcVar18)(0x2e);
            pcVar18 = (code *)(long)DAT_ffffffffbfc439f0;
          }
        }
        (*pcVar18)(10);
        lVar7 = (*(code *)(long)DAT_ffffffffbfc43b08)();
        uVar13 = uVar13 - uVar17;
        if (lVar7 != 0) {
          uVar10 = 1;
          goto LAB_ffffffffbfc17ed8;
        }
      } while (uVar13 != 0);
      uVar10 = 0;
LAB_ffffffffbfc17ed8:
      *(int *)(long)DAT_ffffffffbfc43d1c = (int)puVar4;
      *(int *)(long)DAT_ffffffffbfc43f98 = iVar9;
      *(int *)(long)DAT_ffffffffbfc44088 = iVar8;
    }
  }
  return uVar10;
}

