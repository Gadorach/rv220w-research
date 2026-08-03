/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1d950
 * Function: do_bootoctlinux
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
 * Recovered from U-Boot command table: command='bootoctlinux', maxargs=32, repeatable=0, usage=''.
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
   
   Recovered from U-Boot command table: command='bootoctlinux', maxargs=32, repeatable=0, usage=''.
    */

undefined4 do_bootoctlinux(undefined8 param_1,undefined8 param_2,int param_3,long param_4)

{
  char cVar1;
  char cVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined4 uVar5;
  long lVar6;
  int iVar9;
  char cVar11;
  ulong uVar7;
  long lVar8;
  uint uVar10;
  int iVar12;
  int iVar14;
  int iVar15;
  ulong uVar13;
  char *pcVar16;
  char *pcVar17;
  int iVar18;
  undefined8 unaff_s0;
  ulong uVar19;
  int *piVar20;
  undefined8 unaff_s1;
  uint *puVar21;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int iVar22;
  undefined8 unaff_s5;
  long lVar23;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar24;
  long lVar25;
  undefined8 unaff_s8;
  undefined8 uVar26;
  undefined8 in_ra;
  
  iVar15 = (int)&stack0x00000000;
  lVar25 = (long)(iVar15 + -0xa0);
  *(undefined1 **)(lVar25 + 0x80) = &_gp;
  *(undefined8 *)(lVar25 + 0x78) = unaff_s7;
  *(undefined8 *)(lVar25 + 0x70) = unaff_s6;
  *(undefined8 *)(lVar25 + 0x90) = in_ra;
  *(undefined8 *)(lVar25 + 0x88) = unaff_s8;
  *(undefined8 *)(lVar25 + 0x68) = unaff_s5;
  *(undefined8 *)(lVar25 + 0x60) = unaff_s4;
  *(undefined8 *)(lVar25 + 0x58) = unaff_s3;
  *(undefined8 *)(lVar25 + 0x50) = unaff_s2;
  *(undefined8 *)(lVar25 + 0x48) = unaff_s1;
  *(undefined8 *)(lVar25 + 0x40) = unaff_s0;
  if ((param_3 < 2) ||
     (lVar6 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 4),0,0x10), lVar6 == 0
     )) {
    lVar6 = (long)*(int *)(long)DAT_ffffffffbfc43d48;
  }
  uVar19 = 1;
  lVar23 = 0;
  *(undefined4 *)(lVar25 + 0x34) = 0;
  uVar26 = 0;
  *(undefined4 *)(lVar25 + 0x30) = 0;
  lVar8 = param_4;
  for (iVar22 = 2; iVar22 < param_3; iVar22 = iVar22 + 1) {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -400,iVar22,*(undefined4 *)(lVar8 + 8));
    iVar12 = 0xb;
    iVar14 = *(int *)(lVar8 + 8);
    pcVar17 = (char *)(long)iVar14;
    iVar9 = DAT_ffffffffbfc436f4 + -0xcd8;
    pcVar16 = pcVar17;
    while( true ) {
      cVar1 = *pcVar16;
      cVar2 = *(char *)(long)iVar9;
      cVar11 = cVar2;
      if (iVar12 == 0) break;
      iVar12 = iVar12 + -1;
      pcVar16 = (char *)(long)((int)pcVar16 + 1);
      cVar11 = cVar1;
      if ((cVar2 != cVar1) || (iVar9 = iVar9 + 1, cVar11 = cVar2, cVar1 == '\0')) break;
    }
    if (cVar11 == cVar2) {
      iVar14 = iVar14 + 9;
LAB_ffffffffbfc1dae8:
      uVar19 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar14,0,0);
    }
    else {
      iVar18 = 9;
      iVar12 = 9;
      iVar9 = DAT_ffffffffbfc436f4 + -0xcc8;
      pcVar16 = pcVar17;
      while( true ) {
        cVar1 = *pcVar16;
        cVar2 = *(char *)(long)iVar9;
        cVar11 = cVar2;
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        pcVar16 = (char *)(long)((int)pcVar16 + 1);
        cVar11 = cVar1;
        if ((cVar2 != cVar1) || (iVar9 = iVar9 + 1, cVar11 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar11 == cVar2) {
        pcVar24 = (code *)(long)DAT_ffffffffbfc43a54;
        iVar14 = iVar15 + -0x90;
        uVar3 = *(undefined2 *)((long)DAT_ffffffffbfc436f0 + 0x64e0);
        *(undefined1 *)(lVar25 + 0x12) = *(undefined1 *)((long)(DAT_ffffffffbfc436f0 + 0x64e0) + 2);
        *(undefined2 *)(lVar25 + 0x10) = uVar3;
        (*pcVar24)(iVar15 + -0x8d,0,0x11);
        (*(code *)(long)DAT_ffffffffbfc43a9c)(iVar14,*(int *)(lVar8 + 8) + 9,10);
        goto LAB_ffffffffbfc1dae8;
      }
      iVar12 = 9;
      iVar9 = DAT_ffffffffbfc436f4 + -0xcb8;
      pcVar16 = pcVar17;
      while( true ) {
        cVar1 = *pcVar16;
        cVar2 = *(char *)(long)iVar9;
        cVar11 = cVar2;
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        pcVar16 = (char *)(long)((int)pcVar16 + 1);
        cVar11 = cVar1;
        if ((cVar2 != cVar1) || (iVar9 = iVar9 + 1, cVar11 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar11 == cVar2) {
        *(undefined4 *)(lVar25 + 0x34) = 1;
      }
      else {
        iVar12 = 5;
        iVar9 = DAT_ffffffffbfc436f4 + -0xd00;
        pcVar16 = pcVar17;
        while( true ) {
          cVar1 = *pcVar16;
          cVar2 = *(char *)(long)iVar9;
          cVar11 = cVar2;
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          pcVar16 = (char *)(long)((int)pcVar16 + 1);
          cVar11 = cVar1;
          if ((cVar2 != cVar1) || (iVar9 = iVar9 + 1, cVar11 = cVar2, cVar1 == '\0')) break;
        }
        if (cVar11 == cVar2) {
          *(uint *)(lVar25 + 0x30) = *(uint *)(lVar25 + 0x30) | 2;
        }
        else {
          iVar9 = DAT_ffffffffbfc436f4 + -0xca8;
          pcVar16 = pcVar17;
          while( true ) {
            cVar1 = *pcVar16;
            cVar2 = *(char *)(long)iVar9;
            cVar11 = cVar2;
            if (iVar18 == 0) break;
            iVar18 = iVar18 + -1;
            pcVar16 = (char *)(long)((int)pcVar16 + 1);
            cVar11 = cVar1;
            if ((cVar2 != cVar1) || (iVar9 = iVar9 + 1, cVar11 = cVar2, cVar1 == '\0')) break;
          }
          if (cVar11 == cVar2) {
            lVar23 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar14 + 9,0,0);
          }
          else {
            iVar12 = 10;
            iVar9 = DAT_ffffffffbfc436f4 + -0xc98;
            pcVar16 = pcVar17;
            while( true ) {
              cVar1 = *pcVar16;
              cVar2 = *(char *)(long)iVar9;
              cVar11 = cVar2;
              if (iVar12 == 0) break;
              iVar12 = iVar12 + -1;
              pcVar16 = (char *)(long)((int)pcVar16 + 1);
              cVar11 = cVar1;
              if ((cVar2 != cVar1) || (iVar9 = iVar9 + 1, cVar11 = cVar2, cVar1 == '\0')) break;
            }
            if (cVar11 == cVar2) {
              uVar26 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar14 + 10,0,0);
            }
            else {
              iVar9 = 0xc;
              iVar14 = DAT_ffffffffbfc436f4 + -0xc88;
              while( true ) {
                cVar1 = *pcVar17;
                cVar2 = *(char *)(long)iVar14;
                cVar11 = cVar2;
                if (iVar9 == 0) break;
                iVar9 = iVar9 + -1;
                pcVar17 = (char *)(long)((int)pcVar17 + 1);
                cVar11 = cVar1;
                if ((cVar2 != cVar1) || (iVar14 = iVar14 + 1, cVar11 = cVar2, cVar1 == '\0')) break;
              }
              if (cVar11 == cVar2) {
                param_3 = (param_3 - iVar22) + -1;
                param_4 = (long)((int)param_4 + iVar22 * 4 + 4);
                break;
              }
            }
          }
        }
      }
    }
    lVar8 = (long)((int)lVar8 + 4);
  }
  if (lVar23 != 0) {
    uVar19 = (*(code *)(long)DAT_ffffffffbfc43ee0)((int)lVar23 + (int)uVar26);
    uVar7 = (*(code *)(long)DAT_ffffffffbfc43ee0)(uVar26);
    uVar19 = uVar19 & ~uVar7;
  }
  uVar19 = (*(code *)(long)DAT_ffffffffbfc43d28)(uVar19);
  if (uVar19 == 0) {
    iVar15 = DAT_ffffffffbfc436f4 + -0xc78;
    iVar22 = DAT_ffffffffbfc4400c;
LAB_ffffffffbfc1e020:
    (*(code *)(long)iVar22)(iVar15);
    return 0;
  }
  if ((long)uVar19 < 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0xc38);
    return 1;
  }
  (*(code *)(long)DAT_ffffffffbfc43990)(DAT_ffffffffbfc436f0 + 0x7040,0);
  lVar8 = (*(code *)(long)DAT_ffffffffbfc43bd8)(lVar6);
  if (lVar8 == 0) {
    return 1;
  }
  iVar15 = 0;
  if (*(char *)(lVar6 + 4) == '\x01') {
    iVar15 = 0;
    do {
      uVar4 = *(ushort *)(lVar6 + 0x2c);
      while( true ) {
        if ((int)(uint)uVar4 <= iVar15) {
          uVar10 = (*(code *)(long)DAT_ffffffffbfc43eb8)(lVar6);
          uVar7 = (ulong)uVar10;
          if (-1 < (int)uVar10) goto LAB_ffffffffbfc1ded8;
          uVar7 = (ulong)uVar10 | 0xffffffff00000000;
          goto LAB_ffffffffbfc1def4;
        }
        piVar20 = (int *)(long)((int)lVar6 + iVar15 * 0x20 + *(int *)(lVar6 + 0x1c));
        if (*piVar20 == 1) break;
        iVar15 = iVar15 + 1;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x180);
        uVar4 = *(ushort *)(lVar6 + 0x2c);
      }
      if (piVar20[5] != 0) {
        lVar8 = (*(code *)(long)DAT_ffffffffbfc43a08)(piVar20[5],piVar20[2] & 0x7fffffff,0,0,0);
        pcVar24 = (code *)(long)DAT_ffffffffbfc4400c;
        if (lVar8 < 0) goto LAB_ffffffffbfc1dec4;
        (*pcVar24)(DAT_ffffffffbfc436f4 + -0x128,piVar20[2] & 0x7fffffff,piVar20[5]);
      }
      iVar15 = iVar15 + 1;
    } while( true );
  }
  iVar22 = 0;
  for (; iVar15 < (int)(uint)*(ushort *)(lVar6 + 0x38); iVar15 = iVar15 + 1) {
    lVar8 = (long)((int)lVar6 + iVar22 + *(int *)(lVar6 + 0x24));
    if (*(long *)(lVar8 + 0x28) != 0) {
      uVar13 = *(ulong *)(lVar8 + 0x10);
      uVar7 = uVar13;
      if (((uVar13 & 0xffffffff00000000) == 0xffffffff00000000) ||
         (uVar7 = uVar13 & 0x87ffffffffffffff, (uVar13 & 0x87ffffff00000000) == 0xffffffff00000000))
      {
        uVar7 = uVar7 & 0x7fffffff;
      }
      else {
        uVar7 = uVar13 & 0x7ffffffffffffff;
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + -0xe8,uVar13,uVar7,(int)*(long *)(lVar8 + 0x28));
      lVar23 = (*(code *)(long)DAT_ffffffffbfc43a08)(*(undefined8 *)(lVar8 + 0x28),uVar7,0,0,0);
      pcVar24 = (code *)(long)DAT_ffffffffbfc4400c;
      if (lVar23 < 0) goto LAB_ffffffffbfc1dec4;
      (*pcVar24)(DAT_ffffffffbfc436f4 + -0x88,*(undefined8 *)(lVar8 + 0x10),
                 *(undefined4 *)(lVar8 + 0x2c));
    }
    iVar22 = iVar22 + 0x38;
  }
  uVar7 = (*(code *)(long)DAT_ffffffffbfc43a10)(lVar6);
