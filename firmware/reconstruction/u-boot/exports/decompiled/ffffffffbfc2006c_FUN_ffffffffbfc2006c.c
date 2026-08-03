/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2006c
 * Function: FUN_ffffffffbfc2006c
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

/* WARNING: Removing unreachable block (ram,0xffffffffbfc20288) */
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

int FUN_ffffffffbfc2006c(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar4;
  ulong uVar3;
  long lVar5;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  uint uVar13;
  long lVar12;
  uint uVar14;
  long lVar15;
  int iVar16;
  int iVar17;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  uint uVar18;
  undefined8 unaff_s7;
  undefined8 *puVar19;
  undefined8 in_ra;
  int iVar6;
  
  puVar19 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar19[8] = &_gp;
  puVar19[9] = in_ra;
  puVar19[7] = unaff_s7;
  puVar19[6] = unaff_s6;
  puVar19[5] = unaff_s5;
  puVar19[4] = unaff_s4;
  puVar19[3] = unaff_s3;
  puVar19[2] = unaff_s2;
  puVar19[1] = unaff_s1;
  *puVar19 = unaff_s0;
  if (param_1 < 0) {
    return 0;
  }
  uVar9 = (int)param_1 + 0xb;
  if ((int)uVar9 < 0x17) {
    uVar18 = 0x10;
LAB_ffffffffbfc200d0:
    lVar2 = (long)(int)(uVar18 + DAT_ffffffffbfc436f4 + 0x32a8);
    iVar16 = *(int *)(lVar2 + 0xc);
    lVar11 = (long)iVar16;
    if ((lVar11 != lVar2) ||
       (lVar2 = (long)(iVar16 + 8), lVar11 = (long)*(int *)(lVar2 + 0xc), lVar11 != lVar2)) {
      iVar16 = *(int *)(lVar11 + 0xc);
      iVar4 = (int)lVar11;
      iVar17 = *(int *)(lVar11 + 8);
      lVar2 = (long)(int)(iVar4 + (*(uint *)(lVar11 + 4) & 0xfffffffc));
      uVar9 = *(uint *)(lVar2 + 4);
      *(int *)((long)iVar16 + 8) = iVar17;
      *(int *)((long)iVar17 + 0xc) = iVar16;
      goto LAB_ffffffffbfc20264;
    }
    uVar9 = (uVar18 >> 3) + 2;
  }
  else {
    uVar18 = uVar9 & 0xfffffff8;
    uVar8 = uVar9 >> 9;
    if (uVar18 < 0x1f8) goto LAB_ffffffffbfc200d0;
    if (uVar8 == 0) {
      uVar9 = uVar9 >> 3;
    }
    else if (uVar8 < 5) {
      uVar9 = (uVar9 >> 6) + 0x38;
    }
    else if (uVar8 < 0x15) {
      uVar9 = uVar8 + 0x5b;
    }
    else if (uVar8 < 0x55) {
      uVar9 = (uVar9 >> 0xc) + 0x6e;
    }
    else if (uVar8 < 0x155) {
      uVar9 = (uVar9 >> 0xf) + 0x77;
    }
    else if (uVar8 < 0x555) {
      uVar9 = (uVar9 >> 0x12) + 0x7c;
    }
    else {
      uVar9 = 0x7e;
    }
    lVar11 = (long)(int)(uVar9 * 8 + DAT_ffffffffbfc436f4 + 0x32a8);
    lVar2 = (long)*(int *)(lVar11 + 0xc);
    while (lVar5 = lVar2, lVar5 != lVar11) {
      uVar8 = *(uint *)(lVar5 + 4) & 0xfffffffc;
      iVar16 = uVar8 - uVar18;
      if (0xf < iVar16) {
        uVar9 = uVar9 - 1;
        break;
      }
      iVar17 = *(int *)(lVar5 + 0xc);
      lVar2 = (long)iVar17;
      if (-1 < iVar16) {
        lVar2 = (long)(int)((int)lVar5 + uVar8);
        uVar9 = *(uint *)(lVar2 + 4);
        iVar16 = *(int *)(lVar5 + 8);
        *(int *)((long)iVar17 + 8) = iVar16;
        *(uint *)(lVar2 + 4) = uVar9 | 1;
        *(int *)((long)iVar16 + 0xc) = iVar17;
        return (int)lVar5 + 8;
      }
    }
    uVar9 = uVar9 + 1;
  }
  iVar17 = DAT_ffffffffbfc436f4 + 0x32a8;
  iVar16 = DAT_ffffffffbfc436f4 + 0x32b0;
  lVar11 = (long)iVar16;
  iVar4 = *(int *)(lVar11 + 8);
  lVar2 = (long)iVar4;
  if (lVar2 != lVar11) {
    uVar8 = *(uint *)(lVar2 + 4);
    uVar13 = uVar8 & 0xfffffffc;
    uVar10 = uVar13 - uVar18;
    iVar6 = iVar4 + uVar18;
    lVar5 = (long)iVar6;
    if (0xf < (int)uVar10) {
      *(uint *)(lVar2 + 4) = uVar18 | 1;
      *(uint *)(long)(int)(iVar6 + uVar10) = uVar10;
      *(int *)(lVar11 + 8) = iVar6;
      *(int *)(lVar11 + 0xc) = iVar6;
      *(uint *)(lVar5 + 4) = uVar10 | 1;
      *(int *)(lVar5 + 8) = iVar16;
LAB_ffffffffbfc20718:
      *(int *)(lVar5 + 0xc) = iVar16;
      return iVar4 + 8;
    }
    *(int *)(lVar11 + 0xc) = iVar16;
    *(int *)(lVar11 + 8) = iVar16;
    if (-1 < (int)uVar10) {
      lVar2 = (long)(int)(iVar4 + uVar13);
      uVar9 = *(uint *)(lVar2 + 4);
LAB_ffffffffbfc20264:
      *(uint *)(lVar2 + 4) = uVar9 | 1;
      return iVar4 + 8;
    }
    uVar10 = uVar8 >> 9;
    if (uVar13 < 0x200) {
      uVar10 = *(uint *)((long)iVar17 + 4);
      iVar7 = (uVar8 >> 3) * 8 + iVar17;
      iVar6 = *(int *)((long)iVar7 + 8);
      *(int *)(lVar2 + 0xc) = iVar7;
      *(int *)(lVar2 + 8) = iVar6;
      *(int *)((long)iVar6 + 0xc) = iVar4;
      *(uint *)((long)iVar17 + 4) = uVar10 | 1 << ((int)(uVar8 >> 3) >> 2 & 0x1fU);
      *(int *)((long)iVar7 + 8) = iVar4;
    }
    else {
      if (uVar10 < 5) {
        iVar6 = (uVar8 >> 6) + 0x38;
      }
      else if (uVar10 < 0x15) {
        iVar6 = uVar10 + 0x5b;
      }
      else if (uVar10 < 0x55) {
        iVar6 = (uVar8 >> 0xc) + 0x6e;
      }
      else if (uVar10 < 0x155) {
        iVar6 = (uVar8 >> 0xf) + 0x77;
      }
      else if (uVar10 < 0x555) {
        iVar6 = (uVar8 >> 0x12) + 0x7c;
      }
      else {
        iVar6 = 0x7e;
      }
      lVar5 = (long)(iVar6 * 8 + iVar17);
      lVar15 = (long)*(int *)(lVar5 + 8);
      if (lVar15 == lVar5) {
        *(uint *)((long)(DAT_ffffffffbfc436f4 + 0x32a8) + 4) =
             *(uint *)((long)(DAT_ffffffffbfc436f4 + 0x32a8) + 4) | 1 << (iVar6 >> 2 & 0x1fU);
        lVar5 = lVar15;
      }
      else {
        do {
          if ((*(uint *)(lVar15 + 4) & 0xfffffffc) <= uVar13) break;
          lVar15 = (long)*(int *)(lVar15 + 8);
        } while (lVar15 != lVar5);
        lVar5 = (long)*(int *)(lVar15 + 0xc);
      }
      *(int *)(lVar2 + 0xc) = (int)lVar5;
      *(int *)(lVar2 + 8) = (int)lVar15;
      *(int *)(lVar15 + 0xc) = iVar4;
      *(int *)(lVar5 + 8) = iVar4;
    }
  }
  uVar8 = uVar9;
  if ((int)uVar9 < 0) {
    uVar8 = uVar9 + 3;
  }
  lVar2 = (long)(DAT_ffffffffbfc436f4 + 0x32a8);
  uVar10 = 1 << ((int)uVar8 >> 2 & 0x1fU);
  uVar8 = *(uint *)(lVar2 + 4);
  if (uVar10 <= uVar8) {
    iVar4 = uVar9 << 3;
    if ((uVar10 & uVar8) == 0) {
      uVar9 = uVar9 & 0xfffffffc;
      do {
        uVar9 = uVar9 + 4;
        uVar10 = uVar10 << 1;
      } while ((uVar10 & uVar8) == 0);
      iVar4 = uVar9 * 8;
    }
    do {
      lVar15 = (long)(iVar4 + iVar17);
      lVar5 = lVar15;
      uVar8 = uVar9;
      do {
        lVar1 = (long)*(int *)(lVar5 + 0xc);
        while (lVar12 = lVar1, iVar4 = (int)lVar12, lVar12 != lVar5) {
          uVar13 = *(uint *)(lVar12 + 4) & 0xfffffffc;
          uVar14 = uVar13 - uVar18;
          if (0xf < (int)uVar14) {
            iVar7 = iVar4 + uVar18;
            lVar5 = (long)iVar7;
            iVar17 = *(int *)(lVar12 + 8);
            iVar6 = *(int *)(lVar12 + 0xc);
            *(uint *)(lVar12 + 4) = uVar18 | 1;
            *(uint *)(long)(int)(iVar7 + uVar14) = uVar14;
            *(int *)((long)iVar6 + 8) = iVar17;
            *(int *)((long)iVar17 + 0xc) = iVar6;
            *(int *)(lVar11 + 8) = iVar7;
            *(uint *)(lVar5 + 4) = uVar14 | 1;
            *(int *)(lVar5 + 8) = iVar16;
            *(int *)(lVar11 + 0xc) = iVar7;
            goto LAB_ffffffffbfc20718;
          }
          iVar6 = *(int *)(lVar12 + 0xc);
          lVar1 = (long)iVar6;
          if (-1 < (int)uVar14) {
            lVar2 = (long)(int)(iVar4 + uVar13);
            iVar16 = *(int *)(lVar12 + 8);
            *(uint *)(lVar2 + 4) = *(uint *)(lVar2 + 4) | 1;
            *(int *)((long)iVar6 + 8) = iVar16;
            *(int *)((long)iVar16 + 0xc) = iVar6;
            return iVar4 + 8;
          }
        }
        uVar8 = uVar8 + 1;
        lVar5 = (long)(iVar4 + 8);
      } while ((uVar8 & 3) != 0);
      do {
        lVar15 = (long)((int)lVar15 + -8);
        if ((uVar9 & 3) == 0) {
          *(uint *)(lVar2 + 4) = *(uint *)(lVar2 + 4) & ~uVar10;
          break;
        }
        uVar9 = uVar9 - 1;
      } while (*(int *)(lVar15 + 8) == lVar15);
      uVar10 = uVar10 << 1;
      if (*(uint *)(lVar2 + 4) < uVar10) break;
      uVar9 = uVar8;
      if (uVar10 == 0) goto code_r0xffffffffbfc2048c;
      for (; (uVar10 & *(uint *)(lVar2 + 4)) == 0; uVar10 = uVar10 << 1) {
        uVar9 = uVar9 + 4;
      }
      iVar4 = uVar9 << 3;
    } while( true );
  }
  iVar16 = *(int *)(lVar2 + 8);
LAB_ffffffffbfc204c8:
  lVar11 = (long)iVar16;
  uVar8 = *(uint *)(lVar11 + 4) & 0xfffffffc;
  uVar9 = uVar8 - uVar18;
  if (0xf < (int)uVar9) goto LAB_ffffffffbfc20694;
  lVar5 = (long)DAT_ffffffffbfc436f4;
  uVar9 = uVar18 + *(int *)((long)DAT_ffffffffbfc436f4 + 0x4f60) + 0x10;
  if (*(int *)(lVar5 + 0x2918) != -1) {
    uVar9 = uVar9 + 0xfff & 0xfffff000;
  }
  uVar3 = (*(code *)(long)DAT_ffffffffbfc43a80)(uVar9);
  if (uVar3 != 0xffffffffffffffff) {
    iVar17 = iVar16 + uVar8;
    lVar15 = (long)DAT_ffffffffbfc436f4;
    if (((ulong)(long)iVar17 <= uVar3) || (lVar11 == lVar2)) {
      iVar4 = uVar9 + *(int *)(lVar15 + 0x4f68);
      *(int *)(lVar15 + 0x4f68) = iVar4;
      if (uVar3 == (long)iVar17) {
        *(uint *)((long)*(int *)(lVar2 + 8) + 4) = uVar9 + uVar8 | 1;
      }
      else {
        iVar6 = (int)uVar3;
        if (*(int *)(lVar5 + 0x2918) == -1) {
          *(int *)(lVar5 + 0x2918) = iVar6;
        }
        else {
          *(int *)(lVar15 + 0x4f68) = iVar4 + (iVar6 - iVar17);
        }
        if ((uVar3 & 7) == 0) {
          iVar17 = 0;
        }
        else {
          iVar17 = 8 - (int)(uVar3 & 7);
          uVar3 = (ulong)(iVar6 + iVar17);
        }
        iVar4 = (int)uVar3;
        iVar17 = iVar17 + ((iVar4 + uVar9 + 0xfff & 0xfffff000) - (iVar4 + uVar9));
        lVar5 = (*(code *)(long)DAT_ffffffffbfc43a80)(iVar17);
        lVar15 = (long)DAT_ffffffffbfc436f4;
        if (lVar5 == -1) goto LAB_ffffffffbfc20674;
        *(int *)(lVar2 + 8) = iVar4;
        *(int *)(lVar15 + 0x4f68) = *(int *)(lVar15 + 0x4f68) + iVar17;
        *(uint *)(uVar3 + 4) = ((int)lVar5 - iVar4) + iVar17 | 1;
        if (lVar11 != lVar2) {
          if (uVar8 < 0x10) {
            *(undefined4 *)(uVar3 + 4) = 1;
            goto LAB_ffffffffbfc20674;
          }
          uVar9 = uVar8 - 0xc & 0xfffffff8;
          *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) & 1 | uVar9;
          *(undefined4 *)((long)(int)(iVar16 + uVar9) + 8) = 5;
          *(undefined4 *)((long)(int)(iVar16 + uVar9) + 4) = 5;
          if (0xf < uVar9) {
            (*(code *)(long)DAT_ffffffffbfc43734)(iVar16 + 8);
          }
        }
      }
      lVar11 = (long)DAT_ffffffffbfc436f4;
      uVar9 = *(uint *)((long)DAT_ffffffffbfc436f4 + 0x4f90);
      uVar8 = *(uint *)((long)DAT_ffffffffbfc436f4 + 0x4f68);
      uVar10 = *(uint *)(lVar11 + 0x4f94);
      if (uVar9 < uVar8) {
        uVar9 = uVar8;
      }
      if (uVar10 < uVar8) {
        uVar10 = uVar8;
      }
      *(uint *)((long)DAT_ffffffffbfc436f4 + 0x4f90) = uVar9;
      *(uint *)(lVar11 + 0x4f94) = uVar10;
    }
  }
LAB_ffffffffbfc20674:
  uVar9 = (*(uint *)((long)*(int *)(lVar2 + 8) + 4) & 0xfffffffc) - uVar18;
  if ((int)uVar9 < 0x10) {
    return 0;
  }
LAB_ffffffffbfc20694:
  iVar16 = *(int *)(lVar2 + 8);
  *(uint *)((long)iVar16 + 4) = uVar18 | 1;
  *(uint *)((long)(int)(iVar16 + uVar18) + 4) = uVar9 | 1;
  *(uint *)(lVar2 + 8) = iVar16 + uVar18;
  return iVar16 + 8;
code_r0xffffffffbfc2048c:
  iVar16 = *(int *)(lVar2 + 8);
  goto LAB_ffffffffbfc204c8;
}

