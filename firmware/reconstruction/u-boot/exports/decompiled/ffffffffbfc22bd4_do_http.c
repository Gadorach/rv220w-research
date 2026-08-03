/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc22bd4
 * Function: do_http
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
 * Recovered from U-Boot command table: command='http', maxargs=1, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='http', maxargs=1, repeatable=1, usage=''. */

void do_http(void)

{
  undefined8 uVar1;
  code *pcVar2;
  int *piVar3;
  undefined8 in_ra;
  
  piVar3 = (int *)(long)((int)&stack0x00000000 + -0x30);
  *(undefined1 **)(piVar3 + 8) = &_gp;
  *(undefined8 *)(piVar3 + 10) = in_ra;
  (*(code *)(long)DAT_ffffffffbfc43878)(1);
  uVar1 = (*(code *)(long)DAT_ffffffffbfc43ce8)();
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1110,uVar1);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1120);
  (*(code *)(long)DAT_ffffffffbfc43e84)(0x3000000,0xffffffffbdc50000,0x10000);
  pcVar2 = (code *)(long)DAT_ffffffffbfc44040;
  *piVar3 = DAT_ffffffffbfc436f4 + -0x50d0;
  piVar3[1] = DAT_ffffffffbfc436f4 + 0x1158;
  piVar3[2] = DAT_ffffffffbfc436f4 + 0x1168;
  (*pcVar2)(0,0,3,piVar3);
  return;
}

