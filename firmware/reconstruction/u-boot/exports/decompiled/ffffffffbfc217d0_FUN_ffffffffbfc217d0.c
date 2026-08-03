/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc217d0
 * Function: FUN_ffffffffbfc217d0
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

void FUN_ffffffffbfc217d0(long param_1)

{
  int iVar1;
  
  if (param_1 == 8) {
    iVar1 = DAT_ffffffffbfc436f4 + 0xef8;
  }
  else if (param_1 < 9) {
    if (param_1 == 1) {
      iVar1 = DAT_ffffffffbfc436f4 + 0xe98;
    }
    else {
      if (param_1 < 2) {
        if (param_1 == 0) {
          return;
        }
LAB_ffffffffbfc218c8:
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + 0xfb0,DAT_ffffffffbfc436f4 + 0xfc8,0xdd,param_1);
        return;
      }
      if (param_1 == 2) {
        iVar1 = DAT_ffffffffbfc436f4 + 0xeb8;
      }
      else {
        if (param_1 != 4) goto LAB_ffffffffbfc218c8;
        iVar1 = DAT_ffffffffbfc436f4 + 0xed0;
      }
    }
  }
  else if (param_1 == 0x20) {
    iVar1 = DAT_ffffffffbfc436f4 + 0xf50;
  }
  else if (param_1 < 0x21) {
    if (param_1 != 0x10) goto LAB_ffffffffbfc218c8;
    iVar1 = DAT_ffffffffbfc436f4 + 0xf18;
  }
  else if (param_1 == 0x40) {
    iVar1 = DAT_ffffffffbfc436f4 + 0xf70;
  }
  else {
    if (param_1 != 0x80) goto LAB_ffffffffbfc218c8;
    iVar1 = DAT_ffffffffbfc436f4 + 0xf88;
  }
  (*(code *)(long)DAT_ffffffffbfc43e38)(iVar1);
  return;
}

