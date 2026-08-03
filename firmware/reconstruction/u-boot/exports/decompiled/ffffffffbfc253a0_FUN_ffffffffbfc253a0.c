/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc253a0
 * Function: FUN_ffffffffbfc253a0
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

undefined8 FUN_ffffffffbfc253a0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 unaff_s0;
  int *piVar6;
  undefined8 unaff_s1;
  uint uVar7;
  undefined8 unaff_s2;
  int iVar8;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  uint uVar9;
  undefined8 unaff_s5;
  int iVar10;
  undefined8 unaff_s6;
  uint uVar11;
  undefined8 unaff_s7;
  undefined8 *puVar12;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  puVar12 = (undefined8 *)(long)((int)&stack0x00000000 + -0x60);
  puVar12[3] = unaff_s3;
  iVar8 = param_1[7];
  puVar12[8] = &_gp;
  iVar10 = *(int *)(long)iVar8;
  puVar12[10] = in_ra;
  puVar12[9] = unaff_s8;
  puVar12[7] = unaff_s7;
  puVar12[6] = unaff_s6;
  puVar12[5] = unaff_s5;
  puVar12[4] = unaff_s4;
  puVar12[2] = unaff_s2;
  puVar12[1] = unaff_s1;
  *puVar12 = unaff_s0;
  if (iVar10 == 2) {
    piVar6 = (int *)(long)((int *)(long)iVar8)[5];
    iVar8 = piVar6[0xc];
    uVar5 = 0xfffffffffffffffe;
    if ((iVar8 == piVar6[0xd]) && (uVar5 = 0xfffffffffffffffd, *piVar6 == 0)) {
      iVar10 = *param_1;
      uVar9 = param_1[1];
      uVar11 = piVar6[0xb] - iVar8;
      iVar1 = piVar6[9];
      iVar2 = piVar6[8];
      while( true ) {
        if (uVar9 == 0) break;
        uVar7 = uVar9;
        if (uVar11 <= uVar9) {
          uVar7 = uVar11;
        }
        uVar9 = uVar9 - uVar7;
        if ((code *)(long)piVar6[0xe] != (code *)0x0) {
          iVar4 = (*(code *)(long)piVar6[0xe])(piVar6[0xf],iVar8,uVar7);
          piVar6[0xf] = iVar4;
        }
        if ((code *)(long)param_1[0xc] != (code *)0x0) {
          (*(code *)(long)param_1[0xc])(iVar8,uVar7);
        }
        (*(code *)(long)DAT_ffffffffbfc43e84)(iVar8,iVar10,uVar7);
        iVar8 = iVar8 + uVar7;
        iVar4 = param_1[5];
        iVar10 = iVar10 + uVar7;
        iVar3 = piVar6[0xb];
        piVar6[0xc] = iVar8;
        param_1[5] = iVar4 + uVar7;
        if (iVar8 == iVar3) {
          iVar8 = piVar6[10];
          piVar6[0xc] = iVar8;
          uVar11 = iVar3 - iVar8;
        }
      }
      iVar4 = *param_1;
      uVar5 = 0;
      piVar6[9] = iVar1;
      iVar1 = param_1[2];
      *param_1 = iVar10;
      piVar6[8] = iVar2;
      piVar6[0xd] = iVar8;
      param_1[2] = iVar1 + (iVar10 - iVar4);
      param_1[1] = 0;
    }
  }
  else {
    uVar5 = 0xfffffffffffffffd;
  }
  return uVar5;
}

