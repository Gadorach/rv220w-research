/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc513f0
 * Function: FUN_ffffffffbfc513f0
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

undefined8 FUN_ffffffffbfc513f0(undefined8 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 unaff_s0;
  code *pcVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar9[1] = &_gp;
  *puVar9 = unaff_s0;
  iVar5 = iRamffffffffbfc55c28;
  pcVar8 = (code *)(long)iRamffffffffbfc55dd4;
  puVar9[2] = in_ra;
  (*pcVar8)(iVar5 + 0x4b68);
  (*(code *)(long)iRamffffffffbfc55d98)(iRamffffffffbfc55ca0,0xffffffffbdc6ff9a,0x46);
  iVar5 = iRamffffffffbfc55ca0;
  uVar3 = _DAT_ffffffffbfbffff2;
  lVar6 = (long)iRamffffffffbfc55ca0;
  uVar1 = (undefined1)_DAT_ffffffffbfbffff0;
  *(char *)(lVar6 + 0x2d) = (char)((ushort)_DAT_ffffffffbfbffff0 >> 8);
  *(undefined1 *)(lVar6 + 0x2e) = uVar1;
  uVar4 = _DAT_ffffffffbfbffff4;
  *(char *)(lVar6 + 0x31) = (char)((ushort)uVar3 >> 8);
  uVar1 = *(undefined1 *)(lVar6 + 0x32);
  *(char *)(lVar6 + 0x32) = (char)uVar3;
  pcVar8 = (code *)(long)iRamffffffffbfc55d9c;
  *(char *)(lVar6 + 0x39) = (char)(uVar4 >> 8);
  uVar2 = *(undefined1 *)(lVar6 + 0x3a);
  *(char *)(lVar6 + 0x3a) = (char)uVar4;
  uVar7 = (*pcVar8)(param_1,iVar5 + 7,0x38,uVar2,uVar4 >> 8,uVar1);
  (*(code *)(long)iRamffffffffbfc55dcc)(uVar7,0x50);
  return 0;
}

