/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc01298
 * Function: board_init_r
 * Subsystem: board-init
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: board-init
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Late relocated board initialization. Relocation/GOT repair, flash discovery, RV220W board identity, PCI/network setup and U-Boot service initialization are visible. Identity is supported by the retained CVMX_BOARD_TYPE_CUST_RV200W string.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: board-init
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Late relocated board initialization. Relocation/GOT repair, flash discovery, RV220W board identity, PCI/network setup and U-Boot service initialization are visible. Identity is supported by the retained CVMX_BOARD_TYPE_CUST_RV200W string.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Late relocated board initialization. Relocation/GOT repair, flash discovery, RV220W board identity, PCI/network setup and U-Boot service initialization are visible. Identity is supported by the retained CVMX_BOARD_TYPE_CUST_RV200W string.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: board-init
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Late relocated board initialization. Relocation/GOT repair, flash discovery,
   RV220W board identity, PCI/network setup and U-Boot service initialization are visible. Identity
   is supported by the retained CVMX_BOARD_TYPE_CUST_RV200W string.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: board-init
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Late relocated board initialization. Relocation/GOT repair, flash discovery,
   RV220W board identity, PCI/network setup and U-Boot service initialization are visible. Identity
   is supported by the retained CVMX_BOARD_TYPE_CUST_RV200W string.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Late relocated board initialization. Relocation/GOT repair, flash discovery,
   RV220W board identity, PCI/network setup and U-Boot service initialization are visible. Identity
   is supported by the retained CVMX_BOARD_TYPE_CUST_RV200W string.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void board_init_r(int param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  undefined1 auVar5 [16];
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  long in_zero;
  undefined4 uVar14;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  char *pcVar12;
  char *pcVar13;
  undefined1 uVar16;
  undefined4 uVar15;
  int iVar17;
  char cVar18;
  char *pcVar19;
  int *piVar20;
  int iVar21;
  int *piVar22;
  undefined8 in_t7;
  undefined8 unaff_s0;
  undefined8 uVar23;
  int iVar24;
  undefined8 unaff_s1;
  int iVar25;
  undefined8 unaff_s2;
  ulong uVar26;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  long lVar27;
  code *pcVar28;
  code *pcVar29;
  int *piVar30;
  int *piVar31;
  undefined8 in_ra;
  
  iVar24 = (int)&stack0x00000000;
  piVar31 = (int *)(long)(iVar24 + -0x80);
  *(undefined1 **)(piVar31 + 0x1a) = &_gp;
  *(undefined8 *)(piVar31 + 0x1c) = in_ra;
  *(undefined8 *)(piVar31 + 0x18) = unaff_s4;
  *(undefined8 *)(piVar31 + 0x16) = unaff_s3;
  *(undefined8 *)(piVar31 + 0x14) = unaff_s2;
  *(undefined8 *)(piVar31 + 0x12) = unaff_s1;
  *(undefined8 *)(piVar31 + 0x10) = unaff_s0;
  iVar17 = DAT_ffffffffbfc44078;
  piVar30 = (int *)(long)param_1;
  piVar30[1] = piVar30[1] | 1;
  piVar30[6] = param_2 + 0x40400000;
  iVar25 = piVar30[6];
  *(int *)(long)DAT_ffffffffbfc43ec8 = iVar17 - param_2;
  if (iVar25 != 0) {
    piVar22 = (int *)(long)DAT_ffffffffbfc43b1c;
    iVar25 = DAT_ffffffffbfc4404c;
    while( true ) {
      piVar20 = (int *)(long)iVar25;
      if (piVar20 == piVar22) break;
      iVar17 = piVar30[6];
      piVar20[3] = piVar20[3] + piVar30[6];
      *piVar20 = *piVar20 + iVar17;
      if (piVar20[4] != 0) {
        piVar20[4] = piVar20[4] + piVar30[6];
      }
      if (piVar20[5] != 0) {
        piVar20[5] = piVar20[5] + piVar30[6];
      }
      iVar25 = iVar25 + 0x20;
    }
    *(int *)(long)DAT_ffffffffbfc43e54 = *(int *)(long)DAT_ffffffffbfc43e54 + piVar30[6];
  }
  piVar22 = piVar30;
  uVar14 = (*(code *)(long)DAT_ffffffffbfc43d44)();
  (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f0 + 0x6dc8);
  (*(code *)(long)DAT_ffffffffbfc43a98)(uVar14,DAT_ffffffffbfc436f4 + 0x1150);
  iVar25 = *piVar30;
  lVar27 = (long)iVar25;
  pcVar28 = (code *)(long)DAT_ffffffffbfc43a54;
  *(undefined4 *)(lVar27 + 0x20) = 0xbdc00000;
  *(undefined4 *)(lVar27 + 0x24) = uVar14;
  *(undefined4 *)(lVar27 + 0x28) = 0;
  iVar21 = piVar22[6] + -0x40400000;
  iVar17 = piVar22[6] + -0x40430000;
  *(int *)((long)DAT_ffffffffbfc436f4 + 0x47ec) = iVar21;
  *(int *)((long)DAT_ffffffffbfc436f4 + 0x47e8) = iVar17;
  *(int *)((long)DAT_ffffffffbfc436f4 + 0x47f0) = iVar17;
  (*pcVar28)(iVar17,0,iVar21 - iVar17);
  (*(code *)(long)DAT_ffffffffbfc43a64)();
  (*(code *)(long)DAT_ffffffffbfc43acc)();
  lVar9 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xa00))(0x30d0001);
  if (lVar9 != 0) {
    lVar9 = (*(code *)(long)DAT_ffffffffbfc439fc)();
    if (lVar9 < 0x28) {
      lVar10 = (*(code *)(long)DAT_ffffffffbfc438e8)();
      pcVar28 = (code *)(long)DAT_ffffffffbfc4400c;
      if (lVar10 != 0) {
        (*pcVar28)(DAT_ffffffffbfc436f0 + 0x6dd0,lVar9);
        goto LAB_ffffffffbfc01494;
      }
      iVar17 = DAT_ffffffffbfc436f0 + 0x6e08;
    }
    else {
      pcVar28 = (code *)(long)DAT_ffffffffbfc4400c;
      iVar17 = DAT_ffffffffbfc436f0 + 0x6e68;
    }
    (*pcVar28)(iVar17);
  }
