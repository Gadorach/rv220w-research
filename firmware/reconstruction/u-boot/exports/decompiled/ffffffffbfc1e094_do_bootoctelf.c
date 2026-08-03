/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1e094
 * Function: do_bootoctelf
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
 * Recovered from U-Boot command table: command='bootoctelf', maxargs=32, repeatable=0, usage=''.
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
   
   Recovered from U-Boot command table: command='bootoctelf', maxargs=32, repeatable=0, usage=''. */

undefined8 do_bootoctelf(undefined8 param_1,undefined8 param_2,int param_3,long param_4)

{
  char cVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar6;
  char cVar7;
  ulong uVar5;
  int iVar8;
  int iVar10;
  int iVar11;
  long lVar9;
  uint uVar12;
  char *pcVar13;
  char *pcVar14;
  int iVar15;
  undefined8 unaff_s0;
  ulong uVar16;
  uint *puVar17;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  ulong uVar18;
  undefined8 unaff_s3;
  long lVar19;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 uVar20;
  undefined8 unaff_s7;
  ulong uVar21;
  code *pcVar22;
  long lVar23;
  undefined8 unaff_s8;
  int iVar24;
  undefined8 in_ra;
  
  iVar11 = (int)&stack0x00000000;
  lVar23 = (long)(iVar11 + -0xa0);
  *(undefined1 **)(lVar23 + 0x80) = &_gp;
  *(undefined8 *)(lVar23 + 0x68) = unaff_s5;
  *(undefined8 *)(lVar23 + 0x60) = unaff_s4;
  *(undefined8 *)(lVar23 + 0x90) = in_ra;
  *(undefined8 *)(lVar23 + 0x88) = unaff_s8;
  *(undefined8 *)(lVar23 + 0x78) = unaff_s7;
  *(undefined8 *)(lVar23 + 0x70) = unaff_s6;
  *(undefined8 *)(lVar23 + 0x58) = unaff_s3;
  *(undefined8 *)(lVar23 + 0x50) = unaff_s2;
  *(undefined8 *)(lVar23 + 0x48) = unaff_s1;
  *(undefined8 *)(lVar23 + 0x40) = unaff_s0;
  if (param_3 < 2) {
    uVar21 = 0;
    uVar18 = (ulong)*(int *)(long)DAT_ffffffffbfc43d48;
  }
  else if (param_3 == 2) {
    uVar18 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 4),0,0x10);
    if (uVar18 == 0) {
      uVar18 = (ulong)*(int *)(long)DAT_ffffffffbfc43d48;
    }
    uVar21 = 0;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 8);
  }
  else {
    uVar18 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 4),0,0x10);
    if (uVar18 == 0) {
      uVar18 = (ulong)*(int *)(long)DAT_ffffffffbfc43d48;
    }
    uVar21 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 8),0,0x10);
  }
  *(undefined4 *)(lVar23 + 0x34) = 0;
  uVar16 = 1;
  *(undefined4 *)(lVar23 + 0x30) = 0;
  lVar19 = 0;
  uVar20 = 0;
  lVar9 = param_4;
  for (iVar24 = 3; iVar24 < param_3; iVar24 = iVar24 + 1) {
    iVar8 = 0xb;
    iVar10 = *(int *)(lVar9 + 0xc);
    pcVar14 = (char *)(long)iVar10;
    iVar6 = DAT_ffffffffbfc436f4 + -0xcd8;
    pcVar13 = pcVar14;
    while( true ) {
      cVar1 = *pcVar13;
      cVar2 = *(char *)(long)iVar6;
      cVar7 = cVar2;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar13 = (char *)(long)((int)pcVar13 + 1);
      cVar7 = cVar1;
      if ((cVar2 != cVar1) || (iVar6 = iVar6 + 1, cVar7 = cVar2, cVar1 == '\0')) break;
    }
    if (cVar7 == cVar2) {
      iVar10 = iVar10 + 9;
LAB_ffffffffbfc1e26c:
      uVar16 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar10,0,0);
    }
    else {
      iVar15 = 9;
      iVar8 = 9;
      iVar6 = DAT_ffffffffbfc436f4 + -0xcc8;
      pcVar13 = pcVar14;
      while( true ) {
        cVar1 = *pcVar13;
        cVar2 = *(char *)(long)iVar6;
        cVar7 = cVar2;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar13 = (char *)(long)((int)pcVar13 + 1);
        cVar7 = cVar1;
        if ((cVar2 != cVar1) || (iVar6 = iVar6 + 1, cVar7 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar7 == cVar2) {
        pcVar22 = (code *)(long)DAT_ffffffffbfc43a54;
        iVar10 = iVar11 + -0x90;
        uVar3 = *(undefined2 *)((long)DAT_ffffffffbfc436f0 + 0x64e0);
        *(undefined1 *)(lVar23 + 0x12) = *(undefined1 *)((long)(DAT_ffffffffbfc436f0 + 0x64e0) + 2);
        *(undefined2 *)(lVar23 + 0x10) = uVar3;
        (*pcVar22)(iVar11 + -0x8d,0,0x11);
        (*(code *)(long)DAT_ffffffffbfc43a9c)(iVar10,*(int *)(lVar9 + 0xc) + 9,10);
        goto LAB_ffffffffbfc1e26c;
      }
      iVar8 = 9;
      iVar6 = DAT_ffffffffbfc436f4 + -0xcb8;
      pcVar13 = pcVar14;
      while( true ) {
        cVar1 = *pcVar13;
        cVar2 = *(char *)(long)iVar6;
        cVar7 = cVar2;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar13 = (char *)(long)((int)pcVar13 + 1);
        cVar7 = cVar1;
        if ((cVar2 != cVar1) || (iVar6 = iVar6 + 1, cVar7 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar7 == cVar2) {
        *(undefined4 *)(lVar23 + 0x34) = 1;
      }
      else {
        iVar8 = 5;
        iVar6 = DAT_ffffffffbfc436f4 + -0xd00;
        pcVar13 = pcVar14;
        while( true ) {
          cVar1 = *pcVar13;
          cVar2 = *(char *)(long)iVar6;
          cVar7 = cVar2;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar13 = (char *)(long)((int)pcVar13 + 1);
          cVar7 = cVar1;
          if ((cVar2 != cVar1) || (iVar6 = iVar6 + 1, cVar7 = cVar2, cVar1 == '\0')) break;
        }
        if (cVar7 == cVar2) {
          *(uint *)(lVar23 + 0x30) = *(uint *)(lVar23 + 0x30) | 2;
        }
        else {
          iVar6 = DAT_ffffffffbfc436f4 + -0xca8;
          pcVar13 = pcVar14;
          while( true ) {
            cVar1 = *pcVar13;
            cVar2 = *(char *)(long)iVar6;
            cVar7 = cVar2;
            if (iVar15 == 0) break;
            iVar15 = iVar15 + -1;
            pcVar13 = (char *)(long)((int)pcVar13 + 1);
            cVar7 = cVar1;
            if ((cVar2 != cVar1) || (iVar6 = iVar6 + 1, cVar7 = cVar2, cVar1 == '\0')) break;
          }
          if (cVar7 == cVar2) {
            lVar19 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar10 + 9,0,0);
          }
          else {
            iVar8 = 10;
            iVar6 = DAT_ffffffffbfc436f4 + -0xc98;
            while( true ) {
              cVar1 = *pcVar14;
              cVar2 = *(char *)(long)iVar6;
              cVar7 = cVar2;
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              pcVar14 = (char *)(long)((int)pcVar14 + 1);
              cVar7 = cVar1;
              if ((cVar2 != cVar1) || (iVar6 = iVar6 + 1, cVar7 = cVar2, cVar1 == '\0')) break;
            }
            if (cVar7 == cVar2) {
              uVar20 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar10 + 10,0,0);
            }
          }
        }
      }
    }
    lVar9 = (long)((int)lVar9 + 4);
  }
  if (lVar19 != 0) {
    uVar16 = (*(code *)(long)DAT_ffffffffbfc43ee0)((int)lVar19 + (int)uVar20);
    uVar5 = (*(code *)(long)DAT_ffffffffbfc43ee0)(uVar20);
    uVar16 = uVar16 & ~uVar5;
  }
  uVar16 = (*(code *)(long)DAT_ffffffffbfc43d28)(uVar16);
  if (uVar16 == 0) {
    iVar11 = DAT_ffffffffbfc436f4 + -0xc78;
LAB_ffffffffbfc1e528:
    (*(code *)(long)DAT_ffffffffbfc4400c)(iVar11);
    uVar20 = 0;
  }
  else {
    if ((long)uVar16 < 0) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0xc38);
      return 1;
    }
    lVar9 = (long)DAT_ffffffffbfc436f4;
    if (*(int *)(lVar9 + 0x4c20) == 0) {
      uVar4 = *(undefined4 *)(long)DAT_ffffffffbfc43c00;
      *(undefined4 *)(long)DAT_ffffffffbfc43c00 = 0;
      *(undefined4 *)(lVar9 + 0x4c20) = uVar4;
    }
    lVar9 = special2(uVar16,0,0,0x2c);
    if (lVar9 != 1) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x78);
    }
    lVar9 = (*(code *)(long)DAT_ffffffffbfc43bd8)(uVar18);
    if (lVar9 == 0) {
      return 1;
    }
    if ((uVar16 & (long)*(int *)(long)DAT_ffffffffbfc43828) == 0) {
      if (*(char *)(uVar18 + 4) == '\x01') {
        if (uVar21 != 0) {
          uVar12 = *(uint *)(uVar18 + 0x18) & 0x7ff00000;
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0xe0,uVar12,uVar21);
          lVar9 = (*(code *)(long)DAT_ffffffffbfc43a08)
                            (uVar21 & 0xffffffff,uVar12,uVar12 + (int)uVar21,0,0);
          if (lVar9 < 0) {
            iVar11 = DAT_ffffffffbfc436f4 + 0x118;
            goto LAB_ffffffffbfc1e528;
          }
        }
        uVar18 = (*(code *)(long)DAT_ffffffffbfc43eb8)(uVar18);
      }
      else {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x140);
      }
      pcVar22 = (code *)(long)DAT_ffffffffbfc4400c;
      if (uVar18 != 0) {
        (*pcVar22)(DAT_ffffffffbfc436f4 + 0x178,uVar18);
        pcVar22 = (code *)(long)DAT_ffffffffbfc43ef4;
        *(undefined4 *)(lVar23 + 4) = 1;
        *(undefined4 *)(lVar23 + 0xc) = 0;
        lVar9 = (*pcVar22)(uVar16,param_3,param_4,uVar18 & 0xffffffff,0,0,
                           *(undefined4 *)(lVar23 + 0x30),0);
        if (lVar9 == 0) {
          lVar9 = (*(code *)(long)DAT_ffffffffbfc43ad0)(DAT_ffffffffbfc43f08,uVar16);
          puVar17 = (uint *)(long)DAT_ffffffffbfc43828;
          if (lVar9 == 0) {
            pcVar22 = (code *)(long)DAT_ffffffffbfc43f0c;
            iVar11 = DAT_ffffffffbfc436f4 + -0xcb8;
            *puVar17 = *puVar17 | (uint)uVar16;
            lVar9 = (*pcVar22)(iVar11);
            pcVar22 = (code *)(long)DAT_ffffffffbfc4400c;
            uVar12 = *(uint *)(lVar23 + 0x34);
            if (lVar9 != 0) {
              uVar12 = *(uint *)(lVar23 + 0x34) | 1;
            }
            *(uint *)(lVar23 + 0x34) = uVar12;
            (*pcVar22)(DAT_ffffffffbfc436f4 + -0x830,uVar16);
            uVar4 = getCopReg(2,0);
            *(undefined4 *)(uVar16 + 3) = uVar4;
            if (*(int *)(lVar23 + 0x34) != 0) {
              (*(code *)(long)DAT_ffffffffbfc438c8)();
              (*(code *)(long)DAT_ffffffffbfc43ff4)();
              (*(code *)(long)DAT_ffffffffbfc43a00)(*puVar17);
            }
            *(undefined4 *)(long)DAT_ffffffffbfc43c00 =
                 *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4c20);
            return 0;
          }
          iVar11 = DAT_ffffffffbfc436f4 + -0x860;
        }
        else {
          iVar11 = DAT_ffffffffbfc436f4 + -0x8a0;
        }
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar11,uVar16);
        return 0xffffffffffffffff;
      }
      iVar11 = DAT_ffffffffbfc436f4 + -0x48;
    }
    else {
      pcVar22 = (code *)(long)DAT_ffffffffbfc4400c;
      iVar11 = DAT_ffffffffbfc436f4 + -0xc20;
    }
    (*pcVar22)(iVar11);
    uVar20 = 0xffffffffffffffff;
  }
  return uVar20;
}

