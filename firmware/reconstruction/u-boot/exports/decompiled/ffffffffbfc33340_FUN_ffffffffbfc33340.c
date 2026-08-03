/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc33340
 * Function: FUN_ffffffffbfc33340
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

undefined8 FUN_ffffffffbfc33340(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 unaff_s0;
  uint uVar4;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar5;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar7[4] = &_gp;
  puVar7[1] = unaff_s1;
  pcVar6 = (code *)(long)DAT_ffffffffbfc43aa8;
  puVar7[5] = in_ra;
  puVar7[3] = unaff_s3;
  puVar7[2] = unaff_s2;
  *puVar7 = unaff_s0;
  lVar1 = (*pcVar6)();
  uVar2 = 0xffffffffffffffff;
  if (lVar1 != 0) {
    pcVar6 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x2d4c);
    iVar5 = 0;
    (*pcVar6)(param_1,0x505,0x3ff);
    (*pcVar6)(param_1,0x620,0x3ff);
    (*pcVar6)(param_1,0x59e,0x3ff);
    (*pcVar6)(param_1,0x505,0);
    (*pcVar6)(param_1,0x500,0);
    do {
      uVar4 = iVar5 << 7;
      pcVar6 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x2d4c);
      iVar5 = iVar5 + 1;
      (*pcVar6)(param_1,uVar4 | 0x10,3);
      (*pcVar6)(param_1,uVar4 | 0xf,0x3fff);
      (*pcVar6)(param_1,uVar4,0);
      (*pcVar6)(param_1,uVar4 | 1,0);
      (*pcVar6)(param_1,uVar4 | 0x12,7);
      (*pcVar6)(param_1,uVar4 | 0x15,1);
      (*pcVar6)(param_1,uVar4 | 0x18,0x11cd);
      (*pcVar6)(param_1,uVar4 | 0x19,0);
    } while (iVar5 != 10);
    iVar5 = 0x600;
    (*pcVar6)(param_1,0x59f,0x3ff);
    do {
      pcVar6 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x2d4c);
      (*pcVar6)(param_1,iVar5,0x900);
      (*pcVar6)(param_1,iVar5 + 10,0x800);
      iVar3 = iVar5 + 0x14;
      iVar5 = iVar5 + 1;
      (*pcVar6)(param_1,iVar3,0x380);
    } while (iVar5 != 0x60a);
    (*pcVar6)(param_1,0x59e,0);
    (*pcVar6)(param_1,0x620,0);
    (*pcVar6)(param_1,0x500,0x3ff);
    iVar5 = 0;
    do {
      iVar3 = iVar5 + 1;
      (*(code *)(long)DAT_ffffffffbfc43f90)(param_1,iVar5);
      iVar5 = iVar3;
    } while (iVar3 != 10);
    iVar5 = 0;
    do {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3030))(param_1,iVar5,0x14,0xe2);
      iVar5 = iVar5 + 1;
    } while (iVar5 != 10);
    iVar5 = 0;
    do {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3030))(param_1,iVar5,4,0xd01);
      iVar5 = iVar5 + 1;
    } while (iVar5 != 10);
    iVar5 = 0;
    do {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3030))(param_1,iVar5,0,0x9140);
      iVar5 = iVar5 + 1;
    } while (iVar5 != 10);
    uVar2 = 0;
  }
  return uVar2;
}

