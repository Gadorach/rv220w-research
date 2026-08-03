/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2f384
 * Function: FUN_ffffffffbfc2f384
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

undefined4 FUN_ffffffffbfc2f384(void)

{
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined8 unaff_s0;
  uint uVar12;
  undefined8 unaff_s1;
  long unaff_s2;
  long lVar13;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int iVar14;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar15;
  undefined8 *puVar16;
  undefined8 unaff_s8;
  int iVar17;
  undefined8 in_ra;
  
  puVar16 = (undefined8 *)(long)((int)&stack0x00000000 + -0xf0);
  puVar16[0x1a] = &_gp;
  puVar16[0x1c] = in_ra;
  puVar16[0x1b] = unaff_s8;
  pcVar15 = (code *)(long)DAT_ffffffffbfc43c04;
  iVar17 = 0;
  puVar16[0x19] = unaff_s7;
  puVar16[0x18] = unaff_s6;
  puVar16[0x17] = unaff_s5;
  puVar16[0x16] = unaff_s4;
  puVar16[0x15] = unaff_s3;
  puVar16[0x14] = unaff_s2;
  puVar16[0x13] = unaff_s1;
  puVar16[0x12] = unaff_s0;
  *(undefined4 *)(puVar16 + 0x11) = 0;
  uVar4 = (*pcVar15)();
  pcVar15 = (code *)(long)DAT_ffffffffbfc43848;
  *(undefined4 *)((long)puVar16 + 0x84) = uVar4;
  (*pcVar15)();
  iVar5 = DAT_ffffffffbfc436f8 + 0x1b38;
  do {
    *(int *)(puVar16 + 0x10) = iVar5;
    if (*(int *)((long)puVar16 + 0x84) <= iVar17) {
      pcVar15 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x1508);
      (*pcVar15)(0x80014f0000000000,0x17);
      (*pcVar15)(0x80014f0000000008,0);
      (*pcVar15)(0x80014f0000000010,0x100);
      (*pcVar15)(0x80014f0000000150,1);
      (*pcVar15)(0x80014f0000000158,0);
      (*pcVar15)(&DAT_80014f0000000020,1);
      (*pcVar15)(&DAT_80014f0000000018,_DAT_80014f0000000018 & 0xfffffffffffffff1 | 8);
      lVar13 = 0;
      (*pcVar15)(0x80011800f0000000,0xfff);
      iVar5 = (*(code *)(long)DAT_ffffffffbfc43c04)();
      for (uVar12 = 0; (int)uVar12 < iVar5; uVar12 = uVar12 + 1) {
        uVar3 = (*(code *)(long)DAT_ffffffffbfc43bc0)(uVar12);
        if (uVar3 < 8) {
          uVar3 = 1L << uVar3 & 0xce;
          if ((uVar3 != 0) && (special2(lVar13,uVar3,0x1b,0x32), (uVar12 & 0xfffffffe) == 0)) {
            (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x1508))(uVar3 + 0x80011800080004c8,0xf0f);
          }
        }
        lVar13 = lVar13 + 1;
      }
      return *(undefined4 *)(puVar16 + 0x11);
    }
    uVar4 = (*(code *)(long)DAT_ffffffffbfc43f1c)(iVar17);
    *(undefined4 *)((long)puVar16 + 0x8c) = uVar4;
    uVar3 = (ulong)*(int *)(long)*(int *)(puVar16 + 0x10);
    if (0 < (long)uVar3) {
      uVar1 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar17);
      uVar1 = (*(code *)(long)DAT_ffffffffbfc43c48)(uVar1);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1fc8,iVar17,uVar3,uVar1);
    }
    lVar2 = (*(code *)(long)DAT_ffffffffbfc43b94)(iVar17,0);
    iVar5 = *(int *)(long)*(int *)(puVar16 + 0x10);
    lVar13 = lVar2;
    while( true ) {
      lVar9 = lVar13;
      iVar5 = iVar5 + -1;
      special2(lVar9,uVar3,3,0x32);
      if (iVar5 == -1) break;
      uVar3 = *(ulong *)(uVar3 + 0x80011800a0000400) & 0xfffffffffe000000 | 0x1000000;
      uVar1 = special2(lVar2,unaff_s2,3,0x32);
      iVar14 = DAT_ffffffffbfc436f0 + -0x1508;
      lVar2 = (long)((int)lVar2 + 1);
      (*(code *)(long)iVar14)(unaff_s2 + -0x7ffee7ff5ffffe00,uVar1);
      (*(code *)(long)iVar14)(unaff_s2 + -0x7ffee7ff5ffffc00,uVar3);
      lVar13 = (long)((int)lVar9 + 1);
      if ((code *)(long)*(int *)(long)DAT_ffffffffbfc43c28 != (code *)0x0) {
        (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43c28)(lVar9);
      }
    }
    puVar10 = (undefined8 *)(long)(DAT_ffffffffbfc436f0 + 0x6bd8);
    iVar5 = DAT_ffffffffbfc436f0 + 0x6c58;
    puVar11 = puVar16;
    do {
      uVar1 = *puVar10;
      uVar6 = puVar10[1];
      uVar7 = puVar10[2];
      uVar8 = puVar10[3];
      puVar10 = (undefined8 *)(long)((int)puVar10 + 0x20);
      *puVar11 = uVar1;
      puVar11[1] = uVar6;
      puVar11[2] = uVar7;
      puVar11[3] = uVar8;
      puVar11 = (undefined8 *)(long)((int)puVar11 + 0x20);
    } while (puVar10 != (undefined8 *)(long)iVar5);
    lVar2 = (*(code *)(long)DAT_ffffffffbfc43b94)(iVar17,0);
    iVar5 = *(int *)(long)*(int *)(puVar16 + 0x10);
    lVar13 = lVar2;
    while( true ) {
      iVar5 = iVar5 + -1;
      if (iVar5 == -1) break;
      if ((code *)(long)*(int *)(long)DAT_ffffffffbfc439e4 != (code *)0x0) {
        (*(code *)(long)*(int *)(long)DAT_ffffffffbfc439e4)(lVar2,puVar16);
      }
      iVar14 = (int)lVar2;
      lVar9 = lVar13;
      if (lVar2 < 0x10) {
LAB_ffffffffbfc2f5d4:
        uVar1 = 1;
      }
      else {
        lVar9 = lVar2;
        if (((0xf < iVar14 - 0x10U) && (3 < iVar14 - 0x20U)) && (3 < iVar14 - 0x24U)) {
          lVar9 = 0xffff;
        }
        if ((lVar2 < 0x20) || (uVar1 = 1, lVar2 < 0x24)) goto LAB_ffffffffbfc2f5d4;
        if (0x27 < lVar2) {
          uVar1 = 0;
        }
      }
      lVar2 = (long)(iVar14 + 1);
      (*(code *)(long)DAT_ffffffffbfc43c10)(lVar13,lVar9,uVar1,puVar16);
      lVar13 = lVar13 + 1;
    }
    iVar17 = iVar17 + 1;
    *(uint *)(puVar16 + 0x11) = *(uint *)(puVar16 + 0x11) | *(uint *)((long)puVar16 + 0x8c);
    iVar5 = *(int *)(puVar16 + 0x10) + 4;
    unaff_s2 = -1;
  } while( true );
}

