/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc198f4
 * Function: do_askenv
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
 * Recovered from U-Boot command table: command='askenv', maxargs=64, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='askenv', maxargs=64, repeatable=1, usage=''. */

undefined8 do_askenv(long param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar6;
  long lVar5;
  int iVar9;
  long lVar7;
  char *pcVar8;
  undefined8 uVar10;
  undefined8 unaff_s0;
  int iVar11;
  undefined8 unaff_s1;
  undefined4 *puVar12;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int iVar13;
  undefined8 unaff_s5;
  code *pcVar14;
  undefined4 *puVar15;
  undefined8 in_ra;
  int iVar16;
  
  iVar16 = (int)&stack0x00000000;
  puVar15 = (undefined4 *)(long)(iVar16 + -0x150);
  *(undefined1 **)(puVar15 + 0x50) = &_gp;
  *(undefined8 *)(puVar15 + 0x48) = unaff_s2;
  uVar3 = *param_4;
  uVar4 = param_4[1];
  *(undefined8 *)(puVar15 + 0x4e) = unaff_s5;
  *(undefined8 *)(puVar15 + 0x4a) = unaff_s3;
  *(undefined8 *)(puVar15 + 0x52) = in_ra;
  *(undefined8 *)(puVar15 + 0x4c) = unaff_s4;
  *(undefined8 *)(puVar15 + 0x46) = unaff_s1;
  *(undefined8 *)(puVar15 + 0x44) = unaff_s0;
  *puVar15 = uVar3;
  puVar15[1] = uVar4;
  puVar15[2] = 0;
  puVar15[3] = 0;
  if (param_3 < 2) {
LAB_ffffffffbfc19978:
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
    uVar10 = 1;
  }
  else {
    if (param_3 == 2) {
      lVar7 = 0xff;
      (*(code *)(long)DAT_ffffffffbfc439a4)(iVar16 + -0x140,DAT_ffffffffbfc436f4 + -0x2080);
      pcVar14 = (code *)(long)DAT_ffffffffbfc43e4c;
    }
    else {
      if (param_3 == 3) {
        (*(code *)(long)DAT_ffffffffbfc439a4)(iVar16 + -0x140,DAT_ffffffffbfc436f4 + -0x2080);
        uVar3 = param_4[2];
        iVar6 = DAT_ffffffffbfc438b0;
      }
      else {
        if (param_3 == 1) goto LAB_ffffffffbfc19978;
        iVar13 = 2;
        iVar11 = 0;
        puVar12 = param_4;
        while( true ) {
          iVar6 = DAT_ffffffffbfc438b0;
          lVar7 = (long)(iVar16 + -0x150 + iVar11);
          if ((int)param_3 + -1 <= iVar13) break;
          if (iVar11 != 0) {
            iVar11 = iVar11 + 1;
            *(undefined1 *)(lVar7 + 0x10) = 0x20;
          }
          iVar6 = puVar12[2];
          iVar9 = iVar16 + -0x140 + iVar11;
          do {
            cVar2 = *(char *)(long)iVar6;
            iVar6 = iVar6 + 1;
            *(char *)(long)iVar9 = cVar2;
            iVar9 = iVar9 + 1;
          } while (cVar2 != '\0');
          puVar1 = puVar12 + 2;
          iVar13 = iVar13 + 1;
          puVar12 = (undefined4 *)(long)((int)puVar12 + 4);
          iVar6 = (*(code *)(long)DAT_ffffffffbfc437c8)(*puVar1);
          iVar11 = iVar11 + iVar6;
        }
        uVar3 = *(undefined4 *)((long)((int)param_3 * 4 + (int)param_4) + -4);
        *(undefined1 *)(lVar7 + 0x10) = 0;
      }
      lVar7 = (*(code *)(long)iVar6)(uVar3,0,10);
      if (lVar7 < 0x100) {
        pcVar14 = (code *)(long)DAT_ffffffffbfc43e4c;
        if (lVar7 < 1) {
          return 1;
        }
      }
      else {
        lVar7 = 0xff;
        pcVar14 = (code *)(long)DAT_ffffffffbfc43e4c;
      }
    }
    lVar5 = (*pcVar14)(iVar16 + -0x140);
    iVar16 = DAT_ffffffffbfc44084;
    pcVar8 = (char *)(long)DAT_ffffffffbfc44084;
    if (lVar7 < lVar5) {
      *(undefined1 *)(long)((int)lVar7 + DAT_ffffffffbfc44084) = 0;
    }
    uVar10 = 2;
    if (*pcVar8 != '\0') {
      puVar15[2] = iVar16;
      uVar10 = 3;
    }
    uVar10 = (*(code *)(long)DAT_ffffffffbfc43e0c)(param_2,uVar10,puVar15);
  }
  return uVar10;
}

