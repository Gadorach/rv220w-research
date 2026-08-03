/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc31904
 * Function: FUN_ffffffffbfc31904
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

undefined8 FUN_ffffffffbfc31904(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar8;
  undefined8 uVar4;
  long lVar5;
  ulong *puVar6;
  undefined8 uVar7;
  long extraout_v1;
  ulong uVar9;
  undefined8 unaff_s0;
  int iVar10;
  undefined8 unaff_s1;
  ulong uVar11;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  ulong *puVar12;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar13;
  undefined8 *puVar14;
  undefined8 in_ra;
  
  puVar14 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar14[8] = &_gp;
  puVar14[9] = in_ra;
  puVar14[6] = unaff_s6;
  pcVar13 = (code *)(long)DAT_ffffffffbfc43d30;
  puVar14[4] = unaff_s4;
  puVar14[2] = unaff_s2;
  puVar14[7] = unaff_s7;
  puVar14[5] = unaff_s5;
  puVar14[3] = unaff_s3;
  puVar14[1] = unaff_s1;
  *puVar14 = unaff_s0;
  iVar8 = (*pcVar13)();
  (*(code *)(long)DAT_ffffffffbfc43d60)(param_1,iVar8);
  uVar3 = special2(param_1,extraout_v1,0x1b,0x32);
  puVar12 = (ulong *)(&DAT_80011800080007f8 + extraout_v1);
  uVar9 = *puVar12;
  uVar2 = getCopReg(2,1);
  *(undefined4 *)(uVar9 + 5) = uVar2;
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec))(puVar12,uVar9 | 2);
  for (iVar10 = 0; iVar10 < iVar8; iVar10 = iVar10 + 1) {
    uVar4 = (*(code *)(long)DAT_ffffffffbfc43b94)(param_1,iVar10);
    lVar5 = (*(code *)(long)DAT_ffffffffbfc43c60)();
    uVar1 = *(uint *)(lVar5 + 0x38);
    puVar6 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1160))(iVar10,param_1);
    pcVar13 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec);
    (*pcVar13)(puVar6,*puVar6 & 0xfffffffffffffffe);
    uVar11 = *puVar12;
    puVar6 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1210))(iVar10,param_1);
    uVar9 = special2((ulong)(long)(int)((ulong)uVar1 * 0x431bde83 >> 0x20) >> 0x12,10000,0,3);
    setCopReg(2,uVar3,*(undefined4 *)(uVar11 + 0x10));
    (*pcVar13)(puVar6,*puVar6 & 0xffffffffffff0000 | uVar9 >> 10 & 0xffff);
    puVar6 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x11e4))(iVar10,param_1);
    (*pcVar13)(puVar6,*puVar6 & 0xffffffffffffce1f | 0x1e0);
    uVar7 = (*(code *)(long)DAT_ffffffffbfc43d9c)(uVar4);
    (*(code *)(long)DAT_ffffffffbfc438c0)(uVar4,uVar7);
  }
  for (iVar10 = 0; iVar10 < iVar8; iVar10 = iVar10 + 1) {
    puVar12 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1160))(iVar10,param_1);
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec))(puVar12,*puVar12 | 1);
  }
  return 0;
}

