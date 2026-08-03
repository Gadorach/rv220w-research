/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc52490
 * Function: FUN_ffffffffbfc52490
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

void FUN_ffffffffbfc52490(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  code *pcVar4;
  long lVar5;
  undefined8 in_ra;
  int iVar6;
  
  iVar6 = (int)&stack0x00000000 + -0x420;
  lVar5 = (long)iVar6;
  *(undefined1 **)(lVar5 + 0x410) = &_gp;
  *(undefined8 *)(lVar5 + 0x418) = in_ra;
  *(undefined8 *)(lVar5 + 0x408) = unaff_s1;
  iVar1 = iRamffffffffbfc55c28;
  iVar2 = iRamffffffffbfc55c28 + 0x4ca8;
  pcVar4 = (code *)(long)iRamffffffffbfc55c9c;
  iVar3 = iRamffffffffbfc55c28 + 0x4cb8;
  *(undefined8 *)(lVar5 + 0x400) = unaff_s0;
  iVar1 = (*pcVar4)((int)&stack0x00000000 + -0x3ea,iVar2,iVar3,200,iVar1 + 0x4cc8);
  iVar2 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar6 + iVar1 + 0x36,iRamffffffffbfc55c28 + 0x4cd0);
  iVar2 = iVar1 + 0x36 + iVar2;
  iVar1 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar6 + iVar2,iRamffffffffbfc55c28 + 0x4cf0);
  iVar2 = iVar2 + iVar1;
  iVar1 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar6 + iVar2,iRamffffffffbfc55c28 + 0x4d38);
  iVar2 = iVar2 + iVar1;
  iVar1 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar6 + iVar2,iRamffffffffbfc55c28 + 0x4d70);
  iVar2 = iVar2 + iVar1;
  iVar1 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar6 + iVar2,iRamffffffffbfc55c28 + 0x4d80);
  iVar2 = iVar2 + iVar1;
  iVar1 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar6 + iVar2,iRamffffffffbfc55c28 + 0x4dc8);
  iVar2 = iVar2 + iVar1;
  iVar1 = (*(code *)(long)iRamffffffffbfc55c9c)(iVar6 + iVar2,iRamffffffffbfc55c28 + 0x4df8);
  (*(code *)(long)iRamffffffffbfc55d04)(param_1,lVar5,iVar2 + iVar1,0x18,0);
  return;
}

