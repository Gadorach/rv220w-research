/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1b0c4
 * Function: do_pci
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
 * Subsystem: u-boot-command
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: u-boot-command
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Recovered from U-Boot command table: command='pci', maxargs=5, repeatable=1, usage=''.
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
   Subsystem: u-boot-command
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='pci', maxargs=5, repeatable=1, usage=''. */

undefined8 do_pci(undefined4 param_1,undefined8 param_2,long param_3,long param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  long lVar5;
  uint uVar8;
  undefined4 uVar9;
  undefined8 uVar6;
  long lVar7;
  ulong uVar10;
  char *pcVar11;
  byte *pbVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  undefined8 unaff_s0;
  undefined8 uVar16;
  undefined8 unaff_s1;
  int iVar17;
  undefined8 unaff_s2;
  uint uVar18;
  undefined8 unaff_s3;
  uint uVar19;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  uint uVar20;
  undefined8 unaff_s6;
  int iVar21;
  undefined8 unaff_s7;
  undefined4 *puVar22;
  code *pcVar23;
  byte *pbVar24;
  undefined8 unaff_s8;
  char *pcVar27;
  undefined8 in_ra;
  int iVar25;
  int iVar26;
  
  iVar26 = (int)&stack0x00000000;
  iVar25 = iVar26 + -0x90;
  pbVar24 = (byte *)(long)iVar25;
  *(undefined1 **)(pbVar24 + 0x70) = &_gp;
  *(undefined8 *)(pbVar24 + 0x50) = unaff_s4;
  *(undefined8 *)(pbVar24 + 0x30) = unaff_s0;
  *(undefined8 *)(pbVar24 + 0x80) = in_ra;
  *(undefined8 *)(pbVar24 + 0x78) = unaff_s8;
  *(undefined8 *)(pbVar24 + 0x68) = unaff_s7;
  *(undefined8 *)(pbVar24 + 0x60) = unaff_s6;
  *(undefined8 *)(pbVar24 + 0x58) = unaff_s5;
  *(undefined8 *)(pbVar24 + 0x48) = unaff_s3;
  *(undefined8 *)(pbVar24 + 0x40) = unaff_s2;
  *(undefined8 *)(pbVar24 + 0x38) = unaff_s1;
  *(undefined4 *)(pbVar24 + 0x2c) = param_1;
  if (param_3 < 2) {
    uVar16 = 1;
  }
  else {
    pbVar12 = (byte *)(long)*(int *)(param_4 + 4);
    *(int *)(pbVar24 + 0x28) = (int)param_4 + 4;
    if (((long)(int)(*pbVar12 - 100) & 0xffU) < 0x14) {
      uVar10 = 1L << (long)(int)(*pbVar12 - 100);
      if ((uVar10 & 0x80601) != 0) {
        lVar5 = (*(code *)(long)DAT_ffffffffbfc43ae8)(pbVar12,4);
        if (param_3 < 4) {
          pbVar24[0x24] = 0;
          pbVar24[0x25] = 0;
          pbVar24[0x26] = 0;
          pbVar24[0x27] = 0;
        }
        else {
          uVar9 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 0xc),0,0x10);
          *(undefined4 *)(pbVar24 + 0x24) = uVar9;
        }
        if (param_3 < 5) {
          lVar7 = (long)*(int *)(pbVar24 + 0x2c);
          if (param_3 == 2) goto LAB_ffffffffbfc1b56c;
          uVar8 = 0;
        }
        else {
          uVar8 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 0x10),0,0x10);
        }
        iVar2 = *(int *)(param_4 + 8);
        uVar9 = *(undefined4 *)((long)(DAT_ffffffffbfc436f0 + 0x64a0) + 8);
        uVar3 = *(undefined4 *)((long)(DAT_ffffffffbfc436f0 + 0x64a0) + 4);
        pcVar23 = (code *)(long)DAT_ffffffffbfc437c8;
        *(undefined4 *)(pbVar24 + 0x14) = *(undefined4 *)((long)DAT_ffffffffbfc436f0 + 0x64a0);
        *(undefined4 *)(pbVar24 + 0x18) = uVar3;
        *(undefined4 *)(pbVar24 + 0x1c) = uVar9;
        uVar9 = (*pcVar23)(iVar2);
        *(undefined4 *)(pbVar24 + 0x20) = uVar9;
        if (8 < *(int *)(pbVar24 + 0x20)) {
          return 1;
        }
        iVar17 = 0;
        iVar15 = 0;
        iVar21 = 0;
        puVar22 = (undefined4 *)(long)(iVar26 + -0x7c);
        while( true ) {
          pcVar27 = (char *)(long)(iVar26 + -0x88);
          pcVar13 = (char *)(long)(iVar2 + iVar15);
          pcVar11 = pcVar27;
          if (*(int *)(pbVar24 + 0x20) <= iVar17) break;
          if (*(char *)(long)(iVar2 + iVar17) == '.') {
            iVar21 = iVar21 + 1;
            (*(code *)(long)DAT_ffffffffbfc43e84)(pcVar27,pcVar13,iVar17 - iVar15);
            pcVar23 = (code *)(long)DAT_ffffffffbfc438b0;
            *(undefined1 *)((long)(iVar25 + (iVar17 - iVar15)) + 8) = 0;
            uVar9 = (*pcVar23)(pcVar27,0,0x10);
            iVar15 = iVar17 + 1;
            *puVar22 = uVar9;
            puVar22 = (undefined4 *)(long)((int)puVar22 + 4);
          }
          iVar17 = iVar17 + 1;
        }
        do {
          cVar1 = *pcVar13;
          pcVar13 = (char *)(long)((int)pcVar13 + 1);
          *pcVar11 = cVar1;
          pcVar11 = (char *)(long)((int)pcVar11 + 1);
        } while (cVar1 != '\0');
        if (iVar21 == 0) {
          iVar21 = 1;
        }
        uVar9 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar27,0,0x10);
        *(undefined4 *)((long)(iVar21 * 4 + iVar25) + 0x14) = uVar9;
        uVar4 = *(int *)(pbVar24 + 0x14) << 0x10 | *(int *)(pbVar24 + 0x18) << 0xb |
                *(int *)(pbVar24 + 0x1c) << 8;
        if (uVar4 == 0xffffffff) {
          return 1;
        }
        cVar1 = *(char *)(long)*(int *)(long)*(int *)(pbVar24 + 0x28);
        if (cVar1 == 'm') {
          uVar9 = *(undefined4 *)(pbVar24 + 0x24);
          if (param_3 != 3) {
            uVar16 = 1;
LAB_ffffffffbfc1b524:
            uVar16 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x50d4))
                               (uVar4,uVar9,lVar5,uVar8,uVar16);
            return uVar16;
          }
        }
        else {
          if (cVar1 < 'n') {
            if (cVar1 == 'd') {
              uVar20 = (uint)lVar5;
              if ((uVar8 == 0) && (uVar8 = 0x40 / uVar20, lVar5 == 0)) {
                trap(7);
              }
              uVar8 = uVar8 * uVar20;
              while( true ) {
                uVar19 = 0;
                (*(code *)(long)DAT_ffffffffbfc4400c)
                          (DAT_ffffffffbfc436f4 + -0x3ca0,*(undefined4 *)(pbVar24 + 0x24));
                uVar18 = 0x10;
                if (uVar8 < 0x11) {
                  uVar18 = uVar8;
                }
                while( true ) {
                  if (uVar18 <= uVar19) break;
                  if (lVar5 == 4) {
                    (*(code *)(long)DAT_ffffffffbfc43d88)
                              (uVar4,*(undefined4 *)(pbVar24 + 0x24),iVar26 + -0x8c);
                    pcVar23 = (code *)(long)DAT_ffffffffbfc4400c;
                    uVar14 = *(uint *)(pbVar24 + 4);
                    iVar25 = DAT_ffffffffbfc436f4 + -0x3c98;
                  }
                  else if (lVar5 == 2) {
                    (*(code *)(long)DAT_ffffffffbfc43b3c)
                              (uVar4,*(undefined4 *)(pbVar24 + 0x24),iVar26 + -0x8e);
                    pcVar23 = (code *)(long)DAT_ffffffffbfc4400c;
                    uVar14 = (uint)*(ushort *)(pbVar24 + 2);
                    iVar25 = DAT_ffffffffbfc436f4 + -0x3c90;
                  }
                  else {
                    (*(code *)(long)DAT_ffffffffbfc437d4)
                              (uVar4,*(undefined4 *)(pbVar24 + 0x24),pbVar24);
                    pcVar23 = (code *)(long)DAT_ffffffffbfc4400c;
                    uVar14 = (uint)*pbVar24;
                    iVar25 = DAT_ffffffffbfc436f4 + -0x3c88;
                  }
                  uVar19 = uVar19 + uVar20;
                  (*pcVar23)(iVar25,uVar14);
                  *(uint *)(pbVar24 + 0x24) = *(int *)(pbVar24 + 0x24) + uVar20;
                }
                (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
                lVar7 = (*(code *)(long)DAT_ffffffffbfc43b08)();
                uVar8 = uVar8 - uVar18;
                if (lVar7 != 0) break;
                if (uVar8 == 0) {
                  return 0;
                }
              }
              return 1;
            }
            if (cVar1 != 'h') {
              return 1;
            }
            (*(code *)(long)DAT_ffffffffbfc43db8)(uVar4);
            return 0;
          }
          if (cVar1 != 'n') {
            if (cVar1 != 'w') {
              return 1;
            }
            lVar7 = (long)*(int *)(pbVar24 + 0x2c);
            if (4 < param_3) {
              uVar16 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x5144))
                                 (uVar4,*(undefined4 *)(pbVar24 + 0x24),lVar5,uVar8);
              return uVar16;
            }
            goto LAB_ffffffffbfc1b56c;
          }
          uVar9 = *(undefined4 *)(pbVar24 + 0x24);
          if (param_3 != 3) {
            uVar16 = 0;
            goto LAB_ffffffffbfc1b524;
          }
        }
        lVar7 = (long)*(int *)(pbVar24 + 0x2c);
LAB_ffffffffbfc1b56c:
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(lVar7 + 0x10));
        return 1;
      }
      uVar9 = getCopReg(2,4);
      *(undefined4 *)(uVar10 + 0x1a) = uVar9;
    }
    uVar16 = 1;
    if ((*(char *)(long)*(int *)((long)((int)param_3 * 4 + (int)param_4) + -4) != 'l') ||
       (uVar16 = 0, 1 < (int)param_3 + -1)) {
      uVar6 = (*(code *)(long)DAT_ffffffffbfc438b0)(pbVar12,0,0x10);
      goto LAB_ffffffffbfc1b354;
    }
  }
  uVar6 = 0;
LAB_ffffffffbfc1b354:
  (*(code *)(long)DAT_ffffffffbfc43820)(uVar6,uVar16);
  return 0;
}

