/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2fca0
 * Function: FUN_ffffffffbfc2fca0
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

bool FUN_ffffffffbfc2fca0(void)

{
  bool bVar1;
  byte bVar2;
  ulong *puVar3;
  ulong *puVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  int iVar11;
  int iVar12;
  int *piVar9;
  ulong *puVar10;
  long lVar13;
  ulong unaff_s0;
  long lVar14;
  int iVar15;
  ulong unaff_s1;
  ulong uVar16;
  byte *pbVar17;
  ulong unaff_s2;
  ulong uVar18;
  uint uVar19;
  ulong unaff_s3;
  ulong unaff_s4;
  ulong unaff_s5;
  ulong unaff_s6;
  ulong unaff_s7;
  code *pcVar20;
  undefined1 *puVar21;
  ulong *puVar22;
  ulong unaff_s8;
  ulong in_ra;
  undefined8 in_HW_RESIM31;
  
  puVar22 = (ulong *)(long)((int)&stack0x00000000 + -0x90);
  puVar22[0xe] = (ulong)&_gp;
  puVar22[0xf] = unaff_s8;
  iVar11 = DAT_ffffffffbfc436f0;
  puVar21 = &_gp;
  puVar22[0x10] = in_ra;
  puVar22[0xd] = unaff_s7;
  puVar22[0xc] = unaff_s6;
  puVar22[0xb] = unaff_s5;
  puVar22[10] = unaff_s4;
  puVar22[9] = unaff_s3;
  puVar22[8] = unaff_s2;
  puVar22[7] = unaff_s1;
  puVar22[6] = unaff_s0;
  puVar3 = (ulong *)(*(code *)(long)(iVar11 + -0x814))(0,0);
  puVar22[4] = *puVar3;
  puVar22[3] = _DAT_80011800b0000008;
  puVar22[2] = _DAT_80011800b0000000;
  puVar4 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + -0x7e8))(0,0);
  pcVar20 = (code *)(long)DAT_ffffffffbfc43d58;
  puVar22[1] = *puVar4;
  (*pcVar20)(0);
  (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x7bc))(&DAT_80011800b0000000,0);
  lVar13 = getHWRegister(in_HW_RESIM31);
  do {
    uVar5 = getHWRegister(in_HW_RESIM31);
  } while (uVar5 < lVar13 + 100000000U);
  *(undefined4 *)(puVar22 + 5) = 0;
  do {
    uVar19 = (((uint)((ulong)(long)(int)(uint)_DAT_80014f0000000320 >> 7) & 0x7f) -
             ((uint)_DAT_80014f0000000320 & 0x7f)) + 2 & 3;
    lVar13 = 0;
    if (uVar19 == 0) break;
    lVar13 = (long)(int)(uVar19 + 1);
    (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x7bc))(0x80011800b0000040,1);
    SYNC(0);
    iVar11 = *(int *)(puVar21 + 0x10);
    uVar6 = (*(code *)(long)(iVar11 + -0x5ac))(1);
    iVar12 = *(int *)(puVar21 + 0x10);
    uVar5 = (*(code *)(long)(iVar12 + -0x56c))(uVar6);
    if ((uVar5 & 0xffffffffff) == 0) {
LAB_ffffffffbfc2fe54:
      (*(code *)(long)*(int *)(puVar21 + 0x92c))(*(int *)(puVar21 + 0x14) + 0x2028);
      iVar11 = *(int *)(puVar21 + 0x10);
      goto LAB_ffffffffbfc30318;
    }
    uVar6 = (*(code *)(long)(iVar11 + -0x5ac))(0);
    uVar7 = (*(code *)(long)(iVar12 + -0x56c))(uVar6);
    uVar5 = uVar5 & 0xffffffffff | 0x100000000000000 | lVar13 << 0x28;
    if ((uVar7 & 0xffffffffff) == 0) goto LAB_ffffffffbfc2fe54;
    uVar18 = uVar7 & 0xffffffffff | 0x8007400000000000;
    iVar11 = (uVar19 + 1) * 0x7f8;
    puVar8 = (undefined8 *)
             (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x704))(uVar7 & 0xffffffffff);
    lVar14 = 0;
    puVar8[1] = 0x8004510;
    puVar8[2] = (long)(iVar11 + -0x4c2) << 0x30 | 0x5ae740004000;
    puVar8[3] = 0x3a5fc0a81073c0a8;
    *puVar8 = 0xffffffffffff0000;
    uVar7 = uVar5;
    while( true ) {
      uVar16 = uVar7 & 0xffffffffff;
      uVar7 = uVar16 + 8;
      if (lVar13 <= lVar14) break;
      if (0 < lVar14) {
        uVar18 = uVar18 & 0xff0000ffffffffff | 0x7f80000000000;
      }
      if (lVar14 == (int)uVar19) {
        uVar18 = uVar18 & 0x7fffffffffffffff;
      }
      lVar14 = (long)((int)lVar14 + 1);
      puVar10 = (ulong *)(*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x704))(uVar16);
      *puVar10 = uVar18;
    }
    special2(0xffffffffffffffff,unaff_s4,0x1f,0x32);
    unaff_s4 = unaff_s4 & 0xffffffffffc00000 | lVar13 << 0x10 | (long)(iVar11 + -0x4b4) & 0xffffU;
    pcVar20 = (code *)(long)(*(int *)(puVar21 + 0x10) + -0x7bc);
    (*pcVar20)(puVar3,*puVar3 | 1);
    (*pcVar20)(&DAT_80011800b0000008,1);
    (*pcVar20)(&DAT_80011800b0000000,1);
    (*pcVar20)(puVar4,0xff5e);
    uVar7 = (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x76c))(0);
    *puVar22 = uVar7;
    uVar7 = uVar7 & 0xffff;
    if (uVar7 < 0x100) {
      iVar11 = (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x78c))(uVar7);
      pbVar17 = (byte *)(long)(iVar11 * 0x10 + 0x2800 + *(int *)(long)*(int *)(puVar21 + 0x94));
      if (pbVar17 != (byte *)0x0) {
        prefetch(pbVar17,0);
        iVar11 = *(int *)(long)*(int *)(puVar21 + 0x94);
        iVar12 = (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x78c))(uVar7);
        piVar9 = (int *)(long)(iVar12 * 8 + iVar11);
        iVar11 = *piVar9;
        uVar6 = special2(1,(long)iVar11,0,0x28);
        *piVar9 = (int)uVar6;
        bVar2 = *pbVar17;
        while ((ulong)bVar2 != (long)iVar11) {
          lVar14 = (long)(int)((iVar11 - (uint)bVar2) + -1);
          special2(lVar14,lVar14,5,0x32);
          do {
            bVar1 = lVar14 != 0;
            lVar14 = (long)((int)lVar14 + -1);
          } while (bVar1);
          bVar2 = *pbVar17;
        }
        uVar7 = *(ulong *)(pbVar17 + 8);
        uVar19 = (uint)uVar7 & 0x1fff;
        uVar18 = uVar7 >> 0xd & 0x1fff;
        if ((ulong)(long)(int)(uVar19 + 2) < uVar18) {
          iVar11 = (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x704))
                             ((uVar7 >> 0x20 & 0x1fffffff) << 7);
          uVar19 = (uint)*(ulong *)(pbVar17 + 8) & 0x1fff;
          puVar10 = (ulong *)(long)(int)(iVar11 + uVar19 * 8);
          *(ulong *)(pbVar17 + 8) =
               *(ulong *)(pbVar17 + 8) & 0xffffffffffffe000 | (long)(int)(uVar19 + 2) & 0x1fffU;
          puVar10[1] = uVar5;
          *puVar10 = unaff_s4;
        }
        else {
          puVar10 = (ulong *)(*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x5ac))(uVar7 >> 0x3d);
          if (puVar10 == (ulong *)0x0) {
            *pbVar17 = *pbVar17 + 1;
            SYNC(4);
            SYNC(4);
            goto LAB_ffffffffbfc301c0;
          }
          iVar11 = (int)uVar18 - uVar19;
          iVar12 = (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x704))
                             ((*(ulong *)(pbVar17 + 8) >> 0x20 & 0x1fffffff) << 7);
          iVar12 = iVar12 + ((uint)*(undefined8 *)(pbVar17 + 8) & 0x1fff) * 8;
          *(ulong *)(long)iVar12 = unaff_s4;
          iVar15 = iVar12 + 8;
          if (iVar11 != 1) {
            ((ulong *)(long)iVar12)[1] = uVar5;
            iVar15 = iVar12 + 0x10;
          }
          uVar7 = (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x56c))(puVar10);
          *(ulong *)(long)iVar15 = uVar7;
          special2(uVar7,uVar7,7,0x3a);
          puVar21 = (undefined1 *)special2(uVar7,uVar7,0,0x33);
          uVar7 = (*(ulong *)(pbVar17 + 8) & 0xe0000000ffffffff | uVar7) & 0xffffffffffffe000;
          *(ulong *)(pbVar17 + 8) = uVar7;
          if (iVar11 == 1) {
            *(ulong *)(pbVar17 + 8) = uVar7 | 1;
            *puVar10 = uVar5;
          }
        }
        *pbVar17 = *pbVar17 + 1;
        SYNC(4);
        SYNC(4);
        SYNC(4);
        SYNC(4);
        *(undefined8 *)((*puVar22 & 0x1ff) << 3 | 0x8001520000000000) = 2;
      }
    }
