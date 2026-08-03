/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc190f4
 * Function: FUN_ffffffffbfc190f4
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

undefined8 FUN_ffffffffbfc190f4(undefined8 param_1,int param_2,long param_3)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar5;
  char cVar8;
  char cVar9;
  ulong uVar4;
  undefined1 uVar10;
  uint uVar6;
  undefined4 uVar7;
  long lVar11;
  int *piVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  undefined8 uVar16;
  int iVar17;
  undefined8 unaff_s0;
  char *pcVar18;
  uint uVar19;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int iVar20;
  undefined8 unaff_s3;
  char *pcVar21;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar22;
  int *in_k0;
  int *piVar23;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  piVar23 = (int *)(long)((int)&stack0x00000000 + -0x80);
  *(undefined1 **)(piVar23 + 0x18) = &_gp;
  iVar17 = *in_k0;
  *(undefined8 *)(piVar23 + 0x1a) = unaff_s8;
  pcVar22 = (code *)(long)DAT_ffffffffbfc43c08;
  *(undefined8 *)(piVar23 + 0x14) = unaff_s6;
  *(undefined8 *)(piVar23 + 0x12) = unaff_s5;
  *(undefined8 *)(piVar23 + 0x10) = unaff_s4;
  *(undefined8 *)(piVar23 + 0x1c) = in_ra;
  *(undefined8 *)(piVar23 + 0x16) = unaff_s7;
  *(undefined8 *)(piVar23 + 0xe) = unaff_s3;
  *(undefined8 *)(piVar23 + 0xc) = unaff_s2;
  *(undefined8 *)(piVar23 + 10) = unaff_s1;
  *(undefined8 *)(piVar23 + 8) = unaff_s0;
  piVar23[4] = iVar17;
  pcVar3 = (char *)(*pcVar22)(0);
  if (pcVar3 == (char *)0x0) {
    return 1;
  }
  iVar17 = *(int *)(param_3 + 4);
  pcVar18 = (char *)(long)iVar17;
  iVar20 = (int)param_3;
  piVar23[5] = iVar20 + 4;
  if (*(int *)(long)DAT_ffffffffbfc43998 != 0) {
    iVar5 = DAT_ffffffffbfc436f0 + 0x6fc0;
    cVar9 = *pcVar18;
    pcVar14 = pcVar18;
    do {
      cVar2 = *(char *)(long)iVar5;
      pcVar14 = (char *)(long)((int)pcVar14 + 1);
      iVar5 = iVar5 + 1;
      cVar8 = cVar9;
      if (cVar2 != cVar9) break;
      bVar1 = cVar9 != '\0';
      cVar9 = *pcVar14;
      cVar8 = cVar2;
    } while (bVar1);
    if (cVar8 == cVar2) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x21c8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2180);
      return 1;
    }
  }
  pcVar21 = (char *)0x0;
  lVar11 = -1;
  pcVar14 = pcVar3;
  while( true ) {
    pcVar15 = pcVar14;
    if (*pcVar14 == '\0') break;
    do {
      iVar5 = (int)pcVar15;
      pcVar21 = (char *)(long)(iVar5 + 1);
      pcVar15 = pcVar21;
    } while (*pcVar21 != '\0');
    lVar11 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x71f0))(pcVar18,(int)pcVar14 - (int)pcVar3);
    if (-1 < lVar11) goto LAB_ffffffffbfc19228;
    pcVar14 = (char *)(long)(iVar5 + 2);
  }
  if (-1 < lVar11) {
LAB_ffffffffbfc19228:
    iVar5 = DAT_ffffffffbfc436f0 + 0x7118;
    cVar9 = *pcVar18;
    pcVar15 = pcVar18;
    do {
      cVar2 = *(char *)(long)iVar5;
      pcVar15 = (char *)(long)((int)pcVar15 + 1);
      iVar5 = iVar5 + 1;
      cVar8 = cVar9;
      if (cVar2 != cVar9) break;
      bVar1 = cVar9 != '\0';
      cVar9 = *pcVar15;
      cVar8 = cVar2;
    } while (bVar1);
    if (cVar8 == cVar2) {
      uVar16 = 0;
LAB_ffffffffbfc192e8:
      if (param_2 < 3) {
        pcVar22 = (code *)(long)DAT_ffffffffbfc4400c;
        iVar17 = DAT_ffffffffbfc436f4 + -0x2148;
        goto LAB_ffffffffbfc19304;
      }
      lVar11 = (*(code *)(long)DAT_ffffffffbfc43fa4)(uVar16,*(undefined4 *)(param_3 + 8));
      iVar5 = piVar23[5];
      if (lVar11 < 0) {
        return 1;
      }
    }
    else {
      iVar5 = DAT_ffffffffbfc436f0 + 0x7128;
      cVar9 = *pcVar18;
      pcVar15 = pcVar18;
      do {
        cVar2 = *(char *)(long)iVar5;
        pcVar15 = (char *)(long)((int)pcVar15 + 1);
        iVar5 = iVar5 + 1;
        cVar8 = cVar9;
        if (cVar2 != cVar9) break;
        bVar1 = cVar9 != '\0';
        cVar9 = *pcVar15;
        cVar8 = cVar2;
      } while (bVar1);
      if (cVar8 == cVar2) {
        uVar16 = 1;
        goto LAB_ffffffffbfc192e8;
      }
      iVar5 = DAT_ffffffffbfc436f0 + 0x7130;
      cVar9 = *pcVar18;
      pcVar15 = pcVar18;
      do {
        cVar2 = *(char *)(long)iVar5;
        pcVar15 = (char *)(long)((int)pcVar15 + 1);
        iVar5 = iVar5 + 1;
        cVar8 = cVar9;
        if (cVar2 != cVar9) break;
        bVar1 = cVar9 != '\0';
        cVar9 = *pcVar15;
        cVar8 = cVar2;
      } while (bVar1);
      iVar5 = piVar23[5];
      if (cVar8 == cVar2) {
        uVar16 = 2;
        goto LAB_ffffffffbfc192e8;
      }
    }
    pcVar15 = (char *)(long)*(int *)(long)iVar5;
    iVar5 = DAT_ffffffffbfc436f0 + 0x6da8;
    cVar9 = *pcVar15;
    do {
      cVar2 = *(char *)(long)iVar5;
      pcVar15 = (char *)(long)((int)pcVar15 + 1);
      iVar5 = iVar5 + 1;
      cVar8 = cVar9;
      if (cVar2 != cVar9) break;
      bVar1 = cVar9 != '\0';
      cVar9 = *pcVar15;
      cVar8 = cVar2;
    } while (bVar1);
    if (cVar8 == cVar2) {
      pcVar15 = (char *)(*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_3 + 8),0,10);
      iVar13 = 0;
      iVar5 = DAT_ffffffffbfc436f0 + 0x6480;
LAB_ffffffffbfc19384:
      piVar12 = (int *)(long)iVar5;
      iVar5 = iVar5 + 4;
      if (pcVar15 != (char *)(long)*piVar12) goto LAB_ffffffffbfc193a0;
      if (iVar13 != 7) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2108,pcVar15);
        (*(code *)(long)DAT_ffffffffbfc43b18)(50000);
        pcVar22 = (code *)(long)DAT_ffffffffbfc43da4;
        in_k0[2] = (int)pcVar15;
        (*pcVar22)();
        (*(code *)(long)DAT_ffffffffbfc43b18)(50000);
        do {
          lVar11 = (*(code *)(long)DAT_ffffffffbfc43e94)();
        } while (lVar11 != 0xd);
        goto LAB_ffffffffbfc19414;
      }
      goto LAB_ffffffffbfc193b0;
    }
