/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc51fec
 * Function: FUN_ffffffffbfc51fec
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

void FUN_ffffffffbfc51fec(undefined1 *param_1,uint param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  bool bVar3;
  uint uVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined1 *puVar5;
  int iVar6;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar7;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  code *pcVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar9[6] = &_gp;
  puVar9[2] = unaff_s2;
  iVar6 = iRamffffffffbfc55c28;
  pcVar8 = (code *)(long)iRamffffffffbfc55dd4;
  *puVar9 = unaff_s0;
  puVar9[7] = in_ra;
  puVar9[5] = unaff_s5;
  puVar9[4] = unaff_s4;
  puVar9[3] = unaff_s3;
  puVar9[1] = unaff_s1;
  (*pcVar8)(iVar6 + 0x4bd8);
  uVar4 = param_2;
  if ((int)param_2 < 0) {
    uVar4 = param_2 + 0xf;
  }
  param_2 = param_2 & 0x8000000f;
  if ((int)param_2 < 0) {
    param_2 = (param_2 - 1 | 0xfffffff0) + 1;
  }
  for (iVar6 = 0; iVar6 < (int)uVar4 >> 4; iVar6 = iVar6 + 1) {
    iVar7 = 0;
    puVar5 = param_1;
    do {
      iVar7 = iVar7 + 1;
      uVar2 = *puVar5;
      puVar1 = puVar5 + 1;
      puVar5 = (undefined1 *)(long)((int)puVar5 + 2);
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4bf0,uVar2,*puVar1);
    } while (iVar7 != 8);
    param_1 = (undefined1 *)(long)((int)param_1 + 0x10);
    (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x59b0);
  }
  iVar6 = 0;
  while( true ) {
    bVar3 = (int)param_2 / 2 <= iVar6;
    iVar6 = iVar6 + 1;
    if (bVar3) break;
    uVar2 = *param_1;
    puVar5 = param_1 + 1;
    param_1 = (undefined1 *)(long)((int)param_1 + 2);
    (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4bf0,uVar2,*puVar5);
  }
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc5211c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x59b0);
  return;
}

