/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc14764
 * Function: do_flinfo
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
 * Recovered from U-Boot command table: command='flinfo', maxargs=2, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='flinfo', maxargs=2, repeatable=1, usage=''. */

undefined8 do_flinfo(undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  long lVar2;
  undefined8 unaff_s0;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 in_ra;
  
  puVar4 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar4[1] = &_gp;
  *puVar4 = unaff_s0;
  iVar1 = DAT_ffffffffbfc436f4;
  pcVar3 = (code *)(long)DAT_ffffffffbfc4400c;
  puVar4[2] = in_ra;
  if (param_3 != 1) {
    lVar2 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 4),0,0x10);
    pcVar3 = (code *)(long)DAT_ffffffffbfc4400c;
    iVar1 = DAT_ffffffffbfc436f4;
    if (lVar2 != 1) {
      (*pcVar3)(DAT_ffffffffbfc436f4 + -0x49a0,1);
      return 1;
    }
  }
  (*pcVar3)(iVar1 + -0x49b0,1);
  (*(code *)(long)DAT_ffffffffbfc43c80)(DAT_ffffffffbfc43fc4);
  return 0;
}

