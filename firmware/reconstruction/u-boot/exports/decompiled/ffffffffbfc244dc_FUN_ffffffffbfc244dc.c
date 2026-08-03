/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc244dc
 * Function: FUN_ffffffffbfc244dc
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

undefined8
FUN_ffffffffbfc244dc
          (int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,int *param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined8 uVar4;
  int iVar5;
  undefined1 uVar6;
  long lVar7;
  int iVar10;
  ulong uVar8;
  undefined8 uVar9;
  uint uVar12;
  uint *puVar11;
  int *piVar13;
  ulong uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  ulong uVar19;
  uint uVar20;
  long lVar21;
  long lVar22;
  ulong uVar23;
  long lVar24;
  uint *puVar25;
  undefined8 unaff_s0;
  int iVar26;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  ulong uVar27;
  int iVar28;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  int iVar29;
  char *pcVar30;
  undefined8 unaff_s8;
  int iVar33;
  undefined8 in_ra;
  int iVar31;
  int iVar32;
  
  iVar32 = (int)&stack0x00000000;
  iVar31 = iVar32 + -0x620;
  pcVar30 = (char *)(long)iVar31;
  *(undefined1 **)(pcVar30 + 0x600) = &_gp;
  *(undefined4 *)(pcVar30 + 0x568) = param_3;
  *(undefined4 *)(pcVar30 + 0x56c) = param_4;
  *(undefined8 *)(pcVar30 + 0x610) = in_ra;
  *(undefined8 *)(pcVar30 + 0x608) = unaff_s8;
  *(undefined8 *)(pcVar30 + 0x5f8) = unaff_s7;
  *(undefined8 *)(pcVar30 + 0x5f0) = unaff_s6;
  *(undefined8 *)(pcVar30 + 0x5e8) = unaff_s5;
  *(undefined8 *)(pcVar30 + 0x5e0) = unaff_s4;
  *(undefined8 *)(pcVar30 + 0x5d8) = unaff_s3;
  *(undefined8 *)(pcVar30 + 0x5d0) = unaff_s2;
  *(undefined8 *)(pcVar30 + 0x5c8) = unaff_s1;
  *(undefined8 *)(pcVar30 + 0x5c0) = unaff_s0;
  pcVar30[0x44] = '\0';
  pcVar30[0x45] = '\0';
  pcVar30[0x46] = '\0';
  pcVar30[0x47] = '\0';
  pcVar30[0x48] = '\0';
  pcVar30[0x49] = '\0';
  pcVar30[0x4a] = '\0';
  pcVar30[0x4b] = '\0';
  pcVar30[0x4c] = '\0';
  pcVar30[0x4d] = '\0';
  pcVar30[0x4e] = '\0';
  pcVar30[0x4f] = '\0';
  *(undefined4 *)(pcVar30 + 0x570) = param_5;
  pcVar30[0x50] = '\0';
  pcVar30[0x51] = '\0';
  pcVar30[0x52] = '\0';
  pcVar30[0x53] = '\0';
  *(undefined4 *)(pcVar30 + 0x574) = param_6;
  pcVar30[0x54] = '\0';
  pcVar30[0x55] = '\0';
  pcVar30[0x56] = '\0';
  pcVar30[0x57] = '\0';
  pcVar30[0x58] = '\0';
  pcVar30[0x59] = '\0';
  pcVar30[0x5a] = '\0';
  pcVar30[0x5b] = '\0';
  *(undefined4 *)(pcVar30 + 0x578) = param_8;
  pcVar30[0x5c] = '\0';
  pcVar30[0x5d] = '\0';
  pcVar30[0x5e] = '\0';
  pcVar30[0x5f] = '\0';
  pcVar30[0x60] = '\0';
  pcVar30[0x61] = '\0';
  pcVar30[0x62] = '\0';
  pcVar30[99] = '\0';
  pcVar30[100] = '\0';
  pcVar30[0x65] = '\0';
  pcVar30[0x66] = '\0';
  pcVar30[0x67] = '\0';
  pcVar30[0x68] = '\0';
  pcVar30[0x69] = '\0';
  pcVar30[0x6a] = '\0';
  pcVar30[0x6b] = '\0';
  pcVar30[0x6c] = '\0';
  pcVar30[0x6d] = '\0';
  pcVar30[0x6e] = '\0';
  pcVar30[0x6f] = '\0';
  pcVar30[0x70] = '\0';
  pcVar30[0x71] = '\0';
  pcVar30[0x72] = '\0';
  pcVar30[0x73] = '\0';
  pcVar30[0x74] = '\0';
  pcVar30[0x75] = '\0';
  pcVar30[0x76] = '\0';
  pcVar30[0x77] = '\0';
  pcVar30[0x78] = '\0';
  pcVar30[0x79] = '\0';
  pcVar30[0x7a] = '\0';
  pcVar30[0x7b] = '\0';
  pcVar30[0x7c] = '\0';
  pcVar30[0x7d] = '\0';
  pcVar30[0x7e] = '\0';
  pcVar30[0x7f] = '\0';
  pcVar30[0x80] = '\0';
  pcVar30[0x81] = '\0';
  pcVar30[0x82] = '\0';
  pcVar30[0x83] = '\0';
  piVar13 = param_1;
  uVar15 = param_2;
  do {
    iVar10 = *piVar13;
    uVar15 = uVar15 - 1;
    piVar13 = (int *)(long)((int)piVar13 + 4);
    lVar7 = (long)(iVar10 * 4 + iVar31);
    *(int *)(lVar7 + 0x44) = *(int *)(lVar7 + 0x44) + 1;
  } while (uVar15 != 0);
  uVar19 = 1;
  if (*(uint *)(pcVar30 + 0x44) == param_2) {
    iVar32 = *(int *)(pcVar30 + 0x574);
    *param_7 = 0;
    *(undefined4 *)(long)iVar32 = 0;
    uVar4 = 0;
  }
  else {
    iVar10 = iVar32 + -0x5d8;
    do {
      piVar13 = (int *)(long)iVar10;
      iVar10 = iVar10 + 4;
      if (*piVar13 != 0) break;
      uVar19 = (ulong)((int)uVar19 + 1);
    } while (uVar19 != 0x10);
    uVar27 = (long)*param_7;
    if ((ulong)(long)*param_7 < uVar19) {
      uVar27 = uVar19;
    }
    uVar23 = 0xf;
    iVar10 = iVar32 + -0x5a0;
    do {
      piVar13 = (int *)(long)iVar10;
      iVar10 = iVar10 + -4;
      if (*piVar13 != 0) break;
      uVar23 = (ulong)((int)uVar23 + -1);
    } while (uVar23 != 0);
    uVar15 = (uint)uVar19;
    if (uVar23 < uVar27) {
      uVar27 = uVar23;
    }
    iVar16 = 1 << (uVar15 & 0x1f);
    iVar28 = (int)uVar27;
    *param_7 = iVar28;
    iVar10 = iVar32 + -0x5dc + uVar15 * 4;
    uVar8 = uVar19;
    while( true ) {
      piVar13 = (int *)(long)iVar10;
      bVar3 = uVar23 <= uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
      if (bVar3) break;
      iVar10 = iVar10 + 4;
      if (iVar16 - *piVar13 < 0) goto LAB_ffffffffbfc24a54;
      iVar16 = (iVar16 - *piVar13) * 2;
    }
    lVar7 = (long)((int)uVar23 * 4 + iVar31);
    iVar10 = *(int *)(lVar7 + 0x44);
    iVar16 = iVar16 - iVar10;
    *(int *)(pcVar30 + 0x564) = iVar16;
    if (iVar16 < 0) {
LAB_ffffffffbfc24a54:
      uVar4 = 0xfffffffffffffffd;
    }
    else {
      *(int *)(lVar7 + 0x44) = iVar10 + iVar16;
      iVar18 = 0;
      pcVar30[0x88] = '\0';
      pcVar30[0x89] = '\0';
      pcVar30[0x8a] = '\0';
      pcVar30[0x8b] = '\0';
      iVar16 = iVar32 + -0x5d8;
      iVar10 = iVar32 + -0x594;
      uVar8 = uVar23;
      while( true ) {
        piVar13 = (int *)(long)iVar16;
        uVar8 = (ulong)((int)uVar8 + -1);
        if (uVar8 == 0) break;
        iVar16 = iVar16 + 4;
        iVar18 = iVar18 + *piVar13;
        *(int *)(long)iVar10 = iVar18;
        iVar10 = iVar10 + 4;
      }
      uVar17 = 0;
      do {
        iVar10 = *param_1;
        param_1 = (int *)(long)((int)param_1 + 4);
        if (iVar10 != 0) {
          lVar7 = (long)(iVar10 * 4 + iVar31);
          iVar10 = *(int *)(lVar7 + 0x84);
          *(int *)(lVar7 + 0x84) = iVar10 + 1;
          *(uint *)((long)(iVar10 * 4 + iVar31) + 0xc4) = uVar17;
        }
        uVar17 = uVar17 + 1;
      } while (uVar17 < param_2);
      iVar10 = iVar32 + -0x5dc + uVar15 * 4;
      lVar24 = (long)-iVar28;
      pcVar30[0x84] = '\0';
      pcVar30[0x85] = '\0';
      pcVar30[0x86] = '\0';
      pcVar30[0x87] = '\0';
      lVar21 = -1;
      *(uint *)(pcVar30 + 0x560) = iVar32 + -0x55c + param_2 * 4;
      iVar16 = 0;
      pcVar30[8] = '\0';
      pcVar30[9] = '\0';
      pcVar30[10] = '\0';
      pcVar30[0xb] = '\0';
      *(int *)(pcVar30 + 0x550) = iVar32 + -0x55c;
      *(int *)(pcVar30 + 0x558) = iVar10;
      pcVar30[0x554] = '\0';
      pcVar30[0x555] = '\0';
      pcVar30[0x556] = '\0';
      pcVar30[0x557] = '\0';
      uVar15 = 0;
      lVar7 = lVar24;
      while( true ) {
        puVar25 = (uint *)(long)iVar10;
        if ((long)uVar23 < (long)uVar19) break;
        lVar22 = (long)*(int *)(long)*(int *)(pcVar30 + 0x558);
        while( true ) {
          lVar22 = (long)((int)lVar22 + -1);
          if (lVar22 == -1) break;
          iVar10 = ((int)lVar21 + 1) * 4;
          iVar18 = (int)lVar7;
          iVar33 = iVar32 + -0x618 + iVar10;
          iVar29 = (int)uVar23 - (iVar18 + iVar28);
          *(int *)(pcVar30 + 0x55c) = iVar32 + -0x59c + iVar10;
          uVar17 = (int)uVar19 - (iVar18 + iVar28);
          iVar10 = 0;
          while( true ) {
            uVar8 = (ulong)(int)uVar17;
            uVar20 = iVar18 + iVar10;
            lVar7 = (long)(int)uVar20;
            if ((long)uVar19 <= (long)(iVar18 + iVar28 + iVar10)) break;
            uVar12 = 1 << (uVar17 & 0x1f);
            uVar20 = uVar17;
            if ((int)lVar22 + 1U < uVar12) {
              uVar14 = (long)iVar29;
              if (uVar27 <= (ulong)(long)iVar29) {
                uVar14 = uVar27;
              }
              if (uVar8 < uVar14) {
                iVar16 = (uVar12 - (int)lVar22) + -1;
                puVar11 = puVar25;
                do {
                  uVar20 = (int)uVar8 + 1;
                  uVar8 = (ulong)(int)uVar20;
                  puVar11 = (uint *)(long)((int)puVar11 + 4);
                  uVar12 = iVar16 * 2;
                  if (uVar8 == uVar14) {
                    iVar16 = *(int *)(pcVar30 + 0x578);
                    goto LAB_ffffffffbfc247a4;
                  }
                  iVar16 = uVar12 - *puVar11;
                } while (*puVar11 < uVar12);
              }
            }
            iVar16 = *(int *)(pcVar30 + 0x578);
LAB_ffffffffbfc247a4:
            iVar5 = 1 << (uVar20 & 0x1f);
            iVar1 = *(int *)((long)iVar16 + 0x20);
            iVar26 = iVar5 + 1;
            uVar2 = *(undefined4 *)((long)iVar16 + 0x28);
            *(ulong *)(pcVar30 + 0x580) = uVar19;
            *(long *)(pcVar30 + 0x588) = lVar7;
            *(long *)(pcVar30 + 0x590) = (long)((int)lVar21 + 1);
            *(long *)(pcVar30 + 0x598) = lVar22;
            *(ulong *)(pcVar30 + 0x5a0) = uVar23;
            *(long *)(pcVar30 + 0x5a8) = lVar24;
            *(uint **)(pcVar30 + 0x5b0) = puVar25;
            *(int *)(pcVar30 + 0x554) = iVar5;
            piVar13 = (int *)(*(code *)(long)iVar1)(uVar2,iVar26,8);
            uVar19 = *(ulong *)(pcVar30 + 0x580);
            uVar4 = *(undefined8 *)(pcVar30 + 0x588);
            lVar21 = *(long *)(pcVar30 + 0x590);
            lVar22 = *(long *)(pcVar30 + 0x598);
            uVar23 = *(ulong *)(pcVar30 + 0x5a0);
            lVar24 = *(long *)(pcVar30 + 0x5a8);
            puVar25 = *(uint **)(pcVar30 + 0x5b0);
            if (piVar13 == (int *)0x0) {
              if (lVar21 != 0) {
                (*(code *)(long)(DAT_ffffffffbfc43700 + 0x4488))
                          (*(undefined4 *)(pcVar30 + 8),*(undefined4 *)(pcVar30 + 0x578));
                return 0xfffffffffffffffc;
              }
              return 0xfffffffffffffffc;
            }
            *piVar13 = iVar26;
            iVar1 = *(int *)(pcVar30 + 0x574);
            iVar16 = (int)piVar13 + 8;
            *(int *)(pcVar30 + 0x574) = (int)piVar13 + 4;
            *(int *)(long)iVar1 = iVar16;
            piVar13[1] = 0;
            *(int *)(long)iVar33 = iVar16;
            if (lVar21 != 0) {
              *pcVar30 = (char)uVar20;
              pcVar30[1] = (char)uVar27;
              *(int *)(pcVar30 + 4) = iVar16;
              iVar1 = ((int *)(long)iVar33)[-1];
              uVar9 = *(undefined8 *)pcVar30;
              *(uint *)(long)*(int *)(pcVar30 + 0x55c) = uVar15;
              *(undefined8 *)(long)(int)((uVar15 >> ((uint)uVar4 & 0x1f)) * 8 + iVar1) = uVar9;
            }
            iVar10 = iVar10 + iVar28;
            iVar33 = iVar33 + 4;
            uVar17 = uVar17 + (int)lVar24;
            iVar29 = iVar29 + (int)lVar24;
            *(int *)(pcVar30 + 0x55c) = *(int *)(pcVar30 + 0x55c) + 4;
          }
          pcVar30[1] = (char)uVar19 - (char)uVar20;
          if (*(uint *)(pcVar30 + 0x550) < *(uint *)(pcVar30 + 0x560)) {
            iVar10 = *(int *)(pcVar30 + 0x550);
            uVar17 = *(uint *)(long)iVar10;
            if (uVar17 < *(uint *)(pcVar30 + 0x568)) {
              uVar6 = 0x60;
              if (uVar17 < 0x100) {
                uVar6 = 0;
              }
              *(int *)(pcVar30 + 0x550) = iVar10 + 4;
              *(uint *)(pcVar30 + 4) = uVar17;
              goto LAB_ffffffffbfc248f4;
            }
            *(int *)(pcVar30 + 0x550) = iVar10 + 4;
            uVar2 = *(undefined4 *)
                     (long)(int)(*(int *)(pcVar30 + 0x56c) +
                                (uVar17 - *(int *)(pcVar30 + 0x568)) * 4);
            *pcVar30 = (char)*(undefined4 *)
                              (long)(int)(*(int *)(pcVar30 + 0x570) +
                                         (uVar17 - *(int *)(pcVar30 + 0x568)) * 4) + 'P';
            *(undefined4 *)(pcVar30 + 4) = uVar2;
          }
          else {
            uVar6 = 0xc0;
LAB_ffffffffbfc248f4:
            *pcVar30 = uVar6;
          }
          iVar18 = 1 << ((int)uVar19 - uVar20 & 0x1f);
          uVar17 = uVar15 >> (uVar20 & 0x1f);
          iVar10 = iVar16 + uVar17 * 8;
          while( true ) {
            iVar10 = iVar10 + iVar18 * 8;
            bVar3 = *(uint *)(pcVar30 + 0x554) <= uVar17;
            uVar17 = uVar17 + iVar18;
            if (bVar3) break;
            *(undefined8 *)(long)(iVar18 * -8 + iVar10) = *(undefined8 *)pcVar30;
          }
          for (uVar17 = 1 << ((int)uVar19 - 1U & 0x1f); uVar20 = uVar15 & uVar17,
              uVar15 = uVar15 ^ uVar17, uVar20 != 0; uVar17 = uVar17 >> 1) {
          }
          iVar10 = (int)lVar21 * 4 + iVar31 + 0x84;
          while( true ) {
            puVar11 = (uint *)(long)iVar10;
            iVar10 = iVar10 + -4;
            if ((uVar15 & (1 << ((uint)lVar7 & 0x1f)) - 1U) == *puVar11) break;
            lVar21 = (long)((int)lVar21 + -1);
            lVar7 = (long)(int)((uint)lVar7 + (int)lVar24);
          }
        }
        uVar19 = (ulong)((int)uVar19 + 1);
        iVar10 = (int)puVar25 + 4;
        *(int *)(pcVar30 + 0x558) = *(int *)(pcVar30 + 0x558) + 4;
      }
      if ((*(int *)(pcVar30 + 0x564) == 0) || (uVar4 = 0xfffffffffffffffb, uVar23 == 1)) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