LAB_ffffffffbfc19414:
    pcVar15 = (char *)(long)((int)pcVar21 + 2);
    if (pcVar21[1] == '\0') {
      if (pcVar3 < pcVar14) {
        pcVar14 = (char *)(long)((int)pcVar14 + -1);
      }
      else {
        *pcVar14 = '\0';
      }
    }
    else {
      *pcVar14 = pcVar21[1];
      do {
        cVar9 = *pcVar15;
        while( true ) {
          pcVar14 = (char *)(long)((int)pcVar14 + 1);
          pcVar15 = (char *)(long)((int)pcVar15 + 1);
          *pcVar14 = cVar9;
          if (cVar9 == '\0') break;
          cVar9 = *pcVar15;
        }
      } while (*pcVar15 != '\0');
    }
    pcVar14[1] = '\0';
  }
  iVar13 = 3;
  iVar5 = DAT_ffffffffbfc436f4 + -0x20d0;
  pcVar14 = pcVar18;
  while( true ) {
    cVar9 = *pcVar14;
    cVar2 = *(char *)(long)iVar5;
    cVar8 = cVar2;
    if (iVar13 == 0) break;
    iVar13 = iVar13 + -1;
    pcVar14 = (char *)(long)((int)pcVar14 + 1);
    cVar8 = cVar9;
    if ((cVar2 != cVar9) || (iVar5 = iVar5 + 1, cVar8 = cVar2, cVar9 == '\0')) break;
  }
  if (cVar8 == cVar2) {
    uVar16 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar17 + 3,piVar23,10);
    pcVar14 = (char *)(long)*piVar23;
    iVar17 = DAT_ffffffffbfc436f4 + -0x20c8;
    cVar9 = *pcVar14;
    do {
      cVar2 = *(char *)(long)iVar17;
      pcVar14 = (char *)(long)((int)pcVar14 + 1);
      iVar17 = iVar17 + 1;
      cVar8 = cVar9;
      if (cVar2 != cVar9) break;
      bVar1 = cVar9 != '\0';
      cVar9 = *pcVar14;
      cVar8 = cVar2;
    } while (bVar1);
    if (cVar8 == cVar2) {
      (*(code *)(long)DAT_ffffffffbfc43b78)(uVar16,*(undefined4 *)(param_3 + 8));
    }
  }
  iVar5 = 3;
  iVar17 = DAT_ffffffffbfc436f4 + -0x20c0;
  pcVar14 = pcVar18;
  while( true ) {
    cVar9 = *pcVar14;
    cVar2 = *(char *)(long)iVar17;
    cVar8 = cVar2;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar14 = (char *)(long)((int)pcVar14 + 1);
    cVar8 = cVar9;
    if ((cVar2 != cVar9) || (iVar17 = iVar17 + 1, cVar8 = cVar2, cVar9 == '\0')) break;
  }
  if ((cVar8 == cVar2) &&
     (uVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_3 + 8),0,10), uVar4 < 2))
  {
    pcVar22 = (code *)(long)DAT_ffffffffbfc437f0;
    in_k0[0xe] = (int)uVar4;
    (*pcVar22)(uVar4);
  }
  if ((param_2 < 3) ||
     (piVar12 = (int *)(long)(iVar20 + 8), pcVar14 = pcVar3, *(int *)(param_3 + 8) == 0)) {
    (*(code *)(long)DAT_ffffffffbfc43a58)();
    return 0;
  }
  do {
    while( true ) {
      iVar17 = (int)pcVar14;
      if (*pcVar14 == '\0') break;
      pcVar14 = (char *)(long)(iVar17 + 1);
    }
    pcVar21 = pcVar14 + 1;
    pcVar14 = (char *)(long)(iVar17 + 1);
  } while (*pcVar21 != '\0');
  pcVar14 = (char *)(long)(iVar17 + 1);
  if ((char *)(long)iVar17 <= pcVar3) {
    pcVar14 = (char *)(long)iVar17;
  }
  iVar17 = (*(code *)(long)DAT_ffffffffbfc437c8)(pcVar18);
  iVar17 = iVar17 + 2;
  iVar5 = 2;
  do {
    iVar20 = iVar20 + 4;
    iVar5 = iVar5 + 1;
    iVar13 = (*(code *)(long)DAT_ffffffffbfc437c8)(*(undefined4 *)((long)iVar20 + 4));
    iVar17 = iVar17 + iVar13 + 1;
  } while (iVar5 != param_2);
  if (iVar17 <= ((int)pcVar3 - (int)pcVar14) + 0x1fffc) {
    while( true ) {
      cVar9 = *pcVar18;
      pcVar18 = (char *)(long)((int)pcVar18 + 1);
      *pcVar14 = cVar9;
      if (cVar9 == '\0') break;
      pcVar14 = (char *)(long)((int)pcVar14 + 1);
    }
    iVar17 = 2;
    do {
      cVar9 = ' ';
      iVar20 = *(int *)(param_3 + 8);
      if (iVar17 == 2) {
        cVar9 = '=';
      }
      *pcVar14 = cVar9;
      do {
        cVar9 = *(char *)(long)iVar20;
        pcVar14 = (char *)(long)((int)pcVar14 + 1);
        iVar20 = iVar20 + 1;
        *pcVar14 = cVar9;
      } while (cVar9 != '\0');
      iVar17 = iVar17 + 1;
      param_3 = (long)((int)param_3 + 4);
    } while (iVar17 != param_2);
    pcVar22 = (code *)(long)DAT_ffffffffbfc43a58;
    pcVar14[1] = '\0';
    (*pcVar22)();
    pcVar18 = (char *)(long)*(int *)(long)piVar23[5];
    iVar17 = DAT_ffffffffbfc436f0 + 0x70c0;
    cVar9 = *pcVar18;
    pcVar3 = pcVar18;
    do {
      cVar2 = *(char *)(long)iVar17;
      pcVar3 = (char *)(long)((int)pcVar3 + 1);
      iVar17 = iVar17 + 1;
      cVar8 = cVar9;
      if (cVar2 != cVar9) break;
      bVar1 = cVar9 != '\0';
      cVar9 = *pcVar3;
      cVar8 = cVar2;
    } while (bVar1);
    if (cVar8 == cVar2) {
      iVar20 = 0;
      pcVar3 = (char *)(long)*piVar12;
      iVar17 = piVar23[4] + 8;
      do {
        if (pcVar3 == (char *)0x0) {
          *(undefined1 *)(long)iVar17 = 0;
        }
        else {
          uVar10 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar3,piVar23,0x10);
          iVar5 = *piVar23;
          *(undefined1 *)(long)iVar17 = uVar10;
          pcVar3 = (char *)(long)iVar5;
          if (*(char *)(long)iVar5 != '\0') {
            pcVar3 = (char *)(long)(iVar5 + 1);
          }
        }
        iVar20 = iVar20 + 1;
        iVar17 = iVar17 + 1;
      } while (iVar20 != 6);
      (*(code *)(long)DAT_ffffffffbfc43b78)(0,*piVar12);
      return 0;
    }
    iVar17 = DAT_ffffffffbfc436f0 + 0x70c8;
    cVar9 = *pcVar18;
    pcVar3 = pcVar18;
    do {
      cVar2 = *(char *)(long)iVar17;
      pcVar3 = (char *)(long)((int)pcVar3 + 1);
      iVar17 = iVar17 + 1;
      cVar8 = cVar9;
      if (cVar2 != cVar9) break;
      bVar1 = cVar9 != '\0';
      cVar9 = *pcVar3;
      cVar8 = cVar2;
    } while (bVar1);
    if (cVar8 == cVar2) {
      uVar19 = 0;
      pcVar3 = (char *)(long)*piVar12;
      iVar17 = 0;
      *(undefined4 *)((long)piVar23[4] + 4) = 0;
      do {
        uVar19 = uVar19 << 8;
        if (pcVar3 != (char *)0x0) {
          uVar6 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar3,piVar23,10);
          iVar20 = *piVar23;
          uVar19 = uVar19 | uVar6 & 0xff;
          pcVar3 = (char *)(long)iVar20;
          if (*(char *)(long)iVar20 != '\0') {
            pcVar3 = (char *)(long)(iVar20 + 1);
          }
        }
        iVar17 = iVar17 + 1;
      } while (iVar17 != 4);
      *(uint *)((long)piVar23[4] + 4) = uVar19;
    }
    else {
      iVar17 = DAT_ffffffffbfc436f0 + 0x6fc0;
      cVar9 = *pcVar18;
      pcVar3 = pcVar18;
      do {
        cVar2 = *(char *)(long)iVar17;
        pcVar3 = (char *)(long)((int)pcVar3 + 1);
        iVar17 = iVar17 + 1;
        cVar8 = cVar9;
        if (cVar2 != cVar9) break;
        bVar1 = cVar9 != '\0';
        cVar9 = *pcVar3;
        cVar8 = cVar2;
      } while (bVar1);
      if (cVar8 == cVar2) {
        uVar7 = (*(code *)(long)DAT_ffffffffbfc438b0)(*piVar12,0,0x10);
        *(undefined4 *)(long)DAT_ffffffffbfc43d48 = uVar7;
        return 0;
      }
      iVar17 = DAT_ffffffffbfc436f0 + 0x7740;
      cVar9 = *pcVar18;
      do {
        cVar2 = *(char *)(long)iVar17;
        pcVar18 = (char *)(long)((int)pcVar18 + 1);
        iVar17 = iVar17 + 1;
        cVar8 = cVar9;
        if (cVar2 != cVar9) break;
        bVar1 = cVar9 != '\0';
        cVar9 = *pcVar18;
        cVar8 = cVar2;
      } while (bVar1);
      if (cVar8 == cVar2) {
        (*(code *)(long)DAT_ffffffffbfc43fe4)(DAT_ffffffffbfc43d3c,*piVar12,0x80);
        return 0;
      }
    }
    return 0;
  }
  pcVar22 = (code *)(long)DAT_ffffffffbfc4400c;
  iVar17 = DAT_ffffffffbfc436f4 + -0x20b0;
LAB_ffffffffbfc19304:
  (*pcVar22)(iVar17,pcVar18);
  return 1;
LAB_ffffffffbfc193a0:
  iVar13 = iVar13 + 1;
  if (iVar13 == 7) goto LAB_ffffffffbfc193b0;
  goto LAB_ffffffffbfc19384;
LAB_ffffffffbfc193b0:
  pcVar22 = (code *)(long)DAT_ffffffffbfc4400c;
  iVar17 = DAT_ffffffffbfc436f4 + -0x2130;
  pcVar18 = pcVar15;
  goto LAB_ffffffffbfc19304;
}

