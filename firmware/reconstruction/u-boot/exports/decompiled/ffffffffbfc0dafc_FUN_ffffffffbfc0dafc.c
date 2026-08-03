/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0dafc
 * Function: FUN_ffffffffbfc0dafc
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

void FUN_ffffffffbfc0dafc(short *param_1,int param_2,int param_3,ulong param_4)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  ushort uVar5;
  long lVar6;
  char *pcVar7;
  undefined4 uVar8;
  char cVar9;
  int iVar10;
  long lVar11;
  undefined8 unaff_s0;
  char *pcVar12;
  undefined8 unaff_s1;
  uint uVar14;
  uint uVar15;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar16;
  undefined8 unaff_s4;
  code *pcVar17;
  undefined8 *puVar18;
  undefined8 in_ra;
  int iVar13;
  
  puVar18 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar18[5] = &_gp;
  puVar18[4] = unaff_s4;
  lVar6 = (long)DAT_ffffffffbfc436f4;
  puVar18[6] = in_ra;
  iVar16 = *(int *)(lVar6 + 0x4a34);
  puVar18[3] = unaff_s3;
  puVar18[2] = unaff_s2;
  puVar18[1] = unaff_s1;
  *puVar18 = unaff_s0;
  if (param_2 != iVar16) {
    return;
  }
  if ((*(int *)((long)DAT_ffffffffbfc436f4 + 0x4a4c) != 1) &&
     (param_3 != *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a30))) {
    return;
  }
  if (param_4 < 2) {
    return;
  }
  sVar4 = *param_1;
  uVar14 = (int)param_4 - 2;
  iVar16 = (int)param_1;
  iVar13 = iVar16 + 2;
  if (sVar4 == 5) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5ab8,iVar16 + 4,param_1[1]);
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5aa0);
    goto LAB_ffffffffbfc0de9c;
  }
  if (sVar4 == 6) {
    iVar16 = iVar13 + uVar14;
    do {
      iVar10 = DAT_ffffffffbfc436fc;
      pcVar12 = (char *)(long)iVar13;
      if ((char *)(long)iVar16 <= pcVar12) {
        *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a4c) = 5;
        *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a30) = param_3;
        (*(code *)(long)(iVar10 + -0x2a70))();
        return;
      }
      iVar10 = (*(code *)(long)DAT_ffffffffbfc437c8)(pcVar12);
      iVar10 = iVar13 + iVar10 + 1;
      iVar13 = (*(code *)(long)DAT_ffffffffbfc437c8)(iVar10);
      pcVar7 = (char *)(long)(DAT_ffffffffbfc436f4 + -0x5c60);
      cVar2 = *pcVar7;
      do {
        cVar3 = *pcVar12;
        pcVar7 = (char *)(long)((int)pcVar7 + 1);
        pcVar12 = (char *)(long)((int)pcVar12 + 1);
        cVar9 = cVar2;
        if (cVar3 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar7;
        cVar9 = cVar3;
      } while (bVar1);
      if (cVar9 == cVar3) {
        uVar8 = (*(code *)(long)DAT_ffffffffbfc43f3c)(iVar10,0,10);
        *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x28b0) = uVar8;
      }
      iVar13 = iVar10 + iVar13 + 1;
    } while( true );
  }
  if (sVar4 != 3) {
    return;
  }
  if (uVar14 < 2) {
    return;
  }
  uVar5 = param_1[1];
  *(uint *)((long)DAT_ffffffffbfc436f4 + 0x4a3c) = (uint)uVar5;
  if (uVar5 == 0) {
    lVar6 = (long)DAT_ffffffffbfc436f4;
    lVar11 = (long)DAT_ffffffffbfc436f4;
    pcVar17 = (code *)(long)DAT_ffffffffbfc4400c;
    *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a44) =
         *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a44) + 1;
    iVar13 = DAT_ffffffffbfc436f4;
    uVar14 = *(int *)(lVar6 + 0x28b0) * 0x10000 + *(int *)(lVar11 + 0x4a48);
    *(uint *)(lVar11 + 0x4a48) = uVar14;
    (*pcVar17)(iVar13 + -0x5b20,uVar14 >> 0x14);
    lVar6 = (long)DAT_ffffffffbfc436f4;
  }
  else {
    uVar14 = uVar5 - 1;
    if (uVar14 == (uVar14 / 100) * 100) {
      iVar10 = 0x23;
      iVar13 = DAT_ffffffffbfc439f0;
    }
    else {
      lVar6 = (long)DAT_ffffffffbfc436f4;
      if ((uint)uVar5 != (uVar5 / 0x1964) * 0x1964) goto LAB_ffffffffbfc0dd38;
      iVar10 = DAT_ffffffffbfc436f4 + -0x5b08;
      iVar13 = DAT_ffffffffbfc43e38;
    }
    (*(code *)(long)iVar13)(iVar10);
    lVar6 = (long)DAT_ffffffffbfc436f4;
  }
LAB_ffffffffbfc0dd38:
  if ((*(int *)(lVar6 + 0x4a4c) == 1) || (*(int *)(lVar6 + 0x4a4c) == 5)) {
    iVar13 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a3c);
    *(undefined4 *)(lVar6 + 0x4a4c) = 2;
    *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a30) = param_3;
    *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a40) = 0;
    *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a44) = 0;
    *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a48) = 0;
    iVar10 = 1;
    if (iVar13 != 1) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5b00);
LAB_ffffffffbfc0de9c:
      (*(code *)(long)DAT_ffffffffbfc438f4)();
      return;
    }
  }
  else {
    iVar10 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a3c);
    if (iVar10 == *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a40)) {
      return;
    }
  }
  pcVar17 = (code *)(long)DAT_ffffffffbfc43fec;
  *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a40) = iVar10;
  uVar15 = (int)param_4 - 4;
  lVar6 = (long)DAT_ffffffffbfc436f4;
  (*pcVar17)(2500000000,DAT_ffffffffbfc436fc + -0x259c);
  iVar13 = (*(int *)((long)DAT_ffffffffbfc436f4 + 0x4a3c) + -1) * *(int *)(lVar6 + 0x28b0) +
           *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a48);
  uVar14 = iVar13 + uVar15;
  (*(code *)(long)DAT_ffffffffbfc43e84)
            (iVar13 + *(int *)(long)DAT_ffffffffbfc43c14,iVar16 + 4,uVar15);
  iVar16 = DAT_ffffffffbfc436fc;
  if (*(uint *)(long)DAT_ffffffffbfc43894 < uVar14) {
    *(uint *)(long)DAT_ffffffffbfc43894 = uVar14;
  }
  (*(code *)(long)(iVar16 + -0x2a70))();
  if (uVar15 < *(uint *)(lVar6 + 0x28b0)) {
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5ac0);
    *(undefined4 *)(long)DAT_ffffffffbfc43d80 = 3;
  }
  return;
}

