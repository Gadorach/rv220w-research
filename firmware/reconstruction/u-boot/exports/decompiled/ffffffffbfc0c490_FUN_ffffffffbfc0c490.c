/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0c490
 * Function: FUN_ffffffffbfc0c490
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

void FUN_ffffffffbfc0c490(long param_1,long param_2)

{
  ushort uVar1;
  int *piVar2;
  long lVar3;
  ushort uVar6;
  int iVar4;
  int iVar5;
  uint uVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined2 uVar10;
  ushort uVar12;
  int iVar11;
  ushort uVar13;
  ushort uVar14;
  undefined8 unaff_s0;
  byte *pbVar15;
  undefined4 *puVar16;
  undefined8 unaff_s1;
  undefined4 *puVar17;
  undefined8 unaff_s2;
  int *piVar18;
  undefined8 unaff_s3;
  int iVar19;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  int iVar20;
  code *pcVar21;
  undefined8 *puVar22;
  undefined8 in_ra;
  
  puVar22 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar22[7] = &_gp;
  puVar22[2] = unaff_s2;
  piVar2 = (int *)(long)DAT_ffffffffbfc43ad4;
  puVar22[8] = in_ra;
  iVar4 = (int)param_1;
  *piVar2 = iVar4;
  piVar2 = (int *)(long)DAT_ffffffffbfc4391c;
  puVar22[6] = unaff_s6;
  puVar22[5] = unaff_s5;
  puVar22[4] = unaff_s4;
  puVar22[3] = unaff_s3;
  puVar22[1] = unaff_s1;
  *puVar22 = unaff_s0;
  iVar5 = (int)param_2;
  *piVar2 = iVar5;
  if (param_2 < 0xe) {
    return;
  }
  uVar13 = 0xfff;
  uVar6 = *(ushort *)(param_1 + 0xc);
  uVar1 = *(ushort *)(long)DAT_ffffffffbfc43830;
  uVar12 = *(ushort *)(long)DAT_ffffffffbfc43dc4;
  uVar14 = 0xfff;
  if (uVar1 != 0xffff) {
    uVar14 = uVar1;
  }
  if (uVar12 == 0xffff) {
    uVar12 = 0xfff;
  }
  if (uVar6 < 0x5ea) {
    uVar6 = *(ushort *)(param_1 + 0x14);
    uVar7 = iVar5 - 0x16;
    pbVar15 = (byte *)(long)(iVar4 + 0x16);
  }
  else {
    pbVar15 = (byte *)(long)(iVar4 + 0xe);
    if (uVar6 == 0x8100) {
      if (param_2 < 0x12) {
        return;
      }
      uVar7 = iVar5 - 0x12;
      if ((uVar1 & 0xfff) == 0xfff) {
        return;
      }
      uVar6 = *(ushort *)(param_1 + 0x10);
      pbVar15 = (byte *)(long)(iVar4 + 0x12);
      uVar13 = *(ushort *)(param_1 + 0xe) & 0xfff;
    }
    else {
      uVar7 = iVar5 - 0xe;
      uVar13 = 0xfff;
    }
  }
  if ((uVar14 & 0xfff) != 0xfff) {
    if (uVar13 == 0xfff) {
      uVar13 = uVar12 & 0xfff;
    }
    if (uVar13 != (uVar14 & 0xfff)) {
      return;
    }
  }
  iVar5 = (int)pbVar15;
  if (uVar6 == 0x806) {
    if (0x1b < (int)uVar7) {
      if (*(short *)pbVar15 != 1) {
        return;
      }
      if (*(short *)(pbVar15 + 2) != 0x800) {
        return;
      }
      if (pbVar15[4] != 6) {
        return;
      }
      piVar2 = (int *)(long)DAT_ffffffffbfc43f80;
      if (pbVar15[5] != 4) {
        return;
      }
      if (*piVar2 == 0) {
        return;
      }
      iVar20 = DAT_ffffffffbfc436fc + -0x3d18;
      iVar19 = iVar5 + 8;
      iVar11 = (*(code *)(long)iVar20)(iVar5 + 0x18);
      if (iVar11 != *piVar2) {
        return;
      }
      if (*(short *)(pbVar15 + 6) == 1) {
        iVar4 = (*(code *)(long)DAT_ffffffffbfc43cf8)(param_1,iVar4 + 6,0x806);
        pcVar21 = (code *)(long)DAT_ffffffffbfc43e84;
        pbVar15[6] = 0;
        pbVar15[7] = 2;
        (*pcVar21)(iVar5 + 0x12,iVar19,6);
        iVar11 = DAT_ffffffffbfc436fc + -0x3e90;
        (*(code *)(long)iVar11)(iVar5 + 0x18,iVar5 + 0xe);
        (*(code *)(long)DAT_ffffffffbfc43e84)(iVar19,DAT_ffffffffbfc43fa8,6);
        (*(code *)(long)iVar11)(iVar5 + 0xe,piVar2);
        (*(code *)(long)DAT_ffffffffbfc4376c)(param_1,iVar4 + 0x1c);
        return;
      }
      piVar2 = (int *)(long)DAT_ffffffffbfc43dcc;
      if (*(short *)(pbVar15 + 6) != 2) {
        return;
      }
      if ((*piVar2 != 0) && (piVar18 = (int *)(long)DAT_ffffffffbfc44010, *piVar18 != 0)) {
        iVar4 = (*(code *)(long)iVar20)(iVar5 + 0xe);
        if (iVar4 != *(int *)(long)DAT_ffffffffbfc43e5c) {
          return;
        }
        puVar17 = (undefined4 *)(long)DAT_ffffffffbfc43e40;
        (*(code *)(long)DAT_ffffffffbfc43e84)(*piVar18,iVar19,6);
        puVar16 = (undefined4 *)(long)DAT_ffffffffbfc43e74;
        (*(code *)(long)DAT_ffffffffbfc43e84)(*puVar17,*piVar18,6);
        (*(code *)(long)DAT_ffffffffbfc4376c)(*puVar17,*puVar16);
        *piVar2 = 0;
        *puVar16 = 0;
        *piVar18 = 0;
        return;
      }
LAB_ffffffffbfc0c7b4:
      iVar4 = DAT_ffffffffbfc436f4 + -0x5e68;
LAB_ffffffffbfc0c8ac:
      (*(code *)(long)DAT_ffffffffbfc43e38)(iVar4);
      return;
    }
  }
  else {
    if (uVar6 != 0x8035) {
      if ((uVar6 != 0x800) || (uVar7 < 0x1c)) {
        return;
      }
      uVar9 = (uint)*(ushort *)(pbVar15 + 2);
      if ((int)uVar9 <= (int)uVar7) {
        if ((*pbVar15 & 0xf0) != 0x40) {
          return;
        }
        if ((*(ushort *)(pbVar15 + 6) & 0x1fff) != 0) {
          return;
        }
        lVar3 = (*(code *)(long)DAT_ffffffffbfc44024)(pbVar15,10);
        if (lVar3 != 0) {
          iVar4 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x3d18))(iVar5 + 0x10);
          if (((*(int *)(long)DAT_ffffffffbfc43f80 != 0) &&
              (iVar4 != *(int *)(long)DAT_ffffffffbfc43f80)) && (iVar4 != -1)) {
            return;
          }
          if (pbVar15[9] == 1) {
            if (pbVar15[0x14] != 5) {
              return;
            }
            if (*(char *)((long)(iVar5 + 0x14) + 1) != '\x01') {
              return;
            }
            (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5e28);
            (*(code *)(long)DAT_ffffffffbfc43d68)(*(undefined4 *)((long)(iVar5 + 0x14) + 4));
            (*(code *)(long)DAT_ffffffffbfc439f0)(0x20);
          }
          else if (pbVar15[9] != 0x11) {
            return;
          }
          iVar5 = iVar5 + 0x1c;
          iVar4 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a18);
          uVar10 = *(undefined2 *)(pbVar15 + 0x14);
          iVar11 = *(ushort *)(pbVar15 + 0x18) - 8;
          uVar8 = *(undefined2 *)(pbVar15 + 0x16);
LAB_ffffffffbfc0c98c:
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc0c9b0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(long)iVar4)(iVar5,uVar8,uVar10,iVar11);
          return;
        }
        iVar4 = DAT_ffffffffbfc436f4 + -0x5e38;
        goto LAB_ffffffffbfc0c8ac;
      }
      iVar4 = DAT_ffffffffbfc436f4 + -0x5e50;
      goto LAB_ffffffffbfc0c840;
    }
    if (0x1b < (int)uVar7) {
      if (*(short *)(pbVar15 + 6) == 4) {
        iVar4 = DAT_ffffffffbfc436f4 + -0x5e68;
        if (*(short *)pbVar15 != 1) goto LAB_ffffffffbfc0c8ac;
        if ((*(short *)(pbVar15 + 2) == 0x800) && (*(short *)(pbVar15 + 4) == 0x604)) {
          iVar4 = DAT_ffffffffbfc436fc + -0x3e90;
          (*(code *)(long)iVar4)(DAT_ffffffffbfc43f80,iVar5 + 0x18);
          if (*(int *)(long)DAT_ffffffffbfc43f00 == 0) {
            (*(code *)(long)iVar4)((int *)(long)DAT_ffffffffbfc43f00,iVar5 + 0xe);
          }
          (*(code *)(long)DAT_ffffffffbfc43e84)(DAT_ffffffffbfc43ce0,iVar5 + 8,6);
          iVar5 = 0;
          uVar8 = 0;
          uVar10 = 0;
          iVar11 = 0;
          iVar4 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a18);
          goto LAB_ffffffffbfc0c98c;
        }
      }
      goto LAB_ffffffffbfc0c7b4;
    }
  }
  uVar9 = 0x1c;
  iVar4 = DAT_ffffffffbfc436f4 + -0x5e80;
LAB_ffffffffbfc0c840:
  (*(code *)(long)DAT_ffffffffbfc4400c)(iVar4,uVar7,uVar9);
  return;
}

