/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc5261c
 * Function: FUN_ffffffffbfc5261c
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void FUN_ffffffffbfc5261c(long param_1,undefined8 param_2,long param_3)

{
  char *pcVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  char *pcVar6;
  int iVar10;
  long lVar7;
  long lVar8;
  int *piVar9;
  undefined8 uVar11;
  undefined8 unaff_s0;
  uint uVar12;
  undefined8 unaff_s1;
  long lVar13;
  int iVar14;
  int iVar15;
  undefined8 unaff_s2;
  long lVar16;
  int iVar17;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  int iVar18;
  undefined8 unaff_s7;
  undefined4 *puVar19;
  code *pcVar20;
  int *piVar21;
  undefined8 in_ra;
  
  iVar14 = (int)&stack0x00000000;
  piVar21 = (int *)(long)(iVar14 + -0x1060);
  *(undefined1 **)(piVar21 + 0x414) = &_gp;
  uVar2 = *(undefined2 *)(param_3 + 0x1a);
  *(undefined8 *)(piVar21 + 0x408) = unaff_s2;
  puVar5 = (undefined2 *)(long)iRamffffffffbfc55cc8;
  lVar16 = (long)iRamffffffffbfc55c28;
  *(undefined8 *)(piVar21 + 0x410) = unaff_s6;
  iVar18 = (int)param_1 + 0x36;
  *(undefined8 *)(piVar21 + 0x406) = unaff_s1;
  lVar13 = (long)((int)param_1 + 0xe);
  *puVar5 = uVar2;
  iVar10 = *(int *)(lVar16 + 0x5e48);
  puVar5 = (undefined2 *)(long)iRamffffffffbfc55c60;
  *(undefined8 *)(piVar21 + 0x40e) = unaff_s5;
  *(undefined8 *)(piVar21 + 0x416) = in_ra;
  *(undefined8 *)(piVar21 + 0x412) = unaff_s7;
  *(undefined8 *)(piVar21 + 0x40c) = unaff_s4;
  *(undefined8 *)(piVar21 + 0x40a) = unaff_s3;
  *(undefined8 *)(piVar21 + 0x404) = unaff_s0;
  *puVar5 = uVar2;
  *piVar21 = iVar18;
  if (iVar10 == 0) {
    lVar7 = (*(code *)(long)iRamffffffffbfc55d88)(piVar21);
    if (lVar7 == 0) {
      return;
    }
    lVar8 = (*(code *)(long)iRamffffffffbfc55d88)(piVar21);
    if (lVar8 == 0) {
      return;
    }
    lVar8 = (*(code *)(long)iRamffffffffbfc55da8)(lVar7,iRamffffffffbfc55c28 + 0x5588);
    if (lVar8 == 0) {
      iVar15 = iVar14 + -0xa1c;
      pcVar20 = (code *)(long)iRamffffffffbfc55c7c;
      iVar17 = iVar14 + -0x105c;
      *(uint *)(param_3 + 0x20) = *(int *)(param_3 + 0x24) + (uint)*(ushort *)(param_3 + 0x1c);
      (*pcVar20)(param_3);
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                         (iVar14 + -0x9e6,iRamffffffffbfc55c28 + 0x4ca8,
                          iRamffffffffbfc55c28 + 0x4cb8,200,iRamffffffffbfc55c28 + 0x4cc8);
      iVar18 = (*(code *)(long)iRamffffffffbfc55c9c)
                         (iVar15 + iVar10 + 0x36,iRamffffffffbfc55c28 + 0x4cd0);
      iVar18 = iVar10 + 0x36 + iVar18;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4cf0);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4d38);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5590);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4d80);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4dc8);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x55a0);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x55c8);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x55e0);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5600);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5630);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5678);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5690);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x56a8);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x56f8);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5708);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5718);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5728);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5790);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5800);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5888);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x58e8);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5958);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5988);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5998);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x59a0);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x59b8);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5a10);
      iVar18 = iVar18 + iVar10;
      iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5a58);
      uVar12 = iVar18 + iVar10;
      uVar12 = uVar12 + (uVar12 & 1);
      if (uVar12 < 0x44d) {
        (*(code *)(long)iRamffffffffbfc55d98)(iVar17,iVar15,uVar12);
        uVar11 = 0x18;
      }
      else {
        (*(code *)(long)iRamffffffffbfc55d98)(iVar17,iVar15,0x44c);
        (*(code *)(long)iRamffffffffbfc55d04)(param_3,iVar17,0x44c,0x18,0);
        pcVar20 = (code *)(long)iRamffffffffbfc55cc0;
        *(int *)(param_3 + 0x24) = *(int *)(param_3 + 0x24) + 0x416;
        (*pcVar20)(iVar17,0,0x640);
        (*(code *)(long)iRamffffffffbfc55d98)(iVar14 + -0x1026,iVar14 + -0x5d0,uVar12 - 0x44c);
        uVar12 = uVar12 - 0x416;
        uVar11 = 0x11;
      }
      (*(code *)(long)iRamffffffffbfc55d04)(param_3,iVar17,uVar12,uVar11,0);
      return;
    }
    lVar7 = (*(code *)(long)iRamffffffffbfc55da8)(lVar7,iRamffffffffbfc55c28 + 0x5a88);
    iVar10 = iRamffffffffbfc55c28;
    if (lVar7 != 0) {
      return;
    }
    puVar19 = (undefined4 *)(long)iRamffffffffbfc55cac;
    (*(code *)(long)iRamffffffffbfc55d98)
              (iRamffffffffbfc55c28 + 0x5e58,iVar18 + (*piVar21 - iVar18),
               ((uint)*(ushort *)(lVar13 + 2) - (*piVar21 - iVar18)) + -0x28);
    lVar7 = (*(code *)(long)iRamffffffffbfc55d20)(iVar10 + 0x5e58,iRamffffffffbfc55c28 + 0x5a90);
    pcVar20 = (code *)(long)iRamffffffffbfc55c7c;
    uVar3 = *(ushort *)(param_3 + 0x1c);
    if (lVar7 == 0) {
      uVar4 = *(undefined4 *)(param_3 + 0x20);
      iVar14 = *(int *)(param_3 + 0x24);
      *(undefined4 *)(long)iRamffffffffbfc55c88 = uVar4;
      piVar9 = (int *)(long)iRamffffffffbfc55d64;
      *(undefined4 *)(lVar16 + 0x5e48) = 1;
      *piVar9 = iVar14;
      *(uint *)(param_3 + 0x20) = iVar14 + (uint)uVar3;
      *(undefined4 *)(param_3 + 0x24) = uVar4;
      (*pcVar20)(param_3);
      iVar14 = *piVar21;
      lVar16 = (long)iRamffffffffbfc55c28;
      iVar15 = *(int *)(lVar16 + 0x5e54);
      pcVar20 = (code *)(long)iRamffffffffbfc55d98;
      iVar17 = ((uint)*(ushort *)(lVar13 + 2) - (iVar14 - iVar18)) + -0x28;
      *puVar19 = 1;
      (*pcVar20)(iVar15 + iVar10 + 0x5e58,0,iVar17);
      (*(code *)(long)iRamffffffffbfc55d98)
                (*(int *)(lVar16 + 0x5e54) + iVar10 + 0x5e58,iVar18 + (iVar14 - iVar18),iVar17);
      *(int *)(lVar16 + 0x5e54) = *(int *)(lVar16 + 0x5e54) + iVar17;
      return;
    }
    iVar14 = *(int *)(param_3 + 0x20);
    *(undefined4 *)(lVar16 + 0x5e48) = 1;
    *(int *)(param_3 + 0x24) = iVar14;
    *(uint *)(param_3 + 0x20) = iVar14 + (uint)uVar3;
    (*pcVar20)(param_3);
    lVar16 = (long)iRamffffffffbfc55c28;
    *puVar19 = 1;
    if (*(char *)(lVar16 + 0x5bbc) == '\0') {
      return;
    }
    iVar10 = iVar10 + 0x5e58;
    iVar14 = *piVar21;
    lVar16 = (long)iRamffffffffbfc55c28;
    iVar15 = ((uint)*(ushort *)(lVar13 + 2) - (iVar14 - iVar18)) + -0x28;
    (*(code *)(long)iRamffffffffbfc55d98)(*(int *)(lVar16 + 0x5e54) + iVar10,0,iVar15);
    (*(code *)(long)iRamffffffffbfc55d98)
              (*(int *)(lVar16 + 0x5e54) + iVar10,iVar18 + (iVar14 - iVar18),iVar15);
    iVar18 = iRamffffffffbfc55c28;
    pcVar20 = (code *)(long)iRamffffffffbfc55dd4;
    iVar15 = iVar15 + *(int *)(lVar16 + 0x5e54);
    *(int *)(lVar16 + 0x5e54) = iVar15;
    (*pcVar20)(iVar18 + 0x5aa0,iVar15);
    lVar13 = (*(code *)(long)iRamffffffffbfc55d94)(iVar10);
    if (lVar13 < 1) {
      pcVar20 = (code *)(long)iRamffffffffbfc55cc0;
      *(undefined4 *)(lVar16 + 0x5e54) = 0;
      (*pcVar20)(iVar10,0,0x1000);
      *puVar19 = 2;
LAB_ffffffffbfc533fc:
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4ee8);
      (*(code *)(long)(iRamffffffffbfc55c28 + 0x2490))(param_3);
      *(undefined4 *)(long)iRamffffffffbfc55c98 = 1;
      *(undefined4 *)((long)iRamffffffffbfc55c28 + 0x5e50) = 1;
    }
    else {
      pcVar6 = (char *)(*(code *)(long)iRamffffffffbfc55d20)(iVar10,iRamffffffffbfc55c28 + 0x4c10);
      if (pcVar6 == (char *)0x0) {
        return;
      }
      do {
        while (((iVar10 = (int)pcVar6, *pcVar6 != '\r' || (pcVar6[1] != '\n')) ||
               (pcVar6[2] != '\r'))) {
          pcVar6 = (char *)(long)(iVar10 + 1);
        }
        pcVar1 = pcVar6 + 3;
        pcVar6 = (char *)(long)(iVar10 + 1);
      } while (*pcVar1 != '\n');
      pcVar6 = (char *)(*(code *)(long)iRamffffffffbfc55d20)
                                 (iRamffffffffbfc55c28 + 0x5e58,iRamffffffffbfc55c28 + 0x4eb8);
      iVar18 = iRamffffffffbfc55c28;
      if (pcVar6 == (char *)0x0) {
LAB_ffffffffbfc53348:
        pcVar20 = (code *)(long)iRamffffffffbfc55dd4;
        param_3 = (long)(iRamffffffffbfc55c28 + 0x4ed0);
        goto LAB_ffffffffbfc52738;
      }
      do {
        while (((iVar14 = (int)pcVar6, *pcVar6 != '\r' || (pcVar6[1] != '\n')) ||
               (pcVar6[2] != '\r'))) {
          pcVar6 = (char *)(long)(iVar14 + 1);
        }
        pcVar1 = pcVar6 + 3;
        pcVar6 = (char *)(long)(iVar14 + 1);
      } while (*pcVar1 != '\n');
      iVar15 = iVar14 + 4;
      lVar13 = (long)iRamffffffffbfc55c28;
      *(int *)((long)iRamffffffffbfc55c28 + 0x5e4c) =
           *(int *)((long)iRamffffffffbfc55c28 + 0x5e4c) - (iVar14 - iVar10);
      iVar18 = *(int *)(lVar13 + 0x5e54) - (iVar15 - (iVar18 + 0x5e58));
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x5ab0,iVar18);
      iVar10 = iRamffffffffbfc55c74;
