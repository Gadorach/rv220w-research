/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc33f88
 * Function: FUN_ffffffffbfc33f88
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

undefined8 FUN_ffffffffbfc33f88(undefined8 param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar4;
  long unaff_s4;
  undefined8 unaff_s5;
  int iVar5;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar7[6] = &_gp;
  puVar7[7] = in_ra;
  puVar7[5] = unaff_s5;
  pcVar6 = (code *)(long)DAT_ffffffffbfc43c60;
  puVar7[4] = unaff_s4;
  special2(param_1,unaff_s4,0x1b,0x32);
  puVar7[3] = unaff_s3;
  puVar7[2] = unaff_s2;
  puVar7[1] = unaff_s1;
  *puVar7 = unaff_s0;
  lVar2 = (*pcVar6)();
  uVar1 = *(uint *)(lVar2 + 0x38);
  iVar5 = DAT_ffffffffbfc436f0 + 0x3798;
  (*(code *)(long)iVar5)(unaff_s4 + -0x7ffee7ff6ffffcb8,0x830);
  lVar2 = ((ulong)(long)(int)((ulong)uVar1 * 0x10624dd3 >> 0x20) >> 6) * 100;
  iVar4 = DAT_ffffffffbfc436f0 + 0x37c8;
  (*(code *)(long)iVar4)(lVar2);
  (*(code *)(long)iVar5)(unaff_s4 + -0x7ffee7ff6ffffcb8,0x831);
  (*(code *)(long)iVar4)(lVar2);
  lVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3620))(0x30d0300);
  lVar3 = 3;
  if (lVar2 == 0) {
    lVar3 = 8;
  }
  iVar4 = DAT_ffffffffbfc436f0 + 0x3798;
  (*(code *)(long)iVar4)(unaff_s4 + -0x7ffee7ff6ffffca0,lVar3 << 2 | 0x303);
  (*(code *)(long)iVar4)(unaff_s4 + -0x7ffee7ff6ffffc98,0);
  return 0;
}

