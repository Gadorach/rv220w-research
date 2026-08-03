/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2b654
 * Function: FUN_ffffffffbfc2b654
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

undefined8 FUN_ffffffffbfc2b654(void)

{
  int iVar4;
  long lVar1;
  long lVar2;
  ulong *puVar3;
  int iVar5;
  ulong uVar6;
  undefined8 unaff_s0;
  int iVar7;
  uint uVar8;
  int iVar9;
  ulong unaff_s1;
  undefined8 unaff_s2;
  int iVar11;
  undefined4 *puVar10;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar12;
  long lVar13;
  undefined8 unaff_s8;
  undefined8 uVar14;
  undefined8 in_ra;
  
  lVar13 = (long)((int)&stack0x00000000 + -0xd0);
  *(undefined1 **)(lVar13 + 0xb0) = &_gp;
  *(undefined8 *)(lVar13 + 0xa8) = unaff_s7;
  pcVar12 = (code *)(long)DAT_ffffffffbfc43c04;
  *(undefined8 *)(lVar13 + 0xc0) = in_ra;
  *(undefined8 *)(lVar13 + 0xb8) = unaff_s8;
  *(undefined8 *)(lVar13 + 0xa0) = unaff_s6;
  *(undefined8 *)(lVar13 + 0x98) = unaff_s5;
  *(undefined8 *)(lVar13 + 0x90) = unaff_s4;
  *(undefined8 *)(lVar13 + 0x88) = unaff_s3;
  *(undefined8 *)(lVar13 + 0x80) = unaff_s2;
  *(ulong *)(lVar13 + 0x78) = unaff_s1;
  *(undefined8 *)(lVar13 + 0x70) = unaff_s0;
  iVar4 = (*pcVar12)();
  iVar9 = 2;
  if (iVar4 < 3) {
    iVar9 = iVar4;
  }
  if (*(int *)(long)DAT_ffffffffbfc43ee4 == 0) {
    return 0;
  }
  iVar7 = DAT_ffffffffbfc436f0 + -0x6700;
  lVar1 = (*(code *)(long)iVar7)(0xd0000);
  iVar4 = DAT_ffffffffbfc436f4;
  if (lVar1 == 0) {
    lVar1 = (*(code *)(long)iVar7)(0xd0001);
    iVar4 = 0;
    if (lVar1 == 0) {
      lVar1 = 0;
    }
    else {
      lVar1 = 0;
      if (*(int *)(long)DAT_ffffffffbfc43c1c == 0) {
        pcVar12 = (code *)(long)DAT_ffffffffbfc4400c;
        iVar4 = DAT_ffffffffbfc436f4 + 0x1b88;
        goto LAB_ffffffffbfc2b740;
      }
    }
    for (; iVar4 < iVar9; iVar4 = iVar4 + 1) {
      lVar2 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar4);
      if (lVar2 == 1) {
LAB_ffffffffbfc2b7a0:
        special2(lVar1,unaff_s1,0x1b,0x32);
        iVar7 = DAT_ffffffffbfc436f0 + -0x6504;
        (*(code *)(long)iVar7)(&DAT_80011800b0000000 + unaff_s1,0);
        (*(code *)(long)iVar7)(&DAT_80011800b0000008 + unaff_s1,0);
        iVar7 = (*(code *)(long)DAT_ffffffffbfc43d30)(iVar4);
        for (iVar5 = 0; iVar5 < iVar7; iVar5 = iVar5 + 1) {
          puVar3 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6588))(iVar5,iVar4);
          unaff_s1 = *puVar3;
          pcVar12 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x6504);
          (*pcVar12)(puVar3,unaff_s1 & 0xfffffffffffffffe);
          uVar14 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6530))(iVar5,iVar4);
          (*pcVar12)(uVar14,1);
          uVar14 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x655c))(iVar5,iVar4);
          (*pcVar12)(uVar14,0);
          (*pcVar12)(puVar3,unaff_s1);
        }
      }
      else {
        lVar2 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar4);
        if (lVar2 == 2) goto LAB_ffffffffbfc2b7a0;
        lVar2 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar4);
        if ((lVar2 == 6) || (lVar2 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar4), lVar2 == 5))
        goto LAB_ffffffffbfc2b7a0;
      }
      lVar1 = lVar1 + 1;
    }
    uVar14 = 0;
    for (iVar4 = 0; iVar4 < iVar9; iVar4 = iVar4 + 1) {
      iVar5 = (*(code *)(long)DAT_ffffffffbfc43d30)(iVar4);
      for (iVar7 = iVar4 * 0x10; iVar7 < iVar4 * 0x10 + iVar5; iVar7 = iVar7 + 1) {
        iVar11 = 100;
        uVar6 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6494))(iVar7);
        while( true ) {
          lVar1 = (*(code *)(long)DAT_ffffffffbfc4390c)(uVar6 & 0xffff);
          if ((lVar1 == 0) || (iVar11 == 0)) break;
          iVar11 = iVar11 + -1;
          (*(code *)(long)DAT_ffffffffbfc43b18)(10000);
        }
        lVar1 = (*(code *)(long)DAT_ffffffffbfc4390c)(uVar6 & 0xffff);
        if (lVar1 != 0) {
          uVar14 = 0xffffffffffffffff;
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1bc0,uVar6,lVar1);
        }
      }
    }
    while (lVar1 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x5500))(1), lVar1 != 0) {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x569c))(lVar1);
      (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x5704))(lVar1,1,0);
    }
    lVar1 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6700))(0xd0001);
    if (lVar1 != 0) {
      puVar10 = (undefined4 *)(long)*(int *)((long)*(int *)(long)DAT_ffffffffbfc43c1c + 0x34);
      (*(code *)(long)DAT_ffffffffbfc43d58)(*puVar10);
      uVar8 = ((uint)_DAT_80014f0000000320 & 0x7f) + ((uint)(_DAT_80014f0000000320 >> 0x11) & 1) & 7
      ;
      while( true ) {
        uVar8 = uVar8 - 1;
        if (uVar8 == 0xffffffff) break;
        (*(code *)(long)DAT_ffffffffbfc43a3c)(*(undefined4 *)(long)DAT_ffffffffbfc43c1c,lVar13,100);
        (*(code *)(long)DAT_ffffffffbfc43b18)(50000);
      }
      (*(code *)(long)DAT_ffffffffbfc43b18)(200000);
      if ((((uint)_DAT_80014f0000000320 & 0x7f) + ((uint)(_DAT_80014f0000000320 >> 0x11) & 1) & 7)
          != 0) {
        pcVar12 = (code *)(long)DAT_ffffffffbfc4400c;
        iVar4 = DAT_ffffffffbfc436f4 + 0x1c00;
        goto LAB_ffffffffbfc2b740;
      }
      uVar6 = (ulong)(uint)puVar10[1];
      pcVar12 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x6504);
      special2(uVar6,uVar6,0x1b,0x32);
      (*pcVar12)(&DAT_80011800b0000000 + uVar6,0);
      uVar6 = (ulong)(uint)puVar10[1];
      special2(uVar6,uVar6,0x1b,0x32);
      (*pcVar12)(&DAT_80011800b0000008 + uVar6,0);
      uVar6 = (ulong)(uint)puVar10[1];
      special2(uVar6,uVar6,0x1b,0x32);
      (*pcVar12)(uVar6 + 0x80011800b0000040,0);
      puVar10[4] = puVar10[4] & 0xf7ffffff;
    }
    while (lVar1 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x5500))(1), lVar1 != 0) {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x569c))(lVar1);
      (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x5704))(lVar1,1,0);
    }
    iVar9 = 0;
    do {
      do {
        lVar1 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x57c8))(iVar9);
      } while (lVar1 != 0);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 8);
    (*(code *)(long)DAT_ffffffffbfc43b18)(50000);
    pcVar12 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x6504);
    (*pcVar12)(&DAT_80014f0000000018,_DAT_80014f0000000018 | 0x100);
    lVar1 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6700))(0xd0001);
    if (lVar1 == 0) {
      (*pcVar12)(&DAT_80011800a0000030,_DAT_80011800a0000030 | 1);
    }
    (*pcVar12)(&DAT_8001180050000000,_DAT_8001180050000000 | 8);
    (*pcVar12)(&DAT_8001180028000050,_DAT_8001180028000050 | 0x20000);
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
    (*(code *)(long)DAT_ffffffffbfc4400c)(iVar4 + 0x1150);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1b50);
    iVar4 = iVar4 + 0x1150;
    pcVar12 = (code *)(long)DAT_ffffffffbfc4400c;
LAB_ffffffffbfc2b740:
    uVar14 = 0xffffffffffffffff;
    (*pcVar12)(iVar4);
  }
  return uVar14;
}

