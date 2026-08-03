/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc27d84
 * Function: FUN_ffffffffbfc27d84
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

void FUN_ffffffffbfc27d84(long param_1)

{
  ulong uVar1;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ulong *puVar2;
  undefined8 unaff_s2;
  ulong uVar3;
  undefined8 unaff_s3;
  int iVar4;
  undefined8 unaff_s4;
  undefined8 uVar5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  int iVar6;
  code *pcVar7;
  long in_k0;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  iVar4 = *(int *)(in_k0 + 0x24);
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar8[4] = unaff_s4;
  uVar5 = special2(param_1,param_1,10,0x32);
  puVar8[8] = &_gp;
  *puVar8 = unaff_s0;
  pcVar7 = (code *)(long)DAT_ffffffffbfc43ec0;
  puVar8[5] = uVar5;
  puVar8[1] = unaff_s1;
  puVar8[9] = in_ra;
  puVar2 = (ulong *)(param_1 + -0x7ffee7fffffff7e8);
  puVar8[7] = unaff_s7;
  puVar8[6] = unaff_s6;
  puVar8[3] = unaff_s3;
  puVar8[2] = unaff_s2;
  uVar1 = (*pcVar7)(iVar4 * 1000000);
  uVar3 = *puVar2;
  iVar4 = (int)uVar1 * 0x20 + 10000;
  iVar6 = DAT_ffffffffbfc43700 + 0x7b70;
  (*(code *)(long)iVar6)(iVar4);
  pcVar7 = (code *)(long)(DAT_ffffffffbfc43700 + 0x7b40);
  (*pcVar7)(puVar2,uVar3 | 0x80);
  (*pcVar7)(param_1 + -0x7ffee7fffffff780,uVar1 & 0xff);
  (*pcVar7)(param_1 + -0x7ffee7fffffff778,uVar1 >> 8 & 0xff);
  (*pcVar7)(puVar2,uVar3 & 0xffffffffffffff7f);
  (*(code *)(long)iVar6)(iVar4);
  (*(code *)(long)DAT_ffffffffbfc43b18)(500000);
  return;
}

