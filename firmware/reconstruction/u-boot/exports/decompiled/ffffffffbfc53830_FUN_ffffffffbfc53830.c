/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc53830
 * Function: FUN_ffffffffbfc53830
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

undefined8
FUN_ffffffffbfc53830(long param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  undefined8 unaff_s0;
  long lVar6;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar7;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar8[4] = &_gp;
  iVar3 = ((uint)param_2 & 0xffff) - 0xe;
  puVar8[1] = unaff_s1;
  *puVar8 = unaff_s0;
  psVar5 = (short *)(long)iRamffffffffbfc55cf8;
  iVar4 = (int)param_1;
  lVar6 = (long)(iVar4 + 0xe);
  puVar8[5] = in_ra;
  puVar8[3] = unaff_s3;
  puVar8[2] = unaff_s2;
  *(undefined1 *)(param_1 + 0xe) = 0x45;
  *(char *)(lVar6 + 3) = (char)iVar3;
  *(char *)(lVar6 + 2) = (char)((uint)iVar3 >> 8);
  *(undefined1 *)(lVar6 + 1) = 0;
  uVar1 = uRamffffffffbfc55ca4;
  pcVar7 = (code *)(long)iRamffffffffbfc55d98;
  *(char *)(lVar6 + 4) = (char)((ushort)*psVar5 >> 8);
  *(char *)(lVar6 + 5) = (char)*psVar5;
  *psVar5 = *psVar5 + 1;
  *(undefined1 *)(lVar6 + 9) = param_3;
  *(undefined1 *)(lVar6 + 8) = 0x40;
  *(undefined1 *)(lVar6 + 6) = 0;
  *(undefined1 *)(lVar6 + 7) = 0;
  *(undefined1 *)(lVar6 + 10) = 0;
  *(undefined1 *)(lVar6 + 0xb) = 0;
  (*pcVar7)(iVar4 + 0x1a,uVar1,4);
  (*(code *)(long)iRamffffffffbfc55d98)(iVar4 + 0x1e,param_4,4);
  uVar2 = (*(code *)(long)iRamffffffffbfc55d5c)(lVar6,0x14,0);
  pcVar7 = (code *)(long)iRamffffffffbfc55dc0;
  *(char *)(lVar6 + 0xb) = (char)uVar2;
  *(char *)(lVar6 + 10) = (char)((ushort)uVar2 >> 8);
  (*pcVar7)(param_1,param_2);
  return 0;
}

