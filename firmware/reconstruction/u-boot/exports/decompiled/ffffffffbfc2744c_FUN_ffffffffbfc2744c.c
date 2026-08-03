/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2744c
 * Function: FUN_ffffffffbfc2744c
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

void FUN_ffffffffbfc2744c(void)

{
  undefined8 unaff_s0;
  int iVar1;
  code *pcVar2;
  byte *pbVar3;
  undefined8 in_ra;
  
  pbVar3 = (byte *)(long)((int)&stack0x00000000 + -0x30);
  *(undefined1 **)(pbVar3 + 0x18) = &_gp;
  *(undefined8 *)(pbVar3 + 0x20) = in_ra;
  *(undefined8 *)(pbVar3 + 0x10) = unaff_s0;
  iVar1 = (int)&stack0x00000000 + -0x2e;
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1520);
  pcVar2 = (code *)(long)DAT_ffffffffbfc43f28;
  *pbVar3 = 0x8b;
  (*pcVar2)(0,0xe,pbVar3,1);
  pcVar2 = (code *)(long)DAT_ffffffffbfc43f28;
  *pbVar3 = 0x4b;
  (*pcVar2)(0,0x5d,pbVar3,1);
  pcVar2 = (code *)(long)DAT_ffffffffbfc43f28;
  pbVar3[2] = 1;
  pbVar3[3] = 0x1e;
  (*pcVar2)(0x31,2,iVar1,2);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0x31,4,iVar1,2);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0x31,6,iVar1,2);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0x31,8,iVar1,2);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0x31,0x10,iVar1,2);
  pcVar2 = (code *)(long)DAT_ffffffffbfc43f28;
  pbVar3[2] = 0;
  pbVar3[3] = 0x21;
  (*pcVar2)(0x31,0,iVar1,2);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0x31,10,iVar1,2);
  pcVar2 = (code *)(long)DAT_ffffffffbfc43f28;
  *pbVar3 = 0;
  (*pcVar2)(0,0,pbVar3,1);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0,1,pbVar3,1);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0,2,pbVar3,1);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0,3,pbVar3,1);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0,4,pbVar3,1);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0,5,pbVar3,1);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0,6,pbVar3,1);
  (*(code *)(long)DAT_ffffffffbfc43f28)(0,7,pbVar3,1);
  (*(code *)(long)DAT_ffffffffbfc437ac)(0,0xb,pbVar3);
  pcVar2 = (code *)(long)DAT_ffffffffbfc43f28;
  *pbVar3 = *pbVar3 & 0xfc | 2;
  (*pcVar2)(0,0xb,pbVar3,1);
  pcVar2 = (code *)(long)DAT_ffffffffbfc43f28;
  pbVar3[2] = 0x2c;
  pbVar3[3] = 0;
  (*pcVar2)(0,0x12,iVar1,2);
  return;
}

