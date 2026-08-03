/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc29d5c
 * Function: octeon_mdio_read_c22
 * Subsystem: mdio
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: mdio
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Clause-22 Octeon SMI/MDIO read wrapper.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: mdio
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Clause-22 Octeon SMI/MDIO read wrapper.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Clause-22 Octeon SMI/MDIO read wrapper.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: mdio
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Clause-22 Octeon SMI/MDIO read wrapper.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: mdio
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Clause-22 Octeon SMI/MDIO read wrapper.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Clause-22 Octeon SMI/MDIO read wrapper.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

ulong octeon_mdio_read_c22(undefined1 param_1,undefined1 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  code *pcVar3;
  ushort *puVar4;
  undefined8 in_ra;
  
  puVar4 = (ushort *)(long)((int)&stack0x00000000 + -0x30);
  *(undefined1 **)(puVar4 + 0x10) = &_gp;
  *(undefined8 *)(puVar4 + 0xc) = unaff_s1;
  *(undefined8 *)(puVar4 + 8) = unaff_s0;
  pcVar3 = (code *)(long)DAT_ffffffffbfc43df0;
  *(undefined8 *)(puVar4 + 0x14) = in_ra;
  lVar1 = (*pcVar3)(param_1,param_2,puVar4);
  if (lVar1 < 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1708,param_1,param_2);
    uVar2 = 0xffffffffffffffff;
  }
  else {
    uVar2 = (ulong)*puVar4;
  }
  return uVar2;
}

