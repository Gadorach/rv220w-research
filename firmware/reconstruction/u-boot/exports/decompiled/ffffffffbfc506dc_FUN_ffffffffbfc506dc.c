/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc506dc
 * Function: FUN_ffffffffbfc506dc
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

undefined8 FUN_ffffffffbfc506dc(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  long lVar3;
  long lVar4;
  undefined8 unaff_s0;
  int iVar5;
  undefined8 unaff_s1;
  int iVar6;
  uint uVar7;
  undefined8 unaff_s2;
  code *pcVar8;
  int in_k0_lo;
  undefined4 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined4 *)(long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(puVar9 + 10) = &_gp;
  *(undefined8 *)(puVar9 + 0xc) = in_ra;
  pcVar8 = (code *)(long)iRamffffffffbfc55c90;
  *(undefined8 *)(puVar9 + 6) = unaff_s1;
  iVar6 = 0;
  *(undefined8 *)(puVar9 + 4) = unaff_s0;
  iVar5 = 0;
  *(undefined8 *)(puVar9 + 8) = unaff_s2;
  *puVar9 = 0;
  (*pcVar8)(6,0);
  (*(code *)(long)iRamffffffffbfc55c90)(7,1);
  (*(code *)(long)iRamffffffffbfc55cc0)(uRamffffffffbfc55d34,0,0x640);
  (*(code *)(long)iRamffffffffbfc55cd0)();
  (*(code *)(long)iRamffffffffbfc55d98)(iRamffffffffbfc55c64,in_k0_lo + 0x78,6);
  puVar2 = (undefined1 *)(long)iRamffffffffbfc55c64;
  (*(code *)(long)iRamffffffffbfc55dd4)
            (iRamffffffffbfc55c28 + 0x4970,*puVar2,puVar2[1],puVar2[2],puVar2[3],puVar2[4],puVar2[5]
            );
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4998);
  pcVar8 = (code *)(long)iRamffffffffbfc55cec;
  do {
    lVar3 = (*pcVar8)();
    if (lVar3 != 0) {
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x49b8);
      (*(code *)(long)iRamffffffffbfc55da4)();
      return 0xffffffffffffffff;
    }
    if (100 < iVar6) {
      iVar6 = 0;
      (*(code *)(long)iRamffffffffbfc55dac)(6);
      (*(code *)(long)iRamffffffffbfc55dac)(7);
    }
    iVar6 = iVar6 + 1;
    lVar3 = (*(code *)(long)iRamffffffffbfc55dd0)(uRamffffffffbfc55d34,puVar9);
    if (lVar3 == 0) {
      iVar5 = iVar5 + 1;
      (*(code *)(long)iRamffffffffbfc55d00)(uRamffffffffbfc55d34,*puVar9);
      if (iVar5 == 10) {
        iVar5 = 0;
        (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x49c0);
      }
    }
    pcVar8 = (code *)(long)iRamffffffffbfc55cec;
  } while ((*(int *)(long)iRamffffffffbfc55ce4 != 1) || (*(int *)(long)iRamffffffffbfc55d60 != 1));
  (*(code *)(long)iRamffffffffbfc55dd4)
            (iRamffffffffbfc55c28 + 0x49c8,*(undefined4 *)(long)iRamffffffffbfc55d28);
  (*(code *)(long)iRamffffffffbfc55cf4)(0,0xffffffffbdc80000,0xffffffffbfbfffff);
  lVar3 = (*(code *)(long)iRamffffffffbfc55d08)(0xffffffffbdc80000);
  lVar4 = (*(code *)(long)iRamffffffffbfc55d08)(0xffffffffbfbfffff);
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4940,lVar3,lVar4);
  (*(code *)(long)iRamffffffffbfc55d30)(*(int *)(long)iRamffffffffbfc55cd8 + 0x500000,0x100);
  for (; lVar3 <= lVar4; lVar3 = (long)((int)lVar3 + 1)) {
    (*(code *)(long)iRamffffffffbfc55d58)(lVar3,lVar3);
    uVar1 = getCopReg(2,0);
    *(undefined4 *)(lVar3 + 6) = uVar1;
    (*(code *)(long)iRamffffffffbfc55dac)(6);
    (*(code *)(long)iRamffffffffbfc55dac)(7);
  }
  iVar5 = 0x500000;
  (*(code *)(long)iRamffffffffbfc55cf0)(2000000);
  uVar7 = *(uint *)(long)iRamffffffffbfc55cd8;
  while( true ) {
    (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x49e8,uVar7);
    if (uVar7 < 0x20000) break;
    (*(code *)(long)iRamffffffffbfc55d84)(iVar5,iVar5 + -0x42880000,0x20000);
    uVar7 = uVar7 - 0x20000;
    (*(code *)(long)iRamffffffffbfc55dac)(6);
    (*(code *)(long)iRamffffffffbfc55dac)(7);
    iVar5 = iVar5 + 0x20000;
  }
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x49f8,uVar7);
  (*(code *)(long)iRamffffffffbfc55d84)(iVar5,iVar5 + -0x42880000,uVar7);
  (*(code *)(long)iRamffffffffbfc55cf0)(1000000);
  (*(code *)(long)iRamffffffffbfc55c68)();
  (*(code *)(long)iRamffffffffbfc55cbc)();
  return 0;
}