LAB_ffffffffbfc533e0:
      (*(code *)(long)iVar10)(iVar15,iVar18);
LAB_ffffffffbfc533ec:
      if (*(int *)(long)iRamffffffffbfc55cac == 2) goto LAB_ffffffffbfc533fc;
    }
    *(undefined1 *)((long)iRamffffffffbfc55c28 + 0x5bbc) = 0;
  }
  else {
    iVar10 = *(int *)(long)iRamffffffffbfc55dbc;
    if (*(int *)(param_1 + 0x26) == iVar10) {
      *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(param_3 + 0x20);
      *(uint *)(param_3 + 0x20) = iVar10 + (uint)*(ushort *)(param_3 + 0x1c);
      if (*(char *)(param_3 + 0x2c) == '\0') {
        (*(code *)(long)iRamffffffffbfc55c7c)(param_3);
        lVar16 = (long)iRamffffffffbfc55c28;
        if (*(char *)((long)iRamffffffffbfc55c28 + 0x5bbc) != '\0') {
          iVar10 = *(ushort *)(lVar13 + 2) - 0x28;
          iVar14 = iRamffffffffbfc55c28 + 0x5e58;
          (*(code *)(long)iRamffffffffbfc55d98)(*(int *)(lVar16 + 0x5e54) + iVar14,iVar18,iVar10);
          pcVar20 = (code *)(long)iRamffffffffbfc55d94;
          *(int *)(lVar16 + 0x5e54) = *(int *)(lVar16 + 0x5e54) + iVar10;
          lVar13 = (*pcVar20)(iVar14);
          if (0 < lVar13) {
            pcVar6 = (char *)(*(code *)(long)iRamffffffffbfc55d20)
                                       (iVar14,iRamffffffffbfc55c28 + 0x4c10);
            if (pcVar6 == (char *)0x0) {
              return;
            }
            do {
              while (((iVar18 = (int)pcVar6, *pcVar6 != '\r' || (pcVar6[1] != '\n')) ||
                     (pcVar6[2] != '\r'))) {
                pcVar6 = (char *)(long)(iVar18 + 1);
              }
              pcVar1 = pcVar6 + 3;
              pcVar6 = (char *)(long)(iVar18 + 1);
            } while (*pcVar1 != '\n');
            pcVar6 = (char *)(*(code *)(long)iRamffffffffbfc55d20)
                                       (iRamffffffffbfc55c28 + 0x5e58,iRamffffffffbfc55c28 + 0x4eb8)
            ;
            iVar10 = iRamffffffffbfc55c74;
            if (pcVar6 == (char *)0x0) goto LAB_ffffffffbfc53348;
            do {
              while (((iVar14 = (int)pcVar6, *pcVar6 != '\r' || (pcVar6[1] != '\n')) ||
                     (pcVar6[2] != '\r'))) {
                pcVar6 = (char *)(long)(iVar14 + 1);
              }
              pcVar1 = pcVar6 + 3;
              pcVar6 = (char *)(long)(iVar14 + 1);
            } while (*pcVar1 != '\n');
            lVar13 = (long)iRamffffffffbfc55c28;
            iVar15 = iVar14 + 4;
            iVar17 = iRamffffffffbfc55c28 + 0x5e58;
            *(int *)((long)iRamffffffffbfc55c28 + 0x5e4c) =
                 *(int *)((long)iRamffffffffbfc55c28 + 0x5e4c) - (iVar14 - iVar18);
            iVar18 = *(int *)(lVar13 + 0x5e54) - (iVar15 - iVar17);
            goto LAB_ffffffffbfc533e0;
          }
          pcVar20 = (code *)(long)iRamffffffffbfc55cc0;
          *(undefined4 *)(lVar16 + 0x5e54) = 0;
          (*pcVar20)(iVar14,0,0x1000);
          iVar10 = iRamffffffffbfc55c28;
          pcVar20 = (code *)(long)iRamffffffffbfc55dd4;
          *(undefined4 *)(long)iRamffffffffbfc55cac = 2;
          (*pcVar20)(iVar10 + 0x4ea0);
          goto LAB_ffffffffbfc533ec;
        }
        (*(code *)(long)iRamffffffffbfc55c74)(iVar18,*(ushort *)(lVar13 + 2) - 0x28);
        if (*(int *)(long)iRamffffffffbfc55cac == 2) {
          lVar13 = (*(code *)(long)iRamffffffffbfc55d18)(*(undefined4 *)(long)iRamffffffffbfc55c4c);
          if (lVar13 == 0) {
            (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x5570);
            (*(code *)(long)(iRamffffffffbfc55c28 + 0x2490))(param_3);
            *(undefined4 *)((long)iRamffffffffbfc55c28 + 0x5e50) = 1;
            *(undefined4 *)(long)iRamffffffffbfc55d60 = 0;
            return;
          }
          iVar15 = iVar14 + -0xa1c;
          iVar17 = iVar14 + -0x105c;
          (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4f00);
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar14 + -0x9e6,iRamffffffffbfc55c28 + 0x4ca8,
                              iRamffffffffbfc55c28 + 0x4cb8,200,iRamffffffffbfc55c28 + 0x4cc8);
          iVar18 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar10 + 0x36,iRamffffffffbfc55c28 + 0x4f10);
          iVar18 = iVar10 + 0x36 + iVar18;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4cd0);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4d70);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4f28);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4f70);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4fa0);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x4ff8);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5020);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5088);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x50d8);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5110);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5160);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5190);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x51c8);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5210);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5238);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5278);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x52b8);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5328);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5380);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x53b8);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5430);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5490);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x54d8);
          iVar18 = iVar18 + iVar10;
          iVar10 = (*(code *)(long)iRamffffffffbfc55c9c)
                             (iVar15 + iVar18,iRamffffffffbfc55c28 + 0x5518);
          uVar12 = iVar18 + iVar10;
          if ((uVar12 & 1) != 0) {
            uVar12 = uVar12 + 1;
          }
          (*(code *)(long)iRamffffffffbfc55c9c)
                    (iVar14 + -0x9c5,iRamffffffffbfc55c28 + 0x5568,uVar12 - 0x78);
          (*(code *)(long)iRamffffffffbfc55d98)(iVar17,iVar15,0x514);
          (*(code *)(long)iRamffffffffbfc55d04)(param_3,iVar17,0x514,0x18,0);
          pcVar20 = (code *)(long)iRamffffffffbfc55cc0;
          *(int *)(param_3 + 0x24) = *(int *)(param_3 + 0x24) + 0x4de;
          (*pcVar20)(iVar17,0,0x640);
          (*(code *)(long)iRamffffffffbfc55d98)(iVar14 + -0x1026,iVar14 + -0x508,uVar12 - 0x514);
          (*(code *)(long)iRamffffffffbfc55d04)(param_3,iVar17,uVar12 - 0x4de,0x11,0);
          *(undefined4 *)(long)iRamffffffffbfc55d60 = 1;
        }
        pcVar20 = (code *)(long)iRamffffffffbfc55d80;
        if (*(int *)(long)iRamffffffffbfc55cac != 3) {
          return;
        }
      }
      else {
        (*(code *)(long)iRamffffffffbfc55dd4)
                  (iRamffffffffbfc55c28 + 0x4e98,0x363,iRamffffffffbfc55c28 + 0x4770);
        pcVar20 = (code *)(long)iRamffffffffbfc55d80;
      }
    }
    else {
      pcVar20 = (code *)(long)iRamffffffffbfc55dd4;
      iVar14 = iRamffffffffbfc55c28 + 0x4e98;
      *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(long)iRamffffffffbfc55cb8;
      iVar18 = iRamffffffffbfc55c28;
      *(int *)(param_3 + 0x20) = iVar10;
      (*pcVar20)(iVar14,0x36f,iVar18 + 0x4770);
      pcVar20 = (code *)(long)iRamffffffffbfc55c7c;
    }
LAB_ffffffffbfc52738:
    (*pcVar20)(param_3);
  }
  return;
}

