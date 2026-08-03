/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc543a8
 * Function: FUN_ffffffffbfc543a8
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void FUN_ffffffffbfc543a8(long param_1,undefined8 param_2)

{
  undefined2 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar4;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar6[4] = &_gp;
  puVar6[3] = unaff_s3;
  puVar6[2] = unaff_s2;
  puVar6[1] = unaff_s1;
  lVar4 = (long)((int)param_1 + 0x22);
  puVar6[5] = in_ra;
  *puVar6 = unaff_s0;
  if (*(short *)(lVar4 + 6) == -1) {
    *(undefined1 *)(lVar4 + 6) = 0;
    *(undefined1 *)(lVar4 + 7) = 0;
  }
  if (CONCAT11(*(undefined1 *)(param_1 + 0x22),*(undefined1 *)(lVar4 + 1)) == 0x44) {
    lVar3 = (long)((int)param_1 + 0xe);
    pcVar5 = (code *)(long)iRamffffffffbfc55cb0;
    if (*(short *)(lVar4 + 2) == 0x43) {
      uVar1 = *(undefined2 *)(lVar4 + 4);
      *(char *)(lVar3 + 3) = (char)uVar1;
      *(char *)(lVar3 + 2) = (char)((ushort)uVar1 >> 8);
      uVar1 = *(undefined2 *)(lVar4 + 4);
      uVar2 = (*pcVar5)(lVar3);
      lVar4 = (*(code *)(long)iRamffffffffbfc55d5c)(lVar4,uVar1,uVar2);
      if (lVar4 == 0) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc544ac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(long)iRamffffffffbfc55d2c)(param_1,param_2);
        return;
      }
    }
  }
  return;
}