LAB_ffffffffbfc01494:
  iVar17 = DAT_ffffffffbfc436ec + 0xb78;
  (*(code *)(long)iVar17)(0x8001070000000500,0);
  (*(code *)(long)iVar17)(0x8001070000000508,0);
  iVar17 = DAT_ffffffffbfc436ec + 0xa00;
  lVar9 = (*(code *)(long)iVar17)(0x30d0001);
  if ((lVar9 != 0) || (lVar9 = (*(code *)(long)iVar17)(0x30d0300), lVar9 != 0)) {
    lVar10 = 2;
    do {
      special2(lVar10,lVar9,3,0x32);
      lVar10 = (long)((int)lVar10 + 1);
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0xb78))(lVar9 + -0x7ffef8fffffffb00,0);
      lVar9 = 0x10;
    } while (lVar10 != 0x10);
  }
  (*(code *)(long)DAT_ffffffffbfc43880)();
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x6ec0);
  lVar9 = 0xff00000;
  if (*(ulong *)(piVar30 + 4) < 0x10000001) {
    lVar9 = *(long *)(piVar30 + 4) + -0x100000;
  }
  (*(code *)(long)DAT_ffffffffbfc438d4)(0x8000000000100000,lVar9);
  (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + 0x1650);
  lVar9 = 0x10000000;
  if (0x10000000 < *(ulong *)(piVar30 + 4)) {
    if (*(long *)(piVar30 + 4) - 0x10000000U < 0x10000000) {
      lVar9 = *(long *)(piVar30 + 4) + -0x10000000;
    }
    (*(code *)(long)DAT_ffffffffbfc438d4)(0x8000000410000000,lVar9);
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + 0x1650);
  }
  if (0x20000000 < *(ulong *)(piVar30 + 4)) {
    (*(code *)(long)DAT_ffffffffbfc438d4)(0x8000000020000000,*(long *)(piVar30 + 4) + -0x20000000);
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + 0x1650);
  }
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x6ed8);
  pcVar28 = (code *)(long)(DAT_ffffffffbfc436ec + 0xb78);
  (*pcVar28)(&DAT_8001180080000010,_DAT_8001180080000010);
  (*pcVar28)(&DAT_8001180080000008,_DAT_8001180080000008);
  lVar10 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xa00))(0x30d0400);
  lVar9 = _DAT_8001180080000000;
  if (lVar10 == 0) {
    lVar9 = -0xfffdcffef;
  }
  else {
    setCopReg(2,in_t7,*(undefined4 *)(_DAT_8001180080000000 + 9));
    (*pcVar28)(&DAT_8001180088000000,_DAT_8001180088000000);
    setCopReg(2,lVar9,*(undefined4 *)(lVar9 + 0x10));
    lVar9 = -0xfffdcffe3;
  }
  (*pcVar28)((undefined8 *)(lVar9 * 0x8000000),*(undefined8 *)(lVar9 * 0x8000000));
  uVar23 = *(undefined8 *)(piVar30 + 4);
  uVar11 = (*(code *)(long)DAT_ffffffffbfc43e1c)(0x38);
  lVar9 = (*(code *)(long)DAT_ffffffffbfc439b8)(uVar23,0x100000,uVar11);
  if (lVar9 == 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x6ee0);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  (*(code *)(long)DAT_ffffffffbfc43e3c)();
  pcVar12 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x6f10);
  if (pcVar12 == (char *)0x0) {
LAB_ffffffffbfc017b0:
    if ((*(ulong *)(piVar30 + 4) / 3 & 0xfffffffffff00000) < 0x6000001) {
      auVar5._0_8_ = 0;
      auVar5._8_8_ = *(ulong *)(piVar30 + 4);
      uVar26 = SUB168(auVar5 * ZEXT816(0xaaaaaaaaaaaaaaab),8);
      special2(uVar26,uVar26,1,0x3a);
      uVar26 = uVar26 & 0xfffffffffff00000;
      goto LAB_ffffffffbfc0182c;
    }
    uVar26 = 0x6000000;
LAB_ffffffffbfc01834:
    pcVar12 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x6f38);
    iVar17 = (int)uVar26;
    if (pcVar12 == (char *)0x0) {
LAB_ffffffffbfc01884:
      if ((*(ulong *)(piVar30 + 4) < 0x20000001) ||
         (*(long *)(piVar30 + 4) - 0x20000000U < (uVar26 & 0xffffffff))) {
        if (*(long *)(piVar30 + 4) - 0x100000U < 0xff00000) {
          iVar21 = (int)*(undefined8 *)(piVar30 + 4) + -0x100000;
        }
        else {
          iVar21 = 0xff00000;
        }
      }
      else {
        iVar21 = iVar17 + 0x20000000;
      }
      pcVar28 = (code *)(long)(iVar21 - iVar17);
    }
    else {
      pcVar13 = (char *)(long)(DAT_ffffffffbfc436f0 + 0x6f30);
      cVar2 = *pcVar13;
      pcVar19 = pcVar12;
      do {
        cVar3 = *pcVar19;
        pcVar13 = (char *)(long)((int)pcVar13 + 1);
        pcVar19 = (char *)(long)((int)pcVar19 + 1);
        cVar18 = cVar2;
        if (cVar3 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar13;
        cVar18 = cVar3;
      } while (bVar1);
      if (cVar18 == cVar3) goto LAB_ffffffffbfc01884;
      pcVar28 = (code *)(*(code *)(long)DAT_ffffffffbfc43f3c)(pcVar12,0,0x10);
    }
    lVar9 = (*(code *)(long)DAT_ffffffffbfc43cec)
                      (uVar26 & 0xffffffff,(ulong)pcVar28 & 0xffffffff,(int)pcVar28 + iVar17,0,
                       DAT_ffffffffbfc436f0 + 0x6f58,0);
    if (lVar9 < 0) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x6f68,pcVar28,uVar26);
    }
    else {
      (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24 + -0x72,DAT_ffffffffbfc436f0 + 0x6fb8,pcVar28);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x6fc0,iVar24 + -0x72);
      *(int *)(long)DAT_ffffffffbfc43998 = (int)pcVar28;
      *(int *)(long)DAT_ffffffffbfc4379c = iVar17;
    }
  }
  else {
    pcVar13 = (char *)(long)(DAT_ffffffffbfc436f0 + 0x6f30);
    cVar2 = *pcVar13;
    pcVar19 = pcVar12;
    do {
      cVar3 = *pcVar19;
      pcVar13 = (char *)(long)((int)pcVar13 + 1);
      pcVar19 = (char *)(long)((int)pcVar19 + 1);
      cVar18 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar13;
      cVar18 = cVar3;
    } while (bVar1);
    if (cVar18 == cVar3) goto LAB_ffffffffbfc017b0;
    uVar26 = (*(code *)(long)DAT_ffffffffbfc43f3c)(pcVar12,0,0x10);
LAB_ffffffffbfc0182c:
    if (uVar26 != 0) goto LAB_ffffffffbfc01834;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x6fd0);
  }
  pcVar12 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x7000);
  if (pcVar12 == (char *)0x0) {
LAB_ffffffffbfc019f8:
    if (*(ulong *)(piVar30 + 4) < 0x10000000) {
      special2(*(undefined8 *)(piVar30 + 4),pcVar28,1,0x3a);
      goto LAB_ffffffffbfc01a34;
    }
    pcVar28 = (code *)0x8000000;
LAB_ffffffffbfc01a3c:
    pcVar12 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x7020);
    if (pcVar12 == (char *)0x0) {
LAB_ffffffffbfc01aa4:
      uVar26 = 0x100000;
    }
    else {
      pcVar13 = (char *)(long)(DAT_ffffffffbfc436f0 + 0x6f30);
      cVar2 = *pcVar13;
      pcVar19 = pcVar12;
      do {
        cVar3 = *pcVar19;
        pcVar13 = (char *)(long)((int)pcVar13 + 1);
        pcVar19 = (char *)(long)((int)pcVar19 + 1);
        cVar18 = cVar2;
        if (cVar3 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar13;
        cVar18 = cVar3;
      } while (bVar1);
      if (cVar18 == cVar3) goto LAB_ffffffffbfc01aa4;
      uVar26 = (*(code *)(long)DAT_ffffffffbfc43f3c)(pcVar12,0,0x10);
    }
    lVar9 = (*(code *)(long)DAT_ffffffffbfc43cec)
                      ((ulong)pcVar28 & 0xffffffff,uVar26 & 0xffffffff,(int)uVar26 + (int)pcVar28,0,
                       DAT_ffffffffbfc436f0 + 0x7040,0);
    pcVar29 = (code *)(long)DAT_ffffffffbfc43ac8;
    if (lVar9 < 0) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7058,uVar26,pcVar28);
      pcVar29 = (code *)(long)DAT_ffffffffbfc43ac8;
    }
  }
  else {
    pcVar13 = (char *)(long)(DAT_ffffffffbfc436f0 + 0x6f30);
    cVar2 = *pcVar13;
    pcVar19 = pcVar12;
    do {
      cVar3 = *pcVar19;
      pcVar13 = (char *)(long)((int)pcVar13 + 1);
      pcVar19 = (char *)(long)((int)pcVar19 + 1);
      cVar18 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar13;
      cVar18 = cVar3;
    } while (bVar1);
    if (cVar18 == cVar3) goto LAB_ffffffffbfc019f8;
    pcVar28 = (code *)(*(code *)(long)DAT_ffffffffbfc43f3c)(pcVar12,0,0x10);
LAB_ffffffffbfc01a34:
    pcVar29 = (code *)(long)DAT_ffffffffbfc43ac8;
    if (pcVar28 != (code *)0x0) goto LAB_ffffffffbfc01a3c;
  }
  iVar25 = iVar25 + 8;
  iVar17 = 0;
  _DAT_ffffffff80024100 = (*pcVar29)();
  _DAT_ffffffff80024100 = _DAT_ffffffff80024100 & 0x7fffffff;
  uVar11 = (*(code *)(long)DAT_ffffffffbfc43df4)();
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24 + -0x7c,DAT_ffffffffbfc436f0 + 0x70a8,uVar11);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x70b0,iVar24 + -0x7c);
  (*(code *)(long)DAT_ffffffffbfc438ac)();
  pcVar12 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x70c0);
  do {
    if (pcVar12 == (char *)0x0) {
      *(undefined1 *)(long)iVar25 = 0;
    }
    else {
      uVar16 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar12,piVar31,0x10);
      *(undefined1 *)(long)iVar25 = uVar16;
      iVar21 = *piVar31;
      pcVar12 = (char *)(long)iVar21;
      if (*(char *)(long)iVar21 != '\0') {
        pcVar12 = (char *)(long)(iVar21 + 1);
      }
    }
    iVar21 = DAT_ffffffffbfc436f0;
    uVar14 = SUB84(piVar22,0);
    iVar17 = iVar17 + 1;
    iVar25 = iVar25 + 1;
  } while (iVar17 != 6);
  uVar15 = (*(code *)(long)DAT_ffffffffbfc44060)(DAT_ffffffffbfc436f0 + 0x70c8);
  pcVar28 = (code *)(long)DAT_ffffffffbfc43b64;
  *(undefined4 *)(lVar27 + 4) = uVar15;
  (*pcVar28)();
  iVar25 = DAT_ffffffffbfc436f0;
  (*(code *)(long)DAT_ffffffffbfc438c4)();
  iVar17 = DAT_ffffffffbfc436f0;
  lVar9 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x70d0);
  iVar6 = DAT_ffffffffbfc436f0;
  if (lVar9 == 0) {
    (*(code *)(long)DAT_ffffffffbfc43b14)(iVar21 + 0x7118,DAT_ffffffffbfc436f0 + 29000);
    (*(code *)(long)DAT_ffffffffbfc43b14)(iVar25 + 0x7128,iVar6 + 29000);
    (*(code *)(long)DAT_ffffffffbfc43b14)(iVar17 + 0x7130,iVar6 + 29000);
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x70e8);
    (*(code *)(long)DAT_ffffffffbfc43b14)(iVar21 + 0x7118,iVar6 + 0x7120);
    (*(code *)(long)DAT_ffffffffbfc43b14)(iVar25 + 0x7128,iVar6 + 0x7120);
    (*(code *)(long)DAT_ffffffffbfc43b14)(iVar17 + 0x7130,iVar6 + 0x7120);
    (*(code *)(long)DAT_ffffffffbfc43f30)(DAT_ffffffffbfc436f0 + 0x7138);
  }
  (*(code *)(long)DAT_ffffffffbfc43908)();
  (*(code *)(long)DAT_ffffffffbfc44068)();
  lVar9 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x70d0);
  uVar8 = PRId;
  if (lVar9 == 0) goto LAB_ffffffffbfc021b0;
  uVar4 = *(ushort *)(piVar30 + 0x11);
  if (uVar4 == 0x10) {
    iVar25 = DAT_ffffffffbfc436f0 + 0x7338;
  }
  else if (uVar4 < 0x11) {
    if (uVar4 == 7) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x7248;
    }
    else if (uVar4 < 8) {
      if (uVar4 == 3) {
        iVar25 = DAT_ffffffffbfc436f0 + 0x71e8;
      }
      else if (uVar4 < 4) {
        if (uVar4 == 1) {
          iVar25 = DAT_ffffffffbfc436f0 + 0x71b8;
        }
        else if (uVar4 < 2) {
          iVar25 = DAT_ffffffffbfc436f0 + 0x71a0;
        }
        else {
          iVar25 = DAT_ffffffffbfc436f0 + 0x71d0;
        }
      }
      else if (uVar4 == 5) {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7218;
      }
      else if (uVar4 < 6) {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7200;
      }
      else {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7230;
      }
    }
    else if (uVar4 == 0xb) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x72a8;
    }
    else if (uVar4 < 0xc) {
      if (uVar4 == 9) {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7278;
      }
      else if (uVar4 < 10) {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7260;
      }
      else {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7290;
      }
    }
    else if (uVar4 == 0xd) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x72e8;
    }
    else if (uVar4 < 0xd) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x72c8;
    }
    else if (uVar4 == 0xe) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x7300;
    }
    else {
      if (uVar4 != 0xf) goto LAB_ffffffffbfc01e54;
      iVar25 = DAT_ffffffffbfc436f0 + 0x7320;
    }
  }
  else if (uVar4 == 0x2712) {
    iVar25 = DAT_ffffffffbfc436f0 + 0x7418;
  }
  else if (uVar4 < 0x2713) {
    if (uVar4 == 0x14) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x7398;
    }
    else if (uVar4 < 0x15) {
      if (uVar4 == 0x12) {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7368;
      }
      else if (uVar4 < 0x13) {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7350;
      }
      else {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7380;
      }
    }
    else if (uVar4 == 10000) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x73d0;
    }
    else if (uVar4 < 0x2711) {
      if (uVar4 != 0x15) goto LAB_ffffffffbfc01e54;
      iVar25 = DAT_ffffffffbfc436f0 + 0x73b8;
    }
    else {
      iVar25 = DAT_ffffffffbfc436f0 + 0x73f8;
    }
  }
  else if (uVar4 == 0x2716) {
    iVar25 = DAT_ffffffffbfc436f0 + 0x7498;
  }
  else if (uVar4 < 0x2717) {
    if (uVar4 == 0x2714) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x7458;
    }
    else if (uVar4 < 0x2715) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x7438;
    }
    else {
      iVar25 = DAT_ffffffffbfc436f0 + 0x7478;
    }
  }
  else if (uVar4 == 20000) {
    iVar25 = DAT_ffffffffbfc436f0 + 0x74d8;
  }
  else if (uVar4 < 0x4e21) {
    if (uVar4 == 0x2717) {
      iVar25 = DAT_ffffffffbfc436f0 + 0x74b8;
    }
    else {
LAB_ffffffffbfc01e54:
      iVar25 = DAT_ffffffffbfc436f0 + 0x7178;
    }
  }
  else if (uVar4 == 0x4e21) {
    iVar25 = DAT_ffffffffbfc436f0 + 0x7500;
  }
  else {
    if (uVar4 != 30000) goto LAB_ffffffffbfc01e54;
    iVar25 = DAT_ffffffffbfc436f0 + 0x7160;
  }
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f0 + 0x7518,iVar25,*(undefined1 *)((long)piVar30 + 0x46),
             *(undefined1 *)((long)piVar30 + 0x47),param_1 + 0x4c);
  pcVar28 = (code *)(long)(DAT_ffffffffbfc436ec + 0xa00);
  lVar9 = (*pcVar28)(0x10d0200);
  if (lVar9 == 0) {
    lVar9 = (*pcVar28)(0x10d0210);
    if (lVar9 == 0) {
      lVar9 = (*pcVar28)(0x10d0110);
      if (lVar9 == 0) {
        lVar9 = (*pcVar28)(0x30d0100);
        if (lVar9 == 0) {
          lVar9 = (*pcVar28)(0x30d0300);
          if (lVar9 == 0) {
            lVar9 = (*pcVar28)(0x30d0400);
            if (lVar9 == 0) {
              lVar9 = (*pcVar28)(0x30d0700);
              if (lVar9 == 0) {
                lVar9 = (*pcVar28)(0x30d0600);
                if (lVar9 == 0) {
                  lVar9 = (*pcVar28)(0x30d0001);
                  if (lVar9 == 0) {
                    iVar25 = DAT_ffffffffbfc436f0 + 0x7590;
                  }
                  else {
                    lVar9 = (*pcVar28)(0x30d0001);
                    if ((lVar9 == 0) ||
                       (lVar9 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xba8))(0x108), lVar9 == 0))
                    {
                      iVar25 = DAT_ffffffffbfc436f0 + 0x7758;
                    }
                    else {
                      iVar25 = DAT_ffffffffbfc436f0 + 0x7598;
                    }
                  }
                }
                else {
                  iVar25 = DAT_ffffffffbfc436f0 + 0x7588;
                }
              }
              else {
                iVar25 = DAT_ffffffffbfc436f0 + 0x7580;
              }
            }
            else {
              iVar25 = DAT_ffffffffbfc436f0 + 0x7578;
            }
          }
          else {
            iVar25 = DAT_ffffffffbfc436f0 + 0x7570;
          }
        }
        else {
          iVar25 = DAT_ffffffffbfc436f0 + 0x7568;
        }
      }
      else {
        iVar25 = DAT_ffffffffbfc436f0 + 0x7560;
      }
    }
    else {
      iVar25 = DAT_ffffffffbfc436f0 + 0x7558;
    }
  }
  else {
    iVar25 = DAT_ffffffffbfc436f0 + 0x7550;
  }
  lVar9 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xde4))();
  if (((lVar9 == 0) && (lVar9 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xdc8))(), lVar9 == 0)) &&
     (lVar9 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xe9c))(), lVar9 == 0)) {
    iVar17 = DAT_ffffffffbfc436f0 + 0x75a0;
  }
  else {
    lVar9 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xde4))();
    if ((lVar9 == 0) && (lVar9 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xdc8))(), lVar9 == 0)) {
      iVar17 = DAT_ffffffffbfc436f0 + 0x75a8;
    }
    else {
      lVar9 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xe9c))();
      if (lVar9 == 0) {
        iVar17 = DAT_ffffffffbfc436f0 + 0x75b0;
      }
      else {
        iVar17 = DAT_ffffffffbfc436f0 + 0x75b8;
      }
    }
  }
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f0 + 0x75c0,iVar25,iVar17,uVar8 & 0xef,piVar30[9],piVar30[10],
             piVar30[10] << 1);
