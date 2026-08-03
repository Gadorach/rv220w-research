/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc32d4c
 * Function: FUN_ffffffffbfc32d4c
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

void FUN_ffffffffbfc32d4c(long param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  char cVar3;
  undefined8 unaff_s0;
  long lVar4;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  ulong uVar5;
  undefined8 unaff_s3;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 in_ra;
  undefined8 in_HW_RESIM31;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar7[4] = &_gp;
  puVar7[2] = unaff_s2;
  puVar7[3] = unaff_s3;
  iVar1 = DAT_ffffffffbfc436f0;
  uVar5 = (param_1 << 0x28) + 0x8000660000000000;
  puVar7[5] = in_ra;
  puVar7[1] = unaff_s1;
  pcVar6 = (code *)(long)(iVar1 + 0x2cd8);
  *puVar7 = unaff_s0;
  (*pcVar6)(uVar5 | 0xf2);
  (*pcVar6)(uVar5 | param_2 >> 8 & 0xff);
  (*pcVar6)(uVar5 | param_2 & 0xff);
  (*pcVar6)(uVar5 | 0xf8);
  (*pcVar6)(uVar5 | param_3 >> 0x18 & 0xff);
  (*pcVar6)(uVar5 | param_3 >> 0x10 & 0xff);
  (*pcVar6)(uVar5 | param_3 >> 8 & 0xff);
  (*pcVar6)(uVar5 | param_3 & 0xff);
  (*pcVar6)(uVar5 | 0xfe);
  lVar4 = getHWRegister(in_HW_RESIM31);
  do {
    lVar2 = getHWRegister(in_HW_RESIM31);
    if (400000000 < (ulong)(lVar2 - lVar4)) {
      return;
    }
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2cd8))(uVar5 | 0x30000ff00000000);
    cVar3 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2ca8))();
  } while (cVar3 != '\x04');
  return;
}

