/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc52124
 * Function: FUN_ffffffffbfc52124
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

void FUN_ffffffffbfc52124(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int *piVar4;
  undefined8 unaff_s2;
  uint *puVar5;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int *piVar6;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar7[5] = &_gp;
  puVar7[1] = unaff_s1;
  puVar7[3] = unaff_s3;
  piVar4 = (int *)(long)iRamffffffffbfc55cac;
  puVar7[4] = unaff_s4;
  iVar1 = *piVar4;
  puVar7[2] = unaff_s2;
  *puVar7 = unaff_s0;
  puVar7[6] = in_ra;
  puVar5 = (uint *)(long)iRamffffffffbfc55d90;
  piVar6 = (int *)(long)iRamffffffffbfc55c4c;
  if (iVar1 == 1) {
    (*(code *)(long)iRamffffffffbfc55d98)(*piVar6 + *puVar5,param_1,param_2);
    uVar3 = *(uint *)((long)iRamffffffffbfc55c28 + 0x5e4c);
    UNRECOVERED_JUMPTABLE = (code *)(long)iRamffffffffbfc55dc4;
    uVar2 = (int)param_2 + *puVar5;
    *puVar5 = uVar2;
    if (uVar3 <= uVar2) {
      iVar1 = *piVar6;
      *piVar4 = 2;
      *(undefined4 *)(long)iRamffffffffbfc55c98 = 1;
      uVar3 = (*UNRECOVERED_JUMPTABLE)(iVar1,uVar2);
      iVar1 = iRamffffffffbfc55c28;
      *(uint *)(long)iRamffffffffbfc55d28 = uVar3;
      UNRECOVERED_JUMPTABLE = (code *)(long)iRamffffffffbfc55dd4;
      *(undefined4 *)(long)iRamffffffffbfc55ce4 = 1;
      *puVar5 = uVar3;
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc52214. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(iVar1 + 0x59b0);
      return;
    }
  }
  else if (iVar1 == 2) {
    *piVar4 = 3;
    *(undefined4 *)(long)iRamffffffffbfc55ce4 = 1;
  }
  return;
}

