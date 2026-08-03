/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc522dc
 * Function: FUN_ffffffffbfc522dc
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

undefined4 FUN_ffffffffbfc522dc(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar6;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar8;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  long lVar9;
  code *pcVar10;
  long lVar11;
  undefined8 in_ra;
  
  lVar11 = (long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(lVar11 + 0x30) = &_gp;
  *(undefined8 *)(lVar11 + 0x38) = in_ra;
  *(undefined8 *)(lVar11 + 0x28) = unaff_s3;
  pcVar10 = (code *)(long)iRamffffffffbfc55d74;
  *(undefined8 *)(lVar11 + 0x20) = unaff_s2;
  *(undefined8 *)(lVar11 + 0x10) = unaff_s0;
  *(undefined8 *)(lVar11 + 0x18) = unaff_s1;
  uVar6 = (*pcVar10)();
  iVar1 = iRamffffffffbfc55c28;
  pcVar10 = (code *)(long)iRamffffffffbfc55d20;
  *(undefined4 *)((long)iRamffffffffbfc55c28 + 0x6e60) = uVar6;
  lVar3 = (*pcVar10)(param_1,iVar1 + 0x4c10);
  lVar9 = (long)iRamffffffffbfc55c28;
  if (lVar3 != 0) {
    lVar8 = (long)iRamffffffffbfc55c28;
    lVar4 = (*(code *)(long)iRamffffffffbfc55d20)(lVar3,iRamffffffffbfc55c28 + 0x4ba0);
    if (lVar4 != 0) {
      (*(code *)(long)iRamffffffffbfc55d98)
                (lVar11,(int)lVar3 + 0x10,((int)lVar4 - (int)lVar3) + -0x10);
    }
    uVar5 = (*(code *)(long)iRamffffffffbfc55c54)(lVar11);
    iVar1 = iRamffffffffbfc55c28;
    pcVar10 = (code *)(long)iRamffffffffbfc55dd4;
    *(int *)(lVar9 + 0x5e4c) = (int)uVar5;
    (*pcVar10)(iVar1 + 0x4c20,uVar5,uVar5,0x2000400);
    iVar2 = iRamffffffffbfc55c28;
    iVar1 = *(int *)(lVar9 + 0x5e4c);
    pcVar10 = (code *)(long)iRamffffffffbfc55dd4;
    iVar7 = iRamffffffffbfc55c28 + 0x4c50;
    if (iVar1 < 0x10000) {
      *(undefined4 *)(lVar8 + 0x6e5c) = 0xffffffff;
      (*pcVar10)(iVar7);
      return *(undefined4 *)(lVar8 + 0x6e5c);
    }
    pcVar10 = (code *)(long)iRamffffffffbfc55dd4;
    if (0x2000400 < iVar1) {
      *(undefined4 *)(lVar8 + 0x6e5c) = 0xffffffff;
      (*pcVar10)(iVar2 + 0x4c80);
      return *(undefined4 *)(lVar8 + 0x6e5c);
    }
    *(undefined4 *)(lVar8 + 0x6e5c) = 1;
  }
  return *(undefined4 *)((long)iRamffffffffbfc55c28 + 0x6e5c);
}

