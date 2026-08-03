/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc32e98
 * Function: FUN_ffffffffbfc32e98
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

uint FUN_ffffffffbfc32e98(long param_1,ulong param_2)

{
  int iVar1;
  char cVar6;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ulong uVar7;
  undefined8 unaff_s2;
  code *pcVar8;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  code *pcVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar10[6] = &_gp;
  puVar10[1] = unaff_s1;
  puVar10[2] = unaff_s2;
  iVar2 = DAT_ffffffffbfc436f0;
  uVar7 = (param_1 << 0x28) + 0x8000660000000000;
  puVar10[7] = in_ra;
  *puVar10 = unaff_s0;
  pcVar8 = (code *)(long)(iVar2 + 0x2cd8);
  puVar10[5] = unaff_s5;
  puVar10[4] = unaff_s4;
  puVar10[3] = unaff_s3;
  (*pcVar8)(uVar7 | 0xf0);
  (*pcVar8)(uVar7 | param_2 >> 8 & 0xff);
  (*pcVar8)(uVar7 | param_2 & 0xff);
  (*pcVar8)(uVar7 | 0xfc);
  iVar2 = DAT_ffffffffbfc436f0;
  while( true ) {
    iVar1 = DAT_ffffffffbfc436f0;
    cVar6 = (*(code *)(long)(iVar2 + 0x2ca8))();
    iVar2 = DAT_ffffffffbfc436f0;
    pcVar8 = (code *)(long)(iVar1 + 0x2cd8);
    if (cVar6 == '\0') break;
    (*pcVar8)(uVar7 | 0x30000fd00000000);
  }
  pcVar9 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x2ca8);
  (*pcVar8)(uVar7 | 0x30000f400000000);
  iVar2 = (*pcVar9)();
  uVar7 = uVar7 & 0xfeffffffffffffff | 0x100000000000000;
  (*pcVar8)(uVar7);
  uVar3 = (*pcVar9)();
  (*pcVar8)(uVar7);
  uVar4 = (*pcVar9)();
  (*pcVar8)(uVar7);
  uVar5 = (*pcVar9)();
  return (uVar4 & 0xff) << 8 | iVar2 << 0x18 | (uVar3 & 0xff) << 0x10 | uVar5 & 0xff;
}

