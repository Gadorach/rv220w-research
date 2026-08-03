/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc14a84
 * Function: do_protect
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
 * Recovered from U-Boot command table: command='protect', maxargs=4, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='protect', maxargs=4, repeatable=1, usage=''. */

undefined8 do_protect(long param_1,undefined8 param_2,long param_3,long param_4)

{
  bool bVar1;
  char cVar2;
  int iVar6;
  char cVar7;
  char cVar8;
  ulong uVar3;
  ulong uVar4;
  undefined8 uVar5;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  undefined4 uVar13;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar14;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  char cVar15;
  int *piVar16;
  undefined8 in_ra;
  
  iVar12 = (int)&stack0x00000000;
  piVar16 = (int *)(long)(iVar12 + -0x40);
  *(undefined1 **)(piVar16 + 0xc) = &_gp;
  *(undefined8 *)(piVar16 + 8) = unaff_s2;
  *(undefined8 *)(piVar16 + 6) = unaff_s1;
  *(undefined8 *)(piVar16 + 4) = unaff_s0;
  *(undefined8 *)(piVar16 + 0xe) = in_ra;
  *(undefined8 *)(piVar16 + 10) = unaff_s3;
  if (2 < param_3) {
    pcVar11 = (char *)(long)*(int *)(param_4 + 4);
    iVar6 = DAT_ffffffffbfc436f4 + -0x4900;
    cVar15 = *pcVar11;
    pcVar10 = pcVar11;
    do {
      cVar2 = *(char *)(long)iVar6;
      pcVar10 = (char *)(long)((int)pcVar10 + 1);
      iVar6 = iVar6 + 1;
      cVar7 = cVar15;
      if (cVar2 != cVar15) break;
      bVar1 = cVar15 != '\0';
      cVar15 = *pcVar10;
      cVar7 = cVar2;
    } while (bVar1);
    cVar15 = '\0';
    if (cVar7 != cVar2) {
      iVar6 = DAT_ffffffffbfc436f4 + -0x48f8;
      cVar15 = *pcVar11;
      do {
        cVar2 = *(char *)(long)iVar6;
        pcVar11 = (char *)(long)((int)pcVar11 + 1);
        iVar6 = iVar6 + 1;
        cVar7 = cVar15;
        if (cVar2 != cVar15) break;
        bVar1 = cVar15 != '\0';
        cVar15 = *pcVar11;
        cVar7 = cVar2;
      } while (bVar1);
      cVar15 = '\x01';
      if (cVar7 != cVar2) goto LAB_ffffffffbfc14e24;
    }
    pcVar11 = (char *)(long)*(int *)(param_4 + 8);
    iVar6 = DAT_ffffffffbfc436f4 + -0x4970;
    cVar2 = *pcVar11;
    pcVar10 = pcVar11;
    do {
      cVar7 = *(char *)(long)iVar6;
      pcVar10 = (char *)(long)((int)pcVar10 + 1);
      iVar6 = iVar6 + 1;
      cVar8 = cVar2;
      if (cVar7 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar10;
      cVar8 = cVar7;
    } while (bVar1);
    if (cVar8 == cVar7) {
      lVar14 = (long)DAT_ffffffffbfc43fc4;
      iVar6 = 1;
      iVar12 = *(int *)(lVar14 + 8);
      while( true ) {
        *piVar16 = (int)lVar14;
        if (iVar12 != 0xffff) {
          if (cVar15 == '\0') {
            iVar12 = DAT_ffffffffbfc436f4 + -0x4ac8;
          }
          else {
            iVar12 = DAT_ffffffffbfc436f4 + -0x3ca8;
          }
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x48f0,iVar12,iVar6);
          iVar12 = 0;
          while( true ) {
            iVar9 = iVar12 + *piVar16;
            bVar1 = (int)(uint)*(ushort *)((long)*piVar16 + 4) <= iVar12;
            iVar12 = iVar12 + 1;
            if (bVar1) break;
            *(char *)((long)iVar9 + 0x80c) = cVar15;
          }
        }
        iVar6 = iVar6 + 1;
        lVar14 = (long)((int)lVar14 + 0xa24);
        if (iVar6 == 2) break;
        iVar12 = *(int *)(lVar14 + 8);
      }
      return 0;
    }
    lVar14 = (*(code *)(long)(DAT_ffffffffbfc436fc + 0x44d0))
                       (pcVar11,piVar16,iVar12 + -0x3c,iVar12 + -0x38);
    if (lVar14 != 0) {
      if (-1 < lVar14) {
        if (cVar15 == '\0') {
          iVar12 = DAT_ffffffffbfc436f4 + -0x4ac8;
        }
        else {
          iVar12 = DAT_ffffffffbfc436f4 + -0x3ca8;
        }
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + -0x48d0,iVar12,piVar16[1],piVar16[2],
                   (*piVar16 - DAT_ffffffffbfc43fc4 >> 2) * 0x25de13b9 + 1);
        for (iVar12 = piVar16[1]; iVar12 <= piVar16[2]; iVar12 = iVar12 + 1) {
          *(char *)((long)(iVar12 + *piVar16) + 0x80c) = cVar15;
        }
        return 0;
      }
      iVar12 = DAT_ffffffffbfc436f4 + -0x4950;
LAB_ffffffffbfc14c28:
      (*(code *)(long)DAT_ffffffffbfc43e38)(iVar12);
      return 1;
    }
    if (param_3 == 4) {
      pcVar11 = (char *)(long)*(int *)(param_4 + 8);
      iVar12 = DAT_ffffffffbfc436f4 + -0x4908;
      cVar2 = *pcVar11;
      pcVar10 = pcVar11;
      do {
        cVar7 = *(char *)(long)iVar12;
        pcVar10 = (char *)(long)((int)pcVar10 + 1);
        iVar12 = iVar12 + 1;
        cVar8 = cVar2;
        if (cVar7 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar10;
        cVar8 = cVar7;
      } while (bVar1);
      if (cVar8 == cVar7) {
        lVar14 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 0xc),0,0x10);
        if (lVar14 == 1) {
          if (cVar15 == '\0') {
            iVar12 = DAT_ffffffffbfc436f4 + -0x4ac8;
          }
          else {
            iVar12 = DAT_ffffffffbfc436f4 + -0x3ca8;
          }
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x48f0,iVar12,1);
          iVar12 = *(int *)((long)DAT_ffffffffbfc43fc4 + 8);
          *piVar16 = DAT_ffffffffbfc43fc4;
          if (iVar12 != 0xffff) {
            iVar12 = 0;
            while( true ) {
              iVar6 = iVar12 + *piVar16;
              bVar1 = (int)(uint)*(ushort *)((long)*piVar16 + 4) <= iVar12;
              iVar12 = iVar12 + 1;
              if (bVar1) break;
              *(char *)((long)iVar6 + 0x80c) = cVar15;
            }
            return 0;
          }
          iVar12 = DAT_ffffffffbfc436f4 + -0x5698;
          goto LAB_ffffffffbfc14c28;
        }
        uVar13 = 1;
        iVar12 = DAT_ffffffffbfc436f4 + -0x49a0;
        goto LAB_ffffffffbfc14e30;
      }
      uVar3 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar11,0,0x10);
      iVar12 = *(int *)(param_4 + 0xc);
      if (*(char *)(long)iVar12 == '+') {
        iVar12 = (*(code *)(long)DAT_ffffffffbfc438b0)(iVar12 + 1,0,0x10);
        uVar4 = (*(code *)(long)(DAT_ffffffffbfc436fc + 0x41f0))
                          (DAT_ffffffffbfc43fc4,(int)uVar3 + iVar12 + -1);
      }
      else {
        uVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)((char *)(long)iVar12,0,0x10);
      }
      if (uVar3 < uVar4) {
        uVar5 = (*(code *)(long)DAT_ffffffffbfc43b24)(cVar15,uVar3,uVar4);
        return uVar5;
      }
    }
  }
LAB_ffffffffbfc14e24:
  uVar13 = *(undefined4 *)(param_1 + 0x10);
  iVar12 = DAT_ffffffffbfc436f4 + -0x5320;
LAB_ffffffffbfc14e30:
  (*(code *)(long)DAT_ffffffffbfc4400c)(iVar12,uVar13);
  return 1;
}

