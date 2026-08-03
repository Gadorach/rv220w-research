/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1480c
 * Function: do_erase
 * Subsystem: u-boot-command
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: u-boot-command
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
 * 
 * Recovered from U-Boot command table: command='erase', maxargs=3, repeatable=0, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: u-boot-command
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='erase', maxargs=3, repeatable=0, usage=''. */

undefined8 do_erase(long param_1,undefined8 param_2,long param_3,long param_4)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  int iVar10;
  char cVar12;
  int iVar11;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  ulong uVar9;
  char *pcVar13;
  char *pcVar14;
  undefined4 uVar15;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  code *pcVar16;
  int *piVar17;
  undefined8 in_ra;
  
  iVar11 = (int)&stack0x00000000;
  piVar17 = (int *)(long)(iVar11 + -0x40);
  *(undefined1 **)(piVar17 + 10) = &_gp;
  *(undefined8 *)(piVar17 + 8) = unaff_s2;
  *(undefined8 *)(piVar17 + 6) = unaff_s1;
  *(undefined8 *)(piVar17 + 4) = unaff_s0;
  *(undefined8 *)(piVar17 + 0xc) = in_ra;
  if (1 < param_3) {
    pcVar14 = (char *)(long)*(int *)(param_4 + 4);
    iVar10 = DAT_ffffffffbfc436f4 + -0x4970;
    cVar2 = *pcVar14;
    pcVar13 = pcVar14;
    do {
      cVar3 = *(char *)(long)iVar10;
      pcVar13 = (char *)(long)((int)pcVar13 + 1);
      iVar10 = iVar10 + 1;
      cVar12 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar13;
      cVar12 = cVar3;
    } while (bVar1);
    pcVar16 = (code *)(long)DAT_ffffffffbfc4400c;
    if (cVar12 == cVar3) {
LAB_ffffffffbfc14994:
      (*pcVar16)(DAT_ffffffffbfc436f4 + -0x4968,1);
      iVar5 = DAT_ffffffffbfc43de0;
      iVar11 = 0;
      lVar6 = (long)DAT_ffffffffbfc43fc4;
      uVar4 = *(ushort *)(lVar6 + 4);
      *piVar17 = DAT_ffffffffbfc43fc4;
      iVar10 = uVar4 - 1;
LAB_ffffffffbfc149bc:
      uVar7 = (*(code *)(long)iVar5)(lVar6,iVar11,iVar10);
      return uVar7;
    }
    lVar6 = (*(code *)(long)(DAT_ffffffffbfc436fc + 0x44d0))
                      (pcVar14,piVar17,iVar11 + -0x3c,iVar11 + -0x38);
    if (lVar6 != 0) {
      if (lVar6 < 0) {
        (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x4950);
        return 1;
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + -0x4930,piVar17[1],piVar17[2],
                 (*piVar17 - DAT_ffffffffbfc43fc4 >> 2) * 0x25de13b9 + 1);
      lVar6 = (long)*piVar17;
      iVar11 = piVar17[1];
      iVar10 = piVar17[2];
      iVar5 = DAT_ffffffffbfc43de0;
      goto LAB_ffffffffbfc149bc;
    }
    if (param_3 == 3) {
      pcVar14 = (char *)(long)*(int *)(param_4 + 4);
      iVar11 = DAT_ffffffffbfc436f4 + -0x4908;
      cVar2 = *pcVar14;
      pcVar13 = pcVar14;
      do {
        cVar3 = *(char *)(long)iVar11;
        pcVar13 = (char *)(long)((int)pcVar13 + 1);
        iVar11 = iVar11 + 1;
        cVar12 = cVar2;
        if (cVar3 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar13;
        cVar12 = cVar3;
      } while (bVar1);
      if (cVar12 == cVar3) {
        lVar6 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 8),0,0x10);
        pcVar16 = (code *)(long)DAT_ffffffffbfc4400c;
        if (lVar6 != 1) {
          uVar15 = 1;
          iVar11 = DAT_ffffffffbfc436f4 + -0x49a0;
          goto LAB_ffffffffbfc14a50;
        }
        goto LAB_ffffffffbfc14994;
      }
      uVar8 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar14,0,0x10);
      iVar11 = *(int *)(param_4 + 8);
      if (*(char *)(long)iVar11 == '+') {
        iVar11 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar11 + 1,0,0x10);
        uVar9 = (*(code *)(long)(DAT_ffffffffbfc436fc + 0x41f0))
                          (DAT_ffffffffbfc43fc4,(int)uVar8 + iVar11 + -1);
      }
      else {
        uVar9 = (*(code *)(long)DAT_ffffffffbfc438b0)((char *)(long)iVar11,0,0x10);
      }
      if (uVar8 < uVar9) {
        uVar7 = (*(code *)(long)DAT_ffffffffbfc43c0c)(uVar8,uVar9);
        return uVar7;
      }
    }
  }
  uVar15 = *(undefined4 *)(param_1 + 0x10);
  pcVar16 = (code *)(long)DAT_ffffffffbfc4400c;
  iVar11 = DAT_ffffffffbfc436f4 + -0x5320;
LAB_ffffffffbfc14a50:
  (*pcVar16)(iVar11,uVar15);
  return 1;
}

