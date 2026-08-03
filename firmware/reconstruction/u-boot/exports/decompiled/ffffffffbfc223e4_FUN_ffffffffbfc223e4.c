/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc223e4
 * Function: FUN_ffffffffbfc223e4
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

undefined8 FUN_ffffffffbfc223e4(char *param_1,undefined4 *param_2)

{
  char cVar1;
  long lVar2;
  char *pcVar3;
  uint uVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 uVar5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  undefined8 *puVar6;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x60);
  puVar6[8] = &_gp;
  puVar6[9] = unaff_s8;
  puVar6[4] = unaff_s4;
  puVar6[3] = unaff_s3;
  puVar6[10] = in_ra;
  puVar6[7] = unaff_s7;
  puVar6[6] = unaff_s6;
  puVar6[5] = unaff_s5;
  puVar6[2] = unaff_s2;
  puVar6[1] = unaff_s1;
  *puVar6 = unaff_s0;
  do {
    pcVar3 = param_1;
    if (*pcVar3 == '\0') {
      return 10;
    }
    param_1 = (char *)(long)((int)pcVar3 + 1);
  } while (*pcVar3 != 'S');
  cVar1 = pcVar3[1];
  uVar5 = 10;
  if (cVar1 != '\0') {
    lVar2 = (*(code *)(long)(DAT_ffffffffbfc43700 + 0x2360))((int)pcVar3 + 2);
    *param_2 = (int)lVar2;
    if (lVar2 < 0) {
      uVar5 = 0xfffffffffffffffe;
    }
    else {
      uVar4 = (int)cVar1 - 0x30U & 0xff;
      if (uVar4 < 10) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc224b0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar5 = (*(code *)(long)(*(int *)(long)(int)(uVar4 * 4 + DAT_ffffffffbfc436f0 + 0x6500) +
                                -0x403bc920))(uVar4,lVar2);
        return uVar5;
      }
      uVar5 = 0xffffffffffffffff;
    }
  }
  return uVar5;
}

