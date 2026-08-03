/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc30cf4
 * Function: FUN_ffffffffbfc30cf4
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

void FUN_ffffffffbfc30cf4(ulong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar3;
  undefined8 unaff_s2;
  ulong uVar4;
  undefined8 unaff_s3;
  ulong uVar5;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar7[6] = &_gp;
  puVar7[3] = unaff_s3;
  iVar1 = DAT_ffffffffbfc436f0;
  puVar7[1] = unaff_s1;
  uVar4 = param_1 >> 4 & 1;
  puVar7[7] = in_ra;
  uVar5 = param_1 & 0xf;
  puVar7[5] = unaff_s5;
  puVar7[4] = unaff_s4;
  *puVar7 = unaff_s0;
  puVar7[2] = unaff_s2;
  uVar2 = (*(code *)(long)(iVar1 + 0x664))(uVar5,uVar4);
  pcVar6 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc);
  (*pcVar6)(uVar2,1);
  uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x690))(uVar5,uVar4);
  (*pcVar6)(uVar2,0x200);
  uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x638))(uVar5,uVar4);
  (*pcVar6)(uVar2,0x2000);
  lVar3 = (param_1 >> 4 & 1) * 0x8000000;
  uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5e0))(uVar5,uVar4);
  (*pcVar6)(uVar2,0xe);
  uVar4 = (ulong)(1 << (int)uVar5);
  (*pcVar6)((ulong *)(lVar3 + -0x7ffee7ff4fffffc0),uVar4 | *(ulong *)(lVar3 + -0x7ffee7ff4fffffc0));
  (*pcVar6)(&DAT_80011800b0000008 + lVar3,uVar4 | *(ulong *)(&DAT_80011800b0000008 + lVar3));
  (*pcVar6)(&DAT_80011800b0000000 + lVar3,uVar4 | *(ulong *)(&DAT_80011800b0000000 + lVar3));
  (*pcVar6)(uVar2,0xf);
  return;
}

