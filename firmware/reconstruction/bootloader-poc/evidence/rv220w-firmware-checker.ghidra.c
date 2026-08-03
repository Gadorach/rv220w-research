/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc22834
 * Function: FUN_ffffffffbfc22834
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

undefined8 FUN_ffffffffbfc22834(void)

{
  uint uVar1;
  int iVar2;
  int iVar5;
  undefined8 uVar3;
  long lVar4;
  undefined8 unaff_s0;
  int iVar6;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar7;
  uint *puVar8;
  undefined8 unaff_s8;
  undefined8 in_ra;
  int iVar9;
  
  iVar9 = (int)&stack0x00000000 + -0x90;
  puVar8 = (uint *)(long)iVar9;
  *(undefined1 **)(puVar8 + 0x1e) = &_gp;
  *(undefined8 *)(puVar8 + 0x1a) = unaff_s3;
  *(undefined8 *)(puVar8 + 0x22) = in_ra;
  iVar2 = DAT_ffffffffbfc436f4;
  pcVar7 = (code *)(long)DAT_ffffffffbfc437c8;
  *(undefined8 *)(puVar8 + 0x20) = unaff_s8;
  *(undefined8 *)(puVar8 + 0x1c) = unaff_s4;
  *(undefined8 *)(puVar8 + 0x16) = unaff_s1;
  *(undefined8 *)(puVar8 + 0x14) = unaff_s0;
  iVar6 = (int)&stack0x00000000 + -0x8c;
  *(undefined8 *)(puVar8 + 0x18) = unaff_s2;
  iVar5 = (*pcVar7)(iVar2 + 0x1080);
  pcVar7 = (code *)(long)DAT_ffffffffbfc43a54;
  *puVar8 = 0;
  iVar9 = iVar9 - (iVar5 + 0x20U & 0xfffffff0);
  (*pcVar7)(iVar6,0,0x20);
  iVar5 = (*(code *)(long)DAT_ffffffffbfc437c8)(iVar2 + 0x1080);
  (*(code *)(long)DAT_ffffffffbfc43a54)(iVar9,0,iVar5 + 2);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1090);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar6,0xffffffffbdc80074,0x20);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x10b0,iVar6);
  (*(code *)(long)DAT_ffffffffbfc43e84)(puVar8,0xffffffffbdc80010,4);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x10d0,*puVar8);
  uVar1 = *puVar8;
  if (uVar1 < 0x2000001) {
    iVar5 = (*(code *)(long)DAT_ffffffffbfc437c8)(iVar2 + 0x1080);
    (*(code *)(long)DAT_ffffffffbfc43e84)(iVar9,uVar1 + 0xbdc7ff80,iVar5 + 2);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x10f0,iVar9);
    uVar3 = (*(code *)(long)DAT_ffffffffbfc437c8)(iVar2 + 0x1080);
    lVar4 = (*(code *)(long)DAT_ffffffffbfc43ab4)(iVar9,iVar2 + 0x1080,uVar3);
    if (lVar4 == 0) {
      return 0;
    }
  }
  return 0xffffffffffffffff;
}

