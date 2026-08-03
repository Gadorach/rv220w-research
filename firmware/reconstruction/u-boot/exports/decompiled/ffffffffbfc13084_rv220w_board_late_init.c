/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc13084
 * Function: rv220w_board_late_init
 * Subsystem: board-init
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: board-init
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: RV220W late board/recovery initialization. Selects octeth0, initializes board networking/switch state, configures GPIO 1 as an input, reads it, prints PUSH_BUTTON, and enters recovery logic when asserted low.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: board-init
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: RV220W late board/recovery initialization. Selects octeth0, initializes board networking/switch state, configures GPIO 1 as an input, reads it, prints PUSH_BUTTON, and enters recovery logic when asserted low.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: RV220W late board/recovery initialization. Selects octeth0, initializes board networking/switch state, configures GPIO 1 as an input, reads it, prints PUSH_BUTTON, and enters recovery logic when asserted low.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: board-init
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: RV220W late board/recovery initialization. Selects octeth0, initializes board
   networking/switch state, configures GPIO 1 as an input, reads it, prints PUSH_BUTTON, and enters
   recovery logic when asserted low.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: board-init
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: RV220W late board/recovery initialization. Selects octeth0, initializes board
   networking/switch state, configures GPIO 1 as an input, reads it, prints PUSH_BUTTON, and enters
   recovery logic when asserted low.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: RV220W late board/recovery initialization. Selects octeth0, initializes board
   networking/switch state, configures GPIO 1 as an input, reads it, prints PUSH_BUTTON, and enters
   recovery logic when asserted low.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void rv220w_board_late_init(void)

{
  long lVar1;
  undefined8 unaff_s0;
  undefined8 *puVar2;
  undefined8 in_ra;
  
  puVar2 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar2[1] = &_gp;
  puVar2[2] = in_ra;
  *puVar2 = unaff_s0;
  (*(code *)(long)DAT_ffffffffbfc43b14)
            (DAT_ffffffffbfc436f4 + -23000,DAT_ffffffffbfc436f4 + -0x52a0);
  (*(code *)(long)DAT_ffffffffbfc439ec)();
  (*(code *)(long)DAT_ffffffffbfc43920)(1);
  (*(code *)(long)DAT_ffffffffbfc43ca8)(1);
  lVar1 = (*(code *)(long)DAT_ffffffffbfc439cc)(1);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5298,lVar1);
  if (lVar1 == 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5280);
    (*(code *)(long)DAT_ffffffffbfc43a0c)();
    (*(code *)(long)DAT_ffffffffbfc43b8c)();
  }
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43a2c)();
  if (lVar1 < 0) {
    (*(code *)(long)DAT_ffffffffbfc439b0)();
  }
  (*(code *)(long)DAT_ffffffffbfc43b14)
            (DAT_ffffffffbfc436f4 + -0x5260,DAT_ffffffffbfc436f0 + 0x63b0);
  return;
}

