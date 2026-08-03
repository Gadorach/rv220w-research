/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc53944
 * Function: FUN_ffffffffbfc53944
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

void FUN_ffffffffbfc53944(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 unaff_s0;
  byte *pbVar3;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 *puVar4;
  undefined8 in_ra;
  
  puVar4 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar4[3] = &_gp;
  puVar4[2] = unaff_s2;
  puVar4[1] = unaff_s1;
  *puVar4 = unaff_s0;
  pbVar3 = (byte *)(long)((int)param_1 + 0xe);
  puVar4[4] = in_ra;
  if (pbVar3[9] == 6) {
    lVar2 = (long)((int)param_1 + 0x1e);
    if ((((((*(char *)(param_1 + 0x1e) != -1) || (*(char *)(lVar2 + 1) != -1)) ||
          (*(char *)(lVar2 + 2) != -1)) || (*(char *)(lVar2 + 3) != -1)) &&
        (lVar2 = (*(code *)(long)iRamffffffffbfc55cd4)(lVar2,uRamffffffffbfc55ca4,4), lVar2 != 0))
       || ((lVar2 = (*(code *)(long)iRamffffffffbfc55d5c)(pbVar3,(*pbVar3 & 0xf) << 2,0), lVar2 != 0
           || (iVar1 = iRamffffffffbfc55d1c, *(short *)(param_1 + 0x24) != 0x50)))) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc53a40. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x5b30);
      return;
    }
  }
  else {
    iVar1 = iRamffffffffbfc55d50;
    if (pbVar3[9] != 0x11) {
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc53a68. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(long)iVar1)(param_1,param_2);
  return;
}