LAB_ffffffffbfc301c0:
    SYNC(0);
    iVar12 = 100000;
    iVar11 = *(int *)(puVar21 + 0x10);
    do {
      (*(code *)(long)(iVar11 + -0x734))(*(int *)(puVar21 + 0x10) + 0x6c60);
      (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x3c8))();
      (*(code *)(long)(iVar11 + -0x734))(*(int *)(puVar21 + 0x10) + 0x6c80);
      iVar12 = iVar12 + -1;
      lVar14 = 0;
      if ((-1 < (long)_DAT_8001600000000008) &&
         (lVar14 = (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x704))
                             (_DAT_8001600000000008 & 0xffffffffff), lVar14 != 0)) break;
      iVar11 = *(int *)(puVar21 + 0x10);
    } while (0 < iVar12);
    if (iVar12 == 0) {
      (*(code *)(long)*(int *)(puVar21 + 0x92c))(*(int *)(puVar21 + 0x14) + 0x2068);
    }
    iVar11 = *(int *)(puVar22 + 5);
    if (lVar14 != 0) {
      uVar7 = (ulong)*(byte *)(lVar14 + 0x10);
      uVar5 = *(ulong *)(lVar14 + 0x18);
      while( true ) {
        uVar18 = uVar5 & 0xffffffffff;
        uVar16 = uVar5 >> 0x3b;
        uVar7 = uVar7 - 1;
        iVar11 = *(int *)(puVar21 + 0x10);
        unaff_s4 = uVar5 >> 0x38 & 7;
        if (uVar7 == 0xffffffffffffffff) break;
        puVar10 = (ulong *)(*(code *)(long)(iVar11 + -0x704))(uVar18 - 8 & 0xffffffffff);
        uVar5 = *puVar10;
        uVar6 = (*(code *)(long)(iVar11 + -0x704))
                          (((uVar18 >> 7) - (uVar16 & 0xf) & 0xffffffffff) << 7);
        uVar18 = (*(code *)(long)(*(int *)(puVar21 + 0x10) + -0x56c))(uVar6);
        SYNC(4);
        SYNC(4);
        *(undefined8 *)(uVar18 & 0xffffffffff | (unaff_s4 | 0x800128) << 0x28) = 0;
      }
      iVar11 = *(int *)(puVar22 + 5);
    }
    *(int *)(puVar22 + 5) = iVar11 + 1;
  } while (iVar11 + 1 != 10);
  iVar11 = *(int *)(puVar21 + 0x10);
LAB_ffffffffbfc30318:
  pcVar20 = (code *)(long)(iVar11 + -0x7bc);
  (*pcVar20)(puVar3,puVar22[4]);
  (*pcVar20)(&DAT_80011800b0000008,puVar22[3]);
  (*pcVar20)(&DAT_80011800b0000000,puVar22[2]);
  (*pcVar20)(puVar4,puVar22[1]);
  (*pcVar20)(0x80011800b0000040,0);
  (*(code *)(long)*(int *)(puVar21 + 0x89c))(0,0);
  (*(code *)(long)*(int *)(puVar21 + 0x2a8))(0);
  SYNC(0);
  if (lVar13 != 0) {
    (*(code *)(long)*(int *)(puVar21 + 0x92c))(*(int *)(puVar21 + 0x14) + 0x20a8);
  }
  return lVar13 != 0;
}