LAB_ffffffffbfc1ded8:
  if (uVar7 != 0) {
LAB_ffffffffbfc1def4:
    puVar21 = (uint *)(long)DAT_ffffffffbfc43828;
    pcVar24 = (code *)(long)DAT_ffffffffbfc4400c;
    if ((uVar19 & (long)(int)*puVar21) == 0) {
      (*pcVar24)(DAT_ffffffffbfc436f4 + -0x30,uVar7);
      pcVar24 = (code *)(long)DAT_ffffffffbfc43ef4;
      *(undefined4 *)(lVar25 + 4) = 1;
      *(undefined4 *)(lVar25 + 0xc) = 0;
      lVar6 = (*pcVar24)(uVar19,param_3,param_4,uVar7,0,0,*(undefined4 *)(lVar25 + 0x30),0);
      if (lVar6 == 0) {
        lVar6 = (*(code *)(long)DAT_ffffffffbfc43ad0)(DAT_ffffffffbfc4402c,uVar19);
        iVar15 = DAT_ffffffffbfc436f4;
        if (lVar6 == 0) {
          pcVar24 = (code *)(long)DAT_ffffffffbfc43f0c;
          *puVar21 = *puVar21 | (uint)uVar19;
          lVar6 = (*pcVar24)(iVar15 + -0xcb8);
          pcVar24 = (code *)(long)DAT_ffffffffbfc4400c;
          uVar10 = *(uint *)(lVar25 + 0x34);
          if (lVar6 != 0) {
            uVar10 = *(uint *)(lVar25 + 0x34) | 1;
          }
          *(uint *)(lVar25 + 0x34) = uVar10;
          (*pcVar24)(DAT_ffffffffbfc436f4 + -0x830,uVar19);
          uVar5 = getCopReg(2,0);
          *(undefined4 *)(uVar19 + 4) = uVar5;
          if (*(int *)(lVar25 + 0x34) == 0) {
            return 0;
          }
          (*(code *)(long)DAT_ffffffffbfc438c8)();
          (*(code *)(long)DAT_ffffffffbfc43ff4)();
          iVar15 = *(int *)(long)DAT_ffffffffbfc43828;
          iVar22 = DAT_ffffffffbfc43a00;
          goto LAB_ffffffffbfc1e020;
        }
        iVar15 = DAT_ffffffffbfc436f4 + -0x860;
      }
      else {
        iVar15 = DAT_ffffffffbfc436f4 + -0x8a0;
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar15,uVar19);
      return 0xffffffff;
    }
    iVar15 = DAT_ffffffffbfc436f4 + -0xc20;
    goto LAB_ffffffffbfc1df0c;
  }
LAB_ffffffffbfc1dee4:
  pcVar24 = (code *)(long)DAT_ffffffffbfc4400c;
  iVar15 = DAT_ffffffffbfc436f4 + -0x48;
LAB_ffffffffbfc1df0c:
  (*pcVar24)(iVar15);
  return 0xffffffff;
LAB_ffffffffbfc1dec4:
  (*pcVar24)(DAT_ffffffffbfc436f4 + -0x150);
  goto LAB_ffffffffbfc1dee4;
}

