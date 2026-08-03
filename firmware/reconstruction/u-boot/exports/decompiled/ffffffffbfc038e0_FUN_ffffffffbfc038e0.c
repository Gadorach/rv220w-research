/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc038e0
 * Function: FUN_ffffffffbfc038e0
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

void FUN_ffffffffbfc038e0(void)

{
  char cVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  char *pcVar7;
  undefined8 unaff_s0;
  int iVar8;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  uint uVar9;
  undefined8 unaff_s3;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar11[4] = &_gp;
  puVar11[3] = unaff_s3;
  puVar11[2] = unaff_s2;
  pcVar10 = (code *)(long)DAT_ffffffffbfc43ac8;
  uVar9 = 0;
  *puVar11 = unaff_s0;
  puVar11[5] = in_ra;
  puVar11[1] = unaff_s1;
  lVar3 = (*pcVar10)();
  iVar8 = *(int *)(lVar3 + 0x34) + 8;
  do {
    iVar6 = DAT_ffffffffbfc436f0;
    if (*(uint *)(lVar3 + 0x28) <= uVar9) {
      return;
    }
    if (*(long *)(long)iVar8 != 0) {
      iVar4 = (*(code *)(long)DAT_ffffffffbfc437c8)(DAT_ffffffffbfc436f0 + 0x7c78);
      iVar6 = iVar6 + 0x7c78;
      pcVar7 = (char *)(long)(iVar8 + 8);
      while( true ) {
        cVar1 = *(char *)(long)iVar6;
        cVar2 = *pcVar7;
        cVar5 = cVar2;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        iVar6 = iVar6 + 1;
        cVar5 = cVar1;
        if ((cVar2 != cVar1) ||
           (pcVar7 = (char *)(long)((int)pcVar7 + 1), cVar5 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar5 == cVar2) {
        (*(code *)(long)DAT_ffffffffbfc43990)((char *)(long)(iVar8 + 8),0);
      }
    }
    uVar9 = uVar9 + 1;
    iVar8 = iVar8 + 0x90;
  } while( true );
}

