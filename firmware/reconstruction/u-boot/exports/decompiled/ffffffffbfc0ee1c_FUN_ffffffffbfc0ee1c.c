/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0ee1c
 * Function: FUN_ffffffffbfc0ee1c
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

int FUN_ffffffffbfc0ee1c(undefined8 param_1)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  long lVar4;
  char *pcVar5;
  char cVar6;
  undefined1 uVar7;
  char *pcVar8;
  int iVar10;
  char *pcVar9;
  undefined4 uVar11;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar12;
  char *pcVar13;
  undefined8 unaff_s2;
  undefined1 *puVar14;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  int iVar15;
  code *pcVar16;
  int *piVar17;
  undefined8 in_ra;
  int iVar18;
  
  iVar18 = (int)&stack0x00000000;
  piVar17 = (int *)(long)(iVar18 + -0x70);
  *(undefined1 **)(piVar17 + 0x18) = &_gp;
  *(undefined8 *)(piVar17 + 0x10) = unaff_s2;
  *(undefined8 *)(piVar17 + 0xe) = unaff_s1;
  iVar10 = DAT_ffffffffbfc436f4;
  lVar12 = (long)DAT_ffffffffbfc436f4;
  lVar4 = (long)DAT_ffffffffbfc436f4;
  pcVar16 = (code *)(long)DAT_ffffffffbfc43f0c;
  *(undefined8 *)(piVar17 + 0xc) = unaff_s0;
  *(undefined8 *)(piVar17 + 0x1a) = in_ra;
  *(undefined8 *)(piVar17 + 0x16) = unaff_s5;
  *(undefined8 *)(piVar17 + 0x14) = unaff_s4;
  *(undefined8 *)(piVar17 + 0x12) = unaff_s3;
  *(undefined4 *)(lVar4 + 0x4a78) = 0;
  *(undefined4 *)(lVar12 + 0x4a74) = 0;
  lVar4 = (*pcVar16)(iVar10 + -0x59d0);
  if (lVar4 == 0) {
    (*(code *)(long)DAT_ffffffffbfc439e0)(param_1);
  }
  pcVar13 = (char *)(long)*(int *)(lVar12 + 0x4a74);
  if (pcVar13 == (char *)0x0) {
    lVar4 = (*(code *)(long)DAT_ffffffffbfc43f0c)(iVar10 + -0x59d0);
    pcVar16 = (code *)(long)DAT_ffffffffbfc43e38;
    if (lVar4 == 0) {
      iVar15 = 0;
      iVar10 = DAT_ffffffffbfc436f4 + -0x59b8;
    }
    else {
      iVar15 = 0;
      iVar10 = DAT_ffffffffbfc436f4 + -0x59a0;
    }
    goto LAB_ffffffffbfc0f100;
  }
  iVar15 = 0;
  pcVar5 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x5960);
  do {
    if (iVar15 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5950);
    }
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5948,pcVar13);
    iVar10 = DAT_ffffffffbfc436f4;
    if (pcVar5 != (char *)0x0) {
      cVar2 = *pcVar13;
      pcVar8 = pcVar5;
      pcVar9 = pcVar13;
      do {
        cVar3 = *pcVar8;
        pcVar9 = (char *)(long)((int)pcVar9 + 1);
        pcVar8 = (char *)(long)((int)pcVar8 + 1);
        cVar6 = cVar2;
        if (cVar3 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar9;
        cVar6 = cVar3;
      } while (bVar1);
      if (cVar6 == cVar3) {
        pcVar16 = (code *)(long)DAT_ffffffffbfc43e38;
        *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a78) = (int)pcVar13;
        (*pcVar16)(iVar10 + -0x5940);
      }
    }
    if (iVar15 == 0) {
      iVar10 = DAT_ffffffffbfc436f0 + 0x70c0;
    }
    else {
      iVar10 = DAT_ffffffffbfc436f4 + -0x5930;
    }
    (*(code *)(long)DAT_ffffffffbfc439a4)(iVar18 + -0x66,iVar10,iVar15);
    puVar14 = (undefined1 *)(long)(iVar18 + -0x6c);
    pcVar8 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(iVar18 + -0x66);
    do {
      if (pcVar8 == (char *)0x0) {
        *puVar14 = 0;
      }
      else {
        uVar7 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar8,piVar17,0x10);
        iVar10 = *piVar17;
        *puVar14 = uVar7;
        pcVar8 = (char *)(long)iVar10;
        if (*(char *)(long)iVar10 != '\0') {
          pcVar8 = (char *)(long)(iVar10 + 1);
        }
      }
      puVar14 = (undefined1 *)(long)((int)puVar14 + 1);
    } while (puVar14 != (undefined1 *)(long)(iVar18 + -0x66));
    lVar4 = (*(code *)(long)DAT_ffffffffbfc43ab4)(iVar18 + -0x6c,DAT_ffffffffbfc436f0 + 0x63a0,6);
    if (lVar4 != 0) {
      iVar10 = (int)pcVar13 + 0x10;
      lVar4 = (*(code *)(long)DAT_ffffffffbfc43ab4)(iVar10,DAT_ffffffffbfc436f0 + 0x63a8,3);
      pcVar16 = (code *)(long)DAT_ffffffffbfc43e84;
      if (lVar4 != 0) {
        lVar4 = (*(code *)(long)DAT_ffffffffbfc43ab4)(iVar10,iVar18 + -0x6c,6);
        pcVar16 = (code *)(long)DAT_ffffffffbfc43e84;
        if (lVar4 != 0) {
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5920,pcVar13);
          (*(code *)(long)DAT_ffffffffbfc4400c)
                    (DAT_ffffffffbfc436f4 + -0x58f0,pcVar13[0x10],pcVar13[0x11],pcVar13[0x12],
                     pcVar13[0x13],pcVar13[0x14],pcVar13[0x15]);
          (*(code *)(long)DAT_ffffffffbfc4400c)
                    (DAT_ffffffffbfc436f4 + -0x58b0,*(undefined1 *)(piVar17 + 1),
                     *(undefined1 *)((long)piVar17 + 5),*(undefined1 *)((long)piVar17 + 6),
                     *(undefined1 *)((long)piVar17 + 7),*(undefined1 *)(piVar17 + 2),
                     *(undefined1 *)((long)piVar17 + 9));
          pcVar16 = (code *)(long)DAT_ffffffffbfc43e84;
        }
      }
      (*pcVar16)(iVar10,iVar18 + -0x6c,6);
    }
    iVar10 = DAT_ffffffffbfc436f4;
    pcVar13 = (char *)(long)*(int *)(pcVar13 + 0x30);
    iVar15 = iVar15 + 1;
  } while (pcVar13 != (char *)(long)*(int *)((long)DAT_ffffffffbfc436f4 + 0x4a74));
  lVar4 = (long)DAT_ffffffffbfc436f4;
  if (*(int *)(lVar4 + 0x4a78) == 0) {
    uVar11 = 0;
LAB_ffffffffbfc0f0f0:
    (*(code *)(long)DAT_ffffffffbfc43b14)(iVar10 + -23000,uVar11);
  }
  else {
    lVar12 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -23000);
    uVar11 = *(undefined4 *)(lVar4 + 0x4a78);
    if (lVar12 == 0) goto LAB_ffffffffbfc0f0f0;
  }
  pcVar16 = (code *)(long)DAT_ffffffffbfc439f0;
  iVar10 = 10;
LAB_ffffffffbfc0f100:
  (*pcVar16)(iVar10);
  return iVar15;
}

