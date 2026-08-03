/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1827c
 * Function: rv220w_bcm53115_set_enabled
 * Subsystem: bcm53115-switch
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: BCM53115 enable/disable helper. Writes page 0 registers 1 through 4 through the Broadcom pseudo-PHY transaction helper and delays. Exact bit-0x20 semantics remain intentionally unnamed.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: BCM53115 enable/disable helper. Writes page 0 registers 1 through 4 through the Broadcom pseudo-PHY transaction helper and delays. Exact bit-0x20 semantics remain intentionally unnamed.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: BCM53115 enable/disable helper. Writes page 0 registers 1 through 4 through the Broadcom pseudo-PHY transaction helper and delays. Exact bit-0x20 semantics remain intentionally unnamed.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: BCM53115 enable/disable helper. Writes page 0 registers 1 through 4 through the
   Broadcom pseudo-PHY transaction helper and delays. Exact bit-0x20 semantics remain intentionally
   unnamed.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: BCM53115 enable/disable helper. Writes page 0 registers 1 through 4 through the
   Broadcom pseudo-PHY transaction helper and delays. Exact bit-0x20 semantics remain intentionally
   unnamed.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: BCM53115 enable/disable helper. Writes page 0 registers 1 through 4 through the
   Broadcom pseudo-PHY transaction helper and delays. Exact bit-0x20 semantics remain intentionally
   unnamed.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void rv220w_bcm53115_set_enabled(long param_1)

{
  undefined8 unaff_s0;
  int iVar1;
  undefined8 *puVar2;
  undefined8 in_ra;
  
  puVar2 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar2[3] = &_gp;
  puVar2[4] = in_ra;
  puVar2[2] = unaff_s0;
  if (param_1 == 0) {
    iVar1 = 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2bf0);
    *puVar2 = 0x20;
    do {
      (*(code *)(long)DAT_ffffffffbfc4405c)(0,iVar1,puVar2);
      iVar1 = iVar1 + 1;
    } while (iVar1 != 5);
  }
  else {
    iVar1 = 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2c08);
    *puVar2 = 0;
    do {
      (*(code *)(long)DAT_ffffffffbfc4405c)(0,iVar1,puVar2);
      iVar1 = iVar1 + 1;
    } while (iVar1 != 5);
  }
  (*(code *)(long)DAT_ffffffffbfc43b18)(2000);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2bd8);
  return;
}

