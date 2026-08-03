/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc235a4
 * Function: thunk_FUN_ffffffffbfc235c8
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Function identity or role inferred conservatively from address, retained strings, command table, callers and hardware register operations.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Function identity or role inferred conservatively from address, retained strings, command table, callers and hardware register operations.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Function identity or role inferred conservatively from address, retained strings, command table, callers and hardware register operations.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Function identity or role inferred conservatively from address, retained strings,
   command table, callers and hardware register operations.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Function identity or role inferred conservatively from address, retained strings,
   command table, callers and hardware register operations.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Function identity or role inferred conservatively from address, retained strings,
   command table, callers and hardware register operations.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

int thunk_FUN_ffffffffbfc235c8(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  
  do {
    if (param_3 == 0) {
      return 0;
    }
    bVar1 = *param_1;
    param_3 = param_3 + -1;
    bVar2 = *param_2;
    param_1 = (byte *)(long)((int)param_1 + 1);
    param_2 = (byte *)(long)((int)param_2 + 1);
  } while ((uint)bVar1 - (uint)bVar2 == 0);
  return (uint)bVar1 - (uint)bVar2;
}

