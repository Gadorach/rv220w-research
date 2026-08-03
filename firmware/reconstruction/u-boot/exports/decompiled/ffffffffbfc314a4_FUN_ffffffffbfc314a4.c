/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc314a4
 * Function: FUN_ffffffffbfc314a4
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

undefined8 FUN_ffffffffbfc314a4(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong *puVar4;
  ulong *puVar5;
  undefined8 uVar6;
  undefined8 unaff_s0;
  ulong uVar7;
  ulong uVar8;
  undefined8 unaff_s1;
  ulong uVar9;
  ulong uVar10;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar11;
  undefined8 *puVar12;
  undefined8 in_ra;
  
  puVar12 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar12[8] = &_gp;
  puVar12[9] = in_ra;
  puVar12[5] = unaff_s5;
  pcVar11 = (code *)(long)DAT_ffffffffbfc43fb0;
  puVar12[4] = unaff_s4;
  puVar12[3] = unaff_s3;
  puVar12[2] = unaff_s2;
  *puVar12 = unaff_s0;
  puVar12[7] = unaff_s7;
  puVar12[6] = unaff_s6;
  puVar12[1] = unaff_s1;
  uVar2 = (*pcVar11)();
  uVar3 = (*(code *)(long)DAT_ffffffffbfc43dd0)(param_1);
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1344))(uVar2,uVar3);
  puVar4 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1160))(uVar3,uVar2);
  uVar7 = *puVar4;
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec))(puVar4,uVar7 & 0xfffffffffffffffe);
  uVar8 = *puVar4;
  if ((uVar8 & 0x3000) != 0x3000) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x21c0,uVar2,uVar3);
    do {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x131c))(1000);
      uVar8 = *puVar4;
    } while ((uVar8 & 0x3000) != 0x3000);
  }
  puVar5 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x123c))(uVar3,uVar2);
  uVar9 = *puVar5;
  uVar1 = (ulong)((param_2 & 0x80000) == 0) << 0xb;
  uVar10 = uVar9 & 0xfffffffffffff7ff | uVar1;
  if ((param_2 & 0x80000) != 0) {
    uVar8 = uVar8 & 0xfffffffffffffffb | (param_2 >> 0x12 & 1) << 2;
  }
  param_2 = param_2 & 0x3ffff;
  if (param_2 == 100) {
    uVar8 = uVar8 & 0xfffffffffffffefd;
    uVar10 = 5;
LAB_ffffffffbfc31630:
    uVar8 = uVar8 & 0xfffffffffffffff7;
    uVar10 = uVar9 & 0xfffffffffffff780 | uVar1 | uVar10;
    uVar6 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x11b8))(uVar3,uVar2);
    pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec);
    (*pcVar11)(uVar6,0x40);
    uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x118c))(uVar3,uVar2);
    uVar3 = 0;
  }
  else {
    if (param_2 != 1000) {
      if (param_2 != 10) goto LAB_ffffffffbfc316e4;
      uVar8 = uVar8 & 0xfffffffffffffffd | 0x100;
      uVar10 = 0x19;
      goto LAB_ffffffffbfc31630;
    }
    uVar10 = uVar9 & 0xfffffffffffff780 | uVar1 | 1;
    uVar8 = uVar8 & 0xfffffffffffffeff | 10;
    uVar6 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x11b8))(uVar3,uVar2);
    pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec);
    (*pcVar11)(uVar6,0x200);
    uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x118c))(uVar3,uVar2);
    uVar3 = 0x2000;
  }
  (*pcVar11)(uVar2,uVar3);
LAB_ffffffffbfc316e4:
  pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec);
  (*pcVar11)(puVar5,uVar10);
  (*pcVar11)(puVar4,uVar8);
  (*pcVar11)(puVar4,*puVar4 & 0xfffffffffffffffe | uVar7 & 1);
  return 0;
}

