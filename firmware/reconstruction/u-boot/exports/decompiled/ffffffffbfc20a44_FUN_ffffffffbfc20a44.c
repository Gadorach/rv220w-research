/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc20a44
 * Function: FUN_ffffffffbfc20a44
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

int * FUN_ffffffffbfc20a44(int *param_1,long param_2)

{
  undefined4 uVar1;
  undefined8 in_zero;
  int iVar2;
  int iVar6;
  ulong uVar3;
  long lVar4;
  int *piVar5;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined8 unaff_s0;
  int *piVar10;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  ulong uVar12;
  int iVar13;
  undefined8 unaff_s3;
  int *piVar14;
  undefined8 unaff_s4;
  int iVar16;
  uint uVar17;
  undefined8 unaff_s5;
  uint uVar18;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  long lVar19;
  code *pcVar20;
  undefined8 *puVar21;
  undefined8 in_ra;
  int iVar11;
  int iVar15;
  
  puVar21 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar21[8] = &_gp;
  puVar21[1] = unaff_s1;
  puVar21[9] = in_ra;
  puVar21[7] = unaff_s7;
  puVar21[6] = unaff_s6;
  puVar21[5] = unaff_s5;
  puVar21[4] = unaff_s4;
  puVar21[3] = unaff_s3;
  puVar21[2] = unaff_s2;
  *puVar21 = unaff_s0;
  if (param_2 < 0) {
    return (int *)0x0;
  }
  iVar6 = (int)param_1;
  iVar15 = iVar6 + -8;
  piVar14 = (int *)(long)iVar15;
  if (param_1 == (int *)0x0) {
    piVar14 = (int *)(*(code *)(long)DAT_ffffffffbfc43e1c)(param_2);
    return piVar14;
  }
  uVar3 = (ulong)((int)param_2 + 0xb);
  uVar12 = (long)piVar14[1] & 0xfffffffffffffffc;
  if ((long)uVar3 < 0x17) {
    uVar3 = 0x10;
  }
  else {
    uVar3 = uVar3 & 0xfffffffffffffff8;
  }
  uVar18 = (uint)uVar3;
  if ((long)uVar12 < (long)uVar3) {
    iVar13 = (int)uVar12;
    lVar4 = (long)(iVar15 + iVar13);
    lVar19 = (long)(DAT_ffffffffbfc436f4 + 0x32a8);
    iVar16 = *(int *)(lVar19 + 8);
    if (lVar4 == iVar16) {
      uVar9 = *(uint *)(lVar4 + 4) & 0xfffffffc;
      if ((int)(uVar18 + 0x10) <= (int)(uVar9 + iVar13)) {
        *(uint *)((long)(int)(iVar15 + uVar18) + 4) = (uVar9 + iVar13) - uVar18 | 1;
        uVar9 = piVar14[1];
        *(uint *)(lVar19 + 8) = iVar15 + uVar18;
        piVar14[1] = uVar9 & 1 | uVar18;
        return (int *)(long)iVar6;
      }
    }
    else {
      setCopReg(2,in_zero,
                *(undefined4 *)
                 ((long)*(int *)((long)(int)(iVar15 + iVar13 + (*(uint *)(lVar4 + 4) & 0xfffffffe))
                                + 4) + 0xfb));
      lVar4 = 0;
      uVar9 = 0;
    }
    uVar1 = getCopReg(2,0);
    *(undefined4 *)((long)piVar14[1] + 0x87) = uVar1;
    iVar11 = iVar15 - *piVar14;
    piVar10 = (int *)(long)iVar11;
    if (lVar4 == 0) {
LAB_ffffffffbfc20cec:
      uVar12 = (ulong)(int)((piVar10[1] & 0xfffffffcU) + iVar13);
      if ((long)uVar12 < (long)uVar3) {
        piVar10 = (int *)(*(code *)(long)DAT_ffffffffbfc43e1c)(param_2);
        if (piVar10 == (int *)0x0) {
          return (int *)0x0;
        }
        iVar16 = (int)piVar10;
        uVar9 = iVar13 - 4;
        if ((long)(iVar16 + -8) != (long)(int)(iVar15 + (piVar14[1] & 0xfffffffeU))) {
          if (uVar9 < 0x25) {
            piVar14 = param_1;
            piVar5 = piVar10;
            if (0x13 < uVar9) {
              piVar5 = (int *)(long)(iVar16 + 8);
              piVar14 = (int *)(long)(iVar6 + 8);
              *piVar10 = *param_1;
              piVar10[1] = param_1[1];
              if (0x1b < uVar9) {
                piVar5 = (int *)(long)(iVar16 + 0x10);
                piVar10[2] = param_1[2];
                piVar10[3] = param_1[3];
                piVar14 = (int *)(long)(iVar6 + 0x10);
                if (uVar9 == 0x24) {
                  piVar5 = (int *)(long)(iVar16 + 0x18);
                  piVar14 = (int *)(long)(iVar6 + 0x18);
                  piVar10[4] = param_1[4];
                  piVar10[5] = param_1[5];
                }
              }
            }
            *piVar5 = *piVar14;
            piVar5[1] = piVar14[1];
            piVar5[2] = piVar14[2];
          }
          else {
            (*(code *)(long)DAT_ffffffffbfc43e84)(piVar10,param_1);
          }
          (*(code *)(long)DAT_ffffffffbfc43734)(param_1);
          return piVar10;
        }
        uVar12 = (ulong)(int)(iVar13 + (*(uint *)((long)(iVar16 + -8) + 4) & 0xfffffffc));
        goto LAB_ffffffffbfc20eac;
      }
      iVar15 = piVar10[3];
      iVar16 = piVar10[2];
      *(int *)((long)iVar15 + 8) = iVar16;
      *(int *)((long)iVar16 + 0xc) = iVar15;
    }
    else {
      iVar2 = iVar13 + (piVar10[1] & 0xfffffffcU);
      if (lVar4 == iVar16) {
        iVar2 = uVar9 + iVar2;
        if ((int)(uVar18 + 0x10) <= iVar2) {
          iVar15 = piVar10[3];
          uVar9 = iVar13 - 4;
          iVar16 = piVar10[2];
          piVar14 = (int *)(long)(iVar11 + 8);
          *(int *)((long)iVar15 + 8) = iVar16;
          *(int *)((long)iVar16 + 0xc) = iVar15;
          if (uVar9 < 0x25) {
            piVar5 = param_1;
            piVar7 = piVar14;
            if (0x13 < uVar9) {
              piVar7 = (int *)(long)(iVar11 + 0x10);
              piVar5 = (int *)(long)(iVar6 + 8);
              piVar10[2] = *param_1;
              piVar10[3] = param_1[1];
              if (0x1b < uVar9) {
                piVar7 = (int *)(long)(iVar11 + 0x18);
                piVar10[4] = param_1[2];
                piVar10[5] = param_1[3];
                piVar5 = (int *)(long)(iVar6 + 0x10);
                if (uVar9 == 0x24) {
                  piVar5 = (int *)(long)(iVar6 + 0x18);
                  piVar7 = (int *)(long)(iVar11 + 0x20);
                  piVar10[6] = param_1[4];
                  piVar10[7] = param_1[5];
                }
              }
            }
            *piVar7 = *piVar5;
            piVar7[1] = piVar5[1];
            piVar7[2] = piVar5[2];
          }
          else {
            (*(code *)(long)DAT_ffffffffbfc43e84)(piVar14,param_1);
          }
          *(uint *)(lVar19 + 8) = iVar11 + uVar18;
          *(uint *)((long)(int)(iVar11 + uVar18) + 4) = iVar2 - uVar18 | 1;
          piVar10[1] = piVar10[1] & 1U | uVar18;
          return piVar14;
        }
        goto LAB_ffffffffbfc20cec;
      }
      uVar12 = (ulong)(int)(uVar9 + iVar2);
      if ((long)uVar12 < (long)uVar3) goto LAB_ffffffffbfc20cec;
      iVar15 = *(int *)(lVar4 + 8);
      iVar16 = *(int *)(lVar4 + 0xc);
      *(int *)((long)iVar16 + 8) = iVar15;
      *(int *)((long)iVar15 + 0xc) = iVar16;
      iVar15 = piVar10[3];
      iVar16 = piVar10[2];
      *(int *)((long)iVar15 + 8) = iVar16;
      *(int *)((long)iVar16 + 0xc) = iVar15;
    }
    uVar9 = iVar13 - 4;
    uVar17 = (uint)uVar12;
    piVar14 = (int *)(long)(iVar11 + 8);
    if (0x24 < uVar9) {
      (*(code *)(long)DAT_ffffffffbfc43e84)(piVar14,param_1);
      uVar9 = piVar10[1];
      goto LAB_ffffffffbfc20eb0;
    }
    piVar5 = param_1;
    if (0x13 < uVar9) {
      piVar14 = (int *)(long)(iVar11 + 0x10);
      piVar5 = (int *)(long)(iVar6 + 8);
      piVar10[2] = *param_1;
      piVar10[3] = param_1[1];
      if (0x1b < uVar9) {
        piVar14 = (int *)(long)(iVar11 + 0x18);
        piVar10[4] = param_1[2];
        piVar10[5] = param_1[3];
        piVar5 = (int *)(long)(iVar6 + 0x10);
        if (uVar9 == 0x24) {
          piVar5 = (int *)(long)(iVar6 + 0x18);
          piVar14 = (int *)(long)(iVar11 + 0x20);
          piVar10[6] = param_1[4];
          piVar10[7] = param_1[5];
        }
      }
    }
    *piVar14 = *piVar5;
    piVar14[1] = piVar5[1];
    piVar14[2] = piVar5[2];
    piVar14 = piVar10;
  }
LAB_ffffffffbfc20eac:
  uVar17 = (uint)uVar12;
  uVar9 = piVar14[1];
  piVar10 = piVar14;
LAB_ffffffffbfc20eb0:
  uVar8 = uVar17 - uVar18;
  iVar6 = (int)piVar10;
  if (uVar8 < 0x10) {
    piVar10[1] = uVar9 & 1 | uVar17;
    *(uint *)((long)(int)(iVar6 + uVar17) + 4) = *(uint *)((long)(int)(iVar6 + uVar17) + 4) | 1;
  }
  else {
    iVar15 = iVar6 + uVar18;
    piVar10[1] = uVar9 & 1 | uVar18;
    *(uint *)((long)iVar15 + 4) = uVar8 | 1;
    pcVar20 = (code *)(long)DAT_ffffffffbfc43734;
    *(uint *)((long)(int)(iVar15 + uVar8) + 4) = *(uint *)((long)(int)(iVar15 + uVar8) + 4) | 1;
    (*pcVar20)(iVar15 + 8);
  }
  return (int *)(long)(iVar6 + 8);
}