LAB_ffffffffbfc021b0:
  iVar25 = DAT_ffffffffbfc436f0;
  lVar9 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x6fc0);
  if (lVar9 == 0) {
    iVar17 = iVar24 + -0x72;
    (*(code *)(long)DAT_ffffffffbfc439a4)(iVar17,DAT_ffffffffbfc436f0 + 0x6fb8,0x100000);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7618,iVar17);
    (*(code *)(long)DAT_ffffffffbfc43b14)(iVar25 + 0x6fc0,iVar17);
  }
  else {
    uVar15 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar9,0,0x10);
    *(undefined4 *)(long)DAT_ffffffffbfc43d48 = uVar15;
  }
  iVar25 = DAT_ffffffffbfc436f0;
  iVar24 = iVar24 + -0x5e;
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24,DAT_ffffffffbfc436f0 + 0x6fb8,&DAT_ffffffffbfbe0000);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x76a0,iVar24);
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24,iVar25 + 0x6fb8,0x20000);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x76b0,iVar24);
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24,iVar25 + 0x6fb8,&DAT_ffffffffbdc00000);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x76c0,iVar24);
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24,iVar25 + 0x6fb8,0x2000000);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x76d0,iVar24);
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24,iVar25 + 0x6fb8,0xffffffffbdc30000);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x76e0,iVar24);
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24,iVar25 + 0x6fb8,0x50000);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x76f8,iVar24);
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24,iVar25 + 0x6fb8,0xffffffffbdc80000);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x7710,iVar24);
  (*(code *)(long)DAT_ffffffffbfc439a4)(iVar24,iVar25 + 0x6fb8,0x1f60000);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x7728,iVar24);
  lVar9 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x7740);
  if (lVar9 != 0) {
    (*(code *)(long)DAT_ffffffffbfc43fe4)(DAT_ffffffffbfc43d3c,lVar9,0x80);
  }
  (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f0 + 0x7750);
  (*(code *)(long)DAT_ffffffffbfc43b00)(*piVar30);
  uVar15 = DAT_ffffffffbfc439d8;
  *(undefined4 *)(in_zero + 0xa0c) = DAT_ffffffffbfc43c94;
  uVar7 = DAT_ffffffffbfc43c9c;
  *(undefined4 *)(in_zero + 0xa08) = uVar15;
  *(undefined4 *)(in_zero + 0xa10) = uVar7;
  *(undefined4 *)(in_zero + 0xa00) = uVar15;
  *(undefined4 *)(in_zero + 0xa14) = 0;
  _DAT_ffffffff80000a04 = 0xbfc436e0;
  _DAT_ffffffff80000a68 = uVar14;
  (*(code *)(long)DAT_ffffffffbfc43f38)(2);
  (*(code *)(long)DAT_ffffffffbfc43878)(0);
  do {
    (*(code *)(long)DAT_ffffffffbfc43d8c)();
  } while( true );
}

