/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2a454
 * Function: FUN_ffffffffbfc2a454
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

undefined4 FUN_ffffffffbfc2a454(void)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  int iVar5;
  int iVar6;
  int *piVar4;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 unaff_s0;
  long lVar10;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar11;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar12;
  undefined4 in_k0_hi;
  int in_k0_lo;
  undefined8 *puVar13;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  puVar13 = (undefined8 *)(long)((int)&stack0x00000000 + -0x60);
  puVar13[8] = &_gp;
  *puVar13 = unaff_s0;
  puVar13[9] = unaff_s8;
  iVar2 = DAT_ffffffffbfc436f4;
  lVar10 = (long)DAT_ffffffffbfc436f4;
  iVar8 = *(int *)(lVar10 + 0x2e90);
  puVar13[10] = in_ra;
  puVar13[7] = unaff_s7;
  puVar13[6] = unaff_s6;
  puVar13[5] = unaff_s5;
  puVar13[4] = unaff_s4;
  puVar13[3] = unaff_s3;
  puVar13[2] = unaff_s2;
  puVar13[1] = unaff_s1;
  iVar5 = DAT_ffffffffbfc436f4;
  if (iVar8 == -1) {
    pcVar12 = (code *)(long)DAT_ffffffffbfc43e84;
    *(uint *)(lVar10 + 0x2e90) = (uint)*(byte *)(CONCAT44(in_k0_hi,in_k0_lo) + 0x7e);
    (*pcVar12)(iVar5 + 0x6080,in_k0_lo + 0x78,6);
  }
  lVar3 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x59d0);
  if (lVar3 == 0) {
    if (0 < *(int *)(lVar10 + 0x2e90)) {
      (*(code *)(long)DAT_ffffffffbfc43a54)(DAT_ffffffffbfc436f4 + 0x6088,0xff,400);
      lVar10 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6700))(0xd0000);
      iVar5 = DAT_ffffffffbfc436f4;
      iVar8 = DAT_ffffffffbfc436f0;
      if (lVar10 != 0) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar5 + 0x1150);
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar8 + 0x7dd8);
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1858);
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1898);
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x18e8);
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar8 + 0x7dd8);
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar5 + 0x1150);
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar5 + 0x1150);
      }
      iVar11 = 0;
      iVar5 = (*(code *)(long)DAT_ffffffffbfc43c04)();
      iVar8 = 2;
      if (iVar5 < 3) {
        iVar8 = iVar5;
      }
      do {
        if (iVar8 <= iVar11) {
          return *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x607c);
        }
        lVar10 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar11);
        pcVar12 = (code *)(long)DAT_ffffffffbfc43f1c;
        if (lVar10 == 1) {
LAB_ffffffffbfc2a644:
          (*pcVar12)(iVar11);
          iVar6 = (*(code *)(long)DAT_ffffffffbfc43d30)(iVar11);
          iVar5 = iVar11 * 0x10;
          while( true ) {
            lVar10 = (long)DAT_ffffffffbfc436f4;
            pcVar12 = (code *)(long)DAT_ffffffffbfc43e1c;
            if ((iVar6 + iVar11 * 0x10 <= iVar5) ||
               (iVar7 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x2e90),
               *(int *)((long)DAT_ffffffffbfc436f4 + 0x2e90) = iVar7 + -1, iVar7 < 1)) break;
            lVar3 = (*pcVar12)(0x38);
            pcVar12 = (code *)(long)DAT_ffffffffbfc43e1c;
            if ((iVar5 == 0x10) || (iVar5 == 0)) {
              *(int *)(long)DAT_ffffffffbfc43c1c = (int)lVar3;
            }
            piVar4 = (int *)(*pcVar12)(0x14);
            iVar7 = DAT_ffffffffbfc436f0;
            *piVar4 = iVar5;
            iVar7 = (*(code *)(long)(iVar7 + -0x6494))(iVar5);
            uVar1 = *(undefined4 *)(lVar10 + 0x607c);
            pcVar12 = (code *)(long)DAT_ffffffffbfc439a4;
            iVar9 = DAT_ffffffffbfc436f4 + 0x1920;
            piVar4[2] = iVar7;
            piVar4[1] = iVar11;
            piVar4[3] = 0;
            (*pcVar12)(lVar3,iVar9,uVar1);
            iVar7 = DAT_ffffffffbfc436f4;
            pcVar12 = (code *)(long)DAT_ffffffffbfc43e84;
            *(int *)(lVar10 + 0x607c) = *(int *)(lVar10 + 0x607c) + 1;
            uVar1 = DAT_ffffffffbfc43e04;
            *(int *)(lVar3 + 0x34) = (int)piVar4;
            *(undefined4 *)(lVar3 + 0x20) = uVar1;
            uVar1 = DAT_ffffffffbfc43c34;
            *(undefined4 *)(lVar3 + 0x18) = 0;
            *(undefined4 *)(lVar3 + 0x2c) = uVar1;
            *(undefined4 *)(lVar3 + 0x24) = DAT_ffffffffbfc43a3c;
            *(undefined4 *)(lVar3 + 0x28) = DAT_ffffffffbfc43dc0;
            (*pcVar12)((int)lVar3 + 0x10,iVar7 + 0x6080,6);
            pcVar12 = (code *)(long)DAT_ffffffffbfc43d98;
            *(int *)(long)(iVar2 + 0x6082) = *(int *)(long)(iVar2 + 0x6082) + 1;
            (*pcVar12)(lVar3);
            iVar5 = iVar5 + 1;
          }
        }
        else {
          lVar10 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar11);
          pcVar12 = (code *)(long)DAT_ffffffffbfc43f1c;
          if (lVar10 == 2) goto LAB_ffffffffbfc2a644;
          lVar10 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar11);
          pcVar12 = (code *)(long)DAT_ffffffffbfc43f1c;
          if (lVar10 == 6) goto LAB_ffffffffbfc2a644;
          lVar10 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar11);
          if (lVar10 == 5) {
            pcVar12 = (code *)(long)DAT_ffffffffbfc43f1c;
            goto LAB_ffffffffbfc2a644;
          }
        }
        iVar11 = iVar11 + 1;
      } while( true );
    }
    iVar8 = DAT_ffffffffbfc436f4 + 0x1818;
  }
  else {
    iVar8 = DAT_ffffffffbfc436f4 + 0x17b8;
  }
  (*(code *)(long)DAT_ffffffffbfc4400c)(iVar8);
  return 0;
}

