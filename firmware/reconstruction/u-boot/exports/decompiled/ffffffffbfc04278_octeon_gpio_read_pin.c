/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc04278
 * Function: octeon_gpio_read_pin
 * Subsystem: gpio-button
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: gpio-button
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Reads one Octeon GPIO input bit from the GPIO RX-data CSR.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: gpio-button
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Reads one Octeon GPIO input bit from the GPIO RX-data CSR.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Reads one Octeon GPIO input bit from the GPIO RX-data CSR.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: gpio-button
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Reads one Octeon GPIO input bit from the GPIO RX-data CSR.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: gpio-button
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Reads one Octeon GPIO input bit from the GPIO RX-data CSR.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Reads one Octeon GPIO input bit from the GPIO RX-data CSR.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

uint octeon_gpio_read_pin(long param_1)

{
  return (uint)(_DAT_8001070000000880 >> param_1) & 1;
}

