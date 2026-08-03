/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc035bc
 * Function: octeon_gpio_set_mask
 * Subsystem: gpio-button
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: gpio-button
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Writes a one-bit mask to an Octeon GPIO set/clear control CSR; exact set-versus-clear naming is constrained by caller context.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: gpio-button
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Writes a one-bit mask to an Octeon GPIO set/clear control CSR; exact set-versus-clear naming is constrained by caller context.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Writes a one-bit mask to an Octeon GPIO set/clear control CSR; exact set-versus-clear naming is constrained by caller context.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: gpio-button
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Writes a one-bit mask to an Octeon GPIO set/clear control CSR; exact
   set-versus-clear naming is constrained by caller context.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: gpio-button
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Writes a one-bit mask to an Octeon GPIO set/clear control CSR; exact
   set-versus-clear naming is constrained by caller context.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Writes a one-bit mask to an Octeon GPIO set/clear control CSR; exact
   set-versus-clear naming is constrained by caller context.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void octeon_gpio_set_mask(uint param_1)

{
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x30b8))(&DAT_8001070000000890,1 << (param_1 & 0x1f));
  return;
}

