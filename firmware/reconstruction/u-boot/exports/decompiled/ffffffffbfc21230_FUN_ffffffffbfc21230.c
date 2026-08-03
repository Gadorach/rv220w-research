/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc21230
 * Function: FUN_ffffffffbfc21230
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

void FUN_ffffffffbfc21230(void)

{
  int iVar1;
  int iVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int *piVar3;
  code *pcVar4;
  code *pcVar5;
  long in_k0;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar6[2] = &_gp;
  puVar6[1] = unaff_s1;
  *puVar6 = unaff_s0;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43e1c;
  puVar6[3] = in_ra;
  piVar3 = (int *)(long)DAT_ffffffffbfc43d04;
  iVar2 = (*pcVar4)(0x20000);
  iVar1 = DAT_ffffffffbfc436f4;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43e38;
  *piVar3 = iVar2;
  iVar2 = *(int *)(in_k0 + 0x20);
  pcVar5 = (code *)(long)DAT_ffffffffbfc43f5c;
  *(undefined4 *)(long)DAT_ffffffffbfc43dbc = DAT_ffffffffbfc43808;
  if (iVar2 == 0) {
    (*pcVar4)();
    (*(code *)(long)DAT_ffffffffbfc43a54)(*piVar3,0,0x20000);
    (*(code *)(long)DAT_ffffffffbfc43e84)(*piVar3 + 4,DAT_ffffffffbfc43c4c,0x24a);
    (*(code *)(long)DAT_ffffffffbfc43a58)();
    *(undefined4 *)(in_k0 + 0x20) = 1;
  }
  else {
    (*pcVar5)(iVar1 + 0xe28);
  }
  *(int *)(in_k0 + 0x1c) = *(int *)(long)DAT_ffffffffbfc43d04 + 4;
  return;
}

