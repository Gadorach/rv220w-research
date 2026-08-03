/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1e7b0
 * Function: FUN_ffffffffbfc1e7b0
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

int * FUN_ffffffffbfc1e7b0(char *param_1)

{
  char cVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int *piVar9;
  int *piVar10;
  undefined8 unaff_s3;
  int iVar11;
  code *pcVar12;
  undefined8 *puVar13;
  undefined8 in_ra;
  
  puVar13 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar13[4] = &_gp;
  puVar13[1] = unaff_s1;
  pcVar12 = (code *)(long)DAT_ffffffffbfc43798;
  puVar13[5] = in_ra;
  puVar13[3] = unaff_s3;
  puVar13[2] = unaff_s2;
  *puVar13 = unaff_s0;
  lVar3 = (*pcVar12)(param_1,0x2e);
  if (lVar3 == 0) {
    iVar4 = (*(code *)(long)DAT_ffffffffbfc437c8)(param_1);
  }
  else {
    iVar4 = (int)lVar3 - (int)param_1;
  }
  piVar9 = (int *)(long)DAT_ffffffffbfc4404c;
  iVar11 = 0;
  piVar10 = piVar9;
  do {
    if (piVar10 == (int *)(long)DAT_ffffffffbfc43b1c) {
      piVar10 = (int *)0x0;
      if (iVar11 == 1) {
        piVar10 = piVar9;
      }
      return piVar10;
    }
    iVar7 = *piVar10;
    pcVar8 = param_1;
    iVar6 = iVar4;
    while( true ) {
      cVar1 = *pcVar8;
      cVar2 = *(char *)(long)iVar7;
      cVar5 = cVar2;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar8 = (char *)(long)((int)pcVar8 + 1);
      cVar5 = cVar1;
      if ((cVar2 != cVar1) || (iVar7 = iVar7 + 1, cVar5 = cVar2, cVar1 == '\0')) break;
    }
    if (cVar5 == cVar2) {
      iVar11 = iVar11 + 1;
      iVar7 = (*(code *)(long)DAT_ffffffffbfc437c8)();
      piVar9 = piVar10;
      if (iVar4 == iVar7) {
        return piVar10;
      }
    }
    piVar10 = (int *)(long)((int)piVar10 + 0x20);
  } while( true );
}

