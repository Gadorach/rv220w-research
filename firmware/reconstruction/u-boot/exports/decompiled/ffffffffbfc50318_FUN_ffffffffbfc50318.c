/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc50318
 * Function: FUN_ffffffffbfc50318
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

long FUN_ffffffffbfc50318(int param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  ulong uVar2;
  undefined8 unaff_s0;
  long lVar3;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar5[5] = &_gp;
  *puVar5 = unaff_s0;
  puVar5[2] = unaff_s2;
  iVar1 = iRamffffffffbfc55d6c;
  lVar3 = (long)iRamffffffffbfc55d6c;
  pcVar4 = (code *)(long)iRamffffffffbfc55d98;
  puVar5[6] = in_ra;
  puVar5[4] = unaff_s4;
  puVar5[3] = unaff_s3;
  puVar5[1] = unaff_s1;
  param_3 = param_3 & 0xffff;
  (*pcVar4)(lVar3,param_1 + 6,6);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar1 + 6,uRamffffffffbfc55ddc,6);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar1 + 0xc,param_1 + 0xc,10);
  uVar2 = (long)(int)(param_3 >> 8 | param_3 << 8) & 0xffff;
  pcVar4 = (code *)(long)iRamffffffffbfc55cc0;
  *(char *)(lVar3 + 0x17) = (char)uVar2;
  *(char *)(lVar3 + 0x16) = (char)(uVar2 >> 8);
  (*pcVar4)(iVar1 + 0x18,0,600);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar1 + 0x18,param_2,param_3);
  return lVar3;
}

