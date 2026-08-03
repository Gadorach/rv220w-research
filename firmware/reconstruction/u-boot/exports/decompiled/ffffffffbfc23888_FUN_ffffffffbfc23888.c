/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc23888
 * Function: FUN_ffffffffbfc23888
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

ulong FUN_ffffffffbfc23888(ulong param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  int iVar4;
  int iVar5;
  undefined1 *puVar3;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 unaff_s0;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar9[1] = &_gp;
  *puVar9 = unaff_s0;
  puVar9[2] = in_ra;
  if ((param_3 < 8) || ((param_2 & 7) != (param_1 & 7))) {
    (*(code *)(long)DAT_ffffffffbfc437d8)();
  }
  else {
    iVar5 = 0;
    iVar2 = 8 - (int)(param_2 & 7);
    uVar8 = (int)param_3 - iVar2 & 7;
    uVar6 = (int)param_3 - (iVar2 + uVar8);
    while( true ) {
      iVar1 = (int)param_2 + iVar5;
      iVar4 = (int)param_1 + iVar5;
      if (iVar5 == iVar2) break;
      iVar5 = iVar5 + 1;
      *(undefined1 *)(long)iVar4 = *(undefined1 *)(long)iVar1;
    }
    iVar5 = (int)param_2 + iVar2;
    iVar2 = (int)param_1 + iVar2;
    uVar7 = uVar6;
    if (7 < uVar6) {
      do {
        uVar6 = uVar6 - 8;
        *(undefined8 *)(long)iVar2 = *(undefined8 *)(long)iVar5;
        iVar5 = iVar5 + 8;
        iVar2 = iVar2 + 8;
        uVar7 = 0;
      } while (uVar6 != 0);
    }
    iVar5 = iVar5 + uVar7;
    iVar2 = iVar2 + uVar7;
    while( true ) {
      puVar3 = (undefined1 *)(long)iVar5;
      uVar8 = uVar8 - 1;
      if (uVar8 == 0xffffffff) break;
      iVar5 = iVar5 + 1;
      *(undefined1 *)(long)iVar2 = *puVar3;
      iVar2 = iVar2 + 1;
    }
  }
  return param_1;
}

