/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc29c78
 * Function: octeon_mdio_write_c22
 * Subsystem: mdio
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: mdio
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Clause-22 Octeon SMI/MDIO write using CSRs near 0x8001180000001800/1808.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: mdio
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Clause-22 Octeon SMI/MDIO write using CSRs near 0x8001180000001800/1808.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Clause-22 Octeon SMI/MDIO write using CSRs near 0x8001180000001800/1808.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: mdio
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Clause-22 Octeon SMI/MDIO write using CSRs near 0x8001180000001800/1808.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: mdio
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Clause-22 Octeon SMI/MDIO write using CSRs near 0x8001180000001800/1808.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Clause-22 Octeon SMI/MDIO write using CSRs near 0x8001180000001800/1808.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

undefined8 octeon_mdio_write_c22(ulong param_1,ulong param_2,undefined2 param_3)

{
  int iVar1;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar2;
  undefined8 unaff_s4;
  undefined8 *puVar3;
  undefined8 in_ra;
  
  puVar3 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar3[5] = &_gp;
  *puVar3 = unaff_s0;
  iVar1 = DAT_ffffffffbfc436f0;
  puVar3[4] = unaff_s4;
  puVar3[3] = unaff_s3;
  puVar3[2] = unaff_s2;
  puVar3[1] = unaff_s1;
  puVar3[6] = in_ra;
  (*(code *)(long)(iVar1 + -0x6504))(&DAT_8001180000001808,param_3);
  iVar2 = 1000;
  (*(code *)(long)(iVar1 + -0x6504))(0x8001180000001800,(param_1 & 0x1f) << 8 | param_2 & 0x1f);
  do {
    (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x64d4))(1000);
    setCopReg(2,param_2 & 0xff,*(undefined4 *)(_DAT_8001180000001808 + 6));
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0xffffffffffffffff;
}

